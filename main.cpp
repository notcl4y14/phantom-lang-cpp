#include <iostream>
#include "src/token.h"
#include "src/token.cpp"

int main(int argc, char const *argv[])
{
	// std::cout << "Hello World!\n";
	Token token = Token(TT_Operator, "+");
	std::cout << token._string() << "\n";
	return 0;
}