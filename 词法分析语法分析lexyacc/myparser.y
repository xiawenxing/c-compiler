%{
#include <iostream>
#include <fstream>
#include <string>
#include "AST.h"
using namespace std;

Node* Root;
Node* ptrnode;
ofstream fout;
int i;

extern char* yytext;
//extern int column;
extern FILE* yyin;
extern FILE* yyout;
extern int yylineno;

int yylex(void);
void yyerror(const char* s)
{
	//fflush(stdout);
	cout<<"error"<<yylineno<<"^"<<s<<endl;
	exit(1);
}

%}

%union {
	int comint;

	IntNum* intnum;
	DouNum* dounum;
	ExpNum* expnum;
	StrNode* strnode;
	BoolNum* boolnum;
	char* iden;
	char* filename;
	char* str;
	ChaNode* cha;
	
	DeclaListNode* decls;
	Declaration* decl;
	PreDefi* defi;
	HeadFile* incl;
	VariaDecla* vars;
	Variable* var;     ///////1
	VariaListNode* varlist;
	FuncDecla* funcdecla;
	Node* node;
	Block* blo;
	Statement* stat;
	StateListNode* stalist;
	ExpreListNode* exprs;
	Expression* expr;
	char* oper;
	FunCall* func;
	ExpreList* arglist;
	If_Stmt* ifstmt;
	For_Stmt* forstmt;
	Assignment* assign;
	While_Stmt* whilestmt;
	Return_Stmt* returnstmt;
}

// parser name
%start program
%token <intnum> INTNUM
%token <dounum> DOUNUM
%token <iden> IDEN
%token <filename> FILENAME
%token <strnode> STRING
%token <boolnum> BOOLVAL
%token <cha> CHARACTER
%token DEFINE
%token INCLUDE
%token CHAR 
%token _VOID
%token INT
%token DOUBLE
%token BOOL
%token ELSE
%token IF
%token RETURN
%token WHILE// _STDCALL _CDECL 
%token FOR
%token LT
%token GT
%token SI
%token SD
%token LE
%token GE
%token EQ
%token NE
%token OR
%token AND
%token STR

%right _VOID
%right INT
%right DOUBLE
%right BOOL
%right CHAR
%right STR
%right ELSE

%type <decls> declarations
%type <decl> decl
%type <defi> defi_decl
%type <incl> incl_decl
%type <comint> datatype
%type <vars> var_decl 
%type <varlist> var_list paralist
%type <var> vardef para var
%type <funcdecla> func_decl   
%type <blo> block
%type <stalist> stmts
%type <stat> stmt
%type <exprs> expressions args
%type <expr> expression num_exp factor unary_exp term
%type <oper> logi_op addop mulop unaryop selfop
%type <func> funcall
%type <ifstmt> if_stmt
%type <forstmt> for_stmt
%type <assign> assign_stmt
%type <whilestmt> while_stmt
%type <returnstmt> return_stmt

%%

/////////////////////////////////////////////////////////////////////////////
// rules section
// place your YACC rules here (there must be at least one)


program : declarations
		{ 
			Root = $1;  
			Root->printNode(0,fout);
		};

declarations: declarations decl
			{ 
				$$ = $1; 
				$$->list.push_back(*$2);
				
			}
			| decl
			{  
				$$ = new DeclaListNode();
				$$->list.push_back(*$1);	
				//$$->height = $1->height+1;
				$$->nodename = "declarations";
				$$->content ="("+to_string(yylineno)+","+$$->nodename+")";
				cout<<$$->content<<endl;
			};


decl : var_decl //$1 = new VariaDecla();
	{
		$$ = new Declaration();		
		$$->ptrNext = $1;
		//$$->height = $1->height+1;
		$$->nodename = "decl";
		$$->content ="("+to_string(yylineno)+","+$$->nodename+")";
		cout<<$$->content<<endl;
	}
	| func_decl//$1 = new FuncDecla();
	{
		
		$$ = new Declaration();		
		$$->ptrNext = $1;
		//$$->height = $1->height+1;
		$$->nodename = "decl";
		$$->content ="("+to_string(yylineno)+","+$$->nodename+")";
		cout<<$$->content<<endl;
	}|defi_decl
	{
		$$ = new Declaration();		
		$$->ptrNext = $1;
		//$$->height = $1->height+1;
		$$->nodename = "decl";
		$$->content ="("+to_string(yylineno)+","+$$->nodename+")";
		cout<<$$->content<<endl;
		
	}|incl_decl
	{
		$$ = new Declaration();		
		$$->ptrNext = $1;
		//$$->height = $1->height+1;
		$$->nodename = "decl";
		$$->content ="("+to_string(yylineno)+","+$$->nodename+")";
		cout<<$$->content<<endl;
	};

defi_decl: '#' DEFINE IDEN expression
	{
		$$ = new PreDefi();
		$$->left = string($3);
		$$->rightval = $4;
		$$->nodename = "defi_decl";
		$$->content = "(" + to_string(yylineno)+","+$$->nodename+","+$$->left+")";
		cout<<$$->content<<endl;
	} ;
	
incl_decl:'#' INCLUDE LT FILENAME GT
	{
		$$ = new HeadFile();
		$$->filename = string($4);
		$$->nodename = "incl_decl";
		$$->content = "(" + to_string(yylineno)+","+$$->nodename+","+$$->filename+")";
		cout<<$$->content<<endl;
	}|'#' INCLUDE STRING
	{
		$$ = new HeadFile();
		$$->filename = $3->value;
		$$->nodename = "incl_decl";
		$$->content = "(" + to_string(yylineno)+","+$$->nodename+","+$$->filename+")";
		cout<<$$->content<<endl;
	}|'#' INCLUDE LT IDEN GT
	{
		$$ = new HeadFile();
		$$->filename = string($4);
		$$->nodename = "incl_decl";
		$$->content = "(" + to_string(yylineno)+","+$$->nodename+","+$$->filename+")";
		cout<<$$->content<<endl;
	};

var_decl : datatype var_list ';' //$2 = new VariaListNode();
	{
		$$ = new VariaDecla();
		//$$->height = $2->height+1;
		$$->nodename = "var_decl";
		$$->list = $2;
		$$->content ="("+to_string(yylineno)+","+$$->nodename+")";
		cout<<$$->content<<endl;

		switch($1)
		{
			case 1:// void
				$2->type = "VOID";
				break;
			case 2:// int
				$2->type = "INT";
				break;
			case 3:// char
				$2->type = "CHAR";
				break;
			case 4:// double
				$2->type = "DOUBLE";
				break;
			case 5:
				$2->type = "BOOL";
		}
		$2->content ="("+to_string(yylineno)+","+$$->nodename+","+$2->type+")";
		cout<<$2->content<<endl;
	};

var_list : var_list ',' vardef //$3 = new Variable();
		{
			$$ = $1;
			$$->list.push_back(*$3); 
		}
		| vardef //$1 = new Variable();
		{
			$$ = new VariaListNode();
			$$->nodename = "var_list";
			//$$->height = $1->height+1;
			$$->list.push_back(*$1);
			$$->content ="("+to_string(yylineno)+","+$$->nodename+")";
			cout<<$$->content<<endl;
		};

vardef : IDEN//varname
		{
			$$ = new Variable();
			$$->nodename = "vardef";
			$$->name = string($1);
			//$$->height = 0;
			$$->content ="("+to_string(yylineno)+","+$$->nodename+","+$$->name+")";
			cout<<$$->content<<endl;
		}
		| IDEN '='  expression //$3 = new Expression();
		{
			$$ = new Variable();
			$$->nodename = "vardef";
			//$$->height = 0;
			$$->name = string($1);///////////////////////
			$$->ptrexpr = $3;
			$$->content ="("+to_string(yylineno)+","+$$->nodename+","+$$->name+")";
			cout<<$$->content<<endl;
		};


func_decl : datatype IDEN '(' paralist ')' block //$4 = new VariaListNode();$6 = new Block();;
			{
				$$ = new FuncDecla();
				$$->nodename = "func_decl";
				//$$->height = max($4->height,$6->height)+1;
				$$->name = string($2);
				$$->paras = $4;
				$$->block = $6;
	
				switch($1)
				{
					case 1:// void
					$$->returnval.type = "VOID";
					break;
					case 2:// int
					$$->returnval.type = "INT";
					break;
					case 3:// char
					$$->returnval.type = "CHAR";
					break;
					case 4:// double
					$$->returnval.type = "DOUBLE";
					break;
					case 5:
					$$->returnval.type = "BOOL";
				}
			
				$$->content ="("+to_string(yylineno)+","+$$->nodename+","+$$->name+","+$$->returnval.type+")";
				cout<<$$->content<<endl;
			}
			|datatype IDEN '(' paralist ')' ';'
			{
				$$ = new FuncDecla();
				$$->nodename = "func_decl";
				//$$->height = $4->height+1;
				$$->name = string($2);
				$$->paras = $4;
				switch($1)
				{
					case 1:// void
					$$->returnval.type = "VOID";
					break;
					case 2:// int
					$$->returnval.type = "INT";
					break;
					case 3:// char
					$$->returnval.type = "CHAR";
					break;
					case 4:// double
					$$->returnval.type = "DOUBLE";
					break;
					case 5:
					$$->returnval.type = "BOOL";
				}
				
				$$->content ="("+to_string(yylineno)+","+$$->nodename+","+$$->name+","+$$->returnval.type+")";
				cout<<$$->content<<endl;
			}
			|datatype IDEN '('')' block 
			{
				$$ = new FuncDecla();
				$$->nodename = "func_decl";
				//$$->height = $5->height+1;
				$$->name = string($2);
				$$->block = $5;
				switch($1)
				{
					case 1:// void
					$$->returnval.type = "VOID";
					break;
					case 2:// int
					$$->returnval.type = "INT";
					break;
					case 3:// char
					$$->returnval.type = "CHAR";
					break;
					case 4:// double
					$$->returnval.type = "DOUBLE";
					break;
					case 5:
					$$->returnval.type = "BOOL";
				}
				
				$$->content ="("+to_string(yylineno)+","+$$->nodename+","+$$->name+","+$$->returnval.type+")";
				cout<<$$->content<<endl;
			}
			|datatype IDEN '('')' ';'             
			{
				$$ = new FuncDecla();
				$$->nodename = "func_decl";
				//$$->height = 0;
				$$->name = string($2);
				switch($1)
				{
					case 1:// void
					$$->returnval.type = "VOID";
					break;
					case 2:// int
					$$->returnval.type = "INT";
					break;
					case 3:// char
					$$->returnval.type = "CHAR";
					break;
					case 4:// double
					$$->returnval.type = "DOUBLE";
					break;
					case 5:
					$$->returnval.type = "BOOL";
				}
				
				$$->content ="("+to_string(yylineno)+","+$$->nodename+","+$$->name+","+$$->returnval.type+")";
				cout<<$$->content<<endl;
				
			};
			
paralist : paralist ',' para //$3 = new Variable();
			{
				$$ = $1;
				$1->list.push_back(*$3);
			}
			| para //$1 = new Variable();
			{
				$$ = new VariaListNode();
				$$->list.push_back(*$1);
				//$$->height = $1->height+1;
				$$->nodename = "paralist";
				$$->content ="("+to_string(yylineno)+","+$$->nodename+")";
				cout<<$$->content<<endl;
			};

para : datatype IDEN
		{
			$$ = new Variable();
			$$->name = string($2);
			//$$->height = 0;
			$$->nodename = "para";
			switch($1)
			{
			case 1:// void
				$$->type = "VOID";
				break;
			case 2:// int
				$$->type = "INT";
				break;
			case 3:// char
				$$->type = "CHAR";
				break;
			case 4:// double
				$$->type = "DOUBLE";
				break;
			case 5:
				$$->type = "BOOL";
				break;
			}
			$$->content ="("+to_string(yylineno)+","+$$->nodename+","+$$->type+","+$$->name+")";
			cout<<$$->content<<endl;
		};

datatype : _VOID { $$ = 1; } 
		| INT { $$ = 2;}
		| CHAR { $$ = 3;}
		| DOUBLE { $$ = 4; }
		| BOOL {$$ = 5;}
		| STR {$$ = 6;} ;			

block : '{' stmts '}' //$2 = new StateListNode();
		{
			$$ = new Block();
			$$->stmtlist = $2;
			//$$->height = $2->height+1;
			$$->nodename = "block";
			$$->content ="("+to_string(yylineno)+","+$$->nodename+")";
			cout<<$$->content<<endl;
			
		}| '{''}' 
		{
			$$ = new Block();
			$$->stmtlist = NULL;
			//$$->height = 0;
			$$->nodename = "block";
			$$->content ="("+to_string(yylineno)+","+$$->nodename+")";
			cout<<$$->content<<endl;
		};

stmts : stmts stmt //$2 = new Statement();
		{
			$$ = $1;
			$1->list.push_back(*$2);
		}
		| stmt
		{
			$$ = new StateListNode();
			$$->list.push_back(*$1);
			//$$->height = $1->height+1;
			$$->nodename = "stmts";
			$$->content ="("+to_string(yylineno)+","+$$->nodename+")";
			cout<<$$->content<<endl;
		};

stmt : declarations         //$1 = new DeclaListNode(); 
		{
			$$ = new Statement();
			$$->type = "decl";
			$$->nodename = "stmt";
			$$->ptrstmt = $1;
			//$$->height = $1->height+1;
			$$->content ="("+to_string(yylineno)+","+$$->nodename+","+$$->type+")";
			cout<<$$->content<<endl;
		}
		| expressions//$1 = new ExpreListNode();
		{
			$$ = new Statement();
			$$->type = "expr";
			$$->nodename = "stmt";
			$$->ptrstmt = $1;
			//$$->height = $1->height+1;
			$$->content ="("+to_string(yylineno)+","+$$->nodename+","+$$->type+")";
			cout<<$$->content<<endl;
		}
		| assign_stmt//$1 = new Assignment();
		{
			$$ = new Statement();
			$$->type = "assi";
			$$->nodename = "stmt";
			$$->ptrstmt = $1;
			//$$->height = $1->height+1;
			$$->content ="("+to_string(yylineno)+","+$$->nodename+","+$$->type+")";
			cout<<$$->content<<endl;
		}
		| block //$1 = new Block();
		{
			$$ = new Statement();
			$$->type = "bloc";
			$$->nodename = "stmt";
			$$->ptrstmt = $1;
			//$$->height = $1->height+1;
			$$->content ="("+to_string(yylineno)+","+$$->nodename+","+$$->type+")";
			cout<<$$->content<<endl;

		}
		|
		 if_stmt //$1 = new If_Stmt();
		 {
			$$ = new Statement();
			$$->type = "ifst";
			$$->nodename = "stmt";
			$$->ptrstmt = $1;
			//$$->height = $1->height+1;
			$$->content ="("+to_string(yylineno)+","+$$->nodename+","+$$->type+")";
			cout<<$$->content<<endl;
		 }
		 | while_stmt //$1 = new While_Stmt();
		 {
			$$ = new Statement();
			$$->type = "wlst";
			$$->nodename = "stmt";
			$$->ptrstmt = $1;
			//$$->height = $1->height+1;
			$$->content ="("+to_string(yylineno)+","+$$->nodename+","+$$->type+")";
			cout<<$$->content<<endl;

		 }
		|for_stmt
		{
			$$ = new Statement();
			$$->type = "forst";
			$$->nodename = "stmt";
			$$->ptrstmt = $1;
			//$$->height = $1->height+1;
			$$->content ="("+to_string(yylineno)+","+$$->nodename+","+$$->type+")";
			cout<<$$->content<<endl;

		}
		 | return_stmt//$1 = new Return_Stmt();
		 {
			$$ = new Statement();
			$$->type = "rest";
			$$->nodename = "stmt";
			$$->ptrstmt = $1;
			//$$->height = $1->height+1;
			$$->content ="("+to_string(yylineno)+","+$$->nodename+","+$$->type+")";
			cout<<$$->content<<endl;

		 };

expressions : expressions ',' expression ';'           //$3 = new Expression();     
			{
				$$ = $1;
				$1->list.push_back(*$3);
			}
			| expression ';' //$1 = new Expression();
			{
				$$ = new ExpreListNode();
				$$->nodename = "expressions";
				$$->list.push_back(*$1);
				//$$->height = $1->height+1;
				$$->content ="("+to_string(yylineno)+","+$$->nodename+")";
				cout<<$$->content<<endl;
			}
			| ';'
			{	
	
			};

expression : num_exp logi_op num_exp //$1 = new Expression();
			{
				$$ = new Expression();
				$$->nodename = "expression";
				//$$->height = max($1->height,$3->height)+1;
				$$->leftnode = $1;
				$$->rightnode = $3;
				$$->op = string($2);
				$$->content ="("+to_string(yylineno)+","+$$->nodename+")";
				cout<<$$->content<<endl;
			}
			| num_exp
			{
				$$ = new Expression();
				$$->nodename = "expression";
				//$$->nodename = $1->height+1;
				$$->leftnode = $1;
				$$->content ="("+to_string(yylineno)+","+$$->nodename+")";
				cout<<$$->content<<endl;
			};
			
logi_op  : //LT GT LE GE EQ NE OR AND
			LE 
			{
				$$ = "<=";
			}| LT 
			{
				$$ = "<";
			}| GT  
			{
				$$ = ">";
			}| GE  
			{
				$$ = ">=";
			}| EQ  
			{
				$$ = "==";
			}| NE 
			{
				$$ = "!=";
			}|OR
			{
				$$ = "||";
			}|AND
			{
				$$ = "&&";
			};

num_exp : num_exp addop term  //$3 = new Expression();
		{
			$$ = new Expression();
			$$->leftnode = $1;
			$$->op = string($2);
			$$->rightnode = $3;
			//$$->height = max($1->height,$3->height)+1;
			$$->nodename = "num_exp";
			
			$$->content ="("+to_string(yylineno)+","+$$->nodename+")";
			cout<<$$->content<<endl;
			
		}| term 
		{
			$$ = new Expression();
			$$->leftnode = $1;
			//$$->height = $1->height+1;
			$$->nodename = "num_exp";
			
			$$->content ="("+to_string(yylineno)+","+$$->nodename+")";
			cout<<$$->content<<endl;
		};

addop : '+' {$$ = "+";}| '-'{$$ = "-";};

term : term mulop unary_exp 
		{
			$$ = new Expression();
			$$->leftnode = $1;
			$$->op = string($2);
			$$->rightnode = $3;
			//$$->height = max($1->height,$3->height)+1;
			$$->nodename = "term";

			$$->content ="("+to_string(yylineno)+","+$$->nodename+")";
			cout<<$$->content<<endl;
			
		}| unary_exp 
		{
			$$ = new Expression();
			$$->leftnode = $1;
			//$$->height = $1->height+1;
			$$->nodename = "term";
			
			$$->content ="("+to_string(yylineno)+","+$$->nodename+")";
			cout<<$$->content<<endl;
		};

mulop : '*' {$$ = "*";}| '/' {$$ = "/";}| '%'{$$ = "%";};

unary_exp : unaryop factor 
			{
				$$ = new Expression();
				$$->op = string($1);
				$$->rightnode = $2;
				//$$->height = $2->height+1;
				$$->nodename = "unary_exp";
				$$->content ="("+to_string(yylineno)+","+$$->nodename+","+$$->op+")";
				cout<<$$->content<<endl;
			}| factor
			{
				$$ = new Expression();
				$$->leftnode = $1;
				//$$->height = $1->height+1;
				$$->nodename = "unary_exp";
				$$->content ="("+to_string(yylineno)+","+$$->nodename+")";
				cout<<$$->content<<endl;
			}|selfop factor
			{
				$$ = new Expression();
				$$->rightnode = $2;
				$$->op = string($1);
				$$->nodename = "unary_exp";
				$$->content ="("+to_string(yylineno)+","+$$->nodename+","+$$->op+")";
				cout<<$$->content<<endl;
			}|factor selfop
			{
				$$ = new Expression();
				$$->leftnode = $1;
				$$->op = string($2);
				$$->nodename = "unary_exp";
				$$->content ="("+to_string(yylineno)+","+$$->nodename+","+$$->op+")";
				cout<<$$->content<<endl;
			};

unaryop : '-' {$$ = "-";};
selfop : SI {$$ = "++";} | SD {$$ = "--";};

factor : '(' expression ')'  
		{
			$$ = new Expression();
			$$->leftnode = $2;
			//$$->height = $2->height+1;
			$$->nodename = "factor";
			
			$$->content ="("+to_string(yylineno)+","+$$->nodename+")";
			cout<<$$->content<<endl;
		}| var //$1 = new Variable();
		{
			$$ = new Expression();
			$$->ptrvalue = $1;
			//$$->height = $1->height+1;
			$$->nodename = "factor";
			
			$$->content ="("+to_string(yylineno)+","+$$->nodename+")";
			cout<<$$->content<<endl;
		}
		| funcall  //$1 = new FunCall();
		{
			$$ = new Expression();
			$$->ptrvalue = $1;
			//$$->height = $1->height+1;
			$$->nodename = "factor";
			
			$$->content ="("+to_string(yylineno)+","+$$->nodename+")";
			cout<<$$->content<<endl;
		}
		| INTNUM 
		{
			$$ = new Expression();
			$$->ptrvalue = $1;
			//$$->height = $1->height+1;
			$$->nodename = "factor";
			
			$$->content ="("+to_string(yylineno)+","+$$->nodename+")";
			cout<<$$->content<<endl;
		}
		| DOUNUM 
		{
			$$ = new Expression();
			$$->ptrvalue = $1;
			//$$->height = $1->height+1;
			$$->nodename = "factor";
			
			$$->content ="("+to_string(yylineno)+","+$$->nodename+")";
			cout<<$$->content<<endl;
		}
		| STRING 
		{
			$$ = new Expression();
			$$->ptrvalue = $1;
			//$$->height = $1->height+1;
			$$->nodename = "factor";
			
			$$->content ="("+to_string(yylineno)+","+$$->nodename+")";
			cout<<$$->content<<endl;
		}
		| BOOLVAL /////////////////////////////1010
		{
			$$ = new Expression();
			$$->ptrvalue = $1;
			//$$->height = $1->height+1;
			$$->nodename = "factor";
			
			$$->content ="("+to_string(yylineno)+","+$$->nodename+")";
			cout<<$$->content<<endl;
		}|CHARACTER
		{
			$$ = new Expression();
			$$->ptrvalue = $1;
			//$$->height = $1->height+1;
			$$->nodename = "factor";
			
			$$->content ="("+to_string(yylineno)+","+$$->nodename+")";
			cout<<$$->content<<endl;
		}; 


var : IDEN  
	{
		$$ = new Variable();
		$$->name = string($1);
		//$$->height = 0;
		$$->nodename = "var";
		
		$$->content ="("+to_string(yylineno)+","+$$->nodename+","+$$->name+")";
		cout<<$$->content<<endl;
	}	;

funcall : IDEN '('')'  
		{
			$$ = new FunCall();
			$$->funcname = string($1);
			//$$->height = 0;
			$$->nodename = "var";
		
			$$->content ="("+to_string(yylineno)+","+$$->nodename+","+$$->funcname+")";
			cout<<$$->content<<endl;
		}| IDEN '('args')'//$3 = new ExpreListNode();
		{
			$$ = new FunCall();
			$$->funcname = string($1);
			//$$->height = $3->height+1;
			$$->nodename = "var";
			$$->args = $3;	
			$$->content ="("+to_string(yylineno)+","+$$->nodename+","+$$->funcname+")";
			cout<<$$->content<<endl;
		};

args : args ',' expression //$3 = new Expression();
	{
		$$ = $1;
		$1->list.push_back(*$3);
	
	}| expression 
	{
		$$ = new ExpreListNode();
		$$->list.push_back(*$1);
		//$$->height = $1->height+1;
		$$->nodename = "expressions";
		$$->content ="("+to_string(yylineno)+","+$$->nodename+")";
		cout<<$$->content<<endl;
	};

assign_stmt : var '=' expression ';'// var '=' expression';'//$1 = new Variable();//$3 = new Expression();
			{
				$$ = new Assignment();
				$$->leftnode = $1;
				$$->rightnode = $3;
				$1->ptrexpr = $3;
			//	$$->height = max($1->height,$3->height)+1;
				$$->nodename = "assign_stmt";
				
				$$->content ="("+to_string(yylineno)+","+$$->nodename+")";
				cout<<$$->content<<endl;
			};

if_stmt : IF '(' expression ')' stmt //$3 = new Expression();//$5 = new Statement();
			{
				$$ = new If_Stmt();
				$$->condition = $3;
				$$->ifstmt = $5;
			//	$$->height = max($5->height,$3->height)+1;
				$$->nodename = "if_stmt";
				$$->content ="("+to_string(yylineno)+","+$$->nodename+")";
				cout<<$$->content<<endl;

			}| IF '(' expression ')' stmt ELSE stmt 
			{
				$$ = new If_Stmt();
				$$->condition = $3;
				$$->ifstmt = $5;
				$$->elstmt = $7;
			//	$$->height = max($5->height,$3->height);
			//	$$->height = max($$->height,$7->height)+1;
 				$$->nodename = "if_stmt";
				$$->content ="("+to_string(yylineno)+","+$$->nodename+")";
				cout<<$$->content<<endl;
			};
			
while_stmt :  WHILE '(' expression ')' stmt
			{
				$$ = new While_Stmt();
				$$->condition = $3;
				$$->stmt = $5;
			//	$$->height = max($5->height,$3->height)+1;
				$$->nodename = "while_stmt ";
				$$->content ="("+to_string(yylineno)+","+$$->nodename+")";
				cout<<$$->content<<endl;
			};
for_stmt : FOR '('assign_stmt expression';' expression')' stmt
	{
		$$ = new For_Stmt();
		$$->before = $3;
		$$->condition = $4;
		$$->after = $6;
		$$->stmt = $8;
		$$->nodename = "for_stmt";
		$$->content ="("+to_string(yylineno)+","+$$->nodename+")";
		cout<<$$->content<<endl;
	}
	| FOR '('';' expression';' expression')' stmt
	{
		$$ = new For_Stmt();
		$$->condition = $4;
		$$->after = $6;
		$$->stmt = $8;
		$$->nodename = "for_stmt";
		$$->content ="("+to_string(yylineno)+","+$$->nodename+")";
		cout<<$$->content<<endl;
	}
	|FOR '('assign_stmt expression';' ')' stmt
	{
		$$ = new For_Stmt();
		$$->before = $3;
		$$->condition = $4;
		$$->stmt = $7;
		$$->nodename = "for_stmt";
		$$->content ="("+to_string(yylineno)+","+$$->nodename+")";
		cout<<$$->content<<endl;
	}
	|FOR '('';' expression';' ')' stmt
	{
		$$ = new For_Stmt();
		$$->condition = $4;
		$$->stmt = $7;
		$$->nodename = "for_stmt";
		$$->content ="("+to_string(yylineno)+","+$$->nodename+")";
		cout<<$$->content<<endl;
	}
;

return_stmt : RETURN ';'
			{
				//$$->retval = null;
			}
			|RETURN expression ';' 
			{
				$$ = new Return_Stmt();
			//	$$->height = $2->height+1;
				$$->nodename = "return_stmt";
				$$->retval = $2;
				
				$$->content ="("+to_string(yylineno)+","+$$->nodename+")";
				cout<<$$->content<<endl;
			};

%%

/////////////////////////////////////////////////////////////////////////////
// programs section
/*
void yyerror()
{
	printf("line %d:  %s\n", yylineno,  yytext);
	exit(1);
}
*/
int max(int a, int b){
	if(a>b)return a;
	else return b;
}

int main(void)
{	
	string filesrc;
	string fileobj;
	cin>>filesrc;
	cin>>fileobj;
	yyin = fopen(filesrc.c_str(),"r");	
	yyout = fopen(fileobj.c_str(),"w");
	fout.open(fileobj.c_str(),ios::out);
	yyparse();
	fclose(yyin);
	fclose(yyout);
	return 0;
}
