#ifndef CUBE_H
#define CUBE_H

#include <stdlib.h>
#include <jedi.h> 

//typedef enum ReturnTypes{
//  NanType,    //0
//  IntType,    //1
//  FloatType,  //2
//  DoubleType, //3
//  CharType,   //4
//  StringType, //5
//  BoolType,   //6
//  HexType     //7
//} ReturnTypes; 

//typedef enum Operators{
//    Eq,     //0
//    Gteq,   //1
//    Lteq,   //2
//    Noteq,  //3
//    Gt,     //4
//    Lt,     //5
//    Negat,  //6
//    Plus,   //7
//    Minus,  //8
//    Astrk,  //9
//    Divid,  //10
//    Root,   //11
//    Power,  //12
//    And,    //13
//    Or      //14
//} Operators; 

typedef struct CuboSemantico CuboSemantico; 
typedef struct CuboSemantico {
  int __c[24][9][9];
  int (*getReturnType)(CuboSemantico*, OP, TableType, TableType);
} CuboSemantico;
CuboSemantico NewCubo();

#endif
