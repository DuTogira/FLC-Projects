//Listing91.txt - structure templates and function prototypes
//Austin Smothers – April 21, 2016
//CISP 360

#ifndef COORDIN_H_
#define COORDIN_H_

struct polar
{
	double distance;	//distance from origin
	double angle;		//direction from origin
};

struct rect
{
	double x;	//horizontal distance from origin
	double y;	//vertical distance from origin
};

//prototypes
polar rect_to_polar(rect xypos);
void show_polar(polar dapos);

#endif
