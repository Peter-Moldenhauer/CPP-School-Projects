/************************************************************************************************************
** Program Filename: EngineerSeat.cpp
** Author: Peter Moldenhauer
** Date: 11/25/16
** Assignment: Assignment 5 (Final Assignment)
** Description: This is the EngineerSeat class .cpp file for a text based adventure game. This class is a
** derived class from the Space class.
**************************************************************************************************************/

#include "EngineerSeat.h"
#include "Character.h"

/*********************************************************************
** Function: talk()
** Description: This function tells the user what the character in
** the game is saying in this specific space
*********************************************************************/
void EngineerSeat::talk() {
    std::cout << "ENGINEER: Hi there. I understand you lost your phone? Well, it might be in the "
    << "baggage car.\n";
    //sleep(1);
    std::cout << "Do you have the key?\n";
    //sleep(1);
    std::cout << "YOU: No...\n"
    << "ENGINEER: Well, if you can cheer up the conductor, maybe he'll give it to you.\n"
    << "He can't function without his coffee. Considering he's in charge of the train,\n"
    << "maybe you should give him some.";
}

/*********************************************************************
** Function: lookAround()
** Description: This function tells the user what the character in
** the game is looking at in this specific space
*********************************************************************/
void EngineerSeat::lookAround() {
    std::cout << "You're sitting with the Engineer. You should talk to him.\n";
}

/*********************************************************************
** Function: manipulate()
** Description: This function tells the user what the character in
** the game is manipulating in this specific area - this could be
** picking up or dropping items.
*********************************************************************/
void EngineerSeat::manipulate() {
    std::cout << "ENGINEER: Here's some coffee for the conductor. Go see if he wants it.";
    this->character->addObject("Coffee");
    //sleep(1);
    std::cout << "YOU: Thanks! Bye.\n";
}
