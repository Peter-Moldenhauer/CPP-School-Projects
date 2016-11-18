/************************************************************************************************************
** Program Filename: Queue.cpp
** Author: Peter Moldenhauer
** Date: 11/17/16
** Assignment: Lab 8
** Description: This is the Queue .cpp file for the Lab 8 assignment. In this lab, I created an abstract data
** type, using a doubly-linked circular structure to store values (inputted from user) and links.
** Input: User inputs menu selection and integers to be added to the Queue
** Output: Contents of Queue are outputted
**************************************************************************************************************/

#include <cstdlib>  // for NULL
#include <string>
#include <iostream>
#include "Queue.h"
using namespace std;


/*********************************************************************
 ** Function: Queue::Queue()
 ** Description: Constructs a new Queue object.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: front and back both point to a new element, which
 ** points to itself, the new element is empty
 *********************************************************************/
Queue::Queue(){
    // create first node here to simplify logic
    QueueNode *fst = new QueueNode();
    // set it to empty
    fst->item = EMPTY;
    fst->next = fst;
    fst->prev = fst;

    front = fst;
    back = fst;
}


/*************************************************************************
 ** Function: Queue::~Queue()
 ** Description: Destructor for a Queue object.
 ** Parameters: none
 ** Pre-Conditions: front has not been deleted yet, no pointers are null
 ** Post-Conditions: front and all other nodes have been deleted
 *************************************************************************/
Queue::~Queue(){
    // start at first node
    QueueNode *cur;
    back = front->next;

    // destroy all the QueueNodes until we reach NULL
    while (back != front)
    {
        cur = back;
        back = cur->next;

        delete cur;
    }

    delete back;    // deleting the last node

    // not needed?
    front = NULL;
    back = NULL;
    cur = NULL;
}


/*********************************************************************
 ** Function: Queue::addBack()
 ** Description: Adds a new element to the back of the Queue.
 ** Parameters: item - the integer to add to the Queue
 ** Pre-Conditions: item is not -1 (the sentinel value)
 ** Post-Conditions: back points to a node containing "item", the node
 ** points to the old back node, the node points to the node back used
 ** to point to, the Queue is not empty
 *********************************************************************/
void Queue::addBack(int item){
    // next node after back
    QueueNode *after = back->next;

    // if after is empty, let it hold item's value
    if (after->item == EMPTY)
    {
        after->item = item;

        return;
    }

    // otherwise, make a new node and insert it between back and after
    QueueNode *cur = new QueueNode;
    cur->item = item;
    cur->prev = back;
    cur->next = after;

    // update back and after's pointers
    back->next = cur;
    after->prev = cur;
    back = cur;
}


/*********************************************************************
 ** Function: Queue::getFront()
 ** Description: Sets out to the int stored in the front node of the
 ** Queue and returns a string stating the status of the Queue.
 ** Parameters: none
 ** Pre-Conditions: -1 was never added to the Queue by the user
 ** Post-Conditions: if there is no front element, print empty status;
 ** otherwise returns the value stored in the front node
 *********************************************************************/
int Queue::getFront(){
    int out = front->item;

    if (out == EMPTY)
        cout << "\nThe queue is empty! No front value: ";

    return out;
}


/*********************************************************************
 ** Function: Queue::removeFront()
 ** Description: Returns the int stored in the front node of the Queue
 ** and makes the old front node as empty.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: if there is no front element, returns -1; otherwise
 ** returns the int stored in the front node, old front is empty
 *********************************************************************/
int Queue::removeFront(){
    int val = front->item;

    // mark old front node as empty
    front->item = EMPTY;

    // move to next queue element
    front = front->next;

    return val;
}


/*********************************************************************
 ** Function: Queue::printValues()
 ** Description: Prints out the queue in order.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: each element of the queue is printed in order
 *********************************************************************/
 void Queue::printValues(){
    cout << "\nThe queue contains the following values..." << endl;

    QueueNode *startPos = front;
    QueueNode *curPos = front;

    if (curPos->item == EMPTY)
        cout << "The queue is empty! No values in queue: -1";

    do {
        int curVal = curPos->item;
        if (curVal != EMPTY)
            cout << curPos->item << ' ';
        curPos = curPos->next;
    } while (curPos != startPos);
    cout << endl;
 }
