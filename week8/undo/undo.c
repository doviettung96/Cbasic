#include "stacklib.h"
#include "menu.h"

#define MAX 5

void Add(stack_type *store, stack_type *undo, element_type input);
void Take(stack_type *store, stack_type *undo);

void main() {
	stack_type *store;
	stack_type *undo;
	int choice;
	element_type input, output, check, cmd1, cmd2;

	char sections[MAX][40] = {"Push 1 string", "Indicate top", "Pop 1 string", "Undo", "Exit"};
	store = iniStack(store);
	undo = iniStack(undo);

	do {
		choice = getMenu(sections, MAX);
		switch (choice)
		{
		case 1:
			while (getchar() != '\n');
			printf("Type in a string: ");
			scanf("%s", input.s);
			Add(store, undo, input);
			break;
		case 2:
			if (empty(store))
				printf("Stack empty\n");
			else {
				printf("Top of the stack is: \n");
				printf("%s\n", store->top->element.s);
			}
			break;
		case 3: printf("Pop a string from the stack\n");
			if (empty(store))
				printf("Stack empty\n");
			else
				Take(store, undo);
			break;
		case 4:
			while (getchar() != '\n');
			printf("Type in %s\n", "UNDO");
			scanf("%s", check.s);
			if (strcmp(check.s, "UNDO") == 0)
			{
				if (!empty(undo))
				{
					cmd1 = pop(undo);
					cmd2 = pop(undo);
					printf("cmd1 = %s\n", cmd1.s);
					printf("cmd2 = %s\n", cmd2.s);
					if (strcmp(cmd2.s, "PUSH") == 0)
						if (!empty(store))
							output = pop(store);
					if (strcmp(cmd2.s, "POP") == 0)
						push(cmd1, store);
				}
			}
			else
				printf("Invalid command\n");
			break;
		case MAX: exit(1);
		default: printf("The choice must be from 1 to %d\n", MAX);
			break;
		}
	} while (choice != MAX);
}

void Add(stack_type *store, stack_type *undo, element_type input) {
	element_type tem;
	push(input, store);
	strcpy(tem.s, "PUSH");
	push(tem, undo);
	push(input, undo);
}

void Take(stack_type *store, stack_type *undo) {
	element_type tem, output;
	output = pop(store);
	strcpy(tem.s, "POP");
	push(tem, undo);
	push(output, undo);

}