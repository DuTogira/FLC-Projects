//sEditor.txt – Creates a file to store strings and manipulate them
//Austin Smothers
//CISP 400

//Library functions
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <string>
#include <vector>
#include "sEditorH.h"

using namespace std;

//Global variable declarations
bool run = true;	//creates a variable which controls 				//whether or not the program is run
int count = 0;		//declaration of counter to be used

//Function Declarations
char inVal(char & UI);	//BONUS: a function to validate
			//user input (L/N val)
char inVal2(char & UI);	//same as aforementioned (A/D/R val)
char inVal3(char & UI);	//same as aforementioned (Y/N val)
int inVal4(int & UI);	//same as aforementioned (num val)
char inVal5(char &UI);	//same as aforementioned (N/A/D/R val)


//-----------------------------------------------------------
//			 The Main Function
//-----------------------------------------------------------
int main()
{
	char helper;
while(run == true)
{
	cout << "Would you like to:\n"
		"Add items to the current list;\n"
		"Combine elements of the list;\n"
		"Equate/Combine elements of the list;\n"
		"Display the current list;\n"
		"or remove elements from the list?\n"
		"(A/C/E/D/R): ";
	cin >> helper;
	if(inVal5(helper) == 'C' || inVal5(helper) == 'c')
		count = makeR(list, count, item);
	else if(inVal5(helper) == 'A' || 
		inVal5(helper) == 'a')
		count = addR(list, count, item);
	else if(inVal5(helper) == 'D' ||
		inVal5(helper) == 'd')
		displayR();
	else
		count = removeR();
	cout << "Is there anything else I can help you with?"
		" (Y/N): ";
	cin >> helper;
	if(inVal3(helper) == 'N' || inVal3(helper) == 'n')
		run = false;
}
	return 0;
}

//-----------------------------------------------------------
//		  Non-Class Function Definitions
//-----------------------------------------------------------

//---------------Input Validation Block----------------------

//this function will validate user input.
char inVal(char & UI)
{	//UI is a reference to userInput
//--------Local variable declaration
	char failbit;	//used for input validation

	while( (UI != 'L' && UI != 'l' && 
	        UI != 'N' && UI != 'n') )
	{	//this loop validates character input
		cin.clear();
		cin.get(failbit);
		cout << "\aError: Invalid response!\n";
		cout << "Please enter your answer in L/N "
			"format: ";
		cin >> UI;
	}
	return UI;
}

//this function will validate user input.
char inVal2(char & UI)
{	//UI is a reference to userInput
//--------Local variable declaration
	char failbit;	//used for input validation

	while( (UI != 'A' && UI != 'a' &&
		UI != 'D' && UI != 'd' &&
		UI != 'R' && UI != 'r') )
	{	//this loop validates character input
		cin.clear();
		cin.get(failbit);
		cout << "\aError: Invalid response!\n";
		cout << "Please enter your answer in (A/)D/R "
			"format: ";
		cin >> UI;
	}
	return UI;
}

//in use by main function
//this function will validate user input
char inVal3(char & UI)
{	//UI is a reference to userInput
//--------Local variable declaration
	char failbit;	//used for input validation

	while( (UI != 'y' && UI != 'Y' && 
	        UI != 'n' && UI != 'N') )
	{	//this loop validates character input
		cin.clear();
		cin.get(failbit);
		cout << "\aError: Invalid response!\n";
		cout << "Please enter your answer in Y/N "
			"format: ";
		cin >> UI;
	}
	return UI;
}

//in use by removeR, equateR, and combineR
//this function will validate user input
int inVal4(int & UI)
{	//UI is a reference to userInput
//--------Local variable declaration
	char failbit;	//used for input validation

	while(!UI && UI != 0)
	{	//this loop validates numeric input
		cin.clear();
		cin.get(failbit);
		cout << "\aError: Invalid response!\n";
		cout << "Please enter a number: ";
		cin >> UI;
	}
	return UI;
}

//in use by main function
//this function will validate user input.
char inVal5(char & UI)
{	//UI is a reference to userInput
//--------Local variable declaration
	char failbit;	//used for input validation

	while( (UI != 'E' && UI != 'e' &&
		UI != 'A' && UI != 'a' &&
		UI != 'D' && UI != 'd' &&
		UI != 'R' && UI != 'r' &&
		UI != 'C' && UI != 'c') )
	{	//this loop validates character input
		cin.clear();
		cin.get(failbit);
		cout << "\aError: Invalid response!\n";
		cout << "Please enter your answer in "
			"A/C/E/D/R format: ";
		cin >> UI;
	}
	return UI;
}

//---------------Class function definitions-------------------

//adds elements to the string class member
void String::addR()
{
	cout << "Time to enter your strings!\n"
		"Enter a blank space when "
		"finished!\n";
	string in;
	char failbit;
	cin.clear();
	cin.get(failbit);
	while(getline(std::cin, in) && !in.empty())
	{
		v.push_back(in);
		cin.clear();
	}
}

void String::combineR()

bool String::equateR()


//displays the strings stored
void String::displayR()
{
	int n = 0;
	while(!v.empty())
	{
		cout << ++n << ") ";
		cout << v << endl;
	}
}

//removes elements from the list of strings
void String::removeR()
{
	cout << "Enter the number of the item you would "
		"like to erase\nEnter 0 to quit: ";
	int in;
	char failbit;
	cin.clear();
	cin.get(failbit);
	cin >> in;
	while(inVal4(in) > 0)
	{//input validation so only numeric input accepted
		in--;
		v.erase(v.begin() + in);
		//erases elements from vector v.
		cout << "If you would like to erase another "
			"item, input its number.\n"
			"0 to quit: ";
		cin >> in;
	}
}
