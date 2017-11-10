#include "Encode.h"
#include "Decode.h"
#include <iostream>
using namespace std;

int main()
{
	
	string code = "ac";
	Encode obj;
	obj.encode(code);

	string message = "... ._ _. __.";

	Decode Test(message);

	cout << endl << endl;

	string message1 = "_.. __.";
	Decode Test1(message1);

	cout << endl << endl;

	string message2 = "__. ___ _";
	Decode Test2(message2);

	cout << " ";

	string message3 = "_ .... .";
	Decode Test3(message3);

	cout << " ";

	string message4 = "_._. ___ _.. .";
	Decode Test4(message4);

	cout << " ";

	string message5 = ".__ ___ _._ .. _. __.";
	Decode Test5(message5);

	cout << " ";

	cout << endl << endl;
	system("pause");
	return 0;
}