#include "bintree.h"

#define MAX 6

void main(int argc, char **argv)
{
	int n;
	n = atoi(argv[1]);
	TNode *p;
	element_type val;
	tree_type tree = NULL;
	makeNullTree(&tree);
	for (val = 1; val < MAX; ++val)
		tree = randomInsert(tree, val);
	// printf("The tree in preorder is: \n");
	// preOrder(tree);
	// printf("The tree in inorder is: \n");
	// inOrder(tree);
	// printf("The tree in postorder is: \n");
	// postOrder(tree);
	printf("\nTotal nodes of tree is: %d\n", countNode(tree));
	printf("Total leaves of tree is: %d\n", countLeaves(tree));
	printf("The height of the tree is: %d\n", height(tree));
	printf("Number of internal nodes: %d\n", countinternalNode(tree));
	printf("Number of right children: %d\n", nb_right(tree));
	// p = makeTNode(n);
	// printf("The depth of the %d-th node is: %d\n", n, depth(tree, p, ));
	freeTree(tree);
}