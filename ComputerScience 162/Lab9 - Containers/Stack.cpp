/************************************************************************************************************
** Program Filename: Stack.cpp
** Author: Peter Moldenhauer
** Date: 10/31/16
** Assignment: Lab 6
** Description: This is the stack class .cpp file that demonstrates a stack like structure - first in,
** last out (FILO)
** Input: none
** Output: none
**************************************************************************************************************/

#include "Stack.h"
#include <cstdlib>  // for NULL
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;


/*********************************************************************
 ** Function: Stack::Stack()string str;
    cout << "Please enter a string: ";
    cin >> str;

    vector<char> data(str.begin(), str.end());

    for (vector<char>::const_iterator i = data.begin(); i != data.end(); ++i)
        cout << *i;

    reverse(data.begin(), data.end());

    for (vector<char>::const_iterator i = data.begin(); i != data.end(); ++i)
        cout << *i;

    cout << endl;
    cout << endl;
    cout << data.size();
 ** Description: Constructs a new Stack object.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: top is initialized to a null pointer
 *********************************************************************/
Stack::Stack(){
    top = NULL;
}


/*********************************************************************
 ** Function: Stack::~Stack()
 ** Description: Destructor for a Stack object.
 ** Parameters: none
 ** Pre-Conditions: top has not been deleted yet
 ** Post-Conditions: top and all other nodes have been deleted
 *********************************************************************/
Stack::~Stack()
{
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


/*********************************************************************
 ** Function: Stack::add()
 ** Description: Adds a new StackNode containing "value" to the top of
 ** the Stack.
 ** Parameters: value (the integer to add to the Stack)
 ** Pre-Conditions: none
 ** Post-Conditions: top points to a new node containing "value",
 ** the new node points to the old top node, top is not a null pointer.
 *********************************************************************/
void Stack::push(char value)
{
    // create a new node containing the value
    StackNode *node = new StackNode;
    node->value = value;

    // point it to the old top node
    node->next = top;

    // now it's on top
    top = node;
}


/*********************************************************************
 ** Function: Stack::remove()
 ** Description: Returns the int stored in the top node of the Stack.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: if there is no top node, returns a large negative
 ** int; otherwise returns the int stored in the top node.
 *********************************************************************/
char Stack::pop()
{
    // if there are no nodes, return large negative number
    if (top == NULL)
        return '0';

    // store the current top
    StackNode *old_top = top;

    // top points to the node under the old top
    top = old_top->next;

    // get the value from old top
    int removed = old_top->value;

    // free the memory pointed to by old_top
    delete old_top;
    old_top = NULL;

    // return the value
    return removed;
}


/*********************************************************************
 ** Function: Stack::palindrome()
 ** Description: Calculates the palindrome of a user entered string
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: Outputs the palindrome of a user entered string
 *********************************************************************/
 void Stack::palindrome(){
    char c;
    string str;

    cout << "\nPlease enter a string (no spaces): ";
    cin >> str;

    // create a vector of characters from the inputted string
    vector<char> data(str.begin(), str.end());

    // push all of the characters from the vector onto the stack
    for (vector<char>::const_iterator i = data.begin(); i != data.end(); ++i)
        push(*i);

    // reverse the vector
    reverse(data.begin(), data.end());

    // push all of the "new" characters from the reversed vector on the stack
    for (vector<char>::const_iterator i = data.begin(); i != data.end(); ++i)
        push(*i);

    cout << "The palindrome of the string is: ";

    // iterate through the size of the vector * 2 number of times, popping the stack each time to retrieve all of the characters for the palindrome
    size_t i;
    for (i = 0; i < (data.size() * 2); i++){
        c = pop();
        cout << c;
    }
    cout << endl;
 }
