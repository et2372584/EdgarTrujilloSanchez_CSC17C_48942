/*
* Edgar M Trujillo Sanchez
* File: main.cpp
* Sept 25th, 2015
* Purpose:  Create a simple vector class utilizing a single link-list class.
*/

// System Libraries
#include <iostream>
using namespace std;

// My Library
#include "SimpleVector.h"

// Execution begins here
int main()
{
	/*	Testing Vector when declaring an object
		without passing a value
	// Declare a SimpleVector object
	SimpleVector oneVector;
	// Add new value to oneVector
	cout << "Adding a value to Vector..." << endl;
	int itemOne = 12344;
	oneVector.push(itemOne);
	*/

	// Create oneVector w/a Node with data = 3
    SimpleVector oneVector(3);
	// Print current size of oneVector and its contents
	cout << "The current size of the Vector is: " << oneVector.length() << endl;
	cout << "The current contents of the Vector are: "; 
	oneVector.print();
	cout <<endl;

	// Add values 5,10,15,20,25 to oneVector
	int value = 5;
	cout << "Adding values 5,10,15,20,25 to Vector..." << endl << endl;
	for(int i=0; i<5; i++)
	{
		oneVector.push(value);
		value = value+5;
	}
	// Print current size of oneVector and its contents
	cout << "The current size of the Vector is: " << oneVector.length() << endl;
	cout << "The current contents of the Vector are: "; 
	oneVector.print();
	cout <<endl;

	// Delete a value from oneVector
	cout << "Deleting a value from Vector..." << endl;
	oneVector.pop();
	// Print current size of oneVector and its contents
	cout << "The current size of the Vector is: " << oneVector.length() << endl;
	cout << "The current contents of the Vector are: "; 
	oneVector.print();
	cout <<endl;

	// Delete 5 value from oneVector
	cout << "Deleting 5 values from Vector..." << endl;
	for (int i=0; i<5; i++)
		oneVector.pop();
	// Print current size of oneVector and its contents
	cout << "The current size of the Vector is: " << oneVector.length() << endl;
	cout << "The current contents of the Vector are: "; 
	oneVector.print();
	cout <<endl;

	// Deleting a value from oneVector
	cout << "Deleting a value from Vector..." << endl;
	oneVector.pop();
	// Print current size of oneVector and its contents
	cout << "The current size of the Vector is: " << oneVector.length() << endl;
	cout << "The current contents of the Vector are: "; 
	oneVector.print();
	cout <<endl;

	// Add new value to oneVector
	cout << "Adding a value to Vector..." << endl;
	int itemThree = 12344;
	oneVector.push(itemThree);
	// Print current size of oneVector and its contents
	cout << "The current size of the Vector is: " << oneVector.length() << endl;
	cout << "The current contents of the Vector are: "; 
	oneVector.print();
	cout <<endl;

	// Delete a value from oneVector
	cout << "Deleting a value from Vector..." << endl;
	oneVector.pop();
	// Print current size of oneVector and its contents
	cout << "The current size of the Vector is: " << oneVector.length() << endl;
	cout << "The current contents of the Vector are: "; 
	oneVector.print();
	cout <<endl;

	// Try to delete a node from empty oneVector
	cout << "Deleting a value from Vector..." << endl;
	oneVector.pop();

	//Exit stage right
	return 0;
}