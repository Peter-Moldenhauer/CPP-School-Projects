/*****************************************************************************************************************
** Program Filename: grid.cpp
** Author: Peter Moldenhauer
** Date: 10/25/16
** Assignment: Lab 5
** Description: This is the grid .cpp file for the grid class that is used in the 2D predator-prey simulation
** program. The grid class creates a 2D array of pointers to critter objects (either ant or doodlebug). The grid
** class updates the location of the critters on the grid for each time step as well as prints out the grid to the
** user.
** Input: Uses the ant and doodlebug classes to put critters on the grid
** Output: Prints the grid out to the user with all of the critter objects on the grid.
******************************************************************************************************************/

#include "grid.h"

/*******************************************************************
* Function: grid()
* Description: This function is a constructor for the Grid class.
* In this constructor, two other functions are called that
* create and initialize the grid.
* Parameters: x (int), y (int)
* Pre-Conditions: none
* Post-Conditions: variables set, creates grid, fills grid
* Return: none
********************************************************************/
Grid::Grid(int x, int y) {

    xMax = x;  // set x size of the grid
    yMax = y;  // set y size of the grid
    create();  // create grid
    fillGrid(); // fill the grid with NULL pointers
}


/***********************************************************************
* Function: ~grid()
* Description: This function is the destructor. In this function the
* memory is deallocated
* Parameters: none
* Pre-Conditions: none
* Post-Conditions: deletes 2D array to free up memory
* Return: none
************************************************************************/
Grid::~Grid() {
    //cout << "Grid destructor" << endl;
    for(int i = 0; i < yMax; i++)
        delete [] gridArray[i]; // delete the "inner array"
    delete [] gridArray; // delete the "outer array"
}


/*********************************************************************
* Function: create()
* Description: This function creates and initializes the grid
* Parameters: none
* Pre-Conditions: variables need to be set
* Post-Conditions: grid of pointers to critter objects is created
* Return: none
*********************************************************************/
void Grid::create() {

    // dynamically create the y axis critters
    gridArray = new Critter**[yMax];

    for(int i = 0; i < yMax; i++)
        // dynamically create the x axis critters
        gridArray[i] = new Critter*[xMax];
}


/***************************************************************
* Function: fillGrid()
* Description: This function fills the grid with NULL pointers
* Parameters: none
* Pre-Conditions: yMax and xMax have to be set
* Post-Conditions: grid is initialized with NULL pointers
* Return: none
****************************************************************/
void Grid::fillGrid() {
    for (int i = 0; i < yMax; i++){
        for (int j = 0; j < xMax; j++){
            gridArray[i][j] = NULL; // initializing array to be NULL pointers
        }
    }
}


/***********************************************************
* Function: printGrid()
* Description: This function prints the grid to the screen
* Parameters: none
* Pre-Conditions: variables need to be set
* Post-Conditions: prints the grid using symbols to the
* corresponding objects
* Return: none
************************************************************/
void Grid::printGrid() {
    char blank = 0x45;
    char ant = 0x4F;
    char doodle = 0x58;

    for(int i = 0; i < yMax; i++){
        for (int j = 0; j < xMax; j++){
            if (gridArray[i][j] == NULL)    // print background space when critter == NULL
                cout << " " << blank << " ";
            else if (gridArray[i][j]->getType() == 1)
                cout << " " << ant << " ";     // Ant object
            else if (gridArray[i][j]->getType() == 2)
                cout << " " << doodle << " ";     // Doodlebug object
        }
        cout << endl;
    }
    cout << endl;
}


/********************************************************************************
* Function: startLocation()
* Description: This function sets up the grid by creating the correct number of
* ants and doodlebugs and places them in random positions on the grid
* Parameters: andPop (int), doodlebugPop (int)
* Pre-Conditions: variables need to be set
* Post-Conditions: the grid is set up with the correct ants and doodlebugs
* Return: none
**********************************************************************************/
void Grid::startLocation(int antPop, int doodlebugPop) {

    int newCount = 0;
    for(int i = 0; i < yMax; i++) {
        for (int j = 0; j < xMax; j++) {
            if (newCount < antPop) {
                gridArray[i][j] = new Ant;
                gridArray[i][j]->init(xMax, yMax, this);
                newCount += 1;
            }
        }
    }

    // set the ant locations
    newCount = 0;
    for(int i = 0; i < yMax; i++) {
        for (int j = 0; j < xMax; j++) {
            if (gridArray[i][j] != NULL) {
                if (gridArray[gridArray[i][j]->yGet()][gridArray[i][j]->xGet()] == NULL) {
                    gridArray[gridArray[i][j]->yGet()][gridArray[i][j]->xGet()] = gridArray[i][j];
                    newCount += 1;
                    gridArray[i][j] = NULL;
                }
                else if (gridArray[gridArray[i][j]->yGet()][gridArray[i][j]->xGet()] != NULL) {
                    gridArray[i][j]->setYCurrent(i);
                    gridArray[i][j]->setXCurrent(j);
                }
            }
        }
    }

    newCount = 0;

    for(int i = 0; i < yMax; i++) {
        for (int j = 0; j < xMax; j++) {
            if (newCount < doodlebugPop) {
                gridArray[i][j] = new Doodlebug;
                gridArray[i][j]->init(xMax, yMax, this);
                newCount += 1;
            }
        }
    }

    // set the doodlebug locations
    newCount = 0;
    for(int i = 0; i < yMax; i++) {
        for (int j = 0; j < xMax; j++) {
            if (gridArray[i][j] != NULL) {
                if (gridArray[gridArray[i][j]->yGet()][gridArray[i][j]->xGet()] == NULL
                    && gridArray[i][j]->getType() == 2) {
                    gridArray[gridArray[i][j]->yGet()][gridArray[i][j]->xGet()] = gridArray[i][j];
                    newCount += 1;
                    gridArray[i][j] = NULL;
                }
                else if (gridArray[gridArray[i][j]->yGet()][gridArray[i][j]->xGet()] != NULL) {
                    gridArray[i][j]->setYCurrent(i);
                    gridArray[i][j]->setXCurrent(j);
                }
            }
        }
    }
}

/***********************************************************************************
* Function: updateLocation
* Description: This function updates the location of the ants and doodlebugs and
* uses the getMoveNext ant function to generate the move.
* Parameters: none
* Pre-Conditions: variables need to be set
* Post-Conditions: updates the location of ants and doodlebugs on grid
* Return: none
*************************************************************************************/
void Grid::updateLocation() {

    int moveStep = 0;

    for(int i = 0; i < yMax; i++){
        for (int j = 0; j < xMax; j++){
            // Check if element contains an object
            if (gridArray[i][j] == NULL) {
                // used for testing, ignore
            }
            else if (gridArray[i][j] != NULL && gridArray[i][j]->getMoveNext() == true && gridArray[i][j]->getType() == 2) {

                /*
                cout << "ERROR part below" << endl;
                //if (i == 0 || i == yMax - 1)
                    //moveStep = 0; // there is not an ant above or below doodlebug
                //if (j == 0 || j == xMax -1)
                    //moveStep = 0;  // there is not an ant to the left or right of doodlebug

                if (gridArray[(gridArray[i][j]->yGet())- 1][gridArray[i][j]->xGet()]->getType() == 1){
                    cout << "move up towards ant" << endl;
                    moveStep = 1; // move up towards ant
                }

                else if (gridArray[gridArray[i][j]->yGet()][(gridArray[i][j]->xGet())+ 1]->getType() == 1){
                    cout << "move right towards ant" << endl;
                    moveStep = 2; // move right towards ant
                }

                else if (gridArray[(gridArray[i][j]->yGet())+ 1][gridArray[i][j]->xGet()]->getType() == 1){
                    cout << "move down towards ant" << endl;
                    moveStep = 3; // move down towards ant
                }

                else if (gridArray[gridArray[i][j]->yGet()][(gridArray[i][j]->xGet())- 1]->getType() == 1){
                    cout << "move left towards ant" << endl;
                    moveStep = 4; // move left towards ant
                }

                cout << "Past error part" << endl;
                */

                gridArray[i][j]->move(moveStep); // move the object at this location
                if (gridArray[i][j] != NULL && gridArray[i][j]->xGet() > -1 && gridArray[i][j]->xGet() < xMax && gridArray[i][j]->yGet() > -1 && gridArray[i][j]->yGet() < yMax) {
                    if (gridArray[gridArray[i][j]->yGet()][gridArray[i][j]->xGet()] == NULL) {
                        // update ant position by setting pointer to old location
                        gridArray[gridArray[i][j]->yGet()][gridArray[i][j]->xGet()] = gridArray[i][j];
                        gridArray[i][j] = NULL;     // reset original positioin to NULL
                    }
                    // Check if an ant moves to a valid location
                    else if (gridArray[i][j]->getType() == 1 && gridArray[gridArray[i][j]->yGet()][gridArray[i][j]->xGet()] != NULL) {
                        gridArray[i][j]->setXCurrent(gridArray[i][j]->xPGet());
                        gridArray[i][j]->setYCurrent(gridArray[i][j]->yPGet());
                    }
                    // Check if a doodlebug moves onto an ant and eats
                    else if (gridArray[i][j]->getType() == 2 && gridArray[gridArray[i][j]->yGet()][gridArray[i][j]->xGet()] != NULL && gridArray[gridArray[i][j]->yGet()][gridArray[i][j]->xGet()]->getType() == 1) {
                        gridArray[i][j]->eat(gridArray, i, j);
                    }
                    // Check if an doodlebug moves to a valid location
                    else if (gridArray[i][j]->getType() == 2 && gridArray[gridArray[i][j]->yGet()][gridArray[i][j]->xGet()] != NULL && gridArray[gridArray[i][j]->yGet()][gridArray[i][j]->xGet()]->getType() == 2) {
                        gridArray[i][j]->setXCurrent(gridArray[i][j]->xPGet());
                        gridArray[i][j]->setYCurrent(gridArray[i][j]->yPGet());
                    }
                }
            }
        moveStep = 0;
        }
    moveStep = 0;
    }

    for(int i = 0; i < yMax; i++){
        for (int j = 0; j < xMax; j++){
            // Check if element contains an object
            if (gridArray[i][j] == NULL) {
                // used for testing, ignore
            }
            else if (gridArray[i][j] != NULL && gridArray[i][j]->getMoveNext() == true && gridArray[i][j]->getType() == 1) {
                gridArray[i][j]->move(moveStep); // move the object at this location
                if (gridArray[i][j] != NULL && gridArray[i][j]->xGet() > -1 && gridArray[i][j]->xGet() < xMax && gridArray[i][j]->yGet() > -1 && gridArray[i][j]->yGet() < yMax) {
                    if (gridArray[gridArray[i][j]->yGet()][gridArray[i][j]->xGet()] == NULL) {
                        // update ant position by setting pointer to old location
                        gridArray[gridArray[i][j]->yGet()][gridArray[i][j]->xGet()] = gridArray[i][j];
                        gridArray[i][j] = NULL;     // reset original positioin to NULL
                    }
                    // Check if an ant moves to a valid location
                    else if (gridArray[i][j]->getType() == 1 && gridArray[gridArray[i][j]->yGet()][gridArray[i][j]->xGet()] != NULL) {
                        gridArray[i][j]->setXCurrent(gridArray[i][j]->xPGet());
                        gridArray[i][j]->setYCurrent(gridArray[i][j]->yPGet());
                    }
                    // Check if a doodlebug moves onto an ant and eats
                    else if (gridArray[i][j]->getType() == 2 && gridArray[gridArray[i][j]->yGet()][gridArray[i][j]->xGet()] != NULL && gridArray[gridArray[i][j]->yGet()][gridArray[i][j]->xGet()]->getType() == 1) {
                        gridArray[i][j]->eat(gridArray, i, j);
                    }
                    // Check if an doodlebug moves to a valid location
                    else if (gridArray[i][j]->getType() == 2 && gridArray[gridArray[i][j]->yGet()][gridArray[i][j]->xGet()] != NULL && gridArray[gridArray[i][j]->yGet()][gridArray[i][j]->xGet()]->getType() == 2) {
                        gridArray[i][j]->setXCurrent(gridArray[i][j]->xPGet());
                        gridArray[i][j]->setYCurrent(gridArray[i][j]->yPGet());
                    }
                }
            }
        }
    }

    resetMoveNext();  // reset move
    moveStep = 0;
}


/*********************************************************************
* Function: addNew()
* Description: This function adds a new Ant or Doodlebug to the grid
* Parameters: pointer to a critter object
* Pre-Conditions: variables need to be set
* Post-Conditions: adds a new ant or doodlebug if conditions are met
* Return: none
**********************************************************************/
void Grid::addNew(Critter *critterPtr) {
    // check if the cell to the left is null. If it is then add to the array with a new object
    if (critterPtr->xGet() - 1 <= -1) {
        //cout << "New critter is outside of allowable area and not created." << endl;
    }

    else {
        // Create an Ant object
        if (gridArray[critterPtr->yGet()][critterPtr->xGet() - 1] == NULL && critterPtr->xGet() - 1 > -1 && critterPtr->getType() == 1) {
            //cout << "Ant created" << endl;

            // Establish new ant and points empty grid cell pointer to it
            gridArray[critterPtr->yGet()][critterPtr->xGet() - 1] = new Ant;

            // Edit new ant to contain new information
            gridArray[critterPtr->yGet()][critterPtr->xGet() - 1]->init(xMax, yMax, this);

            gridArray[critterPtr->yGet()][critterPtr->xGet() - 1]->setXCurrent(critterPtr->xGet() - 1);

            gridArray[critterPtr->yGet()][critterPtr->xGet() - 1]->setYCurrent(critterPtr->yGet());
        }
        // Do not create an Ant on a filled location
        else if (gridArray[critterPtr->yGet()][critterPtr->xGet() - 1] != NULL && critterPtr->xGet() - 1 > -1 && critterPtr->getType() == 1) {
            //cout << "Ant cannot be created in a filled location" << endl;
        }

        // Create a Doodlebug
        else if (gridArray[critterPtr->yGet()][critterPtr->xGet() - 1] == NULL && critterPtr->getType() == 2) {
            //cout << "Doodlebug created" << endl;

            // Establish new doodlebug and points empty grid cell pointer to it
            gridArray[critterPtr->yGet()][critterPtr->xGet() - 1] = new Doodlebug;

            // Edit new doodlebug to contain new information
            gridArray[critterPtr->yGet()][critterPtr->xGet() - 1]->init(xMax, yMax, this);

            gridArray[critterPtr->yGet()][critterPtr->xGet() - 1]->setXCurrent(critterPtr->xGet() - 1);

            gridArray[critterPtr->yGet()][critterPtr->xGet() - 1]->setYCurrent(critterPtr->yGet());
        }

        // Doodlebug can breed over an Ant
        else if (gridArray[critterPtr->yGet()][critterPtr->xGet() - 1] != NULL && gridArray[critterPtr->yGet()][critterPtr->xGet() - 1]->getType() == 1 && critterPtr->getType() == 2) {
            //cout << "Doodlebug to be created" << endl;

            // Establish new doodlebug and points empty grid cell pointer to it
            gridArray[critterPtr->yGet()][critterPtr->xGet() - 1] = new Doodlebug;

            // Edits new doodlebug to contain new information
            gridArray[critterPtr->yGet()][critterPtr->xGet() - 1]->init(xMax, yMax, this);

            gridArray[critterPtr->yGet()][critterPtr->xGet() - 1]->setXCurrent(critterPtr->xGet() - 1);

            gridArray[critterPtr->yGet()][critterPtr->xGet() - 1]->setYCurrent(critterPtr->yGet());
        }

        // Doodlebug cannot breed over a Doodlebug
        else if (gridArray[critterPtr->yGet()][critterPtr->xGet() - 1] != NULL && gridArray[critterPtr->yGet()][critterPtr->xGet() - 1]->getType() == 2 && critterPtr->getType() == 2) {
            //cout << "Doodlebug cannot breed over a Doodlebug" << endl;
        }
        else {
        //cout << "Error, addNew() failed.
        }
    }
}


/********************************************************************************
* Function: remove()
* Description: This function deletes a doodlebug from the array when it starves
* Parameters: pointer to a critter object
* Pre-Conditions: array needs to be initialized
* Post-Conditions: critter object is removed
* Return: none
**********************************************************************************/
void Grid::remove(Critter *critterPtr) {
    delete gridArray[critterPtr->yPGet()][critterPtr->xPGet()];

    gridArray[critterPtr->yPGet()][critterPtr->xPGet()] = NULL;
}


/************************************************************************************
* Function: resetMoveNext()
* Description: This function resets grid pointer flag to allow movement on next loop
* Parameters: none
* Pre-Conditions: array and variables need to be initialized
* Post-Conditions: resets bool variable
* Return: none
*************************************************************************************/
void Grid::resetMoveNext() {
    for(int i = 0; i < yMax; i++){
        for (int j = 0; j < xMax; j++){
            if (gridArray[i][j] != NULL)
                gridArray[i][j]->setMoveNextTrue();
        }
    }
}


/**************************************************
* Function: getXMax()
* Description: This function returns grid size x
* Parameters: none
* Pre-Conditions: variables need to be set
* Post-Conditions: none
* Return: xMax
***************************************************/
int Grid::getXMax() {
    return xMax;
}


/**************************************************
* Function: getYMax()
* Description: This function returns grid size y
* Parameters: none
* Pre-Conditions: variables need to be set
* Post-Conditions: none
* Return: yMax
***************************************************/
int Grid::getYMax() {
    return yMax;
}
