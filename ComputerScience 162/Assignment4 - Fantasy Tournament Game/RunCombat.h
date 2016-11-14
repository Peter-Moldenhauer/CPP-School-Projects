/************************************************************************************************************
** Program Filename: RunCombat.h
** Author: Peter Moldenhauer
** Date: 11/10/16
** Assignment: Assignment 4
** Description: This is the RunCombat class header file. The RunCombat class runs a tournament consisting of
** matchups between two teams of Creatures lined up in Queues. It can also determine the winning team and other
** info about the tournament when a tournament ends.
** Input: Creature pointers in Queue
** Output: Runs tournament and prints out tournament info
**************************************************************************************************************/

#ifndef RUNCOMBAT_H
#define RUNCOMBAT_H

#include "Queue.h"  // for storing Creature lineups
#include "Stack.h" // for storing creature losers
#include "Creature.h"  // base class for creatures
#include "Vampire.h"
#include "Barbarian.h"
#include "BlueMen.h"
#include "Medusa.h"
#include "HarryPotter.h"
#include <iostream> // for input and output
#include <ctime>    // for time()
#include <time.h> // for rand
#include <cstdlib>  // used for the rand() function
using namespace std;

class RunCombat
{
    private:
        // names for each team
        string team1Name;
        string team2Name;

        // which team won/loss
        bool p1Won;
        bool p2Won;

        // each players creature lineups
        Queue *side1;
        Queue *side2;

        // running total of points earned throughout tournament
        int side1pts;
        int side2pts;

        // loser pile for creatures who lost in each round
        Stack *losers;

        // current number of rounds in tournament
        int numRounds;

    public:
        // constructor
        RunCombat(Queue* s1, Queue* s2, string t1, string t2);

        // destructor (frees memory)
        ~RunCombat();

        // start tournament
        void playMatch();

        // display final score of tournament
        void finalScore();

        // gives user the option to view losing creatures in stack
        void printLosers();
};

#endif // RUNCOMBAT_H
