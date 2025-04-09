#include "LinkedBTree.h"
#include "BinaryNode.h"
#include "BinaryTreeInterface.h"
#include <string>

template <typename T>
LinkedBTree<T>::LinkedBTree() 
{
	pRoot = nullptr;
}

template <typename T>
LinkedBTree<T>::LinkedBTree(const T& rootItem)
{
	pRoot->setItem(rootItem);
}

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
	if (x == nullptr) {
		return y;
	}
	else if (y == nullptr) {
		return x;
	}
	else {
		if (x->getLeft() == nullptr) {
			x->setLeft(y);
		}
		else if (x->getRight() == nullptr) {
			x->setRight(y);
		}
		else {
			if (getHeightHelper(x->getLeft()) <= getHeightHelper(x->getRight())) {
				x->setLeft(balancedAdd(x->getLeft(), y));
			}
			else {
				x->setRight(balancedAdd(x->getRight(), y));
			}
		}
		return x;
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
void LinkedBTree<T>::inorder(typename BinaryTreeInterface<T>::FunctionType visit, BinaryNode<T>* nodePtr) const 
{
	if (nodePtr != nullptr)
	{
		inorder(visit, nodePtr->getLeft());

		T item = nodePtr->getItem();
		visit(item);
	}
}

template<typename T>
BinaryNode<T>* LinkedBTree<T>::findNode(BinaryNode<T>*, const T&, bool&) const
{
	return nullptr;
}

template<typename T>
bool LinkedBTree<T>::contains(const T& x) const
{
	if (pRoot == nullptr) {
		return false;
	}
	else {
		bool found = false;
		findNode(pRoot, x, found);
		return found;
	}
}

template class LinkedBTree<BinaryNode<int>>;
template class LinkedBTree<BinaryNode<std::string>>;

