/* 
* Edgar N Trujillo Sanchez
* File: SimpleVector.cpp
*/

// My Library
#include "SimpleVector.h"

// Constructor for SimpleVector class
SimpleVector::SimpleVector(int n)
{
	Node *temp=new Node; // Create a new Node
	temp->data=n; // Initialize data field to n
	temp->next=NULL; // Set next field to NULL
	root=temp; // Link new Node to root
	//Initialize listSize and increase it to one
	listSize=0;
	listSize++;
}

// Destructor for SimpleVector class
SimpleVector :: ~SimpleVector()
{
	Node *traverse;
	while (root !=NULL)
	{
		traverse=root;
		root=traverse->next;
		delete traverse;
		listSize--;
	}
	traverse = NULL;
}

// Push function. It adds a new item to the end of the linked list
void SimpleVector :: push(int input)
{
	// Declaring temporary pointer
	Node *tempPush;
	// Creating new node
	tempPush=new Node;
	tempPush->data=input;
	tempPush->next=NULL;
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
	// Declaring temporary pointer
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
	else // If linked list is empty, notify user that item can't be pop
	{
		cout << "Vector is empty, can not delete an item from Vector." << endl;
	}
	traversePush1 = NULL;
}

// Lenght function. It returns the current size of the linked list
int SimpleVector :: length()
{
	return listSize;
}

// Print function. It prints the contents of the linked list
void SimpleVector :: print()
{
	Node *traversePrint = root;
	if (traversePrint != NULL)
	{
		do
		{
			cout << traversePrint->data << " "; 
			traversePrint = traversePrint->next;
		}while (traversePrint != NULL);
		cout << endl;
	}
	else
		cout << "Vector is empty!!!" << endl;
}



