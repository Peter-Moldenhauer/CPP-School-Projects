/************************************************************************************************************
** Program Filename: BackRestroom.cpp
** Author: Peter Moldenhauer
** Date: 11/25/16
** Assignment: Assignment 5 (Final Assignment)
** Description: This is the BackRestroom class .cpp file for a text based adventure game. This class is a
** derived class from the Space class.
**************************************************************************************************************/

#include "BackRestroom.h"

/*********************************************************************
** Function: lookAround()
** Description: This function tells the user what the character in
** the game is looking at in this specific space
*********************************************************************/
void BackRestroom::lookAround() {
    std::cout << "You're in the back restroom of a train feeling sad about losing\n"
    << "your new iPhone. It must be on this train somewhere!\n";
    //sleep(1);
    std::cout << "There doesn't seem to be anything useful in\n"
    << "the restroom (this is your starting point). The exit is to the right.\n";
}

/*********************************************************************
** Function: talk()
** Description: This function tells the user what the character in
** the game is saying in this specific space
*********************************************************************/
void BackRestroom::talk() {
    std::cout << "Why not exit the restroom and look around?\n";
}
