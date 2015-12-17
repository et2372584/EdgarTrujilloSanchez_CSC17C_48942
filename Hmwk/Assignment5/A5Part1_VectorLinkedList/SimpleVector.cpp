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

// Copy Constructor
SimpleVector::SimpleVector(const SimpleVector &firstList)
{
	root=NULL; // Initialize root of this list to NULL
	copyList(firstList);
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
	Node *traversePop1 = root;
	//Deleting node
	if (traversePop1 != NULL)	// If linked list is not empty, delete item from the end of the linked list
	{
		if (traversePop1->next != NULL)
		{
			Node *traversePop2 = traversePop1->next;
			while(traversePop2->next != NULL)
			{
				traversePop1 = traversePop1->next;
				traversePop2 = traversePop2->next;
			}
			traversePop1->next = traversePop2->next;
			delete traversePop2;
			listSize--;
			traversePop2 = NULL;
		}
		else
		{
			root = traversePop1->next;
			delete traversePop1;
			listSize--;
		}
	}
	else // If linked list is empty, notify user that item can't be pop
	{
		cout << "Vector is empty, can not delete an item from Vector." << endl;
	}
	traversePop1 = NULL;
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
	traversePrint = NULL; // Sets temporary pointer to NULL before exiting function
}

// First function. It finds the first value of the linked list
void SimpleVector::first(int &n)
{
	Node *traverseFirst=root;
	if (traverseFirst == NULL)
		cout << "Vector is empy!!!" << endl;
	else
	{
		cout << "The first value of the Vector is: " << traverseFirst->data << endl;
		n=traverseFirst->data;
	}
	traverseFirst = NULL; // Sets temporary pointer to NULL before exiting function
}

// Last function. It finds the last value of the linked list
void SimpleVector::last(int &n)
{
	Node *traverseLast=root;
	if (traverseLast == NULL)
		cout << "Vector is empy!!!" << endl;
	else if(traverseLast->next != NULL)
	{
		while (traverseLast->next != NULL)
			traverseLast=traverseLast->next;
		cout << "The last value of the Vector is: " << traverseLast->data << endl;
		n=traverseLast->data;
	}
	else
	{
		cout << "The last value of the Vector is: " << traverseLast->data << endl;
		n=traverseLast->data;
	}
	traverseLast = NULL; // Sets temporary pointer to NULL before exiting function
}

// Append function. It appends a new item to the linked list
void SimpleVector :: append(int input)
{
	push(input);
}

// Prepend function. It prepends a new item to the linked list
void SimpleVector :: prepend(int input)
{
	// Declaring temporary pointer
	Node *prependPush;
	// Creating new node and linking it to the front of list
	prependPush=new Node;
	prependPush->data=input;
	prependPush->next=root;
	root=prependPush;
	listSize++;
	prependPush = NULL; // Sets temporary pointer to NULL before exiting function
}

// Extract function. It looks for a given value in the linked 
// list and deletes all instance of it
void SimpleVector :: extract(int value)
{
	// Temporary traverse pointers
	Node *traverse1=root;
	Node *traverse2=root;
	Node *traverse3=traverse2->next;
	// Temporary counter
	int tempCount=listSize;

	while(traverse2!=NULL)
	{
		if(traverse2->data!=value)
		{
			traverse1=traverse2;
			traverse2=traverse2->next;
			//traverse3=traverse3->next;
			if(traverse3==NULL)
				traverse3=traverse3;
			else
				traverse3=traverse3->next;
		}
		else if(traverse2==root)
		{
			root=traverse3;
			delete traverse2;
			listSize--;
			traverse1=root;
			traverse2=traverse3;
			if(traverse3==NULL)
				traverse3=traverse3;
			else
				traverse3=traverse3->next;
		}
		else
		{
			traverse1->next=traverse2->next;
			delete traverse2;
			listSize--;
			traverse2=traverse3;
			if(traverse3!=NULL)
				traverse3=traverse3->next;
			else
				traverse3=traverse3;
		}
	}
	traverse1=NULL;

	if(listSize==tempCount)
		cout << "Value not found! No values deleted." << endl;
}

// InsertBefore function. It looks for a given value in the linked 
// list and inserts the input value before the given value
void SimpleVector :: insertBefore(int gvalue, int input)
{
	// Temporary traverse pointers
	Node *traverse1=root;
	Node *traverse2=traverse1;
	// Temporary counter
	int tempCount=listSize;
	// Traverse linked list until traverse2 points to NULL
	while(traverse2!=NULL)
	{
		// Traverse linked list until given value is found
		if(traverse2->data!=gvalue)
		{
			traverse1=traverse2;
			if(traverse2!=NULL)
				traverse2=traverse2->next;
			else
				traverse2=traverse2;
		}
		else if(traverse1==root)
		{
			root=new Node;
			root->data=input;
			root->next=traverse1;
			listSize++;
			traverse2=NULL;
		}
		else
		{
			Node *temp=new Node;
			temp->data=input;
			temp->next=traverse2;
			traverse1->next=temp;
			listSize++;
			traverse2=NULL;
		}
	}
	// Set temporary pointers to NULL before end of function
	traverse1=NULL;
	traverse2=NULL;
	// Check if the given value was found using the listSize
	if(tempCount==listSize)
		cout << "Given value not found. No changes made." << endl;
}

// InsertAfter function. It looks for a given value in the linked 
// list and inserts the input value after the given value
void SimpleVector :: insertAfter(int gvalue, int input)
{
	// Temporary traverse pointers
	Node *traverse1=root;
	Node *traverse2=traverse1->next;
	// Temporary counter
	int tempCount=listSize;
	// Traverse linked list until traverse1 points to NULL
	while(traverse1!=NULL)
	{
		// Traverse linked list until given value is found
		if(traverse1->data!=gvalue)
		{
			traverse1=traverse2;
			if(traverse2!=NULL)
				traverse2=traverse2->next;
			else
				traverse2=traverse2;
		}
		else
		{
			// Create new node
			Node *temp=new Node;
			temp->data=input;
			temp->next=traverse2;
			traverse1->next=temp; // Connect new node to linked list
			listSize++; // Increase listSize
			traverse1=NULL;
		}
	}
	// Set temporary pointers to NULL before end of function
	traverse1=NULL;
	traverse2=NULL;
	// Check if the given value was found using the listSize
	if(tempCount==listSize)
		cout << "Given value not found. No changes made." << endl;
}

// CopyList function.  It copies the contents of a given linked
// list into another linked list
void SimpleVector :: copyList(const SimpleVector &gList)
{
	Node *traverse1;
	Node *traverse2;
	if (root!=NULL) // If this list is non-empty, make it empty
		while(root!=NULL)
		{
			traverse1=root;
			root=root->next;
			delete traverse1;
		}

	// If gList is empty, initialize this list to an empty state
	if (gList.root==NULL)
	{
		root=NULL;
		listSize=0;
	}
	else // If gList is not empty, copy its contents to this list
	{
		// Start copying gList into this list
		traverse1=gList.root;
		//// Copy first node of gList
		root = new Node;
		root->data=traverse1->data;
		root->next=NULL;
		traverse1=traverse1->next; // Move traverse1 to next node of gList
		traverse2=root; // Point traverse2 to root of this list
		//// Copy rest of gList
		Node *temp=NULL;
		while (traverse1!=NULL)
		{
			// Create a new node
			temp = new Node;
			temp->data=traverse1->data;
			temp->next=NULL;
			traverse2->next=temp; // Connects new node to the end of this list
			traverse2=temp; // Move traverse2 to the end of this list
			traverse1=traverse1->next; // Move traverse1 to next node of gList
		}
		temp=NULL; // Sets temporary pointer to NULL before exiting function
		traverse2=NULL; // Sets temporary pointer to NULL before exiting function
		listSize=gList.listSize; // Copy size of gList into listSize of this list
	}
}

// Overloaded = (Assignment) Operator
SimpleVector &SimpleVector :: operator= (const SimpleVector &gList)
{
	if (root!=gList.root) // Avoid self-copy
		copyList(gList);
	else // Notify attempt of self-copy
		cout << "Attempting to self-copy. No changes made." << endl;
	return *this; // Returning current object
}
