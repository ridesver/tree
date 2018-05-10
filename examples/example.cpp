#include <iostream>
#include "tree.hpp"

using namespace std; 

int main() {
	tree_t<int> tree;
	char op;
	while (cin >> op && op != 'q') {
		int num;
		switch (op) {
		case '=':
			tree.print(cout);
			break;
		case '+':
			if (cin >> num) {
				tree.insert(num);
				tree.print(cout);
			}
			else {
				cout << "An error has occured while reading input data\n";
				exit(0);
			}
			break;
		case '?':
			if (cin >> num) {
				if (tree.find(num)) {
					cout << "true\n";
				}
				else {
					cout << "false\n";
				}
			}
			else {
				cout << "An error has occured while reading input data\n";
				exit(0);
			}
			break;
		}
	}
	return 0;
}
