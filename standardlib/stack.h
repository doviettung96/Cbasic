#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct SNode {
	void *element;
	struct SNode *link;
} SNode;

typedef struct stack_type$ {
	SNode *top;
} stack_type;

//initialize a stack
stack_type *iniStack(stack_type *stack) {
	stack = (stack_type *)malloc(sizeof(stack_type));
	stack->top = NULL;
	return stack;
}

int Sempty(stack_type *stack) {
	return stack->top == NULL;
}

SNode *top(stack_type *stack) {
	return stack->top;
}

SNode *makeSNode(void *val) {
	SNode *p;
	p = (SNode *)malloc(sizeof(SNode));
	p->element = val;
	p->link = NULL;
	return p;
}

void push(void *val, stack_type *stack) {
	int i;
	SNode *p;
	p = makeSNode(val);
	p->link = stack->top;
	stack->top = p;
}

void *pop(stack_type *stack) {
	SNode *p;
	void *val;
	if (Sempty(stack))
	{
		printf("Stack overflow\n");
		exit(0);
	}
	val = stack->top->element;
	p = stack->top;
	stack->top = stack->top->link;
	free(p->element);
	free(p);
	return val;
}

void freeStack(stack_type *stack) {
	while (!Sempty(stack))
		pop(stack);
	free(stack);
}
