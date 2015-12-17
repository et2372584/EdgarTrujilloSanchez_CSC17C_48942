/*
* Edgar M Trujillo Sanchez
* File: main.cpp
* Sept 30th, 2015
* Purpose:  Use a simple vector class, implemented with a single linked-list, class with additional functions.
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

	// Create oneVector w/a Node with data = 0
    SimpleVector oneVector(0);

	// Print current size of oneVector and its contents
	cout << "The current size of the Vector is: " << oneVector.length() << endl;
	cout << "The current contents of the Vector are: "; 
	oneVector.print();
	cout <<endl;

	// Find first value of oneVector and print it to screen
	int firstValue=0; //Initialize firstValue holder to zero
	cout << "Finding the first value of Vector..." << endl;
	oneVector.first(firstValue);
	cout << endl;

	// Find last value of oneVector and print it to screen
	int lastValue=0; //Initialize lastValue holder to zero
	cout << "Finding the last value of Vector..." << endl;
	oneVector.last(lastValue);
	cout << endl;

	// Add values 5,10,15,20,25 to oneVector
	int value1 = 5;
	cout << "Adding values 5,10,15,20,25 to Vector..." << endl << endl;
	for(int i=0; i<5; i++)
	{
		oneVector.push(value1);
		value1 = value1+5;
	}
	// Print current size of oneVector and its contents
	cout << "The current size of the Vector is: " << oneVector.length() << endl;
	cout << "The current contents of the Vector are: "; 
	oneVector.print();
	cout <<endl;

	// Find first value of oneVector and print it to screen
	cout << "Finding the first value of Vector..." << endl;
	oneVector.first(firstValue);
	cout << endl;

	// Find last value of oneVector and print it to screen
	cout << "Finding the last value of Vector..." << endl;
	oneVector.last(lastValue);
	cout << endl;

	// Delete a value from oneVector
	cout << "Deleting a value from Vector..." << endl;
	oneVector.pop();
	// Print current size of oneVector and its contents
	cout << "The current size of the Vector is: " << oneVector.length() << endl;
	cout << "The current contents of the Vector are: "; 
	oneVector.print();
	cout <<endl;

	// Find first value of oneVector and print it to screen
	cout << "Finding the first value of Vector..." << endl;
	oneVector.first(firstValue);
	cout << endl;

	// Find last value of oneVector and print it to screen
	cout << "Finding the last value of Vector..." << endl;
	oneVector.last(lastValue);
	cout << endl;

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

	// Append a new value to oneVector
	cout << "Appending a value to Vector..." << endl;
	int itemThree = 12344;
	oneVector.append(itemThree);
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

	// Try to find first value of empty oneVector
	cout << "Finding the first value of Vector..." << endl;
	oneVector.first(firstValue);
	cout << endl;

	// Try to find last value of empty oneVector
	cout << "Finding the last value of Vector..." << endl;
	oneVector.last(lastValue);
	cout << endl;

	// Try to delete a node from empty oneVector
	cout << "Deleting a value from Vector..." << endl;
	oneVector.pop();
	cout << endl;

	////////// Testing the prepend and append functions
	//// Prepend a new value to oneVector
	cout << "Prepending a value to Vector..." << endl;
	int itemFive = 890;
	oneVector.prepend(itemFive);
	// Print current size of oneVector and its contents
	cout << "The current size of the Vector is: " << oneVector.length() << endl;
	cout << "The current contents of the Vector are: "; 
	oneVector.print();
	cout <<endl;
	//// Add values 12,24,36,48 to oneVector
	int value2 = 12;
	cout << "Adding values 12,24,36,48 to Vector..." << endl << endl;
	for(int i=0; i<4; i++)
	{
		oneVector.push(value2);
		value2 = value2+12;
	}
	// Print current size of oneVector and its contents
	cout << "The current size of the Vector is: " << oneVector.length() << endl;
	cout << "The current contents of the Vector are: "; 
	oneVector.print();
	cout <<endl;
	//// Append a new value to oneVector
	cout << "Appending a value to Vector..." << endl;
	int itemFour = 567;
	oneVector.append(itemFour);
	// Print current size of oneVector and its contents
	cout << "The current size of the Vector is: " << oneVector.length() << endl;
	cout << "The current contents of the Vector are: "; 
	oneVector.print();
	cout <<endl;
	//// Prepend a new value to oneVector
	cout << "Prepending a value to Vector..." << endl;
	int itemSix = 44;
	oneVector.prepend(itemSix);
	// Print current size of oneVector and its contents
	cout << "The current size of the Vector is: " << oneVector.length() << endl;
	cout << "The current contents of the Vector are: "; 
	oneVector.print();
	cout <<endl;

	////////// Testing the copy Constructor 
	//// Copy oneVector into twoVector
	cout << "Creating a copy of Vector called twoVector..." << endl;
	SimpleVector twoVector(oneVector);
	// Print current size of twoVector and its contents
	cout << "The current size of twoVector is: " << twoVector.length() << endl;
	cout << "The current contents of twoVector are: "; 
	twoVector.print();
	cout <<endl;
	//// Create an empty Vector called threeVector
	cout << "Creating an empty Vector called threeVector..." << endl;
	SimpleVector threeVector;
	// Print current size of threeVector and its contents
	cout << "The current size of threeVector is: " << threeVector.length() << endl;
	cout << "The current contents of twoVector are: "; 
	threeVector.print();
	cout <<endl;
	//// Copy threeVector into fourVector
	cout << "Creating a copy of threeVector called fourVector..." << endl;
	SimpleVector fourVector(threeVector);
	// Print current size of fourVector and its contents
	cout << "The current size of fourVector is: " << fourVector.length() << endl;
	cout << "The current contents of fourVector are: "; 
	fourVector.print();
	cout <<endl;

	////////// Testing the extract and append functions
	//// Try to extract a value not found on twoVector
	cout << "Extracting value 5 from twoVector..." << endl;
	int extract1=5;
	twoVector.extract(extract1);
	// Print current size of twoVector and its contents
	cout << "The current size of twoVector is: " << twoVector.length() << endl;
	cout << "The current contents of twoVector are: "; 
	twoVector.print();
	cout <<endl;
	// Append a new value to twoVector
	cout << "Appending a value to twoVector..." << endl;
	int itemSeven = 44;
	twoVector.append(itemSeven);
	// Print current size of twoVector and its contents
	cout << "The current size of twoVector is: " << twoVector.length() << endl;
	cout << "The current contents of twoVector are: "; 
	twoVector.print();
	cout <<endl;
	//// Extract a value from twoVector
	cout << "Extracting value 44 from twoVector..." << endl;
	int extract2=44;
	twoVector.extract(extract2);
	// Print current size of twoVector and its contents
	cout << "The current size of twoVector is: " << twoVector.length() << endl;
	cout << "The current contents of twoVector are: "; 
	twoVector.print();
	cout <<endl;
	//// Extract another value from twoVector
	cout << "Extracting value 36 from twoVector..." << endl;
	int extract3=36;
	twoVector.extract(extract3);
	// Print current size of twoVector and its contents
	cout << "The current size of twoVector is: " << twoVector.length() << endl;
	cout << "The current contents of twoVector are: "; 
	twoVector.print();
	cout <<endl;

	////////// Testing the insertBefore function
	//// Try to insert a value into twoVector before a non-existant value
	cout << "Inserting value 7 into twoVector before given value 111..." << endl;
	int item15=7;
	twoVector.insertBefore(111, item15);
	//// Insert a value into twoVector before value 24
	cout << "Inserting value 24 into twoVector before given value 24..." << endl;
	int itemEight=24;
	twoVector.insertBefore(24, itemEight);
	//// Insert a value into twoVector before vector's first value
	cout << "Inserting value 24 into twoVector before given value 890..." << endl;
	int itemNine=24;
	twoVector.insertBefore(890, itemNine);
	//// Insert a value into twoVector before vector's last value
	cout << "Inserting value 890 into twoVector before given value 567..." << endl;
	int itemTen=890;
	twoVector.insertBefore(567, itemTen);
	// Print current size of twoVector and its contents
	cout << "The current size of twoVector is: " << twoVector.length() << endl;
	cout << "The current contents of twoVector are: "; 
	twoVector.print();
	cout <<endl;

	////////// Testing the insertAfter function
	//// Try to insert a value into twoVector after a non-existant value
	cout << "Inserting value 2 into twoVector after given value 1..." << endl;
	int item11=2;
	twoVector.insertAfter(1, item11);
	//// Insert a value into twoVector after vector's first value
	cout << "Inserting value 8 into twoVector after given value 24..." << endl;
	int item12=8;
	twoVector.insertAfter(24, item12);
	//// Insert a value into twoVector after value 12
	cout << "Inserting value 4 into twoVector after given value 12..." << endl;
	int item13=4;
	twoVector.insertAfter(12, item13);
	//// Insert a value into twoVector after vector's last value
	cout << "Inserting value 6 into twoVector after given value 567..." << endl;
	int item14=6;
	twoVector.insertAfter(567, item14);
	// Print current size of twoVector and its contents
	cout << "The current size of twoVector is: " << twoVector.length() << endl;
	cout << "The current contents of twoVector are: "; 
	twoVector.print();
	cout <<endl;

	////////// Testing the overloaded = (assignment) operator
	//// Empty Vetor = Non-Empty Vector
	cout << "Evaluating the following operation: threeVector = twoVector" << endl;
	threeVector = twoVector;
	// Print current size of threeVector and its contents
	cout << "The current size of threeVector is: " << threeVector.length() << endl;
	cout << "The current contents of threeVector are: "; 
	threeVector.print();
	cout <<endl;
	//// Non-Empty Vector = Empty Vector
	cout << "Evaluating the following operation: threeVector=fourVector" << endl;
	threeVector=fourVector;
	// Print current size of threeVector and its contents
	cout << "The current size of threeVector is: " << threeVector.length() << endl;
	cout << "The current contents of threeVector are: "; 
	threeVector.print();
	cout <<endl;
	//// Empty Vetor = Non-Empty Vector
	cout << "Evaluating the following operation: threeVector = twoVector" << endl;
	threeVector = twoVector;
	// Print current size of threeVector and its contents
	cout << "The current size of threeVector is: " << threeVector.length() << endl;
	cout << "The current contents of threeVector are: "; 
	threeVector.print();
	cout <<endl;
	//// Non-Empty Vector = Shorter Non-Empty Vector
	cout << "Evaluating the following operation: threeVector=Vector" << endl;
	threeVector=oneVector;
	// Print current size of threeVector and its contents
	cout << "The current size of threeVector is: " << threeVector.length() << endl;
	cout << "The current contents of threeVector are: "; 
	threeVector.print();
	cout <<endl;
	//// Try to self-copy threeVector
	cout << "Evaluating the following operation: threeVector=threeVector" << endl;
	threeVector=threeVector;
	// Print current size of threeVector and its contents
	cout << "The current size of threeVector is: " << threeVector.length() << endl;
	cout << "The current contents of threeVector are: "; 
	threeVector.print();
	cout <<endl;

	//Exit stage right
	return 0;
}