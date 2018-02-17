#pragma once
#include <string>
#include <iostream>

using namespace std;

class ConstTable {
public:
	ConstTable(string* items, int nTotal);
	~ConstTable();

	int find(string item);
	string find(int index);
	void print();

private:
	int size;
	string* items;
};
