#include <iostream>
#include "Morse_Code.h"
using namespace std;

int main() {
	string message = "_.. __.";
	Morse_Code code(message);

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