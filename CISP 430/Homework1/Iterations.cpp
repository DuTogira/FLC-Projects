//Austin Smothers
//CISP 430
//September 5, 2017

//This program builds on code provided by Professor Ross

//		HEADER FILE DECLARATION BLOCK
#include <iostream>
using namespace std;


//		GLOBAL FUNCTION DECLARATION BLOCK
int Arithmetic(int n)
{
	int sum = 0;

	for (int i = 1; i <= n; i++)
		sum = sum + i;

	return sum;
}

int Geom(int n, int A)
{
	int term = 0;
	int sum = 0;

	for (int i = 1; i <= n; i++)
	{
		term = A;
		for (int j = 1; j < i; j++)
			term = term * A;
		sum = sum + term;
	}

	return sum;
}

/*"Optimized" by replacing the second for loop with an if statement
I really don't think it decreases run time as it serves the same function as the old
for loop AND sends the computer through the same total number of processes... 
but according to lecture notes this is supposed to be better*/
int GeomOP(int n, int A)
{
	int term = 0;
	int sum = 0;
	int i = 0;
	i++;
	term = A;

	for (int j = 1; j <= i; j++)
	{
		if ((i == j) && (i <= n))
		{
			j = 1;	//reset j so that the for loop restarts after this statement is iterated
			sum = sum + term;
			term = A;
			i++;
		}
		term = term * A;
	}

	return sum;
}

/*The same as the Geom code, but before adding sum = sum + term
since at that point, term represents the value of the specific number at A^n*/
int Other(int n, int A)
{
	int term = 0;
	int sum = 0;
	int i = 0;
	i++;
	term = A;

	for (int j = 1; j <= i; j++)
	{
		if ((i == j) && (i <= n))
		{
			j = 1;
			term = term * i;
			sum = sum + term;
			term = A;
			i++;
		}
		term = term * A;
	}

	return sum;
}


//		MAIN FUNCTION BLOCK
int main()
{
	const int n = 5;
	const int A = 5;

	/*Arithmetic calls/outputs
	cout << "Arithmetic: " << Arithmetic(n) << "\n";*/

	/*Geom, GeomOP, and Other calls/outputs*/
	cout << "N = " << n << endl <<
			"A = " << A << endl <<
			"Geom: " << Geom(n, A) << endl <<
			"GeomOP: " << GeomOP(n, A) << endl <<
			"Other: " << Other(n, A) << endl;

	return 0;
}