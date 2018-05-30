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

string Token::readable(std::string name, bool doPrintIndex) {
	string result;
	result.append("(");
	switch (nTable) {
		case N_T_DELIMITERS:
			result.append("delim");
			break;
		case N_T_KEYWORDS:
			result.append("keyword");
			break;
		case N_T_IDENTIFIERS:
			result.append("ident");
			break;
		case N_T_CONSTANTS:
			result.append("const");
			break;
	}

	result.append(", ");
	result.append("'");
	result.append(name);
	result.append("'");

	if (doPrintIndex) {
		result.append(", ");
		result.append(std::to_string(index));
	}

	result.append(")");
	return result;
}

bool Token::correct() {
	if ((nTable == -1) || (index == -1))
		return 0;
	else
		return 1;
}
