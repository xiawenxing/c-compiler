%{
#include "AST.h"
#include "myparser.tab.h"
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
extern YYSTYPE yylval;
%}
%option yylineno

BLANK [ \t\n\r]+
INTNUM [0-9]+
DOUNUM [0-9]+\.[0-9]+
EXPNUM {DOUNUM}|{INTNUM}((e|E)(\+|\-)?[0-9]+)
STRING \"[^"]*\"
CHARACTER \'[a-zA-Z_]\'
COMMENT (\/\/.*)
IDENTIFIER [a-zA-Z_][a-zA-Z0-9_]*
FILENAME [a-zA-Z_]+\.[a-zA-Z_]+

%%
{COMMENT} {}
{BLANK} {}

"#" {return '#';}
"++" {return SI;}
"--" {return SD;}
"<" {return LT;}
">" {return GT;}
"<=" {return LE;}
">=" {return GE;}
"==" {return EQ;}
"!=" {return NE;}
"|" {return OR;}
"&&" {return AND;}
"{" {return '{';}
"}" {return '}';}
"(" {return '(';}
")" {return ')';}
"[" {return '[';}  
"]" {return ']';}
"+" {return '+';}
"-" {return '-';}
"*" {return '*';}
"/" {return '/';}
"%" {return '%';}
";" {return ';';}
"=" {return '=';}
"," {return ',';}
"." {return '.';}

{IDENTIFIER} {
				string defstr = "define";
				string incstr = "include";
				string truestr = "true";
				string falsestr = "false";
				string charstr = "char";
				string intstr = "int";
				string doustr = "double";
				string voidstr = "void";
				string boolstr = "bool";
				string strstr = "string";
				string elsestr = "else";
				string ifstr = "if";
				string whilestr = "while";
				string returnstr = "return";
				string forstr = "for";
				
				if(strcmp(yytext,incstr.c_str())==0)
				{
					return INCLUDE;
				}else if(strcmp(yytext,defstr.c_str())==0)
				{
					return DEFINE;
				}else if(strcmp(yytext,truestr.c_str())==0||strcmp(yytext,falsestr.c_str())==0)
				{
					yylval.boolnum = new BoolNum(yytext);;
					return BOOLVAL;
				}else if(strcmp(yytext,charstr.c_str())==0)
				{
					return CHAR;
				}else if(strcmp(yytext,intstr.c_str())==0)
				{
					return INT;
				}else if(strcmp(yytext,doustr.c_str())==0)
				{
					return DOUBLE;
				}else if(strcmp(yytext,voidstr.c_str())==0)
				{
					return _VOID;
				}else if(strcmp(yytext,boolstr.c_str())==0)
				{
					return BOOL;
				}else if(strcmp(yytext,strstr.c_str())==0)
				{
					return STR;
				}else if(strcmp(yytext,elsestr.c_str())==0)
				{
					return ELSE;
				}else if(strcmp(yytext,ifstr.c_str())==0)
				{
					return IF;
				}else if(strcmp(yytext,whilestr.c_str())==0)
				{
					return WHILE;
				}else if(strcmp(yytext,forstr.c_str())==0)
				{
					return FOR;
				}else if(strcmp(yytext,returnstr.c_str())==0)
				{
					return RETURN;
				}
				
				yylval.iden = yytext;
				return IDEN;
			 }

{FILENAME} {
		yylval.filename = yytext;
		return FILENAME;
		}

{INTNUM} {
			yylval.intnum = new IntNum(yytext);
			return INTNUM;
		}
			
{DOUNUM} {
			yylval.dounum = new DouNum(yytext);
			return DOUNUM;
		}
			
{EXPNUM} {
			yylval.dounum = new DouNum(yytext,'e');
			return DOUNUM;
		}
			
{STRING} {
			yylval.strnode = new StrNode(yytext);
			return STRING;
			}

{CHARACTER} {
			yylval.cha =new ChaNode(yytext[1]);
			return CHARACTER;
			}


%%

int yywrap()
{
	puts("---fileend---\n");
	return 1;
}

