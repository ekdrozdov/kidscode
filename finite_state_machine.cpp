#include "finite_state_machine.h"

using namespace std;

FSM::FSM() {
	currentState = START;

	transformMatrix[0][0] = 5; 
	transformMatrix[0][1] = 1; 
	transformMatrix[0][2] = 2; 
	transformMatrix[0][3] = 4; 

	transformMatrix[1][0] = -1; 
	transformMatrix[1][1] = 1; 
	transformMatrix[1][2] = -1; 
	transformMatrix[1][3] = -1; 

	transformMatrix[2][0] = -1; 
	transformMatrix[2][1] = 3; 
	transformMatrix[2][2] = 2; 
	transformMatrix[2][3] = -1; 

	transformMatrix[3][0] = -1; 
	transformMatrix[3][1] = 3; 
	transformMatrix[3][2] = 3; 
	transformMatrix[3][3] = -1; 

	transformMatrix[4][0] = -1; 
	transformMatrix[4][1] = -1; 
	transformMatrix[4][2] = -1; 
	transformMatrix[4][3] = -1; 

	transformMatrix[5][0] = -1; 
	transformMatrix[5][1] = -1; 
	transformMatrix[5][2] = -1; 
	transformMatrix[5][3] = -1; 
}

FSM::~FSM() {
	currentState = 0;
}

int FSM::getSymbolType(char symbol) {
	if ((symbol >= '0') && (symbol <= '9')) {
		return NUMBER;
	}
	else if ((symbol >= 'a') && (symbol <= 'z')) {
		return CHARACTER;
	}
	else if (symbol == ';') {
		return DELIMITER;
	}
	else if ((symbol == '+') || (symbol == '*')) {
		return OPERATION;
	}
	else {
		currentState = WRONG;
		return UNKNOWN;
	}
}

int FSM::parse(string lexem) {
	for (auto symbol : lexem) {
		int symbolType = getSymbolType(symbol);
		if ((symbolType != UNKNOWN) && (currentState != WRONG)) {
			currentState = transformMatrix[currentState][symbolType];
		}
	}
	return currentState;
}

void FSM::reset() {
	currentState = START;
}
