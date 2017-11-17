#include <iostream>
#include "Morse_Code.h"
using namespace std;

int main() {

	string encodeMessage = "ac";
	Morse_Code encode(encodeMessage);		// Will print ._ _._.	

	string decodeMessage = "_.. __.";
	Morse_Code decode(decodeMessage);		// Will print dg

	cout << endl;

	/*
	// Run this code for fun!

	string message1 = ".__ .";
	string message2 = "._ ._. .";
	string message3 = ".._. .. _. .. ... ....";

	Morse_Code code1(message1);
	cout << " ";

	Morse_Code code2(message2);
	cout << " ";

	Morse_Code code3(message3);
	cout << " ";
	
	*/

	cout << endl;
	system("pause");
	return 0;
}