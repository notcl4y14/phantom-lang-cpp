#pragma once
#include <string>
#include <vector>
#include "token.h"

using namespace std;

class Lexer {
public:
	int pos;
	string code;

	Lexer(string code);
	~Lexer();

	string at(int range);
	string next(int delta);
	string yum(int delta);
	bool not_eof();

	vector<Token> lexerize();
	Token lexerize_number();
	Token lexerize_string();
};