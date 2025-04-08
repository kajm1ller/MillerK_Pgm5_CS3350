#include "BinaryNode.h"
#include "BinaryTreeInterface.h"

#pragma once
#ifndef LINKED_B_TREE_H
template <typename T>
class LinkedBTree : public BinaryTreeInterface<T>
{
private:
	BinaryNode<T>* pRoot;

protected:

	int getHeightHelper(BinaryNode<T>* x) const;
	BinaryNode<T>* balancedAdd(BinaryNode<T>* x, BinaryNode<T>* y);
	void destroyTree(BinaryNode<T>* x);
	void inorder(FunctionType, BinaryNode<T>* x) const;
	BinaryNode<T>* findNode(BinaryNode<T>* x, const T& y, bool& z)const;
	// more protected helper functions omitted
public:
	void inorderTraverse(FunctionType) const;
	LinkedBTree() { pRoot = nullptr; };
	LinkedBTree()(const T& rootItem) { pRoot = new BinaryNode<T>(rootItem); };
	bool isEmpty() const { return pRoot == nullptr; };
	int getHeight() const { return getHeightHelper(pRoot); };
	int getNumberOfNodes() const { return BinaryNode<T>::getNodeCount(); };
	T getRootData() const { return pRoot->getItem(); };
	void setRootData(const T& x) { pRoot->setItem(x); };
	bool add(const T& x) { return balancedAdd(pRoot, new BinaryNode<T>(x)); };
	void clear() { destroyTree(pRoot); pRoot = nullptr; };
	bool contains(const T& x) const;
	
	// more public interface functions omitted
};


#endif LINKED_B_TREE_H