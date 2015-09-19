#ifndef H_triangularMatrixType
#define H_triangularMatrixType

//System Libraries
#include <iostream>
using namespace std;

//specification for class

template <class T>
class triangularMatrixType
{
public:
	void setCols(int); //Function to set number of columns of Matrix
	T *filAray(); //Fills a 1-Dim array with the number of columns per row
	T **filAray(T*); //Fills second array
	void prntAry(T *) const; //Prints first array
	void prntAry(T **,T *) const; //Prints second array
	void destroy(T **,T *); //deallocates all dynamically allocated memory
	triangularMatrixType(); //default constructor

private:
	int col;
};

//implementation for class

//default constructor
template <class T>
triangularMatrixType<T> :: triangularMatrixType()
{
	col = 0;
}

//Sets numbers of columns for Matrix
template <class T>
void triangularMatrixType<T> :: setCols (int nCols){
	col = nCols;
}

//Fills a 1-Dim array with the number of
//Columns per row
template <class T>
T * triangularMatrixType<T> :: filAray(){
    T *array=new T[col];
    for(int i=0;i<col;i++){
        array[i]=i+1;
    }
    return array;
}

//Fills a second array
template <class T>
T ** triangularMatrixType<T> :: filAray(T *cols){

    //Allocates Memory
    T **array=new T*[col];
    for(int i=0;i<col;i++){
        array[i]=new T[cols[i]];
    }
    //Fill the allocated memory
    for(int row=0;row<col;row++){
        for(int column=0;column<cols[row];column++){
			array[row][column]=rand()%90+10;
        }
    }
    return array;
}

//Prints first array
template <class T>
void triangularMatrixType<T> :: prntAry(T *array) const{
    cout<<endl;
    for(int i=0;i<col;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

//Prints second array
template <class T>
void triangularMatrixType<T> :: prntAry(T **array,T *cols) const{
    cout<<endl;
    //Print the allocated memory
    for(int row=0;row<col;row++){
        for(int column=0;column<cols[row];column++){
            cout<<array[row][column]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

template <class T>
void triangularMatrixType<T> :: destroy(T **a,T *b){
    delete []b;
    for(int i=0;i<col;i++){
        delete []a[i];
    }
    delete []a;
}

#endif