/*
* Edgar M Trujillo Sanchez
* Sept 17th, 2015
* Purpose:  Test the newly created push and pull functions of the
* SimpleVector class.
*/

//System Libraries
#include <iostream>
#include "SimpleVector.h"
using namespace std;

//Execution Begins Here
int main()
{
	//Declare variables
	int sizeOfArray = 5; //Original size of array
	int crtSizeCounter = sizeOfArray; //"Current size of array" counter, initialized to original size of array
	int usageCounter = 0; //"Current usage of array" counter

	////////////////////////////////////////////////////////////////
	//Create array
	SimpleVector<int> oneVector(sizeOfArray);

	//Print contents of empty array
	cout << "Contents of empty array: ";
	for (int i = 0; i < crtSizeCounter; i++)
	{
		cout << oneVector.getElementAt(i) << " ";
	}
	cout << endl;

	//Print size of array
	cout << "Current size of array is: " << oneVector.size() << endl;

	//Print current usage of the copy of the array
	cout << "Current usage of array is: " << usageCounter << endl
		<< endl;

	/////////////////////////////////////////////////////////////////
	//////Push new value to array
	int newValue = 99;
	oneVector.push(crtSizeCounter, usageCounter, newValue, oneVector);

	//Prints content of array after pushing new value
	cout << "Contents of array after pushing new value '99': " << endl;
	for (int i = 0; i < crtSizeCounter; i++)
	{
		cout << oneVector.getElementAt(i) << " ";
	}
	cout << endl;

	//Print current usage of array
	cout << "Current usage of array is: " << usageCounter << endl << endl;

	//////Push another new value to array
	int newValue2 = 100;
	oneVector.push(crtSizeCounter, usageCounter, newValue2, oneVector);

	//Prints new contents of array after pushing new value
	cout << "Contents of array after pushing new value '100': " << endl;
	for (int i = 0; i < crtSizeCounter; i++)
	{
		cout << oneVector.getElementAt(i) << " ";
	}
	cout << endl;

	//Print current usage array
	cout << "Current usage of array is: " << usageCounter << endl << endl;

	//////Push 6 more values into array
	for (int i = 0; i<6; i++)
	{
		int newValue3 = i + 5;
		oneVector.push(crtSizeCounter, usageCounter, newValue3, oneVector);
	}

	//Prints new contents of array after pushing new value
	cout << "Contents of array after pushing six new values '5,6,7,8,9,10': " << endl;
	for (int i = 0; i < crtSizeCounter; i++)
	{
		cout << oneVector.getElementAt(i) << " ";
	}
	cout << endl;

	//Print size of array
	cout << "Current size of array is: " << oneVector.size() << endl;

	//Print current usage array
	cout << "Current usage of array is: " << usageCounter << endl << endl;

	/////////////////////////////////////////////////////////////////
	//Pop value from array
	oneVector.pop(usageCounter);

	//Prints new content of array after poping value
	cout << "Contents of array after popping last added value: " << endl;
	for (int i = 0; i < crtSizeCounter; i++)
	{
		cout << oneVector.getElementAt(i) << " ";
	}
	cout << endl;

	//Print current usage of the copy of the array
	cout << "Current usage of array is: " << usageCounter << endl << endl;

	//////Pop 7 values from array
	for (int i = 0; i<7; i++)
	{
		oneVector.pop(usageCounter);
	}

	//Prints new content of array after poping value
	cout << "Contents of array after popping 7 values: " << endl;
	for (int i = 0; i < crtSizeCounter; i++)
	{
		cout << oneVector.getElementAt(i) << " ";
	}
	cout << endl;

	//Print current usage of the copy of the array
	cout << "Current usage of array is: " << usageCounter << endl << endl;

	/////////////////////////////////////////////////////////////////
	//////Push 11 new values into array
	for (int i = 0; i<11; i++)
	{
		int newValue3 = i + 1;
		oneVector.push(crtSizeCounter, usageCounter, newValue3, oneVector);
	}

	//Prints new contents of array after pushing new value
	cout << "Contents of array after pushing 11 new values '1,2,3,4,5,6,7,8,9,10,11': " << endl;
	for (int i = 0; i < crtSizeCounter; i++)
	{
		cout << oneVector.getElementAt(i) << " ";
	}
	cout << endl;

	//Print size of array
	cout << "Current size of array is: " << oneVector.size() << endl;

	//Print current usage array
	cout << "Current usage of array is: " << usageCounter << endl << endl;

	return 0;
}