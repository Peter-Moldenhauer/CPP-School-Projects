/********************************************************************************************************
*Name: Peter Moldenhauer
*Email: moldenhp@oregonstate.edu
*Date: 10/13/16
*Course: CS 162
*Assignment: Assignment 2
*Description: This program simulates a grocery shopping list. The Item and List class files are included
*with this main program. In this program, the user can create a list, add items, remove items and display
*the shopping list.
*********************************************************************************************************/

#include "List.h"
#include <iostream>
#include <string>
using namespace std;

void showMenu(); // This function prints the opening menu to user
int getChoice(); // This function gets the input choice of the user from the menu

int main()
{
    List theList;  // Create a LIst object right away
    int choice;

    cout << "\n         Grocery Shopping List Program" << endl;
    cout << "             By: Peter Moldenhauer" << endl;

    do {
        showMenu(); // display menu to user
        choice = getChoice(); // get the input choice of the user from the menu
        cin.ignore();
        switch (choice) {
            case 1: theList.addItem();
                break;
            case 2: theList.deleteItem();
                break;
            case 3: theList.printList();
                break;
            case 4:
                break;
        }
    } while (choice != 4);

    cout << "\nExiting Grocery Shopping List Program, Goodbye! " << endl;

    return 0;
}

// This function displays the opening menu to the user
void showMenu(){
    cout << "\nPlease select one of the following options: " << endl;
    cout << "1) Add an item to the list" << endl;
    cout << "2) Remove an item from the list" << endl;
    cout << "3) Output the list items to the screen" << endl;
    cout << "4) Exit" << endl;
}

// This function prompts user for menu selection choice and validates the input
int getChoice(){
    bool getData = true;
    int userInput;

    while (getData == true){
        cout << "[Enter 1 - 4]: ";
        cin >> userInput;
        if (userInput > 0 && userInput <= 4){
            getData = false;
        }else{
            cout << "Please enter either 1, 2, 3 or 4 to make your selection!" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
    return userInput;
}
