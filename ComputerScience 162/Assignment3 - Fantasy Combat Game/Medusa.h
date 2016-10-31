/************************************************************************************************************
** Program Filename: Creature.h
** Author: Peter Moldenhauer
** Date: 10/30/16
** Assignment: Assignment 3
** Description: This is the header file for the Medusa class. Medusa is derived from the Creature class.
** Input: none
** Output: This class outputs information to the user regarding attacks, defense, roll results and name.
**************************************************************************************************************/

#ifndef MEDUSA_H
#define MEDUSA_H

#include "Creature.h"

class Medusa : public Creature
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
        ~Medusa() {}
};

#endif // MEDUSA_H
