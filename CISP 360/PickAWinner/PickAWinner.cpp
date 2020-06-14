//PickAWinner.txt – Picks a winner from one of up to twenty 
		  //Entrees
//Austin Smothers – March 30, 2016
//CISP 360

#include <stdlib.h>
#include <iostream>
#include <locale>
#include <vector>

using namespace std;

int arSize;
char loopControl[100];
vector<string> contestants(20); //BONUS: Vector memory type!
int winningNumber;
int count;

int main()
{
	arSize = 0;
	count = 0;
	while (count < 20 && loopControl != '\0')
	{
		cout << "Please enter the contestant's "
			"name!: ";
		cin.getline(loopControl, 100);
		if (loopControl[0] != '\0' && !(isblank(loopControl[0])))
		{
			contestants[arSize] = loopControl;
			arSize = arSize + 1;
		}
		count = count + 1;
	}
	winningNumber = rand() % arSize;
	cout << "Contestant " << contestants[winningNumber] 		     << " has won! Congratulations!\n";
	return 0;
}

