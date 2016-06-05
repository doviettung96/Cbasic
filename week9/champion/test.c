#include "bintree.h"
#include "queue.h"
#include "time.h"

#define MAX 16

void display(tree_type tree);
void buildTree(queue_type *q, int max);

void main() {
	FILE *fin;
	int i = 0;
	element_type input;
	int max;
	TNode *temp;
	tree_type tree;
	queue_type *q = iniQueue();
	makeNullTree(&tree);

	if ((fin = fopen("input.txt", "r")) == NULL)
	{
		printf("Can't open file %s\n", "input.txt");
		exit(1);
	}

	for (i = 0; i < MAX; ++i)
	{
		fscanf(fin, "%s\n", input.s);
		temp = makeTNode(input);
		enQueue(temp, q);
	}

	for (max = MAX / 2; max > 0; max = max / 2)
		buildTree(q, max);

	tree = deQueue(q);
	
	inOrder(tree, display);

	fclose(fin);
	freeTree(tree);
	removeQueue(q);
}

void display(tree_type tree) {
	printf("%s ", tree->info.s);
}

void buildTree(queue_type *q, int max)
{
	int i = 0;
	TNode *x, *y;
	int rd;
	srand(time(NULL));
	for (i = 0; i < max; ++i)
	{
		rd = rand() % 2;
		x = deQueue(q);
		y = deQueue(q);
		if (rd == 0)
		{
			x->left = x;
			x->right = y;
			enQueue(x, q);
		}
		else
		{
			y->left = x;
			y->right = y;
			enQueue(y, q);
		}
	}
	free(x);
	free(y);
}
