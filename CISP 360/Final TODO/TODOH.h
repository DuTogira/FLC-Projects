//TODOH.h - Class definitions for TODO
//Austin Smothers - May 21, 2016
//CISP 360

#ifndef TODO_H_
#define TODO_H_


class Player			//class declaration
{
private:
	//private variables
	int pRoll = 0;		//stores rolls
	int pTurnTotal = 0;	//stores player turn totals
	int pTotTotal = 0;	//stores player's total score
	//private functions
	void pGetRoll() {srand(time(0));
			 pRoll = rand() % 6 + 1;}
		//gets a random number
	void pSetTurnTot() {pTurnTotal += pRoll;}
		//records the player total for the turn
	void pSetTotTot() {pTotTotal += pTurnTotal;
			  pTurnTotal = 0;}
		//records the player total for the game
	void pGoAgain(bool &go);
		//gives the player the option to keep going
public:
	//public functions
	void pTurn(bool &go);
		//function for the player turn
	int pScore() {return pTotTotal;}
		//function that returns player score
};

class CPU			//class declaration
{
private:
	//private variables
	int comRoll = 0;	//stores rolls
	int comTurnTotal = 0;	//stores AI turn totals
	int comTotTotal = 0;	//stores AI's total score
	//private functions
	void comGetRoll() {srand(time(0));
			   comRoll = rand() % 6 + 1;}
		//gets a random number
	void comSetTurnTot() {comTurnTotal += comRoll;}
		//records the AI total for the turn
	void comSetTotTot() {comTotTotal += comTurnTotal;
			  comTurnTotal = 0;}
		//records the AI total for the game
public:
	//public functions
	void comTurn(bool &go);
		//function for the AI turn
	int comScore() {return comTotTotal;}
		//function that returns the AI score
};

#endif
