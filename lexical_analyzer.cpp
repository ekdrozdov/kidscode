#include "lexical_analyzer.h"

using namespace std;

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
	ifstream file;
	file.open(filename);
	fsm.reset(filename);
	while (file) {
		int lexemType = fsm.parse(&file);
		if (lexemType != S_ERROR) {
			Token token = makeToken(fsm.getBuf(), lexemType);
			if (token.correct())
				std::cout << token.readable(fsm.getBuf(), 1);
			file.unget();
		}
		else {
			errorsCount++;
			std::cout << std::endl;
			std::cout << fsm.getFilename() << ":" << fsm.getString() <<
				":" << fsm.getPosition() << ": ";
			std::cout << "\e[1merror:\e[0m expected _analyze_info_\n";
		}
	}
	std::cout << std::endl;
	if (errorsCount != 0)
		std::cout << "Total errors: " << errorsCount << std::endl;
	file.close();
}
