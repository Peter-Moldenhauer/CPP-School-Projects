/*******************************************************************************************************************
** Program Filename: ForwardAttendantCar.cpp
** Author: Peter Moldenhauer
** Date: 11/25/16
** Assignment: Assignment 5 (Final Assignment)
** Description: This is the ForwardAttendantCar class .cpp file for a text based adventure game. This class is a
** derived class from the Space class.
*********************************************************************************************************************/

#include "ForwardAttendantCar.h"

/*********************************************************************
** Function: lookAround()
** Description: This function tells the user what the character in
** the game is looking at in this specific space
*********************************************************************/
void ForwardAttendantCar::lookAround() {
    std::cout << "You're in the front attendant car.\n";
    //sleep(1);
    std::cout << "To your left is the front restroom, to your right is the front galley.\n"
    << "There is a train attendant standing in the galley.\n";
}

/*********************************************************************
** Function: talk()
** Description: This function tells the user what the character in
** the game is saying in this specific space
*********************************************************************/
void ForwardAttendantCar::talk() {
    std::cout << "Nobody to talk to here, why not go left or right?\n";
}
