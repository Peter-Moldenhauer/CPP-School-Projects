/************************************************************************************************************
** Program Filename: Queue.cpp
** Author: Peter Moldenhauer
** Date: 11/10/16
** Assignment: Assignment 4
** Description: This is the Queue class .cpp file. The Queue class provides a queue-like data structure
** for Creature pointers.
** Input: Pointers to Creature objects
** Output: Linked Queue list of Creature pointers
**************************************************************************************************************/

#include "Queue.h"
#include <cstdlib>  // for NULL


/*********************************************************************
 ** Function: Queue()
 ** Description: Constructs a new Queue object.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: front and back are null pointers
 ** Return: none
 *********************************************************************/
Queue::Queue() {
    front = NULL;
    back = NULL;
}


/*********************************************************************
 ** Function: ~Queue()
 ** Description: Destructor for a Queue object.
 ** Parameters: none
 ** Pre-Conditions: front has not been deleted yet
 ** Post-Conditions: front and all other nodes have been deleted
 ** Return: none
 *********************************************************************/
Queue::~Queue()
{
    // start at first node
    QueueNode *cur = front;

    // destroy all the QueueNodes until we reach NULL
    while (cur)
    {
        QueueNode *rmv = cur;
        cur = cur->next;
        delete rmv;
    }
}


/*********************************************************************
 ** Function: add()
 ** Description: Adds a new QueueNode containing "item" to the front
 ** of the Queue.
 ** Parameters: item - the Creature* to add to the Queue
 ** Pre-Conditions: none
 ** Post-Conditions: back points to a new node containing "item",
 ** the new node points to the old back node, front and back are not
 ** null pointers
 ** Return: none
 *********************************************************************/
void Queue::add(Creature* item)
{
    // create a new node containing the item
    QueueNode *node = new QueueNode;
    node->item = item;

    // make the node before it be the old back
    node->next = back;

    // this is the last node
    node->prev = NULL;

    // now it's in back
    back = node;

    // if there were no nodes before, it's now the front node too
    if (node->next == NULL)
        front = node;

    // otherwise make the old back node point to the new back node
    else
        node->next->prev = node;

    // null out the temporary pointer variable
    node = NULL;
}


/*********************************************************************
 ** Function: remove()
 ** Description: Returns the Creature* stored in the front node of the
 ** Queue.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: if there is no front node, returns NULL;
 ** otherwise returns the int stored in the front node
 ** Return: the Creature pointer stored in the front node
 *********************************************************************/
Creature* Queue::remove()
{
    // if there are no nodes, return NULL
    if (front == NULL)
        return NULL;

    // store the current front
    QueueNode *old_front = front;

    // front points to the node after old_front
    front = old_front->prev;

    // new front has no nodes in front of it
    if (front != NULL)
        front->next = NULL;

    // front is NULL so back is NULL
    else
        back = NULL;

    // get the item from old front node
    Creature* removed = old_front->item;

    // free the memory pointed to by old_front
    delete old_front;
    old_front = NULL;

    // return the item
    return removed;
}
