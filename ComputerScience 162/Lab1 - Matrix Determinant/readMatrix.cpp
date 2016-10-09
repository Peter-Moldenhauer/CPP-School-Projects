#include "readMatrix.h"
#include <iostream>
using namespace std;

void readMatrix(int **myPtr, int matrixSize){
    int intNum = 1;
    for (int i=0; i<matrixSize; i++){
        for (int j=0; j<matrixSize; j++){
            cout << "Enter integer " << intNum << ": ";
            cin >> myPtr[i][j];
            intNum++;
        }
    }
}
