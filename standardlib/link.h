#ifndef _LINK_H_
#define _LINK_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[30];
	float mark;
} element_type;

typedef struct Node Node;
typedef struct Node {
	element_type element;
	Node* next;
} Node;

//structure of a single list
typedef struct slist$ {
	Node *root;
	Node *cur;
	Node *last;
} slist;

//initialize a list
slist *iniList();


//make Node
Node *makeNode(element_type val);

//find the length of a list
int listLength(slist *list);
void insertEnd(element_type val, slist *list);
// Node *findNode(element_type val, slist *list);
//locate n-th Node in a list
Node *locateNode(int n, slist *list);
// find pre Node of Node p
Node *preNode(Node *p, slist *list);
// del Node p
void delNode(Node *p, slist *list);
// insert Node before Node p
void insertBefore(Node *p, element_type val, slist *list);
// insert Node after Node p
void insertAfter(Node *p, element_type val, slist *list);
//display a list
void traverse(slist *list, void (*function)(Node *));
//save the content of list to a data file
void savetoFile(slist *list, FILE *f, char fileName[]);
//split a list from startPosition to the end with the length of numSplit
void splitList(int startPosition, int numSplit, slist *list, slist *list2, slist *list3);
//add node to the end of list
void insertNode(Node *p, slist *list);
//display a list
void saveList(slist *list, slist *result, void (*function)(Node *, slist *));
// void checkList(slist *list, char fileName[20]);
void list_reverse(slist *list);
void freeList(slist *list);
#endif