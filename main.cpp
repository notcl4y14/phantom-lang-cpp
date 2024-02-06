#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <streambuf>
#include "src/token.h"
#include "src/lexer.h"
#include "util/vector.h"

using namespace std;

vector<string> valid_args {"--show-tokens"};

vector<string> parse_args(int argc, char const *argv[]) {
	vector<string> args;

	if (argc == 1) {
		return args;
	}

	for (int i = 0; i < argc; i += 1) {
		string arg = argv[i];

		if (arg[0] == '-') {
			if (!vector_find(valid_args, arg)) {
				throw "Unknown parameter \"" + arg + "\"";
			}
		}

		args.push_back(arg);
	}

	return args;
}

string get_filename(vector<string> args) {
	if (args.size() == 0) {
		throw static_cast<string>("Please specify filename!");
	}

	for (int i = 0; i < args.size(); i += 1) {
		string arg = args.at(i);

		if (arg[0] != '-') {
			return arg;
		}
	}

	throw static_cast<string>("Please specify filename!");
}

int main(int argc, char const *argv[])
{
	vector<string> args;
	string filename;
	string code;

	try {
		args = parse_args(argc, argv);
	} catch (string error) {
		std::cout << error << "\n";
		return 1;
	}

	try {
		filename = get_filename(args);
	} catch (string error) {
		std::cout << error << "\n";
		return 1;
	}

	try {
		// https://stackoverflow.com/a/2602060
		ifstream file(filename);
		string str((std::istreambuf_iterator<char>(file)),
		         std::istreambuf_iterator<char>());
		code = str;
	} catch (...) {
		std::cout << "File " << filename << " not found\n";
		return 1;
	}

	Lexer lexer = Lexer(code);
	std::vector<Token> tokens = lexer.lexerize();

	if (vector_find(args, "--show-tokens")) {
		for (int i = 0; i < tokens.size(); i += 1) {
			std::cout << tokens.at(i)._string() << "\n";
		}
	}

	return 0;
}