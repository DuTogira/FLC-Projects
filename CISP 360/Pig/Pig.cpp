//Pig.txt – A Simple Gambling Game
//Austin Smothers – May 14, 2016
//CISP 360

//NOTE: Professor, you will need to compile this code with PigH.h downloaded, which I have included in the dropbox folder as a .txt named PigH.txt.

//Library functions
#include<iostream>
#include<chrono>	//chrono and thread are needed for a
#include<thread>	//time delay called in the program
#include<ctype.h>
#include<ctime>
#include<string>
#include"PigH.h"	//BONUS: uses two classes for data
			//management
using namespace std;

//Global variable declarations
bool PlayerCPU = true;	//keeps track of whose turn it is
int PlayerTurns = 0;	//tracks player turns
int AITurns = 0;	//tracks AI turns
int playerTot = 0;	//tracks player's score total
			//for the AI to compare to its own

//Function Declarations
void intro();		//a function to contain the program's
			//introduction
void instructions();	//provides instructions on how to play
void outro();		//a function to contain the program's
			//farewell
void turnSelector(bool & turn);
			//a function to randomly select who
			//goes first
char inVal(char & UI);	//BONUS: a function to validate
			//user input (i/p)
char inVal2(char & UI);	//same as aforementioned (y/n)


//-----------------------------------------------------------
//			 The Main Function
//-----------------------------------------------------------
int main()
{	

	using namespace std::this_thread;
	using namespace std::chrono;

	Player POne;	//creates a class for the player
	CPU AI;		//creates a class for the AI
	srand(time(0));	//makes it so that the rand() function
			//returns a new value each time it's
			//called

	intro();	//calls a function for the intro
	
	turnSelector(PlayerCPU);
			//calls a function to randomly select
			//who will go first

	while(AI.comScore() < 100 && 
	      POne.pScore() < 100)
	{
//the program will output both the player and AI's scores at the start of each turn, for player convenience. It then waits 3 seconds so that the player has sufficient time to read and process this information
		cout << "Your score: "
		     << POne.pScore()
		     << "          AI's score: "
			     << AI.comScore() << endl;
		playerTot = POne.pScore();
		sleep_for(seconds(3));

		//if statement used to determine whose turn
		if (PlayerCPU == true)
		{//player's turn
			POne.pTurn(PlayerCPU);
			PlayerTurns++;
		}
		else
		{//AI's turn
			AI.comTurn(PlayerCPU, playerTot);
			AITurns++;
		}
	}
	
	//if/else statement to display who won the game
	if(AI.comScore() >= 100)
		cout << "The AI has won!\n";
	else
		cout << "The player has won!\n";

	//BONUS: Keeps count of the number of turns it
	//took to win/lose. 
	//Note: This program does NOT track the total number
	//of rolls each player took, just the total turns.
	//1 'turn' = 1 player turn + 1 AI turn
	if(PlayerTurns > AITurns)
	{
		cout << "This game took: " << PlayerTurns <<
		" turns.\n";
	}
	else
	{
		cout << "This game took: " << AITurns << 
		" turns.\n";
	}
	
	outro();	//calls a function to say goodbye

	return 0;
}

//-----------------------------------------------------------
//		   Class Function Definitions
//-----------------------------------------------------------
void Player::pTurn(bool &go)
{
	//these using directories are necessary for a time
	//delay later in the program
	using namespace std::this_thread;
	using namespace std::chrono;

	int turnCount = 0;	//tracks # rolls

	cout << "It is now your turn!\n";

	while(go == true)
	{
		cout << "Rolling...\n";
//a built in time delay designed to ensure that the computer and player can't use the same time-stamp to roll the same number.
		sleep_for(seconds(2));

		pGetRoll();
		if(pRoll == 1)
		{
			cout << "Oh No! You rolled a 1!\n";
			pTurnTotal = 0;
			go = false;
		}
		else
		{
			pSetTurnTot();
			cout << "Total score for the turn: "
			     << pTurnTotal << endl;
			pGoAgain(go);
		}
	
	turnCount++;	
	}
	cout << "Number of rolls you took this turn: " 
	     << turnCount << endl;
	pSetTotTot();
	sleep_for(seconds(2));
}

void Player::pGoAgain(bool &go)
{
	cout << "Would you like to roll again? Y/N?: ";
	char input;
	cin >> input;
	if(inVal2(input) == 'y' || inVal2(input) == 'Y')
		go = true;
	else
		go = false;
	
}

void CPU::comTurn(bool &go, int pTot)
{	//BONUS: This AI takes its turns based on the
	//statistical optimization of number-of-attempts to
	//points-gained-per-attempt ratio.
	//for reference: 4 turns @ an average 14 score/turn 
	//and average 57.87% success rate (no 1's rolled)

	int turnCount = 0;	//tracks # rolls

	//these using directories are necessary for a time
	//delay later in the program
	using namespace std::this_thread;
	using namespace std::chrono;

	cout << "It is now my turn!\n";

	while(go == false)
	{
		turnCount++;

		cout << "Rolling...\n";
//a built in time delay designed to ensure that the computer and player can't use the same time-stamp to roll the same number. If your processor is sufficiently fast, this is an issue. Mine won its first game against me rolling countless 6's in under a second.
		sleep_for(seconds(2));

		comGetRoll();
		if(comRoll == 1)
		{
			cout << "Yay! AI rolled a 1!\n";
			comTurnTotal = 0;
			go = true;
		}
		else
		{
			comSetTurnTot();
			cout << "AI's score for the turn: "
			     << comTurnTotal << endl;
//AI holds if it gets to 100
			if(100 <= 
			  (comTurnTotal + comTotTotal))
				go = true;
//AI goes for the win if its score is 82+; despite the fact that 18 points in 1 turn is slightly outside of statistically optimized point gains (+0.5), the AI plays slightly more risky in the end game because of the higher reward for higher risk play
			else if (comTotTotal >= 82)
				go = false;
//AI goes for sure if the player's score is 83+; the reason for this is that the average OPTIMIZED score for one turn is 14, with a std. deviation of +/- 3 points based on rolls. The AI goes for sure if the player winning in one turn is a statistically significant possiblity.
			else if (pTot > 82)
				go = false;
//AI goes for certain if the deficit between its score and the players is greater than 13 (14 points is the statistical average for how many points one turn is worth, so it is reasonable to assume 14 points ~ 1 turn). The AI is comfortable playing from 1 turn behind because of its two prior test conditions, which will make it play more risky if losing/winning in 1 turn is a statistically significant possibility. The act of catching up to the player is considered to be "risky enough."
			else if((pTot - 13) > 
				(comTurnTotal + comTotTotal))
				go = false;
//AI uses optimized strategy for gameplay.
//See "BONUS" at the top of the AI's turn function for an explanation.
			else if(turnCount > 3 || 
				comTurnTotal > 13)
				go = true;
			else
				go = false;
		}
	}
	cout << "Number of rolls AI took this turn: " 
	     << turnCount << endl;
	comSetTotTot();
	sleep_for(seconds(2));
}
	
//-----------------------------------------------------------
//		  Non-Class Function Definitions
//-----------------------------------------------------------

//intro function
void intro()
{
	cout << "Welcome to PIG, an interactive game of "
		"chance\nbetween you and myself, the "
		"computer.\nPlease be patient with me, "
		"as this game does have\na built-in "
		"time delay, to make sure nobody cheats."
		"\n  *For instructions, press 'i';\n"
		"  *To play, press 'p'!\n";
	char helper;
	cin >> helper;
	if (inVal(helper) == 'i' || inVal(helper) == 'I')
		instructions();
	else;
	cout << "Here we go!\n";
}

//this function will validate user input.
char inVal(char & UI)
{	//UI is a reference to userInput
//--------Local variable declaration
	char failbit;	//used for input validation

	while( (UI != 'I' && UI != 'i' && 
	       UI != 'P' && UI != 'p') )
	{	//this loop validates user input
		cin.clear();
		cin.get(failbit);
		cout << "\aError: Invalid response!\n";
		cout << "Please enter your answer in I/P "
			"format: ";
		cin >> UI;
	}
	return UI;
}

//this function will validate user input.
char inVal2(char & UI)
{	//UI is a reference to userInput
//--------Local variable declaration
	char failbit;	//used for input validation

	while( (UI != 'Y' && UI != 'y' && 
	       UI != 'N' && UI != 'n') )
	{	//this loop validates user input
		cin.clear();
		cin.get(failbit);
		cout << "\aError: Invalid response!\n";
		cout << "Please enter your answer in Y/N "
			"format: ";
		cin >> UI;
	}
	return UI;
}

void turnSelector(bool & turn)
{
	using namespace std::this_thread;
	using namespace std::chrono;
	srand(time(0));
	int whoseTurn = 0;
	whoseTurn = (rand() % 2 + 1);
	if (whoseTurn == 1)
	{
		cout << "You go first!\n";
		turn = true;
	}
	else
	{
		cout << "I will go first!\n";
		turn = false;
	}
	sleep_for(seconds(1));
}

//instructions function
void instructions()
{
	cout << "You and I are both racing to reach 100 "
		"points!\n"
		"Each turn, the active player faces a "
		"decision:\n"
		"-Hold: take your turn total and add it to "
		"your overall\n       total. The next player "
		"becomes active.\n"
		"-Roll: I will generate a RANDOM number "
		"between 1 & 6.\n       Results are:\n"
		"   *1:   Lose turn, no turn total added to "
		"overall total.\n         All the points you "
		"have accumulated this turn are lost.\n"
		"   *2-6: Add this number to the turn total."
		"\n         The active player goes again.\n"
		"Press any key to continue: ";
	string cont;
	cin >> cont;
	cin.clear();
}

//farewell function
void outro()
{
	cout << "Good game friend!\nCome back and play again "
		"any time!\nNo, really, any time. It gets "
		"lonely inside this computer!\nPlease?\n";
}
