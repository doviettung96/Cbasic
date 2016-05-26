#ifndef _BST_H_
#define _BST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TNode {
	int info;
	struct TNode *left;
	struct TNode *right;
} TNode;

typedef TNode *tree_type;

void makeNullTree(tree_type *tree);
TNode *makeTNode(int val);
int emptyTree(tree_type tree);
void freeTree(tree_type tree);
TNode *search(tree_type tree, int key);
void insert(tree_type *tree, int key);
void preOrder(tree_type tree, void (*order)(tree_type));
void inOrder(tree_type tree, void (*order)(tree_type));
void postOrder(tree_type tree, void (*order)(tree_type));

tree_type findMin(tree_type tree);
tree_type findMax(tree_type tree);
void reverseTree(tree_type *tree);

#endif