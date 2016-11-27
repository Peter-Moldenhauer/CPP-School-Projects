/************************************************************************************************************
** Program Filename: FrontRestroom.h
** Author: Peter Moldenhauer
** Date: 11/25/16
** Assignment: Assignment 5 (Final Assignment)
** Description: This is the FrontRestroom class header file for a text based adventure game. This class is a
** derived class from the Space class.
**************************************************************************************************************/

#ifndef FRONTRESTROOM_H
#define FRONTRESTROOM_H

#include "Space.h"

class FrontRestroom : public Space
{
    public:
        void lookAround();
        void manipulate();
        void talk();
};

#endif // FRONTRESTROOM_H
