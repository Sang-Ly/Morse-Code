#pragma once
#include <iostream>
using namespace std;
class Morse_Code_Tree
{
public:
	Morse_Code_Tree(char, string);
private:
	void decode(string);
	struct mcTree {
		char data;
		mcTree *left = NULL;
		mcTree *right = NULL;
	};
	mcTree *root;
	mcTree* buildTree(mcTree*, char, string, int);
};

