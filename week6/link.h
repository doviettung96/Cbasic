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
typedef struct slist$ {
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

//find the length of a list
int listLength(slist *list) {
  Node *p;
  int i = 0;
  p = list->root;
  while (p != NULL) {
    i++;
    p = p->next;
  }
  return i;
}

//display a node
void display(Node *p) {
  printf("%-30s\t%-3d\t%-2.1f\t%-9d\n", p->element.model, p->element.storage, p->element.screensize, p->element.price);
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

//insert at position
Node *insertAtPosition(slist *list, element_type val, int n) {
  Node *p = list->root;
  int i = 1;
  if (list->root == NULL) {
    printf("Node haven't create !!");
    return NULL;
  }
  if (n < 1 || n > listLength(list))
  {
    printf("You've inputed an invalid position\n");
    return NULL;
  }
  if (n == 1)
    insertAfter(list->root, val, list);
  else if (n == listLength(list))
    insertAfter(list->last, val, list);
  else
  {
    while (p != NULL)
    {
      i++;
      if (i = n)
        break;
      p = p->next;
    }
    insertAfter(p, val, list);
  }
  return list->cur;
}

Node *deleteAtPosition(slist *list, int n) {
  Node *p = list->root;
  int i = 1;
  if (list->root == NULL) {
    printf("Node haven't create !!");
    return NULL;
  }
  if (n < 1 || n > listLength(list))
  {
    printf("You've inputed an invalid position\n");
    return NULL;
  }
  if (n == 1)
    delNode(list->root, list);
  else if (n == listLength(list))
    delNode(list->last, list);
  else
  {
    while (p != NULL)
    {
      i++;
      if (i = n)
        break;
      p = p->next;
    }
    delNode(p, list);
  }
  return list->root;
}


//display a list
void traverse(slist *list) {
  Node *p;
  p = list->root;
  while ( p != NULL ) {
    display(p);
    p = p->next;
  }
}

//save the content of list to a data file
void savetoFile(FILE *fptr, slist *list) {
  Node *p;
  p = list->root;
  while ( p != NULL ) {
    // fwrite(&p->element, sizeof(element_type), 1, fptr);
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
  Node *p = list->root;
  if ((fptr = fopen(fileName, "w + t")) == NULL)
  {
    printf("Can't open file %s\n", fileName);
    exit(1);
  }
  // while (p != NULL) {
  //   fprintf(fptr, "%-30s\t%-3d\t%-2.1f\t%-9d\n", p->element.model, p->element.storage, p->element.screensize, p->element.price);
  //   p = p->next;
  // }
  savetoFile(fptr, list);
}

// Node* list_reverse(slist *list) {
//   Node *p = NULL, *prev = NULL;
//   prev = preNode(p, list);
//   list->last = list->root;
//   p = list->root;
//   list->root = (list->root)->next;
//   prev = list->root;
//   while (list->root != NULL) {
//     p = list->root;
//     list->root = list->root->next;
//     p->next = prev;
//     prev = p;
//   }
//   return prev;
// }

// reverse list
void list_reverse(slist *list) {
  Node *z, *p;
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

void freeList(slist *list) {
  if (list->root == NULL) return;
  Node *to_free = list->root;
  while (to_free != NULL) {
    list->root = (list->root)->next;
    free(to_free); // free node
    to_free = list->root;
  }
}