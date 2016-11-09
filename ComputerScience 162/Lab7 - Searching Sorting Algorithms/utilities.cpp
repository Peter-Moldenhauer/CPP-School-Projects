/*********************************************************************
 ** Program Filename: utilities.cpp
 ** Author: Peter Moldenhauer
 ** Date: 11/8/15
 ** Description: This file provides implementations for each function
 ** declared in utilities.h
 ** Input:
 ** Output:
 *********************************************************************/

#include "utilities.h"
#include <cstdlib>          // for exit
#include <fstream>          // for file opening
#include <iostream>         // for input and output
#include <limits>           // for clearing the input buffer
#include <string>           // for string


/***************************************************************************
 ** Function: showMenu()
 ** Description: Displays the opening menu to the user
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: Menu is displayed on screen
 *****************************************************************************/
 void showMenu(){
    //cout << "-- MAIN MENU --" << endl;
    cout << "\nPlease select one of the following options..." << endl;
    cout << "1) Linear Search" << endl;
    cout << "2) Bubble Sort" << endl;
    cout << "3) Binary Search" << endl;
    cout << "4) Exit program" << endl;
}


/***********************************************************************************************
 ** Function: getChoice()
 ** Description: This function prompts user for menu selection choice and validates the input
 ** Parameters: none
 ** Pre-Conditions: Beginning menu has to be displayed to the user first
 ** Post-Conditions: none
 *************************************************************************************************/
 int getChoice(){
    bool getData = true;
    int userInput;

    while (getData == true){
        cout << "Enter [1 - 4]: ";
        cin >> userInput;
        if (userInput > 0 && userInput <= 4){
            getData = false;
        }else{
            cout << "Please enter either 1, 2, 3 or 4 to make your selection!" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
    return userInput;
}


/*********************************************************************
 ** Function: get_valid_int()
 ** Description: Waits for the user to enter a valid int value.
 ** Each time the user enters an invalid value, it prompts the user
 ** with an error message to try again.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: A user-input int is returned.
 *********************************************************************/
int get_valid_int()
{
    int in_val = 0;

    // get input till valid int is received
    while (!(cin >> in_val))
    {
        cout << "Bad input!  Please enter an integer.\n";

        // clear error bits
        cin.clear();
        // ignore the rest of the input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // clear any trailing characters in the input buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return in_val;
}



/*********************************************************************
 ** Function: get_valid_int_in_range()
 ** Description: Waits for the user to enter a valid int value
 ** between low and high. Each time the user enters an invalid value,
 ** it prompts the user with an error message to try again.
 ** Parameters: low - the minimum value allowed, high - the maximum
 ** value allowed
 ** Pre-Conditions: low is less than high.
 ** Post-Conditions: A user-input int between low and high is returned.
 *********************************************************************/
int get_valid_int_in_range(const int low, const int high)
{
    int in_val;
    bool done = false;
    do
    {
        in_val = get_valid_int();

        if (in_val < low || in_val > high)
            std::cout << "Value must be between " << low << " and " << high << ".\n";
        else
            done = true;
    }
    while (!done);

    return in_val;
}

/*********************************************************************
 ** Function: get_valid_double()
 ** Description: Waits for the user to enter a valid double value.
 ** Each time the user enters an invalid value, it prompts the user
 ** with an error message to try again.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: A user-input double is returned.
 *********************************************************************/
double get_valid_double()
{
    double in_val = 0.0;

    // get input till valid double is received
    while (!(cin >> in_val))
    {
        cout << "Bad input!  Please enter a number.\n";

        // clear error bits
        cin.clear();

        // ignore the rest of the input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // clear any trailing characters in the input buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return in_val;
}


/*********************************************************************
 ** Function: get_valid_double_in_range()
 ** Description:  Waits for the user to enter a valid double value
 ** between low and high. Each time the user enters an invalid value,
 ** it prompts the user with an error message to try again.
 ** Parameters: low - the minimum value allowed, high - the maximum
 ** value allowed
 ** Pre-Conditions: none
 ** Post-Conditions: A user-input double is returned.
 *********************************************************************/
double get_valid_double_in_range(
        const double low, const double high)
{
    double in_val;
    bool done = false;
    do
    {
        in_val = get_valid_double();

        if (in_val < low || in_val > high)
            cout << "Value must be between " << low << " and " << high << ".\n";
        else
            done = true;
    }
    while (!done);

    return in_val;
}


/*********************************************************************
 ** Function: open_in_file()
 ** Description: Given a filestream and a filename, attempts to open
 **              the file for reading and returns the stream.
 ** Parameters: fs - the filestream, fn - the filename
 ** Pre-Conditions: fs must not already be bound to a file
 ** Post-Conditions: either the file "fn" is opened or an error is
 ** printed and the program exits
 *********************************************************************/
ifstream& open_in_file(ifstream& fs, string fn)
{
    // attempt to open the file
    fs.open(fn.c_str());

    if (fs.fail())
    {
        cerr << "Error! Could not open file \'" << fn << "\'.\nExiting program!\n";
        exit(1);
    }

    return fs;
}


/*********************************************************************
 ** Function: open_out_file()
 ** Description: Given a filestream and a filename, attempts to open
 ** the file for writing and returns the stream.
 ** Parameters: fs - the filestream, fn - the filename
 ** Pre-Conditions: fs must not already be bound to a file
 ** Post-Conditions: either the file "fn" is opened or an error is
 ** printed and the program exits
 *********************************************************************/
ofstream& open_out_file(ofstream& fs, string fn)
{
    // attempt to open the file
    fs.open(fn.c_str());

    if (fs.fail())
    {
        cerr << "Error! Could not open file \'" << fn << "\'.\nExiting Program!\n";
        exit(1);
    }

    return fs;
}
