#include "Encode.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

Encode::Encode() {
	ifstream inFile;
	string path;
	char letter;
	inFile.open("Morse Code.txt");

	while (inFile.is_open() && !inFile.eof()) {
		getline(inFile, path);
		letter = path[0];
		path = path.substr(1, path.size());
		map[letter] = path;
	}
}
void Encode::encode(string code) {
	for (int i = 0; i < code.size(); i++) {
		expression += map[code[i]] + " ";
	}
	cout << expression << endl;
}