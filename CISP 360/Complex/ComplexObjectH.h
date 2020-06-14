//ComplexObjectH.h -- Header file for ComplexObject.txt

#ifndef COMPLEXOBJECTH_H_
#define COMPLEXOBJECTH_H_

class Complex
{//adds or subtracts a set of real & imaginary numbers
private:
	//private arrays
double realNum[2] = {0.0,0.0};
double imagiNum[2] = {0.0, 0.0};
	//private variables
double A;			// A & C will be used to
double C;			// control the real aspect of 					// the functions.

double B;			// B & D will be used to
double D;			// control the imaginary 					// aspect of the functions.

double resultAC;		// mathResult will store the
double resultBD;		// result of mathematical
				// operations
	//private functions
void display();

public:
	//public constructors
Complex();			//the default constructor
	//public functions
void mathematics(); 		//performs add/subtract
void getinfo();			//obtains user input
};

#endif
