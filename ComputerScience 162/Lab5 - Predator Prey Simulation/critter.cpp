/*****************************************************************************************************************
** Program Filename: critter.cpp
** Author: Peter Moldenhauer
** Date: 10/25/16
** Assignment: Lab 5
** Description: This is the critter .cpp file for the critter class that is used in the 2D predator-prey
** simulation program. The critter class is an abstract class because it contains pure virtual functions.
** Input: None
** Output: This is the base class that gets inherited by the ant and doodlebug classes to be used in the program
******************************************************************************************************************/

#include "critter.h"
#include "grid.h"

/**********************************************
* Function: ~Critter()
* Description: destructor for the critter class
* Parameters: none
* Pre-Conditions: none
* Post-Conditions: none
* Return: none
***********************************************/
Critter::~Critter() {
}

/**************************************************************
* Function: xGet()
* Description: get current location of critter on x axis
* Parameters: none
* Pre-Conditions: xCurrent needs to be set
* Post-Conditions: none
* Return: xCurrent
****************************************************************/
const int Critter::xGet() {
	return xCurrent;
}

/*****************************************************************
* Function: yGet
* Description: get current location of critter on y axis
* Parameters: none
* Pre-Conditions: yCurrent needs to be set
* Post-Conditions: none
* Return: yCurrent
*****************************************************************/
const int Critter::yGet() {
	return yCurrent;
}

/************************************************************
* Function: xPGet
* Description: previous location of critter on x axis
* Parameters: none
* Pre-Conditions: XPrevious needs to be set
* Post-Conditions: none
* Return: xPrevious
*************************************************************/
const int Critter::xPGet() {
	return xPrevious;
}

/*********************************************************
* Function: yPGet()
* Description: previous location of critter on y axis
* Parameters: none
* Pre-Conditions: yPrevious needs to be set
* Post-Conditions: none
* Return: yPrevious
**********************************************************/
const int Critter::yPGet() {
	return yPrevious;
}

/*********************************************************
* Function: getMoveNext()
* Description: return if next move is true or false
* Parameters: none
* Pre-Conditions: moveNext needs to be set
* Post-Conditions: none
* Return: moveNext (bool)
**********************************************************/
const bool Critter::getMoveNext() {
	return moveNext;
}

/********************************************************
* Function: setMoveNextTrue()
* Description: set the next move to true
* Parameters: none
* Pre-Conditions: none
* Post-Conditions: moveNext set to true
* Return: none
*********************************************************/
void Critter::setMoveNextTrue() {
	moveNext = true;
}

/***************************************************
* Function: setMoveNextFalse()
* Description: set the next move to false
* Parameters: none
* Pre-Conditions: none
* Post-Conditions: moveNext set to false
* Return: none
****************************************************/
void Critter::setMoveNextFalse() {
	moveNext = false;
}

/*****************************************************
* Function: setXCurrent()
* Description: set current location on x axis
* Parameters: x (int)
* Pre-Conditions: none
* Post-Conditions: xCurrent is set
* Return: none
******************************************************/
void Critter::setXCurrent(int x) {
	xCurrent = x;
}

/********************************************************
* Function: setYCurrent()
* Description: set current location on y axis
* Parameters: y (int)
* Pre-Conditions: none
* Post-Conditions: yCurrent is set
* Return: none
*********************************************************/
void Critter::setYCurrent(int y) {
	yCurrent = y;
}
