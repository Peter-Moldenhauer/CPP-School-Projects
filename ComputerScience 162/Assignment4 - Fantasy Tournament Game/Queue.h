/************************************************************************************************************
** Program Filename: Queue.h
** Author: Peter Moldenhauer
** Date: 11/10/16
** Assignment: Assignment 4
** Description: This is the Queue class header file. The Queue class provides a queue-like data structure
** for Creature pointers.
** Input: Pointers to Creature objects
** Output: Linked Queue list of Creature pointers
**************************************************************************************************************/

#ifndef QUEUE_H
#define QUEUE_H

#include "Creature.h"

class Queue
{
    private:
        struct QueueNode
        {
            public:
                Creature *item;
                // node that will come off queue before this one, or NULL
                QueueNode *next;
                // node that will come of queue after this one, or NULL
                QueueNode *prev;
        };

        QueueNode *front;
        QueueNode *back;

    public:
        Queue();
        ~Queue();
        void add(Creature* item);
        Creature* remove();
};

#endif // QUEUE_H
