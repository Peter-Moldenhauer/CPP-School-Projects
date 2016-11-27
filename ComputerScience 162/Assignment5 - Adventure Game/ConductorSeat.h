/************************************************************************************************************
** Program Filename: ConductorSeat.h
** Author: Peter Moldenhauer
** Date: 11/25/16
** Assignment: Assignment 5 (Final Assignment)
** Description: This is the ConductorSeat class header file for a text based adventure game. This class is a
** derived class from the Space class.
**************************************************************************************************************/

#ifndef CONDUCTORSEAT_H
#define CONDUCTORSEAT_H

#include "Space.h"

class ConductorSeat : public Space
{
    protected:
        bool hasCoffee; // Needs coffee before he'll talk to you

    public:
        ConductorSeat();
        void lookAround();
        void talk();
        void manipulate();
};

#endif // CONDUCTORSEAT_H
