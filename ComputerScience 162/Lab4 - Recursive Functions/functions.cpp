/***************************************************************************************************
*Name: Peter Moldenhauer
*Email: moldenhp@oregonstate.edu
*Date: 10/19/16
*Course: CS 162
*Assignment: Lab 4
*Description: This .cpp file contains the function definitions that are used in the Lab 4 program.
****************************************************************************************************/

#include "functions.h"

/*******************************************************
 This is a recursive function that reverses a string
********************************************************/
void reverseString(string str){
    if (str == "")  // base case
        cout << '\n';  // last character, print a newline character
    else{ // there is at least one character in the string
        cout << str[str.length() - 1];  // use array index to print out the last character in string

        reverseString(str.substr(0, str.length() - 1)); // Put the remaining "substring" back into the recursive function. The substring starts  at the 0 index and is 1 less character than the original string
    }
}


/*******************************************************************
 This is a recursive function that calculates the sum of an array
********************************************************************/
int sumOfArray(int theArray[], int arrayLength){
    if (arrayLength == 0) // base case
        return 0;
    else // sum the last element with the sum of the rest of the array
        return theArray[arrayLength - 1] + sumOfArray(theArray, arrayLength - 1);
}


/***************************************************************************
 This is a recursive function that calculates the triangular number for n
****************************************************************************/
int triangleNumber(int n){
    if (n == 0) // base case
        return 0;
    else // sum n with n-1 until the base case is reached
        return n + triangleNumber(n-1);
}


/************************************************************
 This function displays a menu to the screen for the user
*************************************************************/
void showMenu(){
    cout << "1) Reverse a string." << endl;
    cout << "2) Calculate the sum of an array." << endl;
    cout << "3) Calculate the triangle number." << endl;
    cout << "4) Exit program\n" << endl;
}


/***********************************************************************
 This function validates user input from which menu selection is made
************************************************************************/
int getChoice(){
    bool getData = true;
    int userInput;

    while (getData == true){
        cout << "Enter [1-4] here: ";
        cin >> userInput;
        cin.clear();
        cin.ignore(1000, '\n');
        //getline(cin, userInput);
        if (userInput > 0 && userInput <= 4){
            getData = false;
        }else{
            cout << "Please enter either 1, 2, 3 or 4 to make your selection!" << endl;
            //cin.clear();
            //cin.ignore(1000, '\n');
        }
    }
    return userInput;
}


/***********************************************************************************
 This function completes the specific action that the user selects from the menu
************************************************************************************/
void doRecursiveFunctions(int c){
    switch(c){
        case 1:{  // user wants to revers a string
            cout << "\nPlease enter a string to reverse: ";
            string theString;
            getline(cin, theString);

            cout << "The reversed string is: ";
            reverseString(theString); // call the reverse string recursive function
        }
        break;

        case 2: {  // user wants to calculate sum of an array
            int *theArray;
            int counter = 0, aSize = 5;
            theArray = new int[aSize]; // starting size of the array is 5 ints

            int length = 20;
            char *input = new char[length];

            int arrayLength = 0;

            cout << "\nEnter a series of integers to be entered in the array." << endl;
            cout << "If you enter a character that is not a number or the letter Q (to quit) it will count as the number zero!" << endl;
            cout << "If you enter a floating point number it will only take the root integer as the number!\n" << endl;
            cout << "Enter the first number or Q to quit: ";
            cin.getline(input, length);

            while ((strcmp(input, "Q")!=0) && (strcmp(input, "q")!=0)){

            if (counter == aSize){ // if array is at capacity, then increase the size of the array
                aSize = counter * 2;  // Determine a new size for the array
                int *newArray = new int[aSize];  // Allocate a new array

                for (int i = 0; i < counter; i++)  // Copy each old entry of initial array into the new array
                    newArray[i] = theArray[i];

                delete [] theArray;  // Remove old array
                theArray = newArray;  // Point old name to new array
            }

            cout << "You entered: " << atoi(input) << endl;
            theArray[arrayLength] = atoi(input);
            arrayLength++;

            cout << "Enter the next number or Q to quit: ";
            cin.getline(input, length);
            }

            cout << "\nThe array you entered is: ";
            for (int i = 0; i < arrayLength; i++){
            cout << theArray[i] << " ";
            }


            int arrayTotal = sumOfArray(theArray, arrayLength);
            cout << "\nThe sum of the array is: " << arrayTotal << endl;

            delete [] theArray;
            delete [] input;
        }
        break;

        case 3: { // user wants to calculate a triangle number
            int numb;
            cout << "\nEnter a number to calculate the triangle number from: ";
            cin >> numb;
            cout << "The triangle number of " << numb << " is: " << triangleNumber(numb) << endl;
        }
        break;

        default: { // user wants to quit
            cout << "Goodbye!" << endl;
            exit(0);
        }

    }
}
