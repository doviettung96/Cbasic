#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TNode {
	void *info;
	struct TNode *left;
	struct TNode *right;
} TNode;

typedef TNode *tree_type;

void makeNullTree(tree_type *tree) {
	(*tree) = NULL;
}

TNode *makeTNode(void *val) {
	TNode *p;
	p = (TNode *)malloc(sizeof(TNode));
	p->left = NULL;
	p->right = NULL;
	p->info = val;
	return p;
}

int emptyTree(tree_type tree) {
	return tree == NULL;
}

void freeTree(tree_type tree) {
	if (emptyTree(tree))
		return;
	freeTree(tree->left);
	freeTree(tree->right);
	free(tree->info);
	free(tree);
	return;
}

TNode *search(tree_type tree, void *key){
	int *x, *y;
	x = (int *)key;
	if(tree == NULL)
		return NULL;
	if(tree->info == key)
		return tree;

	y = (int *)tree->info;
	if(*x < *y)
		tree = search(&tree->left, key);
	else if(*x > *y)
		tree = search(&tree->right, key);
}

void insert(tree_type *tree, void *key){
	int *x, *y;
	if(*tree == NULL)
		*tree = makeTNode(key);
	else if(*x < *y)
		(*tree)->left = insert(&(*tree)->left, key);
	else if(*x > *y)
		(*tree)->right = insert(&(*tree)->right, key);
}

void preOrder(tree_type tree, void (*order)(tree_type))
{
	if (tree != NULL)
	{
		order(tree);
		preOrder(tree->left, order);
		preOrder(tree->right, order);
	}
}

void inOrder(tree_type tree, void (*order)(tree_type))
{
	if (tree != NULL)
	{
		inOrder(tree->left, order);
		order(tree);
		inOrder(tree->right, order);
	}
}

void postOrder(tree_type tree, void (*order)(tree_type))
{
	if (tree != NULL)
	{
		postOrder(tree->left, order);
		postOrder(tree->right, order);
		order(tree);
	}
}
