/*
* Edgar M Trujillo Sanchez
* File: main.cpp
* Sept 25th, 2015
* Purpose:  Create a templated simple vector class utilizing a single link-list class.
*	Test template with characters
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
		without passing a value*/
	////// Declare an empty SimpleVector object
	SimpleVector<char> oneVector;
	// Print current size of oneVector and its contents
	cout << "The current size of oneVector is: " << oneVector.length() << endl;
	cout << "The current contents of oneVector are: "; 
	oneVector.print();
	cout <<endl;

	////// Create twoVector w/a Node with data = ')'
    SimpleVector<char> twoVector(')');
	//// Print current size of twoVector and its contents
	cout << "The current size of twoVector is: " << twoVector.length() << endl;
	cout << "The current contents of twoVector are: "; 
	twoVector.print();
	cout <<endl;
	//// Add values !,&,+,0,5 to oneVector
	int value1 = '!';
	cout << "Adding values !,&,+,0,5 to oneVector..." << endl << endl;
	for(int i=0; i<5; i++)
	{	
		twoVector.push(value1);
		value1 = value1+5;
	}
	//// Print current size of twoVector and its contents
	cout << "The current size of twoVector is: " << twoVector.length() << endl;
	cout << "The current contents of twoVector are: "; 
	twoVector.print();
	cout <<endl;
	// Declare firstValue and lastValue variables
	char firstValue=0, lastValue=0;
	//// Find first value of twoVector and print it to screen
	cout << "Finding the first value of twoVector..." << endl;
	twoVector.first(firstValue);
	cout << endl;
	//// Find last value of twoVector and print it to screen
	cout << "Finding the last value of twoVector..." << endl;
	twoVector.last(lastValue);
	cout << endl;
	//// Delete a value from twoVector
	cout << "Deleting a value from twoVector..." << endl;
	twoVector.pop();
	//// Print current size of twoVector and its contents
	cout << "The current size of twoVector is: " << twoVector.length() << endl;
	cout << "The current contents of twoVector are: "; 
	twoVector.print();
	cout <<endl;
	//// Append a new value to twoVector
	cout << "Appending a value to twoVector..." << endl;
	int value2 = '/';
	twoVector.append(value2);
	//// Prepend a new value to twoVector
	cout << "Prepending a value to twoVector..." << endl;
	int value3 = '~';
	twoVector.prepend(value3);
	// Print current size of twoVector and its contents
	cout << "The current size of twoVector is: " << twoVector.length() << endl;
	cout << "The current contents of twoVector are: "; 
	twoVector.print();
	cout <<endl;
	//// Copy twoVector into threeVector
	cout << "Creating a copy of twoVector called threeVector..." << endl;
	SimpleVector<char> threeVector(twoVector);
	// Print current size of threeVector and its contents
	cout << "The current size of threeVector is: " << threeVector.length() << endl;
	cout << "The current contents of threeVector are: "; 
	threeVector.print();
	cout <<endl;
	//// Extract value '&' from threeVector
	cout << "Extracting value '&' from threeVector..." << endl;
	char extract1='&';
	threeVector.extract(extract1);
	// Print current size of threeVector and its contents
	cout << "The current size of threeVector is: " << threeVector.length() << endl;
	cout << "The current contents of threeVector are: "; 
	threeVector.print();
	cout <<endl;
	//// Insert value '*' into threeVector before vector's last value
	cout << "Inserting value '*' into threeVector before given value '/'..." << endl;
	char item1='*';
	threeVector.insertBefore('/', item1);
	//// Insert value '^' into threeVector after value 0
	cout << "Inserting value '^' into threeVector after given value '0'..." << endl;
	int item2='^';
	threeVector.insertAfter('0', item2);
	// Print current size of threeVector and its contents
	cout << "The current size of threeVector is: " << threeVector.length() << endl;
	cout << "The current contents of threeVector are: "; 
	threeVector.print();
	cout <<endl;

	////////// Testing the overloaded = (assignment) operator
	//// Empty Vector = Non-Empty Vector
	cout << "Evaluating the following operation: oneVector = twoVector" << endl;
	oneVector = twoVector;
	// Print current size of oneVector and its contents
	cout << "The current size of oneVector is: " << oneVector.length() << endl;
	cout << "The current contents of oneVector are: "; 
	oneVector.print();
	cout <<endl;
	//// Non-Empty Vector = Shorter Non-Empty Vector
	cout << "Evaluating the following operation: oneVector=threeVector" << endl;
	oneVector=threeVector;
	// Print current size of oneVector and its contents
	cout << "The current size of oneVector is: " << oneVector.length() << endl;
	cout << "The current contents of oneVector are: "; 
	oneVector.print();
	cout <<endl;
	//// Try to self-copy oneVector
	cout << "Evaluating the following operation: oneVector=oneVector" << endl;
	oneVector=oneVector;

	//Exit stage right
	return 0;
}