//Linked List Implementation

#include <iostream>

using namespace std;

class Node
{
public:
	int data;
	Node * next;
};

int main()
{
	Node * root;	//Declares pointer for root of linked list
	root = new Node;	//Points root to a new node
	root->next = NULL;	//Sets next field of new node to NULL
	root->data = 5;

	Node * traverse;	//Declares pointer to traverse linked list
	traverse = root;	//Points traverse to root of liked list

	//do-while loop to print contents of linked list
	cout <<"The contents of the linked list are: ";
	do
	{
		cout << traverse->data <<endl;
		if (traverse->next != NULL)
			traverse = traverse->next;
	}
	while (traverse->next != NULL);
	traverse = NULL;
		
	//Create new node and add it to the end of the linked list
	Node * temp;
	temp = new Node;
	temp->next=NULL;
	temp->data=10;
	//Link new node to linked list
	root->next=temp;
	temp=NULL;

	//Create a new node and add it to the end of the linked list
	temp=new Node;
	temp->next=NULL;
	temp->data=15;
	//Link new node to linked list
	traverse = root;
	while (traverse->next !=NULL)
		traverse=traverse->next;
	traverse->next=temp;
	traverse=NULL;
	temp=NULL;

	//Add new node to the beginning of the linked list
	temp=new Node;
	temp->next=root;
	temp->data=4;
	root=temp;
	temp=NULL;

	//Add new node to the beginning of the linked list
	temp=new Node;
	temp->next=root;
	temp->data=3;
	root=temp;
	temp=NULL;

	//Add new node to the middle of the linked list
	temp=new Node;
	temp->next=NULL;
	temp->data=7;
	traverse=root;
	while (traverse->data !=5)
		traverse=traverse->next;
	temp->next=traverse->next;
	traverse->next=temp;
	temp=NULL;
	traverse=NULL;

	return 0;
}
		

	