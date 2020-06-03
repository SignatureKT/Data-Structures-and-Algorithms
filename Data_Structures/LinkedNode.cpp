#include "LinkedNode.h"
#include <iostream>

LinkedNode::LinkedNode() :
	head(nullptr),
	curr(nullptr),
	temp(nullptr)
{
};

void LinkedNode::Append(int addData) {
	nodePtr n = new Node;
	n->next = nullptr;
	n->data = addData;

	if (head != nullptr) {
		curr = head;
		while (curr->next != nullptr) {
			curr = curr->next;
		}
		curr->next = n;
	}
	else {
		head = n;
	}
}

void LinkedNode::DeleteNode(int delData) {
	temp = head;
	curr = head;
	while (curr != nullptr && curr->data != delData) {
		temp = curr;
		curr = curr->next;
	}
	if (curr == NULL) {
		std::cout << delData << " was not in the list.\n";
	}
	else {
		temp->next = curr->next;
		if (curr == head) {
			head = head->next;
		}
		delete curr;
		std::cout << "The value " << delData << " was deleted.\n";
	}
}

void LinkedNode::PrintList() {
	curr = head;
	while (curr != nullptr) {
		std::cout << curr->data << '\n';
		curr = curr->next;
	}
}