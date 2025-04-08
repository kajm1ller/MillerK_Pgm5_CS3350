#pragma once
#ifdef BINARY_NODE_H
template <typedef T>
class BinaryNode
{
public:
	BinaryNode() 
	{
		data();
		pLeft = nullptr;
		pRight = nullptr;
		nodeCount++;
	}; // default constructor

	BinaryNode(const T& x) 
	{
		data = x;
		pLeft = nullptr;
		pRight = nullptr;
	}; // overloaded constructor

	BinaryNode(const T& x, BinaryNode<T>* y)  // overloaded constructor accepting item data, andBinaryNode<T>*, // pointer to left subtree
	{
		data = x;
		pLeft = y->pLeft;
		pRight = y->pRight;
	}; // pointer to right subtree
	
	~BinaryNode<T>() { nodeCount--; } // destructor
	
	T getItem()const { return data; }; // accessor returning data
	
	void setItem(const T& x) { data = this->data; }; // mutator setting data
	
	bool isLeaf() const // true if leaf node, false otherwise
	{
		if ((pLeft == nullptr) && (pRight == nullptr) {
			return true;
		}
		return false;
	
	}; 

	BinaryNode<T>* getLeft()const { return pLeft;  }; // accessor returning pLeft pointer

	BinaryNode<T>* getRight()const{ return pRight; }; // accessor returning pRight pointer

	void setLeft(BinaryNode<T>* x){ pLeft = x->pLeft}; // mutator setting pLeft

	void setRight(BinaryNode<T>* x){ pRight = x->pRight}; // mutator setting pRight

	static int getNodeCount() { return nodeCount; }; // accessor for the static node count

	static int nodeCount; // static members are available to all objects
private:
	T data; // node data
	BinaryNode<T>* pLeft; // pointer left subtree
	BinaryNode<T>* pRight; // pointer to right subtree
};

#endif BINARY_NODE_H
