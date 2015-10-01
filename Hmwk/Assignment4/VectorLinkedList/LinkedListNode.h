// Linked List class
#ifndef LINKEDLISTNODE_H
#define LINKEDLISTNODE_H

#include <iostream>
using namespace std;

// Definition of the node class
class Node
{
public:
	int data;
	Node *next;
	Node()
	{
		data=0;
		next=NULL;
	}
};

#endif