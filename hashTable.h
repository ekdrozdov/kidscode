#pragma once
#include <string>
#include <iostream>
#include "record.h"

using namespace std;

class HashTable {
public:
	HashTable(int size);
	~HashTable();

	int add(string name);
	int find(string name);
	string find(int index);

	int setType(string name, int type);
	int setDefine(string name);

	int getSize() { return size; }

	void print();

private:
	int hashFunc(string name);
	int size;
	Record* items;
};
