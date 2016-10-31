/************************************************************************************************************
** Program Filename: Creature.h
** Author: Peter Moldenhauer
** Date: 10/30/16
** Assignment: Assignment 3
** Description: This is the header file for the BlueMen class. BlueMen is derived from the Creature class.
** Input: none
** Output: This class outputs information to the user regarding attacks, defense, roll results and name.
**************************************************************************************************************/

#ifndef BLUEMEN_H
#define BLUEMEN_H

#include "Creature.h"

class BlueMen : public Creature
{
    protected:
        int loseDie; // for SPECIAL ABILITY

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
        ~BlueMen() {}
};

#endif // BLUEMEN_H
