// TODO
// where to validate a variable name?
// hash function

#include "constTable.h"
#include "map"
#include "attributes.h"
#include "hashTable.h"

using namespace std;

std::ostream& operator<<(std::ostream& os, const Attributes& obj)
{
	os << obj.type << " " << obj.isDefine; 
	return os;
}


int main() {
	string _keywords[3] = {"main", "int", "return"};
	string _delimiters[5] = {";", "(", ")", "{", "}"};
	string _signs[2] = {"+", "="};
	string _additional[0] = {};

	ConstTable keywords = ConstTable(_keywords, 3);
	ConstTable delimiters = ConstTable(_delimiters,  5);
	ConstTable signs = ConstTable(_signs, 2);
	ConstTable additional = ConstTable(_additional, 0);

	HashTable variables = HashTable(100);
	cout << "Table size set as " << variables.getSize() << endl;
	cout << "--- VALUES SETTING ---\n";
	cout << "Let's add three variables: 'x', 'yVar' and 'z'" << endl;
	variables.add("x");
	variables.add("yVar");
	variables.add("z");
	variables.print();
	cout << "--- SEARCHING ---\n";
	cout << "Let's search for 'x' and 'y' by names" << endl;
	cout << variables.find("x") << endl;
	cout << variables.find("y") << endl;
	cout << "--- MODYFYING ---\n";
	cout << "Let's say 'x' and 'z' is define and 'x' type is int" << endl;
	string name = "x";
	variables.setDefine(name);
	variables.setType(name, 1);
	name = "z";
	variables.setDefine(name);
	variables.print();

	/*
	map<string, Attributes> identifiers;
	map<string, Attributes> constants;
	Attributes attributes;
	attributes.type = 1;
	attributes.isDefine = 0;

	identifiers["x"] = attributes;
	identifiers["yVar"] = attributes;

	cout << "--- VALUES SETTING ---\n";
	for (auto it = identifiers.begin(); it != identifiers.end(); ++it) {
		std::cout << it->first << ", " << it->second << '\n';
	}

	auto search = identifiers.find("x");
	cout << "--- SEARCHING ---\n";
	if (search != identifiers.end()) {
		std::cout << search->first << ", " << search->second << '\n';
	}
	else {
		cout << "No results\n";
	}
	search = identifiers.find("y");
	if (search != identifiers.end()) {
		std::cout << search->first << ", " << search->second << '\n';
	}
	else {
		cout << "No results\n";
	}

	cout << "--- MODYFYING ---\n";
	search = identifiers.find("x");
	search->second.isDefine = 1;
	std::cout << search->first << ", " << search->second << '\n';
	*/

	return 0;
}
