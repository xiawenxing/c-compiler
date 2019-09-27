/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "myparser.y" /* yacc.c:339  */

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


#line 94 "myparser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "myparser.tab.h".  */
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
#line 29 "myparser.y" /* yacc.c:355  */

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

#line 204 "myparser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MYPARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 221 "myparser.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  18
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   324

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  159

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   287

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,    33,     2,    45,     2,     2,
      37,    38,    43,    41,    35,    42,     2,    44,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    34,
       2,    36,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,    40,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   136,   136,   142,   148,   159,   168,   177,   186,   196,
     206,   213,   220,   229,   259,   264,   274,   283,   295,   325,
     353,   381,   410,   415,   425,   453,   454,   455,   456,   457,
     458,   460,   469,   479,   484,   494,   504,   514,   524,   536,
     546,   557,   568,   580,   585,   594,   599,   610,   621,   624,
     627,   630,   633,   636,   639,   642,   647,   659,   670,   670,
     672,   684,   695,   695,   695,   697,   706,   714,   722,   732,
     733,   733,   735,   744,   754,   764,   774,   784,   794,   803,
     815,   826,   835,   846,   851,   861,   874,   884,   897,   907,
     918,   928,   938,   949,   953
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTNUM", "DOUNUM", "IDEN", "FILENAME",
  "STRING", "BOOLVAL", "CHARACTER", "DEFINE", "INCLUDE", "CHAR", "_VOID",
  "INT", "DOUBLE", "BOOL", "ELSE", "IF", "RETURN", "WHILE", "FOR", "LT",
  "GT", "SI", "SD", "LE", "GE", "EQ", "NE", "OR", "AND", "STR", "'#'",
  "';'", "','", "'='", "'('", "')'", "'{'", "'}'", "'+'", "'-'", "'*'",
  "'/'", "'%'", "$accept", "program", "declarations", "decl", "defi_decl",
  "incl_decl", "var_decl", "var_list", "vardef", "func_decl", "paralist",
  "para", "datatype", "block", "stmts", "stmt", "expressions",
  "expression", "logi_op", "num_exp", "addop", "term", "mulop",
  "unary_exp", "unaryop", "selfop", "factor", "var", "funcall", "args",
  "assign_stmt", "if_stmt", "while_stmt", "for_stmt", "return_stmt", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,    35,    59,    44,    61,    40,    41,   123,
     125,    43,    45,    42,    47,    37
};
# endif

#define YYPACT_NINF -97

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-97)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     280,   -97,   -97,   -97,   -97,   -97,   -97,    -1,    22,   280,
     -97,   -97,   -97,   -97,   -97,    24,    50,    46,   -97,   -97,
      69,    73,   -97,   282,   -97,   107,   282,    72,   -97,    54,
     -97,   -97,    26,   -97,   -97,   -97,   -97,   -97,   282,   -97,
     -97,    -3,    55,   -97,     9,     9,   110,   -97,   -97,    38,
      47,   -97,    37,   -27,   -97,    74,    53,   -97,    40,    36,
     -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,   -97,
     282,   282,   -97,   -97,   -97,   282,   -97,   -97,   -97,   -97,
     -97,   -97,   112,   -97,    18,    56,   -97,   -97,   -97,    45,
     -97,    97,    55,   -97,    44,   232,    59,    65,   -97,   -97,
     280,   -97,   152,   -97,    79,    57,    82,   -97,   -97,   -97,
     -97,   -97,   -97,   -97,   -97,   282,   -97,   282,   -97,    95,
     282,     2,   -97,   -97,   282,   -97,   282,   -97,   104,   -97,
     105,   -97,   282,    82,   282,   113,   114,   192,   192,   116,
     119,   -97,   -97,   141,   -97,   239,   246,   192,   192,   124,
     192,   125,   -97,   -97,   192,   -97,   192,   -97,   -97
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    27,    25,    26,    28,    29,    30,     0,     0,     2,
       4,     7,     8,     5,     6,     0,     0,     0,     1,     3,
      16,     0,    15,     0,    11,     0,     0,     0,    13,     0,
      75,    76,    80,    77,    78,    79,    70,    71,     0,    69,
       9,    47,    57,    61,     0,     0,    66,    73,    74,     0,
       0,    17,     0,     0,    23,     0,    16,    14,     0,     0,
      49,    50,    48,    51,    52,    53,    54,    55,    58,    59,
       0,     0,    62,    63,    64,     0,    65,    67,    68,    12,
      10,    21,     0,    20,     0,     0,    24,    81,    84,     0,
      72,    46,    56,    60,     0,     0,     0,     0,    45,    32,
      35,    38,     0,    34,    36,     0,    73,    37,    39,    40,
      41,    42,    22,    19,    18,     0,    82,     0,    93,     0,
       0,     0,    31,    33,     0,    44,     0,    83,     0,    94,
       0,    80,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    43,    85,    86,    88,     0,     0,     0,     0,     0,
       0,     0,    87,    92,     0,    91,     0,    90,    89
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -97,   -97,   169,    -7,   -97,   -97,   -97,   -97,   145,   -97,
     -97,    91,   -22,   -48,   -97,   -96,   -97,   -23,   -97,   108,
     -97,   109,   -97,   106,   -97,   133,    96,   -81,   -97,   -97,
      61,   -97,   -97,   -97,   -97
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     8,   100,    10,    11,    12,    13,    21,    22,    14,
      53,    54,    15,   101,   102,   103,   104,   105,    70,    41,
      71,    42,    75,    43,    44,    45,    46,    47,    48,    89,
     107,   108,   109,   110,   111
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      40,   106,    19,    51,    83,    55,   123,   131,    84,    16,
      17,    85,    30,    31,    32,    59,    33,    34,    35,    60,
      61,   106,    18,    62,    63,    64,    65,    66,    67,    20,
       1,     2,     3,     4,     5,    88,   132,   114,    68,    69,
     133,   143,   144,    30,    31,    32,    38,    33,    34,    35,
       6,   152,   153,    24,   155,    23,   106,   106,   157,    56,
     158,    79,    55,    58,    36,    37,   106,   106,    25,   106,
      80,    81,   119,   106,    90,   106,    82,    38,    87,    86,
     115,   117,    39,   116,     1,     2,     3,     4,     5,    26,
     113,   125,   127,    19,   128,    82,   120,   130,    72,    73,
      74,   135,   121,   136,     6,    26,    27,    28,    29,   139,
      52,   140,    49,    50,   124,    30,    31,    32,   126,    33,
      34,    35,   149,   151,     1,     2,     3,     4,     5,   129,
      94,    95,    96,    97,    36,    37,    36,    37,    68,    69,
      76,    77,   137,   138,     6,     7,    98,   141,   142,    38,
     145,    82,    99,   146,    39,    30,    31,    32,   147,    33,
      34,    35,   154,   156,     1,     2,     3,     4,     5,     9,
      94,    95,    96,    97,    57,   112,    36,    37,    91,    78,
      92,    93,   134,     0,     6,     7,    98,     0,     0,    38,
       0,    82,   122,     0,    39,    30,    31,    32,     0,    33,
      34,    35,     0,     0,     1,     2,     3,     4,     5,     0,
      94,    95,    96,    97,     0,     0,    36,    37,     0,     0,
       0,     0,     0,     0,     6,     7,    98,     0,     0,    38,
       0,    82,     0,     0,    39,    30,    31,    32,     0,    33,
      34,    35,    30,    31,    32,     0,    33,    34,    35,    30,
      31,    32,     0,    33,    34,    35,    36,    37,     0,     0,
       0,     0,     0,    36,    37,     0,   118,     0,     0,    38,
      36,    37,     0,     0,    39,     0,    38,   148,     0,     0,
       0,    39,     0,    38,   150,    30,    31,    32,    39,    33,
      34,    35,     1,     2,     3,     4,     5,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    36,    37,     0,     0,
       0,     0,     6,     7,     0,     0,     0,     0,     0,    38,
       0,     0,     0,     0,    39
};

static const yytype_int16 yycheck[] =
{
      23,    82,     9,    26,    52,    27,   102,     5,    35,    10,
      11,    38,     3,     4,     5,    38,     7,     8,     9,    22,
      23,   102,     0,    26,    27,    28,    29,    30,    31,     5,
      12,    13,    14,    15,    16,    58,    34,    85,    41,    42,
     121,   137,   138,     3,     4,     5,    37,     7,     8,     9,
      32,   147,   148,     7,   150,     5,   137,   138,   154,     5,
     156,    23,    84,    37,    24,    25,   147,   148,    22,   150,
      23,    34,    95,   154,    38,   156,    39,    37,    38,     5,
      35,    37,    42,    38,    12,    13,    14,    15,    16,    36,
      34,    34,   115,   100,   117,    39,    37,   120,    43,    44,
      45,   124,    37,   126,    32,    36,    37,    34,    35,   132,
      38,   134,     5,     6,    35,     3,     4,     5,    36,     7,
       8,     9,   145,   146,    12,    13,    14,    15,    16,    34,
      18,    19,    20,    21,    24,    25,    24,    25,    41,    42,
      44,    45,    38,    38,    32,    33,    34,    34,    34,    37,
      34,    39,    40,    34,    42,     3,     4,     5,    17,     7,
       8,     9,    38,    38,    12,    13,    14,    15,    16,     0,
      18,    19,    20,    21,    29,    84,    24,    25,    70,    46,
      71,    75,   121,    -1,    32,    33,    34,    -1,    -1,    37,
      -1,    39,    40,    -1,    42,     3,     4,     5,    -1,     7,
       8,     9,    -1,    -1,    12,    13,    14,    15,    16,    -1,
      18,    19,    20,    21,    -1,    -1,    24,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    32,    33,    34,    -1,    -1,    37,
      -1,    39,    -1,    -1,    42,     3,     4,     5,    -1,     7,
       8,     9,     3,     4,     5,    -1,     7,     8,     9,     3,
       4,     5,    -1,     7,     8,     9,    24,    25,    -1,    -1,
      -1,    -1,    -1,    24,    25,    -1,    34,    -1,    -1,    37,
      24,    25,    -1,    -1,    42,    -1,    37,    38,    -1,    -1,
      -1,    42,    -1,    37,    38,     3,     4,     5,    42,     7,
       8,     9,    12,    13,    14,    15,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    24,    25,    -1,    -1,
      -1,    -1,    32,    33,    -1,    -1,    -1,    -1,    -1,    37,
      -1,    -1,    -1,    -1,    42
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    12,    13,    14,    15,    16,    32,    33,    47,    48,
      49,    50,    51,    52,    55,    58,    10,    11,     0,    49,
       5,    53,    54,     5,     7,    22,    36,    37,    34,    35,
       3,     4,     5,     7,     8,     9,    24,    25,    37,    42,
      63,    65,    67,    69,    70,    71,    72,    73,    74,     5,
       6,    63,    38,    56,    57,    58,     5,    54,    37,    63,
      22,    23,    26,    27,    28,    29,    30,    31,    41,    42,
      64,    66,    43,    44,    45,    68,    72,    72,    71,    23,
      23,    34,    39,    59,    35,    38,     5,    38,    63,    75,
      38,    65,    67,    69,    18,    19,    20,    21,    34,    40,
      48,    59,    60,    61,    62,    63,    73,    76,    77,    78,
      79,    80,    57,    34,    59,    35,    38,    37,    34,    63,
      37,    37,    40,    61,    35,    34,    36,    63,    63,    34,
      63,     5,    34,    73,    76,    63,    63,    38,    38,    63,
      63,    34,    34,    61,    61,    34,    34,    17,    38,    63,
      38,    63,    61,    61,    38,    61,    38,    61,    61
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    49,    49,    50,
      51,    51,    51,    52,    53,    53,    54,    54,    55,    55,
      55,    55,    56,    56,    57,    58,    58,    58,    58,    58,
      58,    59,    59,    60,    60,    61,    61,    61,    61,    61,
      61,    61,    61,    62,    62,    62,    63,    63,    64,    64,
      64,    64,    64,    64,    64,    64,    65,    65,    66,    66,
      67,    67,    68,    68,    68,    69,    69,    69,    69,    70,
      71,    71,    72,    72,    72,    72,    72,    72,    72,    72,
      73,    74,    74,    75,    75,    76,    77,    77,    78,    79,
      79,    79,    79,    80,    80
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     4,
       5,     3,     5,     3,     3,     1,     1,     3,     6,     6,
       5,     5,     3,     1,     2,     1,     1,     1,     1,     1,
       1,     3,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     2,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     1,
       3,     1,     1,     1,     1,     2,     1,     2,     2,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     4,     3,     1,     4,     5,     7,     5,     8,
       8,     7,     7,     2,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 137 "myparser.y" /* yacc.c:1646  */
    { 
			Root = (yyvsp[0].decls);  
			Root->printNode(0,fout);
		}
#line 1447 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 143 "myparser.y" /* yacc.c:1646  */
    { 
				(yyval.decls) = (yyvsp[-1].decls); 
				(yyval.decls)->list.push_back(*(yyvsp[0].decl));
				
			}
#line 1457 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 149 "myparser.y" /* yacc.c:1646  */
    {  
				(yyval.decls) = new DeclaListNode();
				(yyval.decls)->list.push_back(*(yyvsp[0].decl));	
				//$$->height = $1->height+1;
				(yyval.decls)->nodename = "declarations";
				(yyval.decls)->content ="("+to_string(yylineno)+","+(yyval.decls)->nodename+")";
				cout<<(yyval.decls)->content<<endl;
			}
#line 1470 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 160 "myparser.y" /* yacc.c:1646  */
    {
		(yyval.decl) = new Declaration();		
		(yyval.decl)->ptrNext = (yyvsp[0].vars);
		//$$->height = $1->height+1;
		(yyval.decl)->nodename = "decl";
		(yyval.decl)->content ="("+to_string(yylineno)+","+(yyval.decl)->nodename+")";
		cout<<(yyval.decl)->content<<endl;
	}
#line 1483 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 169 "myparser.y" /* yacc.c:1646  */
    {
		
		(yyval.decl) = new Declaration();		
		(yyval.decl)->ptrNext = (yyvsp[0].funcdecla);
		//$$->height = $1->height+1;
		(yyval.decl)->nodename = "decl";
		(yyval.decl)->content ="("+to_string(yylineno)+","+(yyval.decl)->nodename+")";
		cout<<(yyval.decl)->content<<endl;
	}
#line 1497 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 178 "myparser.y" /* yacc.c:1646  */
    {
		(yyval.decl) = new Declaration();		
		(yyval.decl)->ptrNext = (yyvsp[0].defi);
		//$$->height = $1->height+1;
		(yyval.decl)->nodename = "decl";
		(yyval.decl)->content ="("+to_string(yylineno)+","+(yyval.decl)->nodename+")";
		cout<<(yyval.decl)->content<<endl;
		
	}
#line 1511 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 187 "myparser.y" /* yacc.c:1646  */
    {
		(yyval.decl) = new Declaration();		
		(yyval.decl)->ptrNext = (yyvsp[0].incl);
		//$$->height = $1->height+1;
		(yyval.decl)->nodename = "decl";
		(yyval.decl)->content ="("+to_string(yylineno)+","+(yyval.decl)->nodename+")";
		cout<<(yyval.decl)->content<<endl;
	}
#line 1524 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 197 "myparser.y" /* yacc.c:1646  */
    {
		(yyval.defi) = new PreDefi();
		(yyval.defi)->left = string((yyvsp[-1].iden));
		(yyval.defi)->rightval = (yyvsp[0].expr);
		(yyval.defi)->nodename = "defi_decl";
		(yyval.defi)->content = "(" + to_string(yylineno)+","+(yyval.defi)->nodename+","+(yyval.defi)->left+")";
		cout<<(yyval.defi)->content<<endl;
	}
#line 1537 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 207 "myparser.y" /* yacc.c:1646  */
    {
		(yyval.incl) = new HeadFile();
		(yyval.incl)->filename = string((yyvsp[-1].filename));
		(yyval.incl)->nodename = "incl_decl";
		(yyval.incl)->content = "(" + to_string(yylineno)+","+(yyval.incl)->nodename+","+(yyval.incl)->filename+")";
		cout<<(yyval.incl)->content<<endl;
	}
#line 1549 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 214 "myparser.y" /* yacc.c:1646  */
    {
		(yyval.incl) = new HeadFile();
		(yyval.incl)->filename = (yyvsp[0].strnode)->value;
		(yyval.incl)->nodename = "incl_decl";
		(yyval.incl)->content = "(" + to_string(yylineno)+","+(yyval.incl)->nodename+","+(yyval.incl)->filename+")";
		cout<<(yyval.incl)->content<<endl;
	}
#line 1561 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 221 "myparser.y" /* yacc.c:1646  */
    {
		(yyval.incl) = new HeadFile();
		(yyval.incl)->filename = string((yyvsp[-1].iden));
		(yyval.incl)->nodename = "incl_decl";
		(yyval.incl)->content = "(" + to_string(yylineno)+","+(yyval.incl)->nodename+","+(yyval.incl)->filename+")";
		cout<<(yyval.incl)->content<<endl;
	}
#line 1573 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 230 "myparser.y" /* yacc.c:1646  */
    {
		(yyval.vars) = new VariaDecla();
		//$$->height = $2->height+1;
		(yyval.vars)->nodename = "var_decl";
		(yyval.vars)->list = (yyvsp[-1].varlist);
		(yyval.vars)->content ="("+to_string(yylineno)+","+(yyval.vars)->nodename+")";
		cout<<(yyval.vars)->content<<endl;

		switch((yyvsp[-2].comint))
		{
			case 1:// void
				(yyvsp[-1].varlist)->type = "VOID";
				break;
			case 2:// int
				(yyvsp[-1].varlist)->type = "INT";
				break;
			case 3:// char
				(yyvsp[-1].varlist)->type = "CHAR";
				break;
			case 4:// double
				(yyvsp[-1].varlist)->type = "DOUBLE";
				break;
			case 5:
				(yyvsp[-1].varlist)->type = "BOOL";
		}
		(yyvsp[-1].varlist)->content ="("+to_string(yylineno)+","+(yyval.vars)->nodename+","+(yyvsp[-1].varlist)->type+")";
		cout<<(yyvsp[-1].varlist)->content<<endl;
	}
#line 1606 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 260 "myparser.y" /* yacc.c:1646  */
    {
			(yyval.varlist) = (yyvsp[-2].varlist);
			(yyval.varlist)->list.push_back(*(yyvsp[0].var)); 
		}
#line 1615 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 265 "myparser.y" /* yacc.c:1646  */
    {
			(yyval.varlist) = new VariaListNode();
			(yyval.varlist)->nodename = "var_list";
			//$$->height = $1->height+1;
			(yyval.varlist)->list.push_back(*(yyvsp[0].var));
			(yyval.varlist)->content ="("+to_string(yylineno)+","+(yyval.varlist)->nodename+")";
			cout<<(yyval.varlist)->content<<endl;
		}
#line 1628 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 275 "myparser.y" /* yacc.c:1646  */
    {
			(yyval.var) = new Variable();
			(yyval.var)->nodename = "vardef";
			(yyval.var)->name = string((yyvsp[0].iden));
			//$$->height = 0;
			(yyval.var)->content ="("+to_string(yylineno)+","+(yyval.var)->nodename+","+(yyval.var)->name+")";
			cout<<(yyval.var)->content<<endl;
		}
#line 1641 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 284 "myparser.y" /* yacc.c:1646  */
    {
			(yyval.var) = new Variable();
			(yyval.var)->nodename = "vardef";
			//$$->height = 0;
			(yyval.var)->name = string((yyvsp[-2].iden));///////////////////////
			(yyval.var)->ptrexpr = (yyvsp[0].expr);
			(yyval.var)->content ="("+to_string(yylineno)+","+(yyval.var)->nodename+","+(yyval.var)->name+")";
			cout<<(yyval.var)->content<<endl;
		}
#line 1655 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 296 "myparser.y" /* yacc.c:1646  */
    {
				(yyval.funcdecla) = new FuncDecla();
				(yyval.funcdecla)->nodename = "func_decl";
				//$$->height = max($4->height,$6->height)+1;
				(yyval.funcdecla)->name = string((yyvsp[-4].iden));
				(yyval.funcdecla)->paras = (yyvsp[-2].varlist);
				(yyval.funcdecla)->block = (yyvsp[0].blo);
	
				switch((yyvsp[-5].comint))
				{
					case 1:// void
					(yyval.funcdecla)->returnval.type = "VOID";
					break;
					case 2:// int
					(yyval.funcdecla)->returnval.type = "INT";
					break;
					case 3:// char
					(yyval.funcdecla)->returnval.type = "CHAR";
					break;
					case 4:// double
					(yyval.funcdecla)->returnval.type = "DOUBLE";
					break;
					case 5:
					(yyval.funcdecla)->returnval.type = "BOOL";
				}
			
				(yyval.funcdecla)->content ="("+to_string(yylineno)+","+(yyval.funcdecla)->nodename+","+(yyval.funcdecla)->name+","+(yyval.funcdecla)->returnval.type+")";
				cout<<(yyval.funcdecla)->content<<endl;
			}
#line 1689 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 326 "myparser.y" /* yacc.c:1646  */
    {
				(yyval.funcdecla) = new FuncDecla();
				(yyval.funcdecla)->nodename = "func_decl";
				//$$->height = $4->height+1;
				(yyval.funcdecla)->name = string((yyvsp[-4].iden));
				(yyval.funcdecla)->paras = (yyvsp[-2].varlist);
				switch((yyvsp[-5].comint))
				{
					case 1:// void
					(yyval.funcdecla)->returnval.type = "VOID";
					break;
					case 2:// int
					(yyval.funcdecla)->returnval.type = "INT";
					break;
					case 3:// char
					(yyval.funcdecla)->returnval.type = "CHAR";
					break;
					case 4:// double
					(yyval.funcdecla)->returnval.type = "DOUBLE";
					break;
					case 5:
					(yyval.funcdecla)->returnval.type = "BOOL";
				}
				
				(yyval.funcdecla)->content ="("+to_string(yylineno)+","+(yyval.funcdecla)->nodename+","+(yyval.funcdecla)->name+","+(yyval.funcdecla)->returnval.type+")";
				cout<<(yyval.funcdecla)->content<<endl;
			}
#line 1721 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 354 "myparser.y" /* yacc.c:1646  */
    {
				(yyval.funcdecla) = new FuncDecla();
				(yyval.funcdecla)->nodename = "func_decl";
				//$$->height = $5->height+1;
				(yyval.funcdecla)->name = string((yyvsp[-3].iden));
				(yyval.funcdecla)->block = (yyvsp[0].blo);
				switch((yyvsp[-4].comint))
				{
					case 1:// void
					(yyval.funcdecla)->returnval.type = "VOID";
					break;
					case 2:// int
					(yyval.funcdecla)->returnval.type = "INT";
					break;
					case 3:// char
					(yyval.funcdecla)->returnval.type = "CHAR";
					break;
					case 4:// double
					(yyval.funcdecla)->returnval.type = "DOUBLE";
					break;
					case 5:
					(yyval.funcdecla)->returnval.type = "BOOL";
				}
				
				(yyval.funcdecla)->content ="("+to_string(yylineno)+","+(yyval.funcdecla)->nodename+","+(yyval.funcdecla)->name+","+(yyval.funcdecla)->returnval.type+")";
				cout<<(yyval.funcdecla)->content<<endl;
			}
#line 1753 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 382 "myparser.y" /* yacc.c:1646  */
    {
				(yyval.funcdecla) = new FuncDecla();
				(yyval.funcdecla)->nodename = "func_decl";
				//$$->height = 0;
				(yyval.funcdecla)->name = string((yyvsp[-3].iden));
				switch((yyvsp[-4].comint))
				{
					case 1:// void
					(yyval.funcdecla)->returnval.type = "VOID";
					break;
					case 2:// int
					(yyval.funcdecla)->returnval.type = "INT";
					break;
					case 3:// char
					(yyval.funcdecla)->returnval.type = "CHAR";
					break;
					case 4:// double
					(yyval.funcdecla)->returnval.type = "DOUBLE";
					break;
					case 5:
					(yyval.funcdecla)->returnval.type = "BOOL";
				}
				
				(yyval.funcdecla)->content ="("+to_string(yylineno)+","+(yyval.funcdecla)->nodename+","+(yyval.funcdecla)->name+","+(yyval.funcdecla)->returnval.type+")";
				cout<<(yyval.funcdecla)->content<<endl;
				
			}
#line 1785 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 411 "myparser.y" /* yacc.c:1646  */
    {
				(yyval.varlist) = (yyvsp[-2].varlist);
				(yyvsp[-2].varlist)->list.push_back(*(yyvsp[0].var));
			}
#line 1794 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 416 "myparser.y" /* yacc.c:1646  */
    {
				(yyval.varlist) = new VariaListNode();
				(yyval.varlist)->list.push_back(*(yyvsp[0].var));
				//$$->height = $1->height+1;
				(yyval.varlist)->nodename = "paralist";
				(yyval.varlist)->content ="("+to_string(yylineno)+","+(yyval.varlist)->nodename+")";
				cout<<(yyval.varlist)->content<<endl;
			}
#line 1807 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 426 "myparser.y" /* yacc.c:1646  */
    {
			(yyval.var) = new Variable();
			(yyval.var)->name = string((yyvsp[0].iden));
			//$$->height = 0;
			(yyval.var)->nodename = "para";
			switch((yyvsp[-1].comint))
			{
			case 1:// void
				(yyval.var)->type = "VOID";
				break;
			case 2:// int
				(yyval.var)->type = "INT";
				break;
			case 3:// char
				(yyval.var)->type = "CHAR";
				break;
			case 4:// double
				(yyval.var)->type = "DOUBLE";
				break;
			case 5:
				(yyval.var)->type = "BOOL";
				break;
			}
			(yyval.var)->content ="("+to_string(yylineno)+","+(yyval.var)->nodename+","+(yyval.var)->type+","+(yyval.var)->name+")";
			cout<<(yyval.var)->content<<endl;
		}
#line 1838 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 453 "myparser.y" /* yacc.c:1646  */
    { (yyval.comint) = 1; }
#line 1844 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 454 "myparser.y" /* yacc.c:1646  */
    { (yyval.comint) = 2;}
#line 1850 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 455 "myparser.y" /* yacc.c:1646  */
    { (yyval.comint) = 3;}
#line 1856 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 456 "myparser.y" /* yacc.c:1646  */
    { (yyval.comint) = 4; }
#line 1862 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 457 "myparser.y" /* yacc.c:1646  */
    {(yyval.comint) = 5;}
#line 1868 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 458 "myparser.y" /* yacc.c:1646  */
    {(yyval.comint) = 6;}
#line 1874 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 461 "myparser.y" /* yacc.c:1646  */
    {
			(yyval.blo) = new Block();
			(yyval.blo)->stmtlist = (yyvsp[-1].stalist);
			//$$->height = $2->height+1;
			(yyval.blo)->nodename = "block";
			(yyval.blo)->content ="("+to_string(yylineno)+","+(yyval.blo)->nodename+")";
			cout<<(yyval.blo)->content<<endl;
			
		}
#line 1888 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 470 "myparser.y" /* yacc.c:1646  */
    {
			(yyval.blo) = new Block();
			(yyval.blo)->stmtlist = NULL;
			//$$->height = 0;
			(yyval.blo)->nodename = "block";
			(yyval.blo)->content ="("+to_string(yylineno)+","+(yyval.blo)->nodename+")";
			cout<<(yyval.blo)->content<<endl;
		}
#line 1901 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 480 "myparser.y" /* yacc.c:1646  */
    {
			(yyval.stalist) = (yyvsp[-1].stalist);
			(yyvsp[-1].stalist)->list.push_back(*(yyvsp[0].stat));
		}
#line 1910 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 485 "myparser.y" /* yacc.c:1646  */
    {
			(yyval.stalist) = new StateListNode();
			(yyval.stalist)->list.push_back(*(yyvsp[0].stat));
			//$$->height = $1->height+1;
			(yyval.stalist)->nodename = "stmts";
			(yyval.stalist)->content ="("+to_string(yylineno)+","+(yyval.stalist)->nodename+")";
			cout<<(yyval.stalist)->content<<endl;
		}
#line 1923 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 495 "myparser.y" /* yacc.c:1646  */
    {
			(yyval.stat) = new Statement();
			(yyval.stat)->type = "decl";
			(yyval.stat)->nodename = "stmt";
			(yyval.stat)->ptrstmt = (yyvsp[0].decls);
			//$$->height = $1->height+1;
			(yyval.stat)->content ="("+to_string(yylineno)+","+(yyval.stat)->nodename+","+(yyval.stat)->type+")";
			cout<<(yyval.stat)->content<<endl;
		}
#line 1937 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 505 "myparser.y" /* yacc.c:1646  */
    {
			(yyval.stat) = new Statement();
			(yyval.stat)->type = "expr";
			(yyval.stat)->nodename = "stmt";
			(yyval.stat)->ptrstmt = (yyvsp[0].exprs);
			//$$->height = $1->height+1;
			(yyval.stat)->content ="("+to_string(yylineno)+","+(yyval.stat)->nodename+","+(yyval.stat)->type+")";
			cout<<(yyval.stat)->content<<endl;
		}
#line 1951 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 515 "myparser.y" /* yacc.c:1646  */
    {
			(yyval.stat) = new Statement();
			(yyval.stat)->type = "assi";
			(yyval.stat)->nodename = "stmt";
			(yyval.stat)->ptrstmt = (yyvsp[0].assign);
			//$$->height = $1->height+1;
			(yyval.stat)->content ="("+to_string(yylineno)+","+(yyval.stat)->nodename+","+(yyval.stat)->type+")";
			cout<<(yyval.stat)->content<<endl;
		}
#line 1965 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 525 "myparser.y" /* yacc.c:1646  */
    {
			(yyval.stat) = new Statement();
			(yyval.stat)->type = "bloc";
			(yyval.stat)->nodename = "stmt";
			(yyval.stat)->ptrstmt = (yyvsp[0].blo);
			//$$->height = $1->height+1;
			(yyval.stat)->content ="("+to_string(yylineno)+","+(yyval.stat)->nodename+","+(yyval.stat)->type+")";
			cout<<(yyval.stat)->content<<endl;

		}
#line 1980 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 537 "myparser.y" /* yacc.c:1646  */
    {
			(yyval.stat) = new Statement();
			(yyval.stat)->type = "ifst";
			(yyval.stat)->nodename = "stmt";
			(yyval.stat)->ptrstmt = (yyvsp[0].ifstmt);
			//$$->height = $1->height+1;
			(yyval.stat)->content ="("+to_string(yylineno)+","+(yyval.stat)->nodename+","+(yyval.stat)->type+")";
			cout<<(yyval.stat)->content<<endl;
		 }
#line 1994 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 547 "myparser.y" /* yacc.c:1646  */
    {
			(yyval.stat) = new Statement();
			(yyval.stat)->type = "wlst";
			(yyval.stat)->nodename = "stmt";
			(yyval.stat)->ptrstmt = (yyvsp[0].whilestmt);
			//$$->height = $1->height+1;
			(yyval.stat)->content ="("+to_string(yylineno)+","+(yyval.stat)->nodename+","+(yyval.stat)->type+")";
			cout<<(yyval.stat)->content<<endl;

		 }
#line 2009 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 558 "myparser.y" /* yacc.c:1646  */
    {
			(yyval.stat) = new Statement();
			(yyval.stat)->type = "forst";
			(yyval.stat)->nodename = "stmt";
			(yyval.stat)->ptrstmt = (yyvsp[0].forstmt);
			//$$->height = $1->height+1;
			(yyval.stat)->content ="("+to_string(yylineno)+","+(yyval.stat)->nodename+","+(yyval.stat)->type+")";
			cout<<(yyval.stat)->content<<endl;

		}
#line 2024 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 569 "myparser.y" /* yacc.c:1646  */
    {
			(yyval.stat) = new Statement();
			(yyval.stat)->type = "rest";
			(yyval.stat)->nodename = "stmt";
			(yyval.stat)->ptrstmt = (yyvsp[0].returnstmt);
			//$$->height = $1->height+1;
			(yyval.stat)->content ="("+to_string(yylineno)+","+(yyval.stat)->nodename+","+(yyval.stat)->type+")";
			cout<<(yyval.stat)->content<<endl;

		 }
#line 2039 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 581 "myparser.y" /* yacc.c:1646  */
    {
				(yyval.exprs) = (yyvsp[-3].exprs);
				(yyvsp[-3].exprs)->list.push_back(*(yyvsp[-1].expr));
			}
#line 2048 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 586 "myparser.y" /* yacc.c:1646  */
    {
				(yyval.exprs) = new ExpreListNode();
				(yyval.exprs)->nodename = "expressions";
				(yyval.exprs)->list.push_back(*(yyvsp[-1].expr));
				//$$->height = $1->height+1;
				(yyval.exprs)->content ="("+to_string(yylineno)+","+(yyval.exprs)->nodename+")";
				cout<<(yyval.exprs)->content<<endl;
			}
#line 2061 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 595 "myparser.y" /* yacc.c:1646  */
    {	
	
			}
#line 2069 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 600 "myparser.y" /* yacc.c:1646  */
    {
				(yyval.expr) = new Expression();
				(yyval.expr)->nodename = "expression";
				//$$->height = max($1->height,$3->height)+1;
				(yyval.expr)->leftnode = (yyvsp[-2].expr);
				(yyval.expr)->rightnode = (yyvsp[0].expr);
				(yyval.expr)->op = string((yyvsp[-1].oper));
				(yyval.expr)->content ="("+to_string(yylineno)+","+(yyval.expr)->nodename+")";
				cout<<(yyval.expr)->content<<endl;
			}
#line 2084 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 611 "myparser.y" /* yacc.c:1646  */
    {
				(yyval.expr) = new Expression();
				(yyval.expr)->nodename = "expression";
				//$$->nodename = $1->height+1;
				(yyval.expr)->leftnode = (yyvsp[0].expr);
				(yyval.expr)->content ="("+to_string(yylineno)+","+(yyval.expr)->nodename+")";
				cout<<(yyval.expr)->content<<endl;
			}
#line 2097 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 622 "myparser.y" /* yacc.c:1646  */
    {
				(yyval.oper) = "<=";
			}
#line 2105 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 625 "myparser.y" /* yacc.c:1646  */
    {
				(yyval.oper) = "<";
			}
#line 2113 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 628 "myparser.y" /* yacc.c:1646  */
    {
				(yyval.oper) = ">";
			}
#line 2121 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 631 "myparser.y" /* yacc.c:1646  */
    {
				(yyval.oper) = ">=";
			}
#line 2129 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 634 "myparser.y" /* yacc.c:1646  */
    {
				(yyval.oper) = "==";
			}
#line 2137 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 637 "myparser.y" /* yacc.c:1646  */
    {
				(yyval.oper) = "!=";
			}
#line 2145 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 640 "myparser.y" /* yacc.c:1646  */
    {
				(yyval.oper) = "||";
			}
#line 2153 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 643 "myparser.y" /* yacc.c:1646  */
    {
				(yyval.oper) = "&&";
			}
#line 2161 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 648 "myparser.y" /* yacc.c:1646  */
    {
			(yyval.expr) = new Expression();
			(yyval.expr)->leftnode = (yyvsp[-2].expr);
			(yyval.expr)->op = string((yyvsp[-1].oper));
			(yyval.expr)->rightnode = (yyvsp[0].expr);
			//$$->height = max($1->height,$3->height)+1;
			(yyval.expr)->nodename = "num_exp";
			
			(yyval.expr)->content ="("+to_string(yylineno)+","+(yyval.expr)->nodename+")";
			cout<<(yyval.expr)->content<<endl;
			
		}
#line 2178 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 660 "myparser.y" /* yacc.c:1646  */
    {
			(yyval.expr) = new Expression();
			(yyval.expr)->leftnode = (yyvsp[0].expr);
			//$$->height = $1->height+1;
			(yyval.expr)->nodename = "num_exp";
			
			(yyval.expr)->content ="("+to_string(yylineno)+","+(yyval.expr)->nodename+")";
			cout<<(yyval.expr)->content<<endl;
		}
#line 2192 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 670 "myparser.y" /* yacc.c:1646  */
    {(yyval.oper) = "+";}
#line 2198 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 670 "myparser.y" /* yacc.c:1646  */
    {(yyval.oper) = "-";}
#line 2204 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 673 "myparser.y" /* yacc.c:1646  */
    {
			(yyval.expr) = new Expression();
			(yyval.expr)->leftnode = (yyvsp[-2].expr);
			(yyval.expr)->op = string((yyvsp[-1].oper));
			(yyval.expr)->rightnode = (yyvsp[0].expr);
			//$$->height = max($1->height,$3->height)+1;
			(yyval.expr)->nodename = "term";

			(yyval.expr)->content ="("+to_string(yylineno)+","+(yyval.expr)->nodename+")";
			cout<<(yyval.expr)->content<<endl;
			
		}
#line 2221 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 685 "myparser.y" /* yacc.c:1646  */
    {
			(yyval.expr) = new Expression();
			(yyval.expr)->leftnode = (yyvsp[0].expr);
			//$$->height = $1->height+1;
			(yyval.expr)->nodename = "term";
			
			(yyval.expr)->content ="("+to_string(yylineno)+","+(yyval.expr)->nodename+")";
			cout<<(yyval.expr)->content<<endl;
		}
#line 2235 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 695 "myparser.y" /* yacc.c:1646  */
    {(yyval.oper) = "*";}
#line 2241 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 695 "myparser.y" /* yacc.c:1646  */
    {(yyval.oper) = "/";}
#line 2247 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 695 "myparser.y" /* yacc.c:1646  */
    {(yyval.oper) = "%";}
#line 2253 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 698 "myparser.y" /* yacc.c:1646  */
    {
				(yyval.expr) = new Expression();
				(yyval.expr)->op = string((yyvsp[-1].oper));
				(yyval.expr)->rightnode = (yyvsp[0].expr);
				//$$->height = $2->height+1;
				(yyval.expr)->nodename = "unary_exp";
				(yyval.expr)->content ="("+to_string(yylineno)+","+(yyval.expr)->nodename+","+(yyval.expr)->op+")";
				cout<<(yyval.expr)->content<<endl;
			}
#line 2267 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 707 "myparser.y" /* yacc.c:1646  */
    {
				(yyval.expr) = new Expression();
				(yyval.expr)->leftnode = (yyvsp[0].expr);
				//$$->height = $1->height+1;
				(yyval.expr)->nodename = "unary_exp";
				(yyval.expr)->content ="("+to_string(yylineno)+","+(yyval.expr)->nodename+")";
				cout<<(yyval.expr)->content<<endl;
			}
#line 2280 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 715 "myparser.y" /* yacc.c:1646  */
    {
				(yyval.expr) = new Expression();
				(yyval.expr)->rightnode = (yyvsp[0].expr);
				(yyval.expr)->op = string((yyvsp[-1].oper));
				(yyval.expr)->nodename = "unary_exp";
				(yyval.expr)->content ="("+to_string(yylineno)+","+(yyval.expr)->nodename+","+(yyval.expr)->op+")";
				cout<<(yyval.expr)->content<<endl;
			}
#line 2293 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 723 "myparser.y" /* yacc.c:1646  */
    {
				(yyval.expr) = new Expression();
				(yyval.expr)->leftnode = (yyvsp[-1].expr);
				(yyval.expr)->op = string((yyvsp[0].oper));
				(yyval.expr)->nodename = "unary_exp";
				(yyval.expr)->content ="("+to_string(yylineno)+","+(yyval.expr)->nodename+","+(yyval.expr)->op+")";
				cout<<(yyval.expr)->content<<endl;
			}
#line 2306 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 732 "myparser.y" /* yacc.c:1646  */
    {(yyval.oper) = "-";}
#line 2312 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 733 "myparser.y" /* yacc.c:1646  */
    {(yyval.oper) = "++";}
#line 2318 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 733 "myparser.y" /* yacc.c:1646  */
    {(yyval.oper) = "--";}
#line 2324 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 736 "myparser.y" /* yacc.c:1646  */
    {
			(yyval.expr) = new Expression();
			(yyval.expr)->leftnode = (yyvsp[-1].expr);
			//$$->height = $2->height+1;
			(yyval.expr)->nodename = "factor";
			
			(yyval.expr)->content ="("+to_string(yylineno)+","+(yyval.expr)->nodename+")";
			cout<<(yyval.expr)->content<<endl;
		}
#line 2338 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 745 "myparser.y" /* yacc.c:1646  */
    {
			(yyval.expr) = new Expression();
			(yyval.expr)->ptrvalue = (yyvsp[0].var);
			//$$->height = $1->height+1;
			(yyval.expr)->nodename = "factor";
			
			(yyval.expr)->content ="("+to_string(yylineno)+","+(yyval.expr)->nodename+")";
			cout<<(yyval.expr)->content<<endl;
		}
#line 2352 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 755 "myparser.y" /* yacc.c:1646  */
    {
			(yyval.expr) = new Expression();
			(yyval.expr)->ptrvalue = (yyvsp[0].func);
			//$$->height = $1->height+1;
			(yyval.expr)->nodename = "factor";
			
			(yyval.expr)->content ="("+to_string(yylineno)+","+(yyval.expr)->nodename+")";
			cout<<(yyval.expr)->content<<endl;
		}
#line 2366 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 765 "myparser.y" /* yacc.c:1646  */
    {
			(yyval.expr) = new Expression();
			(yyval.expr)->ptrvalue = (yyvsp[0].intnum);
			//$$->height = $1->height+1;
			(yyval.expr)->nodename = "factor";
			
			(yyval.expr)->content ="("+to_string(yylineno)+","+(yyval.expr)->nodename+")";
			cout<<(yyval.expr)->content<<endl;
		}
#line 2380 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 775 "myparser.y" /* yacc.c:1646  */
    {
			(yyval.expr) = new Expression();
			(yyval.expr)->ptrvalue = (yyvsp[0].dounum);
			//$$->height = $1->height+1;
			(yyval.expr)->nodename = "factor";
			
			(yyval.expr)->content ="("+to_string(yylineno)+","+(yyval.expr)->nodename+")";
			cout<<(yyval.expr)->content<<endl;
		}
#line 2394 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 785 "myparser.y" /* yacc.c:1646  */
    {
			(yyval.expr) = new Expression();
			(yyval.expr)->ptrvalue = (yyvsp[0].strnode);
			//$$->height = $1->height+1;
			(yyval.expr)->nodename = "factor";
			
			(yyval.expr)->content ="("+to_string(yylineno)+","+(yyval.expr)->nodename+")";
			cout<<(yyval.expr)->content<<endl;
		}
#line 2408 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 795 "myparser.y" /* yacc.c:1646  */
    {
			(yyval.expr) = new Expression();
			(yyval.expr)->ptrvalue = (yyvsp[0].boolnum);
			//$$->height = $1->height+1;
			(yyval.expr)->nodename = "factor";
			
			(yyval.expr)->content ="("+to_string(yylineno)+","+(yyval.expr)->nodename+")";
			cout<<(yyval.expr)->content<<endl;
		}
#line 2422 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 804 "myparser.y" /* yacc.c:1646  */
    {
			(yyval.expr) = new Expression();
			(yyval.expr)->ptrvalue = (yyvsp[0].cha);
			//$$->height = $1->height+1;
			(yyval.expr)->nodename = "factor";
			
			(yyval.expr)->content ="("+to_string(yylineno)+","+(yyval.expr)->nodename+")";
			cout<<(yyval.expr)->content<<endl;
		}
#line 2436 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 816 "myparser.y" /* yacc.c:1646  */
    {
		(yyval.var) = new Variable();
		(yyval.var)->name = string((yyvsp[0].iden));
		//$$->height = 0;
		(yyval.var)->nodename = "var";
		
		(yyval.var)->content ="("+to_string(yylineno)+","+(yyval.var)->nodename+","+(yyval.var)->name+")";
		cout<<(yyval.var)->content<<endl;
	}
#line 2450 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 827 "myparser.y" /* yacc.c:1646  */
    {
			(yyval.func) = new FunCall();
			(yyval.func)->funcname = string((yyvsp[-2].iden));
			//$$->height = 0;
			(yyval.func)->nodename = "var";
		
			(yyval.func)->content ="("+to_string(yylineno)+","+(yyval.func)->nodename+","+(yyval.func)->funcname+")";
			cout<<(yyval.func)->content<<endl;
		}
#line 2464 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 836 "myparser.y" /* yacc.c:1646  */
    {
			(yyval.func) = new FunCall();
			(yyval.func)->funcname = string((yyvsp[-3].iden));
			//$$->height = $3->height+1;
			(yyval.func)->nodename = "var";
			(yyval.func)->args = (yyvsp[-1].exprs);	
			(yyval.func)->content ="("+to_string(yylineno)+","+(yyval.func)->nodename+","+(yyval.func)->funcname+")";
			cout<<(yyval.func)->content<<endl;
		}
#line 2478 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 847 "myparser.y" /* yacc.c:1646  */
    {
		(yyval.exprs) = (yyvsp[-2].exprs);
		(yyvsp[-2].exprs)->list.push_back(*(yyvsp[0].expr));
	
	}
#line 2488 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 852 "myparser.y" /* yacc.c:1646  */
    {
		(yyval.exprs) = new ExpreListNode();
		(yyval.exprs)->list.push_back(*(yyvsp[0].expr));
		//$$->height = $1->height+1;
		(yyval.exprs)->nodename = "expressions";
		(yyval.exprs)->content ="("+to_string(yylineno)+","+(yyval.exprs)->nodename+")";
		cout<<(yyval.exprs)->content<<endl;
	}
#line 2501 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 862 "myparser.y" /* yacc.c:1646  */
    {
				(yyval.assign) = new Assignment();
				(yyval.assign)->leftnode = (yyvsp[-3].var);
				(yyval.assign)->rightnode = (yyvsp[-1].expr);
				(yyvsp[-3].var)->ptrexpr = (yyvsp[-1].expr);
			//	$$->height = max($1->height,$3->height)+1;
				(yyval.assign)->nodename = "assign_stmt";
				
				(yyval.assign)->content ="("+to_string(yylineno)+","+(yyval.assign)->nodename+")";
				cout<<(yyval.assign)->content<<endl;
			}
#line 2517 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 875 "myparser.y" /* yacc.c:1646  */
    {
				(yyval.ifstmt) = new If_Stmt();
				(yyval.ifstmt)->condition = (yyvsp[-2].expr);
				(yyval.ifstmt)->ifstmt = (yyvsp[0].stat);
			//	$$->height = max($5->height,$3->height)+1;
				(yyval.ifstmt)->nodename = "if_stmt";
				(yyval.ifstmt)->content ="("+to_string(yylineno)+","+(yyval.ifstmt)->nodename+")";
				cout<<(yyval.ifstmt)->content<<endl;

			}
#line 2532 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 885 "myparser.y" /* yacc.c:1646  */
    {
				(yyval.ifstmt) = new If_Stmt();
				(yyval.ifstmt)->condition = (yyvsp[-4].expr);
				(yyval.ifstmt)->ifstmt = (yyvsp[-2].stat);
				(yyval.ifstmt)->elstmt = (yyvsp[0].stat);
			//	$$->height = max($5->height,$3->height);
			//	$$->height = max($$->height,$7->height)+1;
 				(yyval.ifstmt)->nodename = "if_stmt";
				(yyval.ifstmt)->content ="("+to_string(yylineno)+","+(yyval.ifstmt)->nodename+")";
				cout<<(yyval.ifstmt)->content<<endl;
			}
#line 2548 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 898 "myparser.y" /* yacc.c:1646  */
    {
				(yyval.whilestmt) = new While_Stmt();
				(yyval.whilestmt)->condition = (yyvsp[-2].expr);
				(yyval.whilestmt)->stmt = (yyvsp[0].stat);
			//	$$->height = max($5->height,$3->height)+1;
				(yyval.whilestmt)->nodename = "while_stmt ";
				(yyval.whilestmt)->content ="("+to_string(yylineno)+","+(yyval.whilestmt)->nodename+")";
				cout<<(yyval.whilestmt)->content<<endl;
			}
#line 2562 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 908 "myparser.y" /* yacc.c:1646  */
    {
		(yyval.forstmt) = new For_Stmt();
		(yyval.forstmt)->before = (yyvsp[-5].assign);
		(yyval.forstmt)->condition = (yyvsp[-4].expr);
		(yyval.forstmt)->after = (yyvsp[-2].expr);
		(yyval.forstmt)->stmt = (yyvsp[0].stat);
		(yyval.forstmt)->nodename = "for_stmt";
		(yyval.forstmt)->content ="("+to_string(yylineno)+","+(yyval.forstmt)->nodename+")";
		cout<<(yyval.forstmt)->content<<endl;
	}
#line 2577 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 919 "myparser.y" /* yacc.c:1646  */
    {
		(yyval.forstmt) = new For_Stmt();
		(yyval.forstmt)->condition = (yyvsp[-4].expr);
		(yyval.forstmt)->after = (yyvsp[-2].expr);
		(yyval.forstmt)->stmt = (yyvsp[0].stat);
		(yyval.forstmt)->nodename = "for_stmt";
		(yyval.forstmt)->content ="("+to_string(yylineno)+","+(yyval.forstmt)->nodename+")";
		cout<<(yyval.forstmt)->content<<endl;
	}
#line 2591 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 929 "myparser.y" /* yacc.c:1646  */
    {
		(yyval.forstmt) = new For_Stmt();
		(yyval.forstmt)->before = (yyvsp[-4].assign);
		(yyval.forstmt)->condition = (yyvsp[-3].expr);
		(yyval.forstmt)->stmt = (yyvsp[0].stat);
		(yyval.forstmt)->nodename = "for_stmt";
		(yyval.forstmt)->content ="("+to_string(yylineno)+","+(yyval.forstmt)->nodename+")";
		cout<<(yyval.forstmt)->content<<endl;
	}
#line 2605 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 939 "myparser.y" /* yacc.c:1646  */
    {
		(yyval.forstmt) = new For_Stmt();
		(yyval.forstmt)->condition = (yyvsp[-3].expr);
		(yyval.forstmt)->stmt = (yyvsp[0].stat);
		(yyval.forstmt)->nodename = "for_stmt";
		(yyval.forstmt)->content ="("+to_string(yylineno)+","+(yyval.forstmt)->nodename+")";
		cout<<(yyval.forstmt)->content<<endl;
	}
#line 2618 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 950 "myparser.y" /* yacc.c:1646  */
    {
				//$$->retval = null;
			}
#line 2626 "myparser.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 954 "myparser.y" /* yacc.c:1646  */
    {
				(yyval.returnstmt) = new Return_Stmt();
			//	$$->height = $2->height+1;
				(yyval.returnstmt)->nodename = "return_stmt";
				(yyval.returnstmt)->retval = (yyvsp[-1].expr);
				
				(yyval.returnstmt)->content ="("+to_string(yylineno)+","+(yyval.returnstmt)->nodename+")";
				cout<<(yyval.returnstmt)->content<<endl;
			}
#line 2640 "myparser.tab.c" /* yacc.c:1646  */
    break;


#line 2644 "myparser.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 964 "myparser.y" /* yacc.c:1906  */


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
