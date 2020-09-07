#include <iostream>
#include <stdlib.h>
#include <list>

class HashTable
{
private:
	const int buckets;
	std::list<int> *table;

public:
	HashTable(int buck)
		: buckets{ buck }, table{ new std::list<int>[buck] }
	{}
	~HashTable() { delete[] table; }

	void insert(int d);
	void print();
};

void HashTable::insert(int d)
{
	int bucket = d % buckets;
	table[bucket].push_back(d);
}

void HashTable::print()
{
	for (int i = 0; i < buckets; ++i)
	{
		std::cout << "[Bucket " << i << "] ";
		for (const auto &v : table[i])
		{
			std::cout << "-> | " << v << " | ";
		}
		std::cout << '\n';
	}
}

int main(int argc, char **argv)
{
	constexpr int buckets = 8;
	HashTable ht(buckets);

	srand(3);
	for (int i = 0; i < buckets * 4; ++i)
		ht.insert(rand() % 100);

	ht.print();

	return 0;
}