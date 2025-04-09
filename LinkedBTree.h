#include "BinaryNode.h"
#include "BinaryTreeInterface.h"
#include <iostream>

#pragma once
#ifndef LINKED_B_TREE_H
#define LINKED_B_TREE_H
template <typename T>
class LinkedBTree : public BinaryTreeInterface<T>
{
public:

	LinkedBTree();
	LinkedBTree(const T& rootItem);
	
private:
	BinaryNode<T>* pRoot;

protected:

	int getHeightHelper(BinaryNode<T>* x) const;
	BinaryNode<T>* balancedAdd(BinaryNode<T>* x, BinaryNode<T>* y);
	void destroyTree(BinaryNode<T>* x);
	void inorder(typename BinaryTreeInterface<T>::FunctionType, BinaryNode<T>* nodePtr) const;
	BinaryNode<T>* findNode(BinaryNode<T>* x, const T& y, bool& z)const;
	bool isEmpty() const { return pRoot == nullptr; };
	int getHeight() const { return getHeightHelper(pRoot); };
	int getNumberOfNodes() const { return BinaryNode<T>::getNodeCount(); };
	T getRootData() const { return pRoot->getItem(); };
	void setRootData(const T& x) { pRoot->setItem(x); };
	bool add(const T& x) { return balancedAdd(pRoot, new BinaryNode<T>(x)); };
	void clear() { destroyTree(pRoot); pRoot = nullptr; };
	bool contains(const T& x) const;
	
};




#endif LINKED_B_TREE_H