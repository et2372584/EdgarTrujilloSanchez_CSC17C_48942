#ifndef STACK
#define STACK

#include "LinkedList.h"

using namespace std;

class Stack
{
private:
	int stackSize;
	LinkedList<char> oneStack;
public:
	Stack();
	~Stack();

	bool isEmpty();
	int size();
	char top();
	void push(char );
	char pop();
	void print();
	void emptyStack();
};

#endif