/************************************************************************************************************
** Program Filename: Queue.h
** Author: Peter Moldenhauer
** Date: 10/31/16
** Assignment: Lab 6
** Description: This is the queue class header file that demonstrates a queue like structure - first in,
** first out (FIFO)
** Input: none
** Output: none
**************************************************************************************************************/

#ifndef QUEUE_H
#define QUEUE_H

class Queue
{
    private:
        struct QueueNode
        {
            public:
                int value;
                QueueNode *next; // node that will come off queue before this one, or NULL
                QueueNode *prev; // node that will come of queue after this one, or NULL
        };

        QueueNode *front;
        QueueNode *back;

    public:
        Queue();
        ~Queue();
        void push(int value);
        int pop();
};

#endif // QUEUE_H
