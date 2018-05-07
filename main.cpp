// TODO
// Where to validate a variable name?
// Refactor architecture: select a predecessor for tables.

//#include "const_table.h"
//#include "attributes.h"
//#include "hash_table.h"
#include "lexical_analyzer.h"

using namespace std;

string _keywords[3] = {"main", "int", "return"};
string _delimiters[6] = {";", "+", "&&", "=", "-", "||"};

ConstTable keywords = ConstTable(_keywords, 3);
ConstTable delimiters = ConstTable(_delimiters,  6);

HashTable constants = HashTable(100);
HashTable identifiers = HashTable(100);

int main() {
	LexicalAnalyzer la;

	string filename = "sample.txt";
	la.scanCode(filename);

	return 0;
}
