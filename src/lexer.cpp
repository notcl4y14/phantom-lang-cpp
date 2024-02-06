#include <string>
#include <vector>
#include "lexer.h"
#include "token.h"
#include "../util/string.h"

using namespace std;

string TS_Operators = "+-*/%^";
string TS_Digits = "1234567890";
string TS_Quotes = "\"'";

Lexer::Lexer(string code) {
	this->code = code;
	this->pos = 0;
};

Lexer::~Lexer() {};

string Lexer::at(int range = 1) {
	try {
		return code.substr(pos, range);
	} catch (...) {
		return "";
	}
};

string Lexer::next(int delta = 1) {
	try {
		return code.substr(pos + delta, 1);
	} catch (...) {
		return "";
	}
}

string Lexer::yum(int delta = 1) {
	string prev = at();
	pos += delta;
	return prev;
};

bool Lexer::not_eof() {
	return pos < code.length();
};

vector<Token> Lexer::lexerize() {
	vector<Token> tokens;

	while (not_eof()) {
		string character = at();

		if (string_includes(TS_Operators, character)) {
			tokens.push_back(Token(TT_Operator, character));
		} else if (string_includes(TS_Digits, character)) {
			tokens.push_back(lexerize_number());
		} else if (string_includes(TS_Quotes, character)) {
			tokens.push_back(lexerize_string());
		}

		yum();
	}

	return tokens;
};

Token Lexer::lexerize_number() {
	string num_str = "";
	bool dot = false;

	while (not_eof() && string_includes(TS_Digits + ".", at())) {
		num_str += at();

		if (at() == ".") {
			if (dot) break;
			dot = true;
		}

		yum();
	}

	yum(-1);

	return Token(TT_Number, num_str);
}

Token Lexer::lexerize_string() {
	string str = "";
	string quote = yum();

	while (not_eof() && at() != quote) {
		str += yum();
	}

	return Token(TT_String, str);
}