#include "stack.h"

//initialize a stack
stack_type *iniStack() {
	stack_type *stack;
	stack = (stack_type *)malloc(sizeof(stack_type));
	if (stack == NULL)
		return NULL;

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
	free(p);
	return val;
}

void freeStack(stack_type *stack) {
	if (stack == NULL)
		return;
	while (!Sempty(stack))
		free(pop(stack));
	free(stack);
}
