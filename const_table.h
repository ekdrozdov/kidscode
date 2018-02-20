#pragma once
#include <string>
#include <iostream>

#define N_T_DELIMITERS 0
#define N_T_KEYWORDS 1
#define N_T_OPERATIONS 2

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
