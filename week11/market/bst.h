#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char ms[20];
	char name[30];
	int money;
	int tp;
	int dt;
	int mm;
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

element_type deleteMin (tree_type *tree ) {
	element_type entry;
	if ((*tree)->left == NULL) {
		entry = (*tree)->info;
		(*tree) = (*tree)->right;
		return entry;
	}
	else return deleteMin(&(*tree)->left);
}

void delete(tree_type *tree, char *ms)
{
	int flag = 0;
	if (*tree != NULL)
	{
		flag = strcmp(ms, (*tree)->info.ms);

		if (flag < 0)
			delete(&(*tree)->left, ms);
		else if (flag > 0)
			delete(&(*tree)->right, ms);
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

tree_type search(tree_type tree, char *ms) {
	int flag = 0;
	if (tree == NULL)
	{
		printf("Not found!!\n");
		return NULL;
	}
	flag = strcmp(tree->info.ms, ms);
	if (flag == 0) {
		printf("Found.\n");
		return tree;
	}
	else if (flag > 0)
		tree = search(tree->left, ms);
	else if (flag < 0)
		tree = search(tree->right, ms);
}

void insert(tree_type *tree, element_type entry) {
	int flag = 0;
	if (*tree == NULL)
	{
		*tree = makeTNode(entry);
		return;
	}

	flag = strcmp((*tree)->info.ms, entry.ms);
	if (flag == 0)
	{
		printf("Duplicated entry. Please type again\n");
		return;
	}

	if (flag > 0)
		insert(&(*tree)->left, entry);
	else if (flag < 0)
		insert(&(*tree)->right, entry);
}

// void update(tree_type *tree, char *word)
// {
// 	int choice;
// 	char newword[20];
// 	char newmeaning[128];
// 	tree_type temp;
// 	do {
// 		printf("1. Update meaning\n2. Update word\n3. Return to main menu\n");
// 		printf("Your choice: ");
// 		scanf("%d", &choice);
// 		switch (choice)
// 		{
// 		case 1:
// 			temp = search(*tree, word);
// 			printf("Type in the new meaning for %s\n", temp->info.word);
// 			while (getchar() != '\n');
// 			scanf("%[^\n]", newmeaning);
// 			strcpy(temp->info.meaning, newmeaning);
// 			delete(tree, word);
// 			insert(tree, temp->info);
// 			break;
// 		case 2:
// 			temp = search(*tree, word);
// 			printf("Type in the new word for %s\n", temp->info.word);
// 			while (getchar() != '\n');
// 			scanf("%[^\n]", newword);
// 			strcpy(temp->info.word, newword);
// 			delete(tree, word);
// 			insert(tree, temp->info);
// 			break;
// 		case 3:
// 			break;
// 		default:
// 			printf("Choice must be from 1 to 3\n");
// 			break;
// 		}
// 	} while (choice != 3);
// }


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
