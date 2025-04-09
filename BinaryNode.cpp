#include "BinaryNode.h"
#include <string>



template <typename T>
BinaryNode<T>::BinaryNode() 
{ 
	nodeCount = 0;
	pLeft = nullptr;
	pRight = nullptr;
	nodeCount++;
}

template <typename T>
BinaryNode<T>::BinaryNode(const T& x) 
{ 
	data = x;
	pLeft = nullptr;
	pRight = nullptr;
	nodeCount++;
}

template <typename T>
BinaryNode<T>::BinaryNode(const T& x, BinaryNode<T>* y) 
{ 
	data = x;
	pLeft = y->pLeft;
	pRight = y->pRight;
}

template <typename T>
BinaryNode<T>::~BinaryNode() 
{
	nodeCount--;
}

template <typename T>
T BinaryNode<T>::getItem() const 
{
	return data;
}

template <typename T>
void BinaryNode<T>::setItem(const T&) 
{
	data = this->data;
}

template <typename T>
bool BinaryNode<T>::isLeaf() const 
{
	if ((pLeft == nullptr) && (pRight == nullptr)) {
		return true;
	}

	return false;
}

template <typename T>
BinaryNode<T>* BinaryNode<T>::getLeft() const 
{
	return pLeft;
}

template <typename T>
BinaryNode<T>* BinaryNode<T>::getRight() const
{
	return pRight;
}

template <typename T>
void BinaryNode<T>::setLeft(BinaryNode<T>* x) 
{
	this->pLeft = x->pLeft;
}

template <typename T>
void BinaryNode<T>::setRight(BinaryNode<T>* x) 
{
	this->pRight = x->pRight;
}

template<typename T>
int BinaryNode<T>::getNodeCount()
{
	return nodeCount;
}

template class BinaryNode<std::string>;


template <typename T>
int BinaryNode<T>::nodeCount = 0;