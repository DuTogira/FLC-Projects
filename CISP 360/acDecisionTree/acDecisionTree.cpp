//acDecisionTree.txt – Performs on the fly technical support
//Austin Smothers – April 23, 2016
//CISP 360

//Library function declarations
#include <iostream>
using namespace std;

//Global variable declarations
char userInput;		//used to store user input

//function declarations
char inVal(char &);		//function to validate
				//user input
//BONUS: The entire decision structure consists of
//	 inline functions
inline void diagnostics(char);	//contains the diagnostics
				//if/else decision tree
inline void airborne();		//--|
inline void electricalWorking();//--|
inline void engineRunning();	//--|
inline void engineStopped();	//--Decision structure
inline void oxygenAvailable();	//--function declaration
inline void overMountains();	//--block
inline void overNotMountains();	//--|
inline void nightFlying();	//--|

//------------------------------------------------------------

//the main function
int main()
{
	cout << "Welcome to the \"On The Fly!\" aircraft\n"
		"engine diagnostics program!\nThis program "
		"will help you identify\nwhat is wrong with "
		"your aircraft!\n";
	cout << "Would you like to run this program? Y/N: ";
	cin >> userInput;
	while( (inVal(userInput) == 'Y') || 
	       (inVal(userInput) == 'y') )
	{	//loops the program
		diagnostics(userInput);
		cout << "Would you like to run "
			"\"On The Fly!\" again? Y/N: ";
		cin >> userInput;
		inVal(userInput);	//checks for bad input
	}
	cout << "Thank you for using the \"On The Fly!\"\n"
		"aircraft diagnostics program!\nGoodbye!\n";
	return 0;
}

//------------------------------------------------------------

//this function contains the entirety of manageable
//problems an aircraft may experience mid-flight
inline void diagnostics(char userInput)
{
	cout << "Please answer the following questions in Y/N"
		" format.\n";
	cout << "Are you airborne? ";
	cin >> userInput;
	if ( (inVal(userInput) == 'Y') || 
	     (inVal(userInput) == 'y') )
		airborne();
	else
		cout << "Have a drink and\n"
			"call a mechanic.\n";
}

//------------------------------------------------------------

//this function will validate user input.
char inVal(char & UI)
{	//UI is a reference to userInput
//--------Local variable declaration
	char failbit;	//used for input validation

	while( (UI != 'Y' && UI != 'y' && 
	       UI != 'N' && UI != 'n') )
	{	//this loop validates user input
		cin.clear();
		cin.get(failbit);
//BONUS: program provides audible feedback with invalid input
		cout << "\aError: Invalid response!\n";
		cout << "Please enter your answer in Y/N "
			"format: ";
		cin >> UI;
	}
	return UI;
}

//------------------------------------------------------------
//THIS MARKS THE BEGINNING OF DIAGNOSTICS DECISION STRUCTURES
//------------------------------------------------------------

inline void airborne()
{
	cout << "Is the electrical system working? ";
	char userInput;
	cin >> userInput;
	if ( (inVal(userInput) == 'Y') || 
	     (inVal(userInput) == 'y') )
		electricalWorking();
	else 
		cout << "Turn on the Master Switch!\n";
}

//----------------DECISION FUNCTION TIER BREAK----------------

inline void electricalWorking()
{
	cout << "Has the engine stopped running? ";
	char userInput;
	cin >> userInput;
	if ( (inVal(userInput) == 'Y') || 
	     (inVal(userInput) == 'y') )
		engineStopped();
	else
		engineRunning();
}

//----------------DECISION FUNCTION TIER BREAK----------------

inline void engineRunning()
{
	cout << "Is the outside air "
		"temperature < 32 degrees? ";
	char userInput;
	cin >> userInput;
	if ( (inVal(userInput) == 'Y') || 
	     (inVal(userInput) == 'y') )
		cout << "Turn on Carborator Heat.\n";
	else
		cout << "Switch to other fuel tank.\n";
}
	

inline void engineStopped()
{
	cout << "Is oxygen still circulating throughout "
		"the cabin? ";
	char userInput;
	cin >> userInput;
	if ( (inVal(userInput) == 'Y') || 
	     (inVal(userInput) == 'y') )
		oxygenAvailable();
	else
	{
		cout << "Put on your oxygen mask"
			" before proceeding.\n";
		oxygenAvailable();
	}	
}

//----------------DECISION FUNCTION TIER BREAK----------------

//BONUS: Extra decision structure
inline void oxygenAvailable()
{
	cout << "Are you over the Mountains? ";
	char userInput;
	cin >> userInput;
	if ( (inVal(userInput) == 'Y') || 
	     (inVal(userInput) == 'y') )
		overMountains();
	else
		overNotMountains();
}

//----------------DECISION FUNCTION TIER BREAK----------------

inline void overMountains()
{
	cout << "Are you flying at night? ";
	char userInput;
	cin >> userInput;
	if ( (inVal(userInput) == 'Y') || 
	     (inVal(userInput) == 'y') )
		nightFlying();
	else
		cout << "Make emergency landing.\n";
}


inline void overNotMountains()
{
	cout << "Are you over water? ";
	char userInput;
	cin >> userInput;
	if ( (inVal(userInput) == 'Y') || 
	     (inVal(userInput) == 'y') )
		cout << "Inflate your life vest\n"
			"Make emergency landing.\n";
	else
		cout << "Make emergency aldning on a road.\n";
}

//----------------DECISION FUNCTION TIER BREAK----------------

inline void nightFlying()
{
	cout << "Turn on the landing light\n"
		"and look out the window.\n"
		"Do you like what you see? ";
	char userInput;
	cin >> userInput;
	if ( (inVal(userInput) == 'Y') || 
	     (inVal(userInput) == 'y') )
		cout << "Make emergency landing.\n";
	else
		cout << "Turn off the landing light.\n";
}

//------------------------------------------------------------
//		 DECISION FUNCTION ENDING MARK
//------------------------------------------------------------
