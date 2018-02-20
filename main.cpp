// TODO
// Where to validate a variable name?
// Refactor architecture: select a predecessor for tables.

//#include "const_table.h"
//#include "attributes.h"
//#include "hash_table.h"
#include "lexical_analyzer.h"

using namespace std;

string _keywords[3] = {"main", "int", "return"};
string _delimiters[5] = {";", "(", ")", "{", "}"};
string _operations[3] = {"+", "*", "="};

ConstTable keywords = ConstTable(_keywords, 3);
ConstTable delimiters = ConstTable(_delimiters,  5);
ConstTable operations = ConstTable(_operations, 2);

HashTable constants = HashTable(100);
HashTable identifiers = HashTable(100);

int main() {
	LexicalAnalyzer la;

	string filename = "sample.txt";
	la.scanCode(filename);

	/* LAB 1 demonstration code
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
	*/

	return 0;
}
