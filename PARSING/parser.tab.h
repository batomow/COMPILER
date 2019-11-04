/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1685 of yacc.c  */
#line 79 "parser.y"

	/* TODO: Define data types for vars and ids */



/* Line 1685 of yacc.c  */
#line 118 "parser.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


