/************************************************************************************************************
** Program Filename: main.cpp
** Author: Peter Moldenhauer
** Date: 11/10/16
** Assignment: Assignment 4
** Description: This is the main.cpp file for a program that implements a fantasy combat game. The "universe"
** contains Vampires, Barbarians, Blue Men, Medusa and Harry Potter. Each one of these will be derived from
** the abstract base Critter class. Each of the derived classes will have characteristics for attack, defense,
** armor and strength points.
** NOTE: TO RUN ON WINDOWS - flip the comments for the clear screen commands!!!
** Input: User inputs menu selection and which Critters to fight each other
** Output: Program outputs a simulation of Critters attacking each other.
**************************************************************************************************************/

#include "Queue.h"  // for storing Creature lineups
#include "Functions.h"  // for extra functions that are used in the program
#include "Creature.h"  // base class for all creatures
#include "Vampire.h"
#include "Barbarian.h"
#include "BlueMen.h"
#include "Medusa.h"
#include "HarryPotter.h"
#include "RunCombat.h"  // for running the tournament and printing tournament results
#include <iostream>  // for input and output
#include <time.h> // for rand
#include <cstdlib>  // used for the rand() function
#include <iomanip>  // for formating text output
#include <string>  // for using strings
using namespace std;


int main()
{
    // lineup containers
    Queue team1;
    Queue team2;

    // team name variables
    string team1Name;
    string team2Name;

    // output program title to user
    cout << "\n\t~*~ Fantasy Tournament Game ~*~" << endl;
    cout << "\t    By: Peter Moldenhauer" << endl;
    cout << "\t        CS 162 - Lab 7\n" << endl;

    // instructions to user - enter team names
    cout << "Begin by assigning team names for player 1 and player 2..." << endl;
    cout << "Enter a team name for player 1 here: ";
    getline(cin, team1Name);
    cout << "Enter a team name for player 2 here: ";
    getline(cin, team2Name);

    // instructions to user - assemble team lineups
    cout << "\nNext, assemble the lineups for each team..." << endl;
    cout << "How many creatures will be on each team? " << endl;
    const int num = getChoice2(); // get validated number of creatures

    // store pointer to creature objects in these arrays so the memory can be freed later
    Creature **array1 = new Creature*[num];
    Creature **array2 = new Creature*[num];

    // user enter the creature lineup for the first team
    cout << "\nNow enter the starting lineup of creatures in order that " << team1Name << " will be using..." << endl;
    creatureMenu();
    // load the array and Queue for player 1
    for (int i = 0; i < num; i++){
        int c = getChoice3(); // get validated choice of creature

        if (c == 1){
            array1[i] = new Vampire;
        }else if (c == 2){
            array1[i] = new Barbarian;
        }else if (c == 3) {
            array1[i] = new BlueMen;
        }else if (c == 4) {
            array1[i] = new Medusa;
        }else if (c == 5) {
            array1[i] = new HarryPotter;
        }
        array1[i]->setData(team1Name);  // initialize the data fields in the creature object
        team1.add(array1[i]);  // add creature to the lineup queue
    }

    // user enter the creature lineup for the second team
    cout << "\nNow enter the starting lineup of creatures in order that " << team2Name << " will be using..." << endl;
    creatureMenu();
    // load the array and Queue for player 2
    for (int i = 0; i < num; i++){
        int c = getChoice3(); // get validated choice of creature

        if (c == 1){
            array2[i] = new Vampire;
        }else if (c == 2){
            array2[i] = new Barbarian;
        }else if (c == 3) {
            array2[i] = new BlueMen;
        }else if (c == 4) {
            array2[i] = new Medusa;
        }else if (c == 5) {
            array2[i] = new HarryPotter;
        }
        array2[i]->setData(team2Name);  // initialize the data fields in the creature object
        team2.add(array2[i]);  // add creature to the lineup queue
    }

    // display the lineup for first team
    cout << "\n" << team1Name << " starting lineup: " << endl;
    for (int i = 0; i < num; i++){
        cout << i+1 << ") " << setw(10) << left << array1[i]->getName() << "\t";
    }
    cout << endl;

    // display the lineup for the second team
    cout << "\n" << team2Name << " starting lineup: " << endl;
    for (int i = 0; i < num; i++){
        cout << i+1 << ") " << setw(10) << left << array2[i]->getName() << "\t";
    }
    cout << endl;

    // user push enter to proceed with tournament (gives the user a chance to review the creatures that were just entered)
    cout << "\nLineups are set! Press ENTER to begin the tournament!";
    cin.ignore();
    cin.get();

    cout << "--------------------------------------------------------" << endl;

    // Build the run combat object and pass in list queues and team names
    RunCombat run1(&team1, &team2, team1Name, team2Name);

    // Play the tournament between the teams
    run1.playMatch();

    // Print out the final of the tournament
    run1.finalScore();

    // Give user the option to view the losing creatures in each round of the tournament
    run1.printLosers();

    cout << "\nExiting Fantasy Tournament Game. Goodbye!!!\n" << endl;

    // Delete all the Creature pointers in the arrays
    for (int i = 0; i < num; ++i){
        delete array1[i];
        delete array2[i];
    }

    // Delete the Creature arrays themselves
    delete [] array1;
    delete [] array2;

    return 0;
}
