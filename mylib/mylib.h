#ifndef MYLIB_H
#define MYLIB_H

typedef enum DataType{
        TypeInt,
        TypeFloat,
        TypeChar,
        TypeString,
        TypeDouble
} DataType;

typedef struct Var{
        union{
                int iVal;
                float fVal;
                double dVal;
                char* sVal;
                char cVal;
        } data;

        DataType type;

} Var;

Var NewVarI(int);
Var NewVarF(float);
Var NewVarD(double);
Var NewVarS(char*);
Var NewVarC(char);

typedef struct Stack Stack;

typedef struct Stack{
        DataType __type;
        int size; //number of elements inserted
        int __total_size;//total size
        Var* __stack; //the actual structure

        int (*is_empty)(Stack);
        void (*push_raw)(Stack*, void*);
        void (*push) (Stack*, Var);
        void (*pop)(Stack*);
        Var (*peek)(Stack*);
        void (*print)(Stack*);
        void (*insert)(Stack*, Var, int);
        void (*insert_raw)(Stack*, void*, int);
} Stack;

Stack NewStack(DataType, int);
void DestroyStack(Stack* ); 
#endif
