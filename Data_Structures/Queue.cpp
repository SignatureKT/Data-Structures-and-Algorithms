#include "Queue.h"
#include <iostream>

bool Queue::isEmpty() {
	return head == nullptr;
}

int Queue::peek() {
	return head->data;
}

void Queue::add(int data) {
	Node* node = new Node(data);
	if (tail != nullptr) {
		tail->next = node;
	}
	tail = node;
	if (head == nullptr) {
		head = node;
	}
}

int Queue::remove() {
	int data = head->data;
	head = head->next;
	if (head == nullptr) {
		tail = nullptr;
	}
	return data;
}

void Queue::print() {
	if (head == nullptr) {
		std::cout << "There are no Nodes.\n";
		return;
	}

	curr = head;
	while (curr != nullptr) {
		std::cout << curr->data << '\n';
		if (curr->next == nullptr) {
			return;
		}
		else {
			curr = curr->next;
		}
	}
}