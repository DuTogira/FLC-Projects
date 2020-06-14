/*

CISP 430

Circular List Implementation

Updated 09/26/2017
Austin Smothers
This program builds on code provided by Professor Dan Ross

*/

#include <iostream>
using namespace std;

//the list
#define SIZE 10
char mylist[SIZE];
int head, tail, used;

//function declarataions
char remove(void);
void append(char);
int find(char);
void traverse(void);
int isempty(void);

//main for testing the access functions
void main(void)
{
	//initialization
	head = tail = used = 0;

	append('A');
	append('B');
	append('C');
	append('D');
	append('E');
	append('F');
	traverse();

	find('X');
	find('D');
	traverse();

	cout << "Removed: " << remove() << endl;
	cout << "Removed: " << remove() << endl;
	traverse();

	//empty the list
	cout << "Removed: ";
	while (!isempty())
		cout << remove() << " ";
	cout << endl;
	traverse();

	find('G');
}

//reveives a data element and appends it to the tail fo the list
void append(char d)
{
	//if list is empty
	if (!used) {
		mylist[tail] = d;
		used++;
		return;
	}

	//prevent overflow
	if ((tail + 1) % SIZE == head) {
		cout << "Overflow, Element not appended.\n";
		return;
	}

	//append data
	tail = (tail + 1) % SIZE;
	mylist[tail] = d;
	used++;

}

//traverses the list from teh head to the tail, and prints out each data element
void traverse(void)
{
	char p;		//pointer

	//empty list
	if (isempty()) {
		cout << "The list is empty.\n";
		return;
	}

	//1 element
	if (used == 1) {
		cout << "The list contains: " << mylist[head] << endl;
		return;
	}

	//more than 1 element
	p = head;
	printf("The list contains: ");
	do {
		cout << mylist[p] << " ";
		p = (p + 1) % SIZE;
	} while (p != (tail + 1) % SIZE);
	cout << endl;

}

//returns true if the list is empty, returns false otherwise
int isempty(void)
{
	if (used)
		return 0;
	else
		return 1;
}

//removes a data element from the head of the list and returns it
//returns -1 if the list is empty
char remove(void)
{
	char temp;

	//empty list
	if (isempty()) {
		return -1;
	}

	//1 element
	if (used == 1) {
		used = 0;
		return mylist[head];
	}

	//more than 1 element
	//remove data
	temp = mylist[head];
	head = (head + 1) % SIZE;
	used--;
	return temp;
}

//searches the list for a data element
//if the data is found, removes the data element and returns 1
//if the data is not found, returns 0
int find(char d)
{
	int p;	//pointer

	//empty?
	if (isempty()) {
		cout << d << " not found." << endl;
		return 0;
	}

	//only one node?
	if (used == 1) {
		if (mylist[head] == d)
		{
			used = 0;
			cout << d << " found." << endl;
			return 1;
		}
		else
		{
			cout << d << " not found." << endl;
			return 0;
		}
	}

	//more than 1 element
	p = head;
	do {
		if (mylist[p] == d) {	//found it
			//scoot stuff after p up
			while (p != tail) {
				mylist[p] = mylist[(p + 1) % SIZE];
				p = (p + 1) % SIZE;
			}
			tail--;
			if (tail < 0)
				tail = SIZE - 1;
			used--;
			cout << d << " found" << endl;
			return 1;
		}
		p = (p + 1) % SIZE;
	} while (p != (tail + 1) % SIZE);
	cout << d << " not found" << endl;
	return 0;

}

