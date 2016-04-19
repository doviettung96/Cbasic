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

TNode *leftChild(TNode *p) {
	if (p != NULL)
		return p->left;
	else
		return NULL;
}

TNode *rightChild(TNode *p) {
	if (p != NULL)
		return p->right;
	else
		return NULL;
}

int isLeaf(tree_type p) {
	if (p != NULL)
		if (leftChild(p) == NULL && rightChild(p) == NULL)
			return -1;
}

tree_type randomInsert(tree_type tree, element_type val)
{
	TNode *new, *p;
	new = makeTNode(val);
	if (tree == NULL)
		return new;
	if (rand() % 2 == 0)
	{
		p = tree;
		while (p->left != NULL)
			p = p->left;
		p->left = new;
		printf("Node %d is left child of %d\n", val, p->info);
	}
	else
	{
		p = tree;
		while (p->right != NULL)
			p = p->right;
		p->right = new;
		printf("Node %d is right child of %d\n", val, p->info);
	}
	return tree;
}

int countNode(tree_type tree) {
	if (emptyTree(tree))
		return 0;
	else
		return 1 + countNode(leftChild(tree)) + countNode(rightChild(tree));
}

//doesn't work normally
int countLeaves(tree_type tree) {
	int s = 0;
	int l, r;
	if (emptyTree(tree))
		return 0;
	l = isLeaf(tree->left);
	r = isLeaf(tree->right);
	if (l != -1)
		s += l;
	if (r != -1)
		s += r;
	return countLeaves(leftChild(tree)) + countLeaves(rightChild(tree)) + s;
}

int height(tree_type tree) {
	int ld, rd;
	if (emptyTree(tree))
		return 0;
	ld = height(leftChild(tree));
	rd = height(rightChild(tree));
	return 1 + (ld > rd ? ld : rd);
}

int depth(tree_type tree, TNode *p, int d)
{
	if (tree == NULL || p == NULL) return 0;
	else if (tree == p ) return d;
	else {
		return depth(tree->left, p, d + 1) + depth(tree->right, p, d + 1);
	}
}

//doesn't work normally
int countinternalNode(tree_type tree) {
	if (tree == NULL) return 0;
	else {
		int l = isLeaf(tree->left),
		    r = isLeaf(tree->right),
		    s = 0;
		if (l != -1) s += (l == 0) ? 1 : 0;
		if (r != -1) s += (r == 0) ? 1 : 0;
		return s + countinternalNode(tree->left) + countinternalNode(tree->right);
	}
}

int nb_right(tree_type tree) {
	if (tree == NULL) return 0;
	else {
		int s = 0;
		if (tree->right != NULL) s = 1;
		return s + nb_right(tree->right) + nb_right(tree->left);
	}
}

tree_type createFrom2(element_type val, tree_type left, tree_type right)
{
	TNode *new;
	new = makeTNode(val);
	new->left = left;
	new->right = right;
	return new;
}

tree_type addtoLeftmost(tree_type *tree, element_type val)
{
	TNode *new;
	new = makeTNode(val);
	if (new == NULL)
		return new;
	if (*tree == NULL)
		*tree = new;
	else
	{
		TNode *lNode = *tree;
		while (lNode->left != NULL)
			lNode = lNode->left;
		lNode->left = new;
	}
	return new;
}

tree_type addtorightmost(tree_type *tree, element_type val)
{
	TNode *new;
	new = makeTNode(val);
	if (new == NULL)
		return new;
	if (*tree == NULL)
		*tree = new;
	else
	{
		TNode *rNode = *tree;
		while (rNode->right != NULL)
			rNode = rNode->right;
		rNode->right = new;
	}
	return new;
}

void preOrder(tree_type tree)
{
	if (tree != NULL)
	{
		printf("%d\n", tree->info);
		preOrder(tree->left);
		preOrder(tree->right);
	}
}

void inOrder(tree_type tree)
{
	if (tree != NULL)
	{
		inOrder(tree->left);
		printf("%d\n", tree->info);
		inOrder(tree->right);
	}
}

void postOrder(tree_type tree)
{
	if (tree != NULL)
	{
		postOrder(tree->left);
		postOrder(tree->right);
		printf("%d\n", tree->info);
	}
}

