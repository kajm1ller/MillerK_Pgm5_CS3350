#pragma once
#ifndef LINKED_BTREE_H
#define LINKED_BTREE_H

#include <cassert>
#include <algorithm>
#include <iostream>
#include "BinaryTreeInterface.h"
#include "BinaryNode.h"

template <typename T>
class LinkedBTree : public BinaryTreeInterface<T>
{
private:
    BinaryNode<T>* pRoot;

protected:
    int getHeightHelper(BinaryNode<T>* subTreePtr) const;
    BinaryNode<T>* balancedAdd(BinaryNode<T>* subTreePtr, BinaryNode<T>* newNodePtr);
    void destroyTree(BinaryNode<T>* subTreePtr);
    void preorder(typename BinaryTreeInterface<T>::FunctionType visit, BinaryNode<T>* treePtr) const;
    void inorder(typename BinaryTreeInterface<T>::FunctionType visit, BinaryNode<T>* treePtr) const;
    void postorder(typename BinaryTreeInterface<T>::FunctionType visit, BinaryNode<T>* treePtr) const;
    BinaryNode<T>* findNode(BinaryNode<T>* treePtr, const T& target, bool& success) const;
    BinaryNode<T>* copyTree(const BinaryNode<T>* treePtr) const;

public:
    // Constructors and Destructor
    LinkedBTree();
    LinkedBTree(const T& rootItem);
    LinkedBTree(const T& rootItem, const LinkedBTree<T>* leftTreePtr, const LinkedBTree<T>* rightTreePtr);
    LinkedBTree(const LinkedBTree<T>& tree);
    virtual ~LinkedBTree();

    // Interface Methods Implementation
    bool isEmpty() const override;
    int getHeight() const override;
    int getNumberOfNodes() const override;
    T getRootData() const override;
    void setRootData(const T& newData) override;
    bool add(const T& newData) override;
    void clear() override;
    bool contains(const T& anEntry) const override;

    // Traversal methods
    void preorderTraverse(typename BinaryTreeInterface<T>::FunctionType visit) const override;
    void inorderTraverse(typename BinaryTreeInterface<T>::FunctionType visit) const override;
    void postorderTraverse(typename BinaryTreeInterface<T>::FunctionType visit) const override;

    // Additional methods
    bool replace(const T& item, const T& replacementItem);
    void displayVisualTree(BinaryNode<T>* subTreePtr, int totalSpaces) const;
    void displayTree() const;
};

#endif // LINKED_BTREE_H