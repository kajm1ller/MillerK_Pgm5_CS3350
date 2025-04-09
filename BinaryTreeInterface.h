#pragma once
#ifndef BINARYTREEINTERFACE_H
#define BINARYTREEINTERFACE_H
template <typename T>
class BinaryTreeInterface
{
public:
	// function supplied by the client will be used to "visit" each node
	typedef void(*FunctionType)(T& data);

	virtual bool isEmpty() const = 0; // true if empty, false otherwise
	virtual int getHeight() const = 0; // return height of the tree
	virtual int getNumberOfNodes() const = 0; // get this count from BinaryNode class
	virtual T getRootData() const = 0; // return data of root node, assert not empty
	virtual void setRootData(const T&) = 0; // replace root data, if empty create root node
	virtual bool add(const T&) = 0; // add given node to the tree
	virtual void clear() = 0; // remove all nodes from the tree

	// Check whether a given entry is contained in the binary tree
	virtual bool contains(const T&) const = 0;

	// Traverse tree in one of the three traversal methods (preorder, inorder, postorder)
	// Calls the function visit once for each node
	// visit is a client-defined function that operates on or with the data
	// in each visited node
	virtual void preorderTraverse(FunctionType) const = 0;
	virtual void inorderTraverse(FunctionType) const = 0;
	virtual void postorderTraverse(FunctionType) const = 0;

	// Virtual destructor
	virtual ~BinaryTreeInterface() {}
};

#endif // BINARYTREEINTERFACE_H