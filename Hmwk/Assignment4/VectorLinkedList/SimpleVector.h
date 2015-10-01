// SimpleVector class
#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H

#include <iostream>
#include "LinkedListNode.h"
using namespace std;

// Simple vector class using a linked list class
class SimpleVector
{
private:
	Node *root;	// Pointer to start of linked list
	int listSize;    // Number of elements in the linked list

public:
	// Constructor declaration
	SimpleVector();

	// Destructor declaration
	~SimpleVector();

	//// Function that adds a new item to the end of the linked list
	void push(int );

	//// Function that deletes an item from the end of the linked list
	void pop();

	//// Function that prints contents of the linked list
	void print();

	//// Function that returns the current size of the linked list
	int length();
};

// Default Constructor for SimpleVector class.
SimpleVector :: SimpleVector()
	{
		root = NULL;
		listSize=0;
	}

// Destructor for SimpleVector class.
SimpleVector :: ~SimpleVector()
{
	Node *traverse;
	while (root !=NULL)
	{
		traverse=root;
		root=traverse->next;
		delete traverse;
	}
	traverse = NULL;
}

// Push function. It adds a new item to the end of the linked list
void SimpleVector :: push(int input)
{
	// Declaring temporary pointer
	Node *tempPush;
	// Creating new node
	tempPush = new Node;
	tempPush->data = input;
	// Linking new node to list
	if (root != NULL)	// If linked list is not empty, it adds the new node to the end of the list
	{
		Node *traversePush=root;
		while(traversePush->next != NULL)
			traversePush = traversePush->next;
		traversePush->next = tempPush;
		listSize++;
		traversePush = NULL;
	}
	else	// If linked list is empty, root is pointed to the new node
	{
		root=tempPush;
		listSize++;
	}
	tempPush = NULL; // Sets temporary pointer to NULL before exiting function
}

// Pop function. It deletes an item from the end of the linked list
void SimpleVector :: pop()
{
	// Declaring temporary pointers
	Node *traversePush1 = root;
	//Deleting node
	if (traversePush1 != NULL)	// If linked list is not empty, delete item from the end of the linked list
	{
		if (traversePush1->next != NULL)
		{
			Node *traversePush2 = traversePush1->next;
			while(traversePush2->next != NULL)
			{
				traversePush1 = traversePush1->next;
				traversePush2 = traversePush2->next;
			}
			traversePush1->next = traversePush2->next;
			delete traversePush2;
			listSize--;
			traversePush2 = NULL;
		}
		else
		{
			root = traversePush1->next;
			delete traversePush1;
			listSize--;
		}
	}
	else
	{
		cout << "Vector is empty, can not delete an item from Vector." << endl;
		exit(EXIT_FAILURE);
	}
	traversePush1 = NULL;
}

// Print function. It prints the contents of the linked list
void SimpleVector :: print()
{
	Node *traversePrint = root;
	if (traversePrint != NULL)
	{
		while (traversePrint != NULL)
		{
			cout << traversePrint->data << " "; 
			traversePrint = traversePrint->next;
		}
		cout << endl;
	}
	else
		cout << "Vector is empty!!!" << endl;
}

// Lenght function. It returns the current size of the linked list
int SimpleVector :: length()
{
	return listSize;
}

#endif