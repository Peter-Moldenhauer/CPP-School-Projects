/************************************************************************************************************
** Program Filename: ConductorSeat.cpp
** Author: Peter Moldenhauer
** Date: 11/25/16
** Assignment: Assignment 5 (Final Assignment)
** Description: This is the ConductorSeat class .cpp file for a text based adventure game. This class is a
** derived class from the Space class.
**************************************************************************************************************/

#include "ConductorSeat.h"
#include "Character.h"

/*********************************************************************
** Function: ConductorSeat()
** Description: This is the class constructor that initializes the
** data member hasCoffee
*********************************************************************/
ConductorSeat::ConductorSeat() : Space() {
    this->hasCoffee = false;
}

/*********************************************************************
** Function: lookAround()
** Description: This function tells the user what the character in
** the game is looking at in this specific space
*********************************************************************/
void ConductorSeat::lookAround() {
    if (hasCoffee) {
        std::cout << "You're sitting with the Conductor. He doesn't look so grumpy any more.\n"
        << "What's that shiny thing poking out of his coat pocket?\n";
    } else {
        std::cout << "You're sitting with the Conductor. He looks grumpy.\n";
    }
}

/*********************************************************************
** Function: talk()
** Description: This function tells the user what the character in
** the game is saying in this specific space
*********************************************************************/
void ConductorSeat::talk() {
    if (hasCoffee) {
        std::cout << "CONDUCTOR: Hello there. I'm feeling much better now that I've had my coffee.\n";
        //sleep(1);
        std::cout << "So, you're looking for your phone, eh?\n";
        //sleep(1);
        std::cout << "Did you know that the baggage car is at the back of the train?\n"
        << "Maybe it's in there.\n";
        //sleep(1);
    } else {
        std::cout << "CONDUCTOR: *Grumble* Don't talk to me...I haven't had my coffee today...\n";
    }
}

/*********************************************************************
** Function: manipulate()
** Description: This function tells the user what the character in
** the game is manipulating in this specific area - this could be
** picking up or dropping items.
*********************************************************************/
void ConductorSeat::manipulate() {
    if (this->character->objectSearch("Coffee")) {
        std::cout << "YOU: I have some coffee for you. Here you go...\n";
        std::cout << "CONDUCTOR: Gee! Thanks! I needed that.\n";
        //sleep(1);
        std::cout << "So, you lost your phone? Well, it's probably in "
        << "the lost and found area in the baggage car.\n"
        << "Here's the key to get in the baggage car.\n";
        std::cout << "\n** Baggage Car Key acquired **\n";
        this->character->setHasKey(true);
    } else {
        std::cout << "CONDUCTOR: Huh? I don't want any of your stuff. Leave me alone!\n";
    }
}
