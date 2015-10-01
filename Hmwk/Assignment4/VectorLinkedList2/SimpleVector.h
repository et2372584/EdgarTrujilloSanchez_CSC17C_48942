/* 
* Edgar N Trujillo Sanchez
* File: SimpleVector.h
*/

// SimpleVector class
#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H

// System Libraries
#include <iostream>
using namespace std;

// SimpleVector class using a linked list
class SimpleVector
{
public:
	// Default Constructor for SimpleVector class.
	SimpleVector()
	{
		root = NULL;
		listSize=0;
	}

	// Constructor declaration
	SimpleVector(int);

	// Destructor declaration
	~SimpleVector();

	//// Function that adds a new item to the end of the linked list
	void push(int );

	//// Function that deletes an item from the end of the linked list
	void pop();

	//// Function that returns the current size of the linked list
	int length();

	//// Function that prints contents of the linked list
	void print();

private:
	// Definition of the node class
	struct Node
	{
		int data;
		Node *next;
	};
	Node *root;	// Pointer to start of linked list
	int listSize;    // Number of elements in the linked list
};

#endif