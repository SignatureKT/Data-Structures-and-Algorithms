#include "InsertionSort.h"

void InsertionSort(std::vector<int>& arr)
{
	int arrLength = arr.size();
	int counter = 1;
	while (counter < arrLength) {
		if (counter == 0) {
			counter++;
		}
		else if (arr[counter - 1] <= arr[counter]) {
			counter++;
		}
		else {
			int k = arr[counter - 1];
			arr[counter - 1] = arr[counter];
			arr[counter] = k;
			counter--;
			PrintArray(arr);
		}
	}
}