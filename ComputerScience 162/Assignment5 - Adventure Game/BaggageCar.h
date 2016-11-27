/************************************************************************************************************
** Program Filename: BaggageCar.h
** Author: Peter Moldenhauer
** Date: 11/25/16
** Assignment: Assignment 5 (Final Assignment)
** Description: This is the BaggageCar class header file for a text based adventure game. This class is a
** derived class from the Space class.
**************************************************************************************************************/

#ifndef BAGGAGECAR_H
#define BAGGAGECAR_H

#include "Space.h"

class BaggageCar : public Space
{
    public:
        BaggageCar();
        void lookAround();
        void manipulate();
        void talk();
};

#endif // BAGGAGECAR_H
