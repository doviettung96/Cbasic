#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef phone_inf element_type;
typedef struct Node Node;
typedef struct Node {
  element_type element;
  Node* next;
} Node;

//structure of a single list
typedef struct slist${
  Node *root;
  Node *cur;
  Node *last;
} slist;

//initialize a list
void iniList(slist *list) {
  list->root = NULL;
  list->cur = NULL;
  list->last = NULL;
}



//make Node
Node *makeNode(element_type val) {
  Node *p;
  p  = (Node *)malloc(sizeof(Node));
  p->next = NULL;
  p->element = val;
  return p;
}


// insert Node to end

void insertEnd(element_type val, slist *list) {
  Node *p;
  p = makeNode(val);

  if (list->root == NULL) {
    list->root = p;
    list->cur = p;
    list->last = p;
  } else {
    (list->last)->next = p;
    list->last = p;
    list->cur = p;
  }
}


// find Node
Node *findNode(element_type val, slist *list) {
  Node *p = list->root;
  if (list->root == NULL) return NULL;
  else {
    while (p != NULL) {
      if (strcmp(p->element.model, val.model) == 0 && p->element.storage == val.storage &&
          p->element.screensize == val.screensize && p->element.price == val.price)
        return p;
      else p = p->next ;
    }
    printf("Not found \n");
    return NULL;
  }
}


// find pre Node of Node p
Node *preNode(Node *p, slist *list) {
  Node *pre = list->root;
  if (list->root == NULL) return NULL;
  else if (pre == p) return pre;
  else {
    while (pre != NULL) {
      if (pre->next == p) return pre;
      pre = pre->next;
    }
    return NULL;
  }
}


// del Node p
void delNode(Node *p, slist *list) {

  Node *pre = preNode(p, list);
  list->cur = pre;
  if (p == list->root) {
    list->root = p->next;
  } else {
    pre->next = p->next;
    if (p == list->last) {
      list->last = pre;
    }
  }
  free(p);
}



// insert Node before Node p
void insertBefore(Node *p, element_type val, slist *list) {
  Node *q = makeNode(val);
  list->cur = q;
  if (list->root == NULL) {
    printf("Node haven't create !!");
    return;
  } else if (list->root == p) {
    list->root = q;
    q->next = p;
  } else {
    q->next = p;
    preNode(p, list)->next = q;
  }
}


// insert Node after Node p
void insertAfter(Node *p, element_type val, slist *list) {
  Node *q = makeNode(val);
  list->cur = q;
  if (list->root == NULL) {
    printf("Node haven't create !!");
    return;
  } else {
    if (list->last == p) {
      insertEnd(val, list);
      free(q);
    }  else  {
      q->next = p->next;
      p->next = q;
    }
  }
}

void display(slist *list) {
  Node *p;
  p = list->root;
  while ( p != NULL ) {
    printf("%-30s\t%-3d\t%-2.1f\t%-9d\n", p->element.model, p->element.storage, p->element.screensize, p->element.price);
    p = p->next;
  }
}

void savetoFile(FILE *fptr, slist *list) {
  Node *p;
  p = list->root;
  while ( p != NULL ) {
    fprintf(fptr, "%-30s\t%-3d\t%-2.1f\t%-9d\n", p->element.model, p->element.storage, p->element.screensize, p->element.price);
    p = p->next;
  }
}
//split a list from startPosition to the end with the length of numSplit
void splitList(int startPosition, int numSplit, slist *list, slist *list2) {
  int i = 0;
  int check[numSplit];
  for (i = startPosition; i < startPosition + numSplit; ++i)
  {
    insertEnd(parr[i], list2);
    delNode(findNode(parr[i], list), list);
  }
  printf("Split list success\n");
}

void checkList(slist *list, char fileName[20]) {
  FILE *fptr;
  if ((fptr = fopen(fileName, "wt")) == NULL)
  {
    printf("Can't open file %s\n", fileName);
    exit(1);
  }
  savetoFile(fptr, list);
}

Node* list_reverse(slist *list) {
  Node *p = NULL, *prev = NULL;
  prev = preNode(p, list);
  while (list->root != NULL) {
    p = list->root;
    list->root = list->root->next;
    p->next = prev;
    prev = p;
  }
  return prev;
}

void freeList(slist *list){
   if (list->root == NULL) return;
   Node *to_free = list->root;
   while(to_free != NULL){
     list->root = (list->root)->next;
     free(to_free); // free node
     to_free = list->root;
   }
 }