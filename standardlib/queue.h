#include "dlink.h"

#define MAX 100

typedef struct {
	dlist *list;
	element_type position;
} queue_type;

int Qempty(queue_type *q) {
	return q->position == 0;
}

queue_type *iniQueue(queue_type *q) {
	q = (queue_type *)malloc(sizeof(queue_type));
	q->list = iniList(q->list);
	q->position = 0;
	return q;
}

void enQueue(element_type val, queue_type *q) {
	insertEnd(val, q->list);
	q->position++;
}

element_type deQueue(queue_type *q) {
	element_type val;
	Node *p;
	if (!Qempty(q))
	{
		val = q->list->root->element;
		delNode(q->list->root, q->list);
		q->position--;	
		return val;
	}
	else
		printf("Empty queue!\n");
}

void display(Node *p) {
	printf("%c ", p->element);
}

void traverse(queue_type *q) {
	Node *p;
	p = q->list->root;
	while ( p != NULL ) {
		display(p);
		p = p->next;
	}
}

void removeQueue(queue_type *q)
{
	if(q == NULL)
		return;
	if(q->list == NULL)
		return;
	if (q != NULL)
		freeList(q->list);
	free(q);
}