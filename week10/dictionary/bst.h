#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char word[20];
	char meaning[128];
} element_type;

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

void search(tree_type tree, element_type entry) {
	int flag = 0;
	if (tree == NULL)
		return;
	flag = strcmp(tree->info.word, entry.word);
	if (flag == 0)
		printf("Found.\n %s: %s\n", entry.word, entry.meaning);
	else if (flag < 0)
		search(tree->left, entry);
	else if (flag > 0)
		search(tree->right, entry);
}

void insert(tree_type *tree, element_type entry) {
	int flag = 0;
	flag = strcmp((*tree)->info.word, entry.word);
	if (*tree == NULL)
		*tree = makeTNode(entry);
	if (flag == 0)
	{
		printf("Duplicated entry. Please type again\n");
		insert(tree, entry);
	}
	else if (flag < 0)
		insert(&(*tree)->left, entry);
	else if (flag > 0)
		insert(&(*tree)->right, entry);
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