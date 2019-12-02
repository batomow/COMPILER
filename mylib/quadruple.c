#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include "jedi.h"

void __set_operandum_as_pointer(OPDUM* operandum, int otherVirtualAd){
    operandum->isPointer = 1; 
    operandum->dereference = otherVirtualAd; 
}

OPDUM NewOPDUM(char* id, int virtualAd, TableType type){
    OPDUM r; 
    r.isPointer = 0; 
    int idsize = strlen(id); 
    r.id = calloc(idsize+1, sizeof(char));  
    strcpy(r.id, id); 
    r.type = type; 
    r.virad = virtualAd; 
    r.dereference = -1;  
    r.toPointer = &__set_operandum_as_pointer;
    return r; 
}

void DestroyOPDUM(OPDUM* dum){
    if(dum)
        if(dum->id){
            free(dum->id);
        }
}


void DestroyQUAD(QUAD* q){
    if(q->isSet){
        DestroyQUAD(q->next); 
        DestroyOPDUM(&(q->opdum1)); 
        DestroyOPDUM(&(q->opdum2)); 
        free(q->next); 
    }
}

QUAD NewQUAD(){
    QUAD q; 
    q.isSet = 0; 
    q.next = NULL; 
    return q; 
}

void SetQUAD(QUAD* q, OP op, OPDUM opdum1, OPDUM opdum2, OPDUM res){
    q->isSet = 1; 
    q->op = op; 
    q->opdum1 = opdum1; 
    q->opdum2 = opdum2; 
    q->result = res; 
    q->next = calloc(1, sizeof(QUAD)); 
    *(q->next) = NewQUAD(); 
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
        case SCAN: strcat(string, "READ, "); break; 
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
        case NEG: strcat(string, "NEG, "); break; 
        case FORCHECK: strcat(string, "FORCHECK, "); break; 
        case ERA: strcat(string, "ERA, ");break;  
        case PARAM: strcat(string, "PARAM, "); break; 
        case RETURN: strcat(string, "RETURN, "); break; 
        case SCANALL: strcat(string, "SCANALL, "); break; 
        case REGISTER: strcat(string, "REGISTER, "); break; 
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
    char* string = calloc(8000, sizeof(char)); 
    if(quadruple.result.isPointer){
        sprintf(string, "{\"opcode\": %d,\t\"left\": %d,\t\"right\": %d,\t\"result\": %d}", quadruple.op, quadruple.opdum1.virad, quadruple.opdum2.virad, quadruple.result.dereference); 
    }else{
        sprintf(string, "{\"opcode\": %d,\t\"left\": %d,\t\"right\": %d,\t\"result\": %d}", quadruple.op, quadruple.opdum1.virad, quadruple.opdum2.virad, quadruple.result.virad); 
    }
    return string; 
}
