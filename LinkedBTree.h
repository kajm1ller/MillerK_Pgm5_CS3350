#pragma once
#ifndef LINKED_BTREE_H
#define LINKED_BTREE_H

#include <cassert>
#include <algorithm>
#include <iostream>
#include <string>
#include "BinaryNode.h"
#include "BinaryTreeInterface.h"

template <typename T>
class LinkedBTree : public BinaryTreeInterface<T>
{
private:
    BinaryNode<T>* pRoot;

protected:
	// Inherited from BinaryTreeInterface
	int getHeightHelper(BinaryNode<T>* subTreePtr) const;
	BinaryNode<T>* balancedAdd(BinaryNode<T>* subTreePtr, BinaryNode<T>* newNodePtr);
	void destroyTree(BinaryNode<T>* subTreePtr);
	void preorder(typename BinaryTreeInterface<T>::FunctionType visit, BinaryNode<T>* treePtr) const;
	void inorder(typename BinaryTreeInterface<T>::FunctionType visit, BinaryNode<T>* treePtr) const;
	void postorder(typename BinaryTreeInterface<T>::FunctionType visit, BinaryNode<T>* treePtr) const;
	BinaryNode<T>* findNode(BinaryNode<T>* treePtr, const T& target, bool& success) const;
	BinaryNode<T>* copyTree(const BinaryNode<T>* treePtr) const;

public:

	// Constructors and Destructors
	LinkedBTree();
	LinkedBTree(const T& rootItem);
	LinkedBTree(const T& rootItem, const LinkedBTree<T>* x, const LinkedBTree<T>* y);
	LinkedBTree(const LinkedBTree<T>& tree);
	virtual ~LinkedBTree();

	// Various Helper Methods
	
	bool isEmpty() const override;
	int getHeight() const override;
	int getNumberOfNodes() const override;
	T getRootData() const override;
	void setRootData(const T& newData) override;
	bool add(const T& newData) override;
	void clear() override;
	bool contains(const T& anEntry) const override;
	void displayTree() const;
    
    // Traversal methods
    void preorderTraverse(typename BinaryTreeInterface<T>::FunctionType visit) const override;
    void inorderTraverse(typename BinaryTreeInterface<T>::FunctionType visit) const override;
    void postorderTraverse(typename BinaryTreeInterface<T>::FunctionType visit) const override;

    // Additional methods
    bool replace(const T& item, const T& replacementItem);
    void displayVisualTree(BinaryNode<T>* subTreePtr, int totalSpaces) const;
	BinaryNode<T>* getRootNode() const { return pRoot; } // Added to get the root node
};

template <typename T>
LinkedBTree<T>::LinkedBTree()
{
	pRoot = nullptr;
}

template <typename T>
LinkedBTree<T>::LinkedBTree(const T& rootItem)
{
	pRoot = new BinaryNode<T>(rootItem); // Properly initialize pRoot
}

template<typename T>
inline LinkedBTree<T>::LinkedBTree(const T& rootItem, const LinkedBTree<T>* x, const LinkedBTree<T>* y)
{
	pRoot = new BinaryNode<T>(rootItem);
	if (x != nullptr) {
		pRoot->setLeft(x->pRoot);
	}
	if (y != nullptr) {
		pRoot->setRight(y->pRoot);
	}

}

template<typename T>
inline LinkedBTree<T>::LinkedBTree(const LinkedBTree<T>& tree)
{
	if (tree.pRoot == nullptr) {
		pRoot = nullptr;
	}
	else {
		pRoot = copyTree(tree.pRoot);
	}
}

template<typename T>
inline LinkedBTree<T>::~LinkedBTree()
{
	clear();
}

template<typename T>
inline void LinkedBTree<T>::preorderTraverse(typename BinaryTreeInterface<T>::FunctionType visit) const
{
	if (pRoot != nullptr) {
		preorder(visit, pRoot);
	}
	else {
		std::cout << "Tree is empty" << std::endl;
	}
}

template<typename T>
inline void LinkedBTree<T>::inorderTraverse(typename BinaryTreeInterface<T>::FunctionType visit) const
{
	if (pRoot != nullptr) {
		inorder(visit, pRoot);
	}
	else {
		std::cout << "Tree is empty" << std::endl;
	}
}

template<typename T>
inline void LinkedBTree<T>::postorderTraverse(typename BinaryTreeInterface<T>::FunctionType visit) const
{
	if (pRoot != nullptr) {
		postorder(visit, pRoot);
	}
	else {
		std::cout << "Tree is empty" << std::endl;
	}
}

template<typename T>
inline bool LinkedBTree<T>::replace(const T& item, const T& replacementItem)
{
	if (findNode(pRoot, item, true)) {
		pRoot->setItem(replacementItem);
		return true;
	}
	else {
		return false;
	}
}

template<typename T>
inline void LinkedBTree<T>::displayVisualTree(BinaryNode<T>* subTreePtr, int totalSpaces) const
{
	if (subTreePtr != nullptr) {
		displayVisualTree(subTreePtr->getRight(), totalSpaces++);
		for (int i = 0; i < totalSpaces; ++i) {
			std::cout << "";
		}
		std::cout << subTreePtr->getItem();
		displayVisualTree(subTreePtr->getLeft(), totalSpaces++);
	}
	else {
		for (int i = 0; i < totalSpaces; ++i) {
			std::cout << "";
			std::cout << "-----";
		}
	}
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
inline void LinkedBTree<T>::preorder(typename BinaryTreeInterface<T>::FunctionType visit, BinaryNode<T>* treePtr) const
{
	if (treePtr != nullptr)
	{
		T item = treePtr->getItem();
		visit(item);
		preorder(visit, treePtr->getLeft());
		preorder(visit, treePtr->getRight());
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
inline void LinkedBTree<T>::postorder(typename BinaryTreeInterface<T>::FunctionType visit, BinaryNode<T>* treePtr) const
{
	if (treePtr != nullptr)
	{
		T item = treePtr->getItem();
		visit(item);
		postorder(visit, treePtr->getLeft());
		postorder(visit, treePtr->getRight());
	}
}

template<typename T>
BinaryNode<T>* LinkedBTree<T>::findNode(BinaryNode<T>*, const T&, bool&) const
{
	return nullptr;
}

template<typename T>
inline BinaryNode<T>* LinkedBTree<T>::copyTree(const BinaryNode<T>* treePtr) const
{
	return nullptr;
}

template<typename T>
inline void LinkedBTree<T>::clear()
{
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



template<typename T>
inline bool LinkedBTree<T>::isEmpty() const
{
	if (pRoot == nullptr) {
		return true;
	}
	
	return false;
}

template<typename T>
inline int LinkedBTree<T>::getHeight() const
{
	if (pRoot == nullptr) {
		return 0;
	}
	else {
		return getHeightHelper(pRoot);
	}
}

template<typename T>
inline int LinkedBTree<T>::getNumberOfNodes() const
{
	if (pRoot == nullptr) {
		return 0;
	}
	else {
		return pRoot->getNodeCount();
	}
	
}

template<typename T>
inline T LinkedBTree<T>::getRootData() const
{
	return T();
}

template<typename T>
inline void LinkedBTree<T>::setRootData(const T& newData)
{
	pRoot->setItem(newData);
}

template<typename T>
inline bool LinkedBTree<T>::add(const T& newData)
{
	if (pRoot == nullptr) {
		pRoot = new BinaryNode<T>(newData);
	}
	else {
		BinaryNode<T>* newNodePtr = new BinaryNode<T>(newData);
		pRoot = balancedAdd(pRoot, newNodePtr);
	}
	return true;
}

template <typename T>
void LinkedBTree<T>::displayTree() const
{
	displayVisualTree(pRoot, 0);
}

#endif // LINKED_BTREE_H