#include <stdio.h>
#include <stdlib.h>

#define N 1000

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
	for (i = size - 1; i >= 0; --i)
		for (j = 1; j <= i; ++j)
			if (a[j - 1] > a[j])
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

// void merge(element_type a[], int n, int first, int mid, int last)
// {
// 	element_type temp[n];
// 	int first1 = first;
// 	int last1 = mid;
// 	int first2 = mid + 1;
// 	int last2 = last;
// 	int index = first1;
// 	for (; first1 <= last1 && first2 <= last2; ++index)
// 	{
// 		if (a[first1] < a[first2])
// 		{
// 			temp[index] = a[first1];
// 			++first1;
// 		}
// 		else
// 		{
// 			temp[index] = a[first2];
// 			++index;
// 		}
// 		for (; first1 <= last1; ++first1, ++index)
// 			temp[index] = a[first1];
// 		for (; first2 <= last2; ++first2, ++index)
// 			temp[index] = a[first2];
// 		for (index = first; index <= last; ++index)
// 			a[index] = temp[index];
// 	}
// }

// void mergeSort(element_type a[], int n, int first, int last)
// {
// 	int mid;
// 	if (first < last)
// 	{
// 		mid = (first + last) / 2;
// 		mergeSort(a, n, first, mid);
// 		mergeSort(a, n, mid + 1, last);
// 		merge(a, n, first, mid, last);
// 	}
// }

void merge(element_type u[], int m, element_type v[], int n, int a[])
{
	int i = 0, j = 0;
	int k = 0;
	while (k < m + n)
	{
		if (u[i] < v[j])
		{
			a[k] = u[i];
			++i;
		}
		else 
		{
			a[k] = v[j];
			++j;
		}
		++k;
	}
}

void mergeSort(element_type a[], int n)
{
	int i = 0, j = 0;
	int mid = n/ 2;
	element_type u[mid];
	element_type v[n - mid];
	if (n < N)
		selectionSort(a, n);
	else
	{
		for (i = 0; i < mid; ++i)
			u[i] = a[i];
		for (j = 0; j < n - mid; ++j, ++i)
			v[j] = a[i];

		mergeSort(u, mid);
		mergeSort(v, n - mid);
		merge(u, mid, v, n - mid, a);
	}
}

void display(element_type a[], int n)
{
	int i;
	for (i = 0; i < n; ++i)
		printf("%d ", a[i]);
	printf("\n");
}