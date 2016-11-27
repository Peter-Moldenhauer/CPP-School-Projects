/*******************************************************************************************************************
** Program Filename: ForwardAttendantCar.h
** Author: Peter Moldenhauer
** Date: 11/25/16
** Assignment: Assignment 5 (Final Assignment)
** Description: This is the ForwardAttendantCar class header file for a text based adventure game. This class is a
** derived class from the Space class.
*********************************************************************************************************************/

#ifndef FORWARDATTENDANTCAR_H
#define FORWARDATTENDANTCAR_H

#include "Space.h"

class ForwardAttendantCar : public Space
{
    public:
        void lookAround();
        void talk();
};

#endif // FORWARDATTENDANTCAR_H
