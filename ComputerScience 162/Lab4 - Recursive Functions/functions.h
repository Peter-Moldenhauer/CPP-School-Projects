/**************************************************************************************
*Name: Peter Moldenhauer
*Email: moldenhp@oregonstate.edu
*Date: 10/19/16
*Course: CS 162
*Assignment: Lab 4
*Description: This is a header file that contains functions used in the Lab 4 program
***************************************************************************************/

#include <iostream>
#include <string>
#include <cstring> // for strcmp
#include <cstdlib>  // for atoi
using namespace std;

void reverseString(string str); // recursive function prototype to reverse a string

int sumOfArray(int theArray[], int arrayLength); // recursive function to calculate the sum of an array

int triangleNumber(int n); // recursive function to calculate the triangle number of n

void showMenu();  // this function displays a menu to the screen for the user

int getChoice();  // This function validates user input on which menu selection is made

void doRecursiveFunctions(int c);  // This function completes the specific action that the user selects from the menu
