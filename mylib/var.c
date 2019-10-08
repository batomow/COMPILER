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
