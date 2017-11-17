#include "Morse_Code.h"
#include "Morse_Code_Tree.h"
#include <fstream>
#include <map>
#include <iostream>
#include <string>
using namespace std;

Morse_Code::Morse_Code(string code){
	ifstream inFile;
	string path;
	char letter;
	inFile.open("Morse Code.txt");

	// Build root of tree to be a blank character, if we can make root null would be nice
	// else a blank character is fine

	Morse_Code_Tree Decode_Message;
	Decode_Message.build_Morse_Code_Tree_Wrapper(' ', "");
	
	// Run through while loop, first part is insert into map
	// second part is to build tree

	while (inFile.is_open() && !inFile.eof()) {
		getline(inFile, path);
		letter = path[0];
		path = path.substr(1, path.size());
		morse_Code_Map[letter] = path;
		Decode_Message.build_Morse_Code_Tree_Wrapper(letter, path);
	}
	inFile.close();
		
	// When try and catch find no error we either check to see if it needs to be encode or decode
	// here to assume that the user will pick either encoding or decoding 
	// But if needed we can mix match
	// for example code: "a _..."
	// and user want decode, the new code: "a b"
	
	if (error_check(code)) {
		if (isalpha(code[0])) {
			encode(code);
		}
		else {
			Decode_Message.decode_Message_Wrapper(code);
		}
	}
	else { EXIT_FAILURE; }
}

bool Morse_Code::error_check(string code) {

	// This will handle error checking
	for (int i = 0; i < code.size(); i++) {
		try {
			if (code[i] == '.' || code[i] == '_' || isalpha(code[i]) || code[i] == ' ') {}
			else throw i;
		}
		catch (int pos) {
			cout << "Invalid character at position: " << pos + 1 << endl;
			return false;
			break;
		}
	}
	return true;
}

void Morse_Code::encode(string code) {
	string message;
	for (int i = 0; i < code.size(); i++) {
		message += morse_Code_Map[code[i]] + " ";
	}
	cout << message << endl;
}