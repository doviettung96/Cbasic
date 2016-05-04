#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TNode {
	int info;
	struct TNode *left;
	struct TNode *right;
} TNode;

typedef TNode *tree_type;

void makeNullTree(tree_type *tree) {
	(*tree) = NULL;
}

TNode *makeTNode(int val) {
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
	free(tree);
	return;
}

TNode *search(tree_type tree, int key) {
	if (tree == NULL)
		return NULL;
	if (tree->info == key)
		return tree;

	if (key < tree->info)
		tree = search(&tree->left, key);
	else if (key > tree->info)
		tree = search(&tree->right, key);
}

void insert(tree_type *tree, int key) {
	if (*tree == NULL)
		*tree = makeTNode(key);
	else if (key < tree->info)
		(*tree)->left = insert(&(*tree)->left, key);
	else if (key > tree->info)
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

tree_type findMin(tree_type tree) {
	if (tree == NULL)
		return NULL;
	else if (tree->left != NULL)
		return findMin(tree->left);
	else
		return tree;
}

tree_type findMax(tree_type tree) {
	if (tree == NULL)
		return NULL;
	else if (tree->right != NULL)
		return findMax(tree->right);
	else
		return tree;
}

void reverseTree(tree_type *tree) {
	tree_type temp;
	
	if (*tree != NULL) {
		temp = (*tree)->left;
		(*tree)->left = (*tree)->right;
		(*tree)->right = temp;

		if ((*tree)->left != NULL)
			reverseTree(&(*tree)->left);
		if ((*tree)->right != NULL)
			reverseTree(&(*tree)->right);
	}
}