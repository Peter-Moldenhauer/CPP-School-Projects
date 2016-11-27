/************************************************************************************************************
** Program Filename: FirstClassCar.cpp
** Author: Peter Moldenhauer
** Date: 11/25/16
** Assignment: Assignment 5 (Final Assignment)
** Description: This is the FirstClassCar class .cpp file for a text based adventure game. This class is a
** derived class from the Space class.
**************************************************************************************************************/

#include "FirstClassCar.h"

/*********************************************************************
** Function: lookAround()
** Description: This function tells the user what the character in
** the game is looking at in this specific space
*********************************************************************/
void FirstClassCar::lookAround() {
    std::cout << "You're in the first class train car. Donald Trump is\n"
    << "sitting to your left, and Brad Pitt is sitting on your right.";
}

/*********************************************************************
** Function: talk()
** Description: This function tells the user what the character in
** the game is saying in this specific space
*********************************************************************/
void FirstClassCar::talk() {
    std::cout << "You can talk to the people on your left and right...\n";
}
