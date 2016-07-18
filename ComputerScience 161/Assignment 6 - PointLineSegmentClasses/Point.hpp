/*********************************************************************************************
** Name: Peter Moldenhauer
** Date: 5/1/16
** Description: This is the header file for the Point class. This class contains two
**variables of double type that represent x and y coordinates for a Point object. This
**class also contains a function that takes a CONSTANT REFERENCE as a parameter to another
**Point object and returns the distance from the Point object that was passed as a
**parameter to the Point object that called the function of.
**
**Note: Per assignment instructions, do not include a main.cpp file with the classes
***********************************************************************************************/

#ifndef POINT_HPP  //include guard
#define POINT_HPP  //include guard

class Point
{
	private:
		double xCoord;  //keep variables in classes private!
		double yCoord;

	public:
		Point();     //default constructor
		Point(double p1, double p2);  //constructor

		void setXCoord(double x);   //setters
		void setYCoord(double y);

		double getXCoord() const;   //getters
		double getYCoord() const;

		double distanceTo(const Point &point2) const; //calculate distance, Pass another Point object by constant reference
};

#endif  //include guard


