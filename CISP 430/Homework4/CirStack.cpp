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
char pop(void);
void push(char);
int find(char);
void traverse(void);
int isempty(void);
char peek(void);

//main for testing the access functions
void main(void)
{
	//initialization
	head = tail = used = 0;

	push('A');
	push('B');
	push('C');
	push('D');
	push('E');
	push('F');
	traverse();

	cout << "Peeking at the head: " << peek() << endl;

	cout << "Removed: " << pop() << endl;
	cout << "Removed: " << pop() << endl;
	traverse();
	cout << "Peeking at the head: " << peek() << endl;

	//empty the list
	cout << "Removed: ";
	while (!isempty())
		cout << pop() << " ";
	cout << endl;
	traverse();

	peek();
}

//reveives a data element and appends it to the head of the list
void push(char d)
{
	//if list is empty
	if (!used) {
		mylist[head] = d;
		used++;
		return;
	}

	//prevent overflow
	if ((head + 1) % SIZE == tail) {
		cout << "Overflow, Element not appended.\n";
		return;
	}

	//append data
	head = (head + 1) % SIZE;
	mylist[head] = d;
	used++;

}
//Time Complexity: O(1), as the function does not care what size the mylist[] array is, it simply executes for one element within the array, if the array exists and isn’t empty.


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
		cout << "The list contains: " << mylist[0] << endl;
		return;
	}

	//more than 1 element
	p = 0;
	printf("The list contains: ");
	do {
		cout << mylist[p] << " ";
		p = (p + 1) % SIZE;
	} while (p != (head + 1) % SIZE);
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
char pop(void)
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
	head = (head - 1) % SIZE;
	used--;
	return temp;
}
//Time Complexity: O(1), as the function does not care what size the mylist[] array is, it simply executes for one element within the array, if the array exists and isn’t empty.


//looks at the data element at the head
//if the data is found, returns 1
//if the data is not found, returns 0
char peek(void)
{
	//empty?
	if (isempty())
		return -1;

	//1 or more elements
	if (mylist[head]) 		//found it
		return mylist[head];
	return -1;

}
//Time Complexity: O(1), as the function does not care what size the mylist[] array is, it simply executes for one element within the array, if the array exists and isn’t empty.


