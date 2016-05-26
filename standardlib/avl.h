#ifndef _AVL_H_
#define _AVL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element_type;

typedef struct TNode {
	element_type info;
	int height;
	struct TNode *left;
	struct TNode *right;
} TNode;

typedef TNode *tree_type;

void makeNullTree(tree_type *tree);

TNode *makeTNode(element_type val);

int emptyTree(tree_type tree);

int height(tree_type tree);

int getBalance(tree_type tree);

int max(int a, int b);

void rotateLeft(tree_type *tree);

void rotateRight(tree_type *tree);

void freeTree(tree_type tree);

tree_type findMin(tree_type tree);

tree_type findMax(tree_type tree);

tree_type search(tree_type tree, element_type key);


void insert(tree_type *tree, element_type key);

element_type deleteMin (tree_type *tree );

void delete(tree_type *tree, element_type key);

void preOrder(tree_type tree, void (*order)(tree_type));

void inOrder(tree_type tree, void (*order)(tree_type));

void postOrder(tree_type tree, void (*order)(tree_type));

void reverseTree(tree_type *tree);

#endif