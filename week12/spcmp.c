#include <time.h>
#include "sort.h"

#define MAX 1000000

void main() {
	srand(time(NULL));
	int i = 0;
	time_t t1, t2;
	element_type a[MAX];
	for (i = 0; i < MAX; ++i)
		a[i] = rand() % MAX;

	// time(&t1);
	// insertionSort(a, MAX);
	// time(&t2);
	// printf("%-20s", "Insertion Sort: ");
	// printf("Duration in second: %ld\n", t2 - t1);

	
	time(&t1);
	heapSort(a, MAX);
	time(&t2);
	printf("%-20s", "Heap Sort: ");	
	printf("Duration in second: %ld\n", t2 - t1);
}