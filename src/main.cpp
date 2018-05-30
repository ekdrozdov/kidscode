// TODO
// Where to validate a variable name?
// Refactor architecture: select a predecessor for tables.

//#include "const_table.h"
//#include "attributes.h"
//#include "hash_table.h"
#include "lexical_analyzer.h"

void displayUsage(string thisProgName) {
	std::cout << "Error: too few arguments";
	std::cout << "Usage:\n" << thisProgName <<
		" codeFileName.cpp\n";
}

std::string _keywords[3] = {"main", "int", "return"};
std::string _delimiters[6] = {";", "+", "&&", "=", "-", "||"};

ConstTable keywords = ConstTable(_keywords, 3);
ConstTable delimiters = ConstTable(_delimiters,  6);

HashTable constants = HashTable(100);
HashTable identifiers = HashTable(100);

int main(int argc, char** argv) {
	if (argc != 2) {
		displayUsage(std::string(argv[0]));
		return EXIT_FAILURE;
	}

	LexicalAnalyzer la;

	std::string filename = argv[1];
	la.scanCode(filename);

	return EXIT_SUCCESS;
}
