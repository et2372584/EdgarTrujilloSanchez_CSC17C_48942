/*
* Edgar M Trujillo Sanchez
* Dec 20th, 2015
* Purpose: FinalProject - This program will simulate the game Minesweeper
* using the STL vector and some of its algorithms, as well as my own
* vector class. It will also include a binary tree structure, which uses
* recursive algorithms to display its contents.
*/


#include <iostream>
#include<ctime>
#include "Minefield.h"

using namespace std;

int main()
{
	// Initialize the random number generator
    srand(static_cast<unsigned int>(time(0)));
	
	// Welcomes user to game
	cout<<"Welcome to Minesweeper v.2 Game"<<endl;

	// Declaring minefield object
	Minefield minefield;

	//// Getting length of minefield's sides
	//Variable holds length of the sides of the minefield
	int length=0;
	length=minefield.sidesLength();

	// Set size of minefield
	minefield.setSize(length);
	cout<<endl;

	// Decide if help or play
	minefield.helpPlay();

	// Loop will continue looping until user wins or user decides to exit game
	bool control=true;
	do
	{
		// Allocate grids with user-given size
		minefield.allocateGrids();

		// Set playGrid will all locations hidden
		minefield.setShown();

		// Allocate hidden grid
		minefield.allocateHidGrid();

		// Set mines on grid
		minefield.setMines();

		// Set count after placing mines
		minefield.setCount();

		// Print grid
		//minefield.printGrid();

		// Print hidGrid
		//minefield.printHidGrid();

		// Print playGrid
		minefield.printPlayGrid();

		// Start playing game
		minefield.playTime(control);

		//end-of-line statement for when restarting the game
		if(control==true)
			cout<<endl;

	}while(control==true);

	// End of game
	minefield.endGame();

	return 0;
}
