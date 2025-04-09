#pragma once
#ifndef BINARYNODE_H  
#define BINARYNODE_H 
template <typename T>

class BinaryNode
{
public:
	BinaryNode(); // default constructor
	BinaryNode(const T&); // overloaded constructor
	BinaryNode(const T& x, BinaryNode<T>* y); // overloaded constructor accepting item data, and a pointer to another BinaryNode
	~BinaryNode<T>(); // destructor
	T getItem()const; // accessor returning data
	void setItem(const T&); // mutator setting data
	bool isLeaf() const; // true if leaf node, false otherwise
	BinaryNode<T>* getLeft()const; // accessor returning pLeft pointer
	BinaryNode<T>* getRight()const; // accessor returning pRight pointer
	void setLeft(BinaryNode<T>*); // mutator setting pLeft
	void setRight(BinaryNode<T>*); // mutator setting pRight
	static int getNodeCount(); // accessor for the static node count
	static int nodeCount; // static members are available to all objects
private:
	T data; // node data
	BinaryNode<T>* pLeft; // pointer to left subtree
	BinaryNode<T>* pRight; // pointer to right subtree
};

#endif // BINARYNODE_H
