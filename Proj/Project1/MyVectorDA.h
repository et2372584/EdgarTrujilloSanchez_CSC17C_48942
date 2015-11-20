// MyVectorDA class template
#ifndef MYVECTORDA_H
#define MYVECTORDA_H

#include <iostream>
#include <new>       // Needed for bad_alloc exception
#include <cstdlib>   // Needed for the exit function

using namespace std;

template <class T>
class MyVectorDA
{
private:
	T *aptr;          // To point to the allocated array
	int arraySize;    // Number of elements in the array
	void memError();  // Handles memory allocation errors
	void subError();  // Handles subscripts out of range

public:
	// Default constructor
	MyVectorDA()
	{
		aptr = 0; arraySize = 0;
	}

	// Constructor declaration
	MyVectorDA(int);

	// Copy constructor declaration
	MyVectorDA(const MyVectorDA &);

	// Destructor declaration
	~MyVectorDA();

	// Accessor to return the array size
	int size() const
	{
		return arraySize;
	}

	// Allocate memory
	void allocate(int );

	// Accessor to return a specific element
	T getElementAt(int position);

	// Overloaded [] operator declaration
	T &operator[](const int &);

	// Overloaded = (Assignment) Operator
	MyVectorDA &operator= (const MyVectorDA &);

	// Function that adds a new item into the array
	void push(int &, int&, T, MyVectorDA &);

	// Function that deletes the last item added into the array
	void pop(int &);

	// Function that sorts the Vector from smallest to biggest value
	void markSrt(int);
};

//***********************************************************
// Constructor for SimpleVector class. Sets the size of the *
// array and allocates memory for it.                       *
//***********************************************************
template <class T>
MyVectorDA<T>::MyVectorDA(int s)
{
	arraySize = s;
	// Allocate memory for the array.
	try
	{
		aptr = new T[s];
	}
	catch (bad_alloc)
	{
		memError();
	}

	// Initialize the array.
	for (int count = 0; count < arraySize; count++)
		*(aptr + count) = 0;
}

//*******************************************
// Copy Constructor for SimpleVector class. *
//*******************************************
template <class T>
MyVectorDA<T>::MyVectorDA(const MyVectorDA &obj)
{
	// Copy the array size.
	arraySize = obj.arraySize;

	// Allocate memory for the array.
	aptr = new T[arraySize];
	if (aptr == 0)
		memError();

	// Copy the elements of obj's array.
	for (int count = 0; count < arraySize; count++)
		*(aptr + count) = *(obj.aptr + count);
}

//**************************************
// Destructor for SimpleVector class.  *
//**************************************
template <class T>
MyVectorDA<T>::~MyVectorDA()
{
	if (arraySize > 0)
		delete[] aptr;
	arraySize=0;
}

//*******************************************************
// memError function. Displays an error message and     *
// terminates the program when memory allocation fails. *
//*******************************************************
template <class T>
void MyVectorDA<T>::memError()
{
	cout << "ERROR:Cannot allocate memory.\n";
	exit(EXIT_FAILURE);
}

//***********************************************************
// subError function. Displays an error message and         *
// terminates the program when a subscript is out of range. *
//***********************************************************
template <class T>
void MyVectorDA<T>::subError()
{
	cout << "ERROR: Subscript out of range.\n";
	exit(EXIT_FAILURE);
}

// Allocate memory
template <class T>
void MyVectorDA<T>::allocate(int s)
{
	arraySize = s;
	// Allocate memory for the array.
	try
	{
		aptr = new T[s];
	}
	catch (bad_alloc)
	{
		memError();
	}

	// Initialize the array.
	for (int count = 0; count < arraySize; count++)
		*(aptr + count) = 0;
}

//*******************************************************
// getElementAt function. The argument is a subscript.  *
// This function returns the value stored at the sub-   *
// cript in the array.                                  *
//*******************************************************
template <class T>
T MyVectorDA<T>::getElementAt(int sub)
{
	if (sub < 0 || sub >= arraySize)
		subError();
	return aptr[sub];
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************
template <class T>
T &MyVectorDA<T>::operator[](const int &sub)
{
	if (sub < 0 || sub >= arraySize)
		subError();
	return aptr[sub];
}

// Overloaded = (Assignment) Operator
template <class T>
MyVectorDA<T> &MyVectorDA<T> :: operator= (const MyVectorDA &a)
{
	// Copy the array size.
	arraySize = a.arraySize;

	// Allocate memory for the array.
	aptr = new T[arraySize];
	if (aptr == 0)
		memError();

	// Copy the elements of a's array.
	for(int count = 0; count < arraySize; count++)
		*(aptr + count) = *(a.aptr + count);
	
	return *this; // Returning current object
}

// Push function. It adds a new item into the array
template <class T>
void MyVectorDA<T>::push(int &current, int &usage, T nItem, MyVectorDA & obj)
{	//Regular push, new item added into array
	if (usage < current)
	{
		operator[](usage) = nItem;
		usage++;
	}
	//Complex push, array size is doubled before addding new item into array
	else if (usage = current)
	{
		current = current * 2; //double the current size of array
		int* temp = new int[current]; //create a temporary array to store current contents of array
		//copy current contents of array into temp array
		for (int i = 0; i<usage; i++)
			temp[i] = obj.operator[](i);
		//initiallize unused space on temp array to 0
		for (int i = usage; i<current; i++)
			temp[i] = 0;
		temp[usage] = nItem;//copy new item into next avaliable index on array

		arraySize = current;//change original array size to new current size 
		usage++;//increase usage counter

		delete[] obj.aptr;//delete old original array
		obj.aptr = temp;//point original array's pointer to temp array
	}
	else
	{
		cout << "ERROR: There's no more space on the array.\n";
		exit(EXIT_FAILURE);
	}
}

// Pop function. It deletes the last item added into the array
template <class T>
void MyVectorDA<T>::pop(int &usage)
{	//pops one item from array
	if (usage >= 0)
	{
		operator[](usage - 1) = 0;
		usage--;//decrease usage counter
	}
	else
	{
		cout << "ERROR: There's no more items on the array that can be pop.\n";
		exit(EXIT_FAILURE);
	}
}

// MarkSort function.  It sorts the Vector from smallest to biggest value
template <class T>
void MyVectorDA<T>::markSrt (int n)
{
	for(int position=0; position<n-1; position++)
	{
		for(int next=position+1; next<n; next++)
		{
			if(*(aptr+position) > *(aptr+next) )
			{
				int temp=*(aptr+position);
				*(aptr+position)=*(aptr+next);
				*(aptr+next)=temp;
			}
		}
	}
}
#endif