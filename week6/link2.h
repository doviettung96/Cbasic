#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
  char name[30];
  char tel[15];
  char email[30];
} phone_addr;

typedef phone_addr element_type;
typedef struct Node Node;
typedef struct Node {
  element_type element;
  Node* next;
} Node;

//structure of a single list
typedef struct slist{
  Node *root;
  Node *last;
} slist; 

//initialize a list 
void iniList() {
  slist->root = NULL;
  slist->last = NULL;
}

//make Node
Node *makeNode(element_type val) {
  Node *p;
  p  = (Node *)malloc(sizeof(Node));
  p->next = NULL;
  p->element = val;
  return p;
}


// insertNode to end

void insertEnd(element_type val, Node *root, Node *last) {
  Node *p;
  p = makeNode(val);

  if (root == NULL) {
    root = p;
    last = p;
  } else {
    last->next = p;
    last = p;
  }
}


// find Node
Node *findNode(element_type val, Node *root) {
  Node *p = root;
  if (root == NULL) return NULL;
  else {
    while (p != NULL) {
      if (strcmp(p->element.name, val.name) == 0 && strcmp(p->element.tel, val.tel) == 0 
        && strcmp(p->element.email, val.email) == 0)
        return p;
      else p = p->next ;
    }
    printf("Not found \n");
    return NULL;
  }
}


// find pre Node of Node p
Node *preNode(Node *p, Node *root) {
  Node *pre = root;
  if (root == NULL) return NULL;
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
void delNode(Node *p, Node *root, Node *last) {

  Node *pre = preNode(p, root);
  if (p == root) {
    root = p->next;
  } else {
    pre->next = p->next;
    if (p == last) {
      last = pre;
    }
  }
  free(p);
}



// insert Node before Node p
void insertBefore(Node *p, element_type val, Node *root) {
  Node *q = makeNode(val);
  if (root == NULL) {
    printf("Node haven't create !!");
    return;
  } else if (root == p) {
    root = q;
    q->next = p;
  } else {
    q->next = p;
    preNode(p, root)->next = q;
  }
}


// insert Node after Node p
void insertAfter(Node *p, element_type val, Node *root, Node *last) {
  Node *q = makeNode(val);
  if (root == NULL) {
    printf("Node haven't create !!");
    return;
  } else {
    if (last == p) {
      insertEnd(val, root, last);
      free(q);
    }  else  {
      q->next = p->next;
      p->next = q;
    }
  }
}

void display(Node *root) {
  Node *p;
  p = root;
  while ( p != NULL ) {
    printf("%-30s\t%-15s\t%-30s\n", p->element.name, p->element.tel, p->element.email);
    p = p->next;
  }
}

void savetoFile(FILE *fptr, Node *root) {
  Node *p;
  p = root;
  while ( p != NULL ) {
    fprintf(fptr, "%%-30s\t%-15s\t%-30s\n", p->element.name, p->element.tel, p->element.email);
    p = p->next;
  }
}
//split a list from startPosition to the end with the length of numSplit
void splitList(int startPosition, int numSplit, Node *root) {
  int i = 0;
  int check[numSplit];
  for (i = startPosition; i < startPosition + numSplit; ++i)
  {
    insertEnd(parr[i], root2, last2);
    delNode(findNode(parr[i], root), root, last);
  }
  printf("Split list success\n");
}

void checkList(Node *root, char fileName[20]) {
  FILE *fptr;
  if ((fptr = fopen(fileName, "wt")) == NULL)
  {
    printf("Can't open file %s\n", fileName);
    exit(1);
  }
  savetoFile(fptr, root);
}

Node* list_reverse(Node* root) {
  Node *p = NULL, *prev = NULL;
  prev = preNode(p, root);
  while (root != NULL) {
    p = root;
    root = root->next;
    p->next = prev;
    prev = p;
  }
  return prev;
}