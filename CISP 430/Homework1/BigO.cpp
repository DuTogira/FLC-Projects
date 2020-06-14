//Austin Smothers
//CISP 430
//Assignment 1
//September 5, 2017

//This program builds on code provided by Professor Ross

//		HEADER FILE INCLUSION BLOCK
#include <iostream>
using namespace std;

//		GLOBAL FUNCTION DECLARATION BLOCK
int foo1(int n);
int foo2(int n);
int foo3(int n);
int foo4(int n);


//		MAIN FUNCTION BLOCK
int main(void)
{
	/* n declared as a non global variable for... ummm... security reasons!
	n declared as a const variable to make sure run time is solely based on
	modified counters, not modified n's*/
	const int n = 16;

	//foo1 - foo4 output
	cout << "Foo1 run time: " << foo1(n) << "\n";
	cout << "Foo2 run time: " << foo2(n) << "\n";
	cout << "Foo3 run time: " << foo3(n) << "\n";
	cout << "Foo4 run time: " << foo4(n) << "\n";

	return 0;
}


//		GLOBAL FUNCTION DEFINITION BLOCK

//Foo1 looks like a basic N function
int foo1(int n)
{
	int counter = 0;

	for (int i = 0; i < n; i++)
		counter++;

	return counter;
}

//Foo2 looks like an N^2 function
int foo2(int n)
{
	int counter = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			counter++;

	return counter;
}

//Foo3 looks like a logN runtime function
int foo3(int n)
{
	int counter = 0;

	for (int i = n; i > 0; i = i/2)
		counter++;

	return counter;
}

//Foo4 looks like a 2^N runtime function
int foo4(int n)
{
	/*nifty trick so you dont have to keep changing the value of counter
	as this function recursively iterates*/
	static int counter = 0;
	counter++;

	if (n > 0)
	{
		foo4(n - 1);
		foo4(n - 1);
	}

	return counter;
}