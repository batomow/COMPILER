%{
	#include <stdio.h> 
	#include <stdlib.h>
	#include <string.h> 
	#include <jedi.h>
	#include "cube.h"
	#include <limits.h>

	extern int yylex();
	extern int yyparse();
     

	# define YYERROR_VERBOSE 1
 
	int yyerror(const char *s);

	//General neural points
	void npFinalCheck();

	//Declarations
	void np1(); void np1_1(); 
	void np2();	
	void np3();
	void np4();
	void np5();

	//Expressions 
	void npExpr1_1();
	void npExpr1_2_char(char);
    void npExpr1_2_string(); 
    void npExpr1_2_double(); 
    void npExpr1_2_int(); 
    void npExpr1_2_bool(); 
	void npExpr1_3();
	void npExpr1_4();
	void npExpr1_5();
	void npExpr1_6();
	void npExpr2();
	void npExpr3();
	void npExpr3_1();
	void npExpr4();
	void npExpr5();
	void npExpr5_1();
	void npExpr6();
	void npExpr7();
	void npExpr8();
	void npExpr9();
	void npExpr10();
	void npExpr11();
	void npExpr12();
	void npExpr13();
	void npExpr14();
	void npExpr15();

	//Assignments
	void npAssign1();
	void npAssign2();
	void npAssign3();
	void npAssign4();
	void npArrGen1();
	void npArrGen2();

	//If statement
	void npIf0();
	void npIf1();
	void npIf2();
	void npIf3();

	// While statement
	void npWhile1();
	void npWhile2();
	void npWhile3();

	// For statement
	void npFor1();
	void npFor2();
	void npFor3();
	void npFor4();
    
    // Functions
    void npFun1();
    void npFun2(); 

    void npError(); 
    void npFunCall1();
    void npFunCall2(); 

    void npReturn(); 
    void npClean(); //borra todo de la pila 

    // Global Counters //virtual mem-dirs
    int globalsCounter; 
    int localsCounter; 
    int constCounter; 
    int quadrupleCounter; 
    int paramCounter;  

    //Global Variables
    char currentFunction[96];   
    TableType currentType;  //tipo de variable
    int isParam; // true si la variable que se esta parseando es parametro
    int isVector; 
    int isMat; 
    int isElement; 
	    
    int errorCounter = 0; 

    // Global Structures
    VarTable globals; //variables globales
    VarTable constants; //constantes globales
    FuncTable functions; 
    
    Stack pilaNombres; //los ids's 
    Stack pilaOperandos; //las dir de memroai
    Stack pilaOperadores; //el proceso 
    Stack pilaTipos;  //los tipos 
    Stack pilaSaltos; 
    Stack pilaFor; 
    Stack pilaEras; 
    Stack pilaGoSubs;

	Queue filaArrOperandos;
	Queue filaArrNombres;
	Queue filaArrTipos;
    
    QUAD listQuads;   
    QUAD* currentQuad; 
  
    CuboSemantico cubo;  
    // Helper functions 
    TableType DT2TT(DataType current){
        switch(current){
            case TypeInt: return TableInt; break; 
            case TypeDouble: return TableDouble; break; 
            case TypeChar: return TableChar; break; 
            case TypeString: return TableString; break; 
            case TypeNull: return TableNull; break; 
            case TypeBool: return TableBool; break; 
            default : return TableNull; break; 
        }
    }
    
    OPDUM VTE2OPDUM(VTE old){
        return NewOPDUM(old.id, old.dir, old.type); 
    }
    char* OPE2STRING(OP ope){
        switch(ope){
            case SUM: return "SUM"; case RES: return "RES"; case DIV: return "DIV"; case MULT: return "MULT"; case POW: return "POW"; 
            case ROOT: return "ROOT"; case EEQ: return "EEQ"; case NEQ: return "NEQ"; case LT: return "LT"; case GT: return "GT"; 
            case GTE: return "GTE"; case LTE: return "LTE"; case NEG: return "NEG"; case FORCHECK: return "FORCHECK"; 
            case ERA: return "ERA"; case PARAM: return "PARAM"; case RETURN: return "RETURN"; default: return "(undefined)";  
        }
    }
    char* TABLETYPE2STRING(TableType t){
        switch(t){
        case TableInt: return "TableInt"; case TableDouble: return "TableDouble"; 
        case TableBool: return "TableBool"; case TableChar: return "TableChar"; case TableString: return "TableString";
        case TableNull: return "TableNull"; default: return "(undefined)"; 
        }
    }

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

%token <op> MTH_SEQUA
%token <op> MTH_DEQUA
%token <op> MTH_GT
%token <op> MTH_LT
%token <op> MTH_GTEQ
%token <op> MTH_LTEQ
%token <op> MTH_NOT
%token <op> MTH_NOTEQ
%token <op> MTH_PLUS
%token <op> MTH_MINUS
%token <op> MTH_ASTRK
%token <op> MTH_DIVIS
%token <op> MTH_POWER
%token <op> MTH_ROOT
%token <op> MTH_AND
%token <op> MTH_OR

%token LF 
%token CR

%token <yystring> V_ID
%token <yystring> F_ID
%token <yystring> M_ID

%token LOG_IF
%token LOG_ELIF
%token LOG_ELSE
%token LOG_FOR
%token LOG_WHILE

%token V_VAR

%token <yychar> V_CHAR

%token <yystring> V_STRING


%token <yyint> V_INT

%token <yydouble> V_DOUBLE

%token <yybool> V_BOOL

%token <yyint> V_ARR

%token <yyint> V_MAT

%token <yyint>V_VECTOR

%token <yyint> V_ELEM


%token <tabletype> T_BOOL
%token <tabletype> T_INT
%token <tabletype> T_FLOAT
%token <tabletype> T_DOUBLE
%token <tabletype> T_CHAR
%token <tabletype> T_STRING

%token RES_ORDER
%token RES_MEDIT
%token RES_RETRN

%type <op> comp_operator //no terminal 
%type <yystring> vardec //no terminal
%type <yystring> arrdec //no terminal
%type <yystring> matdec //no terminal

%code requires{
    #include <jedi.h>
}

%union{
    TableType tabletype; 
    int yyint; 
    double yydouble; 
    char yychar; 
    char* yystring; 
    int yybool; 
    OP op; 
}

%start prog
%%

/* ------- ENTRY POINT ------- */

prog: 
    script { npFinalCheck(); } 
    | error { npError(); }


/* ------- SCRIPT GRAMMAR ------- */

script:  
	/* empty */
	| function crlf { npClean();} script
	| vardec crlf { npClean();} script
	| crlf script


/* ------- GENERAL GRAMMAR ------- */

crlf:
	  CR LF
	| LF {/*printf("\n");*/}

optlf:
	/* empty */
	| crlf {/*printf("\n");*/} 

function: 
	RES_ORDER V_ID SYM_COLON vartypes SYM_OPARE {npFun1($2); isParam = 1;}funparams SYM_CPARE{isParam = 0;} optlf SYM_OCURL crlf funbody SYM_CCURL{npFun2(); }

funparams: 
     /*empty*/
	| generaldec morefunparams

morefunparams:
     /*empty*/
	|  SYM_COMMA generaldec morefunparams

funbody:
     /*emtpy*/
	| stmt crlf { npClean();} funbody
    | generaldec crlf { npClean();} funbody
    | crlf funbody

generaldec: /* declaras o declaras y assignas */
	  vardec
	| arrdec
	| matdec
	| vectordec
	| elementdec 
	| vardec {npExpr1_1($1);} MTH_SEQUA expr { npAssign1(); }
	| arrdec {npExpr1_1($1);} MTH_SEQUA arr { npAssign2(); }
	| matdec {npExpr1_1($1);} MTH_SEQUA mat { npAssign2(); }
	| vectordec MTH_SEQUA vector {npAssign3();}
	| elementdec MTH_SEQUA funcall {npAssign4();}

stmt: 
	  assign 
	| expr
	| logicstruct
	| RES_MEDIT
	| ret

funcall: 
	V_ID { npFunCall1($1); npExpr6(); } SYM_OPARE funcallHelper SYM_CPARE { npFunCall2(); paramCounter = 0; npExpr7(); }

funcallHelper:
	/* empty */
	| expr {paramCounter++;}funcallHelper2 
	| vector funcallHelper2

funcallHelper2:
	/* empty */
	| SYM_COMMA funcallHelper

ret:
	RES_RETRN expr {npReturn();}


/* ------- VARIABLES GRAMMAR ------- */

vardec: 
	V_VAR V_ID SYM_COLON vartypes { $$ = $2; np1($2); }

basictypes:
	  V_CHAR   { npExpr1_2_char($1); }
	| V_STRING { npExpr1_2_string($1); }
	| V_DOUBLE { npExpr1_2_double($1); }
	| V_INT    { npExpr1_2_int($1); }
	| V_BOOL   { npExpr1_2_bool($1); }

vartypes:
	  T_INT    { np1_1($1);}
	| T_DOUBLE { np1_1($1);} 
	| T_CHAR   { np1_1($1);} 
	| T_STRING { np1_1($1);} 
	| T_BOOL   { np1_1($1);}  


var_or_cte:
	  V_ID { npExpr1_1($1); }
	| basictypes

assign: 
	  V_ID { npExpr1_1($1); } MTH_SEQUA expr {npAssign1();}
	| structaccess MTH_SEQUA expr {npAssign1();}
	| property MTH_SEQUA expr {npAssign1();}

/* ------- DATA STRUCTURES GRAMMAR ------- */

structaccess:
	V_ID SYM_OBRAC expr SYM_CBRAC { npExpr1_4(); } structIndex

structIndex:
	/* empty */
	| SYM_OBRAC expr SYM_CBRAC { npExpr1_5(); }

/* Array*/

arrdec:
	V_ARR V_ID SYM_COLON vartypes SYM_OBRAC V_INT SYM_CBRAC { $$ = $2; np2($2, $6);}

arr:
	SYM_OBRAC arrHelper SYM_CBRAC { npArrGen1(); }

arrHelper: 
	expr SYM_COMMA { npArrGen2(); } arrHelper
	| expr { npArrGen2(); }


/* Matrix */

matdec:
	V_MAT V_ID SYM_COLON vartypes SYM_OBRAC V_INT SYM_CBRAC SYM_OBRAC V_INT SYM_CBRAC { $$ = $2; np3($2, $6, $9); }

mat:
	SYM_OBRAC optlf matHelper SYM_CBRAC

matHelper:
	arr SYM_COMMA optlf matHelper
	| arr optlf


/* ------- ELEMENTS ------- */

elementdec:
	V_ELEM V_ID { isElement = 1; np1($2); isElement = 0; }


/* Geometric vector */

vectordec: 
	V_VECTOR V_ID { isVector = 1; np1($2); isVector = 0;  }

vector:
	SYM_OCURL expr SYM_COMMA expr SYM_CCURL


/* Property access */
property:
	V_ID SYM_DOT V_ID { npExpr1_6(); }


/* ------- EXPRESSIONS GRAMMAR ------- */

expr:
	  logicoperation { OP input[] = {OR}; npExpr5(input, 1); } MTH_OR { npExpr3(OR); } expr
	| logicoperation { OP input[] = {OR}; npExpr5(input, 1); }

logicoperation:
	  logicfactor { OP input[] = {AND}; npExpr5(input, 1); } MTH_AND { npExpr3(AND); } logicoperation
	| logicfactor { OP input[] = {AND}; npExpr5(input, 1); }

logicfactor:
	  MTH_NOT { npExpr3(NEG); } comparison { OP input[] = {NEG}; npExpr5(input, 1); }
	| comparison

comparison:
	  operation comp_operator { npExpr3($2); } operation { OP input[]={LT, GT, LTE, GTE, EEQ, NEQ}; npExpr5(input, 6); }
	| operation

operation:
	  factor { OP input[] = {SUM, RES}; npExpr5(input, 2); } MTH_PLUS { npExpr3(SUM); } operation
	| factor { OP input[] = {SUM, RES}; npExpr5(input, 2); } MTH_MINUS { npExpr3(RES); } operation
	| factor { OP input[] = {SUM, RES}; npExpr5(input, 2); }

factor:
	  hvalue { OP input[] = {MULT, DIV}; npExpr5(input, 2);  } MTH_ASTRK { npExpr3(MULT); } factor
	| hvalue { OP input[] = {MULT, DIV}; npExpr5(input, 2); } MTH_DIVIS { npExpr3(DIV); } factor
	| hvalue { OP input[] = {MULT, DIV}; npExpr5(input, 2); }

hvalue:
	  value { OP input[] = {ROOT, POW}; npExpr5(input, 2); } MTH_POWER { npExpr3(POW); } hvalue
	| value { OP input[] = {ROOT, POW}; npExpr5(input, 2); } MTH_ROOT { npExpr3(ROOT); } hvalue
	| value { OP input[] = {ROOT, POW}; npExpr5(input, 2); }

value:
	var_or_cte
	| funcall
	| structaccess
	| property
	| SYM_OPARE { npExpr6(); } expr SYM_CPARE { npExpr7(); }

comp_operator: 
	MTH_GT {$$ = GT; } 
	| MTH_GTEQ { $$ = GTE;}
	| MTH_LT  {$$ = LT; }
	| MTH_LTEQ  {$$ = LTE; }
	| MTH_DEQUA {$$ = EEQ; } 
	| MTH_NOTEQ {$$ = NEQ; }


/* ------- LOGICAL STRUCTURES GRAMMAR ------ */
logicstruct:
	if
	| for
	| while

if:
	LOG_IF { npIf0(); } ifHelper ifHelper3 { npIf3(); } 

ifHelper:
	SYM_OPARE expr SYM_CPARE { npIf1(); } optlf SYM_OCURL crlf newlineCicle SYM_CCURL ifHelper2 

ifHelper2:
	/* empty */ 
	| LOG_ELIF { npIf2(); }  ifHelper

ifHelper3:
	/* empty */ 
	| LOG_ELSE { npIf2(); } optlf SYM_OCURL crlf newlineCicle SYM_CCURL 

for:
	LOG_FOR forHelper SYM_ARROW V_ID {npFor3($4);} optlf SYM_OCURL crlf newlineCicle  SYM_CCURL {npFor4();}

forHelper:
	V_ID {npFor1();}
	| stepfor

stepfor:
	SYM_OBRAC expr SYM_COMMA expr SYM_COMMA expr SYM_CBRAC {npFor2();}

while:
	LOG_WHILE {npWhile1();} SYM_OPARE expr SYM_CPARE {npWhile2();} optlf SYM_OCURL crlf newlineCicle SYM_CCURL {npWhile3();}

newlineCicle:
	newline
	| newline newlineCicle
	

newline:
	stmt crlf 

;

%%

int yyerror(const char *s){
    errorCounter++; 
	printf("\nERROR: %s\n", s);
    return 1; 
}

int main(int argc, char *argv[]) {
	//globals initializations 
	globals = NewVarTable(127); 
	constants = NewVarTable(127);
	functions = NewFuncTable(127); 
	strcpy(currentFunction, ""); 


	pilaNombres = NewStack(TypeString, 64);  
	pilaOperandos = NewStack(TypeInt, 64); 
	pilaOperadores = NewStack(TypeInt, 64); 
	pilaTipos = NewStack(TypeInt, 64); 
	pilaSaltos = NewStack(TypeInt, 64); 
	pilaFor = NewStack(TypeInt, 64); 
	pilaEras = NewStack(TypeInt, 32); 
	pilaGoSubs = NewStack(TypeString, 16);   
	
	filaArrOperandos = NewQueue(TypeInt, 64);
	filaArrNombres = NewQueue(TypeString, 64);
	filaArrTipos = NewQueue(TypeInt, 64);
	
	cubo = NewCubo(); 

	constCounter = 1000; 
	globalsCounter = 2000; 
	localsCounter = 3000; 
	paramCounter = 0; 

	quadrupleCounter = 0; 

	listQuads = NewQUAD();     
	currentQuad = &listQuads; 
	isParam = 0; 
	isVector = 0; 
	isMat = 0; 
	isElement = 0; 

	OPDUM dummy1 = NewOPDUM("    ", -1, TableNull); 
	OPDUM dummy2 = NewOPDUM("    ", -1, TableNull); 
	OPDUM ondesalto = NewOPDUM("    ", -2, TableNull); 
	SetQUAD(currentQuad, GOTO, dummy1, dummy2, ondesalto); 
	currentQuad = currentQuad->next; 
	push(&pilaSaltos, NewVarI(quadrupleCounter)); 
	quadrupleCounter++;

	functions.add(&functions, "print", TableInt, -5); 

	extern FILE *yyin;
	++argv;
	--argc;
	int r;

	yyin = fopen("./main.fs", "r");

	r = yyparse();

	if(r == 0){
		//printf("COMPILATION SUCCESSFUL!\n");
	} 
	fclose(yyin); 
	//printf("Number of errors: %d\n", errorCounter); 
	return 0;
}

void npError(){
    //printf("Destroying structures\n"); 
    //if(errorCounter){
    //     DestroyStack(&pilaOperandos); 
    //     DestroyStack(&pilaTipos); 
    //     DestroyStack(&pilaOperadores); 

    //     DestroyVarTable(&globals);
    //     DestroyFuncTable(&functions); 
    //     DestroyVarTable(&constants); 

    //     DestroyQUAD(&listQuads); 
    //}
}

void npFinalCheck(){
	/* revisar que existan las funciones necesarias de un script y cosas asi */ 
    //printf("Aqui van las globales\n"); 
    //globals.print(&globals);  
    //printf("Aqui van las constantes\n"); 
    //constants.print(&constants); 
    //printf("Aqui van las locales\n"); 
    //functions.print(&functions); 
     
    OPDUM dummy = NewOPDUM("    ", -1, TableNull); 
    OPDUM dummy2 = NewOPDUM("    ", -1, TableNull); 
    OPDUM dummy3 = NewOPDUM("    ", -1, TableNull);
    
    SetQUAD(currentQuad, ENDPROG, dummy, dummy2, dummy3);  
    currentQuad = currentQuad->next; 
    quadrupleCounter++; 

    //validar que exista enter en la tabla de funcitons 
    FTE* enterlookup = functions.lookup(&functions, "enter"); 
    //si no existe error 
    if(!(enterlookup->isSet)){
        yyerror("falta declarar enter");  
    }else{
    //si existe
        int quadline = enterlookup->quadlinenum; 
        //sacar en que cuadruplo empieza 
        Var salto = peek(&pilaSaltos); pop(&pilaSaltos); 
        //sacar salto de la pila 
        //ir a ese salto y rellenarlo con el quadlinenum de enter 
        QUAD* rellena = &listQuads; 
        for(int n = 0; n<salto.data.iVal; n++){
            rellena = rellena->next; 
        }
        rellena->result.virad = quadline; 
    }
    
    
    //printf("Aqui van los quadruplos!!\n");  
    QUAD* iter = &listQuads;  
    char *aux, *aux2; 
    int n = 0; 
    printf("{\"quads\":["); 
    while(iter->isSet){
        aux = QUADToStringMachine(*iter); 
        //aux2 = QUADToStringHuman(*iter); 
        //printf("%d|\t%s\t%s\n",n, aux, aux2);
        iter->next->isSet ? printf("\n\t%s,\n", aux) : printf("\n\t%s\n\t],\n", aux); 
        n++; 
        free(aux); 
        //free(aux2); 
        iter = iter->next; 
    }
    VTE* iter2; 
    printf("\"globals\":[\n"); 
    for(int n = 0; n<constants.size; n++){
        iter2 = (constants.__dict+n);
        while(iter2->isSet){
            if(iter2->type == TableChar){
                 printf("\n\t{\"valor\": '%s', \t\"memdir\": %d}, ", iter2->id, iter2->dir); 
            }else{
                 printf("\n\t{\"valor\": %s, \t\"memdir\": %d}, ", iter2->id, iter2->dir); 
            }
            iter2 = iter2->next;
        }
    }
    printf("\n\t{\"valor\": %s, \t\"memdir\": %d} ", "\"dummy\"", -1); 
    printf("\n\t\t]\n}\n"); 

    Var* stackIter = pilaNombres.__stack; 
    for(int n = 0; n<pilaNombres.size; n++){
        if(stackIter[n].data.sVal){
            free(stackIter[n].data.sVal); 
            stackIter[n].data.sVal = NULL; 
        }
    }
    DestroyStack(&pilaNombres);  
    DestroyStack(&pilaOperandos); 
    DestroyStack(&pilaTipos); 
    DestroyStack(&pilaOperadores); 
    DestroyStack(&pilaFor); 
    DestroyStack(&pilaSaltos); 
    DestroyStack(&pilaEras); 
    DestroyStack(&pilaGoSubs);

	DestroyQueue(&filaArrNombres);
	DestroyQueue(&filaArrOperandos);
	DestroyQueue(&filaArrTipos);

    DestroyVarTable(&globals);
    DestroyFuncTable(&functions); 
    DestroyVarTable(&constants); 

    DestroyQUAD(&listQuads); 
}

void np1(char* id){
	/* Revisar que no exista una varibale llamada igual en el scope actual o globalmente (tablas de variables) */
	/* Agregar variable a tabla de variables, asignado nombre, tipo, y dirección virtual en base a tipo */
    int success = 0 ;
    DIM* dim = calloc(1, sizeof(DIM)); *dim = NewDIM(); 
    int size = strlen(id); 
    char* copy = calloc(size, sizeof(char)); 
    strcpy(copy, id); 
    if(strlen(currentFunction)>0){
        if(isParam){
            success = functions.addParam(&functions, currentFunction, copy, currentType, localsCounter, dim);
        }else{
            success = functions.addVar(&functions, currentFunction, id, currentType, localsCounter,  dim); 
        }
	if(success){localsCounter++;} 
    }else{
        success = globals.add(&globals, id, currentType, globalsCounter, dim);
	if(success){globalsCounter++;} 
    }
    if(!success){
        DestroyDIM(dim); 
        yyerror("Esa variable ya esta definida"); 
    }
}

void np1_1(TableType type){
    if(isVector){
        currentType = TableVector; 
    }else if(isElement){
        currentType = TableElement; 
    }else{
        currentType = type; 
    }
}

void np2(char* id, int sizeArr){
	/* Revisar que el tamaño del arreglo es mayor a 0 y menor a INT_MAX */
	if(sizeArr <= 0 || sizeArr > INT_MAX){
		yyerror("Tamaño de variable dimensionada no válido");
		return;
	}
	
	/* Generar tabla de dimensión */	
	DIM* dim = calloc(1, sizeof(DIM)); *dim = NewDIM(); SetDIM(dim, sizeArr, 1);
	
	/* Revisar que no exista una varibale llamada igual en el scope actual o globalmente (tablas de variables) */
	/* Agregar variable a tabla de variables, asignado nombre, tipo, y dirección virtual en base a tipo */
	int success = 0;
	char* copy = calloc(strlen(id), sizeof(char));
	strcpy(copy, id);
	if(strlen(currentFunction) > 0){
		if(isParam){
			success = functions.addParam(&functions, currentFunction, copy, currentType, localsCounter, dim);
		} else {
			success = functions.addVar(&functions, currentFunction, id, currentType, localsCounter, dim);
		}
		if(success){localsCounter += sizeArr;}
	} else {
		success = globals.add(&globals, id, currentType, globalsCounter, dim);
		if(success){globalsCounter += sizeArr;}
	}
	
	if(!success){
		DestroyDIM(dim);
		yyerror("Esa variable ya está definida");
	}
}

void np3(char* id, int size1, int size2){
	/* Revisar que el tamaño del arreglo es mayor a 0 y menor a INT_MAX */
	if(size1 <= 0 || size1 > INT_MAX || size2 <= 0 || size2 > INT_MAX ){
		yyerror("Tamaño de variable dimensionada no válido");
		return;
	}
	
	/* Generar tabla de dimensión */	
	DIM* dim = calloc(1, sizeof(DIM)); *dim = NewDIM(); SetDIM(dim, size1, 1);
	DIM* dim2 = calloc(1, sizeof(DIM)); *dim2 = NewDIM(); SetDIM(dim2, size2, 1);
	AddDIM(dim, dim2);
	DestroyDIM(dim2);	

	/* Revisar que no exista una varibale llamada igual en el scope actual o globalmente (tablas de variables) */
	/* Agregar variable a tabla de variables, asignado nombre, tipo, y dirección virtual en base a tipo */
	int success = 0;
	char* copy = calloc(strlen(id), sizeof(char));
	strcpy(copy, id);
	if(strlen(currentFunction) > 0){
		if(isParam){
			success = functions.addParam(&functions, currentFunction, copy, currentType, localsCounter, dim);
		} else {
			success = functions.addVar(&functions, currentFunction, id, currentType, localsCounter, dim);
		}
		if(success){localsCounter += size1 * size2;}
	} else {
		success = globals.add(&globals, id, currentType, globalsCounter, dim);
		if(success){globalsCounter += size1 * size2;}
	}
	
	if(!success){
		DestroyDIM(dim);
		yyerror("Esa variable ya está definida");
	}
}

void np4(){
	/* Revisar que no exista una varibale llamada igual en el scope actual o globalmente (tablas de variables) */
	/* Agregar variable a tabla de variables, asignado nombre, tipo, y dirección virtual en base a tipo */
	/* Recuerda que este vector es un pair, asi que haz las modificaciones necesarias */
	/* Push de nombre a pila de Operandos */
	/* Push tipo a pila de Tipos */
}

void np5(){
	/* Revisar que no exista una varibale llamada igual en el scope actual o globalmente (tablas de variables) */
	/* Agregar variable a tabla de variables, asignado nombre, tipo, y dirección virtual en base a tipo */
	/* Recuerda que un elemento es una clase de "objeto" asi que no tengo idea como se debe almacenar */
	/* Push de nombre a pila de Operandos */
	/* Push tipo a pila de "Tipos */
}


void npExpr1_1(char* varid){
    VTE* result = globals.lookup(&globals, varid);  
    if(!(result->isSet) && (strlen(currentFunction) > 0))
        result = functions.lookupVar(&functions, currentFunction, varid);  
    if(!(result->isSet) && (strlen(currentFunction) > 0))
        result = functions.lookupParam(&functions, currentFunction, varid);  

    if(result->isSet){
        int varidsize = strlen(varid); 
        char* buffer = calloc(varidsize + 1, sizeof(char));     
        strcpy(buffer, varid); 
        Var name = NewVarS(buffer);  
        Var dir = NewVarI(result->dir); 
        Var type = NewVarI(result->type); 
        push(&pilaNombres, name); 
        push(&pilaOperandos, dir); 
        push(&pilaTipos, type); 
    }else{
        yyerror("ERROR: variable no declarada");
    }
}
void npExpr1_2_char(char constChar){
	char* aux = calloc(2, sizeof(char)); 
	sprintf(aux, "%c", constChar);
	int constAddr; 
	
	/* Revisar si existe en tabla de constantes */
	/* Si existe continuar; sino agregarlo, asignandole un espacio de memoria */
	DIM* dim = calloc(1, sizeof(DIM)); *dim = NewDIM(); 
	if(constants.add(&constants, aux, TableChar, constCounter, dim)){
		constAddr = constCounter;
		constCounter++; 
	}else{
		VTE* result = constants.lookup(&constants, aux); 
		constAddr = result->dir;
		DestroyDIM(dim); 
	}
	/* Push a pila de operandos */
	push(&pilaNombres, NewVarS(aux)); 
	push(&pilaOperandos, NewVarI(constAddr)); 
	/* Push tipo a pila de tipos */
	push(&pilaTipos, NewVarI(TableChar)); 
    
}
void npExpr1_2_string(char* constString){
	char* aux = calloc(64, sizeof(char));
	strcpy(aux, constString);
	int constAddr;

	/* Revisar si existe en tabla de constantes */
	/* Si existe continuar; sino agregarlo, asignandole un espacio de memoria */
	DIM* dim = calloc(1, sizeof(DIM)); *dim = NewDIM(); 
	if(constants.add(&constants, aux, TableString, constCounter, dim)){
		constAddr = constCounter;		
		constCounter++; 
	}else{
		VTE* result = constants.lookup(&constants, aux);
		constAddr = result->dir;
		DestroyDIM(dim); 
	}
	/* Push a pila de operandos */
	Var name = NewVarS(constString); 
	push(&pilaNombres, name); 

	push(&pilaOperandos, NewVarI(constAddr)); 
	/* Push tipo a pila de tipos */
	Var type = NewVarI(TableString); 
	push(&pilaTipos, type); 
     
}
void npExpr1_2_double(double constDouble){
	char* aux = calloc(32, sizeof(char)); 
	sprintf(aux, "%lf", constDouble); 
	int constAddr;

	/* Revisar si existe en tabla de constantes */
	/* Si existe continuar; sino agregarlo, asignandole un espacio de memoria */
	DIM* dim = calloc(1, sizeof(DIM)); *dim = NewDIM(); 
	if(constants.add(&constants, aux, TableDouble, constCounter, dim)){
		constAddr = constCounter;
		constCounter++; 
	}else{
		VTE* result = constants.lookup(&constants, aux);
		constAddr = result->dir;
		DestroyDIM(dim); 
	}
	/* Push a pila de operandos */
	Var name = NewVarS(aux); 
	push(&pilaNombres, name); 

	push(&pilaOperandos, NewVarI(constAddr)); 
	/* Push tipo a pila de tipos */
	Var type = NewVarI(TableDouble); 
	push(&pilaTipos, type); 
    
}
void npExpr1_2_int(int constInt){
	char* aux =  calloc(32, sizeof(char)); 
	sprintf(aux, "%d", constInt);
	int constAddr;

	/* Revisar si existe en tabla de constantes */
	/* Si existe continuar; sino agregarlo, asignandole un espacio de memoria */
	DIM* dim = calloc(1, sizeof(DIM)); *dim = NewDIM(); 
	if(constants.add(&constants, aux, TableInt, constCounter, dim)){
		constAddr = constCounter; 
		constCounter++; 
	}else{
		VTE* result = constants.lookup(&constants, aux);
		constAddr = result->dir;
		DestroyDIM(dim); 
	}
	/* Push a pila de operandos */
	Var name = NewVarS(aux); 
	push(&pilaNombres, name); 

	push(&pilaOperandos, NewVarI(constAddr)); 
	/* Push tipo a pila de tipos */
	Var type = NewVarI(TableInt); 
	push(&pilaTipos, type); 
    
}
void npExpr1_2_bool(int constBool){
	char* aux =  calloc(32, sizeof(char)); 
	sprintf(aux, "%d", constBool);
	int constAddr; 
	
	/* Revisar si existe en tabla de constantes */
	/* Si existe continuar; sino agregarlo, asignandole un espacio de memoria */
	DIM* dim = calloc(1, sizeof(DIM)); *dim = NewDIM(); 
	if(constants.add(&constants, aux, TableBool, constCounter, dim)){
		constAddr = constCounter;
		constCounter++; 
	}else{
		VTE* result = constants.lookup(&constants, aux);
		constAddr = result->dir;
		DestroyDIM(dim); 
	}
	/* Push a pila de operandos */
	Var name = NewVarS(aux); 
	push(&pilaNombres, name); 

	push(&pilaOperandos, NewVarI(constAddr)); 
	/* Push tipo a pila de tipos */
	Var type = NewVarI(TableBool); 
	push(&pilaTipos, type); 
    
}
void npExpr1_4(){
	// Todavía no tengo claro el acceso a los arreglos
}
void npExpr1_5(){
	// Todavía no tengo claro el acceso a las matrices
}
void npExpr1_6(){
	/* Revisar que exista un vector o elemento con ese id
	   Revisar que ese vector o elemento tenga esa propiedad
	   Push propiedad a pila de operandos
	   Push tipo a pila de tipos */
}
void npExpr3(OP newOpe){
	/* Push de operador a pila de operadores */
    push(&pilaOperadores, NewVarI(newOpe)); 
    //printf("<Debug> ope:%s\n",  OPE2STRING(newOpe)); 
}
void npExpr5(OP* opes, int opesSize){
    if(pilaOperadores.isEmpty(&pilaOperadores))
        return; 
    Var tope = peek(&pilaOperadores); 
    for(int n = 0; n<opesSize; n++){
        if(tope.data.iVal == opes[n]){
            Var right = peek(&pilaOperandos); pop(&pilaOperandos); 
            Var right_type = peek(&pilaTipos); pop(&pilaTipos); 
            Var right_name = peek(&pilaNombres); pop(&pilaNombres); 
            
            Var left = peek(&pilaOperandos); pop(&pilaOperandos); 
            Var left_type = peek(&pilaTipos); pop(&pilaTipos); 
            Var left_name = peek(&pilaNombres); pop(&pilaNombres); 

            Var operador = peek(&pilaOperadores); pop(&pilaOperadores); 
            
            TableType tipoRetorno = TableNull; 
            tipoRetorno = cubo.getReturnType(&cubo, operador.data.iVal, left_type.data.iVal, right_type.data.iVal); 
            if(tipoRetorno != TableNull){
                DIM* dim = calloc(1, sizeof(DIM)); *dim = NewDIM(); 
                char* aux = calloc(64, sizeof(char)); 
                int tempAddr = strlen(currentFunction) > 0 ? localsCounter++ : globalsCounter++; 
                sprintf(aux, "t%d", tempAddr); 
                if(strlen(currentFunction) > 0){
                    functions.addVar(&functions, currentFunction, aux, tipoRetorno, tempAddr, dim); 
                    int debug = 0; 
                }else{
                    globals.add(&globals, aux, tipoRetorno, tempAddr, dim);  
                }

                OPDUM leftdum = NewOPDUM(left_name.data.sVal, left.data.iVal, left_type.data.iVal);
                OPDUM rightdum = NewOPDUM(right_name.data.sVal, right.data.iVal, right_type.data.iVal);
                OPDUM tempdum = NewOPDUM(aux, tempAddr, tipoRetorno);
                
                SetQUAD(currentQuad, operador.data.iVal, leftdum, rightdum, tempdum); 
                currentQuad = currentQuad->next; 
                quadrupleCounter++;  
               
                push(&pilaNombres, NewVarS(aux)); 
                push(&pilaOperandos, NewVarI(tempAddr)); 
                push(&pilaTipos, NewVarI(tipoRetorno)); 
                
            }else{
		yyerror("ERROR: error de tipos"); 
            }
        }
    }
	
}
void npExpr6(){
	/* Meter un fondo falso a la pila de Operadores */
    push(&pilaOperadores, NewVarI(-1)); 
}
void npExpr7(){
	/* Sacar un fondo falso de la pila de Operadores */
    Var tope = peek(&pilaOperadores); 
    pop(&pilaOperadores);  
}

void npFunCall1(char* funID){
	/*revisar que exista el id de la funcion en la tabla de funciones*/
	FTE* result = functions.lookup(&functions, funID); 
	if(result->isSet){
		// push de funID a la pila de GoSubs 
		char* funAux = calloc(64, sizeof(char));
		strcpy(funAux, funID);
		push(&pilaGoSubs, NewVarS(funAux));
		
		if(strcmp(funID, "print") == 0){
			// do nothing for now
		}
		else{ 
		        int funsize = functions.updateSize(&functions, funID);
		        if(strcmp(currentFunction, funID) == 0) {
				funsize = -9999; 
				push(&pilaEras, NewVarI(quadrupleCounter)); //regresar luego aqui a rellenar
		        }
	        
			//generar el quad <ERA, , ,funsize> tamaño de de la funcion
			OPDUM dummy1 = NewOPDUM("    ", -1, TableNull); 
			OPDUM dummy2 = NewOPDUM("    ", -1, TableNull); 
			OPDUM erasize = NewOPDUM("erasize",  funsize, TableNull); 

			SetQUAD(currentQuad, ERA, dummy1, dummy2, erasize); 
			currentQuad = currentQuad->next; 
			quadrupleCounter++;
		}
		
		//generar nueva temporal-> este es el resultado de la llamada
		DIM* dim = calloc(1, sizeof(DIM)); *dim = NewDIM(); 
		char* aux = calloc(64, sizeof(char)); 
		int tempAddr = localsCounter++; 
		sprintf(aux, "t%d", tempAddr); 
		
		push(&pilaOperandos, NewVarI(tempAddr)); 
		push(&pilaTipos, NewVarI(result->returntype)); 
		push(&pilaNombres, NewVarS(aux));
 
		//meter la nueva temporal a la tabla de variables de currentFunction
		functions.addVar(&functions, currentFunction, aux, result->returntype, tempAddr, dim); 
	}else{
		yyerror("Funcion no definida"); 
	}
}


void npFunCall2(){
	Var currentGoSub = peek(&pilaGoSubs); pop(&pilaGoSubs);
	
	if(strcmp(currentGoSub.data.sVal, "print") == 0){
		if(paramCounter != 1){
			yyerror("Numero de argumentos incorrecto");
			return;
		}
		Var toPrint_dir = peek(&pilaOperandos); pop(&pilaOperandos);
		Var toPrint_name = peek(&pilaNombres); pop(&pilaNombres);
		Var toPrint_type = peek(&pilaTipos); pop(&pilaTipos);

		OPDUM printDummy1 = NewOPDUM("    ", -1, TableNull);
		OPDUM printDummy2 = NewOPDUM("    ", -1, TableNull);
		OPDUM printArg = NewOPDUM(toPrint_name.data.sVal, toPrint_dir.data.iVal, toPrint_type.data.iVal);

		SetQUAD(currentQuad, PRINT, printDummy1, printDummy2, printArg);
		currentQuad = currentQuad->next;
		quadrupleCounter++;
		
	}
	else {
		FTE* registro = functions.lookup(&functions, currentGoSub.data.sVal); 
		Stack* firma = registro->signature; 
		int argsize = firma->size; 
		if(argsize != paramCounter){
			yyerror("Numero de argumentos incorrecto"); 
			return; 
		}
	    
		for(int n = argsize-1; n>=0; n--){
			Var id = accessElement(firma, n);
			VTE* registroparam = functions.lookupParam(&functions, currentGoSub.data.sVal, id.data.sVal); 
			Var operandoTipo = peek(&pilaTipos); pop(&pilaTipos);
			Var operandoNombre = peek(&pilaNombres); pop(&pilaNombres); 
			Var operandoDir = peek(&pilaOperandos); pop(&pilaOperandos);
		
			if(!registroparam->type == operandoTipo.data.iVal){
				yyerror("Argumentos con tipos incorrectos"); 
				return; 
			}else{
				OPDUM exprdum = NewOPDUM(operandoNombre.data.sVal, operandoDir.data.iVal, operandoTipo.data.iVal);
				OPDUM dummy = NewOPDUM("    ", -1, TableNull); 
				OPDUM argdum = NewOPDUM(registroparam->id, registroparam->dir, registroparam->type); 
				SetQUAD(currentQuad, PARAM, exprdum, dummy, argdum); 
				currentQuad = currentQuad->next; 
				quadrupleCounter++; 
			}
		}

		OPDUM godummy1 = NewOPDUM("    ", -1, TableNull); 
		OPDUM godummy2 = NewOPDUM("    ", -1, TableNull); 
		OPDUM gosubdum = NewOPDUM(registro->moduleid, registro->quadlinenum, registro->returntype); 
		SetQUAD(currentQuad, GOSUB, godummy1, godummy2, gosubdum); 
		currentQuad = currentQuad->next; 
		quadrupleCounter++; 
	} 

	OPDUM hardcore = NewOPDUM(" 66 ", 66, TableNull); 
	OPDUM dumdum = NewOPDUM("    ", -1, TableNull); 
	Var ret = peek(&pilaOperandos); 
	Var rettype = peek(&pilaTipos); 
	Var retname = peek(&pilaNombres); 
	OPDUM retdum = NewOPDUM(retname.data.sVal, ret.data.iVal, rettype.data.iVal); 
	SetQUAD(currentQuad, ASSIGN, hardcore, dumdum, retdum); 
	currentQuad = currentQuad->next; 
	quadrupleCounter++;
}

void npAssign1(){
    if(pilaOperandos.isEmpty)
        return; 

    Var value = peek(&pilaOperandos); pop(&pilaOperandos); 
    Var value_name = peek(&pilaNombres); pop(&pilaNombres); 
	Var value_type = peek(&pilaTipos); pop(&pilaTipos); 

    Var variable = peek(&pilaOperandos); pop(&pilaOperandos); 
    Var variable_name = peek(&pilaNombres); pop(&pilaNombres); 
	Var variable_type = peek(&pilaTipos); pop(&pilaTipos); 
    
	if(variable_type.data.iVal == value_type.data.iVal){
        OPDUM opdum1 = NewOPDUM(value_name.data.sVal, value.data.iVal, value_type.data.iVal); 
        OPDUM opdummy = NewOPDUM("    ", -1, TableNull); 
        OPDUM result = NewOPDUM(variable_name.data.sVal, variable.data.iVal, variable_type.data.iVal); 
        SetQUAD(currentQuad, ASSIGN, opdum1, opdummy, result);  
        currentQuad = currentQuad->next;
        quadrupleCounter++; 
	}else{
        yyerror("Type Mismatch 001"); 
    }
	
}
void npAssign2(){
	if(pilaOperandos.isEmpty)
		return;	
	
	Var struct_dir = peek(&pilaOperandos); pop(&pilaOperandos);
	Var struct_name = peek(&pilaNombres); pop(&pilaNombres);
	Var struct_type = peek(&pilaTipos); pop(&pilaTipos);
	
	//Sacar variable de tabla de variables para obtener su información de dimensiones
	VTE* lookup = globals.lookup(&globals, struct_name.data.sVal); 
	if(!(lookup->isSet)){
		lookup = functions.lookupParam(&functions, currentFunction, struct_name.data.sVal);
		if(!(lookup->isSet)){
			lookup = functions.lookupVar(&functions, currentFunction, struct_name.data.sVal); 
		}
	}
	
	// Obtener tamaño de dimensiones
	DIM* struct_dim = lookup->dim;
	int size1 = 0;
	int size2 = 0; 
	if(struct_dim->isSet){
		size1 = struct_dim->limsup;
		DIM* dim2 = struct_dim->next;
		if(dim2->isSet){
			size2 = dim2->limsup;
		}
	}

	int i = 0;
	int j = 0;
	int currentCell = struct_dir.data.iVal;
	Var value_dir;
	Var value_name;
	Var value_type;
	OPDUM from;
	OPDUM dummy = NewOPDUM("    ", -1, TableNull);
	OPDUM to = NewOPDUM(struct_name.data.sVal, struct_dir.data.iVal, struct_type.data.iVal);
	
	while(!(filaArrOperandos.isEmpty)){
		value_dir = peekFront(&filaArrOperandos); popFront(&filaArrOperandos);
		if(value_dir.data.iVal == -10){
			i = 0;
			j++;
			currentCell = struct_dir.data.iVal + size1 * j;
		} else {
			value_name = peekFront(&filaArrNombres); popFront(&filaArrNombres);
			value_type = peekFront(&filaArrTipos); popFront(&filaArrTipos);
			if(i < size1 && j < size2){
				from = NewOPDUM(value_name.data.sVal, value_dir.data.iVal, value_type.data.iVal);			
				SetQUAD(currentQuad, ASSIGN, from, dummy, to);
				currentQuad = currentQuad->next;
				quadrupleCounter++;
				i++;
				currentCell++;
			} else {
				yyerror("Undefined index");
			}				
		}
	}
}
void npAssign3(){
	/*
	Si (pOperadores.top() == '='):
		y = pOperandos.pop()
		y_type = pTipos.pop 
		x = pOperandos.pop()
		x_type = pTipos.pop()
	
		vector = pOperandos.pop()
		pTipos.pop() No necesitamos el tipo de vector
		
		if(y_type y x_type no son int o double):
			ERROR: type mismatch
		
		gen quad(=, pair(x, y), ,vector) o como vayas a asignar en memoria
	*/	
}
void npAssign4(){
	/* 
	Aquí asignas el resultado de la función de generacion de elemento al memory address del elemento.
	No se como planeas implementar los elements, asi que no se cómo darte instrucciones precisas 
	*/
}

void npArrGen1(){
	/* Meter a pila de Operandos un marcador de fin en el fin de un arreglo */
	pushBack(&filaArrOperandos, NewVarI(-10));
}

void npArrGen2(){
	Var value_type = peek(&pilaTipos); pop(&pilaTipos);
	Var value_dir = peek(&pilaOperandos); pop(&pilaOperandos);
	Var value_name = peek(&pilaNombres); pop(&pilaNombres);
	if(value_type.data.iVal == currentType){
		pushBack(&filaArrNombres, value_name);
		pushBack(&filaArrOperandos, value_dir);
		pushBack(&filaArrTipos, value_type);
	} else {
		yyerror("Type mismatch");
	}
}


void npIf0(){
	/* Push fondo falso a pila de saltos */
    push(&pilaSaltos, NewVarI(-1)); 
    
}
void npIf1(){
	Var exp_type = peek(&pilaTipos); pop(&pilaTipos); 
	int falsies[] = {2, 4, 5, 6, 9};
	for(int n = 0; n<5; n++){
		if(exp_type.data.iVal == falsies[n]){
			yyerror("Type Mismatch"); 
			return; 
		}
	}
	Var result = peek(&pilaOperandos); pop(&pilaOperandos);
	Var result_name = peek(&pilaNombres); pop(&pilaNombres); 
	Var result_type = peek(&pilaTipos); pop(&pilaTipos); 

	OPDUM dummy = NewOPDUM("    ", -1, TableNull); 
	OPDUM ondesalto = NewOPDUM("____", -2, TableNull); //aqui no es una virtual dir es el salto 
	OPDUM resdum = NewOPDUM(result_name.data.sVal, result.data.iVal, result_type.data.iVal); 
	SetQUAD(currentQuad, GOTOF, resdum, dummy, ondesalto);  
	currentQuad = currentQuad->next; 
	push(&pilaSaltos, NewVarI(quadrupleCounter));
	quadrupleCounter++; 
        
}
void npIf2(){
    OPDUM dummy1 = NewOPDUM("    ", -1, TableNull); 
    OPDUM dummy2 = NewOPDUM("    ", -1, TableNull); 
    OPDUM ondesalto = NewOPDUM("___", -2, TableNull); 
    SetQUAD(currentQuad, GOTO, dummy1, dummy2, ondesalto); 
    currentQuad = currentQuad->next; 
	
    Var result = peek(&pilaSaltos); pop(&pilaSaltos); 
	push(&pilaSaltos, NewVarI(quadrupleCounter));
    quadrupleCounter++; 

    int quadindex = result.data.iVal; 
    QUAD* listiter = &listQuads; 
    for(int n = 0; n<quadindex; n++)
        listiter = listiter->next; 
    listiter->result.virad = quadrupleCounter; 
}
void npIf3(){
    Var tofill;  
    do{
	    tofill = peek(&pilaSaltos); pop(&pilaSaltos); 
        int quadindex = tofill.data.iVal; 
        QUAD* listiter = &listQuads; 
        for(int n = 0; n<quadindex; n++)
            listiter = listiter->next; 
        listiter->result.virad = quadrupleCounter; 
    }while(tofill.data.iVal != -1); 
}


void npWhile1(){
	/* push siguiente numero de cuadruplo a la pila de saltos */
    push(&pilaSaltos, NewVarI(quadrupleCounter)); 
}
void npWhile2(){
	Var exp_type = peek(&pilaTipos); pop(&pilaTipos);
    int falsies[] = {2, 4, 5, 6, 9};
    for(int n = 0; n<5; n++){
    	if(exp_type.data.iVal == falsies[n]){
		    yyerror("Type Mismatch"); 
            return; 
	    }
    }
	Var result = peek(&pilaOperadores); pop(&pilaOperadores);
    Var result_name = peek(&pilaNombres); pop(&pilaNombres); 
    Var result_type = peek(&pilaTipos); pop(&pilaTipos); 

    OPDUM resdum = NewOPDUM(result_name.data.sVal, result.data.iVal, result_type.data.iVal); 
    OPDUM dummy = NewOPDUM("    ", -1, TableNull); 
    OPDUM ondesalto = NewOPDUM("____", -2, TableNull); 
    SetQUAD(currentQuad, GOTOF, resdum, dummy, ondesalto); 
    currentQuad = currentQuad->next; 
    push(&pilaSaltos, NewVarI(quadrupleCounter)); 
    quadrupleCounter++; 
}
void npWhile3(){
    
	Var salend = peek(&pilaSaltos); pop(&pilaSaltos);
	Var salreturn = peek(&pilaSaltos); pop(&pilaSaltos);
    
    OPDUM dummy1 = NewOPDUM("    ", -1, TableNull); 
    OPDUM dummy2 = NewOPDUM("    ", -1, TableNull); 
    OPDUM ondesalto = NewOPDUM("jumpback", salreturn.data.iVal, TableNull); //restale 1 porque cuando se metio apuntaba al de abajo
     
    SetQUAD(currentQuad, GOTO,  dummy1, dummy2, ondesalto); 
    currentQuad = currentQuad->next; 
    quadrupleCounter++; 
    
    int quadindex = salend.data.iVal; 
    QUAD* listiter = &listQuads; 
    for(int n = 0; n<quadindex; n++)
        listiter = listiter->next; 
    listiter->result.virad = quadrupleCounter; 
}


void npFor1(){
	/* THIS IS SKETCHY, IDK IF IT WILL WORK */
	/*
	Checa si V_ID es un array

	pTipos.push(V_ID.type)
	start = siguiente temporal disponible
	gen quad(=,dirBase de V_ID, ,start) //tipo apuntador o algo asi idk
	pOperandos.push(start)

	limit = siguiente temporal disponible
	gen quad(=,sizeof(V_ID) + dirBase(V_ID), ,limit) //guardas el valor
	pOperandos.push(limit)

	pilaForHelper.push("array")
	*/
}
void npFor2(){
	/* 0 es vanilla for y 1 es array for */
    push(&pilaFor, NewVarI(0)); 
    
	
}
void npFor3(char* iterId){
    Var tipoFor = peek(&pilaFor); pop(&pilaFor); 
    if(tipoFor.data.iVal == 1){
        //meditate
    }else if(tipoFor.data.iVal == 0){
        Var limit = peek(&pilaOperandos); pop(&pilaOperandos); 
        Var limit_type = peek(&pilaTipos); pop(&pilaTipos);
        Var limit_name = peek(&pilaNombres); pop(&pilaNombres); 

        Var step = peek(&pilaOperandos); pop(&pilaOperandos); 
        Var step_type = peek(&pilaTipos); pop(&pilaTipos);
        Var step_name = peek(&pilaNombres); pop(&pilaNombres); 

        Var start = peek(&pilaOperandos); pop(&pilaOperandos); 
        Var start_type = peek(&pilaTipos); pop(&pilaTipos);
        Var start_name = peek(&pilaNombres); pop(&pilaNombres); 

        if((limit_type.data.iVal == TableInt || limit_type.data.iVal == TableDouble) && 
           (step_type.data.iVal == TableInt || step_type.data.iVal == TableDouble) && 
           (start_type.data.iVal == TableInt || start_type.data.iVal == TableDouble) && 
           (start_type.data.iVal == step_type.data.iVal)){
            
		        //Checas que no exista ya una variable con ese nombre
                VTE* lookup = globals.lookup(&globals, iterId); 
                if(lookup->isSet)
                    yyerror("iterator id already taken");  
                lookup = functions.lookupParam(&functions, currentFunction, iterId); 
                if(lookup->isSet)
                    yyerror("iterator id already taken"); 
                lookup = functions.lookupVar(&functions, currentFunction, iterId); 
                if(lookup->isSet)
                    yyerror("iterator id already taken"); 

                //CHECKFOR 
                OPDUM leftcheck = NewOPDUM(start_name.data.sVal, start.data.iVal, start_type.data.iVal); 
                OPDUM rightcheck = NewOPDUM(limit_name.data.sVal, limit.data.iVal, start_type.data.iVal); 
                OPDUM dummycheck = NewOPDUM("    ", -3, TableNull); 
                SetQUAD(currentQuad, FORCHECK, leftcheck, rightcheck, dummycheck); 
                currentQuad = currentQuad->next; 
                quadrupleCounter++; 
                

		        //Crea una variable el nombre que pusiste (iter) de tipo start_type
                DIM* dim = calloc(1, sizeof(DIM)); *dim = NewDIM(); 
                int tempAddr = localsCounter++; 
                functions.addVar(&functions, currentFunction, iterId, start_type.data.iVal, tempAddr, dim); 

		        //init = siguiente temporal
                DIM* dim2  = calloc(1, sizeof(DIM)); *dim2 = NewDIM(); 
                char* aux = calloc(64, sizeof(char)); 
                int tempAddr2 = localsCounter++; 
                sprintf(aux, "t%d", tempAddr); 
                functions.addVar(&functions, currentFunction, aux, start_type.data.iVal, tempAddr2, dim2);
                
		        //gen quad(-, start, step, init)
                OPDUM leftdum1 = NewOPDUM(start_name.data.sVal, start.data.iVal, start_type.data.iVal); 
                OPDUM rightdum1 = NewOPDUM(step_name.data.sVal, step.data.iVal, step_type.data.iVal); 
                OPDUM resdum = NewOPDUM(aux, tempAddr2, start_type.data.iVal); 
                SetQUAD(currentQuad, RES, leftdum1, rightdum1, resdum); 
                currentQuad = currentQuad->next; 
                quadrupleCounter++; 
                
		        //gen quad(=, init, , iter)
                OPDUM leftdum2 = NewOPDUM(aux, tempAddr2, start_type.data.iVal); 
                OPDUM dummydum = NewOPDUM("____", -1, TableNull); 
                OPDUM resdum2 = NewOPDUM(iterId, tempAddr, start_type.data.iVal);  
                SetQUAD(currentQuad, ASSIGN, leftdum2, dummydum, resdum2); 
                currentQuad = currentQuad->next; 
                quadrupleCounter++; 

		        //pSaltos.push(siguiente cuadruplo a generar)
                push(&pilaSaltos, NewVarI(quadrupleCounter));  

		        //gen quad(+, iter, step, iter)
                OPDUM leftdum3 = NewOPDUM(iterId, tempAddr, start_type.data.iVal); 
                OPDUM rightdum3 = NewOPDUM(step_name.data.sVal, step.data.iVal, step_type.data.iVal);   
                OPDUM resdum3 = NewOPDUM(iterId, tempAddr, start_type.data.iVal); 
                SetQUAD(currentQuad, SUM, leftdum3, rightdum3, resdum3); 
                currentQuad = currentQuad->next; 
                quadrupleCounter++; 
                
                //res = siguiente temporal
                DIM* dim3 = calloc(1, sizeof(DIM)); *dim3 = NewDIM(); 
                char* aux2 = calloc(64, sizeof(char)); 
                int tempAddr3 = localsCounter++; 
                sprintf(aux2, "t%d", tempAddr3); 
                functions.addVar(&functions, currentFunction, aux2, TableBool, tempAddr3, dim3); 

		        //gen quad(<=, iter, limit, res)
                OPDUM leftdum4 = NewOPDUM(iterId, tempAddr, start_type.data.iVal); 
                OPDUM rightdum4 = NewOPDUM(limit_name.data.sVal, limit.data.iVal, limit_type.data.iVal); 
                OPDUM resdum4 = NewOPDUM(aux2, tempAddr3, TableBool); 
                SetQUAD(currentQuad, LTE, leftdum4, rightdum4, resdum4);
                currentQuad = currentQuad->next; 
                quadrupleCounter++; 
    
		        //gen quad(gotof, res, , __)
                OPDUM leftdumfinal = NewOPDUM(aux2, tempAddr3, start_type.data.iVal); 
                OPDUM dummyfinal = NewOPDUM("    ", -1, TableNull); 
                OPDUM resdumfinal = NewOPDUM("____", -2, TableNull); 
                SetQUAD(currentQuad, GOTOF, leftdumfinal, dummyfinal, resdumfinal); 
                currentQuad = currentQuad->next; 
                
		        //pSaltos.push(cuadruplo donde pusiste el gotof)
                push(&pilaSaltos, NewVarI(quadrupleCounter)); 

                quadrupleCounter++; 
                free(aux); 
                free(aux2); 
            
        }else{
            yyerror("los valores del for deben de ser int o double y el limite inferior debe de ser del mismo tipo del step"); 
        }
        
        
    }else{
        yyerror("How did you even manage to break this!?"); 
    }

}

void npFor4(){
    Var salexit = peek(&pilaSaltos); pop(&pilaSaltos); 
    Var salreturn = peek(&pilaSaltos); pop(&pilaSaltos); 
    
	//gen quad(goto, , , return)
    OPDUM dummy1 = NewOPDUM("    ", -1, TableNull);
    OPDUM dummy2 = NewOPDUM("    ", -1, TableNull); 
    OPDUM returndum = NewOPDUM("jumpback", salreturn.data.iVal, TableInt);
    SetQUAD(currentQuad, GOTO, dummy1, dummy2, returndum); 
    currentQuad = currentQuad->next; 
    quadrupleCounter++; 

	//fillquad(exit, siguiente cuadruplo)
    int quadindex = salexit.data.iVal; 
    QUAD* listiter = &listQuads; 
    for(int n = 0; n<quadindex; n++)
        listiter = listiter->next; 
    listiter->result.virad = quadrupleCounter;  
}

void npFun1(char* newFunId){
    if(functions.add(&functions, newFunId, currentType, quadrupleCounter)){
        strcpy(currentFunction, newFunId); 
    }else{
        yyerror("Function Already Defined"); 
    }
}

void npFun2(){

    while(!pilaEras.isEmpty(&pilaEras)){
        int eraquadline = (peek(&pilaEras)).data.iVal; pop(&pilaEras); 
        QUAD* iter = &listQuads; 
        for(int n = 0; n<eraquadline; n++){
            iter = iter->next; 
        }
        int funcsize =  functions.updateSize(&functions, currentFunction); 
        iter->result.virad = funcsize; 
    }

    strcpy(currentFunction, ""); 
    localsCounter = 3000; 
    OPDUM dummy1 = NewOPDUM("    ", -1, TableNull); 
    OPDUM dummy2 = NewOPDUM("    ", -1, TableNull); 
    OPDUM dummy3 = NewOPDUM("    ", -1, TableNull); 
    SetQUAD(currentQuad, ENDPROC, dummy1, dummy2, dummy3); 
    currentQuad = currentQuad->next; 
    quadrupleCounter++; 
}

void npReturn(){
    OPDUM dummy = NewOPDUM("    ", -1, TableNull);
    OPDUM dummy1 = NewOPDUM("    ", -1, TableNull);
    Var operando = peek(&pilaNombres); pop(&pilaNombres);  
    Var operando_addr = peek(&pilaOperandos); pop(&pilaOperandos);  
    Var operando_type = peek(&pilaTipos); pop(&pilaTipos); 
    OPDUM result = NewOPDUM(operando.data.sVal, operando_addr.data.iVal, operando_type.data.iVal); 
    SetQUAD(currentQuad, RETURN, dummy, dummy1, result); 
    currentQuad = currentQuad->next; 
    quadrupleCounter++; 
}

void npClean(){
    while(!pilaOperadores.isEmpty(&pilaOperadores)){
        pop(&pilaTipos); 
        pop(&pilaNombres);
        pop(&pilaOperandos); 
    }
        
}
