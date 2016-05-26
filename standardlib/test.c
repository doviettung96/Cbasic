#include "link.h"
#include "menu.h"

#define MAXSC 6

void readData(FILE *f, char fileName[], slist *list);
void search(slist *list, float key);
void best(slist *list, slist *excellent);
void display(Node *p);

void main() {
	FILE *f1, *f2, *fout;
	int choice;
	float key;
	char sections[MAXSC][40] = {"Read from file", "Search", "Best results", "Save to file", "Merge list", "Exit"};

	slist *list1, *list2, *excellent, *merge;

	do {
		choice = getMenu(sections, MAXSC);
		switch (choice) {
		case 1:
			list1 = iniList();
			list2 = iniList();
			readData(f1, "input.txt", list1);
			readData(f2, "input2.txt", list2);
			break;
		case 2:
			printf("Type in the key to search: ");
			scanf("%f", &key);
			search(list1, key);
			search(list2, key);
			break;
		case 3:
			excellent = iniList();
			printf("Excellent students: \n");
			best(list1, excellent);
			best(list2, excellent);
			traverse(excellent, display);
			break;
		case 4:
			savetoFile(excellent, fout, "output.txt");
			printf("Done!\n");
			freeList(excellent);
			break;
		case 5:
			merge = iniList();
			saveList(list1, merge, insertNode);
			saveList(list2, merge, insertNode);
			traverse(merge, display);
			freeList(merge);
			break;
		case MAXSC:
			freeList(list1);
			freeList(list2);
			break;
		default:
			printf("Choice must be from 1 to %d\n", MAXSC);
			break;
		}
	} while (choice != MAXSC);
}

void readData(FILE *f, char fileName[], slist *list) {
	if ((f = fopen(fileName, "r")) == NULL)
	{
		printf("Can't open file %s\n", fileName);
		exit(1);
	}
	int i = 0, j;
	element_type table;
	char c;
	while (!feof(f))
		if ((c = fgetc(f)) == '\n')
			++i;
	rewind(f);
	for (j = 0; j < i / 2; ++j)
	{
		fscanf(f, "%[^\n]\n%f\n", table.name, &table.mark);
		printf(" %s: % f\n", table.name, table.mark);
		insertEnd(table, list);
	}

	if (i % 2 != 0)
	{
		fscanf(f, "%[^\n]\n", table.name);
		printf("Type in the mark for the last student : ");
		scanf(" %f", &table.mark);
		printf("Last student: \n");
		printf(" %s : %f\n", table.name, table.mark);
		insertEnd(table, list);
	}
	fclose(f);
}

void search(slist *list, float key)
{
	Node *p = list->root;
	int flag = 0;
	if (list->root == NULL)
	{
		printf("Empty list!\n");
		return;
	}
	while (p != NULL)
	{
		if (p->element.mark >= key)
		{
			printf("Found. %s: %f\n", p->element.name, p->element.mark);
			flag = 1;
		}
		p = p->next;
	}
	if (flag == 0)
		printf("Not found any sufficient result\n");
}

void best(slist *list, slist *excellent)
{
	Node *p = list->root;
	int flag = 0;
	if (list->root == NULL)
	{
		printf("Empty list!\n");
		return;
	}
	while (p != NULL)
	{
		if (p->element.mark >= 8.5)
		{
			insertEnd(p->element, excellent);
			flag = 1;
		}
		p = p->next;
	}
	if (flag == 0)
		printf("Not found any sufficient result\n");
}

//display a node
void display(Node *p) {
	printf("%s: %f- %p\n", p->element.name, p->element.mark, p);
}

