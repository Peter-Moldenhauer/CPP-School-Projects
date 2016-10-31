/************************************************************************************************************
** Program Filename: Creature.h
** Author: Peter Moldenhauer
** Date: 10/30/16
** Assignment: Assignment 3
** Description: This is the header file for the Barbarian class. Barbarian is derived from the Creature class.
** Input: none
** Output: This class outputs information to the user regarding attacks, defense, roll results and name.
**************************************************************************************************************/

#ifndef BARBARIAN_H
#define BARBARIAN_H

#include "Creature.h"

class Barbarian : public Creature
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
        ~Barbarian() {}
};

#endif // BARBARIAN_H
