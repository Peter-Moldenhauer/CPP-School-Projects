/*************************************************************************************************
** Name: Peter Moldenhauer
** Description: This file is a UTILITY file for future C++ programs. This file contains various
** functions and code segments that I wanted to save for future programs that I will build.
**************************************************************************************************/


#include <iostream>
using namespace std;

int main()
{
    /*****************************************************
    //Clear the Screen

    cout <<"\033[2J\033[1;1H";  //Used in LINUX!

    system("CLS");             //Used in WINDOWS!
    ******************************************************/


    /***********************************************************
    //Enumerated data type

    //put this outside of main or in header file
    enum Direction { north, east, south, west };

    //Use this in the private area of a class
    Direction dir;

    //Use this in the public area of a class
    void setDirection(Direction d);
    Direction getDirection();

    //Use in class .cpp file
    void Ant::setDirection(Direction d){
        dir = d;
    }

    //Use in class .cpp file
    Direction Ant::getDirection(){
        return dir;
    }
    ******************************************************************/


    /**************************************************************************
    //Dynamically create a 2D array, initialize it, print it and delete it

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

    //print out board to screen
    for (int i=0; i<numRows; i++){
        for (int j=0; j<numCols; j++){
            cout << board[i][j];
        }
        cout << endl;
    }

    //deallocate memory to prevent memory leak
    for (int i=0; i<numRows; i++)
        delete [] board[i];
    delete [] board;
    *********************************************************************************/


    /********************************************************
    //Press ENTER to continue

    cout << "\nHere we go! Press ENTER to begin...";
    cin.ignore();
    cin.get();
    **********************************************************/


    /*****************************************************************************************
    //Random number generator

    #include <cstdlib>  //needed for the rand() function
    #include <ctime>  //needed to access computer clock to seed a random number

    cout << "Would you like to have a random starting location for the ant? (Y/N): ";
    cin >> ranStart;

    if (ranStart=='Y' || ranStart=='y'){ //generate random row/column numbers if user wishes to use random starting location for ant
         srand(time(0));  //seed the random number with clock time to get a different set of random numbers each time
         row = (rand()% numRows);
         col = (rand()% numCols);
    }else{
    *******************************************************************************************/


    /**********************************************************************************
    //Validate user input - validates that input is a positive integer
	//this does not allow letters, characters, negative numbers or zero to be input

    bool getData1 = true;

    while (getData1 == true){
        cout << "Enter the number of rows you want for the starting board size: ";
        cin >> numRows;
        if (numRows > 0){
            getData1 = false;
        }else{
            cout << "The number of rows must be an integer greater than 0! Try again! " << endl;
			cin.clear();
			cin.ignore();
        }
    }
    *************************************************************************************/


    return 0;
}
