%{
	#include <stdio.h> 
    #include <stdlib.h>
    #include <string.h> 
    #include <jedi.h>
    #include "cube.h"

	extern int yylex();
	extern int yyparse();
     

	# define YYERROR_VERBOSE 1
 
	void yyerror(const char *s);

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
    void npExpr1_2_float(float); 
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
	void npAssign0();
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

    // Global Counters //virtual mem-dirs
    int globalsCounter; 
    int localsCounter; 
    int constCounter; 
    int quadrupleCounter; 
    
    //Global Variables
    char currentFunction[96];  
    TableType currentType;  //tipo de variable
    TableType returnType;  //tipo de valor de retorno de funcion
    int isParam; // true si la variable que se esta parseando es parametro
    
    int errorCounter = 0; 

    // Global Structures
    VarTable globals; //variables globales
    VarTable constants; //constantes globales
    FuncTable functions; 

    Stack pilaOperandos; 
    Stack pilaOperadores; 
    Stack pilaTipos; 

    QUAD listQuads;   
    QUAD* currentQuad; 
  
    CuboSemantico cubo;  
    // Helper functions 
    TableType DT2TT(DataType current){
        switch(current){
            case TypeInt: return TableInt; break; 
            case TypeFloat: return TableFloat; break; 
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

%type <op> comp_operator //no terminal 
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

%token <yyfloat> V_FLOAT

%token <yyint> V_INT

%token <yydouble> V_DOUBLE

%token <yybool> V_BOOL

%token <yyint> V_ARR

%token <yyint> V_MAT

%token <yyint>V_VECTOR

%token <yyint> V_ELEM


%token <datatype> T_BOOL
%token <datatype> T_INT
%token <datatype> T_FLOAT
%token <datatype> T_DOUBLE
%token <datatype> T_CHAR
%token <datatype> T_STRING

%token RES_ORDER
%token RES_MEDIT
%token RES_RETRN

%code requires{
    #include <jedi.h>
}

%union{
	/* TODO: Define data types for vars and ids */
    DataType datatype; 
    int yyint; 
    float yyfloat; 
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
    | error { npError(); errorCounter++; } 


/* ------- SCRIPT GRAMMAR ------- */

script:  
	/* empty */
	| assign crlf script 
	| expr crlf script
	| function crlf script
	| generaldec crlf script
	| crlf script


/* ------- GENERAL GRAMMAR ------- */

crlf:
	  CR LF
	| LF {printf("\n");}

optlf:
	/* empty */
	| crlf {printf("\n");} 

function: 
	RES_ORDER V_ID SYM_COLON vartypes SYM_OPARE {npFun1($2); isParam = 1;}funparams SYM_CPARE{isParam = 0;} optlf SYM_OCURL crlf funbody SYM_CCURL{npFun2(); }

funparams: 
	  generaldec morefunparams
    | /*empty*/

morefunparams:
	  SYM_COMMA generaldec morefunparams
    | /*empty*/

funbody:
	  stmt crlf funbody
    | generaldec crlf funbody
    | crlf funbody
    | /*emtpy*/

generaldec: /* declaras o declaras y assignas */
	  vardec
	| arrdec
	| matdec
	| vectordec
	| elementdec 
	| vardec MTH_SEQUA { npAssign0(); } expr { npAssign1(); }
	| arrdec MTH_SEQUA { npAssign0(); } arr { npAssign2(); }
	| matdec MTH_SEQUA { npAssign0(); } mat { npAssign2(); }
	| vectordec MTH_SEQUA { npAssign0(); } vector {npAssign3();}
	| elementdec MTH_SEQUA { npAssign0(); } funcall {npAssign4();}

stmt: 
	  assign 
	| expr
	| logicstruct
	| RES_MEDIT
	| ret

funcall: 
	V_ID SYM_OPARE funcallHelper SYM_CPARE { npExpr1_3(); }

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
	V_VAR V_ID SYM_COLON vartypes { np1($2); }

basictypes:
	  V_CHAR { npExpr1_2_char($1); }
	| V_STRING { npExpr1_2_string($1); }
	| V_FLOAT { npExpr1_2_float($1); }
	| V_DOUBLE { npExpr1_2_double($1); }
	| V_INT { npExpr1_2_int($1); }
	| V_BOOL { npExpr1_2_bool($1); }

vartypes:
	  T_INT  { np1_1($1);}
	| T_FLOAT { np1_1($1);}  
	| T_DOUBLE{ np1_1($1);} 
	| T_CHAR{ np1_1($1);} 
	| T_STRING{ np1_1($1);} 
	| T_BOOL{ np1_1($1);}  


var_or_cte:
	  V_ID { npExpr1_1($1); }
	| basictypes

assign: 
	 V_ID { npExpr1_1($1); } MTH_SEQUA { npAssign0(); } expr {npAssign1();}
	| structaccess MTH_SEQUA { npAssign0(); } expr {npAssign1();}
	| property MTH_SEQUA { npAssign0(); } expr {npAssign1();}

/* ------- DATA STRUCTURES GRAMMAR ------- */

structaccess:
	V_ID SYM_OBRAC expr SYM_CBRAC { npExpr1_4(); } structIndex

structIndex:
	/* empty */
	| SYM_OBRAC expr SYM_CBRAC { npExpr1_5(); }

/* Array*/

arrdec:
	V_ARR V_ID SYM_COLON vartypes SYM_OBRAC V_INT SYM_CBRAC { np2();}

arr:
	SYM_OBRAC arrHelper SYM_CBRAC { npArrGen1(); }

arrHelper: 
	expr SYM_COMMA { npArrGen2(); } arrHelper
	| expr { npArrGen2(); }


/* Matrix */

matdec:
	V_MAT V_ID SYM_COLON vartypes SYM_OBRAC V_INT SYM_CBRAC SYM_OBRAC V_INT SYM_CBRAC { np3(); }

mat:
	SYM_OBRAC optlf matHelper SYM_CBRAC

matHelper:
	arr SYM_COMMA optlf matHelper
	| arr optlf


/* ------- ELEMENTS ------- */

elementdec:
	V_ELEM V_ID { np1($2); }


/* Geometric vector */

vectordec: 
	V_VECTOR V_ID { np1($2); }

vector:
	SYM_OCURL expr SYM_COMMA expr SYM_CCURL


/* Property access */
property:
	V_ID SYM_DOT V_ID { npExpr1_6(); }


/* ------- EXPRESSIONS GRAMMAR ------- */

expr:
	logicoperation { npExpr5((OP[]){OR}, 1); } MTH_OR { npExpr3(OR); } expr
	| logicoperation { npExpr5((OP[]){OR}, 1); }

logicoperation:
	logicfactor { npExpr5((OP[]){AND}, 1); } MTH_AND { npExpr3(AND); } logicoperation
	| logicfactor { npExpr5((OP[]){AND}, 1); }

logicfactor:
	MTH_NOT { npExpr3(NEG); } comparison { npExpr5((OP[]){NEG}, 1); }
	| comparison

comparison:
	operation comp_operator { npExpr3($2); } operation { npExpr5((OP[]){LT, GT, LTE, GTE, EEQ, NEQ}, 6); }
	| operation

operation:
	factor { npExpr5((OP[]){SUM, RES}, 2); } MTH_PLUS { npExpr3(SUM); } operation
	| factor { npExpr5((OP[]){SUM, RES}, 2); } MTH_MINUS { npExpr3(RES); } operation
	| factor { npExpr5((OP[]){SUM, RES}, 2); }

factor:
	hvalue { npExpr5((OP[]){MULT, DIV}, 2); } MTH_ASTRK { npExpr3(MULT); } factor
	| hvalue { npExpr5((OP[]){MULT, DIV}, 2); } MTH_DIVIS { npExpr3(DIV); } factor
	| hvalue { npExpr5((OP[]){MULT, DIV}, 2); }

hvalue:
	value { npExpr5((OP[]){ROOT, POW}, 2); } MTH_POWER { npExpr3(POW); } hvalue
	| value { npExpr5((OP[]){ROOT, POW}, 2); } MTH_ROOT { npExpr3(ROOT); } hvalue
	| value { npExpr5((OP[]){ROOT, POW}, 2); }

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
	LOG_FOR forHelper SYM_ARROW V_ID {npFor3();} optlf SYM_OCURL crlf newlineCicle  SYM_CCURL {npFor4();}

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

void yyerror(const char *s){
	printf("\nERROR: %s\n", s);
}

int main(int argc, char *argv[]) {
    //globals initializations 
    globals = NewVarTable(127); 
    constants = NewVarTable(127);
    functions = NewFuncTable(127); 
    strcpy(currentFunction, ""); 
    
    cubo = NewCubo(); 
    pilaOperandos = NewStack(TypeString, 64); 
    pilaOperadores = NewStack(TypeInt, 64); 
    pilaTipos = NewStack(TypeInt, 64); 

    listQuads = NewQUAD();     
    currentQuad = &listQuads; 
    isParam = 0; 

	extern FILE *yyin;
	++argv;
	--argc;
	int r;

	yyin = fopen("./test.fs", "r");

	r = yyparse();

	if(r == 0){
		printf("COMPILATION SUCCESSFUL!\n");
	} 
    fclose(yyin); 
    printf("%d\n", errorCounter); 
	return 0;
}

void npError(){
    if(errorCounter <= 0){
     DestroyStack(&pilaOperandos); 
     DestroyStack(&pilaTipos); 
     DestroyStack(&pilaOperadores); 

     DestroyVarTable(&globals);
     DestroyFuncTable(&functions); 
     DestroyVarTable(&constants); 

     DestroyQUAD(&listQuads); 
    }
}

void npFinalCheck(){
	/* revisar que existan las funciones necesarias de un script y cosas asi */
   /* printf("Aqui van las globales\n"); 
    globals.print(&globals);  
    printf("Aqui van las constantes\n"); 
    constants.print(&constants); 
    printf("Aqui van las locales\n"); 
    functions.print(&functions); 
   
    printf("Aqui van los quadruplos!!\n");  
    QUAD* iter = &listQuads;  
    char* aux; 
    while(iter->isSet){
        aux = QUADToStringHuman(*iter); 
        printf("%s\n", aux); 
        free(aux); 
        iter = iter->next; 
    }*/
     
    DestroyStack(&pilaOperandos); 
    DestroyStack(&pilaTipos); 
    DestroyStack(&pilaOperadores); 

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
    if(strlen(currentFunction)>0){
        if(isParam){
            success = functions.addParam(&functions, currentFunction, id, currentType, localsCounter++, dim);
        }else{
            success = functions.addVar(&functions, currentFunction, id, currentType, localsCounter++,  dim); 
        } 
    }else{
        success = globals.add(&globals, id, currentType, globalsCounter++, dim); 
    }
    if(success){
        /* Push de nombre a pila de Operandos */
        Var name = NewVarS(id); 
        push(&pilaOperandos, name); 
	    /* Push tipo a pila de Tipos */
        Var type = NewVarI(currentType); 
        push(&pilaTipos, type); 
    }else{
        DestroyDIM(dim); 
        yyerror("Esa variable ya esta definida"); 
    }
}

void np1_1(DataType type){
    currentType = DT2TT(type); 
    returnType = DT2TT(type); 
}

void np2(){
	/* Revisar que no exista una varibale llamada igual en el scope actual o globalmente (tablas de variables) */
	/* Revisar que el tamaño del arreglo es mayor a 0 y menor a INT_MAX */
	/* Agregar variable a tabla de variables, asignado nombre, tipo, y dirección virtual en base a tipo */
	/* Generar tabla de dimensión */
	/* Push de nombre a pila de Operandos */
	/* Push tipo a pila de Tipos */
}

void np3(){
	/* Revisar que no exista una varibale llamada igual en el scope actual o globalmente (tablas de variables) */
	/* Revisar que el tamaño de ambas dimensiones son mayores a 0 y menores a INT_MAX */
	/* Agregar variable a tabla de variables, asignado nombre, tipo, y dirección virtual en base a tipo */
	/* Generar tablas de dimensiónes */
	/* Push de apuntador a primera posicion a pila de Operandos */
	/* Push tipo a pila de Tipos */
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
    if(!result->isSet && (strlen(currentFunction) > 0))
        result = functions.lookupVar(&functions, currentFunction, varid);  
    if(!result->isSet && (strlen(currentFunction) > 0))
        result = functions.lookupParam(&functions, currentFunction, varid);  
    if(result->isSet){
        Var name = NewVarS(varid);  
        Var type = NewVarI(result->type); 
        push(&pilaOperandos, name); 
        push(&pilaTipos, type); 
    }else{
        yyerror("ERROR: variable no declarada");
    }
}
void npExpr1_2_char(char constChar){
	/* Revisar si existe en tabla de constantes */
    char aux[2]; 
    sprintf(aux, "%c", constChar); 
    /* Si existe continuar; sino agregarlo, asignandole un espacio de memoria */
    DIM* dim = calloc(1, sizeof(DIM)); *dim = NewDIM(); 
    if(constants.add(&constants, aux, TypeChar, constCounter, dim)){
        constCounter++; 
    }else{
        DestroyDIM(dim); 
    }
    /* Push a pila de operandos */
    Var name = NewVarS(aux); 
    push(&pilaOperandos, name); 
    
    /* Push tipo a pila de tipos */
    Var type = NewVarI(TypeChar); 
    push(&pilaTipos, type); 
    
}
void npExpr1_2_string(char* constString){
	/* Revisar si existe en tabla de constantes */
	/* Si existe continuar; sino agregarlo, asignandole un espacio de memoria */
    DIM* dim = calloc(1, sizeof(DIM)); *dim = NewDIM(); 
    if(constants.add(&constants, constString, TypeString, constCounter, dim)){
        constCounter++; 
    }else{
        DestroyDIM(dim); 
    }
    /* Push a pila de operandos */
    Var name = NewVarS(constString); 
    push(&pilaOperandos, name); 
    
    /* Push tipo a pila de tipos */
    Var type = NewVarI(TypeString); 
    push(&pilaTipos, type); 
     
}
void npExpr1_2_float(float constFloat){
	/* Revisar si existe en tabla de constantes */
    char aux[32]; 
    sprintf(aux, "%f", constFloat); 
    /* Si existe continuar; sino agregarlo, asignandole un espacio de memoria */
    DIM* dim = calloc(1, sizeof(DIM)); *dim = NewDIM(); 
    if(constants.add(&constants, aux, TypeFloat, constCounter, dim)){
        constCounter++; 
    }else{
        DestroyDIM(dim); 
    }
    /* Push a pila de operandos */
    Var name = NewVarS(aux); 
    push(&pilaOperandos, name); 
    
    /* Push tipo a pila de tipos */
    Var type = NewVarI(TypeFloat); 
    push(&pilaTipos, type); 
}
void npExpr1_2_double(double constDouble){
	/* Revisar si existe en tabla de constantes */
     char aux[32]; 
     sprintf(aux, "%lf", constDouble); 
     /* Si existe continuar; sino agregarlo, asignandole un espacio de memoria */
     DIM* dim = calloc(1, sizeof(DIM)); *dim = NewDIM(); 
     if(constants.add(&constants, aux, TypeDouble, constCounter, dim)){
         constCounter++; 
     }else{
         DestroyDIM(dim); 
     }
     /* Push a pila de operandos */
     Var name = NewVarS(aux); 
     push(&pilaOperandos, name); 
     
     /* Push tipo a pila de tipos */
     Var type = NewVarI(TypeDouble); 
     push(&pilaTipos, type); 
    
}
void npExpr1_2_int(int constInt){
	/* Revisar si existe en tabla de constantes */
    char aux[32]; 
    sprintf(aux, "%d", constInt); 
    /* Si existe continuar; sino agregarlo, asignandole un espacio de memoria */
    DIM* dim = calloc(1, sizeof(DIM)); *dim = NewDIM(); 
    if(constants.add(&constants, aux, TypeInt, constCounter, dim)){
        constCounter++; 
    }else{
        DestroyDIM(dim); 
    }
    /* Push a pila de operandos */
    Var name = NewVarS(aux); 
    push(&pilaOperandos, name); 
    
    /* Push tipo a pila de tipos */
    Var type = NewVarI(TypeInt); 
    push(&pilaTipos, type); 
    
}
void npExpr1_2_bool(int constBool){
	/* Revisar si existe en tabla de constantes */
    char aux[32]; 
    sprintf(aux, "%d", constBool); 
    /* Si existe continuar; sino agregarlo, asignandole un espacio de memoria */
    DIM* dim = calloc(1, sizeof(DIM)); *dim = NewDIM(); 
    if(constants.add(&constants, aux, TypeBool, constCounter, dim)){
        constCounter++; 
    }else{
        DestroyDIM(dim); 
    }
    /* Push a pila de operandos */
    Var name = NewVarS(aux); 
    push(&pilaOperandos, name); 
    
    /* Push tipo a pila de tipos */
    Var type = NewVarI(TypeBool); 
    push(&pilaTipos, type); 
    
}
void npExpr1_3(){
	/* Push tipo a pila de tipos */
	/* Esto es después de una llamada a función, de alguna manera debe haber en la 
	   pila de operadores el temporal con el resultado a la funcion */

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
}
void npExpr5(OP* opes, int opesSize){
    if(pilaOperadores.isEmpty(&pilaOperadores))
        return; 
	//Si el top de la pila es un ^ o un ^^:
    Var tope = peek(&pilaOperadores); 
    for(int n = 0; n<opesSize; n++){
        if(tope.data.iVal == opes[n]){
    	    //right = pilaOperandos.pop
            Var right = peek(&pilaOperandos); pop(&pilaOperandos); 
    	    //right_type = pTipos.pop
            Var right_type = peek(&pilaTipos); pop(&pilaTipos); 
    	    //left  = pOperandos.pop
            Var left = peek(&pilaOperandos); pop(&pilaOperandos); 
    	    //left_type = pTipos.pop
            Var left_type = peek(&pilaTipos); pop(&pilaTipos); 
    	    //operador = pOperadores.pop
            Var operador = peek(&pilaOperadores); pop(&pilaOperadores); 
             
    	    //resType = cubosematinco(operador, left_type, right_type)
            TableType tipoRetorno = TableNull; 
            tipoRetorno = cubo.getReturnType(&cubo, operador.data.iVal, left_type.data.iVal, right_type.data.iVal); 
    
    	    //Si (resType != Error):
            if(tipoRetorno != TableNull){
    	       // result = siguiente temporal disponible
               DIM* dim = calloc(1, sizeof(DIM)); *dim = NewDIM(); 
               VTE temp; 
               VTE* lookupizq = NULL; 
               VTE* lookupder = NULL; 
               char* aux = calloc(21, sizeof(char)); 
               if(strlen(currentFunction) > 0){
                   sscanf(aux, "%d", &localsCounter);  
                   temp = NewVTE(); SetVTE(&temp, aux, tipoRetorno, localsCounter++, dim); 
                    functions.addVar(&functions, currentFunction, temp.id, temp.type, temp.dir, temp.dim);
                   lookupizq = functions.lookupVar(&functions, currentFunction, left.data.sVal); 
                   if(!lookupizq->isSet)
                        lookupizq = functions.lookupParam(&functions, currentFunction, left.data.sVal); 
                   lookupder = functions.lookupVar(&functions, currentFunction, right.data.sVal); 
                   if(!lookupder->isSet)
                        lookupder = functions.lookupParam(&functions, currentFunction, right.data.sVal); 
               }else{
                   sscanf(aux, "%d", &globalsCounter); 
                   temp = NewVTE(); SetVTE(&temp, aux, tipoRetorno, globalsCounter++, dim); 
                   globals.add(&globals, temp.id, temp.type, temp.dir, temp.dim); 
               }
               if(!lookupizq || !lookupizq->isSet)
                   lookupizq = globals.lookup(&globals, left.data.sVal); 
               if(!lookupder || !lookupder->isSet)
                   lookupder = globals.lookup(&globals, right.data.sVal); 

    	       // generar quad(operador, left, right, result)
                OPDUM leftdum = NewOPDUM(lookupizq->id, lookupizq->dir, lookupizq->type);
                OPDUM rightdum = NewOPDUM(lookupder->id, lookupder->dir, lookupder->type);
                OPDUM tempdum = NewOPDUM(temp.id, temp.dir, temp.type); 
                
                SetQUAD(currentQuad, operador.data.iVal, leftdum, rightdum, tempdum); 
                currentQuad = currentQuad->next; 
    	       // push de result a pOperandos
               Var tempOperando = NewVarS(temp.id); 
                push(&pilaOperandos, tempOperando); 
    	       // push tipo de resType a pTipos
               Var tempTipo = NewVarI(temp.type); 
                push(&pilaTipos, tempTipo); 
               //free el aux; 
                free(aux); 
            }else{
    	    //Else: 
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

void npAssign0(){
	/* Push '=' a pila de operadores */
}
void npAssign1(){
	/* 
	Si (pOperadores.top() == '=')
		pOperadores.pop()
		value = pOperandos.pop()
		value_type = pTipos.pop()

		variable = pOperandos.pop()
		variable_type = pTipo.pop()

		Si (variable_type == value_type):
			gen quad(=, value, , variable)
		else:
			Error: type mismatch
	*/
}
void npAssign2(){
	/*
	Si (pOperadores.top() == '=')
		pOperadores.pop()
		tamaño1 = size(*pOprandos.top()) o como le tengas que hacer pa sacar el tamaño de la primera dimensión
		tamaño2 = 0
		if (es una matriz):
			tamaño2 = tamaño de la segunda dimensión
		
		primeraCelda = *pOperandos.pop() (Osea, lo que apunta el apuntador que esta en tope)
		tipo = pTipos.pop()

		i=0 
		j=0
		celdaActual = primeraCelda
		while (filaArrOperandos is not empty):
			if(filaArrOperandos.top() == ']'):
				i = 0
				j++
				celdaActual = primeraCelda + tamaño1*j
				filaArrOperandos.pop()
			else:
				value = filaArrOperandos.pop()
				value_type = filaArrTipos.pop()
				if(value_type == tipo && i < tamaño1 && j < tamaño2):
					gen quad(=, value, , celdaActual)
					i++
					celdaActual++
				else:
					ERROR: type mismatch o undefined index
	*/

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
		
		if(y_type y x_type no son int, float, o double):
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
	/* Meter tope de arreglo (]) a filaArrOperandos (queue) */
}
void npArrGen2(){
	/*
	tipo = pTipos.pop()
	Si(pTipos.top() == tipo):
		filaArrOperandos.push(pOperandos.pop())
		filaArrTipos.push(tipo)
	Else:
		ERROR: type mismatch
	*/
}


void npIf0(){
	/* Push fondo falso a pila de saltos */
}
void npIf1(){
	/*
	exp_type = pTipos.pop()
	Si (exp_type es nan o algo no evaluable como truthy value):
		ERROR type mismatch
	else:
		result = pOperadores.pop()
		gen quad(gotof, result, ,__) El ultimo espacio se va a llenar después
		pSaltos.push(el numero de cuadruplo donde pusiste el gotof)
	*/
}
void npIf2(){
	/*
	gen quad(goto, , ,___) El ultimo espacio se va a llenar después
	false = pSaltos.pop()
	pSaltos.push(el numero de cuadruplo donde pusiste el goto)
	fill(false, el numero del cuadruplo después del goto)
	*/
}
void npIf3(){
	/*
	tofill = pSaltos.pop()
	while (tofill != fondo falso)
		fill(tofill, numero siguiente cuadruplo)
	*/
}


void npWhile1(){
	/* push siguiente numero de cuadruplo a la pila de saltos */
}
void npWhile2(){
	/* 
	exp_type = pTipos.pop()
	Si (exp_type es nan o algo no evaluable como truthy value):
		ERROR type mismatch
	else:
		result = pOperadores.pop()
		gen quad(gotof, result, ,___) Después se va a completar este cuadruplo
		pSaltos.push(el numero de cuadruplo donde estaba quad)
	*/
}
void npWhile3(){
	/*
	end = pSaltos.pop()
	return = pSaltos.pop()
	gen quad(goto, , , return)
	fill(end, el siguiente cuadruplo)
	*/
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
	/* THIS IS SKETCHY, IDK IF IT WILL WORK */
	/*
	pilaForHelper.push("step")
	*/
}
void npFor3(){
	/* THIS IS SKETCHY, IDK IF IT WILL WORK */
	/*
	if(pilaForHelper.pop == array)
		Checas que no exista ya una variable con ese nombre
		Crea una variable de tipo apuntador con el nombre que pusiste (iter)

		limit = pOperandos.pop
		start = pOperandos.pop

		init = siguiente temporal
		gen quad(-, start, 1, init)
		gen quad(=, init, , iter) inicializa el iterador una posición atrás, namas para poder sumarle uno

		pSaltos.push(siguiente cuadruplo a generar)
		gen quad(+, iter, 1, iter)
		res = siguiente temporal disponible
		gen quad(<, iter, limit, result)
		pSaltos.push(siguiente cuadruplo a generar)
		gen quad(gotof, result, , ___)

	elif(pilaForHelper.pop == step)
		limit = pOperandos.pop
		limit_type = pTipos.pop()
		step = pOperandos.pop
		step_type = pTipos.pop()
		start = pOperandos.pop
		start_type = pTipos.pop()

		Checa que sean int, float o double, y que sean del mismo tipo, para no tener cosas raras, sino lanzas error de que no se vale eso

		Checas que no exista ya una variable con ese nombre
		Crea una variable el nombre que pusiste (iter) de tipo start_type
		init = siguiente temporal
		gen quad(-, start, step, init)
		gen quad(=, init, , iter)
		pSaltos.push(siguiente cuadruplo a generar)
		gen quad(+, iter, step, iter)
		res = siguiente temporal
		gen quad(<=, iter, limit, res)
		gen quad(gotof, res, , __)
		pSaltos.push(cuadruplo donde pusiste el gotof)

	else
		lanzas error, no se si esto pueda pasar la mera netflix, pero por si acaso
	*/

}
void npFor4(){
	/* THIS IS SKETCHY, IDK IF IT WILL WORK */
	/*
	exit = pSaltos.pop
	return = pSaltos.pop
	gen quad(goto, , , return)
	fillquad(exit, siguiente cuadruplo)
	*/
}

void npFun1(char* newFunId){
    if(functions.add(&functions, newFunId, returnType, quadrupleCounter)){
        strcpy(currentFunction, newFunId); 
    }else{
        yyerror("Function Already Defined"); 
    }
}

void npFun2(){
    strcpy(currentFunction, ""); 
}
