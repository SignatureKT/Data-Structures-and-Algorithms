#include "BST.h"

#include <iostream>

BST::BST() {
	root = nullptr;
}

BST::node* BST::CreateLeaf(int key) {
	node* n = new node;
	n->key = key;
	n->left = nullptr;
	n->right = nullptr;

	return n;
}

void BST::AddLeaf(int key)
{
	AddLeadPrivate(key, root);
}

void BST::AddLeadPrivate(int key, node* Ptr)
{
	if (root == nullptr) {
		root = CreateLeaf(key);
	}
	else if (key < Ptr->key) {
		if (Ptr->left != nullptr) {
			AddLeadPrivate(key, Ptr->left);
		}
		else {
			Ptr->left = CreateLeaf(key);
		}
	}
	else if (key > Ptr->key) {
		if (Ptr->right != nullptr) {
			AddLeadPrivate(key, Ptr->right);
		}
		else {
			Ptr->right = CreateLeaf(key);
		}
	}
	else {
		std::cout << "The key " << key << " has already been added to the tree\n";
	}
}

void BST::PrintInOrder() 
{
	PrintInOrderPrivate(root);
}

void BST::PrintInOrderPrivate(node* Ptr)
{
	if (root != nullptr) {
		if (Ptr->left != nullptr) {
			PrintInOrderPrivate(Ptr->left);
		}
		std::cout << Ptr->key << " ";
		if (Ptr->right != nullptr) {
			PrintInOrderPrivate(Ptr->right);
		}
	}
	else {
		std::cout << "The tree is empty\n";
	}
}

BST::node* BST::ReturnNode(int key)
{
	return ReturnNodePrivate(key, root);
}

BST::node* BST::ReturnNodePrivate(int key, node* Ptr)
{
	if (Ptr != nullptr) {
		if (Ptr->key == key) {
			return Ptr;
		}
		else {
			if (key < Ptr->key) {
				return ReturnNodePrivate(key, Ptr->left);
			}
			else {
				return ReturnNodePrivate(key, Ptr->right);
			}
		}
	}
	else {
		return nullptr;
	}
}

int BST::ReturnRootKey()
{
	if (root != nullptr) {
		return root->key;
	}
	else {
		return -1000;
	}
}

void BST::PrintChildren(int key)
{
	node* Ptr = ReturnNode(key);
	if (Ptr != nullptr) {
		std::cout << "Parent Node = " << Ptr->key << '\n';

		Ptr->left == nullptr ?
			std::cout << "Left Child = NULL\n" :
			std::cout << "Left Child = " << Ptr->left->key << '\n';

		Ptr->right == nullptr ?
			std::cout << "Right Child = NULL\n" :
			std::cout << "Right Child = " << Ptr->right->key << '\n';
	}
	else {
		std::cout << "Key " << key << " is not in the tree\n";
	}
}

int BST::FindSmallest()
{
	return FindSmallestPrivate(root);
}


int BST::FindSmallestPrivate(node* Ptr)
{
	if (root == nullptr) {
		std::cout << "The tree is empty\n";
		return -1000;
	}
	else {
		if (Ptr->left != nullptr) {
			return FindSmallestPrivate(Ptr->left);
		}
		else {
			return Ptr->key;
		}
	}
}

void BST::RemoveNode(int key)
{
	RemoveNodePrivate(key, root);
}

void BST::RemoveNodePrivate(int key, node* parent)
{
	if (root != nullptr) {
		if (root->key == key) {
			RemoveRootMatch();
		}
		else {
			if (key < parent->key && parent->left != nullptr) {
				parent->left->key == key ?
					RemoveMatch(parent, parent->left, true) :
					RemoveNodePrivate(key, parent->left);
			}
			else if (key > parent->key && parent->right != nullptr) {
				parent->right->key == key ?
					RemoveMatch(parent, parent->right, false) :
					RemoveNodePrivate(key, parent->right);
			}
			else {
				std::cout << "The key " << key << " was not found in the tree\n";
			}
		}
	}
	else {
		std::cout << "The tree is empty\n";
	}
}

void BST::RemoveRootMatch()
{
	if (root != nullptr) {
		node* delPtr = root;
		int rootKey = root->key;
		int smallestInRightSubtree;

		// Case 0 - 0 children
		if (root->left == nullptr && root->right == nullptr) {
			root = nullptr;
			delete delPtr;
		}
		// Case 1 - 1 children
		else if (root->left == nullptr && root->right != nullptr) {
			root = root->right;
			delPtr->right = NULL;
			delete delPtr;
			std::cout << "The root node with key" << rootKey << " was deleted." << "The new root contains key " << root->key << '\n';
		}
		else if (root->left != nullptr && root->right == nullptr) {
			root = root->left;
			delPtr->left = NULL;
			delete delPtr;
			std::cout << "The root node with key" << rootKey << " was deleted." << "The new root contains key " << root->key << '\n';
		}
		// Case 2 - 2 Children
		else {
			smallestInRightSubtree = FindSmallestPrivate(root->right);
			RemoveNodePrivate(smallestInRightSubtree, root);
			root->key = smallestInRightSubtree;
			std::cout << "the root key containing key " << rootKey << " was overwritten with key " << root->key << '\n';
		}
	}
	else {
		std::cout << "Can not remove root. The tree is empty\n";
	}
}

void BST::RemoveMatch(node* parent, node* match, bool left)
{
	if (root != nullptr) {
		node* delPtr;
		int matchKey = match->key;
		int smallestInRightSubtree;

		// Case 0 - 0 children
		if (match->left == nullptr && match->right == nullptr) {
			delPtr = match;
			left == true ? parent->left = nullptr : parent->right = nullptr;
			delete delPtr;
			std::cout << "The node containing key " << matchKey << " was removed\n";
		}
		// Case 1 - 1 child
		else if (match->left == nullptr && match->right != nullptr) {
			left == true ? parent->left = match->right : parent->right = match->right;
			match->right = nullptr;
			delPtr = match;
			delete delPtr;
			std::cout << "The node containing key " << matchKey << " was removed\n";
		}
		else if (match->left != nullptr && match->right == nullptr) {
			left == true ? parent->left = match->left : parent->right = match->left;
			match->left = nullptr;
			delPtr = match;
			delete delPtr;
			std::cout << "The node containing key " << matchKey << " was removed\n";
		}
		else {
			smallestInRightSubtree = FindSmallestPrivate(match->right);
			RemoveNodePrivate(smallestInRightSubtree, match);
			match->key = smallestInRightSubtree;
		}
	}
	else {
		std::cout << "Can not remove match. The tree is empty\n";
	}
}

BST::~BST()
{
	RemoveSubtree(root);
}

void BST::RemoveSubtree(node* Ptr)
{
	if (Ptr != nullptr) {
		if (Ptr->left != nullptr) {
			RemoveSubtree(Ptr->left);
		}
		if (Ptr->right != nullptr) {
			RemoveSubtree(Ptr->right);
		}
		std::cout << "Deleting the node containing the key " << Ptr->key << '\n';
		delete Ptr;
	}
}