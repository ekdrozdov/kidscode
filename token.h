#pragma once
#include <iostream>
#include <string>
#include "finite_state_machine.h"
#include "hash_table.h"
#include "const_table.h"

class Token {
public:
	Token();
	int nTable;
	int index;
	std::string readable(std::string name, bool doPirntIndex);
	bool correct();
	friend std::ostream& operator<<(std::ostream& os, const Token& obj);
};



