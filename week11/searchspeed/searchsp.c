#include "avl.h"
#include "time.h"
#include "menu.h"

#define MAX 10000000
#define MAXSC 5

void display(tree_type tree);

void main()
{
	int isFree = 0;
	int choice;
	char sections[MAXSC][40] = {"Create a binary tree database", "Free tree", "Traverse tree", "Find a number", "Exit"};
	int i = 0;
	tree_type tree;
	makeNullTree(&tree);
	element_type rd;
	tree_type temp;
	element_type result;
	srand(time(NULL));

	do {
		choice = getMenu(sections, MAXSC);
		switch (choice) {
		case 1:
			for (i = 0; i < MAX; ++i)
			{
				rd = rand();
				insert(&tree, rd);
			}
			isFree = 0;
			break;
		case 2:
			freeTree(tree);
			isFree = 1;
			break;
		case 3:
			if (isFree == 0) {
				inOrder(tree, display);
				printf("Height = %d\n", height(tree));
			}
			break;
		case 4:
			printf("Type in a number to search: ");
			scanf("%d", &result);
			temp = search(tree, result);
			if (temp == NULL)
				printf("Not found!\n");
			else
				printf("Result = %d, number of comparisions = %d\n", temp->info, height(temp));
			break;

		case MAXSC:
			if (isFree == 0)
				freeTree(tree);
			break;
		default:
			printf("Choice must be from 1 to %d\n", MAXSC);
			break;
		}
	} while (choice != MAXSC);
}

void display(tree_type tree) {
	printf("%d ", tree->info);
}