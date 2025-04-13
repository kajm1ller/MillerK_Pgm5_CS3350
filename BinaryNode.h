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

#endif // BINARY_NODE_H