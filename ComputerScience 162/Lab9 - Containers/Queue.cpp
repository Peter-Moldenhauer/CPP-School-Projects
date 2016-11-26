/************************************************************************************************************
** Program Filename: Queue.cpp
** Author: Peter Moldenhauer
** Date: 11/21/16
** Assignment: Lab 9
** Description: This is the queue class .cpp file that demonstrates a queue like structure - first in,
** first out (FIFO)
** Input: none
** Output: none
**************************************************************************************************************/

#include "Queue.h"
#include <cstdlib>  // for NULL
#include <iostream>
using namespace std;


/*********************************************************************
 ** Function: Queue::Queue()
 ** Description: Constructs a new Queue object.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: front and back are null pointers
 *********************************************************************/
Queue::Queue(){
    front = NULL;
    back = NULL;

    srand(time(0)); // seed random num generator
}


/*********************************************************************
 ** Function: Queue::~Queue()
 ** Description: Destructor for a Queue object.
 ** Parameters: none
 ** Pre-Conditions: front has not been deleted yet
 ** Post-Conditions: front and all other nodes have been deleted
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
 ** Function: Queue::add()
 ** Description: Adds a new QueueNode containing "value" to the front
 ** of the Queue.
 ** Parameters: value is the integer to add to the Queue
 ** Pre-Conditions: none
 ** Post-Conditions: back points to a new node containing "value",
 ** the new node points to the old back node, front and back are not
 ** null pointers
 *********************************************************************/
void Queue::push(int value)
{
    // create a new node containing the value
    QueueNode *node = new QueueNode;
    node->value = value;

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
 ** Function: Queue::remove()
 ** Description: Returns the int stored in the front node of the
 ** Queue.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: if there is no front node, returns a large
 ** negative int; otherwise returns the int stored in the front node.
 *********************************************************************/
int Queue::pop()
{
    // if there are no nodes, return the most negative int
    if (front == NULL)
        return -99999;

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

    // get the value from old front node
    int removed = old_front->value;

    // free the memory pointed to by old_front
    delete old_front;
    old_front = NULL;

    // return the value
    return removed;
}


/*********************************************************************
 ** Function: Queue::getRandNum()
 ** Description: Initializes randNum to a random number
 ** Queue.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: seed random number generator
 *********************************************************************/
 void Queue::getRandNum(){
    randNum = rand() % 100 + 1; // generate a random number from 1 - 100
    //cout << "Random number is: " << randNum << endl;
 }


 /*********************************************************************
 ** Function: Queue::runSimulation()
 ** Description: runs the simulation of the buffer, enters ints in
 ** Queue.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: integers are added/removed to queue based on the
 ** percentages that the user enters.
 *********************************************************************/
 void Queue::runSimulation(){
    bool getData = true;
    int perAdd;
    int perRem;
    int rounds;
    int qSize = 0;
    int poppedNum;
    int iteration = 1;
    int average;

    cout << "\nEnter a percentage that an item will be added to the queue." << endl;
    while (getData == true){
        cout << "Enter [1 - 100]: ";
        cin >> perAdd;
        if (perAdd > 0 && perAdd <= 100){
            getData = false;
        }else{
            cout << "Error! Invalid input!" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }

    getData = true;
    cout << "Enter a percentage that an item will be removed from the queue." << endl;
    while (getData == true){
        cout << "Enter [1 - 100]: ";
        cin >> perRem;
        if (perRem > 0 && perRem <= 100){
            getData = false;
        }else{
            cout << "Error! Invalid input!" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }

    getData = true;
    cout << "Enter the number of turns to run the simulation." << endl;
    while (getData == true){
        cout << "Enter [1 - 100]: ";
        cin >> rounds;
        if (rounds > 0 && rounds <= 100){
            getData = false;
        }else{
            cout << "Error! Invalid input!" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }

    while (rounds > 0){
        getRandNum();  // generate a random number

        // add value to the queue based on the user entered percentage
        if (randNum <= perAdd){
            push(randNum);
            qSize++;  // increment queue size counter
        }

        // remove value from queue based on the user entered percentage
        if (randNum <= perRem){
            poppedNum = pop();
        }

        if (randNum <= perRem){
            qSize--;  // decrement queue size counter
        }

        average = iteration / qSize;

        cout << "\n-- Round " << iteration << " --" << endl;
        cout << "Current length of queue: " << qSize << endl;
        cout << "Average length of queue: " << average << endl;

        iteration++;
        rounds--;
    }

 }
