/************************************************************************************************************
** Program Filename: BradPitt.h
** Author: Peter Moldenhauer
** Date: 11/25/16
** Assignment: Assignment 5 (Final Assignment)
** Description: This is the BradPitt class header file for a text based adventure game. This class is a
** derived class from the Space class.
**************************************************************************************************************/

#ifndef BRADPITT_H
#define BRADPITT_H

#include "Space.h"

class BradPitt : public Space
{
    private:
        bool sad;

    public:
        BradPitt();
        void lookAround();
        void talk();
        void manipulate();
};

#endif // BRADPITT_H
