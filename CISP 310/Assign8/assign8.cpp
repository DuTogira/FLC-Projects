//Assignent8.txt - Uses polymorphism as inheritance
//Austin Smothers - 23 November, 2016
//CISP 400

//I did not have a submission for assignemnt 6. This code is therefore unique.
//There is an attached header file (assign8h.h) attached which will need to be downloaded and run with this program.

//----------------------------------------------------------
//		   Header File Inclusion
//----------------------------------------------------------

using namespace std;
#include <iostream>
#include "assign8h.h"

//----------------------------------------------------------
//		 Global Variable Declaration
//----------------------------------------------------------

//none necessary for this program

//----------------------------------------------------------
//		 Global Function Declaration
//----------------------------------------------------------

void intro();		//function to say hello
void outro();		//function to say goodbye

//----------------------------------------------------------
//		    The Main Function
//----------------------------------------------------------
int main()
{
	intro();
	cout << "Creating a rectangle!\n";
	Rectangle rect;
	cout << "Creating a triangle!\n";
	Triangle tri;
	Shape * sshape1 = &rect;
	Shape * sshape2 = &tri;
	cout << "Area of the rectangle: "
	     << sshape1->area() << endl	//proof pointer works
	     << "Area of the triangle: "
	     << tri.area() << endl;	//proof reference work
	outro();
return 0;
}

//----------------------------------------------------------
//	      Class Function Definition Block
//----------------------------------------------------------

//-------------------Constructor Block----------------------

Shape::Shape()
{
	cout << "Please enter height: ";
	cin >> height;
	inVal(height);
	cout << "Please enter the width: ";
	cin >> width;
	inVal(width);
}

//--------------------Function Block------------------------

void Shape::inVal(int &UI)
{//validates integer input
	char failbit;		//stores bad input
	while(!UI)
	{
		cin.clear();	//clears non-bad input
		cin.get(failbit);//clears failbits
		cout << "Bad Input:\n"
			"Please enter the width: ";
		cin >> UI;
	}
		
}

//----------------------------------------------------------
//	   	  Function Definition Block
//----------------------------------------------------------



//-----------------Input Validation Block-------------------



//-------------------Salutations Block----------------------

void intro()
{//says hello
	cout << "Welcome to... well just\nanother area "
		"calculator.\nThis program will calculate\n"
		"the area of a triangle and a rectangle.\n";
}

void outro()
{//says goodbye
	cout << "Goodbye!\n";
}

