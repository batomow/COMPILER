#ifndef JEDI_H
#define JEDI_H
#include <setjmp.h> 
#define TRY do{ jmp_buf ex_buf__; if ( !setjmp(ex_buf__)) {
#define CATCH } else { 
#define ETRY }} while (0)
#define THROW longjmp(ex_buf__, 1)


typedef enum DataType{
        TypeInt,
        TypeFloat,
        TypeChar,
        TypeString,
        TypeDouble, 
        TypeNull
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
Var NullVar(); 
Var* NewVarArrayI(int*, int); 
Var* NewVarArrayF(float*, int); 
Var* NewVarArrayD(double*, int); 
Var* NewVarArrayS(char**, int); 
Var* NewVarArrayC(char*, int); 

char* VarToString(Var); //free return value

//------------- Stack Stuff ---------------------//
typedef struct Stack Stack;
typedef struct Stack{
        DataType __type;
        int size; //number of elements inserted
        int __total_size;//total size
        Var* __stack; //the actual structure
        int (*is_empty)(Stack*);
        void (*print)(Stack*);
} Stack;
void push_raw(Stack*, void*); 
void push(Stack*, Var); 
void pop(Stack*); 
Var peek(Stack*); 
void insert_raw(Stack*, void*, int); 
void insert(Stack*, Var, int); 
Var extract(Stack*, int);  

//------- queue stufff ----------------//
typedef struct Queue Queue; 
typedef struct Queue{
	Stack __front; 
	Stack __back; 
	int size; 
	void (*print)(Queue*); 
	int (*is_empty)(Queue*); 
} Queue;  
void pop_back(Queue* ); 
void pop_front(Queue* ); 
void push_back(Queue* , Var); 
void push_back_raw(Queue*, void*); 
void push_front(Queue* , Var); 
void push_front_raw(Queue*, void*); 
Var peek_front(Queue* ); 
Var peek_back(Queue* ); 

Stack NewStack(DataType, int);
Stack NewStackFromArrayRaw(DataType, void*, int); 
Stack NewStackFromArray(Var* , int); 
Queue NewQueue(DataType, int); 

void DestroyStack(Stack* ); 
void DestroyQueue(Queue* ); 

//---------------------------------------dictionary stuff -------------//
typedef struct KeyValuePair kvp; 
typedef struct KeyValuePair{
    char* key; 
    Var value; 
    kvp* next; 
    int isSet; 
}kvp; 
kvp NewKeyValuePair(); 
void setkvp(kvp*, char*, Var); 

typedef struct Dictionary Dictionary;
typedef struct Dictionary{
	kvp* __dict; 
	int size; 
	int (*is_empty)(Dictionary*); 
	void (*print)(Dictionary*); 
} Dictionary; 

int add(Dictionary*, char*, Var); //true if sucessfull
int add_pair(Dictionary*, kvp); //true if sucessfull
int remove_entry(Dictionary*, char*); //true if successfull 
char** get_keys(Dictionary*, int*); //dictionary and size, free return value
Var* get_values(Dictionary*, int*); //dictionary and size, free return value
Var lookup(Dictionary*, char*); //return NewVarS("Not found") if unsuccessful

Dictionary NewDictionary(int ); 
void DestroyDictionary(Dictionary*); 

typedef struct DIM DIM; 
typedef struct DIM{
    int isSet; 
    int liminf; 
    int limsup; 
    int step;  
    DIM* next; 
} DIM; 
DIM NewDIM(); 
void SetDIM(DIM*, int, int, int); 
void DestroyDIM(DIM* dim); 

typedef struct VarTableEntry{
    int isSet; 
    DataType type;
    Var data; 
    int dir; 
    DIM* dim; 
} VarTableEntry; 
VarTableEntry NewVarTableEntry(); 
void SetVarTableEntry(VarTableEntry*, Var); 
void PresetVarTableEntry(VarTableEntry*, DataType, int, DIM); 
void DestroyVarTableEntry(VarTableEntry*); 

typedef struct VarTable VarTable; 
typedef struct VarTable{
    int size; 
    VarTableEntry __dict; 
    void (*print)(VarTable*); 
    int (*isEmpty)(VarTable*); 
}VarTable;
VarTable NewVarTable(); 
int presetVar(VarTable*, char*, DataType, int dir, DIM*); 
int setVar(VarTable*, char*, Var); //set the value 
VarTableEntry tableLookup(VarTable*, char*); 
int removeVar(VarTable*, char*); 

#endif
