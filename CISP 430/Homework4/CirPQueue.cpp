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
char dq(void);
void insert(char);
int find(char);
void traverse(void);
int isempty(void);
char peek(void);

//main for testing the access functions
void main(void)
{
	//initialization
	head = tail = used = 0;

	insert('E');
	insert('A');
	insert('F');
	traverse();
	cout << "Peeking at the head: " << peek() << endl;
	insert('C');
	insert('D');
	traverse();
	cout << "Peeking at the head: " << peek() << endl;
	insert('B');
	traverse();
	cout << "Peeking at the head: " << peek() << endl;

	cout << "Removed: " << dq() << endl;
	cout << "Peeking at the head: " << peek() << endl;
	cout << "Removed: " << dq() << endl;
	cout << "Peeking at the head: " << peek() << endl;
	traverse();

	//empty the list
	cout << "Removed: ";
	while (!isempty())
		cout << dq() << " ";
	cout << endl;
	traverse();

}

//receives a data element and inserts it into the list and sorts it
void insert(char d)
{
	//variables for insertion sort
	int j, temp;

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

	//insertion sort... insertion
	for (int i = 0; i < (tail + 1); i++) {
		j = i;
		
		while (j > 0 && (mylist[j] < mylist[j - 1])) {
			temp = mylist[j];
			mylist[j] = mylist[j - 1];
			mylist[j - 1] = temp;
			j--;
		}
	}

	//increment used
	used++;

}
//Time Complexity: O(N^2), as the function must execute a while loop within a for loop


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
//Time Complexity: O(1), as the function does not care what size the mylist[] array is, it simply executes for one element within the array, if the array exists and isn’t empty.

//removes a data element from the head of the list and returns it
//returns -1 if the list is empty
char dq(void)
{
	char temp;
	int p;

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
	used--;
	p = head;
	//scoot stuff after p up
	while (p != tail) {
		mylist[p] = mylist[(p + 1) % SIZE];
		p = (p + 1) % SIZE;
	}
	tail--;
	if (tail < 0)
		tail = SIZE - 1;
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