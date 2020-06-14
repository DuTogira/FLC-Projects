//TenQs.txt - provides the user with 10 questions in random order, and checks if their answers are correct
//Austin Smothers - September 21, 2016
//CISP 400

//Library Functions
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

//Global variable declaration
int ranNum[10] = {};	//an array to store the numbers 1-10
			//in a random order
char userAns[10] = {};	//an array to store the user's answers to the questions
int count = 0;		//will be used as a counter
int numRight = 10;	//tracks the number of incorrect answers the user gets; it goes down

//file related declarations
fstream phi;		//declaration of i/o file
const char *fn = "QandA.txt";
			//the text file
std::vector<string> qas;//creates a vector array to store
			//the questions and answers in the
			//file
//Note: This program assumes questions along with their multiple choice text resides on text file lines 1-30, while the correct answers reside on lines 31-40

//function declarations
void openR(fstream &td, vector<string> &v);
void questionR(vector<string> &v, int i, int ran[]);
void reviewR(vector<string> &v, int i, int ran[], char user[], int &right);

//-----------------------------------------------------------
//			 The Main Function
//-----------------------------------------------------------
main()
{
	int i = 0;		//a counter variable
	srand(time(0));
	while(count < 10)
	{
		ranNum[count] = rand() % 10 + 1;
		while(i < 10)
		{
			if (ranNum[count] != ranNum[i] ||
			     i == count)
				i++;
			else
			{
				i = 0;
				ranNum[count] = rand() % 10 + 1;
			}
		}
		i = 0;
		count++;
	}
	count = 0;
	openR(phi, qas);
	char failbit;		//used for input validation, it gets filled with bad input so that 
	while(i < 10)		//userAns doesn't
	{
		i++;		//side-note: This line caused me a ton of trouble debugging
		cout << i << ") ";
		questionR(qas, i, ranNum);
		cin >> userAns[i];
		while( (userAns[i] != 'A' && userAns[i] != 'B' &&
			userAns[i] != 'C' && userAns[i] != 'D') )
		{	//this loop validates character input
			cin.clear();
			cin.get(failbit);
			cout << "\aError: Invalid resposne!\n";
			cout << "This program is case sensitive.\n"
				"Please enter your answer in "
				"A/B/C/D format: ";
			cin >> userAns[i];
		}
	}
	i = 0;
	reviewR(qas, i, ranNum, userAns, numRight);
	phi.close();
	return 0;
}

//-----------------------------------------------------------
//		  Non-Class Function Definitions
//-----------------------------------------------------------

//---------------Input Validation Block----------------------

//because this program stores user input in one array, there is no need for input validation functions

//----------------File related functions---------------------

//this function opens the file and reads its contents into a vector to make them more easy to manipulate
void openR(fstream &td, vector<string> &v)
{
	fstream file;		//the q and a text file
	file.open("QandA.txt", ios::in);
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
	else
	{
		cout << "No file to load!\nBye!";
		exit(EXIT_FAILURE);
	}
	file.close();
}

//-----------Non-Input Non-File functions--------------------

//a function which will provide the user with the 10 questions
void questionR(vector <string> &v, int i, int ran[])
{
	int n = 0;		//a counter variable
	while(n < 3)		//this loop works with my text file. In the file, 1 question occupies
	{			//3 lines. this loops does that conversion and prints accordingly.
		cout << v[ran[i-1] * 3 - 3 + n] << endl;
		n++;
	}
	n = 0;
}

//a function which will check how many answers the user got right
void reviewR(vector<string> &v, int i, int ran[], char user[], int &right)
{
	for(i = 0; i < 10; i++)
	{
		if(user[i + 1] != v[ran[i] + 29][0])
		{		//user[i + 1] not working as user[i] was what i++ was messing up, earlier
			cout << "You got #" << i + 1 << " wrong.\n";
			right--;//#right starts at 10, and goes down by 1 for each question you get wrong
		}
	}
	cout<< "Your score is: " << right * 10 << "%!\n";
	if(right > 7)
		cout << "Good Job!\n";
	else if(right > 3)
		cout << "Not Bad!\n";
	else
		cout << "Better luck next time!\n";
}
