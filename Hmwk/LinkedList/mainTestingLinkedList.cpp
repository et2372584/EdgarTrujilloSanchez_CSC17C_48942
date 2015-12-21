#include <iostream>
#include <ctime>
#include <cstdlib>

#include "LinkedList.h"

using namespace std;

const int SIZE = 5;

int main()
{
    srand(time(0));
	//// Test the linked list on integer data type
    LinkedList<int> list1;

    for(int i=0;i<SIZE;++i)
	{
		list1.push(i+1);
		//list1.append(rand()%10+1);
    }
	list1.print();
    std::cout<<'\n';

	LinkedList<int> list2(list1);
	list2.print();
    std::cout<<'\n';

	int popItem=list2.pop(list1);
	list2.print();
    std::cout<<'\n';
	cout<<"Item popped: "<<popItem<<endl;
	std::cout<<'\n';

	cout<<"Length of list1 is: "<<list1.length()<<endl;
	cout<<"Length of list2 is: "<<list2.length()<<endl;
	std::cout<<'\n';

	cout<<"First item of list1 is: "<<list1.First()<<endl;
	cout<<"Last item of list1 is: "<<list1.Last()<<endl;
	std::cout<<'\n';

	cout<<"First item of list2 is: "<<list2.First()<<endl;
	cout<<"Last item of list2 is: "<<list2.Last()<<endl;
	std::cout<<'\n';

	int nValue1=25;
	int nValue2=40;
	list2.append(nValue1);
	list2.print();
	cout<<"Length of list2 is: "<<list2.length()<<endl;
	list2.prepend(nValue2);
	list2.print();
	cout<<"Length of list2 is: "<<list2.length()<<endl;
	list2.append(nValue2);
	list2.append(nValue2);
	list2.print();
	cout<<"Length of list2 is: "<<list2.length()<<endl;
	list2.extract(nValue2);
	list2.print();
	cout<<"Length of list2 is: "<<list2.length()<<endl;
	list2.insertBefore(3,nValue1);
	list2.print();
	list2.insertBefore(2,nValue1);
	list2.print();
	list2.extract(nValue1);
	list2.print();
	list2.insertAfter(5,nValue2);
	list2.print();
	list2.insertAfter(2,nValue2);
	list2.print();

	cout<<"Copy list2 into list1: "<<endl;
	list1.copyList(list2);
	cout<<"List1: ";
	list1.print();
	cout<<'\n';
	cout<<"List2: ";
	list2.print();
	cout<<'\n';

	cout<<"Delete first item in list1..."<<endl;
	list1.deleteNode(1);
	list1.print();
	cout<<"Delete sixth item in list1..."<<endl;
	list1.deleteNode(6);
	list1.print();
	cout<<"Delete fifth item in list1..."<<endl;
	list1.deleteNode(5);
	list1.print();
	cout<<"Delete a nonexistant(-1) item in list1..."<<endl;
	list1.deleteNode(0);
	list1.print();
	cout<<"Delete third item in list1..."<<endl;
	list1.deleteNode(3);
	list1.print();
	cout<<'\n';

	cout<<"List1: ";
	list1.print();
	cout<<'\n';
	cout<<"List2: ";
	list2.print();
	cout<<'\n';
	cout<<"list2=list1"<<endl;
	list2=list1;
	cout<<"List1: ";
	list1.print();
	cout<<'\n';
	cout<<"List2: ";
	list2.print();
	cout<<'\n';
	cout<<"list1=list1"<<endl;
	list1=list1;

   /*Demonstrating a stack utilizing a linked list*/
   /*
   list1.push(7); //Pushing items onto the stack
   list1.push(5);
   list1.toString();
   std::cout<<'\n';
   list1.pop(list1); //Popping the items off of the stack, returning the item and removing node
   list1.pop(list1);
   list1.pop(list1);
   list1.toString();
   std::cout<<'\n';
   std::cout<<list1.First()<<'\n'; //outputing first item on the stack without removal
   list1.toString();
   std::cout<<'\n';
   */
   /*Demonstrating a queue utilizing a linked list*/

   return 0;
}