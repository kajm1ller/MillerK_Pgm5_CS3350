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

// Constructors and Destructor Implementations

template <typename T>
LinkedBTree<T>::LinkedBTree() : pRoot(nullptr)
{
}

template <typename T>
LinkedBTree<T>::LinkedBTree(const T& rootItem)
{
    pRoot = new BinaryNode<T>(rootItem);
}

template <typename T>
LinkedBTree<T>::LinkedBTree(const T& rootItem,
    const LinkedBTree<T>* leftTreePtr,
    const LinkedBTree<T>* rightTreePtr)
{
    pRoot = new BinaryNode<T>(rootItem);

    if (leftTreePtr != nullptr)
        pRoot->setLeft(copyTree(leftTreePtr->pRoot));

    if (rightTreePtr != nullptr)
        pRoot->setRight(copyTree(rightTreePtr->pRoot));
}

template <typename T>
LinkedBTree<T>::LinkedBTree(const LinkedBTree<T>& tree)
{
    pRoot = copyTree(tree.pRoot);
}

template <typename T>
LinkedBTree<T>::~LinkedBTree()
{
    clear();
}

// Protected Utility Methods

template <typename T>
BinaryNode<T>* LinkedBTree<T>::copyTree(const BinaryNode<T>* treePtr) const
{
    BinaryNode<T>* newTreePtr = nullptr;

    if (treePtr != nullptr)
    {
        newTreePtr = new BinaryNode<T>(treePtr->getItem());
        newTreePtr->setLeft(copyTree(treePtr->getLeft()));
        newTreePtr->setRight(copyTree(treePtr->getRight()));
    }

    return newTreePtr;
}

template <typename T>
void LinkedBTree<T>::destroyTree(BinaryNode<T>* subTreePtr)
{
    if (subTreePtr != nullptr)
    {
        destroyTree(subTreePtr->getLeft());
        destroyTree(subTreePtr->getRight());
        delete subTreePtr;
    }
}

template <typename T>
int LinkedBTree<T>::getHeightHelper(BinaryNode<T>* subTreePtr) const
{
    if (subTreePtr == nullptr)
        return 0;
    else
        return 1 + std::max(getHeightHelper(subTreePtr->getLeft()),
            getHeightHelper(subTreePtr->getRight()));
}

template <typename T>
BinaryNode<T>* LinkedBTree<T>::balancedAdd(BinaryNode<T>* subTreePtr, BinaryNode<T>* newNodePtr)
{
    if (subTreePtr == nullptr)
        return newNodePtr;

    BinaryNode<T>* leftPtr = subTreePtr->getLeft();
    BinaryNode<T>* rightPtr = subTreePtr->getRight();

    if (getHeightHelper(leftPtr) > getHeightHelper(rightPtr))
    {
        rightPtr = balancedAdd(rightPtr, newNodePtr);
        subTreePtr->setRight(rightPtr);
    }
    else
    {
        leftPtr = balancedAdd(leftPtr, newNodePtr);
        subTreePtr->setLeft(leftPtr);
    }

    return subTreePtr;
}

template <typename T>
BinaryNode<T>* LinkedBTree<T>::findNode(BinaryNode<T>* treePtr, const T& target, bool& success) const
{
    if (treePtr == nullptr)
    {
        success = false;
        return nullptr;
    }

    if (treePtr->getItem() == target)
    {
        success = true;
        return treePtr;
    }

    BinaryNode<T>* targetNodePtr = findNode(treePtr->getLeft(), target, success);

    if (!success)
        targetNodePtr = findNode(treePtr->getRight(), target, success);

    return targetNodePtr;
}

// Traversal helpers
template <typename T>
void LinkedBTree<T>::preorder(typename BinaryTreeInterface<T>::FunctionType visit, BinaryNode<T>* treePtr) const
{
    if (treePtr != nullptr)
    {
        T item = treePtr->getItem();
        visit(item);
        preorder(visit, treePtr->getLeft());
        preorder(visit, treePtr->getRight());
    }
}

template <typename T>
void LinkedBTree<T>::inorder(typename BinaryTreeInterface<T>::FunctionType visit, BinaryNode<T>* treePtr) const
{
    if (treePtr != nullptr)
    {
        inorder(visit, treePtr->getLeft());
        T item = treePtr->getItem();
        visit(item);
        inorder(visit, treePtr->getRight());
    }
}

template <typename T>
void LinkedBTree<T>::postorder(typename BinaryTreeInterface<T>::FunctionType visit, BinaryNode<T>* treePtr) const
{
    if (treePtr != nullptr)
    {
        postorder(visit, treePtr->getLeft());
        postorder(visit, treePtr->getRight());
        T item = treePtr->getItem();
        visit(item);
    }
}

// Public Interface Methods

template <typename T>
bool LinkedBTree<T>::isEmpty() const
{
    return pRoot == nullptr;
}

template <typename T>
int LinkedBTree<T>::getHeight() const
{
    return getHeightHelper(pRoot);
}

template <typename T>
int LinkedBTree<T>::getNumberOfNodes() const
{
    return BinaryNode<T>::getNodeCount();
}

template <typename T>
T LinkedBTree<T>::getRootData() const
{
    assert(!isEmpty());
    return pRoot->getItem();
}

template <typename T>
void LinkedBTree<T>::setRootData(const T& newData)
{
    if (isEmpty())
        pRoot = new BinaryNode<T>(newData);
    else
        pRoot->setItem(newData);
}

template <typename T>
bool LinkedBTree<T>::add(const T& newData)
{
    BinaryNode<T>* newNodePtr = new BinaryNode<T>(newData);
    pRoot = balancedAdd(pRoot, newNodePtr);
    return true;
}

template <typename T>
void LinkedBTree<T>::clear()
{
    destroyTree(pRoot);
    pRoot = nullptr;
}

template <typename T>
bool LinkedBTree<T>::contains(const T& anEntry) const
{
    bool isFound = false;
    findNode(pRoot, anEntry, isFound);
    return isFound;
}

template <typename T>
void LinkedBTree<T>::preorderTraverse(typename BinaryTreeInterface<T>::FunctionType visit) const
{
    preorder(visit, pRoot);
}

template <typename T>
void LinkedBTree<T>::inorderTraverse(typename BinaryTreeInterface<T>::FunctionType visit) const
{
    inorder(visit, pRoot);
}

template <typename T>
void LinkedBTree<T>::postorderTraverse(typename BinaryTreeInterface<T>::FunctionType visit) const
{
    postorder(visit, pRoot);
}

// Additional Methods

template <typename T>
bool LinkedBTree<T>::replace(const T& item, const T& replacementItem)
{
    bool success = false;
    BinaryNode<T>* nodePtr = findNode(pRoot, item, success);

    if (success)
    {
        nodePtr->setItem(replacementItem);
        return true;
    }
    else
    {
        std::cout << "Error: Item '" << item << "' not found in the tree." << std::endl;
        return false;
    }
}

template <typename T>
void LinkedBTree<T>::displayVisualTree(BinaryNode<T>* subTreePtr, int totalSpaces) const
{
    const int SPACING_INCREMENT = 12;

    if (subTreePtr != nullptr)
    {
        // Process the right subtree
        displayVisualTree(subTreePtr->getRight(), totalSpaces + SPACING_INCREMENT);

        // Display this node
        std::cout << std::string(totalSpaces, ' ');
        std::cout << subTreePtr->getItem() << std::endl;

        // Process the left subtree
        displayVisualTree(subTreePtr->getLeft(), totalSpaces + SPACING_INCREMENT);
    }
    else
    {
        // Display null node indicator if not a leaf
        std::cout << std::string(totalSpaces, ' ');
        std::cout << "-----" << std::endl;
    }
}

template <typename T>
void LinkedBTree<T>::displayTree() const
{
    displayVisualTree(pRoot, 0);
}

#endif // LINKED_BTREE_H