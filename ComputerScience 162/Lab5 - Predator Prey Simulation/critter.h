/*****************************************************************************************************************
** Program Filename: critter.h
** Author: Peter Moldenhauer
** Date: 10/25/16
** Assignment: Lab 5
** Description: This is the critter header file for the critter class that is used in the 2D predator-prey
** simulation program. The critter class is an abstract class because it contains pure virtual functions.
** Input: None
** Output: This is the base class that gets inherited by the ant and doodlebug classes to be used in the program
******************************************************************************************************************/

#ifndef CRITTER_H
#define CRITTER_H

#include <iostream>
#include <stdlib.h>	  // for random start position
#include <time.h>  // for random start position

class Grid; // Forward declared

class Critter {

protected:
	int xCurrent;
	int yCurrent;
	int xPrevious;
	int yPrevious;
	int xMax;
	int yMax;
	bool moveNext;
	virtual void breed() = 0;  // pure virtual function

public:
	virtual ~Critter();
	virtual void init(int x, int y, Grid *grid) = 0;  // pure virtual function
	virtual const int getType() = 0;  // pure virtual function
	virtual void eat(Critter ***array, int i, int j) = 0; // pure virtual function
	virtual void move(int m) = 0; //pure virtual function
	virtual void starve(Grid *gridPtr) = 0;  // pure virtual function
	int const xGet();
	int const yGet();
	int const xPGet();
	int const yPGet();
	bool const getMoveNext();
	void setMoveNextTrue();
	void setMoveNextFalse();
	void setXCurrent(int x);
	void setYCurrent(int y);

};

#endif
