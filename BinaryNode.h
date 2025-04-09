#pragma once
#ifndef BINARY_NODE_H
#define BINARY_NODE_H

template <typename T>
class BinaryNode
{
public:
    BinaryNode(); // default constructor
    BinaryNode(const T&); // overloaded constructor
    BinaryNode(const T&, // overloaded constructor accepting item data, and
        BinaryNode<T>*, // pointer to left subtree
        BinaryNode<T>*); // pointer to right subtree
    ~BinaryNode() { nodeCount--; } // destructor
    T getItem() const; // accessor returning data
    void setItem(const T&); // mutator setting data
    bool isLeaf() const; // true if leaf node, false otherwise
    BinaryNode<T>* getLeft() const; // accessor returning pLeft pointer
    BinaryNode<T>* getRight() const; // accessor returning pRight pointer
    void setLeft(BinaryNode<T>*); // mutator setting pLeft
    void setRight(BinaryNode<T>*); // mutator setting pRight
    static int getNodeCount(); // accessor for the static node count
    static int nodeCount; // static members are available to all objects
private:
    T data; // node data
    BinaryNode<T>* pLeft; // pointer left subtree
    BinaryNode<T>* pRight; // pointer to right subtree
};

// Initialize static member
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

// Check if node is a leaf (no children)
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

#endif // BINARY_NODE_H