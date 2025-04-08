#pragma once
#ifdef LINKED_B_TREE_H
template <typename T>
class LinkedBTree : public BinaryTreeInterface<T>
{
private:
	BinaryNode<T>* pRoot;
protected:
	int getHeightHelper(BinaryNode<T>*) const;
	BinaryNode<T>* balancedAdd(BinaryNode<T>*, BinaryNode<T>*);
	void destroyTree(BinaryNode<T>*);
	void inorder(FunctionType, BinaryNode<T>*) const;
	BinaryNode<T>* findNode(BinaryNode<T>*, const T&, bool&)const;
	// more protected helper functions omitted
public:
	void inorderTraverse(FunctionType) const;
	// more public interface functions omitted
};


#endif