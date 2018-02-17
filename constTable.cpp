#include "constTable.h"

ConstTable::ConstTable(string* newItems, int nTotal) {
	size = nTotal;
	items = new string[nTotal];
	for (int i = 0; i < nTotal; ++i) {
		items[i] = newItems[i];
	}
}

ConstTable::~ConstTable() {
	if (items) {
		delete[] items;
	}
	items = NULL;
	size = 0;
}

int ConstTable::find(string item) {
	int i = 0;
	while ((i < size) && (items[i] != item)) {
		i++;
	}
	if (i < size) {
		return i;
	}
	return -1;
}

string ConstTable::find(int index) {
	return items[index];
}

void ConstTable::print() {
	cout << "Size = " << size << endl;
	for (int i = 0; i < size; ++i) {
		cout << items[i] << endl;
	}
}
