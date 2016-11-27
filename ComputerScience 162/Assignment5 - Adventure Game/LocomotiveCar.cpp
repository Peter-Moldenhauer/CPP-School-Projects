/************************************************************************************************************
** Program Filename: LocomotiveCar.cpp
** Author: Peter Moldenhauer
** Date: 11/25/16
** Assignment: Assignment 5 (Final Assignment)
** Description: This is the LocomotiveCar class .cpp file for a text based adventure game. This class is a
** derived class from the Space class.
**************************************************************************************************************/

#include "LocomotiveCar.h"
#include <unistd.h>

/*********************************************************************
** Function: LocomotiveCar()
** Description: This is the class constructor that initializes the
** Space class constructor data member requiresKey
*********************************************************************/
LocomotiveCar::LocomotiveCar() : Space() {
    this->requiresKey = true;
}

/*********************************************************************
** Function: lookAround()
** Description: This function tells the user what the character in
** the game is looking at in this specific space
*********************************************************************/
void LocomotiveCar::lookAround() {
    std::cout << "\nYou're in the locomotive cab of the train!\n";
    //sleep(1);
    std::cout << "The conductor is on your left and the engineer is on the right.\n"
    << "In front of you there's room to look out the front windshield.\n";
}

/*********************************************************************
** Function: talk()
** Description: This function tells the user what the character in
** the game is saying in this specific space
*********************************************************************/
void LocomotiveCar::talk() {
    std::cout << "\nYOU: Hi! Thanks for letting me up front.";
    //sleep(1);
    std::cout << "\nCONDUCTOR: Woah...how'd you get up here???";
    //sleep(1);
    std::cout << "\nENGINEER: Well, nice to have a visitor I guess...";
    //sleep(1);
    std::cout << "\nCONDUCTOR: I haven't had my coffee today. Grrr...";
    //sleep(1);
    std::cout << "\nENGINEER: Watch out for him, he's cranky right now. Come over here to the right and talk to me.";
}
