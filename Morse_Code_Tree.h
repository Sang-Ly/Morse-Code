#pragma once
#include <iostream>
using namespace std;

class Morse_Code_Tree
{
private:

	// create morse code tree (mcTree)

	struct mcTree {
		char data;
		mcTree* left;
		mcTree* right;
	};
	mcTree* root;

	// create build morse code tree and the morse code tree itself

	mcTree* build_Morse_Code_Tree(char, string, mcTree*, int);
	mcTree* decode_Message(string, mcTree*, int);
public:

	// mcTree wrapper, decode, build root

	Morse_Code_Tree();
	void build_Morse_Code_Tree_Wrapper(char, string);
	mcTree* build_root(char);
	void decode_Message_Wrapper(string);
};

