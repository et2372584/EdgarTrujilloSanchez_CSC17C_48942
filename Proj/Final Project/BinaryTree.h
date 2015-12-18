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
		char value; // The value in node
		TreeNode *left; // Pointer left child node
		TreeNode *right; // Pointer right child node
	};
	TreeNode *root; // Pointer to root node
	int treeSize;
	void insert(char , TreeNode *);
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
	void insert(char );
	// Search function
	bool search(char );
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