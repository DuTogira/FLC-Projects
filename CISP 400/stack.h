//Listing107.txt - class definition for the stack ADT
//Austin Smothers – May 5, 2016
//CISP 360

#ifndef STACK_H_
#define STACK_H_

typedef unsigned long Item;

class Stack
{
private:
	enum {MAX = 10};	//constant specific to class
	Item items[MAX];	//holds stack items
	int top;		//index for top stack items
public:
	Stack();
	bool isempty() const;
	bool isfull() const;
	// push() returns false if stack is already full,
	// true otherwise
	bool push(const Item & item);	//add item to stack
	// pop() returns false if stack already empty,
	// true otherwise
	bool pop(Item & item);		//pop top into item
};

#endif
