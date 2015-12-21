// A C++ Program to demonstrate adjacency list representation of graphs
#include<iostream>
#include <iomanip>
using namespace std;

// Structure for an adjacency list node
struct adjListNode
{
	int dest;
	int weight;
	adjListNode *next;
};

// Structure fo an adjacency list
struct adjList
{
	struct adjListNode *head;  // pointer to head node of list
};

// Structure to represent a graph. 
// A graph is an array of adjacency lists.
// Size of array will be the number of vertices in graph
struct graph
{
	int V;
	struct adjList *array;
};

// Giving index value to all vertices
enum vertices {SFO, LAX, DFW, ORD, JFK, MIA, BOS};
void createNode(adjListNode* node,int d, int w);
graph* initGraph(int V);
void shortestD(graph *g, int index1, int index2);
void addEdge(graph *g,int src,int dest, int w);
void print(graph *g);
void printLine();
void printHeader();

int main()
{
	//Print header
	printHeader();
	//Number of vertex
	int V=7;
	graph *g = new graph();
	g = initGraph(V);

	//Vertex 0
	addEdge(g, SFO, LAX, 337);
	addEdge(g, SFO, DFW, 1464);
    addEdge(g, SFO, ORD, 1846);
	addEdge(g, SFO, BOS, 2704);
	//Vertex 1
	addEdge(g, LAX, DFW, 1235);
    addEdge(g, LAX, MIA, 2342);
	//Vertex 2
    addEdge(g, DFW, ORD, 802);
	addEdge(g, DFW, MIA, 1121);
	//Vertex 3
	addEdge(g, ORD, JFK, 740);
	addEdge(g, ORD, BOS, 867);
	//Vertex 4
	addEdge(g, JFK, MIA, 1090);
	addEdge(g, JFK, BOS, 187);
	//Vertex 5
	addEdge(g, MIA, BOS, 1258);

	//print(g);
	cout<<endl;
	shortestD(g,BOS,LAX);
	cout<<endl;

	delete g;
	
	return 0;
}

// Function that creates a new adjacency list node
void createNode(adjListNode* node,int d, int w)
{
	node->dest=d;
	node->weight=w;
	node->next=NULL;
}

// Function that creates a graph of V vertices
graph* initGraph(int V)
{
	graph *g = new graph();
	g->V=V;
	g->array = new adjList[V];		// Create an array of adjacency lists. Size of array will be V

	// Initialize each adjacency list as empty by making head as NULL
	for(int i=0; i<V; i++)
	{
		g->array[i].head=NULL;
	}
	
	return g;			// return graph
}

// Shortest distance
void shortestD(graph *g, int index1, int index2)
{
	int sDis=2964;
	cout<<"The shortest distance from "<<index1<<" to "<<index2<<" is: "<<sDis<<endl;
}

// Adds an edge to an undirected graph
void addEdge(graph *g,int src,int dest, int w) 
{
	// Add an edge from src to dest.  A new node is added to the adjacency
	// list of src.  The node is added at the last

	adjListNode *tmp = new adjListNode();
	createNode(tmp,dest,w);

	adjListNode *curr = g->array[src].head;		// curr holds pointer of head

	if(curr == NULL)
	{		
		// if curr is NULL then make head = tmp( first node )
		tmp->next = g->array[src].head;
		g->array[src].head=tmp;
	}
	else 
	{		
		//	if curr is not NULL , vertex already have its adjecent elements
		while(curr->next!=NULL) {		// loop until we get curr->next=NULL
			curr=curr->next;
		}
		curr->next=tmp;
	}

	// Since graph is undirected, add an edge from dest to src also
	tmp = new adjListNode();
	createNode(tmp,src,w);
	curr = g->array[dest].head;
	if(curr == NULL)
	{
		tmp->next = g->array[dest].head;
		g->array[dest].head=tmp;
	} 
	else 
	{
		while(curr->next!=NULL)
		{
			curr=curr->next;
		}
		curr->next=tmp;
	}
}

// A utility function to print the adjacenncy list representation of graph
void print(graph *g)
{
	for(int i=0; i<g->V; i++)
	{
		adjListNode *tmp = g->array[i].head;
		cout<< "[" << i << "] ";   // to print [0] or [1] or [2] or ..... [V]
		while(tmp!=NULL)
		{
			cout<<"-> "<<tmp->dest;
			cout<<"("<<tmp->weight<<")";
			tmp=tmp->next;
		}
		cout<<endl;
	}
}

void printHeader()
{
	cout<<"\n\n";
	cout<<setw(30)<<"Problem 6 - Weighted Graph\n";
	cout<<"\n";
	cout<<"SFO="<<SFO<<" LAX="<<LAX<<" DFW="<<DFW<<" ORD="<<ORD<<" JFK="<<JFK
		<<" MIA="<<MIA<<" BOS="<<BOS<<endl;
	cout<<"\n";
	cout<<"|"<<setw(10)<<"From |"<<setw(20)<<"Edge Weight   |"<<setw(11)<<"To |\n";
	printLine();
	cout<<"|"<<setw(10)<<"SFO |"<<setw(20)<<"2704   |"<<setw(11)<<"BOS |\n";
	printLine();
	cout<<"|"<<setw(10)<<"SFO |"<<setw(20)<<"1846   |"<<setw(11)<<"ORD |\n";
	printLine();
	cout<<"|"<<setw(10)<<"ORD |"<<setw(20)<<" 867   |"<<setw(11)<<"BOS |\n";
	printLine();
	cout<<"|"<<setw(10)<<"ORD |"<<setw(20)<<" 740   |"<<setw(11)<<"JFK |\n";
	printLine();
	cout<<"|"<<setw(10)<<"JFK |"<<setw(20)<<" 187   |"<<setw(11)<<"BOS |\n";
	printLine();
	cout<<"|"<<setw(10)<<"SFO |"<<setw(20)<<"1464   |"<<setw(11)<<"DFW |\n";
	printLine();
	cout<<"|"<<setw(10)<<"DFW |"<<setw(20)<<" 802   |"<<setw(11)<<"ORD |\n";
	printLine();
	cout<<"|"<<setw(10)<<"DFW |"<<setw(20)<<"1121   |"<<setw(11)<<"MIA |\n";
	printLine();
	cout<<"|"<<setw(10)<<"MIA |"<<setw(20)<<"1090   |"<<setw(11)<<"JFK |\n";
	printLine();
	cout<<"|"<<setw(10)<<"MIA |"<<setw(20)<<"1258   |"<<setw(11)<<"BOS |\n";
	printLine();
	cout<<"|"<<setw(10)<<"SFO |"<<setw(20)<<" 337   |"<<setw(11)<<"LAX |\n";
	printLine();
	cout<<"|"<<setw(10)<<"LAX |"<<setw(20)<<"1235   |"<<setw(11)<<"DFW |\n";
	printLine();
	cout<<"|"<<setw(10)<<"LAX |"<<setw(20)<<"2342   |"<<setw(11)<<"MIA |\n";
	printLine();
}

void printLine()
{
	for(int i=1;i<36;i++)
		cout<<"--";
	cout<<"\n";
}