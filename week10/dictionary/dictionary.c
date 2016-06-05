#include "bst.h"
#include "menu.h"

#define MAX 8

void display(tree_type tree);
void savetoFile(tree_type tree, FILE *f);
void saveTraverse(tree_type tree, void (*order)(tree_type, FILE *));

FILE *f;

void main() {

	tree_type tree;
	makeNullTree(&tree);
	element_type input;
	char sections[MAX][40] = {"Insert a word and meaning", "Traverse through the tree",
	                          "Search a word", "Delete a word", "Find minimum", "Find maximum",
	                          "Update a node", "Save to file and exit"
	                         };
	char word[20];
	char meaning[128];
	int choice;
	tree_type temp;

	if ((f = fopen("output.txt", "w+")) == NULL)
	{
		printf("Can't open file %s\n", "output.txt");
		exit(1);
	}

	do {
		choice = getMenu(sections, MAX);
		switch (choice) {
		case 1:
			while (getchar() != '\n');
			printf("Type in the word for the dictionary\n");
			printf("Word: ");
			scanf("%[^\n]", input.word);
			// printf("%s\n", input.word);
			while (getchar() != '\n');
			printf("Meaning: ");
			scanf("%[^\n]", input.meaning);
			// printf("%s\n", input.meaning);
			insert(&tree, input);
			break;
		case 2:
			printf("\nThe dictionary tree in the preorder\n");
			preOrder(tree, display);
			printf("\nThe dictionary tree in the inorder\n");
			inOrder(tree, display);
			printf("\nThe dictionary tree in the postorder\n");
			postOrder(tree, display);
			break;
		case 3:
			while (getchar() != '\n');
			printf("\nType in the word you want to find: ");
			scanf("%[^\n]", word);
			printf("\nResult: \n");
			temp = search(tree, word);
			printf("%s : %s\n", temp->info.word, temp->info.meaning);
			break;
		case 4:
			while (getchar() != '\n');
			printf("Type in a word to delete: ");
			scanf("%[^\n]", word);
			delete(&tree, word);
			break;
		case 5:
			temp = findMin(tree);
			printf("The min element: %s\n", temp->info.word);
			freeTree(tree);
			break;
		case 6:
			temp = findMax(tree);
			printf("The max element: %s\n", temp->info.word);
			break;
		case 7:
			// while (getchar() != '\n');
			// printf("\nType in the word you want to update: ");
			// scanf("%[^\n]", word);
			// update(tree, word);
			break;
		case MAX:
			saveTraverse(tree, savetoFile);
			fclose(f);
			freeTree(tree);
			break;
		default:
			printf("The choice must be from 1 to %d\n", MAX);
			break;
		}
	} while (choice != MAX);
}

void display(tree_type tree) {
	printf("%s: %s\n", tree->info.word, tree->info.meaning);
}

void savetoFile(tree_type tree, FILE *f) {
	fprintf(f, "%s: %s\n", tree->info.word, tree->info.meaning);
}

void saveTraverse(tree_type tree, void (*order)(tree_type, FILE *))
{
	if (tree != NULL)
	{
		order(tree, f);
		saveTraverse(tree->left, order);
		saveTraverse(tree->right, order);
	}
}