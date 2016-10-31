/************************************************************************************************************
** Program Filename: Creature.h
** Author: Peter Moldenhauer
** Date: 10/30/16
** Assignment: Assignment 3
** Description: This is the header file for the HarryPotter class. HarryPotter is derived from the Creature class.
** Input: none
** Output: This class outputs information to the user regarding attacks, defense, roll results and name.
**************************************************************************************************************/

#ifndef HARRYPOTTER_H
#define HARRYPOTTER_H

#include "Creature.h"

class HarryPotter : public Creature
{
    protected:
        int hogwarts; // for SPECIAL ABILITY

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
        ~HarryPotter() {}
};

#endif // HARRYPOTTER_H
