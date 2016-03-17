#include "phone.h"
#include "link2.h"

int result;


int main(int argc, char **argv) {
	slist *list;
	slist *list2;
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
			list = (slist *)malloc(sizeof(slist));
			if (list == NULL) {
				fprintf(stderr, "ERROR : Allocated memory failed !!\n");
				exit(1);
			}
			list2 = (slist *)malloc(sizeof(slist));
			if (list2 == NULL) {
				fprintf(stderr, "ERROR : Allocated memory failed !!\n");
				exit(1);
			}
			iniList(list);
			iniList(list2);

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
				insertEnd(contact[i], list);
			// printData();
			fclose(fin);
			break;
		case 2:
			traverse(list);
			break;
		case 3:
			printf("Enter 0 to insert before, 1 to insert after: ");
			scanf("%d", &select);
			while (getchar() != '\n');
			if (select == 0)
				insertBefore(list->root, typeHand(), list);
			else
				insertEnd(typeHand(), list);
			break;
		case 4: printf("Position to insert after (1 means root element): ");
			scanf("%d", &select);
			printf("Type in the data to insert\n");
			while (getchar() != '\n');
			if (select < numData)
				// list->cur = insertAtPosition(list, typeHand(), select);
				insertAfter(findNode(contact[select - 1], list), typeHand(), list);
			else
				insertEnd(typeHand(), list);
			break;
		case 5: printf("Position to delete: (1 means root element)");
			scanf("%d", &select);
			// deleteAtPosition(list, select);
			delNode(findNode(contact[select - 1], list), list);
			break;
		case 6: delNode(list->cur, list);
			break;
		case 7: delNode(list->root, list);
			break;
		case 8: searchName();
			while (1) {

				printf("Update for position number (type -1 to stop updating): ");
				scanf("%d", &select);
				while (getchar() != '\n');
				if (select == -1)
					break;

				insertAfter(findNode(contact[select - 1], list), typeHand(), list);

				delNode(findNode(contact[select - 1], list), list);
				printf("Update success\n");
			}
			break;
		case 9:
			printf("Type in where to start (range from 0 to end of the list): ");
			scanf("%d", &startFrom);
			printf("Length of splitting: ");
			scanf("%d", &numSplit);
			if (listLength(list) > startFrom + numSplit)
				splitList(startFrom, numSplit, list, list2);
			else
				splitList(startFrom, listLength(list) - startFrom, list, list2);
			while (getchar() != '\n');
			printf("Now type in 2 file name to save the new lists\n");
			printf("File 1: ");
			scanf("%s", textName1);
			printf("File 2: ");
			scanf("%s", textName2);
			checkList(list2, textName1); //result of splitList
			checkList(list, textName2);
			break;
		case 10: list_reverse(list);
			break;
		case 11:
			printf("Type in the file name\n");
			scanf("%s", fileName);
			if ((fout = fopen(fileName, "w + t")) == NULL)
			{
				printf("Can't open file %s\n", fileName);
				exit(1);
			}
			savetoFile(fout, list);
			break;
		case MAX:
			freeList(list);
			freeList(list2);
			exit(1);
		default: printf("Invalid choice. It must be from 1 to %d\n", MAX); break;
		}
	} while (choice != MAX);
	return 0;
}