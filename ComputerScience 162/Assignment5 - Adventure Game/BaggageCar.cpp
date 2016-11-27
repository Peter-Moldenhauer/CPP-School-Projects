/************************************************************************************************************
** Program Filename: BaggageCar.cpp
** Author: Peter Moldenhauer
** Date: 11/25/16
** Assignment: Assignment 5 (Final Assignment)
** Description: This is the BaggageCar class .cpp file for a text based adventure game. This class is a
** derived class from the Space class.
**************************************************************************************************************/

#include "BaggageCar.h"

/*********************************************************************
** Function: BaggageCar()
** Description: This is the class constructor that initializes the
** Space data member requiresKey
*********************************************************************/
BaggageCar::BaggageCar() : Space() {
    this->requiresKey = true;
}

/*********************************************************************
** Function: lookAround()
** Description: This function tells the user what the character in
** the game is looking at in this specific space
*********************************************************************/
void BaggageCar::lookAround() {
    std::cout << "You've entered the baggage car of the train. It's dark and difficult to see...\n"
    << "Surrounding you are mountains of suitcases, tablets, e-readers and phones. You see someone in the corner.\n";
    //sleep(1);
    std::cout<< "Is that your phone in the corner next to the person?";
}

/*********************************************************************
** Function: talk()
** Description: This function tells the user what the character in
** the game is saying in this specific space
**
** Note: The game ends with a riddle that must be solved to retrieve
** your phone
*********************************************************************/
void BaggageCar::talk() {
    std::cout << "PERSON IN CORNER: Hello. I am the keeper of the lost and found of the baggage car.\n"
    << "It seems you've gone to great lengths to get here.";
    //sleep(1);
    std::cout << "To retrieve your phone, you must first solve a riddle.\n\n"
    << "This is the riddle: Poor people have it. Rich people need it. If you eat it you die.\n";
    std::string answer;
    std::cout << "Enter your answer: ";
    //std::cin.clear();
    std::getline(std::cin, answer);
    while (!std::getline(std::cin, answer)) {
        std::cout << "Enter your answer: ";
    }

    bool wrong = true;
    while (wrong) {
        if (answer == "Nothing" || answer == "nothing") {
            wrong = false;
            std::cout << "That is correct. You have earned your phone back.\n"
            << "Thank you for traveling with us on the train.\n\n";
            //sleep(1);
            std::cout << "**********************************\n**********************************\n"
            << "CONGRATULATIONS YOU WON! Thanks for playing.\n";
            std::cout << "-- Enter 5 at the menu to exit the game --";
        } else {
            std::cout << "That is incorrect. Try again\n"
            << "Enter your answer: ";
            std::cin.clear();
            std::getline(std::cin, answer);
        }
    }
}

/*********************************************************************
** Function: manipulate()
** Description: This function tells the user what the character in
** the game is manipulating in this specific area - this could be
** picking up or dropping items.
*********************************************************************/
void BaggageCar::manipulate() {
    std::cout << "Nothing to manipulate. Try talking.\n";
}
