// By: Coding Jesus

#include <iostream>
#include <cstring>
#include <list>

using namespace std;

class HashTable {
private:
	static const int hashGroups = 10;
	list<pair<int, string>> table[hashGroups];

public:
	bool isEmpty() const;
	int hashFunction(int key);
	void insertItem(int key, string value);
	void removeItem(int key);
	string searchTable(int key);
	void printTable();
};

bool HashTable::isEmpty() const
{
	int sum{};
	for (int i = 0; i < hashGroups; ++i)
		sum += table[i].size();
	if (!sum) return true;
	return false;
}

int HashTable::hashFunction(int key)
{
	return key % hashGroups;
}

void HashTable::insertItem(int key, string value)
{
	int hashValue = hashFunction(key);
	auto &cell = table[hashValue];
	auto bItr = begin(cell);
	bool keyExists{ false };
	for (; bItr != end(cell); ++bItr) {
		if (bItr->first == key) {
			keyExists = true;
			bItr->second = value;
			cout << "[WARNING] Key exists. Value replaced." << endl;
			break;
		}
	}
	if (!keyExists)
		cell.emplace_back(key, value);
}

void HashTable::removeItem(int key)
{
	int hashValue = hashFunction(key);
	auto &cell = table[hashValue];
	bool keyExists{ false };
	auto bItr = begin(cell);
	for (; bItr != end(cell); ++bItr) {
		if (bItr->first == key) {
			keyExists = true;
			cell.remove(*bItr);
			cout << "[INFO] Item removed" << endl;
			break;
		}
	}
	if (!keyExists)
		cout << "[WARNING] Key was not found" << endl;
}

void HashTable::printTable()
{
	for (int i = 0; i < hashGroups; ++i) {
		if (!table[i].size()) continue;
		auto bItr = table[i].begin();
		for (; bItr != table[i].end(); ++bItr)
			cout << "[INFO] Key: " << bItr->first
			<< " Value: " << bItr->second << endl;
	}
		
}

int main(int argc, char *argv[])
{
	HashTable ht;
	if (ht.isEmpty()) cout << "Hash Table created!" << endl;
	ht.insertItem(101, "Jim");
	ht.insertItem(102, "Tom");
	ht.insertItem(103, "Henry");
	ht.insertItem(104, "Charles");
	ht.insertItem(105, "James");
	ht.insertItem(106, "BudDub");
	ht.insertItem(107, "Sagn");
	ht.insertItem(108, "Teddy");
	ht.insertItem(109, "Chewie");
	ht.printTable();
	ht.removeItem(109);
	ht.removeItem(227);


	return 0;
}