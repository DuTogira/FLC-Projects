//sEditorH.h - Class definitions for sEditor

#ifndef SEDITORH_H_
#define SEDITORH_H_

//library functions
#include <cstdlib>
#include <stdio.h>
#include <string>
#include <vector>

class String;		//class declaration
{
private:
	//private variables
std::vector<string> v;
			//declaration of a vector array 
			//to store string elements
	//private functions
public:
	//public variables
	//public functions
	void addR();
			//function that ads strings to the
			//vector array
	void combineR();
			//function that combines elements of
			//the vector array
	bool equateR();
			//function that compares elements
			//of the vector array
	void displayR();
			//displays the vector array
	void removeR();
			//removes elements of vector array
};

#endif
