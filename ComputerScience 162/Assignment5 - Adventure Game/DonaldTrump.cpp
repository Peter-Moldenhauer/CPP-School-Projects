/************************************************************************************************************
** Program Filename: DonaldTrump.cpp
** Author: Peter Moldenhauer
** Date: 11/25/16
** Assignment: Assignment 5 (Final Assignment)
** Description: This is the DonaldTrump class .cpp file for a text based adventure game. This class is a
** derived class from the Space class.
**************************************************************************************************************/

#include "DonaldTrump.h"
#include "Character.h"

/*********************************************************************
** Function: lookAround()
** Description: This function tells the user what the character in
** the game is looking at in this specific space
*********************************************************************/
void DonaldTrump::lookAround() {
    std::cout << "You're sitting next to Donald Trump. His hair looks fake.\n";
}

/*********************************************************************
** Function: talk()
** Description: This function tells the user what the character in
** the game is saying in this specific space
*********************************************************************/
void DonaldTrump::talk() {
    std::cout << "DONALD TRUMP: You lost your phone?? If you were my employee you would be fired!\n"
    << "When you find your phone you should build a wall around it to keep it safe!!\n";
    //sleep(1);
    std::cout << "That train attendant up front wants my autograph, but I forgot her name...\n";
}

/*********************************************************************
** Function: manipulate()
** Description: This function tells the user what the character in
** the game is manipulating in this specific area - this could be
** picking up or dropping items.
*********************************************************************/
void DonaldTrump::manipulate() {
    if (this->character->objectSearch("Name")) {
        std::cout << "YOU: The attendant's name up front is Sally.\n";
        std::cout << "DONALD TRUMP: Outstanding. Here's an autograph for Sally. Can you give it to her?";
        this->character->addObject("Autograph");
    } else {
        std::cout << "DONALD TRUMP: If only I knew that attendant's name, I could give her that autograph.\n"
        << "I wonder if anyone nearby knows it...\n";
    }
}
