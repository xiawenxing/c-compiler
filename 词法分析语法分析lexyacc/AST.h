
#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>
extern int yylineno;
extern char* yytext;
using namespace std;

class Node;

// number character string operater identifier(variable)
class IntNum ;

class DouNum ;

class ExpNum ;

class BoolNum ;

class StrNode ;

class ChaNode;

/*class Identifier : public Node
{
public:
std::string name;
Node* ptrValue;
Identifier(char* txt) :Node(txt)
{
name = string(txt);
}
};*/
// 一个节点用于指向一串decl声明语句
class DeclaListNode ; 

// 一个中间节点用于指向具体的不同类型decl声明语句
class Declaration ;


class Variable;

class VariaDecla;

class VariaListNode ;

class Operator ;

class Assignment ;

class AssignListNode ;

// declaration (func_decla vari_decla)


class FuncDecla ;

// expression
class Expression ;

class ExpreListNode ;
// statements
class Statement ;

class StateListNode;
// blocks
class Block;

class MultiBlock;

class FunCall;

class If_Stmt;

class While_Stmt;

class Return_Stmt;


typedef vector <Variable> VariaList;
typedef vector <Declaration> DeclaList;
typedef vector <Assignment> AssignList;
typedef vector <Expression> ExpreList;
typedef vector <Statement> StateList;



class Node
{
public:
	int height;
	string nodename;
	string content;
	Node(){}
	virtual void printNode(int h, ofstream& fout){}
};

// number character string operater identifier(variable)
class IntNum : public Node
{
public:
	int value;
	string type;
	IntNum(){}
	IntNum(char* txt) : Node()
	{
		value = atoi(txt);
		type = "INT";
		nodename = "INT NUM";
	}

	void printNode(int h, ofstream& fout){		
		for(int i=0; i<h; i++) fout<<"-";
		content = "("+nodename+","+type+","+to_string(value)+")";
		fout<<content<<endl;	
	}
};

class DouNum : public Node
{
public:
	double value;
	string type;
	DouNum(){}
	DouNum(char* txt) : Node()
	{
		value = atof(txt);
		//value = atof(text.c_str());
		type = "DOUBLE";
		nodename = "DOUBLE NUM";
	}

	DouNum(char* txt, char e)
	{
		int eposi;
		string cont(txt);
		eposi = cont.find("e") + cont.find("E") + 1;
		double num = atof((cont).substr(0, eposi - 1).c_str());
		double exp = atof((cont).substr(eposi + 1, cont.length() + 1).c_str());
		value = num*pow(10.0, exp);
		type = "DOUBLE";////////100
		nodename = "DOUBLE NUM";
	}
	
	void printNode(int h,ofstream& fout){		
		for(int i=0; i<h; i++)fout<<"-";
		content = "("+nodename+","+type+","+to_string(value)+")";
		fout<<content<<endl;	
	}
};


class BoolNum:public Node {
public:
	string type;
	string value;
	BoolNum(){}
	BoolNum(char* txt)
	{
		type = "BOOL";
		value = string(txt);
		nodename = "BOOL NUM";
	}
	void printNode(int h, ofstream& fout){		
		for(int i=0; i<h; i++) fout<<"-";
		content = "("+nodename+","+type+","+value+")";
		fout<<content<<endl;	
	}
};

class StrNode :public Node
{
public:
	string type ;
	string value;
	StrNode(){}
	StrNode(char* txt)
	{
		type = "STRING";
		value = string(txt);
		nodename = "STRING CONST";
	}
	
	void printNode(int h, ofstream& fout){		
		for(int i=0; i<h; i++) fout<<"-";
		content = "("+nodename+","+type+","+value+")";
		fout<<content<<endl;	
	}
};

class ChaNode:public Node
{
public:
	string type;
	char value;
	ChaNode(){}
	ChaNode(char c){
		value = c;
		type = "CHAR";
		nodename = "CHAR CONST";
	}
	void printNode(int h, ofstream& fout){		
		for(int i=0; i<h; i++) fout<<"-";
		content = "("+nodename+","+type+","+to_string(value)+")";
		fout<<content<<endl;	
	}
};

class PreDefi : public Node
{
public:
	string left;
	Node* rightval;
	PreDefi(){}
	void printNode(int h, ofstream& fout){		
		for(int i=0; i<h; i++) fout<<"-";
		fout<<content<<endl;	
		if(rightval!=NULL)rightval->printNode(h+1, fout);
	}
};

class HeadFile : public Node
{
public:
	std::string filename;
	HeadFile(){}
	void printNode(int h, ofstream& fout){		
		for(int i=0; i<h; i++) fout<<"-";
		fout<<content<<endl;	
	}
};

// 一个中间节点用于指向具体的不同类型decl声明语句
class Declaration : public Node
{
public:
	Node* ptrNext;
	Declaration(){}
	void printNode(int h, ofstream& fout){		
		for(int i=0; i<h; i++) fout<<"-";
		fout<<content<<endl;
		if(ptrNext!=NULL)ptrNext->printNode(h+1, fout);	
	}
};

// 一个节点用于指向一串decl声明语句
class DeclaListNode :public Node
{
public:
	DeclaList list;
	DeclaListNode(){}
	void printNode(int h, ofstream& fout){		
		for(int i=0; i<h; i++) fout<<"-";
		fout<<content<<endl;
		vector <Declaration>::iterator iter;
		for(iter=list.begin(); iter!=list.end(); iter++)
		{
			iter->Declaration::printNode(h+1,fout);
		}	
	}
}; 

// expression
class Expression : public Node
{
public:
	string type;
	Node* ptrvalue;
	//Operator& oper;
	string op;
	Expression* leftnode;
	Expression* rightnode;
	Expression(){}
	void printNode(int h, ofstream& fout){		
		for(int i=0; i<h; i++) fout<<"-";
		fout<<content<<endl;
		if(leftnode!=NULL)leftnode->printNode(h+1, fout);	
		if(rightnode!=NULL)rightnode->printNode(h+1, fout);	
		if(ptrvalue!=NULL)ptrvalue->printNode(h+1, fout);		
	}
};

class Variable :public Node
{
public:
	string name;
	string type;
	Node* ptrexpr;
	Variable(){}
	void printNode(int h, ofstream& fout){		
		for(int i=0; i<h; i++) fout<<"-";
		fout<<content<<endl;
		if(ptrexpr!=NULL)ptrexpr->printNode(h+1,fout);	
	}
};


class VariaListNode : public Node
{
public:
	VariaList list;
	string type;
	VariaListNode(){}
	void printNode(int h, ofstream& fout){		
		for(int i=0; i<h; i++) fout<<"-";
		fout<<content<<endl;
		vector <Variable>::iterator iter;
		for(iter=list.begin(); iter!=list.end(); iter++)
		{
			iter->printNode(h+1,fout);
		}	
	}
};
class VariaDecla : public Node
{
public:
	VariaListNode* list;
	VariaDecla(){}
	void printNode(int h, ofstream& fout){		
		for(int i=0; i<h; i++) fout<<"-";
		fout<<content<<endl;
		if(list!=NULL)list->printNode(h+1, fout);	
	}
};

/*class Operator : public Node
{
public:
	string op;
	string type;
	Operator(){}
	
};*/

class Assignment :public Node
{
public:
	Node* value;
	Variable* leftnode;
	Expression* rightnode;
	Assignment(){}
	void printNode(int h, ofstream& fout){		
		for(int i=0; i<h; i++) fout<<"-";
		fout<<content<<endl;
		if(leftnode !=NULL)leftnode->printNode(h+1, fout);	
		if(rightnode!=NULL)rightnode->printNode(h+1, fout);	
	}
};

class AssignListNode :public Node
{
public:
	AssignList list;
	AssignListNode(){}
	void printNode(int h, ofstream& fout){		
		for(int i=0; i<h; i++) fout<<"-";
		fout<<content<<endl;
		vector <Assignment>::iterator iter;
		for(iter=list.begin(); iter!=list.end(); iter++)
		{
			iter->printNode(h+1,fout);
		}	
	}
};

// statements
class Statement : public Node
{
public:
	string type;// decl expr bloc ifst wlst rest
	Node* ptrstmt;
	Statement(){}
	void printNode(int h, ofstream& fout){		
		for(int i=0; i<h; i++) fout<<"-";
		fout<<content<<endl;	
		if(ptrstmt!=NULL)ptrstmt->printNode(h+1, fout);	
	}
};

class StateListNode :public Node
{
public:
	StateList list;
	StateListNode(){}
	void printNode(int h, ofstream& fout){		
		for(int i=0; i<h; i++) fout<<"-";
		fout<<content<<endl;
		vector <Statement>::iterator iter;
		for(iter=list.begin(); iter!=list.end(); iter++)
		{
			iter->printNode(h+1,fout);
		}	
	}
};

// blocks
class Block : public Node
{
public:
	StateListNode* stmtlist;
	Block(){}
	void printNode(int h, ofstream& fout){		
		for(int i=0; i<h; i++) fout<<"-";
		fout<<content<<endl;	
		if(stmtlist!=NULL)stmtlist->printNode(h+1, fout);	
	}
};

class FuncDecla : public Node
{
public:
	string name;//Identifier func;
	Variable returnval;
	VariaListNode* paras;
	Block* block;
	FuncDecla(){}
	void printNode(int h, ofstream& fout){		
		for(int i=0; i<h; i++) fout<<"-";
		fout<<content<<endl;	
		if(paras!=NULL)paras->printNode(h+1, fout);
		if(block!=NULL)block->printNode(h+1, fout);	
	}
};


class ExpreListNode :public Node
{
public:
	ExpreList list;
	ExpreListNode(){}
	void printNode(int h, ofstream& fout){		
		for(int i=0; i<h; i++) fout<<"-";
		fout<<content<<endl;
		vector <Expression>::iterator iter;
		for(iter=list.begin(); iter!=list.end(); iter++)
		{
			iter->printNode(h+1,fout);
		}	
	}
};


class MultiBlock : public Node
{
public:
	Block* leftblock;
	Block* rightblock;
	MultiBlock(){}
	void printNode(int h, ofstream& fout){		
		for(int i=0; i<h; i++) fout<<"-";
		fout<<content<<endl;	
		if(leftblock!=NULL)leftblock->printNode(h+1, fout);
		if(rightblock!=NULL)rightblock->printNode(h+1, fout);	
	}
};

class FunCall : public Node
{
public:
	string funcname;
	Node* value;
	ExpreListNode* args;
	FunCall(){}
	void printNode(int h, ofstream& fout){		
		for(int i=0; i<h; i++) fout<<"-";
		fout<<content<<endl;	
		if(value!=NULL)value->printNode(h+1, fout);
		if(args!=NULL)args->printNode(h+1, fout);	
	}
};

class If_Stmt : public Node
{
public:
	Expression* condition;
	Statement* ifstmt;
	Statement* elstmt;
	If_Stmt(){}
	void printNode(int h, ofstream& fout){		
		for(int i=0; i<h; i++) fout<<"-";
		fout<<content<<endl;	
		if(condition!=NULL)condition->printNode(h+1, fout);
		if(ifstmt!=NULL)ifstmt->printNode(h+1, fout);
		if(elstmt!=NULL)elstmt->printNode(h+1, fout);	
	}
};

class For_Stmt:public Node
{
public:
	Node* before;
	Expression* condition;
	Node* after;
	Statement* stmt;
	For_Stmt(){}
	void printNode(int h, ofstream& fout){		
		for(int i=0; i<h; i++) fout<<"-";
		fout<<content<<endl;	
		if(before!=NULL)before->printNode(h+1, fout);
		if(condition!=NULL)condition->printNode(h+1, fout);
		if(after!=NULL)after->printNode(h+1, fout);
		if(stmt!=NULL)stmt->printNode(h+1, fout);
	}
};

class While_Stmt : public Node
{
public:
	Expression* condition;
	Statement* stmt;
	While_Stmt(){}
	void printNode(int h, ofstream& fout){		
		for(int i=0; i<h; i++) fout<<"-";
		fout<<content<<endl;	
		if(condition!=NULL)condition->printNode(h+1, fout);
		if(stmt!=NULL)stmt->printNode(h+1, fout);
	}
};

class Return_Stmt : public Node
{
public:
	Expression* retval;
	Return_Stmt(){}
	void printNode(int h, ofstream& fout){		
		for(int i=0; i<h; i++) fout<<"-";
		fout<<content<<endl;	
		if(retval!=NULL)retval->printNode(h+1, fout);
	}
};

