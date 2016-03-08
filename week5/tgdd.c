#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

typedef struct phone_inf {
	char model[30];
	int storage;
	float screensize;
	int price;
} phone_inf;

int getMenu(char sections[][30], int maxsection);
int importDB(FILE *fin, FILE *fout);
int importfromDB(FILE *fin, int numLine);
void printData();
void searchModel();

phone_inf *parr; //phone array
int result;

void main(int argc, char **argv) {
	int numLine;
	FILE *fin, *fout;
	char finName[15], foutName[15];
	strcpy(finName, argv[1]);
	strcpy(foutName, argv[2]);
	int choice;
	char sections [MAX][30] = {"Import DB from text", "Import from DB", "Print all Nokia database", "Search phone by model", "Exit"};


	do {
		choice = getMenu(sections, MAX);
		switch (choice) {
		case 1:

			if ((fin = fopen(argv[1], "r")) == NULL)
			{
				printf("Can't open file %s\n", argv[1]);
				exit(1);
			}
			if ((fout = fopen(argv[2], "wb")) == NULL)
			{
				printf("Can't open file %s\n", argv[2]);
				exit(1);
			}

			numLine = importDB(fin, fout);
			fclose(fin);
			fclose(fout);
			break;
		case 2:
			fout = fopen(argv[2], "rb");

			result = importfromDB(fout, numLine);
			fclose(fout);
			break;
		case 3: printData(); break;
		case 4: searchModel(); break;
		case 5: exit(1);
		default: printf("Invalid choice. It must be from 1 to %d\n", MAX); break;
		}
	} while (choice != MAX);
}

int getMenu(char sections[MAX][30], int maxsection) {
	int choice;
	printf("\n");
	for (int i = 0; i < maxsection; ++i)
		printf("%d. %s\n", i + 1, sections[i]);
	printf("Your choice: ");
	scanf("%d", &choice);
	printf("\n");
	return choice;
}

int importDB(FILE *fin, FILE *fout) {
	int i = 0;
	int numLine = 0;
	char line[10000];

	while (fgets(line, 10000, fin) != NULL)
		numLine++;
	rewind(fin);
	parr = (phone_inf*)malloc(numLine * sizeof(phone_inf));
	for (i = 0; i < numLine; ++i)
		fscanf(fin, "%[^|]|%d|%f|%d\n", parr[i].model, &parr[i].storage, &parr[i].screensize, &parr[i].price);
	printf("ImportDB success\n\n");
	return fwrite(parr, sizeof(phone_inf), numLine, fout);
}

//import data from DB
int importfromDB(FILE *f, int numLine) {
	int result; // number of lines have been read
	int readMode; //readMode = 0 (all), = 1 (partially reading)

	int startFrom; //startFrom = 0 (begin), = 1 (end)
	int partNum; //number of line to read partially from beginning or end
	int position; //position where it begin to read

	do {
		printf("Choose 0 for read all data, 1 for read partially: ");
		scanf("%d", &readMode);
		if (readMode != 1 && readMode != 0)
			printf("Wrong choice of reading mode. Choose again\n");
	} while (readMode != 1 && readMode != 0);
	if (readMode == 0)
	{
		parr = (phone_inf*)malloc(numLine * sizeof(phone_inf));
		result = fread(parr, sizeof(phone_inf), numLine, f);
		printf("\nRead all data success\n");
		rewind(f);
	}
	else
	{
		do {
			printf("Choose 0 for read from beginning, 1 for from end: ");
			scanf("%d", &startFrom);
			if (startFrom != 1 && startFrom != 0)
				printf("Wrong choice of starting point. Choose again\n");
		} while (startFrom != 1 && startFrom != 0);



		printf("Input the position to start: ");
		scanf("%d", &position);
		do {
			printf("You want to read ? lines from the position: ");
			scanf("%d", &partNum);
			if (partNum <= 0)
				printf("Number of line must be positive\n");
		} while (partNum <= 0);

		parr = (phone_inf*)malloc(sizeof(phone_inf) * partNum);
		if (startFrom == 0)
		{
			if (fseek(f, sizeof(phone_inf) * (position - 1), SEEK_SET) != 0)
				printf("Fseek failed!\n");
			else
				result = fread(parr, sizeof(phone_inf), partNum, f);
			printf("\nRead from beginning success\n");
			rewind(f);
		}
		else
		{
			if (fseek(f, -sizeof(phone_inf) * position, SEEK_END) != 0)
				printf("Fseek failed!\n");
			else
				result = fread(parr, sizeof(phone_inf), partNum, f);
			printf("\nRead from the end success\n");
			rewind(f);
		}
	}
	printf("\n");
	return result;
	free(parr);
}

void printData() {
	int pageNum = 0;
	printf("\nDatabase printing\n");
	if (result < 20)
		for (int i = 0; i < result; ++i)
			printf("%-30s|%-3d|%-4.2f|%-8d\n", parr[i].model, parr[i].storage, parr[i].screensize, parr[i].price);
	else
	{
		int curNum; //the line which is the end of the corresponding page 
		do {
			curNum = 20 + 20 * pageNum;
			if (curNum >= result)
				curNum = result;
			printf("\n\nPage number %d\n\n", pageNum + 1);
			for (int i = pageNum * 20; i < curNum; ++i)
				printf("%-30s|%-3d|%-4.2f|%-8d\n", parr[i].model, parr[i].storage, parr[i].screensize, parr[i].price);
			pageNum++;
		} while (curNum < result);
	}
}

void searchModel() {
	char s[40];
	printf("\nSearch by phone model\n");
	printf("Type in the model\n");
	while (getchar() != '\n');
	scanf("%[^\n]", s);
	printf("\nSearch result: \n");
	for (int i = 0; i < result; ++i)
		if (strstr(parr[i].model, s) != NULL)
			printf("%-30s|%-3d|%-4.2f|%-8d\n", parr[i].model, parr[i].storage, parr[i].screensize, parr[i].price);
}