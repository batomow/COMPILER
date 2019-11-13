#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
#include "jedi.h"

void __reverse(Stack* src, Stack* target){
	Var aux; 
	while(!src->is_empty(src)){
		aux = peek(src); 
		pop(src); 
		push(target, aux); 
	}
}

void pop_back(Queue* queue){
	Stack *front = &(queue->__front), *back = &(queue->__back); 
	if (back->is_empty(back) && !front->is_empty(front)){
		__reverse(front, back); 
		pop(back); 
	}
}
void pop_front(Queue* queue){
	Stack *front = &(queue->__front), *back = &(queue->__back); 
	if (!back->is_empty(back) && front->is_empty(front)){
		__reverse(back, front); 
		pop(front); 
	}
}
void push_back(Queue* queue, Var item){
	Stack* back = &(queue->__back);
	push(back, item); 
} 	
void push_back_raw(Queue* queue, void* item){
	Stack* back = &(queue->__back); 
	push_raw(back, item); 
}
void push_front(Queue* queue, Var item){
	Stack* front = &(queue->__front); 
	push(front, item); 
}
void push_front_raw(Queue* queue, void* item){ 
	Stack* front = &(queue->__front); 
	push_raw(front, item); 
}
Var peek_front(Queue* queue){
	Stack* front = &(queue->__front); 
	if(front->is_empty(front)){
		Stack* back = &(queue->__back); 
		__reverse(back, front); 
	}
	Var result = peek(front); 
	return result; 
}	
Var peek_back(Queue* queue){
	Stack* back = &(queue->__back); 
	if(back->is_empty(back)){
		Stack* front = &(queue->__front);
		__reverse(front, back); 
	}
	Var result = peek(back);
	return result; 
}
void print(Queue* queue){
	Stack *front = &(queue->__front), *back = &(queue->__back); 
	printf("Queue -"); 
        char* aux; 
	for(int n = back->size-1; n>=0; n--){
		Var item = back->__stack[n]; 	
                aux = VarToString(item); 
                printf("[%s]", aux); 
	}
	for(int n = 0; n<front->size; n++){
		Var item = front->__stack[n]; 	
                aux = VarToString(item); 
                printf("[%s]", aux); 
	}
        free(aux); 
	printf("->\n"); 
}

void __debug_print(Queue* queue){
	Stack *front = &(queue->__front), *back = &(queue->__back); 
	printf("Queue Back -"); 
        char* aux; 
	for(int n = back->size-1; n>=0; n--){
		Var item = back->__stack[n]; 	
                aux = VarToString(item); 
                printf("[%s]", aux); 
	}printf("->\nQueue Front -"); 
	for(int n = 0; n<front->size; n++){
		Var item = front->__stack[n]; 	
                aux = VarToString(item); 
                printf("[%s]", aux); 
	}
        free(aux); 
	printf("->\n"); 	
}

int queue_is_empty(Queue* queue){
	Stack *front = &(queue->__front), *back = &(queue->__back); 
	return (front->is_empty(front) && back->is_empty(back));
}

Queue NewQueue(DataType type, int size){ 
	int back_size = size/2; 
	int front_size = (size%2==0) ? (size/2) : (size/2 + 1); 
	Queue new_queue; 
	new_queue.__front = NewStack(type, front_size); 
	new_queue.__back = NewStack(type, back_size); 
	new_queue.print = &print; 
	new_queue.is_empty = &queue_is_empty;
	return new_queue; 
}

void DestroyQueue(Queue* queue){ 
	DestroyStack(&(queue->__back)); 
	DestroyStack(&(queue->__front)); 
}
