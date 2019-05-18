#include <iostream>
#include "BTS.h"

using namespace std;

int main()
{
	BST<int> tree;
	tree.insert(5);
	tree.insert(7);
	tree.insert(1);
	tree.insert(3);
	tree.insert(9);
	tree.insert(2);

    for (auto it = tree.begin(); it != tree.end(); ++it)
		cout << *it << endl;

	cout <<"Size: "<< tree.size() << endl << endl;

	tree.remove(7);
	for (auto it = tree.begin(); it != tree.end(); ++it)
		cout << *it << endl;
	cout <<"Size: "<< tree.size() << endl << endl;

	auto it = tree.find(1);
	cout << *it << endl;


	return 0;
}
