/*****************************************************************************************************************
** Program Filename: doodlebug.h
** Author: Peter Moldenhauer
** Date: 10/25/16
** Assignment: Lab 5
** Description: This is the doodlebug header file for the doodlebug class that is used in the 2D predator-prey
** simulation program. The doodlebug class inherits from the critter class. This class contains virtual functions.
** Input: Inherits from the critter class
** Output: This class is used in the grid class to simulate a doodlebug moving, breeding, eating and starving
******************************************************************************************************************/

#ifndef DOODLEBUG_H
#define DOODLEBUG_H

#include "critter.h"
#include "grid.h"

class Grid;		// forward declared to allow grid reference

class Doodlebug : public Critter {  // inherit from the critter class

private:
	int count;
	int starveSteps;
	int stepsToBreed;
	int stepsAllowed;
	Grid *gridPtr;
	virtual void breed(); // virtual function

public:
	Doodlebug();
	virtual void init(int x, int y, Grid *grid);  // virtual function
	virtual void move(int m);  // virtual function
	virtual const int getType();  // virtual function
	virtual void eat(Critter ***array, int i, int j);  // virtual function
	virtual void starve(Grid *gridPtr);  // virtual function
};

#endif
