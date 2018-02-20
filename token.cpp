#include "token.h"

Token::Token() {
	nTable = 0;
	index = 0;
}

std::ostream& operator<<(std::ostream& os, const Token& obj)
{
	os << "(" << obj.nTable << ", " << obj.index << ")";
	return os;
}
