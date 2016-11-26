/************************************************************************************************************
** Program Filename: Queue.h
** Author: Peter Moldenhauer
** Date: 11/21/16
** Assignment: Lab 9
** Description: This is the queue class header file that demonstrates a queue like structure - first in,
** first out (FIFO)
** Input: none
** Output: none
**************************************************************************************************************/

#ifndef QUEUE_H
#define QUEUE_H
#include <cstdlib>  // used for the rand() function
#include <ctime>    //needed to access computer clock to seed a random number

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
        int randNum;

    public:
        Queue();
        ~Queue();
        void push(int value);
        int pop();
        void getRandNum();
        void runSimulation();
};

#endif // QUEUE_H
