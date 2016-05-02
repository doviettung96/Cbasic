#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element_type;

typedef struct TNode {
	element_type info;
	struct TNode *left;
	struct TNode *right;
} TNode;

typedef TNode *tree_type;

void makeNullTree(tree_type *tree) {
	(*tree) = NULL;
}

TNode *makeTNode(element_type val) {
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

tree_type search(tree_type tree, element_type key) {
	if (tree == NULL)
		return NULL;
	else if (tree->info == key)
		return tree;
	else if (key < tree->info)
		tree = search(tree->left, key);
	else
		tree = search(tree->right, key);
}

void insert(tree_type *tree, element_type key) {
	if (*tree == NULL)
		*tree = makeTNode(key);
	else if ((*tree)->info > key)
		insert(&(*tree)->left, key);
	else if ((*tree)->info < key)
		insert(&(*tree)->right, key);
}

element_type deleteMin (tree_type *tree ) {
	element_type key;
	if ((*tree)->left == NULL) {
		key = (*tree)->info;
		(*tree) = (*tree)->right;
		return key;
	}
	else return deleteMin(&(*tree)->left);
}

void delete(tree_type *tree, element_type key)
{
	if (*tree != NULL)
	{
		if (key < (*tree)->info)
			delete(&(*tree)->left, key);
		else if (key > (*tree)->info)
			delete(&(*tree)->right, key);
		else if ((*tree)->left == NULL && (*tree)->right == NULL)
			*tree = NULL;
		else if ((*tree)->left == NULL)
			*tree = (*tree)->right;
		else if ((*tree)->right == NULL)
			*tree = (*tree)->left;
		else
			(*tree)->info = deleteMin(&(*tree)->right);
	}
}

int height(tree_type tree) {
	int ld, rd;
	if (emptyTree(tree))
		return 0;
	ld = height(tree->left);
	rd = height(tree->right);
	return 1 + (ld > rd ? ld : rd);
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

void reverseTree(tree_type *tree) {
	tree_type temp;

	if (*tree != NULL) {
		if ((*tree)->left != NULL)
			reverseTree(&(*tree)->left);
		if ((*tree)->right != NULL)
			reverseTree(&(*tree)->right);

		temp = (*tree)->left;
		(*tree)->left = (*tree)->right;
		(*tree)->right = temp;
	}
}