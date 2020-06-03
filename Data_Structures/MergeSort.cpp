#include "MergeSort.h"

void MergeSort(std::vector<int>& arr)
{
	int arrLength = arr.size();
	if (arrLength < 2) return;
	int mid = (arrLength / 2);
	std::vector<int>leftArr;
	std::vector<int>rightArr;
	for (int i = 0; i < mid; i++) {
		leftArr.push_back(arr[i]);
	}
	for (int i = mid; i < arrLength; i++) {
		rightArr.push_back(arr[i]);
	}
	MergeSort(leftArr);
	MergeSort(rightArr);
	Merge(arr, leftArr, rightArr);
}

void Merge(std::vector<int>& arr, std::vector<int>& leftArr, std::vector<int>& rightArr)
{
	int leftLength = leftArr.size();
	int rightLength = rightArr.size();
	int i = 0, j = 0, k = 0;
	while (i < leftLength && j < rightLength) {
		if (leftArr[i] < rightArr[j]) {
			arr[k] = leftArr[i];
			PrintWholeArray(leftArr, i);
			i++;
		}
		else {
			arr[k] = rightArr[j];
			PrintWholeArray(rightArr, j);
			j++;
		}
		k++;
	}
	while (i < leftLength) {
		arr[k] = leftArr[i];
		PrintWholeArray(leftArr, i);
		i++; k++;
	}
	while (j < rightLength) {
		arr[k] = rightArr[j];
		PrintWholeArray(rightArr, j);
		j++; k++;
	}
	//Separate for Printed array
	std::cout << '\n';
}