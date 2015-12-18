//BinaryTree.cpp, implementation file of class

//System Libraries
#include "BinaryTree.h"

// Constructor
BinaryTree::BinaryTree()
{
	root=NULL;
	treeSize=0;
}

// Destructor
BinaryTree::~BinaryTree()
{
	destroyTree();
}

// Public destroyTree function. It calls the recursive destroyTree function
	//which will actually delete all the nodes of the tree
void BinaryTree::destroyTree()
{
	destroyTree(root);
}

// Private destroyTree function.  It will delete all the nodes of the tree
void BinaryTree::destroyTree(TreeNode *leaf)
{
	if(leaf!=NULL)
	{
		destroyTree(leaf->left);
		destroyTree(leaf->right);
		delete leaf;
	}
}

// Public insert function.  It handles the case when the root of the tree is
	//empty.  If not empty calls recursive insert function
void BinaryTree::insert(char val)
{
	if(root!=NULL)
		insert(val, root);
	else
	{
		root=new TreeNode;
		root->value=val;
		root->left=NULL;
		root->right=NULL;
		treeSize++;
	}
}

// Private insert function.  It moves down the tree by calling itself while 
	//searching for correct location. Once a new TreeNode is created the 
	//function will not call itself again.
void BinaryTree::insert(char val, TreeNode *leaf)
{
	// If new value is less than current value
	if(val<leaf->value)
	{
		if(leaf->left!=NULL)
			insert(val, leaf->left);
		else
		{
			leaf->left=new TreeNode;
			leaf->left->value=val;
			//Sets left child of child node to null
			leaf->left->left=NULL;
			//Sets right child of child node to null
			leaf->left->right=NULL;
			treeSize++;
		}
	}
	// If new value is greater or equal to current value
	else if(val>=leaf->value)
	{
		if(leaf->right!=NULL)
			insert(val, leaf->right);
		else
		{
			leaf->right=new TreeNode;
			leaf->right->value=val;
			//Sets left child of child node to NULL
			leaf->right->left=NULL;
			//Sets right child of child node to NULL
			leaf->right->right=NULL;
			treeSize++;
		}
	}
}

// Search function.  It moves down the tree
	//searching for given value
bool BinaryTree::search(char val)
{
	TreeNode *p = root;
	while(p)
	{
		if(p->value==val)
			return true;
		else if(val<p->value)
			p=p->left;
		else
			p=p->right;
	}
	return false;
}

// Public printInOrder function
void BinaryTree::printInOrder() const
{
	printInOrder(root);
}

// Public printPreOrder function
void BinaryTree::printPreOrder() const
{
	printPreOrder(root);
}

// Public printPostOrder function
void BinaryTree::printPostOrder() const
{
	printPostOrder(root); 
}

// Private printInOrder function.  It prints the value of the tree in InOrder.
void BinaryTree::printInOrder(TreeNode *p) const
{
	if(p)
	{
		printInOrder(p->left);
		cout << p->value << endl;
		printInOrder(p->right);
	}
}

// Private printPreOrder function.  It prints the value of the tree in PreOrder.
void BinaryTree::printPreOrder(TreeNode *p) const
{
	if(p)
	{
		cout << p->value << endl;
		printPreOrder(p->left);
		printPreOrder(p->right);
	}
}

// Private printPostOrder function.  It prints the value of the tree in PostOrder.
void BinaryTree::printPostOrder(TreeNode *p) const
{
	if(p)
	{
		printPostOrder(p->left);
		printPostOrder(p->right);
		cout << p->value << endl;
	}
}