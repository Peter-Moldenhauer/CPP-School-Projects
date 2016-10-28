/*****************************************************************************************************************
** Program Filename: ant.h
** Author: Peter Moldenhauer
** Date: 10/25/16
** Assignment: Lab 5
** Description: This is the ant header file for the ant class that is used in the 2D predator-prey simulation
** program. The ant class inherits from the critter class. This class contains virtual functions.
** Input: Inherits from the critter class
** Output: This class is used in the grid class to simulate an ant moving and breeding
******************************************************************************************************************/

#ifndef ANT_H
#define ANT_H

#include "critter.h"
#include "grid.h"

class Grid;	 // forward declared to allow grid reference

class Ant : public Critter {  // inherit from the critter class

private:
	int count;
	Grid *gridPtr;
	virtual void breed();  // virtual function

public:
	Ant();
	virtual void init(int x, int y, Grid *grid); // virtual function
	virtual void move(int m); // virtual function
	virtual const int getType(); // virtual function
	virtual void eat(Critter ***array, int i, int j); // does not do anything in this class
	virtual void starve(Grid *gridPtr); // does not do anything in this class
};

#endif
