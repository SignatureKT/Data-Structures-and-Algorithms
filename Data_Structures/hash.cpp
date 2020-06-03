#include "hash.h"

hash::hash()
{
	for (int i = 0; i < tableSize; i++) {
		HashTable[i] = new item;
		HashTable[i]->name = empty;
		HashTable[i]->age = empty;
		HashTable[i]->next = nullptr;
	}
}

int hash::Hash(std::string key) {
	int hash = 0;
	int index;

	for (size_t i = 0; i < key.length(); i++) {
		hash = (hash + static_cast<int>(key[i])) * 17;
	}

	index = hash % tableSize;

	return index;
}

void hash::AddItem(std::string name, std::string age)
{
	int index = Hash(name);

	if (HashTable[index]->name == empty)
	{
		HashTable[index]->name = name;
		HashTable[index]->age = age;
	}
	else {
		item* Ptr = HashTable[index];
		item* n = new item;
		n->name = name;
		n->age = age;
		n->next = nullptr;
		while (Ptr->next != nullptr) {
			Ptr = Ptr->next;
		}
		Ptr->next = n;
	}
}

int hash::NumberOfItemsInIndex(int index)
{
	int count = 0;

	if (HashTable[index]->name == empty) {
		return count;
	}
	else {
		count++;
		item* Ptr = HashTable[index];
		while (Ptr->next != nullptr) {
			count++;
			Ptr = Ptr->next;
		}
	}
	return count;
}

void hash::PrintTable()
{
	int number;
	for (int i = 0; i < tableSize; i++) {
		number = NumberOfItemsInIndex(i);
		std::cout << "--------------------\n";
		std::cout << "index = " << i << '\n';
		std::cout << HashTable[i]->name << '\n';
		std::cout << HashTable[i]->age << '\n';
		std::cout << "# of items = " << number << '\n';
		std::cout << "--------------------\n";
	}
}

void hash::PrintItemsInIndex(int index)
{
	item* Ptr = HashTable[index];
	if (Ptr->name == empty) {
		std::cout << "bucket = " << index << " is empty\n";
	}
	else {
		std::cout << "bucket " << index << " contains the following items:\n";

		while (Ptr != nullptr) {
			std::cout << "--------------------\n";
			std::cout << Ptr->name << '\n';
			std::cout << Ptr->age << '\n';
			std::cout << "--------------------\n";
			Ptr = Ptr->next;
		}
	}
}

void hash::FindAge(std::string name)
{
	int index = Hash(name);
	bool foundName = false;
	std::string age;

	item* Ptr = HashTable[index];
	while (Ptr != nullptr) {
		if (Ptr->name == name) {
			foundName = true;
			age = Ptr->age;
		}
		Ptr = Ptr->next;
	}
	if (foundName == true) {
		std::cout << "Age = " << age << '\n';
	}
	else {
		std::cout << name << "'s info was not found.\n";
	}
}

void hash::RemoveItem(std::string name)
{
	int index = Hash(name);

	item* delPtr;
	item* p1;
	item* p2;

	// Case 0 - bucket is empty
	if (HashTable[index]->name == empty && HashTable[index]->age == empty) {
		std::cout << name << " was not found.\n";
	}
	// Case 1 - Only 1 item contained in bucket, and that item has matching name
	else if (HashTable[index]->name == name && HashTable[index]->next == nullptr) {
		HashTable[index]->name = empty;
		HashTable[index]->age = empty;
		std::cout << name << " was removed from the table.\n";
	}
	// Case 2 - Match is located in the first item in the bucket, but there are more items in the bucket
	else if (HashTable[index]->name == name) {
		delPtr = HashTable[index];
		HashTable[index] = HashTable[index]->next;
		delete delPtr;
		std::cout << name << " was removed from the table.\n";
	}
	// Case 3 - bucket contains items, but first item is not a match

	else {
		p1 = HashTable[index]->next;
		p2 = HashTable[index];

		while (p1 != nullptr && p1->name != name) {
			p2 = p1;
			p1 = p1->next;
		}
		// Case 3.1 - no match
		if (p1 == nullptr) {
			std::cout << name << " was not found.\n";
		}
		// Case 3.2 - match is found
		else {
			delPtr = p1;
			p1 = p1->next;
			p2->next = p1;

			delete delPtr;
			std::cout << name << " was removed from the table.\n";

		}
	}
}

hash::~hash()
{
	item* Ptr;
	for (int i = 0; i < tableSize; i++)
	{
		while (HashTable[i] != NULL)
		{
			Ptr = HashTable[i];
			HashTable[i] = HashTable[i]->next;
			delete Ptr;
		}
	}
}