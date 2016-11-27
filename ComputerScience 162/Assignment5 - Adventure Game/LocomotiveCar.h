/************************************************************************************************************
** Program Filename: LocomotiveCar.h
** Author: Peter Moldenhauer
** Date: 11/25/16
** Assignment: Assignment 5 (Final Assignment)
** Description: This is the LocomotiveCar class header file for a text based adventure game. This class is a
** derived class from the Space class.
**************************************************************************************************************/

#ifndef LOCOMOTIVECAR_H
#define LOCOMOTIVECAR_H

#include "Space.h"

class LocomotiveCar : public Space
{
    public:
        LocomotiveCar();
        void lookAround();
        void talk();
};

#endif // LOCOMOTIVECAR_H
