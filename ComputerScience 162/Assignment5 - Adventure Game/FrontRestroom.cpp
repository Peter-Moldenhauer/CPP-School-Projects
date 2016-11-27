/************************************************************************************************************
** Program Filename: FrontRestroom.cpp
** Author: Peter Moldenhauer
** Date: 11/25/16
** Assignment: Assignment 5 (Final Assignment)
** Description: This is the FrontRestroom class .cpp file for a text based adventure game. This class is a
** derived class from the Space class.
**************************************************************************************************************/

#include "FrontRestroom.h"
#include "Character.h"

/*********************************************************************
** Function: lookAround()
** Description: This function tells the user what the character in
** the game is looking at in this specific space
*********************************************************************/
void FrontRestroom::lookAround() {
    std::cout << "You're in a small and smelly train restroom.\n";
    //sleep(1);
    std::cout << "There's a discolored panel next to the toilet.\n"
    << "I wonder if there's anything in there?\n";
}

/*********************************************************************
** Function: manipulate()
** Description: This function tells the user what the character in
** the game is manipulating in this specific area - this could be
** picking up or dropping items.
*********************************************************************/
void FrontRestroom::manipulate() {
    if (this->character->objectSearch("Restroom Key")) {
        std::cout << "You've opened the panel to reveal instructions for the\n"
        << "secret knock. Now you can enter the locomotive cab!\n";
        std::cout << "\n** Secret knock instructions acquired **\n";
        this->character->setHasCKey(true);
    } else {
        std::cout << "Hmm...it doesn't seem to open, but there's a small key hole\n"
        << "on the front. Maybe you need a key?\n";
    }
}

/*********************************************************************
** Function: talk()
** Description: This function tells the user what the character in
** the game is saying in this specific space
*********************************************************************/
void FrontRestroom::talk() {
    std::cout << "Nobody to talk to, but you might be able to do something else here...\n";
}
