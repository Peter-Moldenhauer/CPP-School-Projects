/************************************************************************************************************
** Program Filename: BackRestroom.h
** Author: Peter Moldenhauer
** Date: 11/25/16
** Assignment: Assignment 5 (Final Assignment)
** Description: This is the BackRestroom class header file for a text based adventure game. This class is a
** derived class from the Space class.
**************************************************************************************************************/

#ifndef BACKRESTROOM_H
#define BACKRESTROOM_H

#include "Space.h"

class BackRestroom : public Space
{
    public:
        void lookAround();
        void talk();
};

#endif // BACKRESTROOM_H
