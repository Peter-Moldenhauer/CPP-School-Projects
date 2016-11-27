/************************************************************************************************************
** Program Filename: SnoringSleeper.cpp
** Author: Peter Moldenhauer
** Date: 11/25/16
** Assignment: Assignment 5 (Final Assignment)
** Description: This is the SnoringSleeper class .cpp file for a text based adventure game. This class is a
** derived class from the Space class.
**************************************************************************************************************/

#include "BackLoungeCar.h"

/*********************************************************************
** Function: lookAround()
** Description: This function tells the user what the character in
** the game is looking at in this specific space
*********************************************************************/
void BackLoungeCar::lookAround() {
    std::cout << "You're in the back lounge car of the train. To your left is the restroom,\n"
    << "to your right is a train attendant next to a snack stand, and the coach\n"
    << "class car is in front of you.\n";
    //sleep(1);
    std::cout << "Behind you is a door to the baggage car. It seems to be locked...\n";
}

/*********************************************************************
** Function: talk()
** Description: This function tells the user what the character in
** the game is saying in this specific space
*********************************************************************/
void BackLoungeCar::talk() {
    std::cout << "You might be able to talk to that train attendant over there..\n";
}
