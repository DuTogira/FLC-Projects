//MadLibs.txt – A computerized mad-lib program
//Austin Smothers – March 30, 2016
//CISP 360

#include <iostream>
#include <cstring>
#include <string>
#include <climits>
using namespace std;

int main()
{
	char verbING[100];
	string looper;
	string timeSpan;
	int theTime;
	char failbit;
	string noun1;
	string noun2;
	string noun3;
	string noun4;
	string noun5;
	string noun6;
	string noun7;
	string noun8;
	string verb1;
	string verb2;
	string verb3;
	string verb4;
	string verb5;
	string preposition;
	string occupation;
	string famousPerson;
	string adjective1;
	string adjective2;
	char letter;
	while (looper != "done")
	{
		cout << "Please enter a time span! ";
		getline(cin, timeSpan);
		cout << endl << "Please enter a noun! ";
		getline(cin, noun1);
		cout << endl << "Please enter a verb! ";
		getline(cin, verb1);
		cout << endl << "Please enter another verb! ";
		getline(cin, verb2);
		cout << endl << "Please enter a noun! "
				"(plural or singular) ";
		getline(cin, noun2);
		cout << endl << "Please enter a noun! ";
		getline(cin, noun3);
		cout << endl;
		//BONUS: Checks for words ending in 'ING'
		cout << "Please enter a verb ending "
			"in 'ing'. ";
		cin.getline(verbING, 100);
		cout << endl;
		int ingLength;
		ingLength = strlen(verbING);
		while ( (verbING[ingLength - 3] != 'i') || (verbING[ingLength - 2] != 'n') || (verbING[ingLength - 1] != 'g') )
		{
			cout << "That is not a verb "
				"ending in 'ing'.\n";
			cout << "Please enter a verb ending "
				"in 'ing'. ";
			cin.getline(verbING, 100);
			cout << endl;
			ingLength = strlen(verbING);
		}
		cout << "Please enter a two word occupation! ";
		getline(cin, occupation);
		cout << endl << "Please enter a noun! ";
		getline(cin, noun4);
		cout << endl << "Please enter another noun! ";
		getline(cin, noun5);
		cout << endl << "Please enter the name of "
				"a famous person! ";
		getline(cin, famousPerson);
		cout << endl << "Please enter an adjective! ";
		getline(cin, adjective1);
		cout << endl << "Please enter a verb! ";
		getline(cin, verb3);
		cout << endl << "Please enter a noun! ";
		getline(cin, noun6);
		cout << endl << "Please enter a plural noun! ";
		getline(cin, noun7);
		cout << endl << "Please enter an adjective! ";
		getline(cin, adjective2);
		cout << endl << "Please enter a plural noun! ";
		getline(cin, noun8);
		cout << endl << "Please enter a verb! ";
		getline(cin, verb4);
		cout << endl << "Please enter a preposition! ";
		getline(cin, preposition);
		cout << endl << "Please enter a time "
				"from 1-12! ";
		cin >> theTime;
		if (!isdigit(theTime))
			cin.clear();
		while (!(isdigit(theTime)) && ((theTime < 1) || (theTime > 12)))
		{
			cout << "That is not a valid time!\n "
				"Please enter a time "
				"from 1-12! " << endl;
			theTime = 4;
			cin >> theTime;
			if (!isdigit(theTime))
				cin.clear();
			cin.get(failbit);
			cin.clear();
		}
		cin.clear();
		cout << "Please enter a verb! ";
		getline(cin, verb5);
		cout << endl << "Please enter a letter! ";
		cin >> letter;
		cout << endl;
		cout << "Every " << timeSpan << ", I wake up and get off my " << noun1 << ". I don't always have time to " << verb1 << " a shower, but I always make sure to " << verb2 << " my hair. Once that's done I get some " << noun2 << ", and then it's off to my first " << noun3 << ". I often get caught " << verbING << " in class. No one likes it when the " << occupation << " gives a surprise " << noun4 << ". My second class is " << noun5 << " Theory. Dr. " << famousPerson << " is incredibly " << adjective1 << ", but I never " << verb3 << " her because of her thick " << noun6 << ". Her " << noun7 << ", however, are really " << adjective2 << ". After lunch, I have no more " << noun8 << " and I'm free to " << verb4 << preposition << " my friends. This is right around " << theTime << " O'clock. Before I go to bed I " << verb5 << " a little bit, in my room, " << letter << ".\n";
		cout << "Would you like to play again? "
			"Please type 'done' if not! ";
		cin >> looper;
	}
	return 0;
}

