#include "Functions.h"

bool IsArraySorted(std::vector<int>& arr) {
	for (size_t i = 1; i < arr.size(); i++) {
		if (arr[i - 1] > arr[i]) {
			return false;
		}
	}
	return true;
}

void PrintArray(std::vector<int>& arr)
{
	for (size_t i = 0; i < arr.size(); i++) {
		std::cout << "[" << arr[i] << "], ";
	}
	std::cout << '\n';
}

void PrintWholeArray(std::vector<int>& arr, int i)
{
	std::cout << "[" << arr[i] << "], ";
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}