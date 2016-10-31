/************************************************************************************************************
** Program Filename: main.cpp
** Author: Peter Moldenhauer
** Date: 10/30/16
** Assignment: Assignment 3
** Description: This is the main.cpp file for a program that implements a fantasy combat game. The "universe"
** contains Vampires, Barbarians, Blue Men, Medusa and Harry Potter. Each one of these will be derived from
** the abstract base Critter class. Each of the derived classes will have characteristics for attack, defense,
** armor and strength points.
** Input: User inputs menu selection and which Critters to fight each other
** Output: Program outputs a simulation of Critters attacking each other.
**************************************************************************************************************/

#include "Functions.h"
#include "Creature.h"  // base class
#include "Vampire.h"
#include "Barbarian.h"
#include "BlueMen.h"
#include "Medusa.h"
#include "HarryPotter.h"
#include <iostream>
#include <time.h> // for rand
#include <cstdlib>  // used for the rand() function
using namespace std;

int main()
{
    srand(time(0));  //seed the random number with clock time to get a different set of random numbers each time
    int choice;

    cout << "\n\t~*~ Fantasy Combat Game ~*~" << endl;
    cout << "\t    By: Peter Moldenhauer\n" << endl;

    // This is the main loop to display the menu and run the specific parts of the program based on user input
    do {
        showMenu(); // display menu to user
        choice = getChoice(); // get the input choice of the user from the menu
        cin.ignore();
        switch (choice) {
            case 1:  // Case 1 is just an output of the game rules and description of each creature
                showRules();
                break;
            case 2:  // Case 2 is the actual game play where two players can select their creatures and attack each other
                {
                int player1, player2;
                int damage;
                Creature *creature1;
                Creature *creature2;

                player1 = getCreature1();
                player2 = getCreature2();

                // create the creature for player 1
                if (player1 == 1){
                    creature1 = new Vampire;
                    //cout << "creature1 is now a Vampire" << endl;
                }else if (player1 == 2){
                    creature1 = new Barbarian;
                    //cout << "creature1 is now a Barbarian" << endl;
                }else if (player1 == 3) {
                    creature1 = new BlueMen;
                    //cout << "creature1 is now Blue Men" << endl;
                }else if (player1 == 4) {
                    creature1 = new Medusa;
                    //cout << "creature1 is now a Medusa" << endl;
                }else if (player1 == 5) {
                    creature1 = new HarryPotter;
                    //cout << "creature1 is now Harry Potter" << endl;
                }

                // create the creature for player 2
                if (player2 == 1) {
                    creature2 = new Vampire;
                    //cout << "creature2 is now a Vampire" << endl;
                }else if (player2 == 2){
                    creature2 = new Barbarian;
                    //cout << "creature2 is now a Barbarian" << endl;
                }else if (player2 == 3) {
                    creature2 = new BlueMen;
                    //cout << "creature2 is now Blue Men" << endl;
                }else if (player2 == 4) {
                    creature2 = new Medusa;
                    //cout << "creature2 is now a Medusa" << endl;
                }else if (player2 == 5) {
                    creature2 = new HarryPotter;
                    //cout << "creature2 is now Harry Potter" << endl;
                }

                // initialize the data members for the creatures...could have used constructor instead? These functions do the same thing...
                creature1->setData();
                creature2->setData();

                // confirm each players creature
                cout << "Player 1 is: " << creature1->getName() << endl;
                cout << "Starting armor: " << creature1->getArmor() << endl;
                cout << "Starting strength: " << creature1->getStrength() << endl;
                cout << endl;
                cout << "Player 2 is: " << creature2->getName() << endl;
                cout << "Starting armor: " << creature2->getArmor() << endl;
                cout << "Starting strength: " << creature2->getStrength() << endl;

                //Code here to Randomly pick and display which player will go first
                int x = rand() % 2 + 1;
                if (x == 1)
                    cout << "\nPlayer 1 was randomly selected to start first!" << endl;
                else
                    cout << "\nPlayer 2 was randomly selected to start first!" << endl;

                // hit enter to continue
                cout << "\nPress ENTER to begin the attacks...";
                cin.ignore();
                cin.get();
                cin.sync();

                // clear the screen
                //cout <<"\033[2J\033[1;1H";   // clear the screen FLIP
                system("CLS");                 // clear the screen WINDOWS

                // bool variables used to determine if each creature died or not
                bool p1Dead = false;
                bool p2Dead = false;

                // PLAYER 1 GOES FIRST - main loop to simulate the attacks and defense
                if (x ==1){
                    while (p1Dead == false && p2Dead == false){
                        cout << "Player 1 attack:" << endl;
                        damage = creature1->attack(); // creature1 attack
                        cout << "\nPlayer 2 defense:" << endl;
                        creature2->defense(damage);  // creature2 defend

                        p2Dead = creature2->isDead(); // check to see if creature2 died

                        if (p2Dead == false){
                            cout << "\nPlayer 2 attack:" << endl;
                            damage = creature2->attack(); // creature2 attack
                            cout << "\nPlayer 1 defense:" << endl;
                            creature1->defense(damage); // creature1 defend
                            cout << endl;
                        }
                        p1Dead = creature1->isDead(); // check to see if creature1 died
                    }
                }else{ // PLAYER 2 GOES First
                    while (p1Dead == false && p2Dead == false){
                        cout << "Player 2 attack:" << endl;
                        damage = creature2->attack(); // creature 2 attack
                        cout << "\nPlayer 1 defense:" << endl;
                        creature1->defense(damage);  // creature 1 defend

                        p1Dead = creature1->isDead(); // check to see if creature1 died

                        if (p1Dead == false){
                            cout << "\nPlayer 1 attack:" << endl;
                            damage = creature1->attack(); // creature2 attack
                            cout << "\nPlayer 2 defense:" << endl;
                            creature2->defense(damage); // creature1 defend
                            cout << endl;
                        }
                        p2Dead = creature2->isDead(); // check to see if creature1 died
                    }
                }

                // Game over, display winner/loser
                if (p1Dead == true){
                    cout << "\n*** Battle over - Player 2 Wins with " << creature2->getName() << "!!! ***" << endl;
                }else if(p2Dead == true){
                    cout << "\n*** Battle over - Player 1 Wins with " << creature1->getName() << "!!! ***" << endl;
                }

                // hit enter to return to main menu
                cout << "\nPress ENTER to return to the main menu...";
                //cin.ignore();
                cin.get();

                // clear the screen
                //cout <<"\033[2J\033[1;1H";   // clear the screen FLIP
                system("CLS");                 // clear the screen WINDOWS

                // deallocate memory
                delete creature1;
                delete creature2;
                }
                break;
            case 3: // Case 3 is a testing suite that the user can automatically run test attacks with each creature match up
                showTestMenu(); // show testing menu
                int tChoice;
                tChoice = getTestChoice(); // get choice of testing menu
                cin.clear();
                cin.ignore(1000, '\n');

                // if statements here to run each test possibility
                runTests(tChoice);

                cout << "\nPress ENTER to return to the main menu...";
                cin.get();

                // clear the screen
                //cout <<"\033[2J\033[1;1H";   // clear the screen FLIP
                system("CLS");                 // clear the screen WINDOWS

                break;
            case 4:  // Case 4 just exits the program
                break;
        }
    } while (choice != 4); // if user enters 4 in the main menu then the program exits

    cout << "\nExiting Fantasy Combat Game, Goodbye! " << endl;

    return 0;
}
