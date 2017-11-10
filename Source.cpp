#include "Encode.h"
#include "Decode.h"
#include <iostream>
using namespace std;

int main()
{
	string code = "ac";
	Encode obj;
	obj.encode(code);

	string message = "_.. __.";
	Decode Message;
	Message.decode(message);

	cout << endl;
	system("pause");
	return 0;
}