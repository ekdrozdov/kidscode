#pragma once
#include "iostream"
#include "fstream"

// FSM parameters.
#define STATES 13
#define LETTERS 11

// FSM states.
#define S_IN_PROGRESS -1
#define S_START 0
#define S_NUMBER 1
#define S_IDENTIFIER 2
#define S_LOG_OR 3
#define S_DELIMITER 4
#define S_LOG_AND 5
#define S_DIVISION 6
#define S_LINE_COMMENT 7
#define S_BLOCK_COMMENT_BEGIN 8
#define S_BLOCK_COMMENT_END 9
#define S_FINAL 10
#define S_ERROR 11
#define S_BLOCK_COMMENT 12

// FSM letters.
#define L_UNKNOWN -1
#define L_NUMBER 0
#define L_SYMBOL 1
#define L_SPACE 2
#define L_SLASH 3
#define L_DELIMITER 4
#define L_STAR 5
#define L_EOL 6
#define L_EOF 7
#define L_TABULATION 8
#define L_AMPERSAND 9
#define L_V_STICK 10

class FSM {
public:
	FSM();
	~FSM();

	int parse(std::string::iterator end, std::string::iterator* letter);
	int getState() { return currentState; }
	int getLetterNumber(char symbol);
	std::string getBuf() { return buf; }
	int getShift() { return shift; }
	void resetShift() { shift = 0; }
	void decShift() { shift--; }

private:
	int transformMatrix[STATES][LETTERS];
	int currentState;
	int prevState;
	std::string buf;
	int shift;
};
