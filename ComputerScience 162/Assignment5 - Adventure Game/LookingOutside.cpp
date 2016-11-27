/************************************************************************************************************
** Program Filename: LookingOutside.cpp
** Author: Peter Moldenhauer
** Date: 11/25/16
** Assignment: Assignment 5 (Final Assignment)
** Description: This is the LookingOutside class .cpp file for a text based adventure game. This class is a
** derived class from the Space class.
**************************************************************************************************************/

#include "LookingOutside.h"
#include <unistd.h>

/*********************************************************************
** Function: lookAround()
** Description: This function tells the user what the character in
** the game is looking at in this specific space
*********************************************************************/
void LookingOutside::lookAround() {
    std::cout << "\nWhat a beautiful view.\n";
    //sleep(1);
    std::cout << "There doesn't seem to be anything here though.\n";
}

/*********************************************************************
** Function: talk()
** Description: This function tells the user what the character in
** the game is saying in this specific space
*********************************************************************/
void LookingOutside::talk() {
    std::cout << "\nNobody up here. Why not go back and talk to the conductor or the engineer?\n";
}
