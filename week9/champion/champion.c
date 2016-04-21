#include "bintree.h"

#define MAX 16

void showArray(tree_type *Tarray);
void savetoFile(tree_type tree, FILE *fout);
void display(tree_type tree);
tree_type *getData(FILE *fin);
tree_type match(tree_type *Tarray);

void main(int argc, char **argv) {
	FILE *fin, *fout;
	tree_type tree;
	tree_type *Tarray;
	makeNullTree(&tree);


	if ((fin = fopen(argv[1], "r")) == NULL)
	{
		printf("Can't open file %s\n", argv[1]);
		exit(1);
	}

	if ((fout = fopen(argv[2], "w")) == NULL)
	{
		printf("Can't open file %s\n", argv[2]);
		exit(1);
	}

	Tarray = getData(fin);
	tree = match(Tarray);
	showArray(Tarray);
	// preOrder(tree, fout, savetoFile);
	inOrder(tree, display);
	// freeTree(Tarray);
	// freeTree(&tree);
	fclose(fin);
	fclose(fout);
}

void display(tree_type tree) {
	printf("%s\n", (char*)tree->info);
}

void savetoFile(tree_type tree, FILE *fout) {
	fprintf(fout, "%s\n", (char *)tree->info);
}

void showArray(tree_type *Tarray) {
	int i;
	for (i = 0; i < MAX; i++) {
		printf("\t%s \n", (char *)Tarray[i]->info);
	}
}

tree_type *getData(FILE *fin) {
	tree_type *Tarray = (tree_type *)malloc(sizeof(tree_type));
	int i = 0;
	char *s;
	while (i < MAX)
	{
		s = (char *)malloc(sizeof(char));
		fscanf(fin, "%s\n", s);
		Tarray[i] = makeTNode(s);
		++i;
	}
	free(s);
	return Tarray;
}

tree_type match(tree_type *Tarray) {
	int n = MAX;
	tree_type temp[MAX];
	tree_type root;
	int i;
	int index;
	char *winner;
	makeNullTree(&root);

	for (i = 0; i < MAX; ++i)
		temp[i] = Tarray[i];
	while (n != 1)
	{
		n /= 2;
		i = 0;
		index = 0;
		while (i < n * 2)
		{
			int rd = rand() % 2;
			winner = (char*)temp[i + rd]->info;
			root = createFrom2(winner, temp[i], temp[i + 1]);
			temp[index] = root;
			i += 2;
		}
	}

	return temp[0];
}
