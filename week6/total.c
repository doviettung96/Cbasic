#include "tgdd.h"
#include "link.h"

// #define NUMDATA 138
int result;

int main(int argc, char **argv) {
	int choice;
	int i = 0;
	int numData;
	FILE *fin, *fout;
	int select = 0;
	int startFrom, numSplit; // where to split and the length of splitting list
	char fileName[15]; //file name for output data
	char textName1[20], textName2[20]; // file name for split lists

	char sections [MAX][40] = {"Import from nokiaDB.dat", "Display (traverse)", "Add new phone (insert before/after)",
	                           "Insert a position" , "Delete a position", "Delete current",
	                           "Delete first", "Search and Update", "Divide and Extract",
	                           "Reverse list", "Save to file", "Exit (free)"
	                          };

	do {
		choice = getMenu(sections, MAX);
		switch (choice) {
		case 1:

			// if ((fin = fopen(argv[1], "r")) == NULL)
			// {
			// 	printf("Can't open file %s\n", argv[1]);
			// 	exit(1);
			// }
			// if ((fout = fopen(argv[2], "wb")) == NULL)
			// {
			// 	printf("Can't open file %s\n", argv[2]);
			// 	exit(1);
			// }

			// numData = importDB(fin, fout);

			// fclose(fin);
			// fclose(fout);


			if ((fin = fopen(argv[1], "rb")) == NULL)
			{
				printf("Can't open file %s\n", argv[1]);
				exit(1);
			}
			fseek(fin, 0, SEEK_END);
			numData = ftell(fin) / sizeof(element_type);
			rewind(fin);
			result = importfromDB(fin, numData);
			for (i = 0; i < result; ++i)
				insertEnd(parr[i], root, last);
			// printData();
			fclose(fin);
			break;
		case 2:
			display(root);
			break;
		case 3:
			printf("Enter 0 to insert before, 1 to insert after: ");
			scanf("%d", &select);
			while (getchar() != '\n');
			if (select == 0)
				insertBefore(root, typeHand(), root);
			else
				insertEnd(typeHand(), root, last);
			break;
		case 4: printf("Position to insert after: ");
			scanf("%d", &select);
			printf("Type in the data to insert\n");
			if (select < numData)
				insertAfter(findNode(parr[select - 1], root), typeHand(), root, last);
			else
				insertEnd(typeHand(), root, last);
			break;
		case 5: printf("Position to delete: ");
			scanf("%d", &select);
			delNode(findNode(parr[select - 1], root), root, last);
			break;
		case 6: delNode(last, root, last);
			break;
		case 7: delNode(root, root, last);
			break;
		case 8: searchModel();
			do {
				printf("Update for position number (type -1 to stop updating): ");
				scanf("%d", &select);
				insertAfter(findNode(parr[select - 1], root), typeHand(), root, last);
				delNode(findNode(parr[select], root), root, last);
				printf("Update success\n");
			} while (select != -1);
			break;
		case 9:
			printf("Type in where to start (range from 0 to end of the list): ");
			scanf("%d", &startFrom);
			printf("Length of splitting: ");
			scanf("%d", &numSplit);
			if (numData > startFrom + numSplit)
				splitList(startFrom, numSplit, root);
			else
				splitList(startFrom, numData - startFrom, root);
			while (getchar() != '\n');
			printf("Now type in 2 file name to save the new lists\n");
			printf("File 1: ");
			scanf("%s", textName1);
			printf("File 2: ");
			scanf("%s", textName2);
			checkList(root2, textName1); //result of splitList
			checkList(root, textName2);
			break;
		case 10: list_reverse(root);
			break;
		case 11:

			printf("Type in the file name\n");
			scanf("%s", fileName);
			if ((fout = fopen(fileName, "w + b")) == NULL)
			{
				printf("Can't open file %s\n", fileName);
				exit(1);
			}
			savetoFile(fout, root);
			break;
		case MAX: exit(1);
		default: printf("Invalid choice. It must be from 1 to %d\n", MAX); break;
		}
	} while (choice != MAX);
	return 0;
}