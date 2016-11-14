/************************************************************************************************************
** Program Filename: Functions.h
** Author: Peter Moldenhauer
** Date: 11/10/16
** Assignment: Assignment 4
** Description: This is a header file for various functions that are used in the main.cpp file for a program
** that implements a fantasy combat game. These functions print out menu's to the screen, get and validate
** user input and run test fights between creatures.
** Input: Some of the functions in this file require user input.
** Output: Some of these functions output information to the user (menu's and results of test fights).
**************************************************************************************************************/

#include "Creature.h" // abstract base class for creatures
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

void creatureMenu(); // This function displays a menu of all of the creatures

int getChoice(); // This function gets the input choice of the user from the menu

int getChoice2(); // This function gets the input choice of the user from the menu

int getChoice3(); // This function gets the input choice of the user from the menu

int getCreature1(); // This function prompts user on which creature to use for player 1

int getCreature2(); // This function prompts user on which creature to use for player 2




