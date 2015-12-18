// Minefield class
#ifndef MINEFIELD_H
#define MINEFIELD_H

#include <iostream>
#include <vector>
#include "MyVectorDA.h"
#include "BinaryTree.h"

using namespace std;

class Minefield
{
private:
	BinaryTree hidGrid;
	MyVectorDA<int> grid;
	vector<char> playGrid;
	int height;
	int width;

public:
	// Default constructor
	Minefield();
	// Destructor declaration
	~Minefield();
	// Function that gets the length for the minefield's sides
	int sidesLength();
	// Function that sets the length of height and width of minefield
	void setSize(int);
	// Function that allocates the necessary memory for both grid and playGrid according to height and width
	void allocateGrids();
	// Function that copies the contents of playGrid before starting to play
	void allocateHidGrid();
	// Function that prints to screen the contents of grid
	void printGrid();
	// Function that prints to screen the contents of playGrid
	void printPlayGrid();
	// Function that prints to screen the contents of hidGrid
	void printHidGrid();
	// Function that fills up playGrid with ASCII value 178, all locations hidden
	void setShown();
	// Function that cycles through all grid locations and stores the amount of mines surrounding each 
		//grid location using the CountNeighbors function
	void setCount();
	// Function that cycles through all grid locations and counts how many mines surround given location
	int countNeighbors(int, int);
	// Function that sets "heigth" many mines on grid
	void setMines();
	// Function that displays rules of how to play game
	void instructions();
	// Function asks the user whether it needs help of how to play or wants to play
	void helpPlay();
	// Function that gets the desired location and right/left click from user, restarts/exits game
		//if user chooses to. It also either reveals location's content, places a flag, removes a
		//flag, ends the game if a mine is uncovered, or ends the game when player wins
	void playTime(bool &);
	// Function that converts an int value into a char value and returns it
	char revealValue(int);
	// Function that clears the console screen and prints the contents of
		//playGrid with all the mines when user loses
	void losePlayGrid();
	// Function that clears the console screen and prints the contents of
		//playGrid with all the flags when user wins
	void winPlayGrid();
	// Function that clears the console screen
	void clearScreen();
	// Function that thanks the user for playing the game
	void endGame();
};


#endif