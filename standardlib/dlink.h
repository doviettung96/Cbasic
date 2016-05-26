#ifndef _DLINK_H_
#define _DLINK_H_

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

DNode *makeDNode(void * val);
dlist *iniList();
//find the length of a list
int listLength(dlist *list);
void insertEnd(void * val, dlist *list);
// //find a DNode with a value
// DNode *findDNode(void * val, dlist *list);
//locate n-th DNode in a list
DNode *locateDNode(int n, dlist *list);
void delDNode(DNode *p, dlist *list);
// insert DNode before DNode p
void insertBefore(DNode *p, void * val, dlist *list);
// insert DNode after DNode p
void insertAfter(DNode *p, void * val, dlist *list);
//display a list
void traverse(dlist *list, void (*display)(DNode *));
//split a list from startPosition to the end with the length of numSplit
void splitDList(int startPosition, int numSplit, dlist *list, dlist *list2, dlist *list3);
// //save the content of list to a data file
void savetoFile(dlist *list, FILE *f, char fileName[]);
// void checkDList(dlist *list, char fileName[20]);
void reverseDList(dlist *list);
//count the identical phone number elements and extract them
dlist *countsameNum(dlist *list, dlist *list2);
void freeDList(dlist * list);
#endif

