#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef phone_addr element_type;
typedef struct Node Node ;
typedef struct Node {
  element_type element;
  Node *prev;
  Node *next;
} Node;

typedef struct dlist$ {
  Node *root;
  Node *last;
} dlist;

Node *makeNode(element_type val) {
  Node *p;
  p = (Node *)malloc(sizeof(Node));
  p->next = NULL;
  p->prev = NULL;
  p->element = val;
  return p;
}

void iniList(dlist *dlist) {
  dlist->root = NULL;
  dlist->last = NULL;
}

//display a node
void display(Node *p) {
  printf("%-30s\t%-15s\t%-30s\n", p->element.name, p->element.tel, p->element.email);
}

void insertEnd(element_type val, dlist *list) {
  Node *p;
  p = makeNode(val);
  if (dlist->root == NULL) {
    dlist->root = p;
    dlist->last = p;
  }
  else
  {
    (dlist->last)->next = p;
    dlist->prev = dlist->last;
    dlist->last = p;
  }
}

Node *findNode(element_type val, dlist *dlist) {
  Node *p = list->root;
  if (dlist->root == NULL)
    return NULL;
  while (p != NULL) {
    if (p->element == val)
      return p;
    p = p->next;
  }
  printf("Not found!!\n");
  return NULL;
}

void delNode(Node *p, dlist *dlist) {
  if (dlist->root == NULL)
    return;
  if (p == NULL)
    return;
  if (p == dlist->root) {
    dlist->root = p->next;
    p->next->prev = NULL;
    free(p);
  }
  else if (p == dlist->last) {
    dlist->last = p->prev;
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

//display a list
void traverse(dlist *dlist) {
  Node *p;
  p = dlist->root;
  while ( p != NULL ) {
    display(p);
    p = p->next;
  }
}

