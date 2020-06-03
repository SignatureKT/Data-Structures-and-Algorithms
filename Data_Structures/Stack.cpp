#include "Stack.h"
#include <iostream>

bool Stack::isEmpty() {
	return top == nullptr;
}

int Stack::peek() {
	return top->data;
}

void Stack::push(int data) {
	Node* node = new Node(data);
	node->next = top;
	top = node;
}

int Stack::pop() {
	int data = top->data;
	top = top->next;
	return data;
}

void Stack::print() {
	if (top == nullptr) {
		std::cout << "There is no data.\n";
	}
	curr = top;
	while (curr != nullptr) {
		std::cout << curr->data << '\n';
		curr = curr->next;
	}
}