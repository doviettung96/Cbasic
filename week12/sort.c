#include "sort.h"
#include <time.h>
#include "menu.h"

#define MAX 2000000
#define MAXSC 6

void main() {
	time_t t1, t2;
	srand(time(NULL));
	int i = 0;
	int choice;
	int a[MAX];
	char sections[MAXSC][40] = {"Generating number", "Insertion Sort", "Selection Sort", "Bubble Sort", "Heap Sort", "Exit"};
	do {
		choice = getMenu(sections, MAXSC);
		switch (choice) {
		case 1:
			for (i = 0; i < MAX; ++i)
				a[i] = rand() % MAX;
			break;

		case 2:
			time(&t1);
			insertionSort(a, MAX);
			time(&t2);
			printf("Duration: %ld\n", t2 - t1);
			break;
		case 3:
			time(&t1);
			selectionSort(a, MAX);
			time(&t2);
			printf("Duration: %ld\n", t2 - t1);
			break;
		case 4:
			time(&t1);
			bubbleSort(a, MAX);
			time(&t2);
			printf("Duration: %ld\n", t2 - t1);
			break;
		case 5:
			time(&t1);
			heapSort(a, MAX);
			time(&t2);
			printf("Duration: %ld\n", t2 - t1);
			break;
		case MAXSC: break;
		default: printf("The choice must be from 1 to %d\n", MAXSC); break;
		}
	} while (choice != MAXSC);
}