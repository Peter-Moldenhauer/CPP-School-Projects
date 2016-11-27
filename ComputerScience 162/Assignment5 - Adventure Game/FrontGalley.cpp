/************************************************************************************************************
** Program Filename: FrontGalley.cpp
** Author: Peter Moldenhauer
** Date: 11/25/16
** Assignment: Assignment 5 (Final Assignment)
** Description: This is the FrontGalley class .cpp file for a text based adventure game. This class is a
** derived class from the Space class.
**************************************************************************************************************/

#include "FrontGalley.h"
#include "Character.h"

/*********************************************************************
** Function: lookAround()
** Description: This function tells the user what the character in
** the game is looking at in this specific space
*********************************************************************/
void FrontGalley::lookAround() {
    std::cout << "You're in the front galley. There's a train attendant here to talk to.\n";
}

/*********************************************************************
** Function: talk()
** Description: This function tells the user what the character in
** the game is saying in this specific space
*********************************************************************/
void FrontGalley::talk() {
    std::cout << "TRAIN ATTENDANT: Hi there! So, you lost your phone?\n";
    //sleep(1);
    std::cout << "I think the Conductor has a key to the baggage car..."
    << "maybe it's there?\n";
    //sleep(1);
    std::cout << "You need to know the secret knock to get into the locomotive cab.\n"
    << "Do you have anything for me? *wink* *wink*\n";
}

/*********************************************************************
** Function: manipulate()
** Description: This function tells the user what the character in
** the game is manipulating in this specific area - this could be
** picking up or dropping items.
*********************************************************************/
void FrontGalley::manipulate() {
    if (this->character->objectSearch("Autograph")) {
        std::cout << "YOU: Donald Trump gave me his autograph to give to you. Here it is...\n";
        std::cout << "TRAIN ATTENDANT: Oh, yay! I was hoping I could get his autograph. My friends will be so jealous.\n";
        //sleep(1);
        std::cout << "Since you've been such a big help, I'll help you get into the locomotive cab.\n";
        //sleep(1);
        std::cout << "I don't remember the knock, but it's written behind a secret panel in the\n"
        << "front restroom. Here's a key to open it...";
        this->character->addObject("Restroom Key");
    }else {
        std::cout << "TRAIN ATTENDANT: I can't believe that Donald Trump is on the train. My friends will never believe me...\n";
    }
}
