%{
	#include <stdio.h> 
    #include <stdlib.h>
    #include <jedi.h>

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
	void npExpr1_2();
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
   
    //int subContextCounter = 0;  
    //Stack* filaPilaTipos; 
    
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

prog: script { npFinalCheck(); } ;


/* ------- SCRIPT GRAMMAR ------- */

script:  
	/* empty */
	| assign crlf script 
	| expr crlf script
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
	| LF {printf("\n");}

optlf:
	/* empty */
	| crlf {printf("\n");} 

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
	V_VAR V_ID SYM_COLON vartypes { np1_1($2); }

basictypes:
	  V_CHAR { npExpr1_2(); }
	| V_STRING { npExpr1_2(); }
	| V_FLOAT { npExpr1_2(); }
	| V_DOUBLE { npExpr1_2(); }
	| V_INT { npExpr1_2(); }
	| V_BOOL { npExpr1_2(); }

vartypes:
	  T_INT  { np1($1);}
	| T_FLOAT { np1($1);}  
	| T_DOUBLE{ np1($1);} 
	| T_CHAR{ np1($1);} 
	| T_STRING{ np1($1);} 
	| T_BOOL{ np1($1);}  


var_or_cte:
	V_ID { npExpr1_1(); }
	| basictypes

assign: 
	vardec MTH_SEQUA { npAssign0(); } expr { npAssign1(); }
	| arrdec MTH_SEQUA { npAssign0(); } arr { npAssign2(); }
	| matdec MTH_SEQUA { npAssign0(); } mat { npAssign2(); }
	| vectordec MTH_SEQUA { npAssign0(); } vector {npAssign3();}
	| elementdec MTH_SEQUA { npAssign0(); } funcall {npAssign4();}
	| V_ID { npExpr1_1(); } MTH_SEQUA { npAssign0(); } expr {npAssign1();}
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
	V_ELEM V_ID { np5(); }


/* Geometric vector */

vectordec: 
	V_VECTOR V_ID { np4(); }

vector:
	SYM_OCURL expr SYM_COMMA expr SYM_CCURL


/* Property access */
property:
	V_ID SYM_DOT V_ID { npExpr1_6(); }


/* ------- EXPRESSIONS GRAMMAR ------- */

expr:
	logicoperation { npExpr15(); } MTH_OR { npExpr14(); } expr
	| logicoperation { npExpr15(); }

logicoperation:
	logicfactor { npExpr13(); } MTH_AND { npExpr12(); } logicoperation
	| logicfactor { npExpr13(); }

logicfactor:
	MTH_NOT { npExpr10(); } comparison { npExpr11(); }
	| comparison

comparison:
	operation comp_operator { npExpr8(); } operation { npExpr9(); }
	| operation

operation:
	factor { npExpr4(); } MTH_PLUS { npExpr2(); } operation
	| factor { npExpr4(); } MTH_MINUS { npExpr2(); } operation
	| factor { npExpr4(); }

factor:
	hvalue { npExpr5(); } MTH_ASTRK { npExpr3(); } factor
	| hvalue { npExpr5(); } MTH_DIVIS { npExpr3(); } factor
	| hvalue { npExpr5(); }

hvalue:
	value { npExpr5_1(); } MTH_POWER { npExpr3_1(); } hvalue
	| value { npExpr5_1(); } MTH_ROOT { npExpr3_1(); } hvalue
	| value { npExpr5_1(); }

value:
	var_or_cte 
	| funcall
	| structaccess
	| property
	| SYM_OPARE { npExpr6(); } expr SYM_CPARE { npExpr7(); }

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
    //filaPilaTipos = calloc(1, sizeof(Stack)); 
    //filaPilaTipos[subContextCounter] = NewStack(32, TypeInt); 
    
    
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
    /*for(int n = 0; n<100; n++){
        if(filaPilaTipos+n)
            DestroyStack(&(filaPilaTipos[n])); 
    }*/
    //free(filaPilaTipos); 
	return 0;
}

void npFinalCheck(){
	printf("<FINALCHECK> ");
	/* revisar que existan las funciones necesarias de un script y cosas asi */
}

void np1(char* id){
    printf("<NP1 %s >", id); 
	/* Revisar que no exista una varibale llamada igual en el scope actual o globalmente (tablas de variables) */
}
void np1_1(DataType type){
    printf("<NP1_1 >"); 
	/* Agregar variable a tabla de variables, asignado nombre, tipo, y dirección virtual en base a tipo */
	/* Push de nombre a pila de Operandos */
	/* Push tipo a pila de Tipos */
}

void np2(){
	printf("<NP2> ");
	/* Revisar que no exista una varibale llamada igual en el scope actual o globalmente (tablas de variables) */
	/* Revisar que el tamaño del arreglo es mayor a 0 y menor a INT_MAX */
	/* Agregar variable a tabla de variables, asignado nombre, tipo, y dirección virtual en base a tipo */
	/* Generar tabla de dimensión */
	/* Push de nombre a pila de Operandos */
	/* Push tipo a pila de Tipos */
}

void np3(){
	printf("<NP3> ");
	/* Revisar que no exista una varibale llamada igual en el scope actual o globalmente (tablas de variables) */
	/* Revisar que el tamaño de ambas dimensiones son mayores a 0 y menores a INT_MAX */
	/* Agregar variable a tabla de variables, asignado nombre, tipo, y dirección virtual en base a tipo */
	/* Generar tablas de dimensiónes */
	/* Push de apuntador a primera posicion a pila de Operandos */
	/* Push tipo a pila de Tipos */
}

void np4(){
	printf("<NP4> ");
	/* Revisar que no exista una varibale llamada igual en el scope actual o globalmente (tablas de variables) */
	/* Agregar variable a tabla de variables, asignado nombre, tipo, y dirección virtual en base a tipo */
	/* Recuerda que este vector es un pair, asi que haz las modificaciones necesarias */
	/* Push de nombre a pila de Operandos */
	/* Push tipo a pila de Tipos */
}

void np5(){
	printf("<NP5> ");
	/* Revisar que no exista una varibale llamada igual en el scope actual o globalmente (tablas de variables) */
	/* Agregar variable a tabla de variables, asignado nombre, tipo, y dirección virtual en base a tipo */
	/* Recuerda que un elemento es una clase de "objeto" asi que no tengo idea como se debe almacenar */
	/* Push de nombre a pila de Operandos */
	/* Push tipo a pila de Tipos */
}


void npExpr1_1(){
	printf("<NP_EXPR_1_1> ");
	/* Push variable a pila de operandos */
	/* Push tipo a pila de tipos */
}
void npExpr1_2(){
	printf("<NP_EXPR_1_2> ");
	/* Revisar si existe en tabla de constantes */
	/* Si existe continuar; sino agregarlo, asignandole un espacio de memoria */
	/* Push a pila de operandos */
	/* Push tipo a pila de tipos */
}
void npExpr1_3(){
	printf("<NP_EXPR_1_3> ");
	/* Push tipo a pila de tipos */
	/* Esto es después de una llamada a función, de alguna manera debe haber en la 
	   pila de operadores el temporal con el resultado a la funcion */

}
void npExpr1_4(){
	printf("<NP_EXPR_1_4> ");
	// Todavía no tengo claro el acceso a los arreglos
}
void npExpr1_5(){
	printf("<NP_EXPR_1_5> ");
	// Todavía no tengo claro el acceso a las matrices
}
void npExpr1_6(){
	printf("<NP_EXPR_1_6> ");
	/* Revisar que exista un vector o elemento con ese id
	   Revisar que ese vector o elemento tenga esa propiedad
	   Push propiedad a pila de operandos
	   Push tipo a pila de tipos */
}
void npExpr2(){
	printf("<NP_EXPR_2> ");
 	/* Push de operador a pila de operadores (+ o -) */
}
void npExpr3(){
	printf("<NP_EXPR_3> ");
	/* Push de operador a pila de operadores (* o /) */
}
void npExpr3_1(){
	printf("<NP_EXPR_3_1> ");
	/* Push de operador a pila de operadores (^ o ^^) */
}
void npExpr4(){
	printf("<NP_EXPR_4> ");
	/*
	Si el top de la pila es un + o un -:
	    right = pilaOperandos.pop
	    right_type = pTipos.pop
	    left  = pOperandos.pop
	    left_type = pTipos.pop
	    operador = pOperadores.pop

	    resType = cubosematinco(operador, left_type, right_type)

	    Si (resType != Error):
	        result = siguiente temporal disponible
	        generar quad(operador, left, right, result)
	        push de result a pOperandos
	        push tipo de resType a pTipos
	    Else: 
	    	Lanzar error de tipos
	*/

}
void npExpr5(){
	printf("<NP_EXPR_5> ");
	/*
	Si el top de la pila es un * o un /:
	    right = pilaOperandos.pop
	    right_type = pTipos.pop
	    left  = pOperandos.pop
	    left_type = pTipos.pop
	    operador = pOperadores.pop

	    resType = cubosematinco(operador, left_type, right_type)

	    Si (resType != Error):
	        result = siguiente temporal disponible
	        generar quad(operador, left, right, result)
	        push de result a pOperandos
	        push tipo de resType a pTipos
	    Else: 
	    	Lanzar error de tipos
	*/
}
void npExpr5_1(){
	printf("<NP_EXPR_5_1> ");
	/*
	Si el top de la pila es un ^ o un ^^:
	    right = pilaOperandos.pop
	    right_type = pTipos.pop
	    left  = pOperandos.pop
	    left_type = pTipos.pop
	    operador = pOperadores.pop

	    resType = cubosematinco(operador, left_type, right_type)

	    Si (resType != Error):
	        result = siguiente temporal disponible
	        generar quad(operador, left, right, result)
	        push de result a pOperandos
	        push tipo de resType a pTipos
	    Else: 
	    	Lanzar error de tipos
	*/
}
void npExpr6(){
	printf("<NP_EXPR_6> ");
	/* Meter un fondo falso a la pila de Operadores */
}
void npExpr7(){
	printf("<NP_EXPR_7> ");
	/* Sacar un fondo falso de la pila de Operadores */
}
void npExpr8(){
	printf("<NP_EXPR_8> ");
	/* Push el operador relacional a pila de Operadores */
}
void npExpr9(){
	printf("<NP_EXPR_9> ");
	/*
	Si el top de la pila es un operador relacional:
	    right = pilaOperandos.pop
	    right_type = pTipos.pop
	    left  = pOperandos.pop
	    left_type = pTipos.pop
	    operador = pOperadores.pop

	    resType = cubosematinco(operador, left_type, right_type)

	    Si (resType != Error):
	        result = siguiente temporal disponible
	        generar quad(operador, left, right, result)
	        push de result a pOperandos
	        push tipo de resType a pTipos
	    Else: 
	    	Lanzar error de tipos
	*/
}
void npExpr10(){
	printf("<NP_EXPR_10> ");
	/* Meter un not (!) a la pila de operadores */
}
void npExpr11(){
	printf("<NP_EXPR_11> ");
	/*
	Si el top de la pila es un not:
	    operando = pilaOperandos.pop
	    type = pilaTipos.pop

	    operador = pOperadores.pop

	    resType = cubosematinco(operador, operando, operando)

	    Si (resType != Error):
	        result = siguiente temporal disponible
	        generar quad(operador, operando, , result)
	        push de result a pOperandos
	        push tipo de resType a pTipos
	    Else: 
	    	Lanzar error de tipos
	*/
}
void npExpr12(){
	printf("<NP_EXPR_12> ");
	/* Meter un AND a la pila de operadores */
}
void npExpr13(){
	printf("<NP_EXPR_13> ");
	/*
	Si el top de la pila es un and:
	    right = pilaOperandos.pop
	    right_type = pTipos.pop
	    left  = pOperandos.pop
	    left_type = pTipos.pop
	    operador = pOperadores.pop

	    resType = cubosematinco(operador, left_type, right_type)

	    Si (resType != Error):
	        result = siguiente temporal disponible
	        generar quad(operador, left, right, result)
	        push de result a pOperandos
	        push tipo de resType a pTipos
	    Else: 
	    	Lanzar error de tipos
	*/
}
void npExpr14(){
	printf("<NP_EXPR_14> ");
	/* Meter un OR a la pila de operadores */
}
void npExpr15(){
	printf("<NP_EXPR_15> ");
	/*
	Si el top de la pila es un OR:
	    right = pilaOperandos.pop
	    right_type = pTipos.pop
	    left  = pOperandos.pop
	    left_type = pTipos.pop
	    operador = pOperadores.pop

	    resType = cubosematinco(operador, left_type, right_type)

	    Si (resType != Error):
	        result = siguiente temporal disponible
	        generar quad(operador, left, right, result)
	        push de result a pOperandos
	        push tipo de resType a pTipos
	    Else: 
	    	Lanzar error de tipos
	*/
}

void npAssign0(){
	printf("<NP_ASSIGN_0> ");
	/* Push '=' a pila de operadores */
}
void npAssign1(){
	printf("<NP_ASSIGN_1> ");
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
	printf("<NP_ASSIGN_2> ");
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
	printf("<NP_ASSIGN_3> ");
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
	printf("<NP_ASSIGN_3> ");
	/* 
	Aquí asignas el resultado de la función de generacion de elemento al memory address del elemento.
	No se como planeas implementar los elements, asi que no se cómo darte instrucciones precisas 
	*/
}

void npArrGen1(){
	printf("<NP_ARRGEN_1> ");
	/* Meter tope de arreglo (]) a filaArrOperandos (queue) */
}
void npArrGen2(){
	printf("<NP_ARRGEN_2> ");
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
	printf("<NP_IF_0> ");
	/* Push fondo falso a pila de saltos */
}
void npIf1(){
	printf("<NP_IF_1> ");
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
	printf("<NP_IF_2> ");
	/*
	gen quad(goto, , ,___) El ultimo espacio se va a llenar después
	false = pSaltos.pop()
	pSaltos.push(el numero de cuadruplo donde pusiste el goto)
	fill(false, el numero del cuadruplo después del goto)
	*/
}
void npIf3(){
	printf("<NP_IF_3> ");
	/*
	tofill = pSaltos.pop()
	while (tofill != fondo falso)
		fill(tofill, numero siguiente cuadruplo)
	*/
}


void npWhile1(){
	printf("<NP_WHILE_1> ");
	/* push siguiente numero de cuadruplo a la pila de saltos */
}
void npWhile2(){
	printf("<NP_WHILE_2> ");
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
	printf("<NP_WHILE_3> ");
	/*
	end = pSaltos.pop()
	return = pSaltos.pop()
	gen quad(goto, , , return)
	fill(end, el siguiente cuadruplo)
	*/
}


void npFor1(){
	printf("<NP_FOR_1> ");
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
	printf("<NP_FOR_2> ");
	/* THIS IS SKETCHY, IDK IF IT WILL WORK */
	/*
	pilaForHelper.push("step")
	*/
}
void npFor3(){
	printf("<NP_FOR_3> ");
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
	printf("<NP_FOR_1> ");
	/* THIS IS SKETCHY, IDK IF IT WILL WORK */
	/*
	exit = pSaltos.pop
	return = pSaltos.pop
	gen quad(goto, , , return)
	fillquad(exit, siguiente cuadruplo)
	*/
}
