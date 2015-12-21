#include <iostream>
#include <iomanip>
#include <cmath>
#include "Stack.h"

using namespace std;

//Function Prototypes
float rSin(float, Stack &);
float rCos(float, Stack &);
void printLine();

const int SIZE = 5;

int main()
{
	////Recursive sin/cos
	Stack stack1;
	
	cout<<"\n\n";
	cout<<setw(42)<<"Problem 2 - Stacks\n";
	//printLine();
	cout<<"\n";
	cout<<"|"<<setw(8)<<"Value |"<<setw(11)<<"Sin= |"<<setw(11)<<"Cos= |"
		<<setw(19)<<"Times called(sin) |"<<setw(19)<<" Times called(cos) |\n";
	for(float val=-1; val<=1.1; val+=0.5)
	{
		float sinV=rSin(val, stack1);
		float cosV=rCos(val, stack1);

		int sinCounter=0;
		int cosCounter=0;
		while(!stack1.isEmpty())
		{
			char fCall=stack1.pop();
			if(fCall=='S')
				sinCounter++;
			else if(fCall=='C')
				cosCounter++;
		}
		printLine();
		cout<<"|"<<setw(7)<<val<<"|"<<setw(10)<<sinV<<"|"
			<<setw(10)<<cosV<<"|"<<setw(18)<<sinCounter<<"|"
			<<setw(18)<<cosCounter<<" |\n";
	}
	printLine();
	cout<<"\n";

	return 0;
}

float rSin(float angle, Stack &one)
{
	char cSin='S';
	one.push(cSin);
	float tol=1e-2;
    if(angle>-tol&&angle<tol)return angle-angle*angle*angle/6;
    return 2*rSin(angle/2,one)*rCos(angle/2,one);
}
    
float rCos(float angle, Stack &one)
{
	char cCos='C';
	one.push(cCos);
	float tol=1e-2;
    if(angle>-tol&&angle<tol)return 1-angle*angle/2+angle*angle*angle*angle/24;
    float cosv=rCos(angle/2,one);
    float sinv=rSin(angle/2,one);
    return cosv*cosv-sinv*sinv;
}

void printLine()
{
	for(int i=1;i<36;i++)
		cout<<"--";
	cout<<"\n";
}