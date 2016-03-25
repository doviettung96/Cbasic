#include "phone.h"
#include "dlink.h"

int result;


int main(int argc, char **argv) {
	dlist *dlist;
	dlist *dlist2;
	int choice;
	int i = 0;
	int numData;
	FILE *fin, *fout;
	int select = 0;
	int startFrom, numSplit; // where to split and the length of splitting list
	char fileName[15]; //file name for output data
	char textName1[20], textName2[20]; // file name for split lists

	char sections [MAX][40] = {"Import from phonebook.dat", "Display (traverse)", "Add new contact (insert before/after)",
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
			dlist = (dlist *)malloc(sizeof(dlist));
			if (dlist == NULL) {
				fprintf(stderr, "ERROR : Allocated memory failed !!\n");
				exit(1);
			}
			dlist2 = (dlist *)malloc(sizeof(dlist));
			if (dlist2 == NULL) {
				fprintf(stderr, "ERROR : Allocated memory failed !!\n");
				exit(1);
			}
			iniList(dlist);
			iniList(dlist2);

			if ((fin = fopen(argv[1], "rb")) == NULL)
			{
				printf("Can't open file %s\n", argv[1]);
				exit(1);
			}
			fseek(fin, 0, SEEK_END);
			numData = ftell(fin) / sizeof(element_type);
			rewind(fin);
			result = import(fin, numData);
			for (i = 0; i < result; ++i)
				insertEnd(contact[i], dlist);
			// printData();
			fclose(fin);
			break;
		case 2:
			traverse(dlist);
			break;
		case 3:
			printf("Enter 0 to insert before, 1 to insert after: ");
			scanf("%d", &select);
			while (getchar() != '\n');
			if (select == 0)
				insertBefore(list->root, typeHand(), dlist);
			else
				insertEnd(typeHand(), dlist);
			break;
		case 4: printf("Position to insert after (1 means root element): ");
			scanf("%d", &select);
			printf("Type in the data to insert\n");
			while (getchar() != '\n');
			if (select < numData)
				// list->cur = insertAtPosition(list, typeHand(), select);
				insertAfter(findNode(contact[select - 1], dlist), typeHand(), dlist);
			else
				insertEnd(typeHand(), dlist);
			break;
		case 5: printf("Position to delete: (1 means root element)");
			scanf("%d", &select);
			// deleteAtPosition(list, select);
			delNode(findNode(contact[select - 1], dlist), dlist);
			break;
		case 6: delNode(list->cur, dlist);
			break;
		case 7: delNode(list->root, dlist);
			break;
		case 8: searchName();
			while (1) {

				printf("Update for position number (type -1 to stop updating): ");
				scanf("%d", &select);
				while (getchar() != '\n');
				if (select == -1)
					break;

				insertAfter(findNode(contact[select - 1], dlist), typeHand(), dlist);

				delNode(findNode(contact[select - 1], dlist), dlist);
				printf("Update success\n");
			}
			break;
		case 9:
			printf("Type in where to start (range from 0 to end of the dlist): ");
			scanf("%d", &startFrom);
			printf("Length of splitting: ");
			scanf("%d", &numSplit);
			if (listLength(dlist) > startFrom + numSplit)
				splitList(startFrom, numSplit, dlist, dlist2);
			else
				splitList(startFrom, listLength(dlist) - startFrom, dlist, dlist2);
			while (getchar() != '\n');
			printf("Now type in 2 file name to save the new lists\n");
			printf("File 1: ");
			scanf("%s", textName1);
			printf("File 2: ");
			scanf("%s", textName2);
			checkList(dlist2, textName1); //result of splitList
			checkList(dlist, textName2);
			break;
		case 10: list_reverse(dlist);
			break;
		case 11:
			printf("Type in the file name\n");
			scanf("%s", fileName);
			if ((fout = fopen(fileName, "w + t")) == NULL)
			{
				printf("Can't open file %s\n", fileName);
				exit(1);
			}
			savetoFile(fout, dlist);
			break;
		case MAX:
			freeList(dlist);
			freeList(dlist2);
			exit(1);
		default: printf("Invalid choice. It must be from 1 to %d\n", MAX); break;
		}
	} while (choice != MAX);
	return 0;
}
