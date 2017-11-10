#pragma once
#include "Decode.h"
#include <map>
using namespace std;

class Decode
{
private:
	struct BT {
		char data;
		BT *left = NULL;
		BT *right = NULL;
	};
	BT *root = NULL;
	BT* buildTree(BT *root, string path);
	map<string, char> map;
public:
	Decode(string message);
	BT* decodeMessage(BT* root, string message, int i);
};

