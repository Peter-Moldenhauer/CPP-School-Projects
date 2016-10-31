/************************************************************************************************************
** Program Filename: Functions.h
** Author: Peter Moldenhauer
** Date: 10/30/16
** Assignment: Assignment 3
** Description: This is a header file for various functions that are used in the main.cpp file for a program
** that implements a fantasy combat game. These functions print out menu's to the screen, get and validate
** user input and run test fights between creatures.
** Input: Some of the functions in this file require user input.
** Output: Some of these functions output information to the user (menu's and results of test fights).
**************************************************************************************************************/

#include "Creature.h" // abstract base class
#include "Vampire.h"
#include "Barbarian.h"
#include "BlueMen.h"
#include "Medusa.h"
#include "HarryPotter.h"
#include <iostream>
#include <time.h> // for rand
#include <cstdlib>  //Delete when compiling on FLIP? This is used for clear screen in windows
using namespace std;

void showMenu(); // This function prints the opening menu to user

int getChoice(); // This function gets the input choice of the user from the menu

void showRules(); // This function displays the game rules and the descriptions of the creatures

int getCreature1(); // This function prompts user on which creature to use for player 1

int getCreature2(); // This function prompts user on which creature to use for player 2

void showTestMenu(); // This function prints out the menu for testing option

int getTestChoice(); // This function gets and verifies input for the testing suite menu

void runTests(int t); // This function runs test fights between characters
