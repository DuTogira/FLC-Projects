//InVal.txt – validates user input
//Austin Smothers – April 16, 2016
//CISP 360

//------------------------------------------------------------

//library function declarations
#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;
//end of library function declarations

//beginning of array declaration
char firstName[100];
char lastName[100];
char empID[7] = {0, 0, 0, 0, 0, 0, 0};
char zipCode[5] = {0, 0, 0, 0, 0};
//end of array declaration

//beginning of pointer declaration
char * first = firstName;
char * last = lastName;
char * ID = empID;
char * zip = zipCode;
//end of pointer declaration

//beginning of function declaration
void validateInput(char *, char *, char *, char *);
int charValidation(char *, int & alphE);
int numValidation(char *, int & numE);
int idValidation(char *, int & alphR, int & numR, int & othE);
//end of function declaration

//-----------------------------------------------------------

//beginning of main module
int main()
{
	char failbit;
	cout << "Hello! This function will ask you for "
		"various input,\n"
		"and inform you if your input is invalid\n"
		"at the end of the program!\n";
	//BONUS: Allows the user to control whether program
	//runs or not.
	cout << "Would you like to run this program? Y/N?\n"
		"Note: Program is case sensitive.\n";
	while(cin.get() == 'Y')
	{
		validateInput(first, last, ID, zip);
		cin.get(failbit);
		cin.clear();
	}
	return 0;
}
//end of main module

//------------------------------------------------------------

//function definition for validateInput()
void validateInput(char * first, char * last, char * ID, char * zip)
{
	//beginning of local variable declaration	
	int alphaErrors1 = 0;
	int numErrors1 = 0;
	int alphaErrors2 = 0;
	int numErrors2 = 0;
	int alphaErrors3 = 0;
	int otherErrors = 0;
	//end of local variable declaration
//First name input
	cout << "Please enter your first name!\n";
	cin >> first;
	while(strlen(first) <= 2)
	{//Used to ensure first name > 2 characters
		cout << "Your name must be longer than 2 " 				"characters.\nPlease enter your "
			"first name!\n";
		cin >> first;
	}
//Last name input
	cout << "Please enter your last name!\n";
	cin >> last;
	while(strlen(last) <= 2)
	{//Used to ensure last name > 2 characters
		cout << "Your last name must be longer than 2"
			" characters.\nPlease enter your "
			"last name!\n";
		cin >> last;
	}
//ID input
	cout << "Please enter your employee ID!\n"
		"Expected input format: AA-1234\n"
		"Note: Expected hyphen input\n";
	cin >> ID;
//ZIP code input
	cout << "Please enter your ZIP code!\n";
	cin >> zip;
//validation/output block
	cout << "Number of errors in first name: " 
	     << charValidation(first, alphaErrors1) << endl 
	     << "Number of errors in last name: "
	     << charValidation(last, alphaErrors2) << endl
	     << "Number of errors in ID: "
	     << idValidation(ID, alphaErrors3, numErrors1, 				     otherErrors) << endl
	     << "Number of errors in ZIP code: "
	     << numValidation(zip, numErrors2) << endl
	     << "Number of alphanumeric errors: "//BONUS: This
	     << alphaErrors1 + alphaErrors2 + alphaErrors3
	     << endl				//tracks # &
	     << "Number of numeric errors: "	//type of
	     << numErrors1 + numErrors2 << endl	//errors made
	     << "Number of other errros: "	//throughout
	     << otherErrors << endl		//the program
	     << "Run finished!\nWould you like to run this "
		"program again? Y/N?\n";
//end of validation/output block
}
//end of validateInput

//------------------------------------------------------------

//function definition for charValidation()
int charValidation(char * userIN, int & alphE)
{
	int CE = 0;	//used to count errors
	for(int p = 0; p < strlen(userIN); p++)
	{
		if(!(isalpha(userIN[p])))
		{
			CE = CE + 1;
			alphE = CE;
			//increments the variable used to
			//track alphabetic input errors
		}
	}
	return CE;
}
//end of charValidation()

//-----------------------------------------------------------

//beggining of numValidation()
int numValidation(char * userIN, int &numE)
{
	int NE = 0;	//used to count errors
	for(int p = 0; p < strlen(userIN); p++)
	{
		if(!(isdigit(userIN[p])))
		{
			NE = NE + 1;
			numE = NE;
			//increments the variable used to
			//track numeric input errors
		}
	}
	return NE;
}
//end of numValidation()

//-----------------------------------------------------------

//beginning of otherValidation()
int idValidation(char * userIN, int &alphR, int &numR,    			 int &othE)
{
	int IDE = 0;	//used to count errors
	for(int p = 0; p < 2; p++)
	{
		if(!(isalpha(userIN[p])))
		{
			IDE = IDE + 1;
			alphR = IDE;
			//increments the variable used to
			//track alphabetic input errors
		}
	}
	if(userIN[2] != '-')
	{
		IDE = IDE + 1;
		othE = 1;
		//increments the variable used to
		//track other input errors
	}
	for(int p = 3; p < 7; p++)
	{
		if(!(isdigit(userIN[p])))
		{
			IDE = IDE + 1;
			int x = 0;
			x = x + 1;
			numR = x + 1;
			//increments the variable used to
			//track numeric input errors
		}
	}
	return IDE;
}
//end of otherValidation()

