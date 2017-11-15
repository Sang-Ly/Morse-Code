#include "Morse_Code_Tree.h"
#include <iostream>
#include <string>
using namespace std;


Morse_Code_Tree::Morse_Code_Tree(char letter, string path) {
	root = NULL;
	root = buildTree(root, letter, path, 0);
}

Morse_Code_Tree::mcTree* Morse_Code_Tree::buildTree(mcTree *rt, char letter, string path, int i) {
	if (rt == NULL) {
		rt = new mcTree;
		rt->left = NULL;
		rt->right = NULL;
		/*root->data = ' ';
		root->left->data = ' ';
		root->right->data = ' ';
		root->left->left = NULL;
		root->left->left = NULL;*/

	}

	


	if (path[i] == '.' && path[i + 1] != NULL) {
		rt->left = buildTree(rt->left, letter, path, i + 1);
	}
	else {
		rt->data = letter;
	}
	if (path[i] == '_' && path[i + 1] != NULL) {
		rt->right = buildTree(rt->right, letter, path, i + 1);
	}
	else {
		
		rt->data = letter;
	}
	
	return rt;
}

void decode(string message) {

}