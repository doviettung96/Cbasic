#include "bst.h"

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

tree_type search(tree_type tree, key_type key) {
	if (tree == NULL)
		return NULL;
	else if (tree->info.key == key)
		return tree;
	else if (key < tree->info.key)
		tree = search(tree->left, key);
	else
		tree = search(tree->right, key);
}

void insert(tree_type *tree, element_type entry) {
	if (*tree == NULL)
		*tree = makeTNode(entry);
	else if (entry.key < tree->info.key)
		(*tree)->left = insert(&(*tree)->left, entry);
	else if (entry.key > tree->info.key)
		(*tree)->right = insert(&(*tree)->right, entry);
}

element_type deleteMin (tree_type *tree) {
	element_type key;
	if ((*tree)->left == NULL) {
		key = (*tree)->info;
		(*tree) = (*tree)->right;
		return key;
	}
	else return deleteMin(&(*tree)->left);
}

void delete(tree_type *tree, key_type key)
{
	if (*tree != NULL)
	{
		if (key < (*tree)->info.key)
			delete(&(*tree)->left, key);
		else if (key > (*tree)->info.key)
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