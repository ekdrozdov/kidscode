#include "lexical_analyzer.h"

using namespace std;

LexicalAnalyzer::LexicalAnalyzer() {
	currentLine = 0;
	currentPosition = 0;
}

LexicalAnalyzer::~LexicalAnalyzer() {
	currentLine = 0;
	currentPosition = 0;
}


Token LexicalAnalyzer::makeToken(std::string lexemName, int lexemType) {
	Token token;
	if (lexemType == -1) {
		token.index = -1;
		token.nTable = -1;
		return token;
	}
	int index;
	int nTable;

	switch (lexemType) {
		case S_CONSTANT:
			nTable = N_T_CONSTANTS;
			index = constants.find(lexemName);
			if (index == -1) {
				index = constants.add(lexemName);
			}
			break;

		case S_IDENTIFIER:
			nTable = N_T_KEYWORDS;
			index = keywords.find(lexemName);
			if (index == -1) {
				nTable = N_T_IDENTIFIERS;
				index = identifiers.find(lexemName);
				if (index == -1) {
					index = identifiers.add(lexemName);
				}
			}
			break;
			
		case S_VARIABLE:
			nTable = N_T_IDENTIFIERS;
			index = identifiers.find(lexemName);
			if (index == -1) {
				index = identifiers.add(lexemName);
			}
			break;

		case S_OPERATION:
			nTable = N_T_OPERATIONS;
			index = operations.find(lexemName);
			if (index == -1) {
				cout << "fsm returned unknown operation type\n";
			}
			break;

		case S_DELIMITER:
			nTable = N_T_DELIMITERS;
			index = delimiters.find(lexemName);
			if (index == -1) {
				cout << "fsm returned unknown operation type\n";
			}
			break;
	}
	token.nTable = nTable;
	token.index = index;
	return token;
}

void LexicalAnalyzer::scanCode(string filename) {
	string word = "";
	ifstream file(filename);
	char c;

	fsm.reset();
	while (file) {
		file.get(c);
		if (c == ';') {
			if (word != "") {
				//cout << "word: " << word << endl;
				//cout << "lexem: " << fsm.parse(word) << endl;
				cout << makeToken(word, fsm.parse(word)) << " ";
				fsm.reset();
			}
			word = ";";
			//cout << "word: " << word << endl;
			//cout << "lexem: " << fsm.parse(word) << endl;
			cout << makeToken(word, fsm.parse(word)) << " ";
			fsm.reset();
			word = "";
		}
		else if ((c != ' ') && (c != '\n') && (c != '\0')) {
			word += c;
		}
		else {
			if (word != "") {
				//cout << "word: " << word << endl;
				//cout << "lexem: " << fsm.parse(word) << endl;
				cout << makeToken(word, fsm.parse(word)) << " ";
				fsm.reset();
			}
			word = "";
		}
	}
	file.close();
	cout << endl;

	// Old code.
	/*
	ifstream file(filename);
	char symbol;

	while (file.get(symbol)) {
		cout << "Current symbold: " << symbol << " ";
		int fsmStatus = fsm.step(symbol);
		if (fsmStatus == WORK) {
			cout << "status: WORK\n";
		}
		else if (fsmStatus == STOP) {
			cout << "status: STOP\n";
			fsm.reset();
		}
		if (fsm.step(symbol) != 0) {
			switch(fsm.getState()) {
				case -1:
					cout << "LA: error\n";
					return;
					break;
				case CONSTANT:
					cout << "LA: constant\n";
					break;
				case IDENTIFIER:
					cout << "LA: identifier\n";
					break;
				case VARIABLE:
					cout << "LA: variable\n";
					break;
				default:
					cout << "LA: unknown error\n";
					break;
			}
			fsm.reset();
		}
	}
	file.close();

	if (fsm.getState() == 0) {
		cout << "LA: unexpected end of file\n";
	}
	*/
}
