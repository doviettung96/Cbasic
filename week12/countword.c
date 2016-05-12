#include "bst.h"
void display(tree_type tree);

void main() {
	FILE *f;
	tree_type temp;
	char s[20];
	f = fopen("para.txt", "r");
	tree_type tree;
	element_type entry;
	makeNullTree(&tree);

	while (!feof(f))
	{
		fscanf(f, "%s ", s);
		temp = search(tree, s);
		if (temp == NULL)
		{
			entry.count = 1;
			strcpy(entry.word, s);
			insert(&tree, entry);
		}
		else
			temp->info.count++;
	}

	inOrder(tree, display);
	freeTree(tree);

}

void display(tree_type tree)
{
	printf("%s %d\n", tree->info.word, tree->info.count);
}