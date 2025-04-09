#include <iostream>
#include "BinaryNode.h"
#include "LinkedBTree.h"
#include <string>


int main() {

	LinkedBTree<std::string> tree("Hello!");
	tree.add("World");
	std::cout << tree;

	



	return 0;
}