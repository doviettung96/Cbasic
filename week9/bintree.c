#include "bintree.h"

#define MAX 9
void display(tree_type tree);
void main(int argc, char **argv)
{
	FILE *f;
	int i;
	TNode *p;
	// void **preval;
	char preval[MAX][10];
	char preLN[MAX];
	tree_type tree = NULL;
	makeNullTree(&tree);

	if ((f = fopen(argv[1], "r")) == NULL)
	{
		printf("Can't open file %s\n", argv[1]);
		exit(1);
	}

	// preval = malloc(sizeof(void) * MAX);
	for (i = 0; i < MAX; ++i)
	{
		// *(preval + i) = (char *)malloc(sizeof(char) * 10);
		fscanf(f, "%s %c\n", preval[i], &preLN[i]);
	}

	tree = buildTree(preval, preLN, MAX);

	printf("\nThe tree in preorder is: \n");
	preOrder(tree, display);
	printf("\nThe tree in inorder is: \n");
	inOrder(tree, display);
	printf("\nThe tree in postorder is: \n");
	postOrder(tree, display);
	printf("\nTotal nodes of tree is: %d\n", countNode(tree));
	printf("Total leaves of tree is: %d\n", countLeaves(tree));
	printf("The height of the tree is: %d\n", height(tree));
	printf("Number of internal nodes: %d\n", countNode(tree) - 1 - countLeaves(tree));
	printf("Number of right children: %d\n", nb_right(tree));
	// printf("Result = %d\n", calInorder(tree));
	// p = makeTNode(n);
	// printf("The depth of the %d-th node is: %d\n", n, depth(tree, p, ));
	freeTree(tree);
}

void display(tree_type tree) {
	printf("%s ", (char *)(tree->info));
}