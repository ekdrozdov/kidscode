#include "finite_state_machine.h"

using namespace std;

FSM::FSM() {
	buf.clear();
	prevState = S_START;
	currentState = S_START;

	transformMatrix[S_START][L_NUMBER] = S_NUMBER; 
	transformMatrix[S_START][L_SYMBOL] = S_IDENTIFIER; 
	transformMatrix[S_START][L_SPACE] = S_START; 
	transformMatrix[S_START][L_SLASH] = S_DIVISION; 
	transformMatrix[S_START][L_DELIMITER] = S_DELIMITER; 
	transformMatrix[S_START][L_STAR] = S_DELIMITER; 
	transformMatrix[S_START][L_EOL] = S_START; 
	transformMatrix[S_START][L_EOF] = S_START; 
	transformMatrix[S_START][L_TABULATION] = S_START; 
	transformMatrix[S_START][L_AMPERSAND] = S_LOG_AND; 
	transformMatrix[S_START][L_V_STICK] = S_LOG_OR; 

	transformMatrix[S_NUMBER][L_NUMBER] = S_NUMBER;
	transformMatrix[S_NUMBER][L_SYMBOL] = S_ERROR;
	transformMatrix[S_NUMBER][L_SPACE] = S_FINAL; 
	transformMatrix[S_NUMBER][L_SLASH] = S_FINAL; 
	transformMatrix[S_NUMBER][L_DELIMITER] = S_FINAL; 
	transformMatrix[S_NUMBER][L_STAR] = S_FINAL; 
	transformMatrix[S_NUMBER][L_EOL] = S_FINAL; 
	transformMatrix[S_NUMBER][L_EOF] = S_FINAL; 
	transformMatrix[S_NUMBER][L_TABULATION] = S_FINAL; 
	transformMatrix[S_NUMBER][L_AMPERSAND] = S_FINAL; 
	transformMatrix[S_NUMBER][L_V_STICK] = S_FINAL; 

	transformMatrix[S_IDENTIFIER][L_NUMBER] = S_IDENTIFIER; 
	transformMatrix[S_IDENTIFIER][L_SYMBOL] = S_IDENTIFIER; 
	transformMatrix[S_IDENTIFIER][L_SPACE] = S_FINAL; 
	transformMatrix[S_IDENTIFIER][L_SLASH] = S_FINAL; 
	transformMatrix[S_IDENTIFIER][L_DELIMITER] = S_FINAL; 
	transformMatrix[S_IDENTIFIER][L_STAR] = S_FINAL; 
	transformMatrix[S_IDENTIFIER][L_EOL] = S_FINAL; 
	transformMatrix[S_IDENTIFIER][L_EOF] = S_FINAL; 
	transformMatrix[S_IDENTIFIER][L_TABULATION] = S_FINAL; 
	transformMatrix[S_IDENTIFIER][L_AMPERSAND] = S_FINAL; 
	transformMatrix[S_IDENTIFIER][L_V_STICK] = S_FINAL; 

	transformMatrix[S_LOG_OR][L_NUMBER] = S_ERROR; 
	transformMatrix[S_LOG_OR][L_SYMBOL] = S_ERROR; 
	transformMatrix[S_LOG_OR][L_SPACE] = S_ERROR; 
	transformMatrix[S_LOG_OR][L_SLASH] = S_ERROR; 
	transformMatrix[S_LOG_OR][L_DELIMITER] = S_ERROR; 
	transformMatrix[S_LOG_OR][L_STAR] = S_ERROR; 
	transformMatrix[S_LOG_OR][L_EOL] = S_ERROR; 
	transformMatrix[S_LOG_OR][L_EOF] = S_ERROR; 
	transformMatrix[S_LOG_OR][L_TABULATION] = S_ERROR; 
	transformMatrix[S_LOG_OR][L_AMPERSAND] = S_ERROR; 
	transformMatrix[S_LOG_OR][L_V_STICK] = S_FINAL; 

	transformMatrix[S_DELIMITER][L_NUMBER] = S_FINAL;
	transformMatrix[S_DELIMITER][L_SYMBOL] = S_FINAL; 
	transformMatrix[S_DELIMITER][L_SPACE] = S_FINAL; 
	transformMatrix[S_DELIMITER][L_SLASH] = S_FINAL; 
	transformMatrix[S_DELIMITER][L_DELIMITER] = S_FINAL; 
	transformMatrix[S_DELIMITER][L_STAR] = S_FINAL; 
	transformMatrix[S_DELIMITER][L_EOL] = S_FINAL; 
	transformMatrix[S_DELIMITER][L_EOF] = S_FINAL; 
	transformMatrix[S_DELIMITER][L_TABULATION] = S_FINAL; 
	transformMatrix[S_DELIMITER][L_AMPERSAND] = S_FINAL; 
	transformMatrix[S_DELIMITER][L_V_STICK] = S_FINAL; 

	transformMatrix[S_LOG_AND][L_NUMBER] = S_ERROR; 
	transformMatrix[S_LOG_AND][L_SYMBOL] = S_ERROR; 
	transformMatrix[S_LOG_AND][L_SPACE] = S_ERROR; 
	transformMatrix[S_LOG_AND][L_SLASH] = S_ERROR; 
	transformMatrix[S_LOG_AND][L_DELIMITER] = S_ERROR; 
	transformMatrix[S_LOG_AND][L_STAR] = S_ERROR; 
	transformMatrix[S_LOG_AND][L_EOL] = S_ERROR; 
	transformMatrix[S_LOG_AND][L_EOF] = S_ERROR; 
	transformMatrix[S_LOG_AND][L_TABULATION] = S_ERROR; 
	transformMatrix[S_LOG_AND][L_AMPERSAND] = S_FINAL; 
	transformMatrix[S_LOG_AND][L_V_STICK] = S_ERROR; 

	transformMatrix[S_DIVISION][L_NUMBER] = S_FINAL; 
	transformMatrix[S_DIVISION][L_SYMBOL] = S_FINAL; 
	transformMatrix[S_DIVISION][L_SPACE] = S_FINAL;
	transformMatrix[S_DIVISION][L_SLASH] = S_LINE_COMMENT; 
	transformMatrix[S_DIVISION][L_DELIMITER] = S_FINAL; 
	transformMatrix[S_DIVISION][L_STAR] = S_BLOCK_COMMENT_BEGIN; 
	transformMatrix[S_DIVISION][L_EOL] = S_FINAL; 
	transformMatrix[S_DIVISION][L_EOF] = S_FINAL; 
	transformMatrix[S_DIVISION][L_TABULATION] = S_FINAL; 
	transformMatrix[S_DIVISION][L_AMPERSAND] = S_FINAL; 
	transformMatrix[S_DIVISION][L_V_STICK] = S_FINAL; 

	transformMatrix[S_LINE_COMMENT][L_NUMBER] = S_LINE_COMMENT; 
	transformMatrix[S_LINE_COMMENT][L_SYMBOL] = S_LINE_COMMENT; 
	transformMatrix[S_LINE_COMMENT][L_SPACE] = S_LINE_COMMENT; 
	transformMatrix[S_LINE_COMMENT][L_SLASH] = S_LINE_COMMENT; 
	transformMatrix[S_LINE_COMMENT][L_DELIMITER] = S_LINE_COMMENT; 
	transformMatrix[S_LINE_COMMENT][L_STAR] = S_LINE_COMMENT; 
	transformMatrix[S_LINE_COMMENT][L_EOL] = S_FINAL; 
	transformMatrix[S_LINE_COMMENT][L_EOF] = S_FINAL; 
	transformMatrix[S_LINE_COMMENT][L_TABULATION] = S_LINE_COMMENT; 
	transformMatrix[S_LINE_COMMENT][L_AMPERSAND] = S_LINE_COMMENT; 
	transformMatrix[S_LINE_COMMENT][L_V_STICK] = S_LINE_COMMENT; 

	transformMatrix[S_BLOCK_COMMENT_BEGIN][L_NUMBER] = S_BLOCK_COMMENT_BEGIN; 
	transformMatrix[S_BLOCK_COMMENT_BEGIN][L_SYMBOL] = S_BLOCK_COMMENT_BEGIN; 
	transformMatrix[S_BLOCK_COMMENT_BEGIN][L_SPACE] = S_BLOCK_COMMENT_BEGIN; 
	transformMatrix[S_BLOCK_COMMENT_BEGIN][L_SLASH] = S_BLOCK_COMMENT_BEGIN; 
	transformMatrix[S_BLOCK_COMMENT_BEGIN][L_DELIMITER] = S_BLOCK_COMMENT_BEGIN; 
	transformMatrix[S_BLOCK_COMMENT_BEGIN][L_STAR] = S_BLOCK_COMMENT_END; 
	transformMatrix[S_BLOCK_COMMENT_BEGIN][L_EOL] = S_BLOCK_COMMENT_BEGIN; 
	transformMatrix[S_BLOCK_COMMENT_BEGIN][L_EOF] = S_BLOCK_COMMENT_BEGIN; 
	transformMatrix[S_BLOCK_COMMENT_BEGIN][L_TABULATION] = S_BLOCK_COMMENT_BEGIN; 
	transformMatrix[S_BLOCK_COMMENT_BEGIN][L_AMPERSAND] = S_BLOCK_COMMENT_BEGIN; 
	transformMatrix[S_BLOCK_COMMENT_BEGIN][L_V_STICK] = S_BLOCK_COMMENT_BEGIN; 

	transformMatrix[S_BLOCK_COMMENT_END][L_NUMBER] = S_BLOCK_COMMENT_BEGIN; 
	transformMatrix[S_BLOCK_COMMENT_END][L_SYMBOL] = S_BLOCK_COMMENT_BEGIN; 
	transformMatrix[S_BLOCK_COMMENT_END][L_SPACE] = S_BLOCK_COMMENT_BEGIN; 
	transformMatrix[S_BLOCK_COMMENT_END][L_SLASH] = S_BLOCK_COMMENT; 
	transformMatrix[S_BLOCK_COMMENT_END][L_DELIMITER] = S_BLOCK_COMMENT_BEGIN; 
	transformMatrix[S_BLOCK_COMMENT_END][L_STAR] = S_BLOCK_COMMENT_BEGIN; 
	transformMatrix[S_BLOCK_COMMENT_END][L_EOL] = S_BLOCK_COMMENT_BEGIN; 
	transformMatrix[S_BLOCK_COMMENT_END][L_EOF] = S_BLOCK_COMMENT_BEGIN; 
	transformMatrix[S_BLOCK_COMMENT_END][L_TABULATION] = S_BLOCK_COMMENT_BEGIN; 
	transformMatrix[S_BLOCK_COMMENT_END][L_AMPERSAND] = S_BLOCK_COMMENT_BEGIN; 
	transformMatrix[S_BLOCK_COMMENT_END][L_V_STICK] = S_BLOCK_COMMENT_BEGIN; 

	transformMatrix[S_BLOCK_COMMENT][L_NUMBER] = S_FINAL; 
	transformMatrix[S_BLOCK_COMMENT][L_SYMBOL] = S_FINAL; 
	transformMatrix[S_BLOCK_COMMENT][L_SPACE] = S_FINAL; 
	transformMatrix[S_BLOCK_COMMENT][L_SLASH] = S_FINAL; 
	transformMatrix[S_BLOCK_COMMENT][L_DELIMITER] = S_FINAL; 
	transformMatrix[S_BLOCK_COMMENT][L_STAR] = S_FINAL; 
	transformMatrix[S_BLOCK_COMMENT][L_EOL] = S_FINAL; 
	transformMatrix[S_BLOCK_COMMENT][L_EOF] = S_FINAL; 
	transformMatrix[S_BLOCK_COMMENT][L_TABULATION] = S_FINAL; 
	transformMatrix[S_BLOCK_COMMENT][L_AMPERSAND] = S_FINAL; 
	transformMatrix[S_BLOCK_COMMENT][L_V_STICK] = S_FINAL; 

	transformMatrix[S_FINAL][L_NUMBER] = S_ERROR; 
	transformMatrix[S_FINAL][L_SYMBOL] = S_ERROR; 
	transformMatrix[S_FINAL][L_SPACE] = S_ERROR; 
	transformMatrix[S_FINAL][L_SLASH] = S_ERROR; 
	transformMatrix[S_FINAL][L_DELIMITER] = S_ERROR; 
	transformMatrix[S_FINAL][L_STAR] = S_ERROR; 
	transformMatrix[S_FINAL][L_EOL] = S_ERROR; 
	transformMatrix[S_FINAL][L_EOF] = S_ERROR; 
	transformMatrix[S_FINAL][L_TABULATION] = S_ERROR; 
	transformMatrix[S_FINAL][L_AMPERSAND] = S_ERROR; 
	transformMatrix[S_FINAL][L_V_STICK] = S_ERROR; 

	transformMatrix[S_ERROR][L_NUMBER] = S_ERROR; 
	transformMatrix[S_ERROR][L_SYMBOL] = S_ERROR; 
	transformMatrix[S_ERROR][L_SPACE] = S_ERROR; 
	transformMatrix[S_ERROR][L_SLASH] = S_ERROR; 
	transformMatrix[S_ERROR][L_DELIMITER] = S_ERROR; 
	transformMatrix[S_ERROR][L_STAR] = S_ERROR; 
	transformMatrix[S_ERROR][L_EOL] = S_ERROR; 
	transformMatrix[S_ERROR][L_EOF] = S_ERROR; 
	transformMatrix[S_ERROR][L_TABULATION] = S_ERROR; 
	transformMatrix[S_ERROR][L_AMPERSAND] = S_ERROR; 
	transformMatrix[S_ERROR][L_V_STICK] = S_ERROR; 

}

FSM::~FSM() {
	buf.clear();
	prevState = S_START;
	currentState = S_START;
}

int FSM::getLetterNumber(char letter) {
	if ((letter >= '0') && (letter <= '9')) {
		return L_NUMBER;
	}
	else if ((letter >= 'a') && (letter <= 'z')) {
		return L_SYMBOL;
	}
	else if (letter == ' ') {
		return L_SPACE;
	}
	else if (letter == '/') {
		return L_SLASH;
	}
	else if ((letter == ';') || (letter == '+') || (letter == '-') ||
			(letter == '=')) {
		return L_DELIMITER;
	}
	else if (letter == '*') {
		return L_STAR;
	}
	else if (letter == '\n') {
		return L_EOL;
	}
	else if (letter == EOF) {
		return L_EOF;
	}
	else if (letter == '\t') {
		return L_TABULATION;
	}
	else if (letter == '&') {
		return L_AMPERSAND;
	}
	else if (letter == '|') {
		return L_V_STICK;
	}
	else {
		//std::cout << "error: getLetterType: unknown symbol\n";
		return L_UNKNOWN;
	}
}

int FSM::parse(std::string::iterator end, std::string::iterator* it) {
	if ((currentState == S_FINAL) || (currentState == S_ERROR)) {
		buf.clear();
		prevState = S_START;
		currentState = S_START;
	}

	while ((currentState != S_FINAL) && (currentState != S_ERROR) && (*it != end)) {
		char letter = **it;
		int letterNumber = getLetterNumber(letter);
		//std::cout << lineItNumber << " " << letter << std::endl;
		if (letterNumber == L_UNKNOWN) {
			currentState = S_ERROR;
		}
		else {
			prevState = currentState;
			currentState = transformMatrix[currentState][letterNumber];
			if (currentState != S_START) {
				buf.push_back(letter);
			}
		}
		(*it)++;
		shift++;
	}

	if (currentState == S_ERROR) {
		return S_ERROR;
	}

	if (currentState == S_FINAL) {
		buf.pop_back();
	}

	if ((*it == end) && (currentState != S_FINAL)) {
		return S_IN_PROGRESS;
	}
	else {
		return prevState;
	}
}
