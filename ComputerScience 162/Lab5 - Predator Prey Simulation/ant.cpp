/**************************************************************************************************************
** Program Filename: ant.pp
** Author: Peter Moldenhauer
** Date: 10/25/16
** Assignment: Lab 5
** Description: This is the ant .cpp file for the ant class that is used in the 2D predator-prey simulation
** program. The ant class inherits from the critter class. This class contains virtual functions.
** Input: Inherits from the critter class
** Output: This class is used in the grid class to simulate an ant moving and breeding
***************************************************************************************************************/

#include "ant.h"

/************************************************
* Function: Ant()
* Description: This is the Ant constructor
* Parameters: none
* Pre-Conditions: none
* Post-Conditions: moveNext is set, count is set
* Return: none
*************************************************/
Ant::Ant() {
	moveNext = true;
	count = 0;
}

/********************************************************************************
* Function: init()
* Description: This function initializes an Ant on the array
* Parameters: x (int) y (int) and a pointer to a grid object
* Pre-Conditions: none
* Post-Conditions: sets xCurrent, yCurrent, xMax, yMax and gridPtr
* Return: none
*********************************************************************************/
void Ant::init(int x, int y, Grid *grid) {

	xCurrent = rand() % x;	// random ant at x location
	yCurrent = rand() % y;	// random ant at y location

	xMax = x;
	yMax = y;
	gridPtr = grid;
}

/*******************************************************************************************
* Function: breed()
* Description: This function counts the number of moves and adds a new ant object if the
* object has made 3 moves.
* Parameters: none
* Pre-Conditions: count and gridPtr have to be set
* Post-Conditions: adds a new ant object based on conditions, reset count variable
* Return: none
*******************************************************************************************/
void Ant::breed() {
	if (count == 4) { // if ant moves three steps (1 + 3)
		gridPtr->addNew(this);	// add a new Ant object
		count = 0;
	}
}

/****************************************************************************************
* Function: move()
* Description: This function moves the ant. This function also calls the starve and breed
* functions based on the ant movement.
* Parameters: none
* Pre-Conditions: variables have to be set
* Post-Conditions: moves the ant object on the grid
* Return: none
*****************************************************************************************/
void Ant::move(int m) {
    //if (m == 0)
        // ant moves now

    int movement = rand() % 4 + 1;	// can move in only 4 directions

    xPrevious = xCurrent;
    yPrevious = yCurrent;
    switch (movement) {
    	case 1: if (yCurrent - 1 == -1 || yCurrent - 1 == yMax) {
				moveNext = false;
			}
			else if (yCurrent - 1 > -1 || yCurrent - 1 < yMax) {
    			yCurrent -= 1;	// Up
    			moveNext = false;
    			count += 1;
    			breed();
			}
    		break;

		case 2: if (xCurrent + 1 == -1 || xCurrent + 1 == xMax) {
				moveNext = false;
			}
			else if (xCurrent + 1 > -1 || xCurrent + 1 < xMax) {
    			xCurrent += 1;	// Right
    			moveNext = false;
    			count += 1;
    			breed();
			}
    		break;

		case 3: if (yCurrent + 1 == -1 || yCurrent + 1 == yMax) {
				moveNext = false;
			}
			else if (yCurrent + 1 > -1 || yCurrent + 1 < yMax) {
    			yCurrent += 1;	// Down
    			moveNext = false;
    			count += 1;
    			breed();
			}
    		break;

		case 4: if (xCurrent - 1 == -1 || xCurrent - 1 == xMax) {
				moveNext = false;
			}
			else if (xCurrent - 1 > -1 || xCurrent - 1 < xMax) {
    			xCurrent -= 1;	// Left
    			moveNext = false;
    			count += 1;
    			breed();
			}
    		break;
    }
}

/*****************************************************
* Function: getType()
* Description: Check the type of object in the array
* Parameters: none
* Pre-Conditions: none
* Post-Conditions: none
* Return: 1 to represent an ant object
******************************************************/
const int Ant::getType() {
	return 1;	// 1 represents ant object
}


/************************************************************
* Function: eat()
* Description: virtual function: does nothing in ant class
* Parameters: none
* Pre-Conditions: none
* Post-Conditions: none
* Return: none
**************************************************************/
void Ant::eat(Critter ***array, int i, int j) {}


/************************************************************
* Function: starve()
* Description: virtual function: does nothing in ant class
* Parameters: none
* Pre-Conditions: none
* Post-Conditions: none
* Return: none
**************************************************************/
void Ant::starve(Grid *gridPtr) {}
