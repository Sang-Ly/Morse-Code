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

	mcTree* buildMorseCodeTree(char, string, mcTree*, int);
	mcTree* MorseCodeTree(string, mcTree*, int);
public:

	// mcTree wrapper, decode, build root

	Morse_Code_Tree();
	void buildMorseCodeTreeWrapper(char, string);
	mcTree* build_root(char);
	void decode(string);
};

