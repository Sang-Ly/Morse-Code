#include "Morse_Code.h"
#include "Morse_Code_Tree.h"
#include <fstream>
#include <map>
#include <iostream>
#include <string>
using namespace std;

Morse_Code::Morse_Code(string message){
	ifstream inFile;
	string path;
	char letter;
	inFile.open("Morse Code.txt");

	while (inFile.is_open() && !inFile.eof()) {
		getline(inFile, path);
		letter = path[0];
		path = path.substr(1, path.size());
		morse_Code_Map[letter] = path;
		Morse_Code_Tree build_Tree(letter, path);
	}

	if (isalpha(message[0])) {
		encode(message);
	}
	else {
		//orse_Code_Tree decode(message);
	}
}

void Morse_Code::encode(string code) {
	string expression;
	for (int i = 0; i < code.size(); i++) {
		expression += morse_Code_Map[code[i]] + " ";
	}
	cout << expression << endl;
}