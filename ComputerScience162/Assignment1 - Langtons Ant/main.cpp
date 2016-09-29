/********************************************************************************************************
*Name: Peter Moldenhauer
*Email: moldenhp@oregonstate.edu
*Date: 9/28/16
*Course: CS 162
*Assignment: Assignment 1
*Description: This program implements a simulation of Langton's Ant. For the ant, there are a few simple
*rules: In a white square, turn right 90 degrees and change the square to black, in a black square, turn
*left 90 degrees and change the square to white. The ant then moves forward to the next cell and repeats
*from step 1.
*********************************************************************************************************/

#include "Ant.h"
#include <iostream>
#include <cstdlib>  //needed for the rand() function
#include <ctime>  //needed to access computer clock to seed a random number
#include <cstdlib>  //Delete when compiling on FLIP? This is used for clear screen in windows
using namespace std;


int main()
{
    int numRows, numCols, steps, row, col;
    char ranStart;
    bool getData1 = true;


    cout << "\n     *** This program will implement a simulation of Langton's Ant. ***     \n" << endl;
    while (getData1 == true){
        cout << "Enter the number of rows you want for the starting board size: ";
        cin >> numRows;
        if (numRows > 0){
            getData1 = false;
        }else{
            cout << "The number of rows must be greater than 0! Try again! " << endl;
        }
    }
    getData1 = true;
    while (getData1 == true){
        cout << "Enter the number of columns you want for the starting board size: ";
        cin >> numCols;
        if (numCols > 0){
            getData1 = false;
        }else{
            cout << "The number of columns must be greater than 0! Try again! " << endl;
        }
    }
    getData1 = true;
    while (getData1 == true){
        cout << "Enter the number of steps that you want the ant to take (such as 100, 1000, or 10000): ";
        cin >> steps;
        if (steps > 0){
            getData1 = false;
        }else{
            cout << "The number of steps must be greater than 0! Try again! " << endl;
        }
    }
    getData1 = true;

    cout << "Would you like to have a random starting location for the ant? (Y/N): ";
    cin >> ranStart;


    if (ranStart=='Y' || ranStart=='y'){ //generate random row/column numbers if user wishes to use random starting location for ant
         srand(time(0));  //seed the random number with clock time to get a different set of random numbers each time
         row = (rand()% numRows);
         col = (rand()% numCols);
    }else{
        while (getData1 == true){
            cout << "Enter the row number (starting at row 1) in which you would like the ant to start at: ";
            cin >> row;
            if (row <= numRows && row > 0){
                row = row - 1;
                getData1 = false;
            }else{
                cout << "Starting row position must be within the specified number of rows! " << endl;
            }
        }
        while (getData1 == false){
            cout << "Enter the column number (starting at column 1) in which you would like the ant to start at: ";
            cin >> col;
            if (col <= numCols && col > 0){
                col = col - 1;
                getData1 = true;
            }else{
                cout << "Starting column position must be within the specified number of columns! " << endl;
            }
        }
    }

    Ant theAnt(row, col);  //create an Ant object

    cout << "\nHere we go! Press ENTER to begin...";
    cin.ignore();
    cin.get();

    //clear the screen
    cout << "\033[2J\033[1;1H" << endl;
    //system("CLS");   //used for testing on WINDOWS machine

    //create board
    char **board = new char*[numRows];
    for (int i=0; i<numRows; i++)
        board[i] = new char[numCols];


    //initialize board to blank spaces
    for (int i=0; i<numRows; i++){
        for (int j=0; j<numCols; j++){
            board[i][j] = ' ';
        }
    }
    board[row][col] = '*'; //create the ant symbol on board at starting location.


    //print out board to screen
    for (int i=0; i<numRows; i++){
        for (int j=0; j<numCols; j++){
            cout << board[i][j];
        }
        cout << endl;
    }

    //system("PAUSE");   //used for debugging in Windows

    //loop for the duration of the number of steps that was inputed by user
    for (int i=steps; i>0; i--){

        //clear screen first
        cout << "\033[2J\033[1;1H" << endl;
        //system("CLS");

        //if statement - if current color = white then change direction, row and col changes to #, row or col gets incremented, row and col mow changes to *,
        if (theAnt.getCurColor() == ' '){
            board[theAnt.getPRow()][theAnt.getPCol()] = '#';

            if(theAnt.getDirection() == north){
                theAnt.setDirection(east);
                col = theAnt.getCCol();
                col = col + 1;
                if (col >= numCols)
                    col = 0;
                theAnt.setCCol(col);
                if (board[theAnt.getCRow()][theAnt.getCCol()] == ' '){
                    theAnt.setCurColor(' ');
                }else{
                    theAnt.setCurColor('#');
                }
                board[theAnt.getCRow()][theAnt.getCCol()] = '*';
            }else if(theAnt.getDirection() == east){
                theAnt.setDirection(south);
                row = theAnt.getCRow();
                row = row + 1;
                if (row >= numRows)
                    row = 0;
                theAnt.setCRow(row);
                if (board[theAnt.getCRow()][theAnt.getCCol()] == ' '){
                    theAnt.setCurColor(' ');
                }else{
                    theAnt.setCurColor('#');
                }
                board[theAnt.getCRow()][theAnt.getCCol()] = '*';
            }else if(theAnt.getDirection() == south){
                theAnt.setDirection(west);
                col = theAnt.getCCol();
                col = col - 1;
                if (col < 0)
                    col = numCols - 1;
                theAnt.setCCol(col);
                if (board[theAnt.getCRow()][theAnt.getCCol()] == ' '){
                    theAnt.setCurColor(' ');
                }else{
                    theAnt.setCurColor('#');
                }
                board[theAnt.getCRow()][theAnt.getCCol()] = '*';
            }else if(theAnt.getDirection() == west){
                theAnt.setDirection(north);
                row = theAnt.getCRow();
                row = row - 1;
                if (row < 0)
                    row = numRows - 1;
                theAnt.setCRow(row);
                if (board[theAnt.getCRow()][theAnt.getCCol()] == ' '){
                    theAnt.setCurColor(' ');
                }else{
                    theAnt.setCurColor('#');
                }
                board[row][col] = '*';
            }
        }else if(theAnt.getCurColor() == '#'){
            board[row][col] = ' ';

            if(theAnt.getDirection() == north){
                theAnt.setDirection(west);
                col = theAnt.getCCol();
                col = col - 1;
                if (col < 0)
                    col = numCols - 1;
                theAnt.setCCol(col);
                if (board[theAnt.getCRow()][theAnt.getCCol()] == ' '){
                    theAnt.setCurColor(' ');
                }else{
                    theAnt.setCurColor('#');
                }
                board[theAnt.getCRow()][theAnt.getCCol()] = '*';
            }else if(theAnt.getDirection() == east){
                theAnt.setDirection(north);
                row = theAnt.getCRow();
                row = row - 1;
                if (row < 0)
                    row = numRows - 1;
                theAnt.setCRow(row);
                if (board[theAnt.getCRow()][theAnt.getCCol()] == ' '){
                    theAnt.setCurColor(' ');
                }else{
                    theAnt.setCurColor('#');
                }
                board[row][col] = '*';
            }else if(theAnt.getDirection() == south){
                theAnt.setDirection(east);
                col = theAnt.getCCol();
                col = col + 1;
                if (col >= numCols)
                    col = 0;
                theAnt.setCCol(col);
                if (board[theAnt.getCRow()][theAnt.getCCol()] == ' '){
                    theAnt.setCurColor(' ');
                }else{
                    theAnt.setCurColor('#');
                }
                board[theAnt.getCRow()][theAnt.getCCol()] = '*';
            }else if(theAnt.getDirection() == west){
                theAnt.setDirection(south);
                row = theAnt.getCRow();
                row = row + 1;
                if (row >= numRows)
                    row = 0;
                theAnt.setCRow(row);
                if (board[theAnt.getCRow()][theAnt.getCCol()] == ' '){
                    theAnt.setCurColor(' ');
                }else{
                    theAnt.setCurColor('#');
                }
                board[theAnt.getCRow()][theAnt.getCCol()] = '*';
            }
        }

        //print out board to screen
        for (int i=0; i<numRows; i++){
            for (int j=0; j<numCols; j++){
                cout << board[i][j];
            }
            cout << endl;
        }

        theAnt.setPRow(row);
        theAnt.setPCol(col);

        //system("PAUSE");     //used for debugging in Windows
    }


    //deallocate memory to prevent memory leak
    for (int i=0; i<numRows; i++)
        delete [] board[i];
    delete [] board;

    cout << endl;
    cout << endl;

    return 0;
}
