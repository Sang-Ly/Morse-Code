#include "Decode.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

Decode::Decode(string message) {
	ifstream inFile;
	string path;
	char letter;
	inFile.open("Morse Code.txt");

	while (inFile.is_open() && !inFile.eof()) {
		getline(inFile, path);
		letter = path[0];
		path = path.substr(1, path.size());
		map[path] = letter;
	}

	root = buildTree(root, "");

	int count = 0;
	string temp;
	while (count != message.size()) {
		temp += message[count];
		if (isspace(message[count + 1]) || message[count + 1] == NULL) {
			decodeMessage(root, temp, 0);
			temp = "";
			if (message[count + 1] != NULL) {
				count++;
			}
		}
		count++;
	}
}

Decode::BT* Decode::buildTree(BT *rt, string path) {
	if (rt == NULL) {
		rt = new BT;
		rt->data = map[path];
		map.erase(path);
		rt->left = NULL;
		rt->right = NULL;
	}
	
	if(map.count(path+=".")) {
		rt->left = buildTree(rt->left, path);
		path.erase(path.begin() + (path.size() - 1));
		rt->right = buildTree(rt->right, path += "_");
	}
	return rt;
}

Decode::BT* Decode::decodeMessage(BT* rt, string message, int i) {
	if (message[i] == '.') {
		if (message[i + 1] != NULL) {
			rt->left = decodeMessage(rt->left, message, i + 1);
		}
		else
			cout << rt->left->data;
	}
	else if (message[i] == '_') {
		if (message[i + 1] != NULL) {
			rt->right = decodeMessage(rt->right, message, i + 1);
		}
		else
			cout << rt->right->data;
	}
	else {
		cout << rt->data << endl;
	}
	return rt;
}