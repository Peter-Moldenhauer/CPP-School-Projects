/************************************************************************************************************
** Program Filename: CoachClassCar.h
** Author: Peter Moldenhauer
** Date: 11/25/16
** Assignment: Assignment 5 (Final Assignment)
** Description: This is the CoachClassCar class header file for a text based adventure game. This class is a
** derived class from the Space class.
**************************************************************************************************************/

#ifndef COACHCLASSCAR_H
#define COACHCLASSCAR_H

#include "Space.h"
#include "CryingBaby.h"
#include <string>

class CoachClassCar : public Space
{
    private:
        CryingBaby *baby; // Baby object changes as player interacts

    public:
        CoachClassCar(CryingBaby*);
        void lookAround();
        void talk();
};

#endif // COACHCLASSCAR_H
