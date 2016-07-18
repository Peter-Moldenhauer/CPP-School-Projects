/************************************************************************************
** Name: Peter Moldenhauer
** Date: 5/1/16
** Description: This is the .cpp file for the LineSegment class. This class
**contains two Point class objects that represent endpoints to a line. This class
**also contains functions to calculates the length of the line made up of the two
**endpoints in addition to the slope of the line.
**
**Note: Per assignment instructions, a main.cpp file was not included with the class
**************************************************************************************/

#include <iostream>
#include <cmath>  //used for the sqrt() function
#include "LineSegment.hpp"  //include the LineSegment class header file

//Constructor
LineSegment::LineSegment(Point p1, Point p2)
{
	setEnd1(p1);
	setEnd2(p2);
}

//Setters
void LineSegment::setEnd1(Point p1)
{
	endpt1 = p1;
	//p1.setXCoord(p1.getXCoord()); How I initially thought the code should look
	//p1.setYCoord(p1.getYCoord());
	//p1 = p1;
}

void LineSegment::setEnd2(Point p2)
{
	endpt2 = p2;
	//p2.setXCoord(p2.getXCoord());
	//p2.setYCoord(p2.getYCoord());
	//p2 = p2;
}

//Getters
Point LineSegment::getEnd1()
{
	return endpt1;
	//return p1;
}

Point LineSegment::getEnd2()
{
	return endpt2;
	//return p2;
}

//length and slope functions
double LineSegment::length()
{
	return endpt1.distanceTo(endpt2);
	//return p1.distanceTo(p2);
}

double LineSegment::slope()
{
	return (endpt2.getYCoord() - endpt1.getYCoord()) / (endpt2.getXCoord() - endpt1.getXCoord());  //calculate slop here
	//return (endpt2.getXCoord() - endpt1.getXCoord()) / (endpt2.getYCoord() - endpt1.getYCoord());
	//return (p2.getYCoord()-p1.getYCoord())/(p2.getXCoord()-p2.getXCoord());
}


