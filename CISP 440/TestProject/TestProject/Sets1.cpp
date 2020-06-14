/* 
	Set operations 

	Dan Ross  Original Feb 2013, 32bit extension Sep 2016

	Performs set operations.

	Universe = {Bat, Cat, Chimp, Dog, Fish, Liger, Snake, Turtle}
*/ 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning( disable : 4996) 
#pragma warning( disable : 4244) 

// Start with a small universe
char Universe[8][10] = {"Bat", "Cat", "Chimp", "Dog", "Fish", "Liger", "Snake", "Turtle"};
typedef unsigned char set;          // a set, by any other name, would smell as sweet.

// Then use this big universe
char BigUniverse[32][20] = {
    "Bat", "Cat", "Chimp", "Dog", "Fish", "Liger", "Snake", "Turtle",
    "Bear", "Dragon", "Horse", "Wolf", "Rat", "Gerbil", "Rabbit", "Monkey",
    "Donkey", "Llama", "Zebra", "Hippopotamus", "Rhiceros", "Gecko", "Frog", "Sloth",
    "Deer", "Kangaroo", "Gorilla", "Alligator", "Panda", "Squirrel", "Duck", "Platypus"};
typedef unsigned long int set32;    // a set, but bigger


/*
Prints out a set in set-sequence notation
*/
void printSet(set A)
{
	printf("{ ");
	
	bool commaflag = false;
	int i = 0;
	unsigned char mask = 0x80;
	for(    ; mask; mask >>= 1, i++) {
		if(mask & A) 
		{
			if(commaflag) printf(", ");
			printf(Universe[i]);
			commaflag = true;
		}
	}
	printf(" }");
}


/*
Prints each bit of a byte
*/
void print8bits(unsigned char x)
{
	for(unsigned char mask = 0x80; mask; mask >>= 1) {
		if(mask & x) 
			printf("1");
		else 
			printf("0");
	}
}


/*
Inserts an element of the universe into a set
*/
void insert(set & A, char str[])
{
	// First we need to get the Universe index of this string
	// Use hashing instead of searching - cuz it is faster 
	// than searching, especially for a big universe.

    // You will have to modify this for the 32bit universe
    // If you do not know how to hash && do not want to learn now
    // then modify this to use a loop search lookup with strcmp

	// get a unique hash for each string
	int hash = (str[0] + str[2] ) % 20;
	
	// map unique string hashes back to their Universe indexes
	//            0   1   2   3   4      5   6   7   8   9
	int g[20] = { 6, -1,  0,  1, -1,     4, -1, -1, -1, -1,
	//           10	 11  12  13  14     15  16  17  18  19            
	             -1,  3,  2, -1, -1,    -1, -1, -1,  7,  5};

	int index = g[hash];

	// make a mask
	set mask = 0x80 >> index;

	// insert this element
	A = A | mask;
}


/*
Calculates base raised to the power exp
*/
int my_pow(int base, int  exp)
{
	int x = 1;
	for(int i = 0; i < exp; i++)
		x *= base;
	
	return x;
}


////////////// YOU WRITE THE FOLLOWING /////////////////


/*
Union
*/
set Union(set A, set B)
{
    // return a dummy value for now
    return A; 
}


/*
Intersection
*/
set Intersection(set A, set B)
{
    // return a dummy value for now
    return A; 
}


/*
Complement
*/
set Complement(set A)
{
    // return a dummy value for now
    return A;
}


/*
Difference
*/
set Difference(set A, set B)
{
    // return a dummy value for now
    return A; 
}


/*
Cardinality
*/
int Cardinality(set A)
{
    // return a dummy value for now
    return 42; 
}


/*
PowerSet

Algorithm:
OriginalSet -> Compress -> permutation0 -> decompress -> print
                           ...
                           permutationN -> decompress -> print

Example:
0010 0001 -> 11 -> 00 -> 0000 0000
                -> 01 -> 0000 0001
			    -> 10 -> 0010 0000
			    -> 11 -> 0010 0001

Basically, just generate all the 'compressed' subsets by 
counting from 0 to 2^|A|

Then decompress by inserting each bit (0 or 1) of
the 'compressed' set into the next 'available' uncompressed slot (1)
*/
void printPowerSet(set A)
{


}


bool IsSubset(set ASubset, set ASet)
{
    // return a dummy value for now
    return true; 
}


bool IsProperSubset(set ASubset, set ASet)
{
    // return a dummy value for now
    return true; 
}

/*********************************************************
   main  -  this be where the program starts...or...is it?
*********************************************************/
void main(void)
{

	set A = 0;

	insert(A, "Bat");
	insert(A, "Cat");
	insert(A, "Chimp");
	insert(A, "Snake");

	printf("Set A: ");
	printSet(A);
	printf("\nCardinality: ");
	printf("%d", Cardinality(A));

	printf("\n\nPowerSet(A):\n");
	printPowerSet(A);

	set B = 0;
	insert(B, "Chimp");
	insert(B, "Fish");
	insert(B, "Liger");

	printf("\nSet B: ");
	printSet(B);

	set C = 0;
	insert(C, "Chimp");
	insert(C, "Fish");
	insert(C, "Liger");
	printf("\nSet C: ");
	printSet(C);

	printf("\n(A Union B) Inter ~C: ");
	set D = Intersection(Union(A, B), ~C);
	printSet(D);

	if(IsSubset(B, C))
		printf("\nB is a subset of C");
	else
		printf("\nB is NOT a subset of C");

	if(IsProperSubset(B, C))
		printf("\nB is a proper subset of C");
	else
		printf("\nB is NOT a proper subset of C");

	printf("\n");

/*
OUTPUT OF ABOVE TESTING

Set A: { Bat, Cat, Chimp, Snake }
Cardinality: 4

PowerSet(A):
{  }
{ Snake }
{ Chimp }
{ Chimp, Snake }
{ Cat }
{ Cat, Snake }
{ Cat, Chimp }
{ Cat, Chimp, Snake }
{ Bat }
{ Bat, Snake }
{ Bat, Chimp }
{ Bat, Chimp, Snake }
{ Bat, Cat }
{ Bat, Cat, Snake }
{ Bat, Cat, Chimp }
{ Bat, Cat, Chimp, Snake }

Set B: { Chimp, Fish, Liger }
Set C: { Chimp, Fish, Liger }
(A Union B) Inter ~C: { Bat, Cat, Snake }
B is a subset of C
B is NOT a proper subset of C

*/


}


