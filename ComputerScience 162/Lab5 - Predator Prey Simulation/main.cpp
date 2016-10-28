/************************************************************************************************************
** Program Filename: main.cpp
** Author: Peter Moldenhauer
** Date: 10/25/16
** Assignment: Lab 5
** Description: This is the main.cpp file for a program demonstrates a 2D predator-prey simulation. The preys
** are ants and the predators are doodlebugs. The critters live in a 20*20 gird of cells. Only one critter may
** occupy a cell at a time. The grid is enclosed and no critter may move off the grid. Time is simulated in
** steps. Each critter performs some action every time step.
** Input: User inputs number of time steps, ant population, doodlebug population and grid size
** Output: Program outputs the starting grid and the grid display after each time step.
**************************************************************************************************************/

#include "grid.h"
#include "doodlebug.h"
#include "ant.h"
#include <iostream>
#include <unistd.h>  // for NULL
using namespace std;

int getSteps(); // This function gets and validates the number of time steps to use
int getRows(); // This function gets and validates the size of the grid rows
int getColumns(); // This function gets and validates the size of the grid columns
int getAnts(); // This function gets and validates the number of starting ants
int getDoodlebugs(); // This function gets and validates the number of starting doodlebugs
void moveCritters(int numMoves, Grid* grid);  // This function simulates the ants and doodlebugs moving around on the grid

int main() {
    srand(time(NULL)); // seed random number generator
    bool again = true;
    char runAgain;

    cout << "\n\t***  2D Predator-Prey Simulation ***" << endl;
    cout << "\t\tby: Peter Moldenhauer\n" << endl;
    cout << "  Extra Credit: Additional prompts to user for size \n of grid rows, columns, number of ants and doodlebugs \n" << endl;

    int xGridSize, yGridSize, antPop, doodlebugPop, numMoves; // variables for user input

    Grid* gridPtr; // pointer to the grid object used in the program

    while (again == true){

    // Get the size of the grid rows
    xGridSize = getRows();

    // Get the size of the grid columns
    yGridSize = getColumns();

    // Get the number of starting ants
    antPop = getAnts();

    // Get the number of starting doodlebugs
    doodlebugPop = getDoodlebugs();

    // Get number of time steps from the user
    numMoves = getSteps();

    // Create the grid
    Grid grid(xGridSize, yGridSize);  // create grid object of appropriate size
    gridPtr = &grid;  // this grid pointer points to the grid object just created that holds all of the ants and doodlebugs

    // set up the grid with the correct number of ants and doodlebugs
    grid.startLocation(antPop, doodlebugPop);

    cout << "Starting location of ants and doodlebugs on the grid...\n";

    // Display grid before loop starts
    grid.printGrid();

    // start simulation
    moveCritters(numMoves, gridPtr);

    //reset grid pointer
    gridPtr = NULL;

    // prompt user to see if the simulation should run again
    cout << "Would you like to run this simulation again? [Y/N]: ";
    cin >> runAgain;
    cout << endl;

    if (runAgain == 'Y' || runAgain == 'y')
        again = true;
    else
        again = false;
    }
    cout << "Goodbye!" << endl;

    return 0;
}

/***********************************************************************************************
* Function: getSteps()
* Description: This function prompts user for the number of time steps and validates the input
* Parameters: none
* Pre-Conditions: none
* Post-Conditions: none
* Return: userInput (int)
*************************************************************************************************/
int getSteps(){
    bool getData = true;
    int userInput;

    while (getData == true){
        cout << "Please enter the number of time-steps to run: ";
        cin >> userInput;
        if (userInput > 0){
            cout << endl;
            getData = false;
        }else{
            cout << "Invalid input! Enter an integer that is greater than 0." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
    return userInput;
}


/*********************************************************************************************
* Function: getRows()
* Description: This function prompts user for the size of grid rows and validates the input
* Parameters: none
* Pre-Conditions: none
* Post-Conditions: none
* Return: userInput (int)
**********************************************************************************************/
int getRows(){
    bool getData = true;
    int userInput;

    while (getData == true){
        cout << "Please enter the size of the grid rows: ";
        cin >> userInput;
        if (userInput > 0){
            getData = false;
        }else{
            cout << "Invalid input! Enter an integer that is greater than 0." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
    return userInput;
}


/**********************************************************************************************
* Function: getColumns
* Description: This function prompts user for the size of grid columns and validates the input
* Parameters: none
* Pre-Conditions: none
* Post-Conditions: none
* Return: userInput (int)
*************************************************************************************************/
int getColumns(){
    bool getData = true;
    int userInput;

    while (getData == true){
        cout << "Please enter the size of the grid columns: ";
        cin >> userInput;
        if (userInput > 0){
            getData = false;
        }else{
            cout << "Invalid input! Enter an integer that is greater than 0." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
    return userInput;
}


/******************************************************************************************
* Function: getAnts
* Description: This function prompts user for the number of ants and validates the input
* Parameters: none
* Pre-Conditions: none
* Post-Conditions: none
* Return: userInput (int)
*******************************************************************************************/
int getAnts(){
    bool getData = true;
    int userInput;

    while (getData == true){
        cout << "Please enter the number of ants to start with: ";
        cin >> userInput;
        if (userInput > -1){
            getData = false;
        }else{
            cout << "Invalid input! Enter an integer that is greater than or equal to 0." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
    return userInput;
}


/***********************************************************************************************
* Function: getDoodlebugs()
* Description: This function prompts user for the number of doodlebugs and validates the input
* Parameters: none
* Pre-Conditions: none
* Post-Conditions: none
* Return: userInput (int)
************************************************************************************************/
int getDoodlebugs(){
    bool getData = true;
    int userInput;

    while (getData == true){
        cout << "Please enter the number of doodlebugs to start with: ";
        cin >> userInput;
        if (userInput > -1){
            getData = false;
        }else{
            cout << "Invalid input! Enter an integer that is greater than or equal to 0." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
    return userInput;
}


/**********************************************************************************
* Function: moveCritters()
* Description: This function is responsible for the simulation of the ants and
* doodlebugs moving around on the grid.
* Parameters: numMoves (int), pointer to a grid object
* Pre-Conditions: variables need to be initialized
* Post-Conditions: simulation, print grid
* Return: none
***********************************************************************************/
void moveCritters(int numMoves, Grid *grid){

    bool keepPlaying = true;
    int count = 1;
    while (keepPlaying == true) {
        grid->updateLocation();

        cout << "Time step number: " << count << " of " << numMoves << endl;
        grid->printGrid();

        if (count == numMoves)
            keepPlaying = false;
        count += 1;
    }
}

