/************************************************************************************************************
*Name: Peter Moldenhauer
*Email: moldenhp@oregonstate.edu
*Date: 10/19/16
*Course: CS 162
*Assignment: Lab 4
*Description: This program implements three functions using recursion and has a menu to call these functions.
*The first function recursively reverses a string, the second function will recursively calculate the sum of
*an array and the third function will calculate the triangular number for N.
**************************************************************************************************************/

#include "functions.h"

int main()
{
    int choice = -1;
    cout << "\nThis program demonstrates the use of recursive functions. " << endl;

    while (true){  // loop repeatedly

        cout << endl;
        cout << "Please enter your selection below." << endl;

        showMenu(); // display menu on screen

        while (choice < 1 || choice > 4){
            choice = getChoice(); // validate user input
        }

        doRecursiveFunctions(choice); // complete the task that the user selects

        choice = -1; // reset choice
    }

    return 0;
}


