#ifndef Stack_H
#define Stack_H

class Stack
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

	nodePtr top;
	nodePtr curr;
public:
	bool isEmpty();
	int peek();
	void push(int data);
	int pop();
	void print();
};

#endif // !Stack_H