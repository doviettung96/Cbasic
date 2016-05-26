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
slist *iniList() {
	slist *list;
	list = (slist *)malloc(sizeof(slist));
	if (list == NULL) {
		fprintf(stderr, "ERROR : Allocated memory failed !!\n");
		exit(1);
	}
	list->root = NULL;
	list->cur = NULL;
	list->last = NULL;
	return list;
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


// // find Node
// Node *findNode(element_type val, slist *list) {
//   Node *p = list->root;
//   if (list->root == NULL) return NULL;
//   else {
//     while (p != NULL) {
//       if (strcmp(p->element.model, val.model) == 0 && p->element.storage == val.storage &&
//           p->element.screensize == val.screensize && p->element.price == val.price)
//       {
//         list->cur = p;
//         return p;
//       }
//       else p = p->next ;
//     }
//     printf("Not found \n");
//     return NULL;
//   }
// }

//locate n-th Node in a list
Node *locateNode(int n, slist *list) {
	int i = 0;
	Node *p = list->root;
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

// find pre Node of Node p
Node *preNode(Node *p, slist *list) {
	Node *pre = list->root;
	if (list->root == NULL) return NULL;
	else if (pre == p) return pre;
	else {
		while (pre != NULL) {
			if (pre->next == p)
			{
				list->cur = p;
				return pre;
			}
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
	// free(p->element);
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
			// free(q->element);
			free(q);
		}  else  {
			q->next = p->next;
			p->next = q;
		}
	}
}

//display a list
void traverse(slist *list, void (*function)(Node *)) {
	Node *p;
	p = list->root;
	while ( p != NULL ) {
		function(p);
		p = p->next;
	}
}

//save the content of list to a data file
void savetoFile(slist *list, FILE *f, char fileName[]) {
	Node *p;
	p = list->root;
	if ((f = fopen(fileName, "w")) == NULL)
	{
		printf("Can't open file %s\n", fileName);
		exit(1);
	}

	while ( p != NULL ) {
		fprintf(f, "%s\n%f\n", p->element.name, p->element.mark);
		p = p->next;
	}
	fclose(f);
}

//split a list from startPosition to the end with the length of numSplit
void splitList(int startPosition, int numSplit, slist *list, slist *list2, slist *list3) {
	Node *p;
	int i;
	int check[numSplit];
	printf("The length of the list is %d\n", listLength(list));
	for (i = 1; i <= listLength(list); ++i)
	{
		p = locateNode(i, list);
		if (i >= startPosition && i < startPosition + numSplit)
			insertEnd(p->element, list2);
		else
			insertEnd(p->element, list3);
	}
	printf("Split list success\n");
}

//add node to the end of list
void insertNode(Node *p, slist *list) {
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

//display a list
void saveList(slist *list, slist *result, void (*function)(Node *, slist *)) {
	Node *p;
	p = list->root;
	while ( p != NULL ) {
		function(p, result);
		p = p->next;
	}
}

// void checkList(slist *list, char fileName[20]) {
// 	FILE *fptr;
// 	Node *p = list->root;
// 	if ((fptr = fopen(fileName, "w + t")) == NULL)
// 	{
// 		printf("Can't open file %s\n", fileName);
// 		exit(1);
// 	}
// 	// while (p != NULL) {
// 	//   fprintf(fptr, "%-30s\t%-3d\t%-2.1f\t%-9d\n", p->element.model, p->element.storage, p->element.screensize, p->element.price);
// 	//   p = p->next;
// 	// }
// 	savetoFile(fptr, list);
// }

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
		// free(to_free->element);
		free(to_free); // free node
		to_free = list->root;
	}
	free(list);
}