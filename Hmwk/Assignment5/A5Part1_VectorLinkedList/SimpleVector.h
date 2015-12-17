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

	// Copy Constructor
	SimpleVector(const SimpleVector &);

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

	//// Function that returns the first value in the linked list
	void first(int &);

	//// Function that returns the last value in the linked list
	void last(int &);

	//// Function that appends a new item to the linked list
	void append(int );

	//// Function that prepends a new item to the linked list
	void prepend(int );

	//// Function that looks for given value in linked list
		// and deletes all instance of it
	void extract(int );

	//// Function that looks for given value in linked list
		// and inserts the input value before the given value
	void insertBefore(int, int);

	//// Function that looks for given value in linked list
		// and inserts the input value after the given value
	void insertAfter(int, int);

	//// Function that copies the contents of a given linked
		// list into another linked list
	void copyList(const SimpleVector &);

	// Overloaded = (Assignment) Operator
	SimpleVector &operator= (const SimpleVector &);
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