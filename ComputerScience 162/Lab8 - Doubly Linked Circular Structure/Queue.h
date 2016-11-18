/************************************************************************************************************
** Program Filename: Queue.h
** Author: Peter Moldenhauer
** Date: 11/17/16
** Assignment: Lab 8
** Description: This is the Queue header file for the Lab 8 assignment. In this lab, I created an abstract data
** type, using a doubly-linked circular structure to store values (inputted from user) and links.
** Input: User inputs menu selection and integers to be added to the Queue
** Output: Contents of Queue are outputted
**************************************************************************************************************/

#ifndef QUEUE_H
#define QUEUE_H

class Queue
{
    private:
        struct QueueNode
        {
            public:
                int item;
                // node that will come off queue before this one, or NULL
                QueueNode *next;
                // node that will come of queue after this one, or NULL
                QueueNode *prev;
        };

        // first element in queue
        QueueNode *front;
        // last element in queue
        QueueNode *back;

        // indicates that a node is empty
        static const int EMPTY = -1;

    public:
        Queue();
        ~Queue();

        void addBack(int item);    // inserts new node with item
        int getFront();            // returns the front node
        int removeFront();         // basically just sets the node to -1 and returns the node
        void printValues();        // prints all of the elements in the queue
};

#endif // QUEUE_H
