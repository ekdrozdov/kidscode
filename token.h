#pragma once
#include <iostream>

class Token {
public:
	Token();
	int nTable;
	int index;
	friend std::ostream& operator<<(std::ostream& os, const Token& obj);
};



