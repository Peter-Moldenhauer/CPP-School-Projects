/************************************************************************************************************
** Program Filename: main.cpp
** Author: Peter Moldenhauer
** Date: 11/27/16
** Assignment: Lab 10
** Description: This is the main.cpp file for the Lab 10 assignment. In this lab, I compare recursion versus
** iteration algorithms efficiency with implementations of fibonacci numbers calculation.
** Note: The recursive and non-recursive classes/functions used in this program are used from the website:
** https://www.codeproject.com/tips/109443/fibonacci-recursive-and-non-recursive-c
**************************************************************************************************************/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cstdio>
#include "FibonacciR.h"
#include "FibonacciNR.h"
using namespace std;

int getChoice();

int main(int argc, char** args) {
    int n;
    clock_t start;
    double duration;

    cout << "Enter the number of fibonacci numbers to calculate...";
    n = getChoice();
    cout << "Finding '"<<n<<"'th "<<"fibonacci number...." << endl;


    cout << "\nCalling Recursive Fibonacci implementation" << endl;
    start = clock();
    FibonacciR fr(n);
    fr.PrintFibonacci();
    duration = (clock() - start ) / (double) CLOCKS_PER_SEC;
    cout << "Duration to complete function: " << duration << endl;

    cout << "\nCalling Non-Recursive Fibonacci implementation" << endl;
    start = clock();
    FibonacciNR fnr(n);
    fnr.PrintFibonacci();
    duration = (clock() - start ) / (double) CLOCKS_PER_SEC;
    cout << "Duration to complete function: " << duration << endl;

    cout << "\nDone!!!!" << endl;

    return 0;
  }

/***********************************************************************************************
 ** Function: getChoice()
 ** Description: This function gets an int input from the user
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *************************************************************************************************/
  int getChoice(){
    bool getData = true;
    int userInput;

    while (getData == true){
        cout << "\nEnter an integer here: ";
        cin >> userInput;
        if (userInput > 0 && userInput <= 1000000000000){
            getData = false;
        }else{
            cout << "Error! Enter an integer greater than 0!" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
    return userInput;
}
