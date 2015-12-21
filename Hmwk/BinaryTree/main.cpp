/*
* Edgar M Trujillo Sanchez
* Dec 15th, 2015
* Purpose: BinaryTree - This program will implement a BinaryTree.
*/

#include <iostream>
#include "BinaryTree.h"

using namespace std;

int main()
{
	BinaryTree oneTree;

	// Inserting info into tree
	cout << "Inserting Nodes..."<<endl;
	for(int i=0; i<=15; i=i+3)
	{
		oneTree.insert(i);
	}

	// Print inorder
	cout << "InOrder Traversal: " <<endl;
	oneTree.printInOrder();

	// Print in preorder
	cout << "PreOrder Traversal: " <<endl;
	oneTree.printPreOrder();

	// Print in postorder
	cout << "PostOrder Traversal: " <<endl;
	oneTree.printPostOrder();

	// Search for 3
	int searchVal=3;
	cout << "Searching for value 3..."<<endl;
	if(oneTree.search(searchVal))
		cout<<searchVal<<" is found in tree."<<endl;
	else
		cout<<searchVal<<" is not found in tree."<<endl;

	// Search for 100
	int searchVal2=100;
	cout << "Searching for value 100..."<<endl;
	if(oneTree.search(searchVal2))
		cout<<searchVal2<<" is found in tree."<<endl;
	else
		cout<<searchVal2<<" is not found in tree."<<endl;

	return 0;
}