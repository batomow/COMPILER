#ifndef JEDI_H
#define JEDI_H

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
Var* NewVarArrayI(int*, int); 
Var* NewVarArrayF(float*, int); 
Var* NewVarArrayD(double*, int); 
Var* NewVarArrayS(char**, int); 
Var* NewVarArrayC(char*, int); 
char* VarToString(Var); 
int EqualVars(Var, Var); 

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
typedef struct KeyValuePair KeyValuePair; 
typedef struct KeyValuePair{
    Var key; 
    Var value; 
    KeyValuePair *next; 
    KeyValuePair *prev; 
} KeyValuePair; 
KeyValuePair NewKeyValuePair(Var, Var); 

typedef struct Dictionary Dictionary;
typedef struct Dictionary{
	KeyValuePair* __dict; 
	int size; 
	int (*is_empty)(Dictionary*); 
	void (*print)(Dictionary*); 
} Dictionary; 

void add(Dictionary*, Var, Var); 
void add_pair(Dictionary*, KeyValuePair); 
int has_key(Dictionary*, Var); 
Var* get_keys(Dictionary*); 
Var* get_values(Dictionary*); 
Var lookup(Dictionary*, Var); 

Dictionary NewDictionary(int ); 
void DestroyDictionary(Dictionary*); 

#endif
