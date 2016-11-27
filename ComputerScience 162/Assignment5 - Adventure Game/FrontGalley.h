/************************************************************************************************************
** Program Filename: FrontGalley.h
** Author: Peter Moldenhauer
** Date: 11/25/16
** Assignment: Assignment 5 (Final Assignment)
** Description: This is the FrontGalley class header file for a text based adventure game. This class is a
** derived class from the Space class.
**************************************************************************************************************/

#ifndef FRONTGALLEY_H
#define FRONTGALLEY_H

#include "Space.h"

class FrontGalley : public Space
{
    public:
        void lookAround();
        void talk();
        void manipulate();
};

#endif // FRONTGALLEY_H
