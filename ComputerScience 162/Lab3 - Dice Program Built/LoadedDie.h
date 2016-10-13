/********************************************************************************************************
*Name: Peter Moldenhauer
*Email: moldenhp@oregonstate.edu
*Date: 10/11/16
*Course: CS 162
*Assignment: Lab 3
*Description: This is the LoadedDie class header file. The LoadedDie is derived from the Die class.
*********************************************************************************************************/

#include "Die.h"
#ifndef LOADEDDIE_H
#define LOADEDDIE_H


class LoadedDie: public Die
{
    private:
        int numSides;   // number of sides on die

    public:
        LoadedDie(int sides);  // constructor with the number of sides on die as a parameter

        int rollDie();    // returns a random integer between 1 and the number of sides, Increased probability of highest number on die!

};

#endif // LOADEDDIE_H
