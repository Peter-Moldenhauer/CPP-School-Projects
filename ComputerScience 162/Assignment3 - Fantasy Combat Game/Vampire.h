/************************************************************************************************************
** Program Filename: Creature.h
** Author: Peter Moldenhauer
** Date: 10/30/16
** Assignment: Assignment 3
** Description: This is the header file for the Vampire class. Vampire is derived from the Creature class.
** Input: none
** Output: This class outputs information to the user regarding attacks, defense, roll results and name.
**************************************************************************************************************/

#ifndef VAMPIRE_H
#define VAMPIRE_H

#include "Creature.h"
#include <time.h>

class Vampire : public Creature
{
    protected:

    public:
        void setData();
        int attack();
        void defense(int d);
        string getName();
        bool isDead();
        int attackRoll();
        int defenseRoll();
        int getArmor();
        int getStrength();
        ~Vampire() {}
};

#endif // VAMPIRE_H
