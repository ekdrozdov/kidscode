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
	// -1 -- no define
	// 0 -- define
	int isDefine;
};

/*
std::ostream& operator<<(std::ostream& os, const Attributes& obj)
{
	os << "hi";
	return os;
}
*/
