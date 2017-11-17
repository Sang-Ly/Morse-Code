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

void Morse_Code_Tree::build_Morse_Code_Tree_Wrapper(char letter, string path) {

	// This check to see if I need to build a root or continue to build tree

	if (letter != ' ') {
		build_Morse_Code_Tree(letter, path, root, 0);
	}
	else{
		root = build_root(' ');
	}
}

Morse_Code_Tree::mcTree* Morse_Code_Tree::build_Morse_Code_Tree(char letter, string path, mcTree* rt, int i) {
	if (rt == NULL) {
		rt = new mcTree;
		rt->left = NULL;
		rt->right = NULL;
	}

	// goes left or right depends on . or _
	// When reaches Null insert the letter into that position

	if (path[i] == '.') {
		rt->left = build_Morse_Code_Tree(letter, path, rt->left, i + 1);
	}
	else if (path[i] == '_') {
		rt->right = build_Morse_Code_Tree(letter, path, rt->right, i + 1);
	}
	else {
		rt->data = letter;
	}
	return rt;
}

void Morse_Code_Tree::decode_Message_Wrapper(string code) {

	// since using token here is difficult 
	// I made a decode wrapper to run through message
	// and pass message to morse code tree

	int i = 0;
	string temp;
	while (i != code.size()) {
		temp += code[i];
		if (isspace(code[i + 1]) || code[i + 1] == NULL) {
			decode_Message(temp, root, 0);
			temp = "";
			if (code[i + 1] != NULL) {
				i++;
			}
		}
		i++;
	}
}

Morse_Code_Tree::mcTree* Morse_Code_Tree::decode_Message(string code, mcTree* rt, int index) {
	
	// if . goes left
	// if _ goes right
	// and print out letter when code reaches NULL

	if (code[index] == '.') {
		if (code[index + 1] != NULL) {
			rt->left = decode_Message(code, rt->left, index + 1);
		}
		else
			cout << rt->left->data;
	}
	else if (code[index] == '_') {
		if (code[index + 1] != NULL) {
			rt->right = decode_Message(code, rt->right, index + 1);
		}
		else
			cout << rt->right->data;
	}
	return rt;
}