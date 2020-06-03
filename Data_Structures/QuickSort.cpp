#include "QuickSort.h"

void QuickSort(std::vector<int>& arr, int start, int end)
{
	if (start >= end) return;
	int pIndex = Partition(arr, start, end);
	QuickSort(arr, start, pIndex - 1);
	QuickSort(arr, pIndex + 1, end);
}

int Partition(std::vector<int>& arr, int start, int end)
{
	int pivot = arr[end];
	int pIndex = start;
	for (int i = start; i < end; i++) {
		if (arr[i] <= pivot) {
			swap(&arr[i], &arr[pIndex]);
			PrintArray(arr);
			pIndex++;
		}
	}
	swap(&arr[pIndex], &arr[end]);
	PrintArray(arr);
	return pIndex;
}