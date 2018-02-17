#pragma once
#include <iostream>

using namespace std;

class Attributes {
public:
	Attributes() { type = -1; isDefine = -1; }
	// --- values meaning ---
	// -1 -- undeclarate
	// 0 -- int
	int type;
	int isDefine;
};

/*
std::ostream& operator<<(std::ostream& os, const Attributes& obj)
{
	os << "hi";
	return os;
}
*/
