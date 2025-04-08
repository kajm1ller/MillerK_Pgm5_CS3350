#pragma once
#ifdef BINARY_NODE_H
template <typedef T>
class BinaryNode
{
public:
	BinaryNode() // default constructor
	{
		data();
		pLeft = nullptr;
		pRight = nullptr;
		nodeCount++;
	}; 

	BinaryNode(const T& x) // overloaded constructor
	{
		data = x;
		pLeft = nullptr;
		pRight = nullptr;
	}; 

	BinaryNode(const T& x, BinaryNode<T>* y)  // overloaded constructor accepting item data, andBinaryNode<T>*
	{
		data = x;
		pLeft = y->pLeft;    // pointer to left subtree
		pRight = y->pRight;  // pointer to right subtree
	};
	
	~BinaryNode<T>() { nodeCount--; } // destructor
	
	T getItem()const // accessor returning data
	{ 
		return data; 
	}; 
	
	void setItem(const T& x) // mutator setting data
	{ 
		data = this->data; 
	}; 
	
	bool isLeaf() const // true if leaf node, false otherwise
	{
		if ((pLeft == nullptr) && (pRight == nullptr) {
			return true;
		}

		return false;
	}; 

	BinaryNode<T>* getLeft()const // accessor returning pLeft pointer
	{ 
		return pLeft;  
	}; 

	BinaryNode<T>* getRight()const // accessor returning pRight pointer
	{ 
		return pRight; 
	}; 

	void setLeft(BinaryNode<T>* x) // mutator setting pLeft
	{ 
		pLeft = x->pLeft
	}; 

	void setRight(BinaryNode<T>* x) // mutator setting pRight
	{ 
		pRight = x->pRight
	}; 

	static int getNodeCount() // accessor for the static node count
	{ 
		return nodeCount; 
	}; 

	static int nodeCount; // static members are available to all objects
private:
	T data; // node data
	BinaryNode<T>* pLeft; // pointer left subtree
	BinaryNode<T>* pRight; // pointer to right subtree
};

#endif BINARY_NODE_H
