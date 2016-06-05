#include "tgdd.h"
#include "bst.h"
#include "menu.h"

#define MAX 6

void display(tree_type tree);

int main(int argc, char **argv) {
	tree_type tree;
	tree_type t;
	int choice;
	char temp[20];
	int i = 0;
	int numData;
	FILE *fin;

	char sections [MAX][40] = {"Import from nokiaDB.dat", "Display (traverse)", "Add new phone ",
	                           "Delete by model", "Search and update", "Exit (free)"
	                          };


	makeNullTree(&tree);
	do {
		choice = getMenu(sections, MAX);
		switch (choice) {
		case 1:
			if ((fin = fopen(argv[1], "rb")) == NULL)
			{
				printf("Can't open file %s\n", argv[1]);
				exit(1);
			}
			fseek(fin, 0, SEEK_END);
			numData = ftell(fin) / sizeof(element_type);
			rewind(fin);
			result = importfromDB(fin, numData);
			// for (i = 0; i < result; ++i)
			insert(&tree, parr[i]);
			fclose(fin);
			break;
		case 2:
			inOrder(tree, display);
			break;
		case 3:
			insert(&tree, typeHand());
			break;
		case 4:
			printf("Type in the model to delete: \n");
			while (getchar() != '\n');
			scanf("%[^\n]", temp);
			delete(&tree, temp);
			break;
		case 5:
			printf("Type in the model to search: \n");
			while (getchar() != '\n');
			scanf("%[^\n]", temp);
			t = search(tree, temp);
			if (t != NULL)
				display(t);
			break;
		case MAX:
			freeTree(tree);
			exit(1);
		default: printf("Invalid choice. It must be from 1 to %d\n", MAX); break;
		}
	} while (choice != MAX);
	return 0;
}

void display(tree_type tree) {
	printf("%-30s|%-3d|%-4.2f|%-8d\n", tree->info.model, tree->info.storage, tree->info.screensize, tree->info.price);
}