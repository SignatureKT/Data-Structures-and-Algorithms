#ifndef Queue_H
#define Queue_H

class Queue
{
private:
	typedef struct Node {
		int data;
		Node* next;
		Node(int data) {
			this->data = data;
			this->next = nullptr;
		}
	}*nodePtr;

	nodePtr curr;
	nodePtr head; // remove here
	nodePtr tail; // add here

public:
	bool isEmpty();
	int peek();
	void add(int data);
	int remove();
	void print();
};

#endif // !Queue_H