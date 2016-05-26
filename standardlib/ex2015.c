#include "avl.h"
#include "menu.h"

#define MAXSC 6

void readData(FILE *f, char fileName[], tree_type *tree);
void display(tree_type tree);
void main() {
	int choice;
	char sections[MAXSC][40] = {"Read from A.txt", "Read from B.txt", "Search", "Ultility", "Report", "Exit"};
	FILE *f;
	tree_type tree;
	makeNullTree(&tree);

	do {
		choice = getMenu(sections, MAXSC);
		switch (choice)
		{
		case 1:
			readData(f, "A.txt", &tree);
			inOrder(tree, display);
			break;
		case 2: break;
		case 3: break;
		case 4: break;
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