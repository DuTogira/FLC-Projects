/*
CISP 430

Linked List Implementation

Updated 09/26/2017
Austin Smothers
This program builds on code provided by
Dan Ross

*/

#include <iostream>
using namespace std;

//Our Node
struct node {
	node *next;
	char d;
};

//head and tail pointers
node *head = 0;
node *tail = 0;

//function declarations
char remove(void);
void append(char);
int find(char);
void traverse(void);
int isempty(void);

//main for testing the access functions
void main(void)
{
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
		cout << remove() << ", ";
	cout << endl;
	traverse();

	find('G');

	//should do more testing than is shown here
}

//receives a char element and appends it to the tail of the list
void append(char d)
{
	//make a new node
	node *p = new node;
	p->next = 0;
	p->d = d;

	if (!(head))	//list is empty
	{
		head = tail = p;
	}
	else			//append to tail end
	{
		tail->next = p;
		tail = p;
	}
}

//traverse the list from the head to the tail, and prints out each char element
void traverse(void)
{
	node *p = head;

	cout << "The list contains: ";

	while (p)
	{
		cout << (char)p->d << " ";
		p = p->next;
	}
	cout << endl;
}

//returns true if the list is empty, returns false otherwise
int isempty(void)
{
	if (head)
		return 0;
	else
		return 1;
}

//removes a char element from the head of the list and returns it
//returns -1 if the list is empty
char remove(void)
{
	node *p;
	char temp;

	//return null if list is empty
	if (!head)
		return -1;

	//only one node?
	if (head == tail)
	{
		//remove and destroy head node
		temp = head->d;
		delete head;
		head = tail = 0;
		return temp;
	}

	//more than one node
	//remove and destroy head node
	p = head;
	head = head->next;
	temp = p->d;
	delete p;
	return temp;
}

//searches the list for a char element
//if the char is found, removes the char element and returns 1, otherwise returns 0
int find(char d)
{
	node *c;
	node *pc;

	//empty?
	if (!head)
	{
		cout << d << " not found" << endl;
		return 0;
	}

	//one node?
	if (head == tail)
	{
		if (head->d == d)
		{
			//destroy node
			delete head;
			head = tail = 0;
			cout << d << " found." << endl;
			return 1;
		}
		else
		{
			cout << d << " not found." << endl;
			return 0;
		}
	}

	//two or more nodes
	pc = head;
	c = head->next;
	if (pc->d == d)	//found it at the head
	{
		head = head->next;
		delete pc;
		cout << d << " found." << endl;
		return 1;
	}

	//look at nodes after the head node
	while (c)
	{
		if (c->d == d)	//found it after the head
		{
			pc->next = c->next;
			//take care of tail
			if (c == tail)
				tail == pc;
			//destroy node
			delete c;
			cout << d << " found." << endl;
			return 1;
		}
		pc = c;
		c = c->next;

	}
	cout << d << " not found." << endl;
	return 0;
}