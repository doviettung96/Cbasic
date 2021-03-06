#include "bst.h"

#define MAX 6

void display(tree_type tree);
void main() {
	int input[MAX];
	int i;
	int check;
	tree_type tree;
	makeNullTree(&tree);
	tree_type temp;
	printf("Type in the input: \n");
	for (i = 0; i < MAX; ++i)
	{
		printf("%d-th number: ", i + 1);
		scanf("%d", &input[i]);
		insert(&tree, input[i]);
	}
	printf("Type in a value to delete: ");
	scanf("%d", &check);
	delete(&tree, check);
	
	reverseTree(&tree);

	printf("\nThe tree in preoder: \n");
	preOrder(tree, display);
	printf("\nThe tree in inoder: \n");
	inOrder(tree, display);
	printf("\nThe tree in postoder: \n");
	postOrder(tree, display);
	printf("\n");
	temp = findMin(tree);
	printf("The min element: %d\n", temp->info);
	temp = findMax(tree);
	printf("The max element: %d\n", temp->info);
	freeTree(tree);
}

void display(tree_type tree) {
	printf("%d ", tree->info);
}