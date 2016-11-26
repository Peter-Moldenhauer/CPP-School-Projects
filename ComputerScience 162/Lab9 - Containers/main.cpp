/************************************************************************************************************
** Program Filename: main.cpp
** Author: Peter Moldenhauer
** Date: 11/21/16
** Assignment: Lab 9
** Description: This is the main.cpp file for the Lab 9 assignment. In this lab I created two data structures:
** a stack and a queue and use STL containers to demonstrate basic ADT's
**************************************************************************************************************/

#include "Queue.h"
#include "Stack.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void showMenu();
int getChoice();

int main()
{
    int choice;
    Stack s;
    Queue q;

    cout << "CS162 Lab 9" << endl;
    cout << "By: Peter Moldenhauer" << endl;

    do {
        showMenu();
        choice = getChoice();
        cin.ignore();

        switch (choice){
            case 1:  // simulate a buffer (queue)
                {
                    q.runSimulation();
                }
            break;
            case 2:  // create a palindrome (stack)
                {
                    s.palindrome(); // run palindrome stack function
                }
            break;
            case 3:  // Exit
            break;
        }
    } while (choice != 3);

    cout << "\nExiting Lab 9 program. Goodbye!!!" << endl;

    return 0;
}

/***************************************************************************
 ** Function: showMenu()
 ** Description: Displays the opening menu to the user
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: Menu is displayed on screen
 *****************************************************************************/
  void showMenu(){

    cout << "\nPlease select one of the following options..." << endl;
    cout << "1) Simulate a buffer (Queue)" << endl;
    cout << "2) Create a palindrome (Stack)" << endl;
    cout << "3) Exit" << endl;
}

/***********************************************************************************************
 ** Function: getChoice()
 ** Description: This function prompts user for menu selection choice and validates the input
 ** Parameters: none
 ** Pre-Conditions: Beginning menu has to be displayed to the user first
 ** Post-Conditions: none
 *************************************************************************************************/
  int getChoice(){
    bool getData = true;
    int userInput;

    while (getData == true){
        cout << "Enter [1 - 3]: ";
        cin >> userInput;
        if (userInput > 0 && userInput <= 3){
            getData = false;
        }else{
            cout << "Error! Enter either 1, 2 or 3 to make your selection!" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
    return userInput;
}
