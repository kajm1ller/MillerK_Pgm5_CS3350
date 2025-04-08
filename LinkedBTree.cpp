#include "LinkedBTree.h"
#include "BinaryNode.h"
#include "BinaryTreeInterface.h"
#include <string>

template <typename T>
int LinkedBTree<T>::getHeightHelper(BinaryNode<T>* x) const 
{
	if (x == nullptr) {
		return 0;
	}
	else {
		int leftHeight = getHeightHelper(x->getLeft());
		int rightHeight = getHeightHelper(x->getRight());
		return 1 + std::max(leftHeight, rightHeight);
	}
}

template<typename T>
BinaryNode<T>* LinkedBTree<T>::balancedAdd(BinaryNode<T>* x, BinaryNode<T>* y)
{ 
	if (x == nullptr) 
	{
		return nullptr;
    }

	else
	{
		BinaryNode<T>* newNode = new BinaryNode<T>(x->getItem());
		newNode->setLeft(balancedAdd(x->getLeft(), x));
		newNode->setRight(balancedAdd(x->getRight(), x));
		return newNode;
	}
}

template<typename T>
void LinkedBTree<T>::destroyTree(BinaryNode<T>* x)
{
	if (x == nullptr) {
		return;
	}
	else {
		destroyTree(x->getLeft());
		destroyTree(x->getRight());
		delete x;
	}
}

template<typename T>
void LinkedBTree<T>::inorder(FunctionType, BinaryNode<T>*) const // literally what the fuck does FunctionType mean
{

}

template<typename T>
BinaryNode<T>* LinkedBTree<T>::findNode(BinaryNode<T>*, const T&, bool&) const
{
	return nullptr;
}

template<typename T>
void LinkedBTree<T>::inorderTraverse(FunctionType) const // Refer to line 50
{
}

template<typename T>
bool LinkedBTree<T>::contains(const T& x) const
{
	return false;
}


template class LinkedBTree<BinaryNode<std::string>>;

