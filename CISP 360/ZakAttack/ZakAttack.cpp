//ZakAttack.txt – Allows the user to input a student's name 
//		  and 9 quiz scores, the three lowest of which
//		  are dropped.
//Austin Smothers – April 1, 2016
//CISP 360

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//beginning of variable declaration

int c = 0;			//creates two variables c&a
int a = 0;			//which will be used for
				//arrays later on

char studentName[100];		//used for user-input data
int studentScores[8];


char letterGrade[30] = "ABCDF";	//holds the letter grades
char advice[5][300] = 		//creates a 2-D array
{				//to store advice strings
	": Great Job! You got an A!\n",
	": Get that extra hour of sleep and "
	 "have a hearty breakfast next time!\n",
	": Studying over the course of a week "
	 "prior to the test might help!\n",
	": You need to put more effort into "
	 "this class. You can do better than a D!\n",
	": Wake up! There is no excuse for "
	 "an F!\n"
};

//end of variable declaration
			

int main()
{
	cout << "Hello!\n This program allows you to input "
		"a student's name\n and test scores. The "
		"highest 6 scores, the letter\n grade of "
		"each score, and provides sagely advice "
		"based\n on the grade received!\n";
	cout << "Please enter the first and last name "
		"of the student.\n";
	cin.getline(studentName, 100);
	for (c = 0; c < 9; c++)		//for loop used to
	{				//input test scores
		cout << "Please enter test score #: ";
		cout << c + 1 << endl;

//creates a variable to catch failbits (necessary later)
		char failbit;

		cin >> studentScores[c];

//BONUS: Program checks for valid integer-type input in
//addition to range testing the scores!
		if (!isdigit(studentScores[c]))
			cin.clear();
//The purpose of this while loop is to catch non-numeric input and clear it from the input cache, while range testing!
		while (!isdigit(studentScores[c]) 			&& ((studentScores[c] <= 0) || 			(studentScores[c] > 100)))
		{
			cin.get(failbit);
			cin.clear();
			cout << 
			"That is not a valid score!\n "
			"re-enter test score #: ";
			cout << c + 1 << endl;
			cin >> studentScores[c];
			if (!(isdigit(studentScores[c])))
				cin.clear();
			cin.clear();
		}
	}

//BONUS: Beginning of sort algorithm to output scores in order from least to greatest.
	int i, j, tmp;
	for (i = 1; i < 9; i++)
	{
		j = i;
		while (j > 0 && studentScores[j-1] > 
			studentScores[j])
		{
			tmp = studentScores[j];
			studentScores[j] = studentScores[j-1];
			studentScores[j-1] = tmp;
			j--;	
		}	
	}
//End of Bonus

	c = 0;			//resets c to be used again

//Note: The following for loop omits the lowest three scores
//utilizing the fact that the scores have been sorted
	for (c = 3; c < 9; c++)	//creates a for loop for
	{			//outputting scores
		cout << "Score #: " << c + 1 << " = ";
		cout << studentScores[c];
	

//the following if-else block determines what letter grade
//the student received. This is the grading table!
		if (studentScores[c] >= 90)
			a = 0;
		else if (studentScores[c] < 90
			&& studentScores[c] >=80)
			a = 1;
		else if (studentScores[c] < 80
			&& studentScores[c] >=70)
			a = 2;
		else if (studentScores[c] < 70
			&& studentScores[c] >=60)
			a = 3;
		else
			a = 4;
		cout << " percent!\n This counts as a(n) ";

//Note: The letterGrade and advice arrays are controlled by
//the same variable, a
		cout << letterGrade[a];	//outputs the letter
		cout << advice[a];	//outputs the advice
	}
	return 0;
}


