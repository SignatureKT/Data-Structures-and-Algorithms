#ifndef LinkedNode_H
#define LinkedNode_H

class LinkedNode
{
private:
	typedef struct Node {
		int data;
		Node* next;
	}*nodePtr;

	nodePtr head;
	nodePtr curr;
	nodePtr temp;

public:
	LinkedNode();
	void Append(int addData);
	void DeleteNode(int delData);
	void PrintList();
};

#endif // !LinkedNode_H

