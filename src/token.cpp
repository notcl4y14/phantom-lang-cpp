#include "token.h"
#include <string>

using namespace std;

Token::Token(int type, std::string value) {
    this->type = type;
    this->value = value;
}

Token::~Token() {}

bool Token::matches(int type, std::string value) {
    return this->type == type && this->value == value;
}

std::string Token::_string() {
    return "Token { type: " + std::to_string(type) + ", value: \"" + value + "\" }";
}