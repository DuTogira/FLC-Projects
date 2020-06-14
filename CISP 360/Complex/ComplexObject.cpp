//ComplexObject.txt – Adds two complex numbers
//Austin Smothers – October 19, 2016
//CISP 400

//-----------------------------------------------------------
//		     Declaration Block
//-----------------------------------------------------------

//library function declarations
#include <iostream>
#include <string>
#include "ComplexObjectH.h"
using namespace std;

//global variable declaration
string dOver = "yes";		// creates a string variable
				// to allow the user to run
				// the program as many times
				// as they like

char failbit;			//used for user input
				//validation
//end of variable declaration

//beginning of function declaration
void greeting();
//end of function declaration

//-----------------------------------------------------------
//			The Main Function
//-----------------------------------------------------------

int main()
{
	greeting();		//say hi!
	Complex object;		//creates the object class
while (dOver == "yes")
{
	object.getinfo();	//obtains user input
	object.mathematics();	//does the math
	cin >> dOver;		//wanna do it again?
}
return 0;
}

//-----------------------------------------------------------
//		Non-Class Function Definitions
//-----------------------------------------------------------

//this function will greet the user
void greeting()
{
	cout << "Hello!\nThis program will add two complex "
		"numbers.\n";
}

//-----------------------------------------------------------
//		     Class Constructors
//-----------------------------------------------------------

Complex::Complex()
{	//the purpose of this constructor is to initialize
	//all variables
	A = realNum[0];		// A & C will be used to
	C = realNum[1];		// control the real aspect of 					// the functions.
	B = imagiNum[0];	// B & D will be used to
	D = imagiNum[1];	// control the imaginary 					// aspect of the functions.
	resultAC = 0.0;		// mathResult will store the
	resultBD = 0.0;		// result of mathematical
				// operations
};

//-----------------------------------------------------------
//		  Class Function Definitions
//-----------------------------------------------------------

//function definition for getinfo()
void Complex::getinfo()
{
	string realNumAC = "Please enter a real "
			   "number in decimal form: ";
	string imagiNumBD = "Please enter an "
			    "imaginary modifier in decimal"
			    " form: ";
	int p;	//creates a variable p to control for loop
	for (p = 0; p < 2; p++)
	{	//the program uses a for loop to store user
		//input in a parallel array
		cout << realNumAC;
		while(!(cin >> realNum[p]))
		{
			cin.clear();
			cin.get(failbit);
			cout << "Bad input:\n" << realNumAC;
		}
		cout << imagiNumBD;
		while(!(cin >> imagiNum[p]))
		{
			cin.clear();
			cin.get(failbit);
			cout << "Bad input:\n" << imagiNumBD;
		}
	}	//end of for loop
	A = realNum[0];
	C = realNum[1];
	B = imagiNum[0];
	D = imagiNum[1];
	cout << "a = (" << A << ", " << B << "i)" << endl
	     << "c = (" << C << ", " << D << "i)" << endl;
}

//function definition for mathematics()
void Complex::mathematics()
{
	string userInput;	//creates a string variable
				//for user input
	char failbit;
	int ctrl = 0;		//controls while loop
	cout << "Would you like to add or subtract "
		"these numbers?: ";
	//The following if/else statements allow the 
	//user to choose whether to add or subtract the 
	//numbers AND checks for bad input
	while (ctrl != 1)
	{
		cin >> userInput;
		if(userInput == "add")	
		{	//adds a + c
			resultAC = A + C;
			resultBD = B + D;
			ctrl = 1;
		}
		else if (userInput == "subtract")
		{	//subtracts a - c
			resultAC = A - C;
			resultBD = B - D;
			ctrl = 1;
		}
		else
		{	//defaults to restart the while loop
			cin.clear();
			cin.get(failbit);
			cout << "I'm sorry, that wasn't an "
				"option.\nWould you like "
				"to add or subtract "
				"these numbers?: ";
		}//end of if/else statements
	}//end of while loop
	display();
}

//Displays the calculated numbers
void Complex::display()
{
	cout << "(" << resultAC << ", " << resultBD << "i)\n";
	cout << "Done! Would you like to add/subtract\n"
		"another set of complex numbers?\n"
		"If so, enter 'yes'!\n"
		"Note: This program is case sensitive.\n";
}

