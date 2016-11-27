/************************************************************************************************************
** Program Filename: CoachClassCar.cpp
** Author: Peter Moldenhauer
** Date: 11/25/16
** Assignment: Assignment 5 (Final Assignment)
** Description: This is the CoachClassCar class .cpp file for a text based adventure game. This class is a
** derived class from the Space class.
**************************************************************************************************************/

#include "CoachClassCar.h"

/*********************************************************************
** Function: CoachClassCar()
** Description: This is the class constructor that initializes the
** data member baby
*********************************************************************/
CoachClassCar::CoachClassCar(CryingBaby *b) : Space() {
    this->baby = b;
}

/*********************************************************************
** Function: lookAround()
** Description: This function tells the user what the character in
** the game is looking at in this specific space
*********************************************************************/
void CoachClassCar::lookAround() {
    std::string baby;
    if (this->baby->getCrying()) {
        baby = "crying baby";
    } else {
        baby = "happy baby";
    }
    std::cout << "You're in the coach class car. To you right is a snoring man,\n"
    << "to your left is a " << baby << ".\n";
}

/*********************************************************************
** Function: talk()
** Description: This function tells the user what the character in
** the game is saying in this specific space
*********************************************************************/
void CoachClassCar::talk() {
    std::cout << "See if you can talk to anyone next to you...\n";
}
