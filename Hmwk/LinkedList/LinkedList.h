#ifndef LINKEDLIST
#define LINKEDLIST

using namespace std;

template<class T>
class LinkedList
{
private:
	struct Node
	{
		//Node() : next(nullptr){}
		//Node(const T &val ,Node* next = nullptr,Node* prev = nullptr) : value(val), next(nullptr), prev(nullptr){}
		//struct Node* next;
		//struct Node* prev;
		T value;
		Node *next;
		Node *prev;
	};
	Node *root; // Pointer to start of linked list
	Node *tail;
	int listSize; // Number of elements in the linked list
public:
	LinkedList();
	~LinkedList();
	void ClearList();
	LinkedList(const LinkedList &);
	void push(T);
	int pop(LinkedList &);
	bool isEmpty(LinkedList &);
	int length();
	void print();
	T First();
	T Last();
	void append(T );
	void prepend(T );
	void extract(T );
	//void insertBefore(T,int);
	void insertBefore(T, T);
	//void insertAfter(T,int);
	void insertAfter(T, T);
	void copyList(const LinkedList &);
	void deleteNode(int);
	LinkedList &operator=(const LinkedList &);

	//T dequeue();
	//void enqueue(T);
	//void Back();

};

// Constructor
template<class T>
LinkedList<T>::LinkedList() //: head(nullptr),tail(nullptr)
{
	root = nullptr;
	tail = nullptr;
	listSize = 0;
}

// Destructor
template<class T>
LinkedList<T>::~LinkedList()
{
    ClearList();
}

// Used to delete the contents of the linked list
template<class T>
void LinkedList<T>::ClearList()
{
    Node *current = root;
    while(root)
	{
        current = root;
        root = root->next;
        delete current;
		listSize--;
    }

    root = nullptr;
    tail = nullptr;
}

// Copy Constructor
template<class T>
LinkedList<T>::LinkedList(const LinkedList &l)
{
    Node *p1 = nullptr;
    Node *p2 = nullptr;

	// If l is empty, initialize this list to an empty state
    if(l.root == nullptr)
	{
        root = nullptr;
		listSize=0;
    }

    else
	{
        root = new Node;
        root->next = l.root->next;
        root->value = l.root->value;

        p1 = root;
        p2 = l.root->next;
    }

    while(p2)
	{
        p1->next = new Node;
        p1 = p1->next;
        p1->next = p2->next;
        p1->value = p2->value;

        p2 = p2->next;
    }
	listSize=l.listSize;
	p1->next = nullptr;
}

// It adds a new item to the end of the linked list
template<class T>
void LinkedList<T>::push(T val)
{
    // Declaring temporary pointer
	Node *tempPush;
	// Creating new node
	tempPush=new Node;
	tempPush->value=val;
	tempPush->next=nullptr;
	// Linking new node to list
	if (root != nullptr)	// If linked list is not empty, it adds the new node to the end of the list
	{
		Node *traversePush=root;
		while(traversePush->next != nullptr)
			traversePush = traversePush->next;
		traversePush->next = tempPush;
		listSize++;
		traversePush = nullptr;
	}
	else	// If linked list is empty, root is pointed to the new node
	{
		root=tempPush;
		listSize++;
	}
	tempPush = nullptr; // Sets temporary pointer to NULL before exiting function
}

// Deletes an element from root of the list
template<class T>
int LinkedList<T>::pop(LinkedList &l)
{
   if(isEmpty(l))
       return -1;
   else
   {
	   int temp = root->value;
	   Node *temp2 = root;
	   root = root->next;
	   delete temp2;
	   listSize--;
	   return temp;
   }
}

// Checks if list is empty
template<class T>
bool LinkedList<T>::isEmpty(LinkedList &l)
{
    if(root==nullptr)
        return true;
    return false;
}

// It returns the current size of the linked list
template<class T>
int LinkedList<T>::length()
{
	return listSize;
}

// Prints the contents of the list
template<class T>
void LinkedList<T>::print()
{
	Node *traversePrint = root;
	if (traversePrint != NULL)
	{
		while(traversePrint!=nullptr)
		{
			cout<<traversePrint->value<<" ";
			traversePrint = traversePrint->next;
		}
		cout<<endl;
	}
	else
		cout << "It is empty!!!" << endl;
}

// Function that returns the first value in the linked list
template<class T>
T LinkedList<T>::First()
{
	if(root==nullptr)
		return -1;
	else
		return root->value;
}

// Function that returns the last value in the linked list
template<class T>
T LinkedList<T>::Last()
{
    Node* temp = root;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    return temp->value;
}

// Adds an element to the end of the list
template<class T>
void LinkedList<T>::append(T val)
{
    Node *temp;
    Node *traverse;

    //allocate memory for a new node
    temp = new Node;
	temp->value=val;
	temp->next=nullptr;

    if(!root)
	{
		root = temp;
		listSize++;
	}
    else
	{
      traverse = root;
      while(traverse->next != nullptr)
	  {
        traverse = traverse->next;
        //traverse->prev = traverse;
      }
      traverse->next = temp;
      //temp->prev = traverse;
	  listSize++;
    }
	temp=nullptr;
	traverse=nullptr;;
}

// Adds a new item to the beginning of the list
template<class T>
void LinkedList<T>::prepend(T val)
{
	// Declaring temporary pointer
	Node *prependPush;
	// Creating new node and linking it to the front of list
	prependPush=new Node;
	prependPush->value=val;
	prependPush->next=root;
	root=prependPush;
	listSize++;
	prependPush = nullptr; // Sets temporary pointer to NULL before exiting function
}

// Looks for given value in linked list and deletes
	// all instances of it
template<class T>
void LinkedList<T>::extract(T val)
{
	// Temporary traverse pointers
	Node *traverse1=root;
	Node *traverse2=root;
	Node *traverse3=traverse2->next;
	// Temporary counter
	int tempCount=listSize;

	while(traverse2!=NULL)
	{
		if(traverse2->value!=val)
		{
			traverse1=traverse2;
			traverse2=traverse2->next;
			if(traverse3==NULL)
				traverse3=traverse3;
			else
				traverse3=traverse3->next;
		}
		else if(traverse2==root)
		{
			root=traverse3;
			delete traverse2;
			listSize--;
			traverse1=root;
			traverse2=traverse3;
			if(traverse3==NULL)
				traverse3=traverse3;
			else
				traverse3=traverse3->next;
		}
		else
		{
			traverse1->next=traverse2->next;
			delete traverse2;
			listSize--;
			traverse2=traverse3;
			if(traverse3!=NULL)
				traverse3=traverse3->next;
			else
				traverse3=traverse3;
		}
	}
	traverse1=nullptr;
	if(listSize==tempCount)
		cout << "Value not found! No values deleted." << endl;
}

// Inserts an element before the given value in the list
template<class T>
void LinkedList<T>::insertBefore(T gvalue, T input)
{
	// Temporary traverse pointers
	Node *traverse1=root;
	Node *traverse2=traverse1;
	// Temporary counter
	int tempCount=listSize;
	// Traverse linked list until traverse2 points to NULL
	while(traverse2!=nullptr)
	{
		// Traverse linked list until given value is found
		if(traverse2->value!=gvalue)
		{
			traverse1=traverse2;
			if(traverse2!=NULL)
				traverse2=traverse2->next;
			else
				traverse2=traverse2;
		}
		else if(traverse1==root)
		{
			root=new Node;
			root->value=input;
			root->next=traverse1;
			listSize++;
			traverse2=NULL;
		}
		else
		{
			Node *temp=new Node;
			temp->value=input;
			temp->next=traverse2;
			traverse1->next=temp;
			listSize++;
			traverse2=nullptr;
		}
	}
	// Set temporary pointers to NULL before end of function
	traverse1=nullptr;
	traverse2=nullptr;
	// Check if the given value was found using the listSize
	if(tempCount==listSize)
		cout << "Given value not found. No changes made." << endl;
/*
void LinkedList<T>::insertBefore(T val,int pos)
{
    //Create new Node struct and crawler
    Node *curr = head;
    Node *prev = head;
    Node *newNode = new Node(val);
    //traverse list to desired location
    for(int i=0;i<pos;++i){
        prev = curr;
        curr = curr->next;
    }
    newNode->next = curr;
    prev->next = newNode;
}
*/
}

// Inserts an element after the given value in the list
template<class T>
void LinkedList<T>::insertAfter(T gvalue, T input)
{
	// Temporary traverse pointers
	Node *traverse1=root;
	Node *traverse2=traverse1->next;
	// Temporary counter
	int tempCount=listSize;
	// Traverse linked list until traverse1 points to NULL
	while(traverse1!=nullptr)
	{
		// Traverse linked list until given value is found
		if(traverse1->value!=gvalue)
		{
			traverse1=traverse2;
			if(traverse2!=nullptr)
				traverse2=traverse2->next;
			else
				traverse2=traverse2;
		}
		else
		{
			// Create new node
			Node *temp=new Node;
			temp->value=input;
			temp->next=traverse2;
			traverse1->next=temp; // Connect new node to linked list
			listSize++; // Increase listSize
			traverse1=nullptr;
		}
	}
	// Set temporary pointers to NULL before end of function
	traverse1=nullptr;
	traverse2=nullptr;
	// Check if the given value was found using the listSize
	if(tempCount==listSize)
		cout << "Given value not found. No changes made." << endl;
/*
void LinkedList<T>::insertAfter(T val,int pos){
    //allocate memory for new node
    Node *curr = head;
    Node *prev = head;
    Node *newNode = new Node;
    newNode->value = val;
    for(int i=0;i<pos+1;++i){
        prev = curr;
        curr = curr->next;
    }
    std::cout<<prev->value;
    std::cout<<curr->value;
    newNode->next = curr;
    prev->next = newNode;
}*/
}

// Copies the contents of a given linked list into another linked list
template<class T>
void LinkedList<T>::copyList(const LinkedList &gList)
{
	Node *traverse1;
	Node *traverse2;
	if (root!=nullptr) // If this list is non-empty, make it empty
	{
		while(root!=nullptr)
		{
			traverse1=root;
			root=root->next;
			delete traverse1;
		}
	}
	// If gList is empty, initialize this list to an empty state
	if (gList.root==nullptr)
	{
		root=NULL;
		listSize=0;
	}
	else // If gList is not empty, copy its contents to this list
	{
		// Start copying gList into this list
		traverse1=gList.root;
		//// Copy first node of gList
		root = new Node;
		root->value=traverse1->value;
		root->next=nullptr;
		traverse1=traverse1->next; // Move traverse1 to next node of gList
		traverse2=root; // Point traverse2 to root of this list
		//// Copy rest of gList
		Node *temp=nullptr;
		while (traverse1!=nullptr)
		{
			// Create a new node
			temp = new Node;
			temp->value=traverse1->value;
			temp->next=nullptr;
			traverse2->next=temp; // Connects new node to the end of this list
			traverse2=temp; // Move traverse2 to the end of this list
			traverse1=traverse1->next; // Move traverse1 to next node of gList
		}
		temp=nullptr; // Sets temporary pointer to NULL before exiting function
		traverse2=nullptr; // Sets temporary pointer to NULL before exiting function
		listSize=gList.listSize; // Copy size of gList into listSize of this list
	}
}

// Deletes a node in the list at the given index
template<class T>
void LinkedList<T>::deleteNode(int index)
{
	//check that index is not bigger than listSeize and linked list is not empty
	if(index>listSize && listSize>0)
		cout<<"Invalid index!"<<endl;
	//check that index is bigger than 0
	else if(index<=0)
		cout<<"Invalid index!"<<endl;
	//continue deleting node if index is valid
	else
	{
		// If linked list has only one node
		if (root->next==nullptr)
		{
			delete root;
			listSize--;
			root=nullptr;
		}
		// If linked list has more than one node
		else
		{
			// Temporary traverse pointer
			Node *traverse1=root;

			// Deleting node 1 in linked list that has more than one node
			if(index==1)
			{
				root=traverse1->next;
				delete traverse1;
				listSize--;
				traverse1=nullptr;
			}

			else
			{
				// Additional temporary traverse pointers
				Node *traverse2=root;
				Node *traverse3=traverse2->next;

				// traversing linked list
				for(int i=1;i<index;i++)
				{
					traverse1=traverse2;
					traverse2=traverse2->next;
					if(traverse3==nullptr)
						traverse3=traverse3;
					else
						traverse3=traverse3->next;
				}
				traverse1->next=traverse3;
				delete traverse2;
				listSize--;
				traverse1=nullptr;
				traverse2=nullptr;
				traverse3=nullptr;
			}
		}
	}
}

// Overloaded = (Assignment) Operator
template<class T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList &gList)
{
    if (root!=gList.root) // Avoid self-copy
		copyList(gList);
    else // Notify attempt of self-copy
		cout << "Attempting to self-copy. No changes made." << endl;
	return *this; // Returning current object
}

/*
template<class T>
T LinkedList<T>::dequeue(){
   int tmp = tail->value;
   delete tail;
   return tmp;
}*/

#endif