/***********************************************************************************
** Name: Peter Moldenhauer
** Date: 5/22/16
** Description: This is the implementation file for the TicTacToe class. This class
**allows two people to play the game. The TicTacToe class uses a Board object. This
**class contains a play method which keeps looping to actually play the game. This
**file also contains the main function.
**************************************************************************************/

#include <iostream>
using namespace std;

#include "TicTacToe.hpp"  //include the TicTacToe class header file

TicTacToe::TicTacToe(char whoStarts)  //constructor with char parameter
{
	currentPlayer = whoStarts;
}

void TicTacToe::play()   //function to play the game
{
	board1.clearBoard();   //call clear board object from board class

	char player1 = 'X';
	char player2 = 'O';

	bool isDone = false;  //use bool type for while loop to play the game

	int x, y;  //these variables will be used in the while loop

	while (isDone == false)  //create game loop, keep going for the length that the players are playing the game
	{
		cout << "Player " << currentPlayer << ": Please enter your move..." << endl;

		board1.print();  //call function from Board class to print board

		x = getXCoord();  //get x and y coords from functions
		y = getYCoord();

		if (board1.makeMove(x, y, currentPlayer) == false){
			cout << "That spot is occupied!\n";
		}else{
			if (board1.gameState() == X_WON){
				cout << "The game is over! Player X has won! \n";
				board1.print();
				isDone = true; //this will end the game
			}
			if (board1.gameState() == O_WON){
				cout << "The game is over! Player O has won! \n";
				board1.print();
				isDone = true;  //this will end the game
			}
			if (board1.gameState() == DRAW){
				cout << "Its a tie game! \n";
				board1.print();
				isDone = true;  //this will end the game
			}
			if (board1.gameState() == UNFINISHED){
				cout << "Game unfinished, please continue... \n";
			}
			if (currentPlayer == player1){   //switch players
				currentPlayer = player2;
			}else{
				currentPlayer = player1;
			}
		}
	}
}

int TicTacToe::getXCoord()  //check to see if x coordinate is valid
{
	bool isInputBad = true;
	int x;

	while (isInputBad == true){
		cout << "Enter the X coordinate: ";
		cin >> x;

		if (x < 0 || x > 2){
			cout << "Invalid Coordinate!\n";
		}else{
			isInputBad = false;
		}
	}
	return x;
}

int TicTacToe::getYCoord()  //check to see if y coordinate is valid
{
	bool isInputBad = true;
	int y;

	while (isInputBad == true){
		cout << "Enter the Y coordinate: ";
		cin >> y;
		cout << "\n";

		if (y < 0 || y > 2){
			cout << "Invalid Coordinate!\n";
		}else{
			isInputBad = false;
		}
	}
	return y;
}


int main()  //main function
{
	char whoStartsInput;
	char whoStarts;
	char input;
	bool isDone = false;   //used in while loop below to see if players want to play again

	cout << "Welcome to Tic-Tac-Toe!" << endl;
	cout << "Please enter which player should go first. "<< endl;
	cout << "Enter O for player O to start or press any key for player X to start: ";
	cin >> whoStartsInput;

	if (whoStartsInput == 'O'){
		whoStarts = whoStartsInput;
	}else whoStarts = 'X';

	Board board1;  //board object
	TicTacToe game(whoStarts);  //tictactoe object

	while (isDone == false){  //loop to play the game
		game.play();
		cout << "Would you like to play again? (Y/N): ";
		cin >> input;
		if (input == 'N' || input == 'n'){
			isDone = true;  //if players do not want to play again, end loop
		}
	}
	return 0;
}





































































































