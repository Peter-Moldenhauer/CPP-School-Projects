/********************************************************************************************************
*Name: Peter Moldenhauer
*Email: moldenhp@oregonstate.edu
*Date: 10/11/16
*Course: CS 162
*Assignment: Lab 3
*Description: This is the Game class .cpp file. The Game class uses inheritance to either create a Die
*class object or a LoadedDie class object. The Game class plays the game and prints the game results.
*********************************************************************************************************/

#include "Game.h"
#include "Die.h"
#include "LoadedDie.h"
#include <iostream>
using namespace std;

// constructor with parameters to initialize private data members and allocate memory for either Die or LoadedDie objects
Game::Game(int rounds, int p1Sides, int p2Sides, bool p1Loaded, bool p2Loaded){
    numRounds = rounds;
    curRound = 1;
    p1Score = 0;
    p2Score = 0;

    p1 = p1Loaded ? new LoadedDie(p1Sides) : new Die(p1Sides);

    p2 = p2Loaded ? new LoadedDie(p2Sides) : new Die(p2Sides);
}

// destructor deallocates memory at the end of the program
Game::~Game(){
    delete p1;
    delete p2;
}

// the playGame function calls the die object functions to "roll the die" and play the game
void Game::playGame(){
    while(numRounds > 0){ // keep looping for the specified number of rounds
        cout << "\nRound " << curRound << ": " << endl;

        int rollP1 = p1->rollDie(); // roll die for player 1
        int rollP2 = p2->rollDie(); // roll die for player 2

        cout << "Player 1 rolled: " << rollP1 << endl;
        cout << "Player 2 rolled: " << rollP2 << endl;

        if(rollP1 > rollP2){
            p1Score++;
            cout << "Player 1 wins this round, score increased! " << endl;
        }
        else if(rollP1 < rollP2){
            p2Score++;
            cout << "Player 2 wins this round, score increased! " << endl;
        }
        else
            cout << "Round is a draw! No increase in scores." << endl;

        cout << "-------------------------------------------";

        curRound++;
        numRounds--;
    }
}

// this function outputs the final scores of the game
void Game::printResults(){
    cout << "\n\nFinal results of the game: \n" << endl;

    cout << "Player 1 won " << p1Score << " round(s). Final Score: " << p1Score << endl;
    cout << "Player 2 won " << p2Score << " round(s). Final Score: " << p2Score << endl;

    if(p1Score > p2Score)
        cout << "\nPlayer 1 WINS!!!";
    else if(p1Score < p2Score)
        cout << "\nPlayer 2 WINS!!!";
    else
        cout << "Game is a TIE!!!";

    cout << endl;
}
