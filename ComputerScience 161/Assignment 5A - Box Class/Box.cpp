/**************************************************************************************
** Name: Peter Moldenhauer
** Date: 4/23/16
** Description: Project 5a This is the Box class implementation file that demonstrates
**the use of a class with the class declaration (interface/header) in a separate file.
**This program contains the class called Box that has set and get methods and
**constructors. The class also contains functions that calculate and return the volume
**and surface area of a Box object.
**
**Note: Per the assignment requirements, a main.cpp file/function is not included.
**************************************************************************************/

#include "Box.hpp"

//Default constructor
Box::Box()
{
	setHeight(1.0);  //initialize variables with default values through set methods
	setWidth(1.0);
	setLength(1.0);
}

//Constructor
Box::Box(double h1, double w1, double l1)  //constructor with three parameters
{
	setHeight(h1);  //can call the set methods here to initialize the variables or can initialize them directly
	setWidth(w1);  //example of initializing variables directly: width = w1;
	setLength(l1);
}

void Box::setHeight(double h)  //setter, takes a parameter but does not return anything
{
	height = h;
}

void Box::setWidth(double w)  //setter, takes a parameter but does not return anything
{
	width = w;
}

void Box::setLength(double l)  //setter, takes a parameter but does not return anything
{
	length = l;
}

double Box::getVolume()  //getter, no parameter, returns a double
{
	return height*width*length;  //formula for volume
}

double Box::getSurfaceArea()  //getter, no parameter, returns a double
{
	return (((length*height)*2) + ((width*height)*2) + ((length*width)*2)); //formula for surface area
}


