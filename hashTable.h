#pragma once
#include <string>
#include <iostream>
#include "attributes.h"

using namespace std;

class HashTable {
public:
	HashTable(int size);
	~HashTable();

	int find(string item);
	void add(string item);
	void print();

private:
	int hashFunc(string item);
	int size;
	string* items;
};
