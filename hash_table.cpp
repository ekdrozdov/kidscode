#include "hash_table.h"

HashTable::HashTable(int newSize) {
	size = newSize;
	items = new Record[newSize];
}

HashTable::~HashTable() {
	if (items) {
		delete[] items;
	}
	items = NULL;
	size = 0;
}

int HashTable::add(string item) {
	int index = hashFunc(item);

	// Collision handling.
	while ((index < size) && (items[index].name != "")) {
		++index;
	}
	if (index < size) {
		items[index].name = item;	
		return index;
	}

	cout << "unresovable collision\n";
	return -1;	
}

int HashTable::find(string name) {
	int index = hashFunc(name);
	while ((index < size) && (items[index].name != name)) {
		++index;
	}
	if (index < size) {
		return index;
	}
	return -1;
}

string HashTable::find(int index) {
	return items[index].name;
}

void HashTable::print() {
	for (int i = 0; i < size; ++i) {
		if (items[i].name != "") {
			cout << items[i].name << " " << items[i].attributes.type << " "
				<< items[i].attributes.isDefine << endl;
		}
	}
}

int HashTable::setDefine(string name) {
	int index = find(name);
	items[index].attributes.isDefine = 1;
	return index;
}

int HashTable::setType(string name, int type) {
	int index = find(name);
	items[index].attributes.type = type;
	return index;
}

int HashTable::hashFunc(string name) {
	int counter = 0;
	for (auto it : name) {
		counter += int(it);
	}
	counter %= size;

	return counter;
}
