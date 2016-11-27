/************************************************************************************************************
** Program Filename: Space.h
** Author: Peter Moldenhauer
** Date: 11/25/16
** Assignment: Assignment 5 (Final Assignment)
** Description: This is the Space class header file for a text based adventure game. The Space class
** is an abstract base class from which all of the unique spaces used in the game are derived from.
**************************************************************************************************************/

#ifndef SPACE_H
#define SPACE_H

#include <iostream>
#include <string>
#include <unistd.h>
class Character;

class Space
{
    protected:
        // Pointers to adjacent spaces
        Space *fwd;
        Space *back;
        Space *left;
        Space *right;
        bool requiresKey;
        Character *character;
        std::string spaceName;

    public:
        Space();
        Space(Space*, Space*, Space*, Space*);
        ~Space();
        // Space is first instantiated, then relationship pointers are set up using setLocaiton
        void setLocation(Space*, Space*, Space*, Space*, Character*, std::string);
        bool getRequiresKey();
        Space* getFwd();
        Space* getBack();
        Space* getLeft();
        Space* getRight();
        std::string getSpaceName();
        // virtual functions, two pure virtual
        virtual void talk() = 0;
        virtual void lookAround() = 0;
        virtual void manipulate();
};

#endif // SPACE_H
