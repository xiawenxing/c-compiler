#include "llvm/ADT/APInt.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"
#include <memory>
#include <string>
#include <vector>
#include <iostream>

using namespace llvm;

static LLVMContext TheContext;
static IRBuilder<> Builder(TheContext);

void temp()
{
	std::unique_ptr<Module> TheModule = std::make_unique<Module>("main module", TheContext);
	FunctionType* fun_type =
		FunctionType::get(Type::getInt32Ty(TheContext), std::vector<Type*>(2, Type::getInt32Ty(TheContext)), false);
	Function* fun = Function::Create(fun_type, GlobalValue::InternalLinkage, "function", TheModule.get());

	std::vector<Value*> args;
	int cnt = 0;
	std::string xx[] = { "a", "b" };
	for (auto& arg : fun->args()) { arg.setName(xx[cnt++]); args.push_back(&arg); }

	BasicBlock* bb = BasicBlock::Create(TheContext, "entry", fun);
	Builder.SetInsertPoint(bb);
	Value* constant2 = Constant::getIntegerValue(Type::getInt32Ty(TheContext), APInt(32, 2));
	Value* constant48 = Constant::getIntegerValue(Type::getInt32Ty(TheContext), APInt(32, 48));
	Value* a = Builder.CreateAdd(constant2, constant48, "w");
	FunctionType* putchar_type =
		FunctionType::get(Type::getInt32Ty(TheContext), std::vector<Type*>(1, Type::getInt32Ty(TheContext)), false);

	Function* fputchar = Function::Create(putchar_type, GlobalValue::ExternalLinkage, "putchar", TheModule.get());
	Value* b = Builder.CreateAdd(a, args[0], "x");
	Value* c = Builder.CreateAdd(b, args[1], "y");
	Value* z = Builder.CreateCall(fputchar, std::vector<Value*>(1, c), "z");
	Builder.CreateRet(z);
	TheModule->print(outs(), nullptr);
}

int main() {
	temp();
	int n;  std::cin >> n;
	return 0;
}
