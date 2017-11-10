#pragma once
#include "Encode.h"
#include <map>
using namespace std;
class Encode
{
public:
	Encode();
	void encode(string code);

private:
	map<char, string> map;
	string expression;
};