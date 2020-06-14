//inventoryH.h - Class definitions for inventory

#ifndef INVENTORYH_H_
#define INVENTORYH_H_

//library functions


class Inventory		//class declaration
{
private:
	//private variables
int itemNumber;		//stores the item's I.D number
int quantity;		//stores the # of items in stock
double cost;		//stores the cost/item
double totalCost;	//stores the total cost of the items

public:
	//public constructors
Inventory();		//sets member variables to 0
Inventory(int n, int q, double c);
			//accepts user input
	//public functions
void setItemNumber(int i);
			//sets the itemNum variable
void setQuantity(int i);//sets the quantity variable
void setCost(double i);	//sets the cost variable
int getItemNumber();	//returns itemNumber
int getQuantity();	//returns quantity
double getCost();	//returns cost
double getTotalCost();	//returns quantity * cost
void showData();	//displays collected data
};

#endif
