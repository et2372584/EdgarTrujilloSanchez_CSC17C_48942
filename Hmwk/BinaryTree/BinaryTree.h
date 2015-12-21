// BinaryTree class
#ifndef BINARYTREE_H
#define BINARYTREE_H

//System Libraries
#include <iostream>
using namespace std;

class BinaryTree
{
private:
	struct TreeNode
	{
		int value; // The value in node
		TreeNode *left; // Pointer left child node
		TreeNode *right; // Pointer right child node
	};
	TreeNode *root; // Pointer to root node
	void insert(int , TreeNode *);
	void destroyTree(TreeNode *);
	void printInOrder(TreeNode *) const;
	void printPreOrder(TreeNode *) const;
	void printPostOrder(TreeNode *) const;

public:
	// Constructor
	BinaryTree();
	// Destructor
	~BinaryTree();
	// Public insert function
	void insert(int );
	// Search function
	bool search(int );
	// Public destroyTree function
	void destroyTree();
	// Public printInOrder function
	void printInOrder() const;
	// Public printPreOrder function
	void printPreOrder() const;
	// Public printPostOrder function
	void printPostOrder() const;
};

#endif