#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int id;
	int mem;
	int status; //1 is running, 0 is waitting
}element_type;

typedef struct Node {
	element_type element;
	struct Node *prev;
	struct Node *next;
} Node;

typedef struct dlist$ {
	Node *root;
	Node *last;
} dlist;

Node *makeDNode(element_type val) {
	Node *p;
	p = (Node *)malloc(sizeof(Node));
	p->next = NULL;
	p->prev = NULL;
	p->element = val;
	return p;
}

dlist *iniList(dlist *list) {
	list = (dlist *)malloc(sizeof(dlist));
	if (list == NULL) {
		fprintf(stderr, "ERROR : Allocated memory failed !!\n");
		exit(1);
	}
	list->root = NULL;
	list->last = NULL;
	return list;
}

//find the length of a list
int listLength(dlist *list) {
	Node *p;
	int i = 0;
	p = list->root;
	while (p != NULL) {
		i++;
		p = p->next;
	}
	return i;
}

void insertEnd(element_type val, dlist *list) {
	Node *p;
	p = makeDNode(val);
	if (list->root == NULL) {
		list->root = p;
		list->last = p;
	}
	else
	{
		(list->last)->next = p;
		p->prev = list->last;
		list->last = p;
	}
}



void delNode(Node *p, dlist *list) {
	if (list->root == NULL)
		return;
	if (p == NULL)
		return;
	if (p == list->root) {
		list->root = list->root->next;
		free(p);
	}
	else if (p == list->last) {
		list->last = p->prev;
		p->prev->next = NULL;
		free(p);
	}
	else
	{
		p->prev->next = p->next;
		p->next->prev = p->prev;
		free(p);
	}
}

// insert Node before Node p
void insertBefore(Node *p, element_type val, dlist *list) {
	Node *q = makeDNode(val);
	if (list->root == NULL) {
		printf("Node haven't create !!");
		return;
	} else if (list->root == p) {
		q->next = p;
	} else {
		q->next = p;
		q->prev = p->prev;
		p->prev->next = q;
	}
}

// insert Node after Node p
void insertAfter(Node *p, element_type val, dlist *list) {
	Node *q = makeDNode(val);
	if (list->root == NULL) {
		printf("Node haven't create !!");
		return;
	} else {
		if (list->last == p) {
			insertEnd(val, list);
			free(q);
		}  else  {
			q->next = p->next;
			q->prev = p;
			p->next = q;
		}
	}
}

void freeList(dlist * list) {
	if (list->root == NULL)
		return;
	Node *to_free = list->root;
	while (to_free != NULL) {
		list->root = (list->root)->next;
		free(to_free); // free node
		to_free = list->root;
	}
}

