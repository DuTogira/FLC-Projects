//assign8h.h - Header file for assign8

#ifndef ASSIGN8H_H_
#define ASSIGN8H_H_

//library functions

//Class Declarations

class Shape
{
protected:
	int height = 0;		//stores height; initialized
	int width = 0;		//stores width; initialized
public:
	Shape();		//default constructor
	void inVal(int &UI);	//integer input validation
	virtual int area()	//virtual area; areas of
	{ return 0; }		//member functions differ
};

class Rectangle: public Shape
{
public:
	int area()		//outputs width * height
	{ return (width * height); }	
};

class Triangle: public Shape
{
public:
	int area()		//outputs (width*height)/2
	{ return ((width * height)/2); }
};

#endif
