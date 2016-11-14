/************************************************************************************************************
** Program Filename: Stack.h
** Author: Peter Moldenhauer
** Date: 11/10/16
** Assignment: Assignment 4
** Description: This is the Stack class header file. The Stack class provides a stack-like data structure
** for Creature pointers.
** Input: Pointers to Creature objects
** Output: Linked Stack list of Creature pointers
**************************************************************************************************************/

#ifndef STACK_H
#define STACK_H

#include "Creature.h"

class Stack
{
    private:
        struct StackNode
        {
            public:
                Creature* item;
                StackNode *next;
        };

        StackNode *top;

    public:
        Stack();
        ~Stack();
        void add(Creature* item);
        Creature* remove();
};

#endif // STACK_H
