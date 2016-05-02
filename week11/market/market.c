#include "bst.h"

void display(tree_type tree);

void main()
{
	FILE *f;
	tree_type tree;
	element_type input;
	tree_type temp;
	int tp, dt, mm;
	if ((f = fopen("input.txt", "r")) == NULL)
	{
		printf("Can't open file %s\n", "input.txt");
		exit(1);
	}
	makeNullTree(&tree);
	while (!feof(f))
	{
		fscanf(f, "%s %[^-]", input.ms, input.name);
		input.money = 0;
		input.tp = 0;
		input.dt = 0;
		input.mm = 0;
		fscanf(f, "%d %d %d", &tp, &dt, &mm);
		if(tp > 0)
			input.tp++;
		if(dt > 0)
			input.dt++;
		if(mm > 0)
			input.mm++;
		input.money = input.money + tp + dt + mm;
		temp = search(tree, input.ms);
		if(temp == NULL)
			insert(&tree, input);
		else
		{
			input.money += temp->info.money;
			input.tp += temp->info.tp;
			input.dt += temp->info.dt;
			input.mm += temp->info.mm;
			delete(&tree, input.ms);
			insert(&tree, input);
		}
	}
	inOrder(tree, display);
	fclose(f);
	freeTree(tree);
}

void display(tree_type tree)
{
	printf("%-20s %-30s %-9d %-2d %-2d %-2d\n", tree->info.ms, tree->info.name, tree->info.money, tree->info.tp, tree->info.dt, tree->info.mm);
}