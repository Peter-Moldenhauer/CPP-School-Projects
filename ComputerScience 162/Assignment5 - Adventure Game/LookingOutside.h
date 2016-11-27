/************************************************************************************************************
** Program Filename: LookingOutside.h
** Author: Peter Moldenhauer
** Date: 11/25/16
** Assignment: Assignment 5 (Final Assignment)
** Description: This is the LookingOutside class header file for a text based adventure game. This class is a
** derived class from the Space class.
**************************************************************************************************************/

#ifndef LOOKINGOUTSIDE_H
#define LOOKINGOUTSIDE_H

#include "Space.h"

class LookingOutside : public Space
{
    public:
        void lookAround();
        void talk();
};

#endif // LOOKINGOUTSIDE_H
