#include <iostream>
#include "Morse_Code.h"
using namespace std;

int main() {

	string this_Should_Throw_Error_1 = "112";
	Morse_Code throw_error1(this_Should_Throw_Error_1);		// this should throw error at position 1

	string this_Should_Throw_Error_2 = ".._. +=/";			// this should throw error at position 6
	Morse_Code throw_error2(this_Should_Throw_Error_2);

	string encode_Message = "ac";
	Morse_Code encode(encode_Message);		// Will print ._ _._.	

	string decode_Message = "_.. __.";
	Morse_Code decode(decode_Message);		// Will print dg

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