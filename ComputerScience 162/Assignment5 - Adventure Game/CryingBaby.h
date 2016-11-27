/************************************************************************************************************
** Program Filename: CryingBaby.h
** Author: Peter Moldenhauer
** Date: 11/25/16
** Assignment: Assignment 5 (Final Assignment)
** Description: This is the CryingBaby class header file for a text based adventure game. This class is a
** derived class from the Space class.
**************************************************************************************************************/

#ifndef CRYINGBABY_H
#define CRYINGBABY_H

#include "Space.h"

class CryingBaby : public Space
{
    private:
        bool crying; // Interaction changes when baby stops crying

    public:
        CryingBaby();
        void setCrying(bool);
        bool getCrying();
        void lookAround();
        void talk();
        void manipulate();
};

#endif // CRYINGBABY_H
