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
        void (*print)(Stack*);
} Stack;
void push_raw(Stack*, void*); 
void push(Stack*, Var); 
void pop(Stack*); 
Var peek(Stack*); 
void insert_raw(Stack*, void*, int); 
void insert(Stack*, Var, int); 
Var extract(Stack*, int);  

typedef struct Queue Queue; 
typedef struct Queue{
	Stack __front; 
	Stack __back; 
	int size; 
	void (*print)(Queue*); 
	void (*is_empty)(Queue*); 
} Queue;  
Var pop_back(Queue* ); 
Var pop_front(Queue* ); 
void push_back(Queue* ); 
void push_front(Queue* ); 
Var front(Queue* ); 
Var back(Queue* ); 

Stack NewStack(DataType, int);
Queue NewQueue(DataType, int); 

void DestroyStack(Stack* ); 
void DestroyQueue(Queue* ); 

#endif
