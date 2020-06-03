#include "BubbleSort.h"

void BubbleSort(std::vector<int>& arr)
{
	int arrLegnth = arr.size();
	for (int k = 1; k < arrLegnth; k++) {
		for (int i = 0; i < arrLegnth - 1; i++) {
			if (arr[i] > arr[i + 1]) {
				swap(&arr[i], &arr[i + 1]);
				PrintArray(arr);
			}
		}
	}
}