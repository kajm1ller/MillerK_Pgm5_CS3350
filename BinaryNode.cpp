#include "BinaryNode.h"
#include <string>

template <typename T>
int BinaryNode<T>::nodeCount = 0;

// Default constructor
template <typename T>
BinaryNode<T>::BinaryNode() : pLeft(nullptr), pRight(nullptr)
{
    nodeCount++;
}

// Overloaded constructor with data
template <typename T>
BinaryNode<T>::BinaryNode(const T& anItem) : data(anItem), pLeft(nullptr), pRight(nullptr)
{
    nodeCount++;
}

// Overloaded constructor with data and subtree pointers
template <typename T>
BinaryNode<T>::BinaryNode(const T& anItem,
    BinaryNode<T>* leftPtr,
    BinaryNode<T>* rightPtr) :
    data(anItem),
    pLeft(leftPtr),
    pRight(rightPtr)
{
    nodeCount++;
}

// Get data from node
template <typename T>
T BinaryNode<T>::getItem() const
{
    return data;
}

// Set data in node
template <typename T>
void BinaryNode<T>::setItem(const T& anItem)
{
    data = anItem;
}

// Check if node is a leaf 
template <typename T>
bool BinaryNode<T>::isLeaf() const
{
    return (pLeft == nullptr && pRight == nullptr);
}

// Get left child pointer
template <typename T>
BinaryNode<T>* BinaryNode<T>::getLeft() const
{
    return pLeft;
}

// Get right child pointer
template <typename T>
BinaryNode<T>* BinaryNode<T>::getRight() const
{
    return pRight;
}

// Set left child pointer
template <typename T>
void BinaryNode<T>::setLeft(BinaryNode<T>* leftPtr)
{
    pLeft = leftPtr;
}

// Set right child pointer
template <typename T>
void BinaryNode<T>::setRight(BinaryNode<T>* rightPtr)
{
    pRight = rightPtr;
}

// Get the total count of nodes
template <typename T>
int BinaryNode<T>::getNodeCount()
{
    return nodeCount;
}

template class BinaryNode<std::string>;