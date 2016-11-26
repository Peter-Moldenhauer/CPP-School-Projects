/************************************************************************************************************
** Program Filename: Stack.h
** Author: Peter Moldenhauer
** Date: 11/21/16
** Assignment: Lab 9
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
                char value;
                StackNode *next;
        };

        StackNode *top;

    public:
        Stack();
        ~Stack();
        void push(char value);
        char pop();
        void palindrome();
};

#endif // STACK_H
