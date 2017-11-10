#include "Encode.h"
#include "Decode.h"
#include <iostream>
using namespace std;

int main()
{
	string code = "ac";
	Encode obj;
	obj.encode(code);

	string message1 = "_.. __.";
	Decode Test1(message1);

	cout << endl;
	system("pause");
	return 0;
}