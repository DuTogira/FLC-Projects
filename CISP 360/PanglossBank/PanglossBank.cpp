//PanglossBank.txt – Keeps track of customer records
//Austin Smothers – April 30, 2016
//CISP 360

//Library function declarations
#include <iostream>
#include <string>
using namespace std;



//Global variable declarations
string runBank = "Y";	//a variable which controls whether
			//or not the program runs

string *bHav = new string[1];

const float oLimit = 0 - 500;	//Overdraft limit
float monOut = 0.0;		//used for math later
int tipper = 0;			//used for controlling
				//regular vs plus accounts
				//in switch statement




//structure declarations
struct regular
{//structure for handling regular client accounts
	string name;		//client name
	int accNo;		//Client account number
	float accBal = 0.0;	//Account balance
};

struct pluss
{//structure for handling pluss client accounts
	string name;
	int accNo;
	float accBal = 0.0;
	float oDraft = 0.0;	//Overdraft protection
	float inRate = 0.0;	//Interest rate
};




//function declarations
inline void cAcct(regular &r);	//creates regular account
inline void cAcctPlus(pluss &p);//creates plus account
float depMoney();		//adds money to an account
float getMoney();		//takes money from an account


//------------------------------------------------------------
// 			THE MAIN FUNCTION
//------------------------------------------------------------

int main()
{//1
	
	cout <<"Welcome to Pangloss Bank!\n";
	regular reg;
	pluss plu;
	float monOut;
	int p;
	float balance;
	string name;
	char failbit;
	string num;
	string l;
	while(runBank == "Y" || runBank == "y")
	{//BONUS: Allows the client to perform as many
	 //actions as they desire via a do/while loop and
	 //a switch statement
	cout << "Would you like to:\n1. Create an account\n"
		"2. Create a plus account\n"
		"3. Deposit money into an account\n"
		"4. Withdraw money from an account\n"
		"5. Display existing account info\n"
		"Please enter the number corresponding to\n"
		"the action you would like to perform: ";
	cin >> *bHav;
	cout << endl << endl;
	p = std::stoi(*bHav, 0, 0);
	switch(p)
	{//3
		case 1 :cout << "Welcome to the family!\n";
			while(l != "Y" && l != "y")
			{
			cout << "Please enter your First and Last name: ";
			cin.get(failbit);
			cin.clear();
			getline(cin, name);
			reg.name = name;
			cout << "Thank you " << reg.name << "!\n";
			cout << "Please enter your new 8 digit account " 			"number: ";
			std::string::size_type sz;
			cin >> num;
			reg.accNo = stoi(num, &sz + 1);
			cout << "Does the following information appear to be "
		"correct?\n" << reg.name << endl 
	    		 << reg.accNo << "\nY/N: ";
			cin >> l;
			}
			cout << "Thank you for creating an account with us!\n"
			"You will now be taken back to the main "
			"menu.\n\n\n";
			l = "Y";
			tipper = 0;
			break;
		case 2 : cout << "Welcome to the family!\n";
			while(l != "Y" && l != "y")
			{
			cout << "Please enter your First and Last name: ";
			cin.get(failbit);
			cin.clear();
			getline(cin, name);
			plu.name = name;
			cout << "Thank you " << plu.name << "!\n";
			cout << "Please enter your new 8 digit account " 			"number: ";
			std::string::size_type sz;
			cin >> num;
			plu.accNo = stoi(num, &sz + 1);
			cout << "Does the following information appear to be "
			"correct?\n" << plu.name << endl 
	   		  << plu.accNo << "\nY/N: ";
			cin >> l;
			}
			cout << "Thank you for creating an account with us!\n"
			"You will now be taken back to the main "
			"menu.\n\n\n";
			l = "Y";
			tipper = 1;
			break;
		case 3 : if (tipper == 0)
			{
				balance =
				reg.accBal + depMoney();
				reg.accBal = balance;
			}
			if (tipper == 1)
			{//4
				balance =
				plu.accBal + depMoney();
				plu.accBal = balance;
				plu.oDraft =
				plu.accBal - oLimit;
				if(plu.oDraft < 500.0)
				{//5
					plu.inRate = 
					0.03 * 
					(0 - plu.accBal);
				}//4
				if(plu.oDraft > 500.0)
					plu.oDraft = 500.0;
			}//3
			break;
		case 4 : monOut = getMoney();
			if(tipper == 1)
			{//4
				while (monOut > 
				(plu.accBal + plu.oDraft))
				{//5
					cout << "Error!\a "
						"Insufficient"
						" funds!\n"
						"Try again: ";
					monOut = getMoney();
				}//4
				balance =
				plu.accBal - monOut;
				plu.accBal = balance;
				if(plu.accBal < 0.0)
				{//5
					plu.oDraft =
					plu.accBal - oLimit;
					plu.inRate = 
					0.03 * 
					(0 - plu.accBal);
					
				}//4
			}//3
			if (tipper == 0)
			{//4
				while(monOut > reg.accBal)
				{//BONUS: validates input
					cout << "Error!\a "
						"Insufficient"
						" funds!\n"
						"Try again: ";
					monOut = getMoney();
				}//4
				balance =
				reg.accBal - monOut;
				reg.accBal = balance;
			}//3
			break;
		case 5 : if(tipper = 1)
				cout << plu.name <<
				endl << plu.accNo <<
				endl << plu.accBal <<
				endl << plu.oDraft <<
				endl << plu.inRate <<
				endl;
			if(tipper = 0)
				cout << reg.name << 					endl << reg.accNo <<
				endl << reg.accBal <<
				endl << endl;
			break;
		default : break;
	}//2
	delete [] bHav;
	cout << "Is there anything else we can help "
		"you with? Y/N?: ";
	cin >> runBank;
	cout << endl << endl;
	}
cout << "Thank you for banking with Pangloss Bank!\n"
	"Goodbye!\n";
return 0;
}//0

//------------------------------------------------------------
//                     Function Definitions
//------------------------------------------------------------

void cAcct(regular &r)
{//BONUS: Both this function and the following allows users
//to revise account information before creating the account
	cout << "Welcome to the family!\n";
	string l;
	while(l != "Y" && l != "y")
	{
	cout << "Please enter your First and Last name: ";
	string name;
	char failbit;
	cin.get(failbit);
	cin.clear();
	getline(cin, name);
	r.name = name;
	cout << "Thank you " << r.name << "!\n";
	cout << "Please enter your new 8 digit account " 			"number: ";
	string num;
	std::string::size_type sz;
	cin >> num;
	r.accNo = stoi(num, &sz + 1);
	cout << "Does the following information appear to be "
		"correct?\n" << r.name << endl 
	     << r.accNo << "\nY/N: ";
	cin >> l;
	}
	cout << "Thank you for creating an account with us!\n"
		"You will now be taken back to the main "
		"menu.\n\n\n";
}

void cAcctPlus(pluss &p)
{
	cout << "Welcome to the family!\n";
	string l;
	while(l != "Y" && l != "y")
	{
	cout << "Please enter your First and Last name: ";
	string name;
	char failbit;
	cin.get(failbit);
	cin.clear();
	getline(cin, name);
	p.name = name;
	cout << "Thank you " << p.name << "!\n";
	cout << "Please enter your new 8 digit account " 			"number: ";
	string num;
	std::string::size_type sz;
	cin >> num;
	p.accNo = stoi(num, &sz + 1);
	cout << "Does the following information appear to be "
		"correct?\n" << p.name << endl 
	     << p.accNo << "\nY/N: ";
	cin >> l;
	}
	cout << "Thank you for creating an account with us!\n"
		"You will now be taken back to the main "
		"menu.\n\n\n";
}

float depMoney()
{
	string money;
	string l;
	float mon;
	while(l != "Y" && l != "y")
	{
	cout << "Please enter the amount of money\nyou would "
		"like to deposit: ";
	cin >> money;
	std::string::size_type sz;
	mon = stof(money, (&sz + 16));
	cout << "Is this the correct ammount: $" << mon
	     << "?\nY/N: ";
	cin >> l;
	}
	cout << endl << endl;
	return mon;
}

float getMoney()
{
	string money;
	string l;
	float mon;
	while(l != "Y" && l != "y")
	{
	cout << "Please enter the amount of money\nyou would "
		"like to deposit: ";
	cin >> money;
	std::string::size_type sz;
	mon = stof(money, &sz + 16);
	cout << "Is this the correct ammount: $" << mon
	     << "?\nY/N: ";
	cin >> l;
	}
	cout << endl << endl;
	return mon;
}
