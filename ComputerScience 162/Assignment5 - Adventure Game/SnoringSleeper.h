/************************************************************************************************************
** Program Filename: SnoringSleeper.h
** Author: Peter Moldenhauer
** Date: 11/25/16
** Assignment: Assignment 5 (Final Assignment)
** Description: This is the SnoringSleeper class header file for a text based adventure game. This class is a
** derived class from the Space class.
**************************************************************************************************************/

#ifndef SNORINGSLEEPER_H
#define SNORINGSLEEPER_H

#include "Space.h"

class SnoringSleeper : public Space
{
    protected:
        bool awake; // Interaction changes when sleeper is awake

    public:
        void setAwake(bool);
        void lookAround();
        void talk();
        void manipulate();
};

#endif // SNORINGSLEEPER_H
