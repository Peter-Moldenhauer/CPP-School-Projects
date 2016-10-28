/*****************************************************************************************************************
** Program Filename: doodlebug.cpp
** Author: Peter Moldenhauer
** Date: 10/25/16
** Assignment: Lab 5
** Description: This is the doodlebug .cpp file for the doodlebug class that is used in the 2D predator-prey
** simulation program. The doodlebug class inherits from the critter class. This class contains virtual functions.
** Input: Inherits from the critter class
** Output: This class is used in the grid class to simulate a doodlebug moving, breeding, eating and starving
******************************************************************************************************************/

#include "doodlebug.h"

/**************************************************************
* Function: Doodlebug()
* Description: This is the doodlebug constructor
* Parameters: none
* Pre-Conditions: none
* Post-Conditions: moveNext is set, count is set
* Return: none
***************************************************************/
Doodlebug::Doodlebug() {
	moveNext = true;	// Sets object to be moved
	count = 0;			// object not moved yet
	stepsToBreed = 9;
	stepsAllowed = 4;  // 3 steps until doodlebug starves (1 + 3)
}

/*********************************************************************
* Function: init()
* Description: This function initializes a doodlebug on the array
* Parameters: x (int), y (int), pointer to grid object
* Pre-Conditions: none
* Post-Conditions: sets variables
* Return: none
**********************************************************************/
void Doodlebug::init(int x, int y, Grid *grid) {

	xCurrent = rand() % x;	// random doodlebug x location
	yCurrent = rand() % y;	// random doodlebug y location
	xMax = x;
	yMax = y;
	gridPtr = grid;
	starveSteps = 0;	// initialize starveSteps to 0
}

/*********************************************************************************
* Function: breed()
* Description: This function counts the number of times doodlebug moves and then
* adds a new doodlebug once it moves 8 times.
* Parameters: none
* Pre-Conditions: count and gridPtr need to be set
* Post-Conditions: adds a new doodlebug object if conditions are met
* Return: none
**********************************************************************************/
void Doodlebug::breed() {
	// 8 steps until a doodlebug breeds (8 + 1)
	//int stepsToBreed = 9;

	// Doodlebug will breed and not die
	if (count >= 0 && count == stepsToBreed) {
		// add a doodlebug to the cell to the left (if open)
		gridPtr->addNew(this);
		count = 0;  // reset count, don't starve
	}
}


/**********************************************************************************
* Function: move()
* Description: This function moves the ant. This function also calls the starve
* and breed functions based on the ant movement.
* Parameters: none
* Pre-Conditions: variables need to be set
* Post-Conditions: moves doodlebug object, resets variables
* Return: none
***********************************************************************************/
void Doodlebug::move(int m) {

    if (m == 0) {
    int movement = rand() % 4 + 1;	// can only move in 4 directions

    xPrevious = xCurrent;
    yPrevious = yCurrent;
    starveSteps += 1;

    switch (movement) {
    	case 1: if (yCurrent - 1 == -1 || yCurrent - 1 == yMax) {
				moveNext = false;
				starve(gridPtr);
			}
			else if (yCurrent - 1 > -1 || yCurrent - 1 < yMax) {
    			yCurrent -= 1;	// Up
    			moveNext = false;
    			count += 1;
    			breed();
    			starve(gridPtr);
			}
    		break;

		case 2: if (xCurrent + 1 == -1 || xCurrent + 1 == xMax) {
				moveNext = false;
				starve(gridPtr);
			}
			else if (xCurrent + 1 > -1 || xCurrent + 1 < xMax) {
    			xCurrent += 1;	// Right
    			moveNext = false;
    			count += 1;
    			breed();
    			starve(gridPtr);
			}
    		break;

		case 3: if (yCurrent + 1 == -1 || yCurrent + 1 == yMax) {
				moveNext = false;
				starve(gridPtr);
			}
			else if (yCurrent + 1 > -1 || yCurrent + 1 < yMax) {
    			yCurrent += 1;	// Down
    			moveNext = false;
    			count += 1;
    			breed();
    			starve(gridPtr);
			}
    		break;

		case 4: if (xCurrent - 1 == -1 || xCurrent - 1 == xMax) {
				moveNext = false;
				starve(gridPtr);
			}
			else if (xCurrent - 1 > -1 || xCurrent - 1 < xMax) {
    			xCurrent -= 1;	// Left
    			moveNext = false;
    			count += 1;
    			breed();
    			starve(gridPtr);
			}
    		break;
    }
    }


    else if (m == 1){
        xPrevious = xCurrent;
        yPrevious = yCurrent;
        starveSteps += 1;

        if (yCurrent - 1 == -1 || yCurrent - 1 == yMax) {
            moveNext = false;
            starve(gridPtr);
        }
        else if (yCurrent - 1 > -1 || yCurrent - 1 < yMax) {
            yCurrent -= 1;	// Up
            moveNext = false;
            count += 1;
            breed();
            starve(gridPtr);
        }
    }

    else if (m == 2){
        xPrevious = xCurrent;
        yPrevious = yCurrent;
        starveSteps += 1;

        if (xCurrent + 1 == -1 || xCurrent + 1 == xMax) {
            moveNext = false;
            starve(gridPtr);
        }
        else if (xCurrent + 1 > -1 || xCurrent + 1 < xMax) {
            xCurrent += 1;	// Right
            moveNext = false;
            count += 1;
            breed();
            starve(gridPtr);
        }
    }

    else if (m == 3){
        xPrevious = xCurrent;
        yPrevious = yCurrent;
        starveSteps += 1;

        if (yCurrent + 1 == -1 || yCurrent + 1 == yMax) {
            moveNext = false;
            starve(gridPtr);
        }
        else if (yCurrent + 1 > -1 || yCurrent + 1 < yMax) {
            yCurrent += 1;	// Down
            moveNext = false;
            count += 1;
            breed();
            starve(gridPtr);
        }
    }

    else if (m == 4){
        xPrevious = xCurrent;
        yPrevious = yCurrent;
        starveSteps += 1;

        if (xCurrent - 1 == -1 || xCurrent - 1 == xMax) {
            moveNext = false;
            starve(gridPtr);
        }
        else if (xCurrent - 1 > -1 || xCurrent - 1 < xMax) {
            xCurrent -= 1;	// Left
            moveNext = false;
            count += 1;
            breed();
            starve(gridPtr);
        }
    }


}

/*****************************************************
* Function: getType()
* Description: Check the type of object in the array
* Parameters: none
* Pre-Conditions: none
* Post-Conditions: none
* Return: 2 to represent a doodlebug object
******************************************************/
const int Doodlebug::getType() {
	return 2;	// 2 represents doodlebug object
}

/*******************************************************************************
* Function: starve()
* Description: This function counts how many steps the doodlebug has taken and
* then will delete the doodlebug if it has taken 3 steps.
* Parameters: pointer to a grid object
* Pre-Conditions: variables need to be set
* Post-Conditions: moves doodlebug object, resets variables
* Return: none
********************************************************************************/
void Doodlebug::starve(Grid *gridPtr) {

	//int stepsAllowed = 4;  // 3 steps until doodlebug starves (1 + 3)

	if (starveSteps == stepsAllowed) {
        //cout << "Doodlebug Die" << endl;
        gridPtr->remove(this);
	}
}

/*********************************************************************************
* Function: eat()
* Description: This function deletes an ant if doodlebug moves to ant location
* Parameters: critter array (the grid being used), i (int), j (int)
* Pre-Conditions: variables need to be set
* Post-Conditions: deletes ant object from array if conditions are met
* Return: none
**********************************************************************************/
void Doodlebug::eat(Critter ***array, int i, int j) {

	starveSteps = 0; 	// starve steps reset because an ant was eaten

	// Delete ant's dynamically allocated memory
	delete array[array[i][j]->yGet()][array[i][j]->xGet()];

    array[array[i][j]->yGet()][array[i][j]->xGet()] = array[i][j];

    array[i][j] = NULL;     // reset original position to NULL
}
