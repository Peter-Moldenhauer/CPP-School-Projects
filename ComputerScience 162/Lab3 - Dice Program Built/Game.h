/********************************************************************************************************
*Name: Peter Moldenhauer
*Email: moldenhp@oregonstate.edu
*Date: 10/11/16
*Course: CS 162
*Assignment: Lab 3
*Description: This is the Game class header file. The Game class uses inheritance to either create a Die
*class object or a LoadedDie class object. The Game class plays the game and prints the game results.
*********************************************************************************************************/

#include "Die.h"
#ifndef GAME_H
#define GAME_H
#include <iostream>
using namespace std;

class Game
{
    private:
        Die *p1;  // pointer to Die object
        Die *p2;  // pointer to Die object

        int numRounds;
        int curRound;
        int p1Score;
        int p2Score;

    public:
        Game(int rounds, int p1Sides, int p2Sides, bool p1Loaded, bool p2Loaded); //constructor with parameters

        ~Game();  // destructor will deallocate memory that is created in constructor

        void playGame();  // this function calls the die object functions to "roll the die" and play the game

        void printResults();  // this function outputs the final scores of the game
};

#endif // GAME_H
