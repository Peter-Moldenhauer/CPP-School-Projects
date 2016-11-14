/************************************************************************************************************
** Program Filename: Creature.h
** Author: Peter Moldenhauer
** Date: 11/10/16
** Assignment: Assignment 4
** Description: This is the header file that contains the base class Creature. Creature is an abstract class
** because all of the functions contained in this class are pure virtual functions. All of the other classes
** are derived from the Creature class.
** Input: none
** Output: none
**************************************************************************************************************/

#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>
#include <string>
#include <time.h> // for rand
#include <cstdlib>  // used for the rand() function
using namespace std;

class Creature
{
    protected:
        string name;
        string teamName;
        int armor;
        int strength;
        bool dead;

    public:
        Creature();

        // all virtual functions
        virtual void setData(string tN)=0;
        virtual int attack()=0;
        virtual void defense(int d)=0;
        virtual string getName()=0;
        virtual string getTeamName()=0;
        virtual bool isDead()=0;
        virtual int attackRoll()=0;
        virtual int defenseRoll()=0;
        virtual int getArmor()=0;
        virtual int getStrength()=0;
        virtual void revive()=0;     // this function revives a creature when it is put back in the Queue to fight again
        virtual ~Creature() {}
};

#endif // CREATURE_H
