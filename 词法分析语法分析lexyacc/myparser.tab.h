/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_MYPARSER_TAB_H_INCLUDED
# define YY_YY_MYPARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INTNUM = 258,
    DOUNUM = 259,
    IDEN = 260,
    FILENAME = 261,
    STRING = 262,
    BOOLVAL = 263,
    CHARACTER = 264,
    DEFINE = 265,
    INCLUDE = 266,
    CHAR = 267,
    _VOID = 268,
    INT = 269,
    DOUBLE = 270,
    BOOL = 271,
    ELSE = 272,
    IF = 273,
    RETURN = 274,
    WHILE = 275,
    FOR = 276,
    LT = 277,
    GT = 278,
    SI = 279,
    SD = 280,
    LE = 281,
    GE = 282,
    EQ = 283,
    NE = 284,
    OR = 285,
    AND = 286,
    STR = 287
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 29 "myparser.y" /* yacc.c:1909  */

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

#line 124 "myparser.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MYPARSER_TAB_H_INCLUDED  */
