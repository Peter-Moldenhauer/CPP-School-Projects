/************************************************************************************************************
** Program Filename: EngineerSeat.h
** Author: Peter Moldenhauer
** Date: 11/25/16
** Assignment: Assignment 5 (Final Assignment)
** Description: This is the EngineerSeat class header file for a text based adventure game. This class is a
** derived class from the Space class.
**************************************************************************************************************/

#ifndef ENGINEERSEAT_H
#define ENGINEERSEAT_H

#include "Space.h"

class EngineerSeat : public Space
{
    public:
        void lookAround();
        void talk();
        void manipulate();
};

#endif // ENGINEERSEAT_H
