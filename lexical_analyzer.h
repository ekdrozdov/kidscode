// TODO
// Error handling mechanism.

#pragma once
#include <fstream>
#include "hash_table.h"
#include "const_table.h"
#include "finite_state_machine.h"
#include "token.h"

extern ConstTable delimiters;
extern ConstTable keywords;
extern HashTable identifiers;
extern HashTable constants;

class LexicalAnalyzer {
public:
	LexicalAnalyzer();
	~LexicalAnalyzer();
	void scanCode(string filename);

private:
	FSM fsm;	
	int errorsCount;

	Token makeToken(std::string name, int type);
};
