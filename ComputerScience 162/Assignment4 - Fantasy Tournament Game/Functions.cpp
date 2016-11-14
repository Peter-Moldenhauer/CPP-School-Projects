/************************************************************************************************************
** Program Filename: Functions.cpp
** Author: Peter Moldenhauer
** Date: 11/10/16
** Assignment: Assignment 4
** Description: This is the .cpp file for various functions that are used in the main.cpp file for a program
** that implements a fantasy combat game. These functions print out menu's to the screen, get and validate
** user input and run test fights between creatures.
** Input: Some of the functions in this file require user input.
** Output: Some of these functions output information to the user (menu's and results of test fights).
**************************************************************************************************************/

#include "Functions.h"

/***********************************************************************************************
* Function: showMenu()
* Description: This function displays the opening menu to the user
* Parameters: none
* Pre-Conditions: none
* Post-Conditions: none
* Return: none
*************************************************************************************************/
void showMenu(){
    cout << "Please select one of the following options... " << endl;
    cout << "1) View game rules and descriptions of creatures." << endl;
    cout << "2) Start combat between two creatures." << endl;
    cout << "3) Run test driver to simulate all possible creature attacks." << endl;
    cout << "4) Exit program." << endl;
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
        cout << "Enter [1 - 4]: ";
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

/***********************************************************************************************
* Function: getChoice2()
* Description: This function prompts user for menu selection choice and validates the input
* Parameters: none
* Pre-Conditions: Beginning menu has to be displayed to the user first
* Post-Conditions: none
* Return: user menu choice
*************************************************************************************************/
int getChoice2(){
    bool getData = true;
    int userInput;

    while (getData == true){
        cout << "Enter the number of creatures here: ";
        cin >> userInput;
        if (userInput > 0 && userInput <= 10){
            getData = false;
        }else{
            cout << "Error! Please enter a number in the range of 1 - 10." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
    return userInput;
}

/***********************************************************************************************
* Function: getChoice3()
* Description: This function prompts user for menu selection choice and validates the input
* Parameters: none
* Pre-Conditions: Beginning menu has to be displayed to the user first
* Post-Conditions: none
* Return: user menu choice
*************************************************************************************************/
int getChoice3(){
    bool getData = true;
    int userInput;

    while (getData == true){
        cout << "Enter creature number here: ";
        cin >> userInput;
        if (userInput > 0 && userInput <= 5){
            getData = false;
        }else{
            cout << "Error! Please enter a number in the range of 1 - 5." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
    return userInput;
}

/***********************************************************************************************************************
* Function: getCreature1()
* Description: This function prompts user on which creature to use for player 1, it also verifies that input is correct
* Parameters: none
* Pre-Conditions: user must choose to start a two player game first via the main menu
* Post-Conditions: none
* Return: user input of which creature they want to select
*************************************************************************************************************************/
int getCreature1(){
    //cout <<"\033[2J\033[1;1H";   // clear the screen
    system("CLS");                 // clear the screen WINDOWS

    cout << "Which creature will player 1 be using... " << endl;
    cout << "1) Vampire" << endl;
    cout << "2) Barbarian" << endl;
    cout << "3) Blue Men" << endl;
    cout << "4) Medusa" << endl;
    cout << "5) Harry Potter" << endl;

    bool getData = true;
    int userInput;

    while (getData == true){
        cout << "Enter [1 - 5]: ";
        cin >> userInput;
        if (userInput > 0 && userInput <= 5){
            getData = false;
        }else{
            cout << "Please enter either 1, 2, 3, 4 or 5 to make your selection!" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
    return userInput;
}

/***********************************************************************************************************************
* Function: getCreature2()
* Description: This function prompts user on which creature to use for player 2, it also verifies that input is correct
* Parameters: none
* Pre-Conditions: user must choose to start a two player game first via the main menu
* Post-Conditions: none
* Return: user input of which creature they want to select
*************************************************************************************************************************/
int getCreature2(){

    cout << "\nWhich creature will player 2 be using... " << endl;
    cout << "1) Vampire" << endl;
    cout << "2) Barbarian" << endl;
    cout << "3) Blue Men" << endl;
    cout << "4) Medusa" << endl;
    cout << "5) Harry Potter" << endl;

    bool getData = true;
    int userInput;

    while (getData == true){
        cout << "Enter [1 - 5]: ";
        cin >> userInput;
        if (userInput > 0 && userInput <= 5){
            cout << endl;
            getData = false;
        }else{
            cout << "Please enter either 1, 2, 3, 4 or 5 to make your selection!" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
    return userInput;
}

/*********************************************************************
** Function: creatureMenu()
** Description: Prints the character selection options for the user.
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void creatureMenu(){
    cout << "For each creature, please enter the corresponding number." << endl;
    cout << "1) Vampire" << endl;
    cout << "2) Barbarian" << endl;
    cout << "3) Blue Men" << endl;
    cout << "4) Medusa" << endl;
    cout << "5) Harry Potter" << endl;
}
