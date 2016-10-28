/*****************************************************************************************************************
** Program Filename: grid.h
** Author: Peter Moldenhauer
** Date: 10/25/16
** Assignment: Lab 5
** Description: This is the grid header file for the grid class that is used in the 2D predator-prey simulation
** program. The grid class creates a 2D array of pointers to critter objects (either ant or doodlebug). The grid
** class updates the location of the critters on the grid for each time step as well as prints out the grid to the
** user.
** Input: Uses the ant and doodlebug classes to put critters on the grid
** Output: Prints the grid out to the user with all of the critter objects on the grid.
******************************************************************************************************************/

#ifndef GRID_H
#define GRID_H

#include "ant.h"
#include "doodlebug.h"
#include <iostream>
using namespace std;

class Ant; 	// Forward declared class Ant to allow for compilation

class Grid {

private:

	Critter ***gridArray;  // 2d array of pointers to critter objects to be used as the grid
	int xMax;
	int yMax;

	void create();
	void fillGrid();
	void resetMoveNext();

public:
	Grid(int x, int y);
	~Grid();
	int gridSize();
	void printGrid();
	void startLocation(int antPop, int doodlebugPop);
	void updateLocation();
	void addNew(Critter *critterPtr);
	void remove(Critter *critterPtr);
    int getXMax();
    int getYMax();
};

#endif
