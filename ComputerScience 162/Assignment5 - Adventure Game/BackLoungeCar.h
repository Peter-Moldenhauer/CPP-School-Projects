/************************************************************************************************************
** Program Filename: SnoringSleeper.h
** Author: Peter Moldenhauer
** Date: 11/25/16
** Assignment: Assignment 5 (Final Assignment)
** Description: This is the SnoringSleeper class header file for a text based adventure game. This class is a
** derived class from the Space class.
**************************************************************************************************************/

#ifndef BACKLOUNGECAR_H
#define BACKLOUNGECAR_H

#include "Space.h"

class BackLoungeCar : public Space
{
    public:
        void lookAround();
        void talk();
};

#endif // BACKLOUNGECAR_H
