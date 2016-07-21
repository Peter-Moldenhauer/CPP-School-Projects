/***********************************************************************************
** Name: Peter Moldenhauer
** Date: 5/22/16
** Description: This is the header file for the TicTacToe class. This class
**allows two people to play the game. The TicTacToe class uses a Board object. This
**class contains a play method which keeps looping to actually play the game. This
**file also includes the Board class header file.
**************************************************************************************/

#include <iostream>
using namespace std;

#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP

#include "Board.hpp"    //include Board class header file

class TicTacToe
{
	private:
		Board board1;   //Board object
		char currentPlayer;  //keeps track of what player turn it is
	public:
		TicTacToe(char whoStarts);   //constructor with char parameter, who has the first move
		void play();   //this function starts the game
		int getXCoord();  //function for invalid x coordinate
		int getYCoord();  //function for invalid y coordinates
};

#endif
