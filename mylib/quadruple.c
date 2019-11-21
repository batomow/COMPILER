#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include "jedi.h"

void __set_operandum_as_pointer(OPDUM* operandum, int otherVirtualAd){
    operandum->isPointer = 1; 
    operandum->dereference = otherVirtualAd; 
}

OPDUM NewOPDUM(char* id, int virtualAd, int otherVirtualAd){
    OPDUM r; 
    r.isPointer = 0; 
    r.id = id; 
    r.virad = virtualAd; 
    r.dereference = otherVirtualAd; 
    r.toPointer = &__set_operandum_as_pointer;
    return r; 
}


QUAD NewQUAD(OP op, OPDUM opdum1, OPDUM opdum2, OPDUM res){
    QUAD q; 
    q.op = op; 
    q.opdum1 = opdum1; 
    q.opdum2 = opdum2; 
    q.result = res; 
    return q; 
}

char* QUADToStringHuman(QUAD quadruple){
    char* string = calloc(96, sizeof(char)); 
    strcat(string, "<"); 
    switch(quadruple.op){
        case SUM: strcat(string, "SUM, "); break; 
        case RES: strcat(string, "RES, "); break; 
        case ROOT: strcat(string, "ROOT, "); break; 
        case DIV: strcat(string, "DIV, "); break; 
        case MULT: strcat(string, "MULT, "); break; 
        case POW: strcat(string, "POW, "); break; 
        case GOTO: strcat(string, "GOTO, "); break; 
        case GOTOF: strcat(string, "GOTOF, "); break; 
        case GOTOV: strcat(string, "GOTOV, "); break; 
        case GOSUB: strcat(string, "GOSUB, "); break; 
        case ASSIGN: strcat(string, "ASSIGN, "); break; 
        case PRINT: strcat(string, "PRINT, "); break; 
        case READ: strcat(string, "READ, "); break; 
        case LT: strcat(string, "LT, "); break; 
        case GT: strcat(string, "GT, "); break; 
        case LTE: strcat(string, "LTE, "); break; 
        case GTE: strcat(string, "GTE, "); break; 
        case AND: strcat(string, "AND, "); break; 
        case OR: strcat(string, "OR, "); break; 
        case EEQ: strcat(string, "EEQ, "); break; 
        case NEQ: strcat(string, "NEQ, "); break; 
        case ENDPROC: strcat(string, "ENDPROC, "); break; 
        case ENDPROG: strcat(string, "ENDPROG, "); break; 
        default: strcat(string, "not defined"); break; 
    }
    strcat(string, quadruple.opdum1.id); 
    strcat(string, ", "); 
    strcat(string, quadruple.opdum2.id); 
    strcat(string, ", "); 
    strcat(string, quadruple.result.id); 
    strcat(string, ">\0"); 
    return string; 
}

char* QUADToStringMachine(QUAD quadruple){
    char* string = calloc(96, sizeof(char)); 
    sprintf(string, "<%d, %d, %d, %d>", quadruple.op, quadruple.opdum1.virad, quadruple.opdum2.virad, quadruple.result.virad); 
    return string; 
}
