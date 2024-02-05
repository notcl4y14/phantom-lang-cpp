#include "token.h"
#include <string>

using namespace std;

class Token {
public:
	int type;
	string value;

	Token(int type, string value) {
		this->type = type;
		this->value = value;
	};

	~Token() {};

	bool matches(int type, string value) {
		return this->type == type && this->value == value;
	};

	string _string() {
		return "Token { type: " + to_string(type) + ", value: " + value + " }";
	};
};