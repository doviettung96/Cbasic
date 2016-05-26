#ifndef _STACK_H_
#define _STACK_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SNode {
	void *element;
	struct SNode *link;
} SNode;

typedef struct stack_type$ {
	SNode *top;
} stack_type;

//initialize a stack
stack_type *iniStack();
int Sempty(stack_type *stack);
SNode *top(stack_type *stack);
SNode *makeSNode(void *val);
void push(void *val, stack_type *stack);
void *pop(stack_type *stack);
void freeStack(stack_type *stack);

#endif
