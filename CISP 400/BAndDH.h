//BAndDH.h - Class definitions for BAndD

#ifndef BANDDH_H_
#define BANDDH_H_

//library functions
	//none required

//class declarations

class Population	//class declaration
{
private:
	//private variables
double pop = 0;		//stores the population
int birthNum = 0;	//stores # of births
int deathNum = 0;	//stores # of deaths
double birthRate = 0;	//stores Birth Rate
double deathRate = 0;	//stores Death Rate
	//private functions
void setPopulation();	//sets the pop variable
void setBirths();	//sets the birthNum variable
void setDeaths();	//sets the deathNum variable
double getBirthRate();	//sets birthRate = birthNum / pop
double getDeathRate();	//sets deathRate = deathNum / pop

int inVal6(int &UI);	//validates integer input

public:
	//public constructors
Population();		//calls class member functions
Population(double p, int b, int d);
			//accepts 3 arguments
	//public functions
void showData();	//displays collected data
};

#endif
