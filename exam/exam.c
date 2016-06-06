#include "bst.h"
#include "menu.h"
#include "strapi.h"

#define MAXSC 4

void display(tree_type tree);
void readData(FILE *f, char fileName[], tree_type *tree);
void saveTree(tree_type tree, FILE *f);
void saveinOrder(tree_type tree, FILE *f, void (*order)(tree_type, FILE *));

void main() {
	FILE *f1, *f2;
	int choice;
	char *s;
	int i = 0, j = 0;
	long numspace = 1;
	tree_type temp;
	char **result;
	int flag = 0;
	element_type new;
	char sections[MAXSC][40] = {"Read from data.txt", "Print in increasing order", "Translate", "Exit and save"};
	tree_type tree;
	makeNullTree(&tree);

	do {
		choice = getMenu(sections, MAXSC);
		switch (choice)
		{
		case 1:
			readData(f1, "data.txt", &tree);
			break;
		case 2:
			inOrder(tree, display);
			break;
		case 3:
			printf("Type in a string: ");
			s = (char *)malloc(sizeof(char) * 100);
			while (getchar() == '\n');
			scanf("%[^\n]", s);



			for (i = 0; i < strlen(s); ++i)
			{
				if (s[i] == ' ')
					numspace++;
				else if (isupper(s[i]))
					tolower(s[i]);
			}
			// printf("After validate: %s\n", s);
			result = (char **)malloc(sizeof(char*)*numspace);
			result = strsplit(s, " ", &numspace);
			printf("The word after split: \n");
			for (i = 0; i < numspace; ++i)
				printf("%s\n", result[i]);

			printf("\nNow this sentence means: \n");
			for (i = 0; i < numspace; ++i)
			{
				temp = search(tree, result[i]);

				if (temp == NULL)
				{
					printf("Can't find the word (%s) in dictionary. Please type it:\n", result[i]);
					scanf("%s", new.word);
					printf("Its meaning: ");
					scanf("%s", new.meaning);
					insert(&tree, new);
				}
				else
					printf("%s\n", temp->info.meaning);
			}
			free(s);
			free(result);
			break;
		case MAXSC:
			if ((f2 = fopen("data.txt", "w")) == NULL)
			{
				printf("Can't open file %s\n", "data.txt");
				exit(1);
			}
			saveinOrder(tree, f2, saveTree);
			fclose(f2);
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
	int flag = 0;
	element_type entry;
	while (!feof(f))
	{
		fscanf(f, "%s\t%s\n", entry.word, entry.meaning);
		// printf("%d: %s\n", entry.word, entry.meaning);
		insert(tree, entry);
	}
	fclose(f);
}

void saveTree(tree_type tree, FILE *f) {
	fprintf(f, "%s\t%s\n", tree->info.word, tree->info.meaning);
}

void display(tree_type tree) {
	printf("%s\t%s\n", tree->info.word, tree->info.meaning);
}

void saveinOrder(tree_type tree, FILE *f, void (*order)(tree_type, FILE *))
{
	if (tree != NULL)
	{
		saveinOrder(tree->left, f, order);
		order(tree, f);
		saveinOrder(tree->right, f, order);
	}
}



// char **splitString() {
// 	char s[30];
// 	int i = 0;
// 	int j = 0;
// 	printf("Type in a string: \n");
// 	scanf("%[^\n]", s);

// 	while(s[i] != '\0')
// 		if(s[i] == ' ')
// 			++i;

// 	char result[i][10];
// 	return result;
// }

