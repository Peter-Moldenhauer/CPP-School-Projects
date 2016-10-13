/********************************************************************************************************
*Name: Peter Moldenhauer
*Email: moldenhp@oregonstate.edu
*Date: 10/11/16
*Course: CS 162
*Assignment: Lab 3
*Description: This program implements the program that I designed in Lab 2. This program contains the
*Die, LoadedDie and Game classes. Together, these classes are used to simulate a dice rolling game.
*********************************************************************************************************/

#include "Game.h"
#include <iostream>
#include <string>
#include <cstdlib>  //Delete when compiling on FLIP? This is used for clear screen in windows
#include <time.h>   //need for rand
using namespace std;

int getSides(string player);   //function to get and verify number of sides on die
bool loadedOrNot(string player);  //function to get and verify if die is loaded or regular
int getRounds();             // function to get and verify the number of rounds to be played

int main()
{
    srand(time(0));  //seed the random number with clock time to get a different set of random numbers each time

    string p1 = "Player 1", p2 = "Player 2";
    string p1LoadedOrNot, p2LoadedOrNot;
    int p1Sides, p2Sides, rounds;
    bool p1Loaded, p2Loaded;

    cout << "\n                 welcome to the Dice Rolling Game! " << endl;
    cout << "                       By: Peter Moldenhauer" << endl;
    cout << "\nThis game will simulate a game of two players taking turns to roll a dice. " << endl;
    cout << "The user will specify the number of sides of die that each player is using. " << endl;
    cout << "The user will also specify if each player is using a loaded die or regular die." << endl;
    cout << "The game will continue for a user-specified number of rounds. " << endl;
    cout << "In each round, the player with the highest die roll will win the round. " << endl;
    cout << "The winner of the game is the player who won the most rounds. \n" << endl;

    p1Sides = getSides(p1);       // get the number of sides of die for player 1
    p1Loaded = loadedOrNot(p1);   // check to see if player 1's die is loaded or regular

    p2Sides = getSides(p2);       // get the number of sides of die for player 2
    p2Loaded = loadedOrNot(p2);   // check to see if player 2's die is loaded or regular

    rounds = getRounds();         // get the number of rounds to play

    // generate strings for output to user to inform user what type of die each player is using.
    if(p1Loaded == true)
        p1LoadedOrNot = "that is loaded. ";
    else
        p1LoadedOrNot = "that is not loaded. ";
    if(p2Loaded == true)
        p2LoadedOrNot = "that is loaded. ";
    else
        p2LoadedOrNot = "that is not loaded. ";

    // give output to user to inform user of how many sides and of what type of die each player is using.
    cout << "\nPlayer 1 will be using a " << p1Sides << " sided die " << p1LoadedOrNot << endl;
    cout << "Player 2 will be using a " << p2Sides << " sided die " << p2LoadedOrNot << endl;
    cout << "The game will continue for a total of " << rounds << " round(s). " << endl;

    cout << "\nLet the game begin! Press ENTER to start...";
    cin.ignore();
    cin.get();

    cout <<"\033[2J\033[1;1H";   // clear the screen
    //system("CLS");                 // clear the screen

    Game g1(rounds, p1Sides, p2Sides, p1Loaded, p2Loaded);  //create a Game object to play the game

    g1.playGame();  // call the play game function in the Game class to play the game

    g1.printResults();  // call the print results function in Game class to output to user the results of the game.

    // give output to user again to inform user of how many sides and of what type of die each player was using.
    cout << "\nPlayer 1 was using a " << p1Sides << " sided die " << p1LoadedOrNot << endl;
    cout << "Player 2 was using a " << p2Sides << " sided die " << p2LoadedOrNot << endl;
    cout << "The game continued for a total of " << rounds << " round(s). " << endl;

    return 0;
}

/********************************************************
* This function is used in main to prompt for number of
* sides for a die. It then validates that the number the
* user entered is an integer that is greater than 0. This
* function will then return the number of sides that the
* user enters.
**********************************************************/
int getSides(string player){
    bool getData = true;
    int numSides;

    while (getData == true){
        cout << "Enter the number of sides on the die for " << player <<": ";
        cin >> numSides;
        if (numSides > 0){
            getData = false;
        }else{
            cout << "The number of sides on the die must be an integer greater than 0! Try again! " << endl;
            cin.clear();
            cin.ignore();
        }
    }
    return numSides;
}


/********************************************************
* This function is used in main to the user to see if a
* die is to loaded or not. The function will also validate
* the user input. The function will return a bool variable
* that is either true or false based on user input.
**********************************************************/
bool loadedOrNot(string player){
    bool getData = true, loaded;
    char c;

    while (getData == true){
        cout << "Do you want " << player <<" to use a loaded die? Y/N ";
        cin >> c;
        if (c == 'y' || c == 'Y'){
            loaded = true;
            getData = false;
        }else if(c == 'n' || c == 'N'){
            loaded = false;
            getData = false;
        }else{
            cout << "Please enter either Y/N! Try again! " << endl;
            cin.clear();
            cin.ignore();
        }
    }
    return loaded;
}


/********************************************************
* This function is used in main to prompt for number of
* rounds to play. It then validates that the number the
* user entered is an integer greater than 0. This function
* then returns the number that the user entered.
**********************************************************/
int getRounds(){
    bool getData = true;
    int numRounds;

    while (getData == true){
        cout << "Enter the number of rounds that you want in the game: ";
        cin >> numRounds;
        if (numRounds > 0){
            getData = false;
        }else{
            cout << "The number of rounds in the game must be an integer greater than 0! Try again! " << endl;
            cin.clear();
            cin.ignore();
        }
    }
    return numRounds;
}
