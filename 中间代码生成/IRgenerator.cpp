#include "AST.hpp"
#include "IRgeneerator.h"
#include "myparser.hpp"

using namespace std;

/* Compile the AST into a module */
void CodeGenContext::generateCode(Block& root)
{
	std::cout << "Generating LLVMIR...\n";
	
	/* Create the top level interpreter function to call as entry */
	vector<Type*> argTypes;
	FunctionType *funtype = FunctionType::get(Type::getVoidTy(thisContext), makeArrayRef(argTypes), false);
	mainFunction = Function::Create(funtype, GlobalValue::InternalLinkage, "main", module);
	BasicBlock *bblock = BasicBlock::Create(thisContext, "entry", mainFunction, 0);
	
	/* Push a new variable/block context */
	pushBlock(bblock);
	root.codeGen(*this); /* emit bytecode for the toplevel block */
	ReturnInst::Create(thisContext, bblock);
	popBlock();
	
	/* Print the bytecode in a human-readable format 
	   to see if our program compiled properly
	 */
	std::cout << "LLVMIR is generated.\n";
	// module->dump();

	legacy::PassManager pm;
	pm.add(createPrintModulePass(outs()));
	pm.run(*module);
}


/* Returns an LLVM type based on the id */
static Type *TheType(const Identifier& type) 
{
	if (type.name.compare("int") == 0) {
		return Type::getInt64Ty(thisContext);
	}
	else if (type.name.compare("double") == 0) {
		return Type::getDoubleTy(thisContext);
	}
	return Type::getVoidTy(thisContext);
}


//int
Value* IntNum::codeGen(CodeGenContext& context)
{
	std::cout << "Creating intunm: " << value << endl;
	return ConstantInt::get(Type::getInt64Ty(thisContext), value, true);
}

Value* DouNum::codeGen(CodeGenContext& context)
{
	std::cout << "Creating dounum: " << value << endl;
	return ConstantFP::get(Type::getDoubleTy(thisContext), value);
}

//二元运算
Value* BinOP::codeGen(CodeGenContext& context)
{
	std::cout << "Creating BinOP " << op << endl;
	Value *L = LHS->Codegen();
  	Value *R = RHS->Codegen();
  	if (L == 0 || R == 0) return 0;

  	switch (Op) {
  	case '+': return Builder.CreateFAdd(L, R, "addtmp");
  	case '-': return Builder.CreateFSub(L, R, "subtmp");
  	case '*': return Builder.CreateFMul(L, R, "multmp");
  	case '<':
    L = Builder.CreateFCmpULT(L, R, "cmptmp");
    // Convert bool 0/1 to double 0.0 or 1.0
    return Builder.CreateUIToFP(L, Type::getDoubleTy(getGlobalContext()),
                                "booltmp");
  default: return ErrorV("invalid BinOP");
  }

Value* Identifier::codeGen(CodeGenContext& context)
{
	std::cout << "Creating id : " << name << endl;
	if (context.locals().find(name) == context.locals().end()) {
		cerr << "undeclared var " << name << endl;
		return NULL;
	}
	return new LoadInst(context.locals()[name], "", false, context.currentBlock());
}

//函数声明
Value* FunCall::codeGen(CodeGenContext& context)
{
	Function *function = context.module->getFunction(id.name.c_str());
	if (function == NULL) {
		std::cerr << "no this function " << id.name << endl;
	}
	std::vector<Value*> args;
	ExpressionList::const_iterator it;
	for (it = arg.begin(); it != arg.end(); it++) {
		args.push_back((**it).codeGen(context));
	}
	CallInst *call = CallInst::Create(function, makeArrayRef(args), "", context.currentBlock());
	cout << "Creating fun call: " << id.name << endl;
	return call;
}


//赋值
Value* Assignment::codeGen(CodeGenContext& context)
{
	std::cout << "Creating assignment for " << lhs.name << endl;
	if (context.locals().find(lhs.name) == context.locals().end()) {
		std::cerr << "undeclared var " << lhs.name << endl;
		return NULL;
	}
	return new StoreInst(rhs.codeGen(context), context.locals()[lhs.name], false, context.currentBlock());
}

//block
Value* Block::codeGen(CodeGenContext& context)
{
	StatementList::const_iterator it;
	Value *last = NULL;
	for (it = statements.begin(); it != statements.end(); it++) {
		std::cout << "Generating IR for " << typeid(**it).name() << endl;
		last = (**it).codeGen(context);
	}
	std::cout << "Creating block" << endl;
	return last;
}

Value* ExpreState::codeGen(CodeGenContext& context)
{
	std::cout << "Generating IR for " << typeid(expression).name() << endl;
	return expression.codeGen(context);
}

//变量声明
Value* VariaDecla::codeGen(CodeGenContext& context)
{
	std::cout << "Creating vardecl " << type.name << " " << id.name << endl;
	AllocaInst *alloc = new AllocaInst(TheType(type), id.name.c_str(), context.currentBlock());
	context.locals()[id.name] = alloc;
	if (assignmentExpr != NULL) {
		Assignment assn(id, *assignmentExpr);
		assn.codeGen(context);
	}
	return alloc;
}

//返回值
Value* RetState::codeGen(CodeGenContext& context)
{
	std::cout << "Generating return code for " << typeid(expression).name() << endl;
	Value *returnValue = expression.codeGen(context);
	context.setCurrentReturnValue(returnValue);
	return returnValue;
}

//外部函数
Value* ExtDecl::codeGen(CodeGenContext& context)
{
    vector<Type*> argTypes;
    VariableList::const_iterator it;
    for (it = arg.begin(); it != arg.end(); it++) {
        argTypes.push_back(TheType((**it).type));
    }
    FunctionType *funtype = FunctionType::get(TheType(type), makeArrayRef(argTypes), false);
    Function *function = Function::Create(funtype, GlobalValue::ExternalLinkage, id.name.c_str(), context.module);
    return function;
}

//函数声明
Value* FuncDecla::codeGen(CodeGenContext& context)
{
	vector<Type*> argTypes;
	VariableList::const_iterator it;
	for (it = arg.begin(); it != arg.end(); it++) {
		argTypes.push_back(TheType((**it).type));
	}
	FunctionType *funtype = FunctionType::get(TheType(type), makeArrayRef(argTypes), false);
	Function *function = Function::Create(funtype, GlobalValue::InternalLinkage, id.name.c_str(), context.module);
	BasicBlock *bblock = BasicBlock::Create(thisContext, "entry", function, 0);

	context.pushBlock(bblock);

	Function::arg_iterator argsValues = function->arg_begin();
    Value* argValue;

	for (it = arg.begin(); it != arg.end(); it++) {
		(**it).codeGen(context);
		
		argValue = &*argsValues++;
		argValue->setName((*it)->id.name.c_str());
		StoreInst *inst = new StoreInst(argValue, context.locals()[(*it)->id.name], false, bblock);
	}
	
	block.codeGen(context);
	ReturnInst::Create(thisContext, context.getCurrentReturnValue(), bblock);

	context.popBlock();
	std::cout << "Creating fun: " << id.name << endl;
	return function;
}

//报错
Value *ErrorV(const char *Str) { Error(Str); return 0; }

Value *NumberExprAST::Codegen() {
  return ConstantFP::get(getGlobalContext(), APFloat(Val));
}

Value *VariableExprAST::Codegen() {
  // Look this variable up in the function.
  Value *V = NamedValues[Name];
  return V ? V : ErrorV("Unknown variable name");
}

Value *CallExprAST::Codegen() {
  // Look up the name in the global module table.
  Function *CalleeF = TheModule->getFunction(Callee);
  if (CalleeF == 0)
    return ErrorV("Unknown function referenced");

  // If argument mismatch error.
  if (CalleeF->arg_size() != Args.size())
    return ErrorV("Incorrect # arg passed");

  std::vector<Value*> ArgsV;
  for (unsigned i = 0, e = Args.size(); i != e; ++i) {
    ArgsV.push_back(Args[i]->Codegen());
    if (ArgsV.back() == 0) return 0;
  }

  return Builder.CreateCall(CalleeF, ArgsV, "calltmp");
}

Function *PrototypeAST::Codegen() {
  // Make the function type:  double(double,double) etc.
  std::vector<Type*> Doubles(Args.size(),
                             Type::getDoubleTy(getGlobalContext()));
  FunctionType *FT = FunctionType::get(Type::getDoubleTy(getGlobalContext()),
                                       Doubles, false);

  Function *F = Function::Create(FT, Function::ExternalLinkage, Name, TheModule);

  // If F conflicted, there was already something named 'Name'.  If it has a
  // body, don't allow redefinition or reextern.
  if (F->getName() != Name) {
    // Delete the one we just made and get the existing one.
    F->eraseFromParent();
    F = TheModule->getFunction(Name);

    // If F already has a body, reject this.
    if (!F->empty()) {
      ErrorF("redefinition of function");
      return 0;
    }

    // If F took a different number of args, reject.
    if (F->arg_size() != Args.size()) {
      ErrorF("redefinition of function with different # args");
      return 0;
    }
  }

  // Set names for all arg.
  unsigned Idx = 0;
  for (Function::arg_iterator AI = F->arg_begin(); Idx != Args.size();
       ++AI, ++Idx) {
    AI->setName(Args[Idx]);

    // Add arg to variable symbol table.
    NamedValues[Args[Idx]] = AI;
  }

  return F;
}

Function *FunctionAST::Codegen() {
  NamedValues.clear();

  Function *TheFunction = Proto->Codegen();
  if (TheFunction == 0)
    return 0;

  // Create a new basic block to start insertion into.
  BasicBlock *BB = BasicBlock::Create(getGlobalContext(), "entry", TheFunction);
  Builder.SetInsertPoint(BB);

  if (Value *RetVal = Body->Codegen()) {
    // Finish off the function.
    Builder.CreateRet(RetVal);

    // Validate the generated code, checking for consistency.
    verifyFunction(*TheFunction);

    return TheFunction;
  }

  // Error reading body, remove function.
  TheFunction->eraseFromParent();
  return 0;
}
//内存管理
void *_cava_alloc_(CavaCtx *ctx, size_t size, int flag) {
    if (size == 0) {
        ++size;
    }
    CavaAlloc *cavaAlloc = (CavaAlloc *)ctx->userCtx;
    void *ret = cavaAlloc->alloc(size);
    if (flag && ret) {
        memset(ret, 0, size);
    }
    return ret;
}
void *alloc(size_t size) {
    return _pool.allocate(size);
}