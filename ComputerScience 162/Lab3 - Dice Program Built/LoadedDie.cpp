/********************************************************************************************************
*Name: Peter Moldenhauer
*Email: moldenhp@oregonstate.edu
*Date: 10/11/16
*Course: CS 162
*Assignment: Lab 3
*Description: This is the LoadedDie class .cpp file. The LoadedDie is derived from the Die class.
*********************************************************************************************************/

#include <iostream>
#include <cstdlib>  // used for the rand() function
#include <ctime>    //needed to access computer clock to seed a random number
#include "LoadedDie.h"
using namespace std;

// Constructor
LoadedDie::LoadedDie(int sides): Die(sides){
    numSides = sides;
}


int LoadedDie::rollDie(){
    int roll = rand() % numSides + 1;  // generate random number within the die sides

    // return the highest number on die about 50% of the time
    int r = rand() % 2;
    if(r == 0)
        return numSides;
    else
        return roll;
}
