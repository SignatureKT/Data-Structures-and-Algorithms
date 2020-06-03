#include <string>
#include <iostream>

constexpr char empty[] = "empty";

#ifndef Hash_H
#define Hash_H

class hash
{
private:
	static const int tableSize = 4;

	struct item {
		std::string name;
		std::string age;
		item* next;
	};

	item* HashTable[tableSize];

public:
	hash();
	~hash();
	int Hash(std::string key);
	void AddItem(std::string name, std::string age);
	int NumberOfItemsInIndex(int index);
	void PrintTable();
	void PrintItemsInIndex(int index);
	void FindAge(std::string name);
	void RemoveItem(std::string name);
};

#endif // !Hash_H
