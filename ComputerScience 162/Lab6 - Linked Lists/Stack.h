/************************************************************************************************************
** Program Filename: Stack.h
** Author: Peter Moldenhauer
** Date: 10/31/16
** Assignment: Lab 6
** Description: This is the stack class header file that demonstrates a stack like structure - first in,
** last out (FILO)
** Input: none
** Output: none
**************************************************************************************************************/

#ifndef STACK_H
#define STACK_H


class Stack
{
    private:
        struct StackNode
        {
            public:
                int value;
                StackNode *next;
        };

        StackNode *top;

    public:
        Stack();
        ~Stack();
        void push(int value);
        int pop();
};

#endif // STACK_H
