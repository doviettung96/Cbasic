#ifndef _BST_H_
#define _BST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int key_type;
typedef struct{
	key_type key;
} element_type;

typedef struct TNode {
	element_type info;
	struct TNode *left;
	struct TNode *right;
} TNode;

typedef TNode *tree_type;

void makeNullTree(tree_type *tree);
TNode *makeTNode(element_type val);
int emptyTree(tree_type tree);
void freeTree(tree_type tree);
tree_type search(tree_type tree, key_type key);
void insert(tree_type *tree, element_type entry);
element_type deleteMin (tree_type *tree);
void delete(tree_type *tree, key_type key);
void preOrder(tree_type tree, void (*order)(tree_type));
void inOrder(tree_type tree, void (*order)(tree_type));
void postOrder(tree_type tree, void (*order)(tree_type));

tree_type findMin(tree_type tree);
tree_type findMax(tree_type tree);
void reverseTree(tree_type *tree);

#endif