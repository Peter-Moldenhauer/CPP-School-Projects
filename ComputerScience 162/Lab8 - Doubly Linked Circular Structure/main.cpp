/************************************************************************************************************
** Program Filename: main.cpp
** Author: Peter Moldenhauer
** Date: 11/17/16
** Assignment: Lab 8
** Description: This is the main.cpp file for the Lab 8 assignment. In this lab, I created an abstract data
** type, using a doubly-linked circular structure to store values (inputted from user) and links.
** Input: User inputs menu selection and integers to be added to the Queue
** Output: Contents of Queue are outputted
**************************************************************************************************************/

#include "Queue.h"
#include <iostream>
#include <string>
using namespace std;

void showMenu();
int getChoice();
int getInt();

int main()
{
    int choice;
    Queue q;

    cout << "CS162 Lab 8 - Doubly-linked circular structure" << endl;
    cout << "By: Peter Moldenhauer" << endl;

    do {
        showMenu();
        choice = getChoice();
        cin.ignore();

        switch (choice){
            case 1:  // enter a value to be added to the queue
                {
                    cout << "\nEnter an integer in the range [0 - 1000] to be added to the queue..." << endl;
                    int val = getInt();
                    q.addBack(val);
                }
                break;
            case 2:  // Display first node (front) value
                {
                    cout << "\nThe first node value in the queue is: ";
                    int val = q.getFront();
                    cout << val << endl;
                }
                break;
            case 3:  // Remove first node (front) value
                {
                    cout << "\nRemoving first node value from queue..." << endl;
                    int val = q.removeFront();
                    if (val == -1)
                        cout << "The queue is already empty!" << endl;
                    else
                        cout << "Removed the value " << val << " from queue successfully." << endl;
                }
                break;
            case 4:  // Display the queue contents
                {
                    q.printValues();
                }
                break;
            case 5:  // Exit
                break;
        }
    } while (choice != 5);

    cout << "\nExiting Lab 8 program. Goodbye!!!" << endl;

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
    cout << "1) Enter a value to be added to the queue" << endl;
    cout << "2) Display first node (front) value" << endl;
    cout << "3) Remove first node (front) value" << endl;
    cout << "4) Display the queue contents" << endl;
    cout << "5) Exit" << endl;
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
        cout << "Enter [1 - 5]: ";
        cin >> userInput;
        if (userInput > 0 && userInput <= 5){
            getData = false;
        }else{
            cout << "Error! Enter either 1, 2, 3, 4 or 5 to make your selection!" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
    return userInput;
}


/***********************************************************************************************
 ** Function: getInt()
 ** Description: This function prompts user to enter an integer in range and validates the input
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *************************************************************************************************/
  int getInt(){
    bool getData = true;
    int userInput;

    while (getData == true){
        cout << "Enter the integer here: ";
        cin >> userInput;
        if (cin.fail()){
            cout << "Invalid Input! Enter an integer in the range [0 - 1000]!" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else if (userInput >= 0 && userInput <= 1000){
            getData = false;
        }else{
            cout << "Invalid Input! Enter an integer in the range [0 - 1000]!" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
    return userInput;
}

