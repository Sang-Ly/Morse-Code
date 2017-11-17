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

	// Build root of tree to be a blank character, if we can make root null would be nice
	// else a blank character is fine

	Morse_Code_Tree build_Tree;
	build_Tree.buildMorseCodeTreeWrapper(' ', "");
	
	// Run through while loop, first part is insert into map
	// second part is to build tree

	while (inFile.is_open() && !inFile.eof()) {
		getline(inFile, path);
		letter = path[0];
		path = path.substr(1, path.size());
		morse_Code_Map[letter] = path;
		build_Tree.buildMorseCodeTreeWrapper(letter, path);
	}
	
	// Used try and catch for error checking to see if user enter invalid characters other than morse
	// code, a letter or a blank space

		for (int i = 0; i < message.size(); i++) {
			try {
				if (message[i] == '.' || message[i] == '_' || isalpha(message[i]) || message[i] == ' '){}
				else throw i;
			}
			catch (int pos){
				cout << "invalid character at position: " << pos << endl;
				break;
			}
	}
		
	// When try and catch find no error we either check to see if it needs to be encode or decode
	// here to assume that the user will pick either encoding or decoding 
	// But if needed we can mix match
	// for example code: "a _..."
	// and user want decode, the new code: "a b"

	if (isalpha(message[0])) {
		encode(message);
	}
	else {
		build_Tree.decode(message);
	}
}

void Morse_Code::encode(string code) {
	string expression;
	for (int i = 0; i < code.size(); i++) {
		expression += morse_Code_Map[code[i]] + " ";
	}
	cout << expression << endl;
}