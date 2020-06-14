//Assignment5.txt - Overloads various operators
//Austin Smothers - November 2, 2016
//CISP 400

//-----------------------------------------------------------
//		  Non-Class Declaration Block
//-----------------------------------------------------------

//library function declarations
#include <iostream>
using namespace std;

//function declarations
int inVal4(int &UI);
double inVal5(double &UI);
void intro();
void instructions();
void outro();

//-----------------------------------------------------------
//		    Class Declaration Block
//-----------------------------------------------------------

class Square {
	
private:
	double side;
     
public:
	bool boolOp;

//returns the value of the area of a square
	double getArea() {
	return side * side;
	}

//returns the value of the sides of a square	
	double getSide() {
	return side;
	}

//sets the value of the sides of a square
	void setSide( double s ) {
	side = s;
	}

//-------------------Operator overloading--------------------
     
      //Overload + operator to add two Square objects.
      Square operator+(const Square& b) {
          Square square;
          square.side = side + b.side;
          return square;
      }
      
      //Overload - operator to subtract two Square objects.
      Square operator-(const Square& b) {
          Square square;
          square.side = side - b.side;
          return square;
      }
		
      // Overload * operator to multiply two Square objects.
      Square operator*(const Square& b) {
         Square square;
         square.side = side * b.side;
         return square;
      }
      
      //Overload / operator to divide two Square objects
      Square operator/(const Square& b) {
          Square square;
          square.side = side / b.side;
          return square;
      }
      
      //Overload > operator
      bool operator>(const Square& b) {
          Square square;
          if( side > b.side) {
              square.boolOp = true;
          }
          else {
              square.boolOp = false;
          }
          return square.boolOp;
      }
      
      
      //Overload prefix operator
      Square operator--() {
	  side--;
          return *this;
      }
      
      //Overload postfix-- operator
      Square operator--(int x) {
          side -= x;
          return *this;
      }

      //Overload - operator to negate.
      Square operator-() {
	  side = -side;
          return *this;
      }
      
      //Overload ! operator
      bool operator!() {
	  Square square;
          if (!square.side) {
              square.boolOp = true;
          }
          else {
              square.boolOp = false;
          }
          return square.boolOp;
      }
      
    };

//-----------------------------------------------------------
//		    The Main Function
//-----------------------------------------------------------

int main() 
{
//class object declarations
	Square Square1;
	Square Square2;
	Square Square3;

//variable declarations
	double side = 0.0;
	double area = 0.0;
	double x = 0.0;
	int option = 0;

	intro();

//while loop to accept user input and display switch options
	while (option != 10)
	{
	x = 0;
	cout << "Please input the side length of the\n"
		"first square: ";
	cin >> x;
	inVal5(x);
	Square1.setSide(x);
	cout << "Please input the side length of the\n"
		"second square: ";
	cin >> x;
	inVal5(x);
	Square2.setSide(x);
//switch statement allowing the user to choose which overloaded operator to use
	instructions();
	cin >> option;
	inVal4(option);
	switch (option)
	{
		case 1: Square3 = Square1 + Square2;
	//Square1 side length
	area = Square1.getSide();
	cout << "Side length of Square1: " << area << endl;

	//Square2 side length
	area = Square2.getSide();
	cout << "Side length of Square2: " << area << endl;

	//Square 3 side length
	area = Square3.getSide();
	cout << "Side length of Square3: " << area << endl;

	// Square1 area
	area = Square1.getArea();
	cout << "Area of Square1: " << area <<endl;

	// Square2 area
	area = Square2.getArea();
	cout << "Area of Square2: " << area <<endl;

	// Area of Square3
	area = Square3.getArea();
	cout << "Area of Square3: " << area <<endl;
			break;
		case 2: Square3 = Square1 - Square2;
	//Square1 side length
	area = Square1.getSide();
	cout << "Side length of Square1: " << area << endl;

	//Square2 side length
	area = Square2.getSide();
	cout << "Side length of Square2: " << area << endl;

	//Square 3 side length
	area = Square3.getSide();
	cout << "Side length of Square3: " << area << endl;

	// Square1 area
	area = Square1.getArea();
	cout << "Area of Square1: " << area <<endl;

	// Square2 area
	area = Square2.getArea();
	cout << "Area of Square2: " << area <<endl;

	// Area of Square3
	area = Square3.getArea();
	cout << "Area of Square3: " << area <<endl;
			break;
		case 3: Square3 = Square1 * Square2;
	//Square1 side length
	area = Square1.getSide();
	cout << "Side length of Square1: " << area << endl;

	//Square2 side length
	area = Square2.getSide();
	cout << "Side length of Square2: " << area << endl;

	//Square 3 side length
	area = Square3.getSide();
	cout << "Side length of Square3: " << area << endl;

	// Square1 area
	area = Square1.getArea();
	cout << "Area of Square1: " << area <<endl;

	// Square2 area
	area = Square2.getArea();
	cout << "Area of Square2: " << area <<endl;

	// Area of Square3
	area = Square3.getArea();
	cout << "Area of Square3: " << area <<endl;
			break;
		case 4: Square3 = Square1 / Square2;
	//Square1 side length
	area = Square1.getSide();
	cout << "Side length of Square1: " << area << endl;

	//Square2 side length
	area = Square2.getSide();
	cout << "Side length of Square2: " << area << endl;

	//Square 3 side length
	area = Square3.getSide();
	cout << "Side length of Square3: " << area << endl;

	// Square1 area
	area = Square1.getArea();
	cout << "Area of Square1: " << area <<endl;

	// Square2 area
	area = Square2.getArea();
	cout << "Area of Square2: " << area <<endl;

	// Area of Square3
	area = Square3.getArea();
	cout << "Area of Square3: " << area <<endl;
			break;
		case 5: if (Square1 > Square2) {
				cout << "Square1 is "
					"greater!\n";
			}
			else
				cout << "Square2 is "
					"greater!\n";
	//Square1 side length
	area = Square1.getSide();
	cout << "Side length of Square1: " << area << endl;

	//Square2 side length
	area = Square2.getSide();
	cout << "Side length of Square2: " << area << endl;

	// Square1 area
	area = Square1.getArea();
	cout << "Area of Square1: " << area <<endl;

	// Square2 area
	area = Square2.getArea();
	cout << "Area of Square2: " << area <<endl;
			break;
		case 6: --Square1;
	//Square1 side length
	area = Square1.getSide();
	cout << "Side length of Square1: " << area << endl;

	// Square1 area
	area = Square1.getArea();
	cout << "Area of Square1: " << area <<endl;
			break;
		case 7: Square1.operator--(3);
	//Square1 side length
	area = Square1.getSide();
	cout << "Side length of Square1: " << area << endl;

	// Square1 area
	area = Square1.getArea();
	cout << "Area of Square1: " << area <<endl;
			break;
		case 8: -Square1;
	//Square1 side length
	area = Square1.getSide();
	cout << "Side length of Square1: " << area << endl;

	// Square1 area
	area = Square1.getArea();
	cout << "Area of Square1: " << area <<endl;
			break;
		case 9: if(!Square1) {
				cout << "Square1 wasn't "
					"declared!\n";}
			else {
				cout << "Square1 was "
					"declared!\n";}
	//Square1 side length
	area = Square1.getSide();
	cout << "Side length of Square1: " << area << endl;

	// Square1 area
	area = Square1.getArea();
	cout << "Area of Square1: " << area <<endl;
			break;
		case 10: break;
		default: cout << "That wasn't an option.\n";
	}
	};
	
	outro();
	
	return 0;
}

//-----------------------------------------------------------
//		   Function Definition Block
//-----------------------------------------------------------

//-----------------Input Validation Block--------------------

//this function will validate integer input
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

//this function will validate double input
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

//-------------------Text Function Block---------------------

//says hello
void intro()
{
	cout << "Welcome to 'OverAll!'\nA program which "
		"overloads a lot of functions!\n";
}

//displays the options of the switch statement
void instructions()
{
	cout << "1) Add the two numbers\n"
		"2) Subtract the two numbers\n"
		"3) Multiply the two numbers\n"
		"4) Divide the two numbers\n"
		"5) See if the first number is > the second\n"
		"6) Decrement the first number by 1\n"
		"7) Decrement the first number by 3\n"
		"8) Change the sign of the first number+/-\n"
		"9) See if the first number exists\n"
		"10) Exit the program\n";
}

//says goodbye
void outro()
{
	cout << "Thanks for using 'OverAll!'\nGoodbye!\n";
}
