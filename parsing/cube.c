#include <stdlib.h>
#include <stdio.h> 
#include "cube.h"
#include <jedi.h>

TableType  __getReturnType(CuboSemantico* cube, OP operator, TableType type1, TableType type2){
    return cube->__c[operator][type1][type2];
}

CuboSemantico NewCubo() {
	CuboSemantico CS;	
    
    for(int op = 0; op<25; op++){
        for(int type1 = 0; type1<9; type1++){
            for(int type2 = 0; type2<9; type2++){
                CS.__c[op][type1][type2] = TableNull; }}}

/* --------------------- INT _ --------------------- */
	//Int Int
	CS.__c[EEQ ][TableInt][TableInt] = TableBool;
	CS.__c[GT  ][TableInt][TableInt] = TableBool;
	CS.__c[LTE ][TableInt][TableInt] = TableBool;
	CS.__c[NEQ ][TableInt][TableInt] = TableBool;
	CS.__c[GT  ][TableInt][TableInt] = TableBool;
	CS.__c[LT  ][TableInt][TableInt] = TableBool;
	CS.__c[NEG ][TableInt][TableInt] = TableBool;
	CS.__c[SUM ][TableInt][TableInt] = TableInt;
	CS.__c[RES ][TableInt][TableInt] = TableInt;
	CS.__c[MULT][TableInt][TableInt] = TableInt;
	CS.__c[DIV ][TableInt][TableInt] = TableInt;
	CS.__c[ROOT][TableInt][TableInt] = TableInt;
	CS.__c[POW ][TableInt][TableInt] = TableInt;
	CS.__c[AND ][TableInt][TableInt] = TableBool;
	CS.__c[OR  ][TableInt][TableInt] = TableBool;
	//Int Double
	CS.__c[EEQ ][TableInt][TableDouble] = TableBool;
	CS.__c[GT  ][TableInt][TableDouble] = TableBool;
	CS.__c[LTE ][TableInt][TableDouble] = TableBool;
	CS.__c[NEQ ][TableInt][TableDouble] = TableBool;
	CS.__c[GT  ][TableInt][TableDouble] = TableBool;
	CS.__c[LT  ][TableInt][TableDouble] = TableBool;
	CS.__c[NEG ][TableInt][TableDouble] = TableNull;
	CS.__c[SUM ][TableInt][TableDouble] = TableDouble;
	CS.__c[RES ][TableInt][TableDouble] = TableDouble;
	CS.__c[MULT][TableInt][TableDouble] = TableDouble;
	CS.__c[DIV ][TableInt][TableDouble] = TableDouble;
	CS.__c[ROOT][TableInt][TableDouble] = TableDouble;
	CS.__c[POW ][TableInt][TableDouble] = TableDouble;
	CS.__c[AND ][TableInt][TableDouble] = TableBool;
	CS.__c[OR  ][TableInt][TableDouble] = TableBool;
	//Int Char
	CS.__c[EEQ ][TableInt][TableChar] = TableBool;
	CS.__c[GT  ][TableInt][TableChar] = TableBool;
	CS.__c[LTE ][TableInt][TableChar] = TableBool;
	CS.__c[NEQ ][TableInt][TableChar] = TableBool;
	CS.__c[GT  ][TableInt][TableChar] = TableBool;
	CS.__c[LT  ][TableInt][TableChar] = TableBool;
	CS.__c[NEG ][TableInt][TableChar] = TableInt;
	CS.__c[SUM ][TableInt][TableChar] = TableInt;
	CS.__c[RES ][TableInt][TableChar] = TableInt;
	CS.__c[MULT][TableInt][TableChar] = TableInt;
	CS.__c[DIV ][TableInt][TableChar] = TableInt;
	CS.__c[ROOT][TableInt][TableChar] = TableInt;
	CS.__c[POW ][TableInt][TableChar] = TableInt;
	CS.__c[AND ][TableInt][TableChar] = TableBool;
	CS.__c[OR  ][TableInt][TableChar] = TableBool;
	//Int Bool
	CS.__c[EEQ ][TableInt][TableBool] = TableBool;
	CS.__c[GT  ][TableInt][TableBool] = TableBool;
	CS.__c[LTE ][TableInt][TableBool] = TableBool;
	CS.__c[NEQ ][TableInt][TableBool] = TableBool;
	CS.__c[GT  ][TableInt][TableBool] = TableBool;
	CS.__c[LT  ][TableInt][TableBool] = TableBool;
	CS.__c[NEG ][TableInt][TableBool] = TableNull;
	CS.__c[SUM ][TableInt][TableBool] = TableNull;
	CS.__c[RES ][TableInt][TableBool] = TableNull;
	CS.__c[MULT][TableInt][TableBool] = TableNull;
	CS.__c[DIV ][TableInt][TableBool] = TableNull;
	CS.__c[ROOT][TableInt][TableBool] = TableNull;
	CS.__c[POW ][TableInt][TableBool] = TableNull;
	CS.__c[AND ][TableInt][TableBool] = TableBool;
	CS.__c[OR  ][TableInt][TableBool] = TableBool;
/* --------------------- DOUBLE ___ --------------------- */
	//Double Int
	CS.__c[EEQ ][TableDouble][TableInt] = TableBool;
	CS.__c[GT  ][TableDouble][TableInt] = TableBool;
	CS.__c[LTE ][TableDouble][TableInt] = TableBool;
	CS.__c[NEQ ][TableDouble][TableInt] = TableBool;
	CS.__c[GT  ][TableDouble][TableInt] = TableBool;
	CS.__c[LT  ][TableDouble][TableInt] = TableBool;
	CS.__c[NEG ][TableDouble][TableInt] = TableNull;
	CS.__c[SUM ][TableDouble][TableInt] = TableDouble;
	CS.__c[RES ][TableDouble][TableInt] = TableDouble;
	CS.__c[MULT][TableDouble][TableInt] = TableDouble;
	CS.__c[DIV ][TableDouble][TableInt] = TableDouble;
	CS.__c[ROOT][TableDouble][TableInt] = TableDouble;
	CS.__c[POW ][TableDouble][TableInt] = TableDouble;
	CS.__c[AND ][TableDouble][TableInt] = TableBool;
	CS.__c[OR  ][TableDouble][TableInt] = TableBool;
	//Double Float	//Double Double
	CS.__c[EEQ ][TableDouble][TableDouble] = TableBool;
	CS.__c[GT  ][TableDouble][TableDouble] = TableBool;
	CS.__c[LTE ][TableDouble][TableDouble] = TableBool;
	CS.__c[NEQ ][TableDouble][TableDouble] = TableBool;
	CS.__c[GT  ][TableDouble][TableDouble] = TableBool;
	CS.__c[LT  ][TableDouble][TableDouble] = TableBool;
	CS.__c[NEG ][TableDouble][TableDouble] = TableBool;
	CS.__c[SUM ][TableDouble][TableDouble] = TableDouble;
	CS.__c[RES ][TableDouble][TableDouble] = TableDouble;
	CS.__c[MULT][TableDouble][TableDouble] = TableDouble;
	CS.__c[DIV ][TableDouble][TableDouble] = TableDouble;
	CS.__c[ROOT][TableDouble][TableDouble] = TableDouble;
	CS.__c[POW ][TableDouble][TableDouble] = TableDouble;
	CS.__c[AND ][TableDouble][TableDouble] = TableBool;
	CS.__c[OR  ][TableDouble][TableDouble] = TableBool;
	//Double Char
	CS.__c[EEQ ][TableDouble][TableChar] = TableBool;
	CS.__c[GT  ][TableDouble][TableChar] = TableBool;
	CS.__c[LTE ][TableDouble][TableChar] = TableBool;
	CS.__c[NEQ ][TableDouble][TableChar] = TableBool;
	CS.__c[GT  ][TableDouble][TableChar] = TableBool;
	CS.__c[LT  ][TableDouble][TableChar] = TableBool;
	CS.__c[NEG ][TableDouble][TableChar] = TableNull;
	CS.__c[SUM ][TableDouble][TableChar] = TableDouble;
	CS.__c[RES ][TableDouble][TableChar] = TableDouble;
	CS.__c[MULT][TableDouble][TableChar] = TableDouble;
	CS.__c[DIV ][TableDouble][TableChar] = TableDouble;
	CS.__c[ROOT][TableDouble][TableChar] = TableDouble;
	CS.__c[POW ][TableDouble][TableChar] = TableDouble;
	CS.__c[AND ][TableDouble][TableChar] = TableBool;
	CS.__c[OR  ][TableDouble][TableChar] = TableBool;
	//Double Bool
	CS.__c[EEQ ][TableDouble][TableBool] = TableBool;
	CS.__c[GT  ][TableDouble][TableBool] = TableBool;
	CS.__c[LTE ][TableDouble][TableBool] = TableBool;
	CS.__c[NEQ ][TableDouble][TableBool] = TableBool;
	CS.__c[GT  ][TableDouble][TableBool] = TableBool;
	CS.__c[LT  ][TableDouble][TableBool] = TableBool;
	CS.__c[NEG ][TableDouble][TableBool] = TableNull;
	CS.__c[SUM ][TableDouble][TableBool] = TableDouble;
	CS.__c[RES ][TableDouble][TableBool] = TableDouble;
	CS.__c[MULT][TableDouble][TableBool] = TableDouble;
	CS.__c[DIV ][TableDouble][TableBool] = TableDouble;
	CS.__c[ROOT][TableDouble][TableBool] = TableDouble;
	CS.__c[POW ][TableDouble][TableBool] = TableDouble;
	CS.__c[AND ][TableDouble][TableBool] = TableBool;
	CS.__c[OR  ][TableDouble][TableBool] = TableBool;
	/* --------------------- CHAR ___ --------------------- */
	//Char Int
	CS.__c[EEQ ][TableChar][TableInt] = TableBool;
	CS.__c[GT  ][TableChar][TableInt] = TableBool;
	CS.__c[LTE ][TableChar][TableInt] = TableBool;
	CS.__c[NEQ ][TableChar][TableInt] = TableBool;
	CS.__c[GT  ][TableChar][TableInt] = TableBool;
	CS.__c[LT  ][TableChar][TableInt] = TableBool;
	CS.__c[NEG ][TableChar][TableInt] = TableNull;
	CS.__c[SUM ][TableChar][TableInt] = TableInt;
	CS.__c[RES ][TableChar][TableInt] = TableInt;
	CS.__c[MULT][TableChar][TableInt] = TableInt;
	CS.__c[DIV ][TableChar][TableInt] = TableInt;
	CS.__c[ROOT][TableChar][TableInt] = TableInt;
	CS.__c[POW ][TableChar][TableInt] = TableInt;
	CS.__c[AND ][TableChar][TableInt] = TableBool;
	CS.__c[OR  ][TableChar][TableInt] = TableBool;
	//Char Float	//Char Double
	CS.__c[EEQ ][TableChar][TableDouble] = TableBool;
	CS.__c[GT  ][TableChar][TableDouble] = TableBool;
	CS.__c[LTE ][TableChar][TableDouble] = TableBool;
	CS.__c[NEQ ][TableChar][TableDouble] = TableBool;
	CS.__c[GT  ][TableChar][TableDouble] = TableBool;
	CS.__c[LT  ][TableChar][TableDouble] = TableBool;
	CS.__c[NEG ][TableChar][TableDouble] = TableNull;
	CS.__c[SUM ][TableChar][TableDouble] = TableDouble;
	CS.__c[RES ][TableChar][TableDouble] = TableDouble;
	CS.__c[MULT][TableChar][TableDouble] = TableDouble;
	CS.__c[DIV ][TableChar][TableDouble] = TableDouble;
	CS.__c[ROOT][TableChar][TableDouble] = TableDouble;
	CS.__c[POW ][TableChar][TableDouble] = TableDouble;
	CS.__c[AND ][TableChar][TableDouble] = TableBool;
	CS.__c[OR  ][TableChar][TableDouble] = TableBool;
	//Char Char
	CS.__c[EEQ ][TableChar][TableChar] = TableBool;
	CS.__c[GT  ][TableChar][TableChar] = TableBool;
	CS.__c[LTE ][TableChar][TableChar] = TableBool;
	CS.__c[NEQ ][TableChar][TableChar] = TableBool;
	CS.__c[GT  ][TableChar][TableChar] = TableBool;
	CS.__c[LT  ][TableChar][TableChar] = TableBool;
	CS.__c[NEG ][TableChar][TableChar] = TableBool;
	CS.__c[SUM ][TableChar][TableChar] = TableInt;
	CS.__c[RES ][TableChar][TableChar] = TableInt;
	CS.__c[MULT][TableChar][TableChar] = TableInt;
	CS.__c[DIV ][TableChar][TableChar] = TableInt;
	CS.__c[ROOT][TableChar][TableChar] = TableInt;
	CS.__c[POW ][TableChar][TableChar] = TableInt;
	CS.__c[AND ][TableChar][TableChar] = TableBool;
	CS.__c[OR  ][TableChar][TableChar] = TableBool;
	//Char String
	CS.__c[EEQ ][TableChar][TableString] = TableNull;
	CS.__c[GT  ][TableChar][TableString] = TableNull;
	CS.__c[LTE ][TableChar][TableString] = TableNull;
	CS.__c[NEQ ][TableChar][TableString] = TableNull;
	CS.__c[GT  ][TableChar][TableString] = TableNull;
	CS.__c[LT  ][TableChar][TableString] = TableNull;
	CS.__c[NEG ][TableChar][TableString] = TableNull;
	CS.__c[SUM ][TableChar][TableString] = TableString;
	CS.__c[RES ][TableChar][TableString] = TableNull;
	CS.__c[MULT][TableChar][TableString] = TableNull;
	CS.__c[DIV ][TableChar][TableString] = TableNull;
	CS.__c[ROOT][TableChar][TableString] = TableNull;
	CS.__c[POW ][TableChar][TableString] = TableNull;
	CS.__c[AND ][TableChar][TableString] = TableBool;
	CS.__c[OR  ][TableChar][TableString] = TableBool;
	//Char Bool
	CS.__c[EEQ ][TableChar][TableBool] = TableBool;
	CS.__c[GT  ][TableChar][TableBool] = TableBool;
	CS.__c[LTE ][TableChar][TableBool] = TableBool;
	CS.__c[NEQ ][TableChar][TableBool] = TableBool;
	CS.__c[GT  ][TableChar][TableBool] = TableBool;
	CS.__c[LT  ][TableChar][TableBool] = TableBool;
	CS.__c[NEG ][TableChar][TableBool] = TableNull;
	CS.__c[SUM ][TableChar][TableBool] = TableInt;
	CS.__c[RES ][TableChar][TableBool] = TableInt;
	CS.__c[MULT][TableChar][TableBool] = TableInt;
	CS.__c[DIV ][TableChar][TableBool] = TableInt;
	CS.__c[ROOT][TableChar][TableBool] = TableInt;
	CS.__c[POW ][TableChar][TableBool] = TableInt;
	CS.__c[AND ][TableChar][TableBool] = TableBool;
	CS.__c[OR  ][TableChar][TableBool] = TableBool;
	/* --------------------- STRING ___ --------------------- */
	//String Int
	CS.__c[EEQ ][TableString][TableInt] = TableNull;
	CS.__c[GT  ][TableString][TableInt] = TableNull;
	CS.__c[LTE ][TableString][TableInt] = TableNull;
	CS.__c[NEQ ][TableString][TableInt] = TableNull;
	CS.__c[GT  ][TableString][TableInt] = TableNull;
	CS.__c[LT  ][TableString][TableInt] = TableNull;
	CS.__c[NEG ][TableString][TableInt] = TableNull;
	CS.__c[SUM ][TableString][TableInt] = TableNull;
	CS.__c[RES ][TableString][TableInt] = TableNull;
	CS.__c[MULT][TableString][TableInt] = TableNull;
	CS.__c[DIV ][TableString][TableInt] = TableNull;
	CS.__c[ROOT][TableString][TableInt] = TableNull;
	CS.__c[POW ][TableString][TableInt] = TableNull;
	CS.__c[AND ][TableString][TableInt] = TableBool;
	CS.__c[OR  ][TableString][TableInt] = TableBool;
	//String Float	//String Double
	CS.__c[EEQ ][TableString][TableDouble] = TableNull;
	CS.__c[GT  ][TableString][TableDouble] = TableNull;
	CS.__c[LTE ][TableString][TableDouble] = TableNull;
	CS.__c[NEQ ][TableString][TableDouble] = TableNull;
	CS.__c[GT  ][TableString][TableDouble] = TableNull;
	CS.__c[LT  ][TableString][TableDouble] = TableNull;
	CS.__c[NEG ][TableString][TableDouble] = TableNull;
	CS.__c[SUM ][TableString][TableDouble] = TableNull;
	CS.__c[RES ][TableString][TableDouble] = TableNull;
	CS.__c[MULT][TableString][TableDouble] = TableNull;
	CS.__c[DIV ][TableString][TableDouble] = TableNull;
	CS.__c[ROOT][TableString][TableDouble] = TableNull;
	CS.__c[POW ][TableString][TableDouble] = TableNull;
	CS.__c[AND ][TableString][TableDouble] = TableBool;
	CS.__c[OR  ][TableString][TableDouble] = TableBool;
	//String Char
	CS.__c[EEQ ][TableString][TableChar] = TableBool;
	CS.__c[GT  ][TableString][TableChar] = TableNull;
	CS.__c[LTE ][TableString][TableChar] = TableNull;
	CS.__c[NEQ ][TableString][TableChar] = TableBool;
	CS.__c[GT  ][TableString][TableChar] = TableNull;
	CS.__c[LT  ][TableString][TableChar] = TableNull;
	CS.__c[NEG ][TableString][TableChar] = TableNull;
	CS.__c[SUM ][TableString][TableChar] = TableString;
	CS.__c[RES ][TableString][TableChar] = TableNull;
	CS.__c[MULT][TableString][TableChar] = TableNull;
	CS.__c[DIV ][TableString][TableChar] = TableNull;
	CS.__c[ROOT][TableString][TableChar] = TableNull;
	CS.__c[POW ][TableString][TableChar] = TableNull;
	CS.__c[AND ][TableString][TableChar] = TableBool;
	CS.__c[OR  ][TableString][TableChar] = TableBool;
	//String String
	CS.__c[EEQ ][TableString][TableString] = TableBool;
	CS.__c[GT  ][TableString][TableString] = TableNull;
	CS.__c[LTE ][TableString][TableString] = TableNull;
	CS.__c[NEQ ][TableString][TableString] = TableBool;
	CS.__c[GT  ][TableString][TableString] = TableNull;
	CS.__c[LT  ][TableString][TableString] = TableNull;
	CS.__c[NEG ][TableString][TableString] = TableBool;
	CS.__c[SUM ][TableString][TableString] = TableString;
	CS.__c[RES ][TableString][TableString] = TableNull;
	CS.__c[MULT][TableString][TableString] = TableNull;
	CS.__c[DIV ][TableString][TableString] = TableNull;
	CS.__c[ROOT][TableString][TableString] = TableNull;
	CS.__c[POW ][TableString][TableString] = TableNull;
	CS.__c[AND ][TableString][TableString] = TableBool;
	CS.__c[OR  ][TableString][TableString] = TableBool;
	/* --------------------- BOOL ___ --------------------- */
	//Bool Int
	CS.__c[EEQ ][TableBool][TableInt] = TableBool;
	CS.__c[GT  ][TableBool][TableInt] = TableBool;
	CS.__c[LTE ][TableBool][TableInt] = TableBool;
	CS.__c[NEQ ][TableBool][TableInt] = TableBool;
	CS.__c[GT  ][TableBool][TableInt] = TableBool;
	CS.__c[LT  ][TableBool][TableInt] = TableBool;
	CS.__c[NEG ][TableBool][TableInt] = TableNull;
	CS.__c[SUM ][TableBool][TableInt] = TableInt;
	CS.__c[RES ][TableBool][TableInt] = TableInt;
	CS.__c[MULT][TableBool][TableInt] = TableInt;
	CS.__c[DIV ][TableBool][TableInt] = TableInt;
	CS.__c[ROOT][TableBool][TableInt] = TableInt;
	CS.__c[POW ][TableBool][TableInt] = TableInt;
	CS.__c[AND ][TableBool][TableInt] = TableBool;
	CS.__c[OR  ][TableBool][TableInt] = TableBool;
	//Bool Float	//Bool Double
	CS.__c[EEQ ][TableBool][TableDouble] = TableBool;
	CS.__c[GT  ][TableBool][TableDouble] = TableBool;
	CS.__c[LTE ][TableBool][TableDouble] = TableBool;
	CS.__c[NEQ ][TableBool][TableDouble] = TableBool;
	CS.__c[GT  ][TableBool][TableDouble] = TableBool;
	CS.__c[LT  ][TableBool][TableDouble] = TableBool;
	CS.__c[NEG ][TableBool][TableDouble] = TableNull;
	CS.__c[SUM ][TableBool][TableDouble] = TableDouble;
	CS.__c[RES ][TableBool][TableDouble] = TableDouble;
	CS.__c[MULT][TableBool][TableDouble] = TableDouble;
	CS.__c[DIV ][TableBool][TableDouble] = TableDouble;
	CS.__c[ROOT][TableBool][TableDouble] = TableDouble;
	CS.__c[POW ][TableBool][TableDouble] = TableDouble;
	CS.__c[AND ][TableBool][TableDouble] = TableBool;
	CS.__c[OR  ][TableBool][TableDouble] = TableBool;
	//Bool Char
	CS.__c[EEQ ][TableBool][TableChar] = TableBool;
	CS.__c[GT  ][TableBool][TableChar] = TableBool;
	CS.__c[LTE ][TableBool][TableChar] = TableBool;
	CS.__c[NEQ ][TableBool][TableChar] = TableBool;
	CS.__c[GT  ][TableBool][TableChar] = TableBool;
	CS.__c[LT  ][TableBool][TableChar] = TableBool;
	CS.__c[NEG ][TableBool][TableChar] = TableNull;
	CS.__c[SUM ][TableBool][TableChar] = TableInt;
	CS.__c[RES ][TableBool][TableChar] = TableInt;
	CS.__c[MULT][TableBool][TableChar] = TableInt;
	CS.__c[DIV ][TableBool][TableChar] = TableInt;
	CS.__c[ROOT][TableBool][TableChar] = TableInt;
	CS.__c[POW ][TableBool][TableChar] = TableInt;
	CS.__c[AND ][TableBool][TableChar] = TableBool;
	CS.__c[OR  ][TableBool][TableChar] = TableBool;
	//Bool Bool
	CS.__c[EEQ ][TableBool][TableBool] = TableBool;
	CS.__c[GT  ][TableBool][TableBool] = TableBool;
	CS.__c[LTE ][TableBool][TableBool] = TableBool;
	CS.__c[NEQ ][TableBool][TableBool] = TableBool;
	CS.__c[GT  ][TableBool][TableBool] = TableBool;
	CS.__c[LT  ][TableBool][TableBool] = TableBool;
	CS.__c[NEG ][TableBool][TableBool] = TableBool;
	CS.__c[SUM ][TableBool][TableBool] = TableInt;
	CS.__c[RES ][TableBool][TableBool] = TableInt;
	CS.__c[MULT][TableBool][TableBool] = TableInt;
	CS.__c[DIV ][TableBool][TableBool] = TableInt;
	CS.__c[ROOT][TableBool][TableBool] = TableNull;
	CS.__c[POW ][TableBool][TableBool] = TableNull;
	CS.__c[AND ][TableBool][TableBool] = TableBool;
	CS.__c[OR  ][TableBool][TableBool] = TableBool;
	
    CS.getReturnType = &__getReturnType;
	return CS;
}
