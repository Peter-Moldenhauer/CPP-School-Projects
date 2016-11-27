/************************************************************************************************************
** Program Filename: SnackStand.h
** Author: Peter Moldenhauer
** Date: 11/25/16
** Assignment: Assignment 5 (Final Assignment)
** Description: This is the SnackStand class header file for a text based adventure game. This class is a
** derived class from the Space class.
**************************************************************************************************************/

#ifndef SNACKSTAND_H
#define SNACKSTAND_H

#include "Space.h"

class SnackStand : public Space
{
    public:
        void lookAround();
        void talk();
        void manipulate();
};

#endif // SNACKSTAND_H
