// DATASTRUCTURES
#include "LinkedNode.h"
#include "Queue.h"
#include "Stack.h"
#include "hash.h"
#include "BST.h"

// ALGORITHMS
#include "BubbleSort.h"
#include "MergeSort.h"
#include "InsertionSort.h"
#include "QuickSort.h"

//Functions
#include "Functions.h"

#include <vector>

// DATA STRUCTURE USING OOP 
void LinkedListFunction();
void QueueFunction();
void StackFunction();
void HashFunction();
void BST_Function();

// ALGORITHMS

int main()
{
	std::vector<int>numbers = { 50, 76, 21, 4, 32, 64, 15, 52, 14, 100, 83, 2, 3, 70, 87, 80, 90, 101, 4, 51 };

	//LinkedListFunction();

	//QueueFunction();

	//StackFunction();

	//HashFunction();

	//BST_Function();

	//BubbleSort(numbers);

	//MergeSort(numbers);

	//InsertionSort(numbers);

	//QuickSort(numbers, 0, numbers.size() - 1);

	PrintArray(numbers);

	return 0;
}

void LinkedListFunction()
{
	LinkedNode* NodeA = new LinkedNode();
	NodeA->Append(5);
	NodeA->Append(6);
	NodeA->Append(7);

	NodeA->DeleteNode(5);

	NodeA->PrintList();
}

void QueueFunction()
{
	Queue* NodeB = new Queue();
	NodeB->add(5);
	NodeB->add(9);
	NodeB->print();
	NodeB->add(12);
	NodeB->add(10);
	NodeB->print();
}

void StackFunction()
{
	Stack* NodeC = new Stack();
	NodeC->push(5);
	NodeC->push(10);
	NodeC->push(22);
	NodeC->print();
}

void HashFunction()
{
	hash Hashy;
	std::string name = "";

	Hashy.AddItem("Paul", "Locha");
	Hashy.AddItem("Kim", "Iced Mocha");
	Hashy.AddItem("Emma", "Strawberry Smoothie");
	Hashy.AddItem("Annie", "Hot Chocolate");
	Hashy.AddItem("Sarah", "Passion Tea");
	Hashy.AddItem("Pepper", "Caramel Mocha");
	Hashy.AddItem("Mike", "Chai Tea");
	Hashy.AddItem("Steve", "Apple Cider");
	Hashy.AddItem("Bill", "Root Beer");
	Hashy.AddItem("Marie", "Skinny Latte");
	Hashy.AddItem("Susan", "Water");
	Hashy.AddItem("Joe", "Green Tea");

	Hashy.PrintItemsInIndex(2);

	while (name != "exit") {
		std::cout << "Remove ";
		std::cin >> name;
		if (name != "exit") {
			Hashy.RemoveItem(name);
		}
	}

	Hashy.PrintItemsInIndex(2);
	Hashy.~hash();
}

void BST_Function()
{
	int TreeKeys[16] = { 50, 76, 21, 4, 32, 64, 15, 52, 14, 100, 83, 2, 3, 70, 87, 80 };
	BST myTree;
	int input = 0;

	std::cout << "Printing the tree in order\nBefore adding numbers\n";

	myTree.PrintInOrder();

	for (int i = 0; i < 16; i++) {
		myTree.AddLeaf(TreeKeys[i]);
	}

	std::cout << "Printing the tree in order\nAfter adding numbers\n";

	myTree.PrintInOrder();

	std::cout << '\n';

	std::cout << "The smallest value in the tree is " << myTree.FindSmallest() << '\n';

	std::cout << "Enter a key value to delete. Enter -1 to stop the process\n";
	while (input != -1) {
		std::cout << "Delete Node: ";
		std::cin >> input;
		if (input != -1) {
			std::cout << '\n';
			myTree.RemoveNode(input);
			myTree.PrintInOrder();
			std::cout << '\n';
		}
	}

}
