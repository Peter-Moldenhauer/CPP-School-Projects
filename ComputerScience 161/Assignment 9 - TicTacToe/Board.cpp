/***********************************************************************************
** Name: Peter Moldenhauer
** Date: 5/22/16
** Description: This is the implementation file for the Board class. The Board class
**represents a tic-tac-toe board. It uses a 3x3 array as a data member, which stores
**the locations of the players' moves. The Board class also prints the current state
**of the tic-tac-toe board to the screen.
**************************************************************************************/

#include "Board.hpp"  //include Board class header file

Board::Board()
{                    //Default constructor
	clearBoard();  //This function is called to initialize all fields to empty
}

bool Board::makeMove(int x, int y, char currentPlayer)  //checks to see if you can place a marker in a spot, if a spot is unoccupied
{
	if (board[y][x] != ' '){
		return false;
	}
	board[y][x] = currentPlayer;
	return true;
}

State Board::gameState()  //This function checks for wins, draw or unfinished
{
	for (int i = 0; i < 3; i++){  //Check rows for X
		if ((board[i][0] == 'X') && (board[i][0] == board[i][1]) && (board[i][1] == board[i][2])){
			return X_WON;
		}
	}
	for (int i = 0; i < 3; i++){  //Check rows for O
		if ((board[i][0] == 'O') && (board[i][0] == board[i][1]) && (board[i][1] == board[i][2])){
			return O_WON;
		}
	}
	for (int i = 0; i < 3; i++){  //Check columns for X
		if ((board[0][i] == 'X') && (board[0][i] == board[1][i]) && (board[1][i] == board[2][i])){
			return X_WON;
		}
	}
	for (int i = 0; i < 3; i++){  //Check columns for O
		if ((board[0][i] == 'O') && (board[0][i] == board[1][i]) && (board[1][i] == board[2][i])){
			return O_WON;
		}
	}
	//Check top left diagonal for X
	if ((board[0][0] == 'X') && (board[0][0] == board[1][1]) && (board[1][1] == board[2][2])){
		return X_WON;
	}
	//Check top left diagonal for O
	if ((board[0][0] == 'O') && (board[0][0] == board[1][1]) && (board[1][1] == board[2][2])){
		return O_WON;
	}
	//Check top right diagonal for X
	if ((board[0][2] == 'X') && (board[0][2] == board[1][1]) && (board[1][1] == board[2][0])){
		return X_WON;
	}
	//Check the top right diagonal for O
	if ((board[0][2] == 'O') && (board[0][2] == board[1][1]) && (board[1][1] == board[2][0])){
		return O_WON;
	}
	//Check to see if its a Draw
	int space = 0;
	for (int rows = 0; rows < 3; rows++){
		for (int columns = 0; columns < 3; columns++){
			if ((board[rows][columns] == 'X') || (board[rows][columns] == 'O')){
				space++;
			}
		}
	}
	if (space == 9){
		return DRAW;
	}
	return UNFINISHED;   //Return unfinished if none of the above choices are true
}

void Board::clearBoard()  //This is the function that is called in the default construcor to make board empty
{
	for (int rows = 0; rows < 3; rows++){
		for (int columns = 0; columns < 3; columns++){
			board[rows][columns] = ' ';
		}
	}
}

void Board::print()  //this function prints the tic tac toe board to the screen
{
	cout << endl;
	cout << "  0 1 2 \n";
	for (int row = 0; row < 3; row++){
		cout << " -------\n";
		cout << row << "|" << board[row][0] << "|" << board[row][1] << "|" << board[row][2] << "|\n";
	}
	cout << " -------\n";
}

















































