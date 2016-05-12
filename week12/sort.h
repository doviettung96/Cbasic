#include <stdio.h>
#include <stdlib.h>

typedef int element_type;

void swap(element_type *a, element_type *b)
{
	element_type temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void insertionSort(element_type a[], int size)
{
	int i, j;
	element_type last;
	for (i = 1; i < size; ++i)
	{
		last = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > last)
		{
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = last;
	}
}

void selectionSort(element_type a[], int size)
{
	int i, j, temp;
	int min; //index of the minimum
	for (i = 0; i < size - 1; ++i)
	{
		min = i;
		for (j = i + 1; j < size; ++j)
			if (a[j] < a[min])
				min = j;
		swap(&a[i], &a[min]);
	}
}

void bubbleSort(element_type a[], int size)
{
	int i, j, temp;
	for(i = size - 1; i >= 0; --i)
		for(j = 1; j <= i; ++j)
			if(a[j - 1] > a[j])
				swap(&a[j - 1], &a[j]);
}

void maxHeapify(element_type a[], int n, int i)
{
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	element_type temp = i;

	if (left < n && a[left] > a[temp])
		temp = left;

	if (right < n && a[right] > a[temp])
		temp = right;

	if (temp != i)
	{
		swap(&a[i], &a[temp]);
		maxHeapify(a, n, temp);
	}
}

void heapSort(element_type a[], int n) {
	int i;
	for (i = n / 2 - 1; i >= 0; --i)
		maxHeapify(a, n, i);
	for (i = n - 1; i >= 0; --i)
	{
		swap(&a[0], &a[i]);
		maxHeapify(a, i, 0);
	}
}

int partition(element_type a[], int low, int high)
{
	element_type pivot = a[high];
	int i = low - 1;
	int j;
	for (j = low; j <= high - 1; ++j)
		if (a[j] <= pivot)
		{
			i++;
			swap(&a[i], &a[j]);
		}
	swap(&a[i + 1], &a[high]);
	return i + 1;
}

void quickSort(element_type a[], int low, int high)
{
	int p;
	if (low < high)
	{
		p = partition(a, low, high);
		quickSort(a, low, p - 1);
		quickSort(a, p + 1, high);
	}
}

void display(element_type a[], int n)
{
	int i;
	for (i = 0; i < n; ++i)
		printf("%d ", a[i]);
	printf("\n");
}