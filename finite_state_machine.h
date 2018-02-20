#pragma once
#include "iostream"

// FSM parameters.
#define STATES 6
#define LETTERS 4

// FSM statuses.
#define START 0
#define WORK 0 
#define STOP 1

// Symbol types.
#define UNKNOWN -1
#define DELIMITER 0
#define NUMBER 1
#define CHARACTER 2
#define OPERATION 3

// FSM states.
#define WRONG -1
#define S_CONSTANT 1
#define S_IDENTIFIER 2
#define S_VARIABLE 3
#define S_OPERATION 4
#define S_DELIMITER 5

class FSM {
public:
	FSM();
	~FSM();

	int parse(std::string lexem);
	void reset();
	int getState() { return currentState; }
	int getSymbolType(char symbol);

private:
	int transformMatrix[STATES][LETTERS];
	int currentState;
};
