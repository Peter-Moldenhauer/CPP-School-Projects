/************************************************************************************************************
** Program Filename: main.cpp
** Author: Peter Moldenhauer
** Date: 10/31/16
** Assignment: Lab 6
** Description: This is the main.cpp file for a program that demonstrates a stack like structure - first in,
** last out (FILO) and a queue like structure - first in, first out (FIFO).
** Input: User has to input menu selections and what values to add to the stack/queue
** Output: Outputs menus, selections and confirmation of push/pop on the stack/queue
**************************************************************************************************************/

#include "Queue.h"
#include "Stack.h"
#include <iostream>
#include <cstdlib>  //Delete when compiling on FLIP? This is used for clear screen in windows
using namespace std;

void showMenu(); // This function prints the opening menu to user
int getChoice(); // This function gets the input choice of the user from the menu
void showSQMenu(); // This function prints out the menu for stack and queue
int getSQChoice(); // This function gets and validates the user input to push or pop

int main()
{
    int choice;
    Stack s;
    Queue q;

    cout << "CS162 Lab 6 - Linked Structures" << endl;
    cout << "by: Peter Moldenhauer\n" << endl;

    do {
        showMenu();
        choice = getChoice();
        cin.ignore();

        switch (choice){
            case 1: // user wants to access the stack
                {
                    cout <<"\033[2J\033[1;1H";   // clear the screen
                    //system("CLS");                 // clear the screen WINDOWS
                    int input;

                    do {
                        cout << "-- Stack operations Menu --" << endl;
                        showSQMenu();
                        input = getChoice();

                        switch (input){
                            case 1: // user wants to push on stack
                                {
                                    int integer;
                                    cout << "\nPush integer on stack..." << endl;
                                    integer = getSQChoice();

                                    s.push(integer);
                                    cout << integer << " was added to the stack\n" << endl;
                                }
                            break;
                            case 2:  // user wants to pop from stack
                                {
                                    int integer;
                                    cout << "\nPop integer from stack..." << endl;
                                    integer = s.pop();

                                    if (integer == -99999)
                                        cout << "ERROR! No node in Stack. Stack is empty!\n" << endl;
                                    else
                                        cout << integer << " popped successfully from the stack.\n" << endl;
                                }
                                break;
                            case 3:  // user wants to return to main menu
                                {
                                    cout <<"\033[2J\033[1;1H";   // clear the screen
                                    //system("CLS");                 // clear the screen WINDOWS
                                }
                                break;
                        }
                    } while (input != 3);
                }
                break;
            case 2: // user wants to access the queue
                {
                    cout <<"\033[2J\033[1;1H";   // clear the screen
                    //system("CLS");                 // clear the screen WINDOWS
                    int input;

                    do {
                        cout << "-- Queue operations Menu --" << endl;
                        showSQMenu();
                        input = getChoice();

                        switch (input){
                            case 1: // user wants to push on queue
                                {
                                    int integer;
                                    cout << "\nPush integer on queue..." << endl;
                                    integer = getSQChoice();

                                    q.push(integer);
                                    cout << integer << " was added to the queue\n" << endl;
                                }
                            break;
                            case 2:  // user wants to pop from queue
                                {
                                    int integer;
                                    cout << "\nPop integer from queue..." << endl;
                                    integer = q.pop();

                                    if (integer == -99999)
                                        cout << "ERROR! No node in queue. Queue is empty!\n" << endl;
                                    else
                                        cout << integer << " popped successfully from the queue.\n" << endl;
                                }
                                break;
                            case 3:  // user wants to return to main menu
                                {
                                    cout <<"\033[2J\033[1;1H";   // clear the screen
                                    //system("CLS");                 // clear the screen WINDOWS
                                }
                                break;
                        }
                    } while (input != 3);
                }
                break;
            case 3: // user wants to quit program
                break;
        }
    } while (choice != 3); // if user enters 3 then the program exits

    cout << "\nExiting Linked Structures Program, Goodbye!!!\n" << endl;

    return 0;
}


/***********************************************************************************************
* Function: showMenu()
* Description: This function displays the opening menu to the user
* Parameters: none
* Pre-Conditions: none
* Post-Conditions: none
* Return: none
*************************************************************************************************/
void showMenu(){
    cout << "-- MAIN MENU --" << endl;
    cout << "Please select one of the options to access the Stack or Queue or exit the program..." << endl;
    cout << "1) Access Stack" << endl;
    cout << "2) Access Queue" << endl;
    cout << "3) Exit program." << endl;
}

/***********************************************************************************************
* Function: getChoice()
* Description: This function prompts user for menu selection choice and validates the input
* Parameters: none
* Pre-Conditions: Beginning menu has to be displayed to the user first
* Post-Conditions: none
* Return: user menu choice
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
            cout << "Please enter either 1, 2 or 3 to make your selection!" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
    return userInput;
}

/***********************************************************************************************
* Function: showSQMenu()
* Description: This function displays the menu for the stack and queue options
* Parameters: none
* Pre-Conditions: user must choose either 1 or 2 in the main menu
* Post-Conditions: none
* Return: none
*************************************************************************************************/
void showSQMenu(){
    cout << "Please select one of the following actions to take..." << endl;
    cout << "1) Push operation" << endl;
    cout << "2) Pop operation" << endl;
    cout << "3) Return to main menu" << endl;
}


/***********************************************************************************************
* Function: getChoice()
* Description: This function prompts user to input an integer to either be pushed or popped
* Parameters: none
* Pre-Conditions: Beginning menu has to be displayed to the user first
* Post-Conditions: none
* Return: user menu choice
*************************************************************************************************/
int getSQChoice(){
    bool getData = true;
    int userInput;

    while (getData == true){
        cout << "Please enter an INTEGER here: ";
        cin >> userInput;
        if (cin.fail()){
            cout << "Invalid input! Please enter an INTEGER!" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }else{
            getData = false;
        }
    }
    return userInput;
}
