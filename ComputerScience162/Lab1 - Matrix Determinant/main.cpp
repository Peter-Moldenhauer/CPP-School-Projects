/********************************************************************************************************
*Name: Peter Moldenhauer
*Email: moldenhp@oregonstate.edu
*Date: 9/25/16
*Course: CS 162
*Assignment: Lab 1
*Description: This program contains the files for the readMatrix function and the determinant functions.
*The main function file uses readMatrix() to prompt the user to enter data, calculates the determinant
*using determinant() and then displays both an array and the determinant to the user.
*********************************************************************************************************/

#include "readMatrix.h"
#include "determinant.h"
#include <iostream>
using namespace std;

int main() {

    int matrixSize;
    int getMatrix = 1;

    cout << "This program will calculate the determinant of a matrix. " << endl;
    cout << endl;

    while (getMatrix == 1) {
        cout << "Enter 2 to calculate a 2x2 matrix or 3 to calculate a 3x3 matrix: ";
        cin >> matrixSize;

        if (matrixSize == 2 || matrixSize == 3)
            getMatrix = 0;
        else
            cout << "Please enter either a 2 or a 3! " << endl;
    }

    int rowCount = matrixSize;
    int colCount = matrixSize;

    int **myPtr;
    myPtr = new int *[rowCount];

    for (int i=0; i < rowCount; i++){
        myPtr[i] = new int[colCount];
    }
    cout << endl;

    readMatrix(myPtr, matrixSize);  //call the readMatrix function

    cout << "\nThe matrix that you entered is: \n" << endl;
    for (int i=0; i<matrixSize; i++){
        for (int j=0; j<matrixSize; j++){
            cout << myPtr[i][j] << " ";
        }
        cout << endl;
    }

    int determ = determinant(myPtr, matrixSize);  //call the determinant function
    cout << "\nThe determinant of the matrix is: " << determ << endl;


    //deallocate memory to prevent memory leak
    for (int i=0; i<rowCount; i++)
        delete [] myPtr[i];
    delete [] myPtr;


    return 0;
}
