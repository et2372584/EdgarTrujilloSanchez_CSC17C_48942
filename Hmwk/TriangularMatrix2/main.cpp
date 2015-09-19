/*
 * Edgar M Trujillo Sanchez
 * Sept 9th, 2015
 * Purpose:  Create a templated Class implementing the Matrix
*/

//System Libraries
#include <iostream>
#include "triangularMatrixType.h"
#include <cstdlib>
#include <ctime>
using namespace std;

//Execution Begins Here
int main(){
    //Initialize the random number generator
    srand(static_cast<unsigned int>(time(0)));

    //Declare variables

	triangularMatrixType<int> oneTriMatrix;
	int cols = 10;

	//Set number of columns on matrix
	oneTriMatrix.setCols(cols);

    //Fill the arrays
	int *d1ary=oneTriMatrix.filAray();
	int **d2ary=oneTriMatrix.filAray(d1ary);

    //Print the arrays
	oneTriMatrix.prntAry(d1ary);
	oneTriMatrix.prntAry(d2ary,d1ary);
    
    //Delete the dynamic arrays
	oneTriMatrix.destroy(d2ary,d1ary);

    return 0;
}

