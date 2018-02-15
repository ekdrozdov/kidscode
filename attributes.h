#pragma once
#include <iostream>

using namespace std;

class Attributes {
public:
	// --- values meaning ---
	// -1 -- undeclarate
	// 0 -- int
	int type;
	bool isDefine;
};

/*
std::ostream& operator<<(std::ostream& os, const Attributes& obj)
{
	os << "hi";
	return os;
}
*/
