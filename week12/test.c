#include "sort.h"

void main() {
	FILE *f;
	int i = 0;
	int max = 0;

	f = fopen("input.txt", "r");

	while (!feof(f))
		if (fgetc(f) == '\n')
			++max;
	rewind(f);

	int a[max];
	for (i = 0; i < max; ++i)
		fscanf(f, "%d", &a[i]);
	
	// insertionSort(a, max);
	// printf("%-20s", "Insertion Sort: ");
	// display(a, max);

	// selectionSort(a, max);
	// printf("%-20s", "Selection Sort: ");
	// display(a, max);

	// printf("%-20s", "Heap Sort: ");
	// heapSort(a, max);
	// display(a, max);

	printf("%-20s", "Quick Sort: ");
	quickSort(a, 0, max - 1);
	display(a, max);
	fclose(f);
}