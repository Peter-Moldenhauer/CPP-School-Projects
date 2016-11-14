/************************************************************************************************************
** Program Filename: Creature.h
** Author: Peter Moldenhauer
** Date: 11/10/16
** Assignment: Assignment 4
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
        void setData(string tN);
        int attack();
        void defense(int d);
        string getName();
        string getTeamName();
        bool isDead();
        int attackRoll();
        int defenseRoll();
        int getArmor();
        int getStrength();
        void revive();  // revive some strength if being added back in queue
        ~Medusa() {}
};

#endif // MEDUSA_H
