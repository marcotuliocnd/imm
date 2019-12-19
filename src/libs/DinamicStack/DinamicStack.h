#define DINAMICSTACK_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#define SUCCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_OF_MEMORY -2
#define OUT_OF_RANGE -3
#define ELEM_NOT_FOUND -4

typedef struct stack Stack;

struct ponto
{
	int x;
	int y;
};

Stack *stack_create();
int stack_free(Stack *st);

int stack_push(Stack *st, struct ponto pt);
int stack_pop(Stack *st);
int stack_top(Stack *st, struct ponto *pt);
int stack_empty(Stack *st);
int stack_size(Stack *st);
