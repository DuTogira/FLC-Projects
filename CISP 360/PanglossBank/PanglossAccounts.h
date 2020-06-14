//Function Template

#ifndef PANGLOSSACCOUNTS_H_	//defines the header file
#define PANGLOSSACCOUNTS_H_

#include <string>

//variable declarations

extern string bHav;		//controls which behavior 
				//a client
				//would like to acccess
extern string cName;		//Client name

//structure declarations

struct regular
{//structure for handling regular client accounts
	string accNo[16];	//Client account number
	string accBal;		//Account balance
	string cInfo;		//BONUS: allows client to 
				//correct improperly entered 
				//information
};

struct plus
{//structure for handling plus client accounts
	string accNo;
	string accBal;
	float oDraft = 0.0;	//Overdraft protection
	float inRate = 0.0;	//Interest rate
	string cInfo;
};

//end structure declarations

//------------------------------------------------------------

//function declarations
string cAcct();
string cAcctPlus();
float depMoney();
float getMoney();
string dispAcct();

#endif
