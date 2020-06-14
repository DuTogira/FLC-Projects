//Complex.txt – Adds two complex numbers
//Austin Smothers – April 9, 2016
//CISP 360

//------------------------------------------------------------

//library function declarations
#include <iostream>
#include <string>
using namespace std;

//beginning of array declaration
double realNum[2] = {0.0, 0.0};
double imagiNum[2] = {0.0, 0.0};
//end of array declaration

//beginning of variable declaration
double & A = realNum[0];	// A & C will be used to
double & C = realNum[1];	// control the real aspect of 					// the functions.

double & B = imagiNum[0];	// B & D will be used to
double & D = imagiNum[1];	// control the imaginary 					// aspect of the functions.

double resultAC = 0.0;		// mathResult will store the
double resultBD = 0.0;		// result of mathematical
				// operations

string dOver = "yes";		// creates a string variable
				// to allow the user to run
				// the program as many times
				// as they like

char failbit;			//used for user input
				//validation
//end of variable declaration

//beginning of function declaration
void greeting();
void mathematics(double, double, double, double,
			double, double);
void display(double, double);
//end of function declaration

//-----------------------------------------------------------

//beginning of main module
int main()
{
while (dOver == "yes")
{	//BONUS:
	//allows the user to run the program until they decide
	//otherwise
	greeting();
	string realNumAC = "Please enter a real "
			   "number in decimal form: ";
	string imagiNumBD = "Please enter an "
			    "imaginary modifier in decimal"
			    " form: ";
	int p;	//creates a variable p to control for loop
	for (p = 0; p < 2; p++)
	{	//the program uses a for loop to store user
		//input in a parallel array
	//BONUS:
		//This program will use a series of while 
		//loops to obtain user input and test it
		//for validity
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
	//end of BONUS
	A = realNum[0];
	C = realNum[1];
	B = imagiNum[0];
	D = imagiNum[1];
	cout << "a = (" << A << ", " << B << "i)" << endl
	     << "c = (" << C << ", " << D << "i)" << endl;
	mathematics(A, C, B, D, resultAC, resultBD);
	cin >> dOver;
}
//end of BONUS
return 0;
}
//end of main module

//------------------------------------------------------------

//function definition for greeting()
void greeting()
{
	cout << "Hello!\nThis program will add two complex "
		"numbers.\n";
}
//end of greeting()

//------------------------------------------------------------

//function definition for mathematics()
void mathematics(double A, double C, double B, 
			double D, double resultAC, 
			double resultBD)
{
	string userInput;	//creates a string variable
				//for user input
	char failbit;
	int ctrl = 0;		//controls while loop
	cout << "Would you like to add or subtract "
		"these numbers?: ";
	//BONUS: The following if/else statements allow the 
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
	//end of BONUS
	display(resultAC, resultBD);
}
//end of mathematics()

//-----------------------------------------------------------

//beggining of display()
void display(double a, double c)
{
	cout << "(" << a << ", " << c << "i)\n";
	cout << "Done! Would you like to add/subtract\n"
		"another set of complex numbers?\n"
		"If so, enter 'yes'!\n"
		"Note: This program is case sensitive.\n";
}
//end of display()

