/********************************************************************************************************
*Name: Peter Moldenhauer
*Email: moldenhp@oregonstate.edu
*Date: 10/11/16
*Course: CS 162
*Assignment: Lab 3
*Description: This is the Die class .cpp file. The Die class is the base class for LoadedDie class.
*********************************************************************************************************/

#include "Die.h"
#include <cstdlib>  // used for the rand() function
#include <ctime>    //needed to access computer clock to seed a random number
#include <iostream>
using namespace std;

// Constructor with sides as a parameter
Die::Die(int sides){
    numSides = sides;
}

// Destructor
Die::~Die(){

}

// Function to roll the die and return a random integer within the die sides
int Die::rollDie(){
    int roll = rand() % numSides + 1;  // generate random number within the die sides
    return roll;
}
