#include <iostream>
#include <ctime>
#include <cstdlib>

#include "LinkedList.h"

using namespace std;

const int SIZE = 5;

int main()
{
	srand(time(0));
	LinkedList<int> list1;
	LinkedList<int> list2;
	LinkedList<int> list3;
	
	//Implementation of a stack using a linked list
	for(int i=0;i<SIZE;++i)
		list1.prepend(i+1);
		//list1.append(rand()%10+1);
	
	cout<<"Initial values in Stack\n";
	list1.print();
	cout<<'\n';
	//Pushing items onto the stack
	list1.prepend(10);
	list1.prepend(7);
	cout<<"Values 10 and 7 have been pushed onto the Stack\n";
	list1.print();
	cout<<'\n';
	//Popping the items off of the stack
	list1.pop(list1);
	list1.pop(list1);
	list1.pop(list1);
	cout<<"Three values have been poped off of the Stack\n";
	list1.print();
	cout<<'\n';
	//top item on the stack
	cout<<"Top value of the Stack: ";
	cout<<list1.First()<<'\n';
	cout<<"Current content of Stack:";
	list1.print();
	cout<<'\n';
	cout<<"Empty the Stack..\n";
	list1.ClearList();
	cout<<"Current content of Stack:";
	list1.print();
	cout<<'\n';
    
    /*
     //Implementation of a Queue using a linked list.
    for(int i=0;i<SIZE;++i){
        list2.append(rand()%10+1);
    }
    std::cout<<'\n';
    std::cout<<"Initial values in each node.\n";
    list2.toString();
    std::cout<<'\n';
    std::cout<<"Calling Enqueue to add to the end of the list.\n";
    list2.enqueue(10);
    list2.enqueue(2);
    list2.toString();
    std::cout<<'\n';
    std::cout<<"Calling the dequeue function to remove element from head.\n";
    std::cout<<list2.dequeue()<<'\n';
    list2.toString();
    std::cout<<'\n';
    
    // Implementation of a Priority Queue using a linked list
    for(int i=0;i<SIZE;i++){
        list3.append(rand()%10+1);
    }
    std::cout<<"Initial values in the list.\n";
    list3.toString();
    std::cout<<'\n';
    std::cout<<list3.removeMax(list3)<<'\n';
    list3.toString();
    std::cout<<'\n';
    
    // Implementation of a Sorted LinkedList
    list3.mergeSortList(&(list3.head));
    std::cout<<"The list in sorted order.\n";
    list3.toString();
	*/

	return 0;
}