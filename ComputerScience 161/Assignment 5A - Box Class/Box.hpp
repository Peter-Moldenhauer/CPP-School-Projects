/**************************************************************************************
** Name: Peter Moldenhauer
** Date: 4/23/16
** Description: Project 5a This is the Box class declaration/header file for the Box
**class declaration file. This header file contains the Box class declaration that has
**set and get methods and constructors. The class also contains functions that calculate
**and return the volume and surface area of a Box object.
**
**Note: Per the assignment requirements, a main.cpp file/function is not included.
**************************************************************************************/

#ifndef BOX_H  //include guard
#define BOX_H  //include guard
#include <iostream>
using namespace std;

//Box class declaration
class Box
{
	private:  //Make variables private so they are not global variables!
		double height;
		double width;
		double length;

	public:
		Box();    //default constructor
		Box(double w1, double h1, double l1);  //constructor with three parameters

		//Setters prototypes, these take parameters and do not return anything
		void setHeight(double h);
		void setWidth(double w);
		void setLength(double l);

		//Getters prototypes, no parameters but both return doubles
		double getVolume();
		double getSurfaceArea();

};  //Remember semi-colon here!!!

#endif  //include guard

