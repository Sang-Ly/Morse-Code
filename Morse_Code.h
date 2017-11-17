#pragma once
#include <map>
using namespace std;
class Morse_Code
{
public:
	Morse_Code(string);
	bool error_check(string);
private:
	map<char, string> morse_Code_Map;
	void encode(string);
};

