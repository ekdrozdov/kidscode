#pragma once
#include <string>
#include <iostream>

using namespace std;

class ConstTable {
public:
	ConstTable(string* items, int nTotal);
	~ConstTable();

	int find(string item);
	void print();

private:
	int size;
	string* items;
};
