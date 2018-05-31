#include "lexical_analyzer.h"

LexicalAnalyzer::LexicalAnalyzer() {
	errorsCount = 0;
}

LexicalAnalyzer::~LexicalAnalyzer() {
	errorsCount = 0;
}


Token LexicalAnalyzer::makeToken(std::string lexemName, int lexemType) {
	Token token;
	int index = -1;
	int nTable = -1;

	switch (lexemType) {
		case S_START:
			break;
		case S_NUMBER:
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
		case S_LOG_OR:
			nTable = N_T_DELIMITERS;
			index = delimiters.find(lexemName);
			if (index == -1) {
				cout << "fsm returned unknown operation type\n";
			}
			break;
		case S_DELIMITER:
			nTable = N_T_DELIMITERS;
			index = delimiters.find(lexemName);
			if (index == -1) {
				cout << "fsm returned unknown delimiter type\n";
			}
			break;
		case S_LOG_AND:
			nTable = N_T_DELIMITERS;
			index = delimiters.find(lexemName);
			if (index == -1) {
				cout << "fsm returned unknown operation type\n";
			}
			break;
		case S_DIVISION:
			nTable = N_T_DELIMITERS;
			index = delimiters.find(lexemName);
			if (index == -1) {
				cout << "fsm returned unknown operation type\n";
			}
			break;
		case S_LINE_COMMENT:
			//std::cout << "S_LINE_COMMENT\n";
			break;
		case S_BLOCK_COMMENT:
			//std::cout << "S_BLOCK_COMMENT\n";
			break;
		default:
			std::cout << "error: makeToken: unknown lexem type: " << 
				lexemType << std::endl;
			break;
	}

	token.nTable = nTable;
	token.index = index;
	return token;
}

void LexicalAnalyzer::scanCode(std::string filename) {
	errorsCount = 0;
	currentLine = 0;
	ifstream file;
	file.open(filename);

	while (file) {
		std::string line;
		std::getline(file, line);
		fsm.resetShift();
		currentLine++;
		line.append("\n");
		std::string::iterator it = line.begin();
		std::string::iterator end = line.end();

		while (it != end) {
			int lexemType = fsm.parse(end, &it);

			if (lexemType != S_ERROR) {
				if (lexemType != S_IN_PROGRESS) {
					Token token = makeToken(fsm.getBuf(), lexemType);
					if (token.correct())
						std::cout << token.readable(fsm.getBuf(), 1);
				}
				if (it != end) {
					it--;
					fsm.decShift();
				}
			}
			else {
				errorsCount++;
				printErrorMessage(lexemType, filename, line);
			}
		}
	}

	if (errorsCount > 0) {
		std::cout << "Errors total: " << errorsCount << std::endl;
	}
	file.close();
}

void LexicalAnalyzer::printErrorMessage(int lexemType, 
		std::string filename, std::string line) {
	std::cout << std::endl;
	currentPosition = fsm.getShift();
	std::cout << "\e[1m" << filename << ":" <<
		currentLine << ":" << currentPosition;
	std::cout << ": error:\e[0m ";
	switch (lexemType) {
		case S_ERROR:
			std::cout << "invalid character sequence\n";	
			break;
	}
	std::string mark = "\e[1m!\e[0m";
	line.insert(currentPosition, mark);
	cout << '\t' << line << std::endl;
}
