#ifndef _SORT_H_
#define _SORT_H_

#include "link.h"
#include <stdio.h>
#include <stdlib.h>


#define N 1000

void swap(element_type *a, element_type *b);
void insertionSort(element_type a[], int size);
void selectionSort(element_type a[], int size);
void bubbleSort(element_type a[], int size);
void maxHeapify(element_type a[], int n, int i);
void heapSort(element_type a[], int n);
int partition(element_type a[], int low, int high);
void quickSort(element_type a[], int low, int high);
void merge(element_type u[], int m, element_type v[], int n, element_type a[]);
void mergeSort(element_type a[], int n);
void display(element_type a[], int n);
#endif