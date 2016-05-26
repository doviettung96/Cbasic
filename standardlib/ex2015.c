#include "avl.h"
#include "menu.h"

#define MAXSC 6

void readData(FILE *f, char fileName[], tree_type *tree);
void display(tree_type tree);
void main() {
	int choice;
	char sections[MAXSC][40] = {"Read from A.txt", "Read from B.txt", "Search", "Ultility", "Report", "Exit"};
	FILE *f1, *f2;
	tree_type tree;
	element_type pattern[4];
	int i = 0;
	tree_type temp;
	makeNullTree(&tree);

	do {
		choice = getMenu(sections, MAXSC);
		switch (choice)
		{
		case 1:
			readData(f1, "A.txt", &tree);
			inOrder(tree, display);
			// preOrder(tree, display);
			// postOrder(tree, display);
			break;
		case 2:
			if ((f2 = fopen("B.txt", "r")) == NULL)
			{
				printf("Can't open file %s\n", "B.txt");
				exit(1);
			}
			for (i = 0; i < 4; ++i)
			{
				fscanf(f2, "%d\t%s\n", &pattern[i].key, pattern[i].name);
				if (strcmp(pattern[i].name, "-1") == 0)
				{
					printf("Type in the name of %d: ", pattern[i].key);
					scanf("%s", pattern[i].name);
				}
			}

			printf("Result: \n");
			for (i = 0; i < 4; ++i)
				printf("%d: %s\n", pattern[i].key, pattern[i].name);

			break;
		case 3:
			for (i = 0; i < 4; ++i)
			{
				temp = search(tree, pattern[i].key);
				if (temp != NULL)
				{
					printf("Duplicate entry: ");
					display(temp);
					delete(&tree, pattern[i].key);
				}
			}
			printf("New tree\n");
			inOrder(tree, display);
			break;
		case 4:
			for(i = 0; i < 4; ++i)
				insert(&tree, pattern[i]);
			reinOrder(tree, display);
			break;
		case 5: break;
		case MAXSC:
			freeTree(tree);
			break;
		default: printf("Choice must be from 1 to %d\n", MAXSC); break;
		}
	} while (choice != MAXSC);
}

void readData(FILE *f, char fileName[], tree_type *tree) {
	if ((f = fopen(fileName, "r")) == NULL)
	{
		printf("Can't open file %s\n", fileName);
		exit(1);
	}
	int i = 0, j;
	element_type entry;
	while (!feof(f))
	{
		fscanf(f, "%d\t%s\n", &entry.key, entry.name);
		// printf("%d: %s\n", entry.key, entry.name);
		if (strcmp(entry.name, "-1") == 0)
		{
			printf("Type in the name of %d: ", entry.key);
			scanf("%s", entry.name);
		}
		insert(tree, entry);
	}
	fclose(f);
}

void display(tree_type tree)
{
	printf("%d: %s\n", tree->info.key, tree->info.name);
}