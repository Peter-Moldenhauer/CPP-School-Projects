/************************************************************************************************************
** Program Filename: SnoringSleeper.cpp
** Author: Peter Moldenhauer
** Date: 11/25/16
** Assignment: Assignment 5 (Final Assignment)
** Description: This is the SnoringSleeper class .cpp file for a text based adventure game. This class is a
** derived class from the Space class.
**************************************************************************************************************/

#include "SnoringSleeper.h"
#include "Character.h"

/*********************************************************************
** Function: lookAround()
** Description: This function tells the user what the character in
** the game is looking at in this specific space
*********************************************************************/
void SnoringSleeper::lookAround() {
    std::cout << "You're sitting next to a snoring sleeper.\n"
    << "I wonder if you could wake him?\n";
}

/*********************************************************************
** Function: talk()
** Description: This function tells the user what the character in
** the game is saying in this specific space
*********************************************************************/
void SnoringSleeper::talk() {
    if (this->awake) {
        std::cout << "SLEEPER: Gee! Thanks for waking me up. Sorry to hear about your phone!\n";
    } else {
        std::cout << "YOU: Hey are you awake...\n";
        std::cout << "SLEEPER: ZZZZZZ...sooo tired...ZZZZ...need to wake up...\n";
    }
}

/*********************************************************************
** Function: manipulate()
** Description: This function tells the user what the character in
** the game is manipulating in this specific area - this could be
** picking up or dropping items.
*********************************************************************/
void SnoringSleeper::manipulate() {
    if (this->character->objectSearch("Energy Drink")) {
        std::cout << "YOU: Here is an energy drink. It will help you wake up.\n";
        //sleep(1);
        std::cout << "SLEEPER: Boy I needed that! Thanks for the energy drink.\n";
        //sleep(1);
        std::cout << "Here's some candy. My doctor says I can't have sugar.";
        this->character->addObject("Candy");

    } else {
        std::cout << "SLEEPER: ZZZZ...need..energy drink...ZZZZ\n";
    }
}

/*********************************************************************
** Function: setAwake()
** Description: This function sets the data member awake
*********************************************************************/
void SnoringSleeper::setAwake(bool b) {
    this->awake = b;
}
