#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "jedi.h"

Var NewVarI(int val){
        Var r;
        r.data.iVal = val;
        r.type = TypeInt;
        return r;
}
Var NewVarF(float val){
        Var r;
        r.data.fVal = val;
        r.type = TypeFloat;
        return r;
}

Var NewVarD(double val){
        Var r;
        r.data.dVal = val;
        r.type = TypeDouble;
        return r;
}

Var NewVarS(char* val){
        Var r;
        r.data.sVal = val;
        r.type = TypeString;
        return r;
}
Var NewVarC(char val){
        Var r;
        r.data.cVal = val;
        r.type = TypeChar;
        return r;
}

Var* NewVarArrayI(int* array, int size){
	Var* r = (Var*)calloc(sizeof(Var), size);  
	for(int n = 0; n<size; n++){
		r[n] = NewVarI(array[n]); 
	}
	return r; 
}

Var* NewVarArrayF(float* array, int size){
	Var* r = (Var*)malloc(sizeof(Var)*size);  
	for(int n = 0; n<size; n++){
		r[n] = NewVarF(array[n]); 
	}
	return r; 
}

Var* NewVarArrayD(double* array, int size){
	Var* r = (Var*)malloc(sizeof(Var)*size);  
	for(int n = 0; n<size; n++){
		r[n] = NewVarD(array[n]); 
	}
	return r; 
}

Var* NewVarArrayS(char** array, int size){
	Var* r = (Var*)malloc(sizeof(Var)*size);  
	for(int n = 0; n<size; n++){
		r[n] = NewVarS(array[n]); 
	}
	return r; 
}
Var* NewVarArrayC(char* array, int size){
	Var* r = (Var*)malloc(sizeof(Var)*size);  
	for(int n = 0; n<size; n++){
		r[n] = NewVarC(array[n]); 
	}
	return r; 
}

char* VarToString(Var var){
    char* result = (char*)calloc(12, sizeof(char));
    switch(var.type){
        case TypeFloat: sprintf(result, "%0.4f", var.data.fVal); break;  
        case TypeDouble: sprintf(result, "%0.4f", var.data.dVal); break;  
        case TypeInt: sprintf(result, "%d", var.data.iVal); break;  
        case TypeChar: sprintf(result, "%c", var.data.cVal); break;  
        case TypeString: return var.data.sVal; 
    }
    return result; 
}

int EqualVars(Var a, Var b){
    switch(a.type){
        case TypeInt: return a.data.iVal == b.data.iVal; 
        case TypeFloat: return a.data.fVal == b.data.fVal; 
        case TypeDouble: return a.data.dVal == b.data.dVal; 
        case TypeChar: return a.data.cVal == b.data.cVal; 
        case TypeString: return strcmp(a.data.sVal, b.data.sVal);

    }
}
