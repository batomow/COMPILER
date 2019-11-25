#ifndef CUBE_H
#define CUBE_H

#include <stdlib.h>
#include <jedi.h> 

typedef struct CuboSemantico CuboSemantico; 
typedef struct CuboSemantico {
  int __c[24][9][9];
  TableType (*getReturnType)(CuboSemantico*, OP, TableType, TableType);
} CuboSemantico;
CuboSemantico NewCubo();

#endif
