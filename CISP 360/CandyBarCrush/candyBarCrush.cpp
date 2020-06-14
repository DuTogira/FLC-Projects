//candyBarCrush.txt – Stores data about candy bars in a
//		      dynamically allocated array structure
//Austin Smothers – February 27, 2016
//CISP 360

#include <iostream>
#include <string>
struct CandyBar
{
	std::string name;
	float weight;
	int calories;
};

int main() 
{
	using namespace std;
	CandyBar snack =
	{
		"Mocha Munch",
		2.3,
		350
	};
	cout << snack.name << endl;
	cout << snack.weight << " grams.\n";
	cout << snack.calories << " calories.\n";
	//Bonus: Dynamically allocated structure array!
	CandyBar *candy = new CandyBar[3];
		//Snickers
	candy[0].name = "Snickers";
	candy[0].weight = 52.7;
	candy[0].calories = 250;
		//Three Musketeers
	candy[1].name = "Three Musketeers";
	candy[1].weight = 54.4;
	candy[1].calories = 240;
		//Kit-Kat
	candy[2].name = "Kit-Kat";
	candy[2].weight = 21;
	candy[2].calories = 210;
	//Bonus: For loop display function!
	int looper = 0;
	for (looper = 0; looper < 3; looper++)
	{
		cout << endl;
		cout << candy[looper].name << endl;
		cout << candy[looper].weight
		     << " grams.\n";
		cout << candy[looper].calories 
		     << " calories.\n";
	}
	delete [] candy;
	return 0;
}


