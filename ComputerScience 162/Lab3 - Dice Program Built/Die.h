/********************************************************************************************************
*Name: Peter Moldenhauer
*Email: moldenhp@oregonstate.edu
*Date: 10/11/16
*Course: CS 162
*Assignment: Lab 3
*Description: This is the Die class header file. The Die class is the base class for LoadedDie class.
*********************************************************************************************************/

#ifndef DIE_H
#define DIE_H


class Die
{
    private:
        int numSides;   // number of sides on die

    public:
        Die(int sides);  // constructor with the number of sides on die as a parameter

        virtual ~Die();          // virtual destructor

        virtual int rollDie();    // virtual function that returns a random integer between 1 and the number of sides
};

#endif // DIE_H
