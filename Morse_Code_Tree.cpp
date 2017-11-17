#include "Morse_Code_Tree.h"
#include <iostream>
#include <string>
using namespace std;

Morse_Code_Tree::Morse_Code_Tree() {
	root = NULL;
}

// This is where i built the root 

Morse_Code_Tree::mcTree* Morse_Code_Tree::build_root(char letter) {
	mcTree* n = new mcTree;
	n->data = NULL;
	n->left = NULL;
	n->right = NULL;

	return n;
}

void Morse_Code_Tree::buildMorseCodeTreeWrapper(char letter, string path) {

	// This check to see if I need to build a root or continue to build tree

	if (letter != ' ') {
		buildMorseCodeTree(letter, path, root, 0);
	}
	else{
		root = build_root(' ');
	}
}

Morse_Code_Tree::mcTree* Morse_Code_Tree::buildMorseCodeTree(char letter, string path, mcTree* rt, int i) {
	
	
	if (rt == NULL) {
		rt = new mcTree;
		rt->left = NULL;
		rt->right = NULL;
	}

	// goes left or right depends on . or _
	// When reaches Null insert the letter into that position

	if (path[i] == '.') {
		rt->left = buildMorseCodeTree(letter, path, rt->left, i + 1);
	}
	else if (path[i] == '_') {
		rt->right = buildMorseCodeTree(letter, path, rt->right, i + 1);
	}
	else {
		rt->data = letter;
	}
	return rt;
}

void Morse_Code_Tree::decode(string code) {

	// since using token here is difficult 
	// I made a decode wrapper to run through message
	// and pass message to morse code tree

	int i = 0;
	string temp;
	while (i != code.size()) {
		temp += code[i];
		if (isspace(code[i + 1]) || code[i + 1] == NULL) {
			MorseCodeTree(temp, root, 0);
			temp = "";
			if (code[i + 1] != NULL) {
				i++;
			}
		}
		i++;
	}
}

Morse_Code_Tree::mcTree* Morse_Code_Tree::MorseCodeTree(string code, mcTree* rt, int count) {
	
	// if . goes left
	// if _ goes right
	// and print out letter when code reaches NULL

	if (code[count] == '.') {
		if (code[count + 1] != NULL) {
			rt->left = MorseCodeTree(code, rt->left, count + 1);
		}
		else
			cout << rt->left->data;
	}
	else if (code[count] == '_') {
		if (code[count + 1] != NULL) {
			rt->right = MorseCodeTree(code, rt->right, count + 1);
		}
		else
			cout << rt->right->data;
	}
	return rt;
}