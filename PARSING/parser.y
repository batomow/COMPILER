%{
	#include <stdio.h>

	extern int yylex();
	extern int yyparse();

	# define YYERROR_VERBOSE 1
 
	void yyerror(const char *s);	
%}

%token SYM_OBRAC 
%token SYM_CBRAC 
%token SYM_OPARE 
%token SYM_CPARE 
%token SYM_OCURL 
%token SYM_CCURL
%token SYM_COMMA
%token SYM_ARROW
%token SYM_COLON
%token SYM_DOT

%token MTH_SEQUA
%token MTH_DEQUA
%token MTH_GT
%token MTH_LT
%token MTH_GTEQ
%token MTH_LTEQ
%token MTH_NOT
%token MTH_NOTEQ
%token MTH_PLUS
%token MTH_MINUS
%token MTH_ASTRK
%token MTH_DIVIS
%token MTH_POWER
%token MTH_ROOT
%token MTH_AND
%token MTH_OR

%token LF 
%token CR

%token RES_MSCN
%token RES_SCNS
%token RES_DPLY
%token V_ID
%token F_ID
%token M_ID

%token LOG_IF
%token LOG_ELIF
%token LOG_ELSE
%token LOG_FOR
%token LOG_WHILE

%token V_VAR
%token V_CHAR
%token V_STRING
%token V_FLOAT
%token V_INT
%token V_DOUBLE
%token V_BOOL
%token V_HEX
%token V_ARR
%token V_MAT
%token V_VECTOR
%token V_ELEM

%token T_BOOL
%token T_INT
%token T_FLOAT
%token T_DOUBLE
%token T_CHAR
%token T_STRING
%token T_HEX

%token RES_ORDER
%token RES_MEDIT
%token RES_RETRN

%union{
	/* TODO: Define data types for vars and ids */
}


%start prog
%%

/* ------- ENTRY POINT ------- */

prog: 
	config 
	| script
;

/* ------- CONFIG GRAMMAR ------- */ 

config: 
	optlfCicle mainscene optlfCicle scenelist optlfCicle configHelper optlfCicle

configHelper:
	/* empty */ 
	| deploy crlf configHelper

mainscene: 
	RES_MSCN F_ID crlf 

scenelist: 
	RES_SCNS SYM_OBRAC scenelistHelper SYM_CBRAC crlf 

scenelistHelper: 
	F_ID SYM_COMMA scenelistHelper 
	| F_ID

optlfCicle:
	/* empty */
	| crlf optlfCicle

/* ------- SCRIPT GRAMMAR ------- */

script:  
	/* empty */
	| assign crlf script 
	| expr crlf script
	| deploy crlf script
	| function crlf script
	| vardec crlf script
	| arrdec crlf script
	| matdec crlf script
	| vectordec crlf script
	| elementdec crlf script
	| crlf script


/* ------- GENERAL GRAMMAR ------- */

crlf:
	CR LF
	| LF

optlf:
	/* empty */
	| crlf

deploy: 
	RES_DPLY M_ID

function: 
	RES_ORDER V_ID SYM_COLON vartypes SYM_OPARE functionHelper SYM_CPARE optlf SYM_OCURL crlf functionHelper2 SYM_CCURL

functionHelper: 
	/* empty */
	| functionHelper4 SYM_COMMA functionHelper
	| functionHelper4

functionHelper2:
	stmt crlf functionHelper3

functionHelper3: 
	/* empty */ 
	| functionHelper2 


functionHelper4:
	vardec
	| arrdec
	| matdec
	| vectordec
	| elementdec

stmt: 
	/* empty */
	| assign 
	| expr
	| logicstruct
	| vardec
	| arrdec
	| matdec
	| vectordec
	| elementdec
	| RES_MEDIT
	| ret

funcall: 
	V_ID SYM_OPARE funcallHelper SYM_CPARE

funcallHelper:
	/* empty */
	| expr funcallHelper2
	| vector funcallHelper2

funcallHelper2:
	/* empty */
	| SYM_COMMA funcallHelper

ret:
	RES_RETRN expr


/* ------- VARIABLES GRAMMAR ------- */

vardec: 
	V_VAR V_ID SYM_COLON vartypes

basictypes:
	V_CHAR
	| V_STRING
	| V_FLOAT
	| V_DOUBLE
	| V_INT
	| V_BOOL
	| V_HEX

vartypes:
	T_INT
	| T_FLOAT
	| T_DOUBLE
	| T_CHAR
	| T_STRING
	| T_BOOL
	| T_HEX


var_or_cte:
	V_ID
	| basictypes 

assign: 
	vardec MTH_SEQUA expr
	| arrdec MTH_SEQUA arr
	| matdec MTH_SEQUA mat
	| vectordec MTH_SEQUA vector
	| elementdec MTH_SEQUA funcall
	| V_ID MTH_SEQUA expr
	| structaccess MTH_SEQUA expr
	| property MTH_SEQUA expr



/* ------- DATA STRUCTURES GRAMMAR ------- */

structaccess:
	V_ID SYM_OBRAC expr SYM_CBRAC structIndex

structIndex:
	/* empty */
	| SYM_OBRAC expr SYM_CBRAC

/* Array*/

arrdec:
	V_ARR V_ID SYM_COLON vartypes SYM_OBRAC V_INT SYM_CBRAC

arr:
	SYM_OBRAC arrHelper SYM_CBRAC

arrHelper: 
	expr SYM_COMMA arrHelper
	| expr


/* Matrix */

matdec:
	V_MAT V_ID SYM_COLON vartypes SYM_OBRAC V_INT SYM_CBRAC SYM_OBRAC V_INT SYM_CBRAC

mat:
	SYM_OBRAC optlf matHelper SYM_CBRAC

matHelper:
	arr SYM_COMMA optlf matHelper
	| arr optlf


/* Geometric vector */

vectordec: 
	V_VECTOR V_ID

vector:
	SYM_OCURL expr SYM_COMMA expr SYM_CCURL


/* ------- ELEMENTS ------- */

elementdec:
	V_ELEM V_ID


/* Property access */
property:
	V_ID SYM_DOT V_ID


/* ------- EXPRESSIONS GRAMMAR ------- */

expr:
	logicoperation MTH_OR expr
	| logicoperation

logicoperation:
	logicfactor MTH_AND logicoperation
	| logicfactor

logicfactor:
	comparison
	| MTH_NOT comparison

comparison:
	operation comp_operator operation
	| operation

operation:
	factor MTH_PLUS operation
	| factor MTH_MINUS operation
	| factor

factor:
	hvalue MTH_ASTRK factor
	| hvalue MTH_DIVIS factor
	| hvalue

hvalue:
	value MTH_POWER hvalue
	| value MTH_ROOT hvalue
	| value

value:
	var_or_cte
	| funcall
	| structaccess
	| property
	| SYM_OPARE expr SYM_CPARE

comp_operator: 
	MTH_GT
	| MTH_GTEQ
	| MTH_LT
	| MTH_LTEQ
	| MTH_DEQUA
	| MTH_NOTEQ


/* ------- LOGICAL STRUCTURES GRAMMAR ------ */

logicstruct:
	if
	| for
	| while

if:
	LOG_IF ifHelper ifHelper3

ifHelper:
	SYM_OPARE expr SYM_CPARE optlf SYM_OCURL crlf newlineCicle SYM_CCURL optlf ifHelper2 

ifHelper2:
	/* empty */ 
	| LOG_ELIF ifHelper

ifHelper3:
	/* empty */ 
	| LOG_ELSE optlf SYM_OCURL crlf newlineCicle SYM_CCURL 

for:
	LOG_FOR forHelper SYM_ARROW V_ID optlf SYM_OCURL crlf newlineCicle SYM_CCURL

forHelper:
	V_ID
	| stepfor

stepfor:
	SYM_OBRAC expr SYM_COMMA expr SYM_COMMA expr SYM_CBRAC

while:
	LOG_WHILE SYM_OPARE expr SYM_CPARE optlf SYM_OCURL crlf newlineCicle SYM_CCURL

newlineCicle:
	newline newlineCicle
	| newline

newline:
	stmt crlf

;

%%

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