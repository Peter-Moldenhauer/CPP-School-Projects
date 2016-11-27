/************************************************************************************************************
** Program Filename: SnackStand.cpp
** Author: Peter Moldenhauer
** Date: 11/25/16
** Assignment: Assignment 5 (Final Assignment)
** Description: This is the SnackStand class .cpp file for a text based adventure game. This class is a
** derived class from the Space class.
**************************************************************************************************************/

#include "SnackStand.h"
#include "Character.h"

/*********************************************************************
** Function: lookAround()
** Description: This function tells the user what the character in
** the game is looking at in this specific space
*********************************************************************/
void SnackStand::lookAround() {
    std::cout << "You're next to the snack stand.\n";
    //sleep(1);
    std::cout << "There's a train attendant nearby to talk to. He looks friendly.\n";
}

/*********************************************************************
** Function: talk()
** Description: This function tells the user what the character in
** the game is saying in this specific space
*********************************************************************/
void SnackStand::talk() {
    if (this->character->getHasKey()) {
        std::cout << "TRAIN ATTENDANT: Oh, you're back! And I see you have the key to the baggage car.\n";
        //sleep(1);
        std::cout << "I've been hearing some funny sounds coming from there. Take this machine gun\n"
        << "to use for protection...just in case.\n";
        std::cout << "\n** Machine gun acquired **\n";
    } else {
        std::cout << "TRAIN ATTENDANT: Hi! I heard you lost your phone. That's too bad. I know there's a lost and found\n"
        << "back here somewhere...\n";
    }
}

/*********************************************************************
** Function: manipulate()
** Description: This function tells the user what the character in
** the game is manipulating in this specific area - this could be
** picking up or dropping items.
*********************************************************************/
void SnackStand::manipulate() {
    std::cout << "TRAIN ATTENDANT: Here, take this energy drink. Maybe you can use it while looking for your phone.";
    this->character->addObject("Energy Drink");
    //sleep(1);
    std::cout << "YOU: Thanks!\n";
}
