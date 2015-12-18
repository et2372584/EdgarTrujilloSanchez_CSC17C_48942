//Minefield.cpp, implementation file of class

//System Libraries
#include <iostream>
#include <string>
#include <ctime>
#include "Minefield.h"
#include "MyVectorDA.h"

using namespace std;

// Default constructor
Minefield::Minefield()
{
		height=0;
		width=0;
}

// Destructor
Minefield::~Minefield()
{
	height=0;
	width=0;
}

// SidesLength function. It gets the length for the minefield's sides
int Minefield::sidesLength()
{
	// Variable holds length of the sides of the minefield
	int length=0;
	//Will continue looping until length is bigger than 0
	while(true)
	{
		cout<<"Enter the desired length for the minefield's sides: ";
		cin>>length;
		//if user gives a length of less than one
		if(length<1)
			cout<<"Not a valid length..."<<endl;
		//if length is valid break from loop and continue executing program
		else
			break;
	}
	return length;
}

// SetSize function. It sets the length of height and width of minefield
void Minefield::setSize(int size)
{
	height=size;
	width=size;
}

// AllocateGrids function. It allocates the necessary memory for both grid and
	//playGrid according to height and width
void Minefield::allocateGrids()
{
	grid.allocate(height*width);
	playGrid.assign(height*width,'0');
}

// AllocateHidGrid function. It copies contents of playGrid before starting to play
void Minefield::allocateHidGrid()
{
	for(int i=0; i<(height*width); i++)
	{
		char temp;
		temp=playGrid[i];
		hidGrid.insert(temp);
	}
}

// PrintGrid function. It prints to screen the contents of grid
void Minefield::printGrid()
{
	// Print contents of grid
	for(int i = 0; i<height; i++)
	{
		for(int j=0; j<width; j++)
			cout << grid.getElementAt(i*height+j) << "  ";
		cout<<endl<<endl;
	}
	cout<<endl;
}

// PrintPlayGrid function. It prints to screen the contents of playGrid
void Minefield::printPlayGrid()
{
	// Print contents of playGrid
	for(int i=0; i<height; i++)
	{
		for(int j=0; j<width; j++)
			cout<<playGrid[i*height+j]<< "  ";
		cout<<endl<<endl;
	}
	cout<<endl;
}

// PrintHidGrid function. It prints to screen the contents of hidGrid
void Minefield::printHidGrid()
{
	hidGrid.printInOrder();
}

// SetShown function. It fills up playGrid with ASCII value 178, all locations hidden
void Minefield::setShown()
{
	char a=178; //ASCII value 178
	//Using fill algorithm to initialize playGrid STL vector
	fill(playGrid.begin(), playGrid.end(), a);
}

// SetCount function. It cycles through all grid locations and stores the amount
	//of mines surrounding each grid location using the CountNeighbors function
void Minefield::setCount()
{
	//cycle through all grid locations
	for (int i= 0;i<height;i++)
	{
		for(int j=0; j<width; j++)
		{
			//if mine, no need to count
			if (grid.getElementAt(i*height+j)==9)
				continue;
			int count=countNeighbors(i,j);
			grid.operator[](i*height+j)=count;
		}
	}
}

// CountNeighbors function. It cycles through all grid locations and counts how many
	//mines surround the given location
int Minefield::countNeighbors(int row, int col)
{
	//counter for mines surrounding grid location
	int count=0;
	//cycle through all surrounding locations of given grid location
	for (int i=row-1; i<=row+1; i++)
	{
		for(int j=col-1; j<=col+1; j++)
		{
			//bounds check
			if (i<0 || i>=height || j<0 || j>=width)
				continue;
			//skip middle location
			if (i==row && j==col)
				continue;
			//current location is a mine
			if (grid.getElementAt(i*height+j)==9)
				//increase count by one when a mine is found
				count++;
		}
	}
	//return how many mines were found
	return count;
}

// SetMines function. It sets "heigth" many mines on grid
void Minefield::setMines()
{
	//Will keep looping until "heigth" many mines are set on grid
	for (int mineC=0; mineC<height; mineC++)
	{
		int row = rand() % height;
		int col = rand() % width;

		// If random location is already a mine, mineC decreases 
		//	by one so another mine is set in a new location
		if (grid.getElementAt(row*height+col)==9)
			mineC--;

		// Random location stores a mine
		grid.operator[](row*height+col)=9;
	}
}

// Instructions function. It displays rules of how to play game
void Minefield::instructions()
{
	cout<<endl;
	cout<<"1.Enter the desired row and column numbers to choose a location on the minefield"<<endl;
	cout<<"2.Enter 'l' for left click or 'r' for right click during the right/left click "<<
		"option to either ('l')reveal the content or ('r')place a flag on that location"<<endl;
	cout<<"3.Whenever a 0 is revealed you can safely open its neighboring cells"<<endl;
	cout<<"4.Whenever a number is revealed it is telling you how many mines are surrounding "<<
		"the current location"<<endl;
	cout<<"5.When you reveal all board's locations without revealing a mine you will win!"<<endl;
	cout<<"6.There are "<<height<<" mines on the minefield. Only "<<height<<" flags can be placed "<<
		"on the board. Flags help you remember where you believe a mine is"<<endl;
	cout<<"7.To unflag a flag select the flag's location and press 'r' during the right/left "<<
		"click option"<<endl;
	cout<<"8.Press 'D' to restart or 'E' to exit the game while in the right/left click option"<<endl;
	cout<<endl;
}

// HelpPlay function. It asks the user whether it needs help of how to play or wants to play
void Minefield::helpPlay()
{
	int choice;
	cout<<"Enter '0' for instructions or any other number to play: ";
	cin>>choice;
	//Will display how to play game if user enter a '0'
	if(choice==0)
	{
		instructions();
		//Value given by user will not be used, this lets user know that the game will start
		cout<<"Enter any number to start the game...";
		cin>>choice;
		cout<<endl<<endl;
	}
	else
		cout<<endl<<endl;
}

// PlayTime function. It gets the desired location and right/left click from user, restarts/exits
	//game if user chooses to. It also either reveals location's content, places a flag, removes a
	//flag, ends the game if a mine is uncovered, or ends the game when player wins
void Minefield::playTime(bool &set)
{
	int urow=0; //will hold the user-given row number
	int ucol=0; //will hold the user-given col number
	char uclick=0; //will hold user-given right/left click
	int totalCtn=0;//will keep track of open locations
	int total=grid.size();//holds total locations
	int flagCtn=0;//will keep track of how many flags are placed by user
	char hide=178; //ASCII value 178 for hidden locations on playGrid
	float seconds=0;

	// Will keep looping until a mine is uncovered, until the user wins, or if the user decides
		//to restart or exit the game
	for(int i=1; i>0; i++)
	{
		clock_t t1,t2;
		t1=clock();
		//Getting desired location from user and either right/left click
		cout<<"Enter row number: ";
		cin>>urow;
		cout<<"Enter col number: ";
		cin>>ucol;
		cout<<"Enter right click('r') or left click('l'): ";
		cin>>uclick;
		//Decrease urow and ucol by one to match memory "coordinates"
		urow--;
		ucol--;
		//Check if the location's "coordinates" are in-bounds
		if(urow<0||urow>=height||ucol<0||ucol>=height)
			continue;
		////// Options if user wants to restart/exti game
		//Restart game
		if(uclick=='D'||uclick=='d')
		{
			int confirm;
			cout<<"Confirm restart of game, press '0' to restart or any other number to continue playing: ";
			cin>>confirm;
			//If restart the game is confirmed
			if(confirm==0)
			{
				//Set=true to restart game
				set=true;
				//Breaks for-loop and ends function
				break;
			}
			//User decideds not to restart the game
			else
				//Skips all code after and starts a new iteration of for-loop
				continue;
		}
		//Exit game
		else if(uclick=='E'||uclick=='e')
		{
			int confirm;
			cout<<"Confirm that you want to exit the game, press '0' to exit or any other number to continue playing: ";
			cin>>confirm;
			//If exit the game is confirmed
			if(confirm==0)
			{
				//Set=false to exit game
				set=false;
				//Breaks for-loop and ends function
				break;
			}
			//User decideds not to exit the game
			else
				//Skips all code after and starts a new iteration of for-loop
				continue;
		}

		//If left click and chosen location is not a mine
		if(uclick=='l'&&grid.getElementAt(urow*height+ucol)!=9&&playGrid[urow*height+ucol]==hide)
		{
			//temp2 holds current grid value
			int temp2=grid.getElementAt(urow*height+ucol);
			//current location of playGrid set to char version of variable temp2
			playGrid[urow*height+ucol]=revealValue(temp2);
			//increases total count by one
			totalCtn++;
		}
		//Placing a flag
		else if(uclick=='r'&&playGrid[urow*height+ucol]!='F'&&flagCtn<height)
		{
			playGrid[urow*height+ucol]='F'; //places flag on chosen location
			totalCtn++; //increases total count by one
			flagCtn++; //increases flag count by one
		}
		//Removing a flag
		else if(uclick=='r'&&playGrid[urow*height+ucol]=='F')
		{
			playGrid[urow*height+ucol]=hide; //removes flag by hiding chosen location
			totalCtn--; //decreases total count by one
			flagCtn--; //decreases flag count by one
		}
		//Chosing a mine
		else if(uclick=='l'&&grid.getElementAt(urow*height+ucol)==9&&playGrid[urow*height+ucol]!='F')
		{
			//function that clears screen and prints playGrid with all mines
			losePlayGrid();
			cout<<"You just hit a mine, game over!"<<endl;
			//Calculate and display elapsed time of game
			t2=clock();
			float diff((float)t2-(float)t1);
			seconds=seconds+diff/CLOCKS_PER_SEC;
			cout<<"Total time: "<<seconds<<" seconds"<<endl;
			//Set=false to exit game
			set=false;
			//Breaks for-loop and ends function
			break;
		}

		//Check if all user has win game
		if(totalCtn==total)
		{
			//function that clears screen and prints playGrid with all flags
			winPlayGrid();
			cout<<"Congratulations, you win!"<<endl;
			//Calculate and display elapsed time of game
			t2=clock();
			float diff((float)t2-(float)t1);
			seconds=seconds+diff/CLOCKS_PER_SEC;
			cout<<"Total time: "<<seconds<<" seconds"<<endl;
			//Set=false to exit game
			set=false;
			//Breaks for-loop and ends function
			break;
		}
		//function that clears the console screen
		clearScreen();
		//function that prints current version of playGrid
		printPlayGrid();
		//flags left to place on minefield
		cout<<"Flags left: "<<height-flagCtn<<endl;
		//Calculate and display elapsed time of game
		t2=clock();
		float diff((float)t2-(float)t1);
		seconds=seconds+diff/CLOCKS_PER_SEC;
		cout<<"Elapsed time: "<<seconds<<" seconds"<<endl;
	}
}

// RevealValue function. It converts an int value into a char value and returns it.
char Minefield::revealValue(int value)
{
	char temp;
	// All possible values of variable value should be between 0-8
	for(int i=0; i<=8; i++)
	{
		if(value==i)
			// Converts int(i) into char(temp)
			temp='0'+i;
	}
	return temp;
}

// LosePlayGrid function. It clears the console screen and prints the contents
	//of playGrid with all the mines when user loses
void Minefield::losePlayGrid()
{
	//This clears the console screen
	clearScreen();
	// Print contents of playGrid with all mines
	for(int i=0; i<height; i++)
	{
		for(int j=0; j<width; j++)
		{
			// If grid's current location is a mine, set playGrid's current location to 'X'
			if(grid.getElementAt(i*height+j)==9)
				playGrid[i*height+j]='X';
			cout<<playGrid[i*height+j]<< "  ";
		}
		cout<<endl<<endl;
	}
	cout<<endl;
}

// WinPlayGrid function. It clears the console screen and prints the contents of
	//playgrid with all the flags when user wins
void Minefield::winPlayGrid()
{
	//This clears the console screen
	clearScreen();
	// Print contents of playGrid with all flags
	for(int i=0; i<height; i++)
	{
		for(int j=0; j<width; j++)
		{
			// If grid's current location is a mine, set playGrid's current location to 'F'
			if(grid.getElementAt(i*height+j)==9)
				playGrid[i*height+j]='F';
			cout<<playGrid[i*height+j]<< "  ";
		}
		cout<<endl<<endl;
	}
	cout<<endl;
}

// EndGame function. It thanks the user for playing
void Minefield::endGame()
{
	cout<<"Thank you for playing, good bye."<<endl;
}

// ClearScreen function. It clears the console screen
void Minefield::clearScreen()
{
	//Windows OS specific, might need to change
	system("CLS");
}