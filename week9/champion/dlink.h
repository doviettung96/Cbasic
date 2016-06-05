#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DNode DNode ;
typedef struct DNode {
	void * element;
	DNode *prev;
	DNode *next;
} DNode;

typedef struct dlist$ {
	DNode *root;
	DNode *cur;
	DNode *last;
} dlist;

DNode *makeDNode(void * val) {
	DNode *p;
	p = (DNode *)malloc(sizeof(DNode));
	p->next = NULL;
	p->prev = NULL;
	p->element = val;
	return p;
}

dlist *iniList() {
	dlist *list;
	list = (dlist *)malloc(sizeof(dlist));
	if (list == NULL) {
		fprintf(stderr, "ERROR : Allocated memory failed !!\n");
		exit(1);
	}
	list->root = NULL;
	list->cur = NULL;
	list->last = NULL;
	return list;
}

//find the length of a list
int listLength(dlist *list) {
	DNode *p;
	int i = 0;
	p = list->root;
	while (p != NULL) {
		i++;
		p = p->next;
	}
	return i;
}


void insertEnd(void * val, dlist *list) {
	DNode *p;
	p = makeDNode(val);
	if (list->root == NULL) {
		list->root = p;
		list->cur = p;
		list->last = p;
	}
	else
	{
		(list->last)->next = p;
		p->prev = list->last;
		list->last = p;
		list->cur = p;
	}
}

// //find a DNode with a value
// DNode *findDNode(void * val, dlist *list) {
// 	DNode *p = list->root;
// 	if (list->root == NULL)
// 		return NULL;
// 	while (p != NULL) {
// 		if (strcmp(p->element.name, val.name) == 0 && strcmp(p->element.tel, val.tel) == 0 && strcmp(p->element.email, val.email) == 0)
// 		{
// 			list->cur = p;
// 			return p;
// 		}
// 		p = p->next;
// 	}
// 	printf("Not found!!\n");
// 	return NULL;
// }

//locate n-th DNode in a list
DNode *locateDNode(int n, dlist *list) {
	int i = 0;
	DNode *p = list->root;
	if (n > listLength(list))
	{
		printf("Not found!!\n");
		return NULL;
	}
	if (list->root == NULL)
		return NULL;
	for (i = 0; i < n; ++i) {
		list->cur = p;
		p = p->next;
	}
	return list->cur;
}

void delDNode(DNode *p, dlist *list) {
	if (list->root == NULL)
		return;
	if (p == NULL)
		return;
	if (p == list->root) {
		list->root = p->next;
		 //careful , maybe core dump
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
		list->cur = p->prev;
		free(p);
	}
}

// insert DNode before DNode p
void insertBefore(DNode *p, void * val, dlist *list) {
	DNode *q = makeDNode(val);
	list->cur = q;
	if (list->root == NULL) {
		printf("DNode haven't create !!");
		return;
	} else if (list->root == p) {
		list->root = q;
		q->next = p;
	} else {
		q->next = p;
		q->prev = p->prev;
		p->prev->next = q;
	}
}

// insert DNode after DNode p
void insertAfter(DNode *p, void * val, dlist *list) {
	DNode *q = makeDNode(val);
	list->cur = q;
	if (list->root == NULL) {
		printf("DNode haven't create !!");
		return;
	} else {
		if (list->last == p) {
			insertEnd(val, list);
			free(q->element);
			free(q);
		}  else  {
			q->next = p->next;
			q->prev = p;
			p->next = q;
		}
	}
}


void reverseDList(dlist *list) {
	DNode *z, *p;
	list->last = list->root;


	p = list->root;

	list->root = list->root->next;

	z = list->root;
	list->root = list->root->next;
	z->next = p;


	while (list->root != NULL) {
		p = z;
		z = list->root;
		list->root = list->root->next;
		z->next = p ;
	}

	list->root = z;
	list->last->next = NULL;
	list->cur = list->root;
}

void freeDList(dlist * list) {
	if (list->root == NULL)
		return;
	DNode *to_free = list->root;
	while (to_free != NULL) {
		list->root = (list->root)->next;
		free(to_free->element);
		free(to_free); // free DNode
		to_free = list->root;
	}
}

