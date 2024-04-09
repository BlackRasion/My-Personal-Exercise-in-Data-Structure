#include <stdio.h>
#include <stdlib.h>


int* copylist(const int* unsortedlist, int length)
{
	int* list = (int*)malloc(sizeof(int) * length);
	for (int i = 0; i < length; i++) {
		list[i] = unsortedlist[i];
	}
	return list;
}

void displaylist(int* list, int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%d ", list[i]);
	}
	printf("\n");
}

//Function to exchange the values of two variables
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

//Insetion Sort
int* Insertion_sort(int* unsortedlist, int length)
{
	int* list = copylist(unsortedlist, length);
	for (int i = 1; i < length; i++) {
		int current = list[i];
		int j = i - 1;
		while (j >= 0 && current < list[j]) {
			list[j + 1] = list[j];
			j--;
		}
		list[j+1] = current;
	}
	return list;
}

//Binary Insertion Sort
int* binaryInsertion_sort(int* unsortedlist, int length)
{
	int* list = copylist(unsortedlist, length);
	for (int i = 1; i < length; i++) {
		int low = 0;
		int high = i - 1;
		int temp = list[i];

		while (low <= high) {
			int mid = (low + high) / 2;

			if (temp < list[mid]) high = mid - 1;
			else low = mid + 1;
		}
		int j = i - 1;
		while (j >= low) {
			list[j + 1] = list[j];
			j--;
		}
		if (temp > list[low]) list[low + 1] = temp;
		else list[low] = temp;
	}

		return list;
}

//Bubble Sort
int* bubble_sort(int* unsortedlist, int length)
{
	int* list = copylist(unsortedlist, length);
	for (int i = 0; i < length - 1; i++) {
		for (int j = 0; j < length - 1 - i; j++) {
			if (list[j] > list[j + 1]) {
				swap(&list[j], &list[j + 1]);
			}
		}
	}
	return list;
}

//Quick Sort
int partition(int* list, int low, int high)
{
	int pivot = list[high];
	int index = low - 1;
	for (int j = low; j < high; j++) {
		if (list[j] < pivot) {
			index++;
			swap(&list[index], &list[j]);
		}
	}
	index++;
	swap(&list[index], &list[high]);
	return index;
}

void quick_sortRec(int* list, int low, int high)
{
	if (low < high) {
		int pivot = partition(list, low, high);
		quick_sortRec(list, low, pivot - 1);
		quick_sortRec(list, pivot + 1, high);
	}

}

int* quick_sort(int* unsortedlist, int length)
{
	int* list = copylist(unsortedlist, length);
	int low = 0;
	int high = length - 1;
	quick_sortRec(list, low, high);
	return list;
}

//Simple Selection Sort
int* selection_sort(int* unsortedlist, int length)
{
	int* list = copylist(unsortedlist, length);
	for (int i = 0; i < length; i++) {
		int minIndex = i;
		for (int j = i + 1; j < length; j++) {
			if (list[minIndex] > list[j]) minIndex = j;
		}
		swap(&list[i], &list[minIndex]);
	}
	return list;

}

//Heap Sort
void heapify(int* list, int n, int root_index)
{
	int maxIndex = root_index;
	int left = root_index * 2 + 1;
	int right = root_index * 2 + 2;

	if (left <n && list[left] > list[maxIndex]) maxIndex = left;
	if (right < n && list[right] > list[maxIndex])maxIndex = right;
	if (maxIndex != root_index) {
		swap(&list[root_index], &list[maxIndex]);
		heapify(list, n, maxIndex);
	}
}

int* heap_sort(int* unsortedlist, int length)
{
	int* list = copylist(unsortedlist, length);
	for (int i = length / 2 - 1; i >= 0; i--) {
		heapify(list, length, i);
	}

	for (int i = length - 1; i > 0; i--) {
		swap(&list[0], &list[i]);
		heapify(list, i, 0);
	}

	return list;
}


int main()
{
	//give and display a unsortedlist
	int unsortedlist1[] = { 8,3,6,5,7,0,1,2,9,4 };
	int length = sizeof(unsortedlist1) / sizeof(unsortedlist1[0]);
	printf("Before sort:\n");
	displaylist(unsortedlist1,length);

	//InsertionSort
	int* InsertionSortList = Insertion_sort(unsortedlist1, length);
	printf("InsertionSort:\n");
	displaylist(InsertionSortList, length);

	//BinaryInsertionSort
	int* BinaryInsertionSortList = binaryInsertion_sort(unsortedlist1, length);
	printf("BinaryInsertionSort:\n");
	displaylist(BinaryInsertionSortList, length);

	//BubbleSort 
	int* BubbleSortList = bubble_sort(unsortedlist1, length);
	printf("BubbleSort:\n");
	displaylist(BubbleSortList, length);

	//QuickSort
	int* quickSortList = quick_sort(unsortedlist1, length);
	printf("QuickSort:\n");
	displaylist(quickSortList,length);

	//SelectionSort
	int* SelectionSortList = selection_sort(unsortedlist1, length);
	printf("SelectionSort:\n");
	displaylist(SelectionSortList, length);

	//HeapSort
	int* HeapSortList = heap_sort(unsortedlist1, length);
	printf("HeapSort:\n");
	displaylist(HeapSortList, length);

	return 0;
}