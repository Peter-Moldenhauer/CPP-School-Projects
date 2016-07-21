/***********************************************************************************
** Name: Peter Moldenhauer
** Date: 5/22/16
** Description: This is the header file for the Board class. The Board class
**represents a tic-tac-toe board. It uses a 3x3 array as a data member, which stores
**the locations of the players' moves. The Board class also prints the current state
**of the tic-tac-toe board to the screen.
**************************************************************************************/

#include <iostream>
using namespace std;

#ifndef BOARD_HPP  //include guards
#define BOARD_HPP

enum State {X_WON, O_WON, DRAW, UNFINISHED};  //Need this for the gameState function

class Board //Board class
{
	private:
		char board[3][3];  //3x3 array to store locations of players moves

	public:
		Board();  //Default constructor
		bool makeMove(int x, int y, char currentPlayer); //This function checks to see if you can place a marker in a given spot
		State gameState(); //This is the enum function to return xwon owon draw or unfinished
		void clearBoard();  //This function is used to initialize the board to empty
		void print();  //This function prints the board to the screen
};

#endif






