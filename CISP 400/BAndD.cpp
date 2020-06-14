//BAndD.txt - Calculates birth and death rates
//Austin Smothers - October 5, 2016
//CISP 400

//NOTE: Professor, you will need to compile this code with BAndDH.h downloaded, which I have included in the dropbox folder as a .txt named BAndDH.txt.

//this program doesn't accept 0 as a numeric input. Thus, if 0 is your desired input, enter a negative number and the program will default to 0 for the desired variable.

//library functions
#include <iostream>
#include <iomanip>	//included for std::setprecision()
#include "BAndDH.h"	//header file inclusion

using namespace std;

//Global variable declarations
int whichCon;		//used to determine which constructor
double p = 0;		//stores population
int b = 0;		//stores births
int d = 0;		//stores deaths

//Function declarations
void classPass(double p, int b, int d);
			//accepts user input then passes data
			//to the class
void intro();
void outro();

//Input Validation Function declarations
int inVal2(int &UI);		//validates integer input
int inVal4(int &UI);		//validates integer input
double inVal5(double &UI);	//validates double input
int inVal6(double p, int &UI);	//validates integer input

//-----------------------------------------------------------
//			 The Main Function
//-----------------------------------------------------------
int main()
{
	intro();
	cin >> whichCon;
	if(inVal2(whichCon) == '1')
	{
		classPass(p, b, d);
			//creates the myTown class using
			//the 3 argument constructor
	}
	else
	{
		Population myTown;
			//creates the myTown class using
			//the null parameter constructor
	}
	outro();
	return 0;
}

//-----------------------------------------------------------
//		   Class Function Definitions
//-----------------------------------------------------------

//-------------------Constructors----------------------------

Population::Population()
{
	setPopulation();
	setBirths();
	setDeaths();
	showData();
}

Population::Population(double p, int b, int d)
{
	//these if statements check user input
	//against pre determined sentinals
	if(p < 2)
		pop = 2;
	else
		pop = p;
	if(b < 0)
		birthNum = 0;
	else
		birthNum = b;
	if(d < 0)
		deathNum = 0;
	else
		deathNum = d;
	showData();
}

//------------------Non-Constructors-------------------------

//sets the population parameter pop
void Population::setPopulation()
{
	cout << "Please enter this year's\nPopulation: ";
	cin >> p;
	if(inVal5(p) < 2)
		pop = 2;
	else
		pop = p;
}

//sets the population parameter birthNum
void Population::setBirths()
{
	cout << "Please enter this year's number of\n"
		"Births: ";
	cin >> b;
	if(inVal4(b) < 0)
		birthNum = 0;
	else
		birthNum = b;
}

//sets the population parameter deathNum
void Population::setDeaths()
{
	cout << "Please enter this year's number of\n"
		"Deaths: ";
	cin >> d;
	if(inVal6(d) < 0)
		deathNum = 0;
	else
		deathNum = d;
}

//computes and returns the birth rate
double Population::getBirthRate()
{
	birthRate = birthNum / pop;
	return birthRate;
}

//computes and returns the death rate
double Population::getDeathRate()
{
	deathRate = deathNum / pop;
	return deathRate;
}

void Population::showData()
{
	cout << std::setprecision(2) << std::fixed;
			//fixes output to 2 decimal places
	cout << "\n\nPopulation: " << pop << endl <<
		"# of Births: " << birthNum << endl <<
		"# of Deaths: " << deathNum << endl <<
		"Birth Rate: " << getBirthRate() <<
		" (or " << getBirthRate() * 100 << "%)\n"
		"Death Rate: " << getDeathRate() <<
		" (or " << getDeathRate() * 100 << "%)\n";
}

//this function will validate user input
int Population::inVal6(int & UI)
{	//UI is a reference to userInput
//--------Local variable declaration
	char failbit;	//used for input validation

	while(!UI || (UI > pop))
	{	//this loop validates numeric input
		cin.clear();
		cin.get(failbit);
		cout << "\aError: Invalid response!\n";
		cout << "Deaths can't be higher than "
			"population.\n";
		cout << "Please enter a number: ";
		cin >> UI;
	}
	return UI;
}

//-----------------------------------------------------------
//		  Non-Class Function Definitions
//-----------------------------------------------------------

void classPass(double p, int b, int d)
{
	cout << "Please enter this year's\nPopulation: ";
	cin >> p;
	inVal5(p);
	cout << "Please enter this year's number of\n"
		"Births: ";
	cin >> b;
	inVal4(b);
	cout << "Please enter this year's number of\n"
		"Deaths: ";
	cin >> d;
	inVal6(p, d);
	Population myTown(p, b, d);
			//creates the myTown class using
			//the 3 argument constructor
}

//----------------------Intro & Outro------------------------

void intro()
{
	cout << "Welcome to 'Mortality Calculator'!\n"
		"The best way to calculate the birth and\n"
		"death rates of a population!\n"
		"This program can be used in two ways:\n"
		"1) You input the population, # of Births,\n"
		"   and # of Deaths before passing them to\n"
		"   a class to be calculated.\n"
		"2) The class is made, and you input these\n"
		"   variables within the class itself!\n";
	cout << "Which would you like to do?\n"
		"(1/2): ";
}

void outro()
{
	cout << "Thanks for using 'Mortality Calculator'!\n"
		"Goodbye!\n";
}

//-----------------------------------------------------------
//	       Input Validation Function Definitions
//-----------------------------------------------------------

//this function will validate user input.
int inVal2(int & UI)
{	//UI is a reference to userInput
//--------Local variable declaration
	char failbit;	//used for input validation

	while( !UI || (UI != 1 && UI != 2) )
	{	//this loop validates user input
		cin.clear();
		cin.get(failbit);
		cout << "\aError: Invalid response!\n";
		cout << "Please enter your answer in 1/2 "
			"format: ";
		cin >> UI;
	}
	return UI;
}

//this function will validate user input
int inVal4(int & UI)
{	//UI is a reference to userInput
//--------Local variable declaration
	char failbit;	//used for input validation

	while(!UI)
	{	//this loop validates numeric input
		cin.clear();
		cin.get(failbit);
		cout << "\aError: Invalid response!\n";
		cout << "Please enter a number: ";
		cin >> UI;
	}
	return UI;
}

//this function will validate user input
double inVal5(double & UI)
{	//UI is a reference to userInput
//--------Local variable declaration
	char failbit;	//used for input validation

	while(!UI)
	{	//this loop validates numeric input
		cin.clear();
		cin.get(failbit);
		cout << "\aError: Invalid response!\n";
		cout << "Please enter a number: ";
		cin >> UI;
	}
	return UI;
}

//this function will validate user input
int inVal6(double p, int &UI)
{	//UI is a reference to userInput
//--------Local variable declaration
	char failbit;	//used for input validation

	while(!UI || (UI > p))
	{	//this loop validates numeric input
		cin.clear();
		cin.get(failbit);
		cout << "\aError: Invalid response!\n";
		cout << "Deaths can't be higher than "
			"population.\n";
		cout << "Please enter a number: ";
		cin >> UI;
	}
	return UI;
}
