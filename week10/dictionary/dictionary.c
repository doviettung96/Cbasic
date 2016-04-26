#include "bst.h"

#define MAX 6
void display(tree_type tree);
void main(int argc, char **argv) {
	FILE *f;
	tree_type tree;
	makeNullTree(&tree);
	element_type input[MAX];
	int i;

	if((f = fopen(argv[1], "r")) == NULL)
	{
		printf("Can't open file %s\n", argv[1]);
		exit(1);
	}

	printf("Type in the words for the dictionary\n");
	for (i = 0; i < MAX; ++i)
	{
		// printf("%d-th word: ", i + 1);
		fscanf(f, "%s\n", input[i].word);
		// while (getchar() != '\n');
		// printf("Meaning: ");
		fscanf(f, "%[^\n]", input[i].meaning);
		insert(&tree, input[i]);
	}

	printf("The dictionary tree in the preorder\n");
	preOrder(tree, display);
	printf("The dictionary tree in the inorder\n");
	inOrder(tree, display);
	printf("The dictionary tree in the postorder\n");
	postOrder(tree, display);

	freeTree(tree);
}

void display(tree_type tree) {
	printf("%s: %s \n", tree->info.word, tree->info.meaning);
}