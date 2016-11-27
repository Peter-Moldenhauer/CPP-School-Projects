/************************************************************************************************************
** Program Filename: BradPitt.cpp
** Author: Peter Moldenhauer
** Date: 11/25/16
** Assignment: Assignment 5 (Final Assignment)
** Description: This is the BradPitt class .cpp file for a text based adventure game. This class is a
** derived class from the Space class.
**************************************************************************************************************/

#include "BradPitt.h"
#include "Character.h"

/*********************************************************************
** Function: BradPitt()
** Description: This is the class constructor that initializes the
** data member sad
*********************************************************************/
BradPitt::BradPitt() {
    this->sad = true;
}

/*********************************************************************
** Function: lookAround()
** Description: This function tells the user what the character in
** the game is looking at in this specific space
*********************************************************************/
void BradPitt::lookAround() {
    std::cout << "You're sitting next to Brad Pitt.\n"
    << "He looks sad.\n";
}

/*********************************************************************
** Function: talk()
** Description: This function tells the user what the character in
** the game is saying in this specific space
*********************************************************************/
void BradPitt::talk() {
    if (this->sad) {
        std::cout << "BRAD PITT: Hey! I heard you lost your phone. Thats too bad.\n"
        << "I'm sad too. After I broke up with Angelina Jolie I lost her phone number, and now I can't call her.\n";
        //sleep(1);
        //std::cout << ":'(\n";
    } else {
        std::cout << "BRAD PITT: Thanks for that number! I miss Angelina so much! Good luck finding your phone\n";
    }

}

/*********************************************************************
** Function: manipulate()
** Description: This function tells the user what the character in
** the game is manipulating in this specific area - this could be
** picking up or dropping items.
*********************************************************************/
void BradPitt::manipulate() {
    if (this->character->objectSearch("Angelina's number")) {
        this->sad = false;
        std::cout << "YOU: Angelina Jolie's number was posted on Twitter. Here it is...\n";
        std::cout << "BRAD PITT: Awesome! Now I can call Angelina! Thank you!\n";
        //sleep(1);
        std::cout << "By the way...the train attendant up front, her name is Sally in case you\n"
        << "need anything from her.";
        this->character->addObject("Name");
    } else {
        std::cout << "BRAD PITT: Do you have anything for me? No? Leave me alone so I can cry...\n";
    }
}
