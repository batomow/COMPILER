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
        TypeNull,
        TypeBool
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
Var NewVarNull(); //NullVar()
Var* NewVarArrayI(int*, int);  //needs destroying
Var* NewVarArrayF(float*, int);  //needs destroying 
Var* NewVarArrayD(double*, int);  //needs destroying 
Var* NewVarArrayS(char**, int);  //needs destroying 
Var* NewVarArrayC(char*, int);  //needs destroying 
char* VarToString(Var); //free return value

//element
typedef struct Vector{
    Var a;
    Var b;
} Vector; 
Vector NewVector(Var, Var); 

typedef struct Element{    
    Vector position;  
    Vector size; 
    int color; 
} Element; 
Element NewElement(Vector, Vector, int); 

//------------- Stack Stuff ---------------------//
typedef struct Stack Stack;
typedef struct Stack{
        DataType __type;
        int size; //number of elements inserted
        int __total_size;//total size
        Var* __stack; //the actual structure
        int (*isEmpty)(Stack*);
        void (*print)(Stack*);
} Stack;
void push(Stack*, Var); 
void pop(Stack*); 
Var peek(Stack*); 
    //-----array functions-----///
    void insert(Stack*, Var, int); 
    Var extract(Stack*, int);  
    Var accessElement(Stack*, int); 
Stack NewStack(DataType, int);
Stack NewStackFromArray(Var* , int); 
void DestroyStack(Stack* ); 

//------- queue stufff ----------------//
typedef struct Queue Queue; 
typedef struct Queue{
	Stack __front; 
	Stack __back; 
	int size; 
	void (*print)(Queue*); 
	int (*isEmpty)(Queue*); 
} Queue;  
void popBack(Queue* ); 
void popFront(Queue* ); 
void pushBack(Queue* , Var); 
void pushFront(Queue* , Var); 
Var peekFront(Queue* ); 
Var peekBack(Queue* ); 
Queue NewQueue(DataType, int); 
void DestroyQueue(Queue* ); 

//---------------------------------------dictionary stuff -------------//
typedef struct KeyValuePair kvp; 
typedef struct KeyValuePair{
    char* key; 
    Var value; 
    kvp* next; 
    int isSet; 
}kvp; 

typedef struct Dictionary Dictionary;
typedef struct Dictionary{
	kvp* __dict; 
	int size; 
	int (*isEmpty)(Dictionary*); 
	void (*print)(Dictionary*); 
        int (*add)(Dictionary*, char*, Var);//true if successfull
        void (*remove)(Dictionary*, char*);
        Var (*lookup)(Dictionary*, char*); //return NewVarS("Not found") if unsuccessful
} Dictionary; 
char** getKeys(Dictionary*, int*); //dictionary and size, free return value
Var* getValues(Dictionary*, int*); //dictionary and size, free return value

Dictionary NewDictionary(int ); 
void DestroyDictionary(Dictionary*);

//---------------------------- var table stuff ----------------------///
typedef enum TableType{
    TableInt, 
    TableFloat, 
    TableChar, 
    TableString, 
    TableElement, 
    TableVector, 
    TableNull, 
    TableDouble,
} TableType; 
//you have to manualy free the DIM if you dont add it to a vartable
//you cant modify the DIM once assigned
typedef struct DIM DIM; 
typedef struct DIM{
    int isSet; 
    int limsup; 
    int step;  
    char* (*toString)(DIM*); //needs freeing
    int size; //the total size of the multiple dimensions
    DIM* next; 
} DIM; 
DIM NewDIM(); 
void SetDIM(DIM*, int, int); 
void AddDIM(DIM*, DIM*);  //modifies the first dim linking -> a copy of the second DIM
void DestroyDIM(DIM* dim); //null protected, assumes first dim is pointer, recomend to call with next as param

typedef struct VarTableEntry VTE; 
typedef struct VarTableEntry{
    int isSet; 
    char* id; 
    TableType type;
    int dir; 
    DIM* dim; 
    VTE* next; 
} VTE; 
VTE NewVTE(); //initialized with dim = null and next = null
void SetVTE(VTE*, char*, TableType, int, DIM*); //automatically calloc next = NewDIM(); 
void DestroyVTE(VTE*);//destroys all  

typedef struct VarTable VarTable; 
typedef struct VarTable{
    int size; 
    int __current_size; 
    VTE* __dict; 
    void (*print)(VarTable*); 
    int (*isEmpty)(VarTable*); 
    int (*add)(VarTable*, char*, TableType, int, DIM*); 
    void (*remove)(VarTable*, char*); 
    VTE* (*lookup)(VarTable*, char*); 
}VarTable;
VarTable NewVarTable(); 
void DestroyVarTable(VarTable*); 

// ------------------ func table stuff -----------//

typedef struct FuncTableEntry FTE; 
typedef struct FuncTableEntry {
    int isSet; 
    char* moduleid; 
    TableType returntype;  
    int quadlinenum; 
    VarTable* params; 
    VarTable* vars;  
    int bytesize; 
    FTE* next;//llinked list;   
}FTE; 
FTE NewFTE(); 
void SetFTE(FTE*, char*, TableType, int); 
void DestroyFTE(FTE*); 

typedef struct FuncTable FuncTable; 
typedef struct FuncTable{
    FTE* __dict;     
    int size; 
    int __current_size; 
    int (*isEmpty)(FuncTable*); 
    void (*print)(FuncTable*); 
    int (*add)(FuncTable*, char*, TableType, int); //id, return type, quad line
    int (*addVar)(FuncTable*, char*, char*, TableType, int, DIM*); //set dim later 
    int (*addParam)(FuncTable*, char*, char*, TableType, int, DIM*); //set dim later
    int (*updateSize)(FuncTable*, char*); 
    FTE* (*lookup)(FuncTable*, char*);  
    VTE* (*lookupVar)(FuncTable*, char*, char*); 
    VTE* (*lookupParam)(FuncTable*, char*, char*); 
} FuncTable; 
FuncTable NewFuncTable(int); 
void DestroyFuncTable(FuncTable*); 

typedef enum OP{
    SUM, //0
    RES, //1
    ROOT, //2
    DIV, //3
    MULT, //4
    POW, //5
    GOTO, //6
    GOTOF, //7
    GOTOV,//8
    GOSUB, //9
    ASSIGN, //10
    PRINT, //11
    READ, //12
    LT, //13
    GT, //14
    LTE, //15
    GTE, //16
    AND, //17
    OR, //18
    EEQ, //19
    NEQ,//20
    ENDPROC,//21
    ENDPROG, //22
    NEG //23
} OP; 

typedef struct Operandum OPDUM; 
typedef struct Operandum {
    int isPointer; 
    char* id; 
    int virad; 
    int dereference;  
    void (*toPointer)(OPDUM*, int);
} OPDUM; 
OPDUM NewOPDUM(char*, int, int); 

typedef struct QUADRUPLE {
    OP op; 
    OPDUM opdum1;
    OPDUM opdum2;
    OPDUM result;
} QUAD; 
QUAD NewQUAD(OP, OPDUM, OPDUM, OPDUM); 
char* QUADToStringHuman(QUAD); //need freeing
char* QUADToStringMachine(QUAD); //need freeing

#endif
