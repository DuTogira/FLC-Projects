//TODO.txt – Creates a to do list
//Austin Smothers – May 21, 2016
//CISP 360

//Library functions
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>	//reads and writes to files to store
			//data
using namespace std;

//Global variable declarations
bool run = true;	//creates a variable which controls 				//whether or not the program is run
const char *fn = "ToDo.txt";
			//the text file
fstream list;		//declaration of input/output file
int count = 0;		//declaration of counter to be used
std::vector<string> item;
			//declaration of a vector array 
			//to store To-Do tasks

//Function Declarations
int makeR(ostream &td, int count, vector<string> &item);
			//a function to create a new To-Do
			//list
int loadR(ostream &td, int count, vector<string> &item);
			//a function to load an existing
			//To-Do list
int addR(ostream &td, int count, vector<string> &v);
			//a function to add elements to the 
			//To-Do list
void displayR();
			//a function to display the elements
			//of the To-Do list
int writeR(ostream &td, int n, vector<string> v);
			//a function to write the elements
			//of the To-Do list to file
int removeR(ostream &td, int n, vector<string> &v);
			//a function to remove elements from
			//the To-Do list
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
	cout << "Welcome to \"Geet'er Done\", the easiest\n"
		"way to manage your To-Do lists!\n";
	cout << "Would you like to load the existing list\n"
		"or start a new one? (L/N): ";
	char helper;
	cin >> helper;
	if (inVal(helper) == 'N' || inVal(helper) == 'n')
	{
		count = makeR(list, count, item);
	}
	else
	{
		count = loadR(list, count, item);
	}
	cout << "Is there anything else I can help you with?"
		" (Y/N): ";
	cin >> helper;
	if(inVal3(helper) == 'N' || inVal3(helper) == 'n')
		run = false;
while(run == true)
{
	cout << "Would you like to:\n"
		"Start a new list;\n"
		"Add items to the current list;\n"
		"Display the current list;\n"
		"or remove a task from the"
		" current list? (N/A/D/R): ";
	cin >> helper;
	if(inVal5(helper) == 'N' || inVal5(helper) == 'n')
		count = makeR(list, count, item);
	else if(inVal5(helper) == 'A' || 
		inVal5(helper) == 'a')
		count = addR(list, count, item);
	else if(inVal5(helper) == 'D' ||
		inVal5(helper) == 'd')
		displayR();
	else
		count = removeR(list, count, item);
	cout << "Is there anything else I can help you with?"
		" (Y/N): ";
	cin >> helper;
	if(inVal3(helper) == 'N' || inVal3(helper) == 'n')
		run = false;
}
	list.close();
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

//this function will validate user input.
char inVal5(char & UI)
{	//UI is a reference to userInput
//--------Local variable declaration
	char failbit;	//used for input validation

	while( (UI != 'N' && UI != 'n' &&
		UI != 'A' && UI != 'a' &&
		UI != 'D' && UI != 'd' &&
		UI != 'R' && UI != 'r') )
	{	//this loop validates character input
		cin.clear();
		cin.get(failbit);
		cout << "\aError: Invalid response!\n";
		cout << "Please enter your answer in N/A/D/R "
			"format: ";
		cin >> UI;
	}
	return UI;
}

//----------------File related functions---------------------

//creates a new To-Do list file
int makeR(ostream &td, int count, vector<string> &item)
{
	cout << "Creating your list...\n";
	list.open(fn, ios::out | ios::trunc);
	if(!list.is_open())
	{
		cout << "Can't create " << fn << 
			". Bye!\n";
		exit(EXIT_FAILURE);
	}
	else
	{
		cout << fn << 
			" created successfully!\n";
		count = addR(list, count, item);
	}	
	return count;
}

//loads an existing To-Do list file
int loadR(ostream &td, int count, vector<string> &item)
{
	char helper;
	cout << "Opening your list...\n";
	list.open(fn, ios::in | ios:: out | ios::app);
	if(!list.is_open())
	{
		cout << "No file to load!\nBye!";
		exit(EXIT_FAILURE);
	}
	else
	{
		cout << fn << 
			" opened successfully!\n";
		cout << "Would you like to\n"
			"add items to the list,\n"
			"display the list,\n"
			"or remove a task from the"
			" list? (A/D/R): ";
		cin >> helper;
		if(inVal2(helper) == 'A' ||
		   inVal2(helper) == 'a')
			addR(list, count, item);
		else if(inVal2(helper) == 'D' || 
			inVal2(helper) == 'd')
			displayR();
		else
		count = removeR(list, count, item);
	}
	return count;
}

//adds elements to the To-Do list file
int addR(ostream &td, int count, vector<string> &v)
{
	cout << "Time to fill your list!\n"
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
	count = writeR(list, count, v);
	char helper;
	cout << "Would you like to display the list,\n"
		"or remove a task from the list? (D/R): ";
	cin >> helper;
	if(inVal2(helper) == 'D' || inVal2(helper) == 'd')
		displayR();
	else
		count = removeR(list, count, v);
	return count;
}


//displays the To-Do list
void displayR()
{
	ifstream item("ToDo.txt");
	ios_base::fmtflags initial;		//saves
	initial = item.setf(ios_base::fixed);	//formatting
	item.precision(0);
	string line;
	int n = 0;
	if(item.is_open())
	{
	while(getline(item, line))
	{
		cout << ++n << ") ";
		cout << line << endl;	//1/2 BONUS: elements
	}				//displayed on
	item.close();			//separate lines
	}				
	else
		cout << "Failed to open file.\n";
	item.setf(initial);
}

//displays the To-Do list
int writeR(ostream &td, int n, vector<string> v)
{
	ios_base::fmtflags initial;		//saves
	initial = td.setf(ios_base::fixed);	//formatting
	td.precision(0);
	std::vector<string>::const_iterator i;	
	int c = 0;
	for ((i = v.begin() + n); i != v.end(); i++)
	{
		td << (*i) << endl;	//1/2 BONUS: elements
		c++;			//stored on
	}				//separate lines
	td.setf(initial);		
	return c;			//BONUS:
//returning c sets addR's int cout to be equal to the number of lines written to ToDo.txt. addR then returns cout setting main's cout to be equal to the number of lines written to ToDo.txt. Since main's cout is passed to addR and then to writeR, this allows n to be a place-holder for the number of lines written to ToDo.txt, allowing the statement v.begin()+n to prevent text from being written to ToDo.txt a second time when new lines are appended.
//summatively, n makes sure that only new information is written to ToDo.txt
}

//removes elements from the To-Do list file
int removeR(ostream &td, int n, vector<string> &v)
{
	fstream file;
	file.open("ToDo.txt", ios::in);
	string fContents;	//stores files contents
	if(file.is_open())
	{
		v.clear();	//clears vector v so no
				//duplicate content occurs
		while(getline(file, fContents))
		//reads ToDo.txt into string fContents
			v.push_back(fContents);
		//reads fContents into vector v
	}
	file.close();
	cout << "Enter the number of the item you would "
		"like to erase\nEnter 0 to quit: ";
	int in;
	std::vector<string>::const_iterator i;
	char failbit;
	cin.clear();
	cin.get(failbit);
	cin >> in;
	int c = 0;	//c (# of list elements) reset to 0
	while(inVal4(in) > 0)
	{//input validation so only numeric input accepted
		in--;
		v.erase(v.begin() + in);
		//erases elements from vector v.
		//this is easier than erasing lines from
		//ToDo.txt
		cout << "If you would like to erase another "
			"item, input its number.\n"
			"0 to quit: ";
		cin >> in;
	}
	file.open("ToDo.txt", ios::out | ios::trunc);
	//re-opens ToDo.txt, but clears it to prevent
	//duplicate list elements
	for ((i = v.begin()); i != v.end(); i++)
	{//reads the modified vector v back into ToDo.txt
		file << (*i) << endl;	//1/2 BONUS:
					//elements
		c++;			//stored on
	}				//separate
					//lines
	file.close();
	return c;
}
