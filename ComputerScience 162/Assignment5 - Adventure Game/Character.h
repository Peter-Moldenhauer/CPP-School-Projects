/************************************************************************************************************
** Program Filename: Character.h
** Author: Peter Moldenhauer
** Date: 11/25/16
** Assignment: Assignment 5 (Final Assignment)
** Description: This is the Character class header file for a text based adventure game. The Character class
** implements the character and character attributes that will be moving through the spaces in the game.
**************************************************************************************************************/

#ifndef CHARACTER_H
#define CHARACTER_H

#include <vector>
#include <string>
#include <unistd.h>
class Space;

class Character
{
    protected:
        std::string name;
        bool hasCKey;        // locomotive Cab key
        bool hasKey;         // baggage area key
        Space *currentSpace;
        std::vector<std::string> objects;   // vector to hold objects

    public:
        Character();
        void setName(std::string);
        void setHasKey(bool);
        void setHasCKey(bool);
        void setCurrentSpace(Space*);
        Space* getCurrentSpace();
        bool getHasKey();
        bool getHasCKey();
        bool getTalked();
        std::string getName();
        bool objectSearch(std::string);    // search objects vector

        // movement
        void moveFwd();
        void moveBack();
        void moveLeft();
        void moveRight();
        void addObject(std::string);
};

#endif // CHARACTER_H
