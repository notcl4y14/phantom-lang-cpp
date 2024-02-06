#pragma once
#include <string>

#define TT_Number 0
#define TT_String 1
#define TT_Identifier 2
#define TT_Literal 3
#define TT_Keyword 4

#define TT_Operator 5
#define TT_Closure 6
#define TT_Symbol 7

#define TT_Comment 8
#define TT_EOF 9

using namespace std;

class Token {
public:
	int type;
	std::string value;

	Token(int type, std::string value);
	~Token();

	bool matches(int type, std::string value);
	std::string _string();
};