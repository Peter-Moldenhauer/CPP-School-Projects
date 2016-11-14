/************************************************************************************************************
** Program Filename: Stack.cpp
** Author: Peter Moldenhauer
** Date: 11/10/16
** Assignment: Assignment 4
** Description: This is the Stack class .cpp file. The Stack class provides a stack-like data structure
** for Creature pointers.
** Input: Pointers to Creature objects
** Output: Linked Stack list of Creature pointers
**************************************************************************************************************/

#include <cstdlib>  // for NULL
#include "Stack.h"


/*********************************************************************
 ** Function: Stack()
 ** Description: Constructs a new Stack object.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: top is a null pointer
 ** Return: none
 *********************************************************************/
Stack::Stack(){
    top = NULL;
}


/*********************************************************************
 ** Function: ~Stack()
 ** Description: Destructor for a Stack object.
 ** Parameters: none
 ** Pre-Conditions: top has not been deleted yet
 ** Post-Conditions: top and all other nodes have been deleted
 ** Return: none
 *********************************************************************/
Stack::~Stack(){
    // start at first node
    StackNode *cur = top;

    // destroy all the StackNodes until we reach NULL
    while (cur)
    {
        StackNode *rmv = cur;
        cur = cur->next;
        delete rmv;
    }
}


/*************************************************************************
 ** Function: add()
 ** Description: Adds a new StackNode containing "item" to the top of
 ** the Stack.
 ** Parameters: item - the Creature* to add to the Stack
 ** Pre-Conditions: none
 ** Post-Conditions: top points to a new node containing "item",
 ** the new node points to the old top node, top is not a null pointer
 ** Return: none
 *************************************************************************/
void Stack::add(Creature* item){
    // create a new node containing the item
    StackNode *node = new StackNode;
    node->item = item;

    // point it to the old top node
    node->next = top;

    // now it's on top
    top = node;
}


/*********************************************************************
 ** Function: remove()
 ** Description: Returns the Creature* stored in the top node of the
 ** Stack.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: if there is no top node, returns NULL; otherwise
 ** returns the Creature* stored in the top node
 ** Return: Creature pointer
 *********************************************************************/
Creature* Stack::remove(){
    // if there are no nodes, return NULL
    if (top == NULL)
        return NULL;

    // store the current top
    StackNode *old_top = top;

    // top points to the node under the old top
    top = old_top->next;

    // get the item from old top
    Creature* removed = old_top->item;

    // free the memory pointed to by old_top
    delete old_top;
    old_top = NULL;

    // return the item
    return removed;
}
