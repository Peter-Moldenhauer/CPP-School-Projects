/************************************************************************************
** Name: Peter Moldenhauer
** Date: 5/1/16
** Description: This is the header file for the LineSegment class. This class
**contains two Point class objects that represent endpoints to a line. This class
**also contains functions to calculates the length of the line made up of the two
**endpoints in addition to the slope of the line.
**
**Note: Per assignment instructions, a main.cpp file was not included with the class
**************************************************************************************/

#ifndef LINESEGMENT_HPP //include guard
#define LINESEGMENT_HPP  //include guard
#include "Point.hpp"  //include the Point class header file

class LineSegment{

	private:
		Point endpt1;  //Point class object 1
		Point endpt2;  //Point class object 2

	public:
		LineSegment(Point, Point);    //Constructor
		void setEnd1(Point p1);      //Setters
		void setEnd2(Point p2);

		Point getEnd1();     //Getters
		Point getEnd2();

		double length();    //Calculate length
		double slope();     //Calculate slope

};

#endif  //include guard



