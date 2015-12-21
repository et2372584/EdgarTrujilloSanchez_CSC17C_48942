//Stack.cpp, implementation file of class

//System Libraries
#include "Stack.h"

// Constructor
Stack::Stack()
{
	stackSize=0;
}

// Destructor
Stack::~Stack()
{
	stackSize=0;
}

// Check if stack is empty
bool Stack::isEmpty()
{
	if(oneStack.length()==0)
		return true;
	else
		return false;
}

int Stack::size()
{
	return oneStack.length();
}

char Stack::top()
{
	return oneStack.First();
}

void Stack::push(char input)
{
	oneStack.prepend(input);
	stackSize++;
}

char Stack::pop()
{
	char valPop=oneStack.pop(oneStack);
	stackSize--;
	return valPop;
}

void Stack::print()
{
	oneStack.print();
}

//Empty Stack
void Stack::emptyStack()
{
	oneStack.ClearList();
	if(size()==0)
		stackSize=0;
}
