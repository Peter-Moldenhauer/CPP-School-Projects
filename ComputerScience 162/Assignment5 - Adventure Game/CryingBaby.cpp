/************************************************************************************************************
** Program Filename: CryingBaby.cpp
** Author: Peter Moldenhauer
** Date: 11/25/16
** Assignment: Assignment 5 (Final Assignment)
** Description: This is the CryingBaby class .cpp file for a text based adventure game. This class is a
** derived class from the Space class.
**************************************************************************************************************/

#include "CryingBaby.h"
#include "Character.h"

/*********************************************************************
** Function: CryingBaby()
** Description: This is the class constructor that initializes the
** data member crying
*********************************************************************/
CryingBaby::CryingBaby() {
    this->crying = true;
}

/*********************************************************************
** Function: setCrying()
** Description: This function sets the data member crying to true or
** false
*********************************************************************/
void CryingBaby::setCrying(bool b) {
    this->crying = b;
}

/*********************************************************************
** Function: getCrying()
** Description: This function returns the data member crying
*********************************************************************/
bool CryingBaby::getCrying() {
    return this->crying;
}

/*********************************************************************
** Function: lookAround()
** Description: This function tells the user what the character in
** the game is looking at in this specific space
*********************************************************************/
void CryingBaby::lookAround() {
    std::string baby;
    if (this->getCrying()) {
        baby = "crying baby";
    } else {
        baby = "happy baby";
    }
    std::cout << "You're sitting next to a " << baby << " and her sister.\n";
}

/*********************************************************************
** Function: talk()
** Description: This function tells the user what the character in
** the game is saying in this specific space
*********************************************************************/
void CryingBaby::talk() {
    std::cout << "\nSISTER: OMG! I can't seem to get him to stop crying!\n";
    //sleep(1);
    std::cout << "He LOVES candy. *LOL*\n";
    std::cout << "Can you help me?\n";
}

/*********************************************************************
** Function: manipulate()
** Description: This function tells the user what the character in
** the game is manipulating in this specific area - this could be
** picking up or dropping items.
*********************************************************************/
void CryingBaby::manipulate() {
    if (this->character->objectSearch("Candy")) {
        this->setCrying(false);
        std::cout << "YOU: Here is some candy for the baby...\n";
        std::cout << "SISTER: Yay!! Thanks for the candy. I know he'll stop crying now.\n";
        //sleep(1);
        std::cout << "(baby stops crying)\n";
        //sleep(1);
        std::cout << "SISTER: LOOK!!..Someone just posed Angelina Jolie's phone number "
        << "on Twitter!\n";
        //sleep(1);
        std::cout << "I heard Brad Pitt is sitting up front in first class. I wonder if he knows about this...\n";
        std::cout << "Here is her phone number...";
        this->character->addObject("Angelina's number");
    } else {
        std::cout << "YOU: I'll sing to the baby, maybe that will help...\n";
        std::cout << "SISTER: Nope..he's still crying. If only I had some candy...\n";
    }
}
