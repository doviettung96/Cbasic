#ifndef _BIN_TREE_H
#define _BIN_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TNode {
	void *info;
	struct TNode *left;
	struct TNode *right;
} TNode;

typedef TNode *tree_type;


void makeNullTree(tree_type *tree);

TNode *makeTNode(void *val);

int emptyTree(tree_type tree);

void freeTree(tree_type tree);

TNode *leftChild(TNode *p);

TNode *rightChild(TNode *p);

int isLeaf(tree_type p);

tree_type constructTree(void **preval, char preLN[], int *index_ptr, int n);

tree_type buildTree(void **preval, char preLN[], int n);

int countNode(tree_type tree);

int countLeaves(tree_type tree);

int height(tree_type tree);

int depth(tree_type tree, TNode *p, int d);

int nb_right(tree_type tree);

tree_type createFrom2(void *val, tree_type left, tree_type right);

tree_type addtoLeftmost(tree_type *tree, void *val);

tree_type addtorightmost(tree_type *tree, void *val);

void preOrder(tree_type tree, void (*order)(tree_type));

void inOrder(tree_type tree, void (*order)(tree_type));

void postOrder(tree_type tree, void (*order)(tree_type));

void reverseTree(tree_type *tree);

#endif