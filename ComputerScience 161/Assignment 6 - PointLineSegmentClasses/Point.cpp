/*********************************************************************************************
** Name: Peter Moldenhauer
** Date: 5/1/16
** Description: This is the .cpp file for the Point class. This class contains two
**variables of double type that represent x and y coordinates for a Point object. This
**class also contains a function that takes a CONSTANT REFERENCE as a parameter to another
**Point object and returns the distance from the Point object that was passed as a
**parameter to the Point object that called the function of.
**
**Note: Per assignment instructions, do not include a main.cpp file with the classes
***********************************************************************************************/

#include <cmath>  //used for the sqrt() function
#include <iostream>
#include "Point.hpp"  //include the Point class header file

//Default constructor
Point::Point()
{
	setXCoord(0.0);
	setYCoord(0.0);
}

//Constructor
Point::Point(double p1, double p2)
{
	setXCoord(p1);
	setYCoord(p2);
}

//Setters
void Point::setXCoord(double x)
{
	xCoord = x;
}

void Point::setYCoord(double y)
{
	yCoord = y;
}

//Getters
double Point::getXCoord() const{  //note the const here to pass by constant reference
	return xCoord;
}

double Point::getYCoord() const{  //note the const here to pass by constant reference
	return yCoord;
}

//Calculate distance
double Point::distanceTo(const Point &point2) const{  //note the constant reference Point object here
	return sqrt((xCoord - point2.xCoord)*(xCoord - point2.xCoord)+(yCoord - point2.yCoord)*(yCoord - point2.yCoord));
}

















