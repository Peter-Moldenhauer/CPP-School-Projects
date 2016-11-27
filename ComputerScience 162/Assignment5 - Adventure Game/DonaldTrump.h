/************************************************************************************************************
** Program Filename: DonaldTrump.h
** Author: Peter Moldenhauer
** Date: 11/25/16
** Assignment: Assignment 5 (Final Assignment)
** Description: This is the DonaldTrump class header file for a text based adventure game. This class is a
** derived class from the Space class.
**************************************************************************************************************/

#ifndef DONALDTRUMP_H
#define DONALDTRUMP_H

#include "Space.h"

class DonaldTrump : public Space
{
    public:
        void lookAround();
        void talk();
        void manipulate();
};

#endif // DONALDTRUMP_H
