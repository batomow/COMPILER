#include <stdio.h> 
#include <stdlib.h> 
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
