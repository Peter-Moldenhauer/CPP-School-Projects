/************************************************************************************************************
** Program Filename: FirstClassCar.h
** Author: Peter Moldenhauer
** Date: 11/25/16
** Assignment: Assignment 5 (Final Assignment)
** Description: This is the FirstClassCar class header file for a text based adventure game. This class is a
** derived class from the Space class.
**************************************************************************************************************/

#ifndef FIRSTCLASSCAR_H
#define FIRSTCLASSCAR_H

#include "Space.h"

class FirstClassCar : public Space
{
    public:
        void lookAround();
        void talk();
};

#endif // FIRSTCLASSCAR_H
