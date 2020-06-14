//inventory.txt - holds information for a retail item
//Austin Smothers - September 28, 2016
//CISP 400

//NOTE: Professor, you will need to compile this code with inventoryH.h downloaded, which I have included in the dropbox folder as a .txt named inventoryH.txt.

//Library functions
#include <iostream>
#include <iomanip>	//included for std::setprecision()
#include "inventoryH.h"	//header file containing class code

using namespace std;

//Global Variable declarations
int n = 0;		//stores ints for item number
int q = 0;		//stores ints for quantity
double c = 0;		//stores doubles for cost

//Function Declarations
void intro();		//the program's introduction text
void outro();		//program's goodbye text

void getNumbers(int &n, int &q, double &c);
			//obtains the user's input

int inVal4(int & UI);		//validates integer input
double inVal5(double & UI);	//validates double input

//-----------------------------------------------------------
//			 The Main Function
//-----------------------------------------------------------
int main()
{
	intro();		//says hello &
				//provides instructions
	getNumbers(n, q, c);	//obtains user input for
				//ID #, # items, & cost
	Inventory retail(n, q, c);	
				//creates an inventory class
	retail.showData();	//displays collected data
	outro();		//says goodbye
	return 0;
}

//-----------------------------------------------------------
//		   Class Function Definitions
//-----------------------------------------------------------

//-------------------Constructors----------------------------
Inventory::Inventory(void)
{			//initializes class variables
	itemNumber = 0;
	quantity = 0;
	cost = 0;
	totalCost = 0;
}

Inventory::Inventory(int n, int q, double c) : Inventory()
{			//copys values to variables
	setItemNumber(n);
	setQuantity(q);
	setCost(c);
}

//------------------Non-Constructors-------------------------

void Inventory::setItemNumber(int i)
{			//sets the itemNum variable
	itemNumber = i;
}

void Inventory::setQuantity(int i)
{			//sets the quantity variable
	quantity = i;
}

void Inventory::setCost(double i)
{			//sets the cost variable
	cost = i;
}

int Inventory::getItemNumber()
{			//returns itemNumber
	return itemNumber;
}

int Inventory::getQuantity()
{			//returns quantity
	return quantity;
}

double Inventory::getCost()	
{			//returns cost
	return cost;
}

double Inventory::getTotalCost()	
{			//calculates & returns totalCost
	totalCost = getQuantity() * getCost();
	return totalCost;
}

void Inventory::showData()
{			//outputs the gathered data
	cout << "I.D #: " << getItemNumber() << endl;
	cout << "# of items: " << getQuantity() << endl;
	cout << std::setprecision(2) << std::fixed;
			//fixes output to 2 decimal places
	cout << "Total cost: $" << getTotalCost() << endl;
}

//-----------------------------------------------------------
//		  Non-Class Function Definitions
//-----------------------------------------------------------

void intro()
{			//says hello
	cout << "Welcome to 'Inventory Manager', the best\n"
		"way to manage the expenses of your "
		"growing\nretail inventory!\n";
}

void getNumbers(int &n, int &q, double &c)
{			//gathers data from the user and 
			//validates it
	cout << "Enter the I.D number of the retail item.\n"
		"I.D: ";
	cin >> n;
	inVal4(n);
	cout << "Enter the number of items in inventory.\n"
		"#: ";
	cin >> q;
	inVal4(q);
	cout << "Enter the cost of the item per item.\n"
		"Cost/Item: $";
	cin >> c;
	inVal5(c);
	cout << endl << endl;
}

void outro()
{			//says goodbye
	cout << "Thanks for using 'Inventory Manager'!\n"
		"Goodbye!\n";
}

//-----------------------------------------------------------
//	       Input Validation Function Definitions
//-----------------------------------------------------------

//this function will validate user input
int inVal4(int & UI)
{	//UI is a reference to userInput
//--------Local variable declaration
	char failbit;	//used for input validation

	while(!UI || UI <= 0)
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

	while(!UI || UI <= 0)
	{	//this loop validates numeric input
		cin.clear();
		cin.get(failbit);
		cout << "\aError: Invalid response!\n";
		cout << "Please enter a number: ";
		cin >> UI;
	}
	return UI;
}

