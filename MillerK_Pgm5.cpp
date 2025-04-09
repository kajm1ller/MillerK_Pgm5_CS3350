#include <iostream>
#include "BinaryNode.h"
#include "LinkedBTree.h"
#include <string>

template <typename T>
void displayNode(T& item)
{
   std::cout << item << " ";
}

int main() {

   LinkedBTree<std::string> tree("Hello!");
   tree.add("World");
   tree.add("Penis");

   tree.preorderTraverse(displayNode<std::string>);
   tree.inorderTraverse(displayNode<std::string>);
   tree.postorderTraverse(displayNode<std::string>);

   tree.displayVisualTree(tree.getRootNode(), 1);

   return 0;
}