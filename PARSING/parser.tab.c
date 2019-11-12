/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2006, 2009-2010 Free Software
   Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "parser.y"

	#include <stdio.h>

	extern int yylex();
	extern int yyparse();

	# define YYERROR_VERBOSE 1
 
	void yyerror(const char *s);	


/* Line 189 of yacc.c  */
#line 84 "parser.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     SYM_OBRAC = 258,
     SYM_CBRAC = 259,
     SYM_OPARE = 260,
     SYM_CPARE = 261,
     SYM_OCURL = 262,
     SYM_CCURL = 263,
     SYM_COMMA = 264,
     SYM_ARROW = 265,
     SYM_COLON = 266,
     SYM_DOT = 267,
     MTH_SEQUA = 268,
     MTH_DEQUA = 269,
     MTH_GT = 270,
     MTH_LT = 271,
     MTH_GTEQ = 272,
     MTH_LTEQ = 273,
     MTH_NOT = 274,
     MTH_NOTEQ = 275,
     MTH_PLUS = 276,
     MTH_MINUS = 277,
     MTH_ASTRK = 278,
     MTH_DIVIS = 279,
     MTH_POWER = 280,
     MTH_ROOT = 281,
     MTH_AND = 282,
     MTH_OR = 283,
     LF = 284,
     CR = 285,
     TWS = 286,
     RES_MSCN = 287,
     RES_SCNS = 288,
     RES_DPLY = 289,
     V_ID = 290,
     F_ID = 291,
     M_ID = 292,
     LOG_IF = 293,
     LOG_ELIF = 294,
     LOG_ELSE = 295,
     LOG_FOR = 296,
     LOG_WHILE = 297,
     V_VAR = 298,
     V_CHAR = 299,
     V_STRING = 300,
     V_FLOAT = 301,
     V_INT = 302,
     V_DOUBLE = 303,
     V_BOOL = 304,
     V_HEX = 305,
     V_ARR = 306,
     V_MAT = 307,
     V_MAT4 = 308,
     V_MAP = 309,
     V_VECTOR = 310,
     V_ELEM = 311,
     RES_ORDER = 312,
     RES_XRDER = 313,
     RES_MEDIT = 314,
     RES_RETRN = 315,
     OTHER = 316
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 79 "parser.y"

	/* TODO: Define data types for vars and ids */



/* Line 214 of yacc.c  */
#line 187 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 199 "parser.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  79
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   604

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  63
/* YYNRULES -- Number of rules.  */
#define YYNRULES  136
/* YYNRULES -- Number of states.  */
#define YYNSTATES  274

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   316

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    15,    16,    20,    24,    30,
      34,    36,    37,    40,    41,    45,    49,    53,    57,    61,
      64,    67,    69,    70,    72,    75,    86,    87,    91,    93,
      97,    98,   100,   101,   103,   105,   107,   109,   111,   113,
     118,   119,   122,   123,   126,   129,   132,   134,   136,   138,
     140,   142,   144,   146,   148,   150,   152,   154,   156,   158,
     160,   162,   164,   166,   168,   170,   174,   178,   182,   186,
     187,   189,   195,   196,   200,   206,   210,   214,   216,   225,
     230,   235,   238,   241,   246,   252,   258,   259,   261,   264,
     270,   273,   277,   281,   283,   287,   289,   291,   294,   298,
     300,   304,   308,   310,   314,   318,   320,   324,   328,   330,
     332,   334,   336,   338,   342,   344,   346,   348,   350,   352,
     354,   356,   358,   360,   364,   375,   376,   379,   380,   387,
     397,   399,   401,   409,   419,   422,   424
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      63,     0,    -1,    64,    -1,    70,    -1,    69,    66,    69,
      67,    69,    65,    69,    -1,    -1,    73,    71,    65,    -1,
      32,    36,    71,    -1,    33,     3,    68,     4,    71,    -1,
      36,     9,    68,    -1,    36,    -1,    -1,    71,    69,    -1,
      -1,    87,    71,    70,    -1,   105,    71,    70,    -1,    73,
      71,    70,    -1,    74,    71,    70,    -1,    83,    71,    70,
      -1,    71,    70,    -1,    30,    29,    -1,    29,    -1,    -1,
      71,    -1,    34,    37,    -1,    57,    35,     5,    75,     6,
      72,     7,    71,    76,     8,    -1,    -1,    83,     9,    75,
      -1,    83,    -1,    78,    71,    77,    -1,    -1,    76,    -1,
      -1,    87,    -1,   105,    -1,   114,    -1,    83,    -1,    59,
      -1,    82,    -1,    35,     5,    80,     6,    -1,    -1,   105,
      81,    -1,    -1,     9,    80,    -1,    60,   105,    -1,    43,
      35,    -1,    91,    -1,    94,    -1,    97,    -1,   101,    -1,
     103,    -1,    44,    -1,    45,    -1,    46,    -1,    48,    -1,
      47,    -1,    49,    -1,    50,    -1,    84,    -1,    92,    -1,
      95,    -1,    98,    -1,   102,    -1,    35,    -1,    85,    -1,
      83,    13,   105,    -1,    35,    13,   105,    -1,    89,    13,
     105,    -1,   104,    13,   105,    -1,    -1,    47,    -1,    35,
       3,   105,     4,    90,    -1,    -1,     3,   105,     4,    -1,
      51,    35,     3,    88,     4,    -1,     3,    93,     4,    -1,
     105,     9,    93,    -1,   105,    -1,    52,    35,     3,    88,
       4,     3,    88,     4,    -1,     3,    72,    96,     4,    -1,
      92,     9,    72,    96,    -1,    92,    72,    -1,    54,    35,
      -1,     7,    72,    99,     8,    -1,    84,    11,   105,    71,
     100,    -1,    35,    11,   105,    71,   100,    -1,    -1,    99,
      -1,    55,    35,    -1,     7,   105,     9,   105,     8,    -1,
      56,    35,    -1,    35,    12,    35,    -1,   106,    28,   105,
      -1,   106,    -1,   107,    27,   106,    -1,   107,    -1,   108,
      -1,    19,   108,    -1,   109,   113,   109,    -1,   109,    -1,
     110,    21,   109,    -1,   110,    22,   109,    -1,   110,    -1,
     111,    23,   110,    -1,   111,    24,   110,    -1,   111,    -1,
     112,    25,   111,    -1,   112,    26,   111,    -1,   112,    -1,
      86,    -1,    79,    -1,    89,    -1,   104,    -1,     5,   105,
       6,    -1,    15,    -1,    17,    -1,    16,    -1,    18,    -1,
      14,    -1,    20,    -1,   115,    -1,   119,    -1,   122,    -1,
      38,   116,   118,    -1,     5,   105,     6,    72,     7,    71,
     123,     8,    72,   117,    -1,    -1,    39,   116,    -1,    -1,
      40,    72,     7,    71,   123,     8,    -1,    41,   120,    10,
      35,    72,     7,    71,   123,     8,    -1,    35,    -1,   121,
      -1,     3,   105,     9,   105,     9,   105,     4,    -1,    42,
       5,   105,     6,    72,     7,    71,   123,     8,    -1,   124,
     123,    -1,   124,    -1,    78,    71,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    90,    90,    91,    97,    99,   101,   104,   107,   110,
     111,   113,   115,   119,   121,   122,   123,   124,   125,   126,
     132,   133,   135,   137,   140,   143,   145,   147,   148,   151,
     153,   155,   157,   159,   160,   161,   162,   163,   164,   167,
     169,   171,   173,   175,   178,   184,   185,   186,   187,   188,
     189,   192,   193,   194,   195,   196,   197,   198,   201,   202,
     203,   204,   205,   208,   209,   212,   213,   214,   215,   221,
     223,   226,   228,   230,   235,   238,   241,   242,   248,   251,
     254,   255,   261,   264,   267,   268,   270,   272,   278,   281,
     287,   292,   298,   299,   302,   303,   306,   307,   310,   311,
     314,   315,   316,   319,   320,   321,   324,   325,   326,   329,
     330,   331,   332,   333,   336,   337,   338,   339,   340,   341,
     347,   348,   349,   352,   355,   357,   359,   361,   363,   366,
     369,   370,   373,   376,   379,   380,   383
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SYM_OBRAC", "SYM_CBRAC", "SYM_OPARE",
  "SYM_CPARE", "SYM_OCURL", "SYM_CCURL", "SYM_COMMA", "SYM_ARROW",
  "SYM_COLON", "SYM_DOT", "MTH_SEQUA", "MTH_DEQUA", "MTH_GT", "MTH_LT",
  "MTH_GTEQ", "MTH_LTEQ", "MTH_NOT", "MTH_NOTEQ", "MTH_PLUS", "MTH_MINUS",
  "MTH_ASTRK", "MTH_DIVIS", "MTH_POWER", "MTH_ROOT", "MTH_AND", "MTH_OR",
  "LF", "CR", "TWS", "RES_MSCN", "RES_SCNS", "RES_DPLY", "V_ID", "F_ID",
  "M_ID", "LOG_IF", "LOG_ELIF", "LOG_ELSE", "LOG_FOR", "LOG_WHILE",
  "V_VAR", "V_CHAR", "V_STRING", "V_FLOAT", "V_INT", "V_DOUBLE", "V_BOOL",
  "V_HEX", "V_ARR", "V_MAT", "V_MAT4", "V_MAP", "V_VECTOR", "V_ELEM",
  "RES_ORDER", "RES_XRDER", "RES_MEDIT", "RES_RETRN", "OTHER", "$accept",
  "prog", "config", "configHelper", "mainscene", "scenelist",
  "scenelistHelper", "optlfCicle", "script", "crlf", "optlf", "deploy",
  "function", "functionHelper", "functionHelper2", "functionHelper3",
  "stmt", "funcall", "funcallHelper", "funcallHelper2", "ret", "vardec",
  "basictypes", "cte", "var_or_cte", "assign", "int_or_blank",
  "structaccess", "structIndex", "arrdec", "arr", "arrHelper", "matdec",
  "mat", "matHelper", "mapdec", "map", "mapHelper", "mapHelper2",
  "vectordec", "vector", "elementdec", "property", "expr",
  "logicoperation", "logicfactor", "comparison", "operation", "factor",
  "hvalue", "value", "comp_operator", "logicstruct", "if", "ifHelper",
  "ifHelper2", "ifHelper3", "for", "forHelper", "stepfor", "while",
  "newlineCicle", "newline", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    63,    63,    64,    65,    65,    66,    67,    68,
      68,    69,    69,    70,    70,    70,    70,    70,    70,    70,
      71,    71,    72,    72,    73,    74,    75,    75,    75,    76,
      77,    77,    78,    78,    78,    78,    78,    78,    78,    79,
      80,    80,    81,    81,    82,    83,    83,    83,    83,    83,
      83,    84,    84,    84,    84,    84,    84,    84,    85,    85,
      85,    85,    85,    86,    86,    87,    87,    87,    87,    88,
      88,    89,    90,    90,    91,    92,    93,    93,    94,    95,
      96,    96,    97,    98,    99,    99,   100,   100,   101,   102,
     103,   104,   105,   105,   106,   106,   107,   107,   108,   108,
     109,   109,   109,   110,   110,   110,   111,   111,   111,   112,
     112,   112,   112,   112,   113,   113,   113,   113,   113,   113,
     114,   114,   114,   115,   116,   117,   117,   118,   118,   119,
     120,   120,   121,   122,   123,   123,   124
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     7,     0,     3,     3,     5,     3,
       1,     0,     2,     0,     3,     3,     3,     3,     3,     2,
       2,     1,     0,     1,     2,    10,     0,     3,     1,     3,
       0,     1,     0,     1,     1,     1,     1,     1,     1,     4,
       0,     2,     0,     2,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     0,
       1,     5,     0,     3,     5,     3,     3,     1,     8,     4,
       4,     2,     2,     4,     5,     5,     0,     1,     2,     5,
       2,     3,     3,     1,     3,     1,     1,     2,     3,     1,
       3,     3,     1,     3,     3,     1,     3,     3,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,    10,     0,     2,     0,     6,     9,
       1,     1,     7,     9,     2,     1,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      11,     0,     0,     0,     0,    21,     0,     0,    63,     0,
      51,    52,    53,    55,    54,    56,    57,     0,     0,     0,
       0,     0,     0,     0,     2,     0,     3,    11,     0,     0,
     110,     0,    58,    64,   109,     0,   111,    46,    59,    47,
      60,    48,    61,    49,    62,    50,   112,     0,    93,    95,
      96,    99,   102,   105,   108,    63,    23,     0,   111,     0,
     112,    77,     0,     0,     0,    97,    20,    24,     0,    40,
       0,     0,    45,     0,     0,    82,    88,    90,     0,     1,
       0,    11,    12,    19,    13,    13,     0,    13,    13,     0,
       0,    13,     0,     0,   118,   114,   116,   115,   117,   119,
       0,     0,     0,     0,     0,     0,     0,     0,    22,     0,
      75,     0,   113,     0,     0,     0,     0,     0,     0,    42,
      91,    66,    69,    69,    26,     0,     0,    11,    16,    13,
      17,    65,    18,    14,    67,    68,    15,    92,    94,    98,
     100,   101,   103,   104,   106,   107,    22,    81,    79,    76,
       0,     0,    83,     0,    72,    39,    40,    41,    70,     0,
       0,     0,    28,     7,     0,    11,     0,     0,     0,    89,
       0,    71,    43,    74,     0,    22,    26,     0,     5,    80,
      86,    86,     0,    69,     0,    27,    10,     0,    11,     0,
      87,    85,    84,    73,     0,     0,     0,     0,     4,     5,
      78,    32,     9,     8,     6,     0,     0,     0,    37,     0,
       0,     0,    38,    36,    33,    34,    35,   120,   121,   122,
       0,   127,     0,   130,     0,   131,     0,    44,    25,    32,
       0,    22,   123,     0,     0,     0,    31,    29,    22,     0,
       0,    22,    22,     0,     0,     0,     0,     0,     0,    32,
       0,     0,     0,    32,     0,     0,    32,     0,    32,    32,
       0,   136,   128,   134,   132,     0,     0,    22,   129,   133,
     125,     0,   124,   126
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    23,    24,   188,    81,   165,   187,    82,    83,    56,
      57,    28,    29,   161,   210,   237,   254,    30,   118,   157,
     212,    31,    32,    33,    34,    35,   159,    58,   171,    37,
      38,    59,    39,    40,   109,    41,    42,   190,   191,    43,
      44,    45,    60,    47,    48,    49,    50,    51,    52,    53,
      54,   100,   216,   217,   221,   272,   232,   218,   224,   225,
     219,   255,   256
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -196
static const yytype_int16 yypact[] =
{
     455,   279,    22,   279,   175,  -196,   -19,    14,     8,     3,
    -196,  -196,  -196,  -196,  -196,  -196,  -196,    18,    27,    43,
      45,    46,    49,    87,  -196,    66,  -196,   455,   -15,   -15,
    -196,    13,  -196,  -196,  -196,   -15,    88,  -196,  -196,  -196,
    -196,  -196,  -196,  -196,  -196,  -196,    89,   -15,    78,    82,
    -196,    59,    11,    21,    30,    19,  -196,   109,  -196,   113,
    -196,   110,   117,   100,   122,  -196,  -196,  -196,    22,    22,
      91,    22,  -196,   129,   131,  -196,  -196,  -196,   133,  -196,
     104,   -15,  -196,  -196,   547,   547,    22,   547,   547,    22,
      22,   547,    22,    22,  -196,  -196,  -196,  -196,  -196,  -196,
     175,   175,   175,   175,   175,   175,   175,    22,     7,   138,
    -196,    22,  -196,   145,   149,   153,    22,   158,   159,   155,
    -196,  -196,   119,   119,    39,   -15,   135,   -15,  -196,   547,
    -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,
    -196,  -196,  -196,  -196,  -196,  -196,   -15,  -196,  -196,  -196,
      22,    22,  -196,   161,   167,  -196,    22,  -196,  -196,   169,
     170,   173,   166,  -196,   180,   -15,   109,   -15,   -15,  -196,
      22,  -196,  -196,  -196,   182,   -15,    39,   140,   154,  -196,
     100,   100,   185,   119,   184,  -196,   183,   189,   -15,   -15,
    -196,  -196,  -196,  -196,   190,   -15,   140,   -15,  -196,   154,
    -196,   489,  -196,  -196,  -196,   191,     5,   194,  -196,    22,
     187,   -15,  -196,   188,  -196,  -196,  -196,  -196,  -196,  -196,
      22,   160,    22,  -196,   196,  -196,    22,  -196,  -196,   339,
     198,   -15,  -196,   205,   172,   210,  -196,  -196,   -15,   211,
      22,   -15,   -15,   219,   -15,   218,   222,   224,   -15,   489,
      22,   -15,   -15,   489,   -15,   225,   397,   228,   489,   489,
     226,  -196,  -196,  -196,  -196,   229,   232,   -15,  -196,  -196,
     197,   191,  -196,  -196
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -196,  -196,  -196,    44,  -196,  -196,    48,     2,    23,   124,
      -3,  -169,  -196,    69,    17,  -196,  -194,  -196,    86,  -196,
    -196,   -72,   -60,  -196,  -196,  -195,  -118,     1,  -196,  -196,
     -53,   136,  -196,  -196,    92,  -196,  -196,   192,    71,  -196,
    -196,  -196,    12,    47,   179,  -196,   258,   -83,   -57,   -46,
    -196,  -196,  -196,  -196,    -8,  -196,  -196,  -196,  -196,  -196,
    -196,  -131,  -196
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -136
static const yytype_int16 yytable[] =
{
      63,    36,    25,   114,   108,   160,   214,   211,   222,   189,
      66,    68,    46,    69,     5,     6,   146,   139,   140,   141,
      70,    71,    68,    26,    69,     1,    86,     2,    36,     3,
     189,    70,   101,   102,   214,   211,     5,     6,    72,    46,
     223,     4,     5,     6,   103,   104,   142,   143,    61,    62,
      64,    67,   162,    73,   214,   105,   106,    55,   214,   144,
     145,   214,    74,   214,   214,   194,    10,    11,    12,    13,
      14,    15,    16,    94,    95,    96,    97,    98,    75,    99,
      76,    77,     9,   126,    78,    36,    36,    79,    36,    36,
      17,    18,    36,    19,    20,    21,    46,    46,    80,    46,
      46,    89,    90,    46,   162,   147,    92,   128,   130,    93,
     132,   133,   107,   108,   136,   117,   119,   110,   121,   111,
     114,   114,   260,   112,    27,   263,   120,   265,   266,   213,
      36,   116,   122,   131,   123,   113,   134,   135,   124,   137,
     125,    46,   148,   166,    10,    11,    12,    13,    14,    15,
      16,    27,    84,    85,    61,    87,   150,   213,    61,    88,
     151,   152,   154,   153,   156,   155,   158,   178,   164,   169,
     170,    91,   184,   173,   174,   176,   186,   213,     1,   175,
       2,   213,     3,   177,   213,   183,   213,   213,     7,   193,
     198,   195,   196,   197,   200,   228,   220,   167,   168,   226,
     231,    86,    36,   119,   238,   127,   234,   241,   129,   129,
      55,   129,   129,    46,   240,   129,   242,   182,   244,    10,
      11,    12,    13,    14,    15,    16,   248,   250,   239,   251,
      36,   252,   264,   262,   267,   243,   271,   268,   246,   247,
     269,    46,   172,   204,   202,   185,   236,   149,   215,   163,
      36,   127,   192,   129,    36,   115,   227,    36,   179,    36,
      36,    46,    65,   273,   270,    46,     0,   230,    46,   233,
      46,    46,   138,   235,     0,     0,   215,     0,     0,     0,
       0,     0,     1,     0,     2,     0,     3,   245,     0,   127,
       0,   180,   181,     0,     0,     0,   215,   257,     4,     0,
     215,     0,     0,   215,     0,   215,   215,     0,     5,     6,
       0,     0,   127,   199,    55,     0,     0,     0,     0,   201,
       0,   203,     0,    10,    11,    12,    13,    14,    15,    16,
       0,     0,     0,     0,     0,   229,     0,     0,     0,     0,
       0,     0,     1,     0,     2,     0,     3,   -30,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     4,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   249,     0,
       0,     0,   253,     0,     8,   258,   259,   205,   261,     0,
     206,   207,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,     0,    19,    20,    21,     0,     0,   208,   209,
       1,     0,     2,     0,     3,  -135,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     4,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     8,     0,     0,   205,     0,     0,   206,   207,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
       0,    19,    20,    21,     0,   -13,   208,   209,     1,     0,
       2,     0,     3,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     4,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     5,     6,     0,     0,     0,     7,
       8,     0,     1,     0,     2,     0,     3,     0,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,     4,    19,
      20,    21,    22,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     8,     0,     0,   205,     0,     0,
     206,   207,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,     0,    19,    20,    21,     0,     0,   208,   209,
       1,     0,     2,     0,     3,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     4,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     5,     6,     0,     0,
       0,     7,     8,     0,     0,     0,     0,     0,     0,     0,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
       0,    19,    20,    21,    22
};

static const yytype_int16 yycheck[] =
{
       3,     0,     0,    63,    57,   123,   201,   201,     3,   178,
      29,     3,     0,     5,    29,    30,     9,   100,   101,   102,
      12,    13,     3,     0,     5,     3,    13,     5,    27,     7,
     199,    12,    21,    22,   229,   229,    29,    30,    35,    27,
      35,    19,    29,    30,    23,    24,   103,   104,     1,     2,
       3,    37,   124,    35,   249,    25,    26,    35,   253,   105,
     106,   256,    35,   258,   259,   183,    44,    45,    46,    47,
      48,    49,    50,    14,    15,    16,    17,    18,    35,    20,
      35,    35,    43,    81,    35,    84,    85,     0,    87,    88,
      51,    52,    91,    54,    55,    56,    84,    85,    32,    87,
      88,    13,    13,    91,   176,   108,    28,    84,    85,    27,
      87,    88,     3,   166,    91,    68,    69,     4,    71,     9,
     180,   181,   253,     6,     0,   256,    35,   258,   259,   201,
     129,     9,     3,    86,     3,    35,    89,    90,     5,    92,
      36,   129,     4,   146,    44,    45,    46,    47,    48,    49,
      50,    27,    28,    29,   107,    31,    11,   229,   111,    35,
      11,     8,     4,   116,     9,     6,    47,   165,    33,     8,
       3,    47,   175,     4,     4,     9,    36,   249,     3,     6,
       5,   253,     7,     3,   256,     3,   258,   259,    34,     4,
     188,     7,     9,     4,     4,     8,     5,   150,   151,     5,
      40,    13,   201,   156,     6,    81,    10,    35,    84,    85,
      35,    87,    88,   201,     9,    91,     6,   170,     7,    44,
      45,    46,    47,    48,    49,    50,     7,     9,   231,     7,
     229,     7,     4,     8,     8,   238,    39,     8,   241,   242,
       8,   229,   156,   199,   196,   176,   229,   111,   201,   125,
     249,   127,   181,   129,   253,    63,   209,   256,   166,   258,
     259,   249,     4,   271,   267,   253,    -1,   220,   256,   222,
     258,   259,    93,   226,    -1,    -1,   229,    -1,    -1,    -1,
      -1,    -1,     3,    -1,     5,    -1,     7,   240,    -1,   165,
      -1,   167,   168,    -1,    -1,    -1,   249,   250,    19,    -1,
     253,    -1,    -1,   256,    -1,   258,   259,    -1,    29,    30,
      -1,    -1,   188,   189,    35,    -1,    -1,    -1,    -1,   195,
      -1,   197,    -1,    44,    45,    46,    47,    48,    49,    50,
      -1,    -1,    -1,    -1,    -1,   211,    -1,    -1,    -1,    -1,
      -1,    -1,     3,    -1,     5,    -1,     7,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   244,    -1,
      -1,    -1,   248,    -1,    35,   251,   252,    38,   254,    -1,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    -1,    54,    55,    56,    -1,    -1,    59,    60,
       3,    -1,     5,    -1,     7,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    19,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    -1,    -1,    38,    -1,    -1,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      -1,    54,    55,    56,    -1,     0,    59,    60,     3,    -1,
       5,    -1,     7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    19,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    30,    -1,    -1,    -1,    34,
      35,    -1,     3,    -1,     5,    -1,     7,    -1,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    19,    54,
      55,    56,    57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    -1,    -1,    38,    -1,    -1,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    -1,    54,    55,    56,    -1,    -1,    59,    60,
       3,    -1,     5,    -1,     7,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    19,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    -1,    -1,
      -1,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      -1,    54,    55,    56,    57
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     5,     7,    19,    29,    30,    34,    35,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    54,
      55,    56,    57,    63,    64,    69,    70,    71,    73,    74,
      79,    83,    84,    85,    86,    87,    89,    91,    92,    94,
      95,    97,    98,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,    35,    71,    72,    89,    93,
     104,   105,   105,    72,   105,   108,    29,    37,     3,     5,
      12,    13,    35,    35,    35,    35,    35,    35,    35,     0,
      32,    66,    69,    70,    71,    71,    13,    71,    71,    13,
      13,    71,    28,    27,    14,    15,    16,    17,    18,    20,
     113,    21,    22,    23,    24,    25,    26,     3,    92,    96,
       4,     9,     6,    35,    84,    99,     9,   105,    80,   105,
      35,   105,     3,     3,     5,    36,    69,    71,    70,    71,
      70,   105,    70,    70,   105,   105,    70,   105,   106,   109,
     109,   109,   110,   110,   111,   111,     9,    72,     4,    93,
      11,    11,     8,   105,     4,     6,     9,    81,    47,    88,
      88,    75,    83,    71,    33,    67,    72,   105,   105,     8,
       3,    90,    80,     4,     4,     6,     9,     3,    69,    96,
      71,    71,   105,     3,    72,    75,    36,    68,    65,    73,
      99,   100,   100,     4,    88,     7,     9,     4,    69,    71,
       4,    71,    68,    71,    65,    38,    41,    42,    59,    60,
      76,    78,    82,    83,    87,   105,   114,   115,   119,   122,
       5,   116,     3,    35,   120,   121,     5,   105,     8,    71,
     105,    40,   118,   105,    10,   105,    76,    77,     6,    72,
       9,    35,     6,    72,     7,   105,    72,    72,     7,    71,
       9,     7,     7,    71,    78,   123,   124,   105,    71,    71,
     123,    71,     8,   123,     4,   123,   123,     8,     8,     8,
      72,    39,   117,   116
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
      

/* Line 1464 of yacc.c  */
#line 1724 "parser.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1684 of yacc.c  */
#line 387 "parser.y"


void yyerror(const char *s){
	printf("\nERROR: %s\n", s);
}

int main(int argc, char *argv[]) {
	extern FILE *yyin;
	++argv;
	--argc;
	int r;

	yyin = fopen("../test.fs", "r");

	r = yyparse();

	if(r == 0){
		printf("COMPILATION SUCCESSFUL!\n");
	} 

	return 0;
}
