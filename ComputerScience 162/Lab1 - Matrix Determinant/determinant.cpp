#include "determinant.h"
#include <iostream>
using namespace std;

int determinant(int *myPtr[2], int matrixSize){
    if (matrixSize == 2){
        return ((myPtr[0][0] * myPtr[1][1]) - (myPtr[1][0] * myPtr[0][1]));
    }else{
        return ((myPtr[0][0]*((myPtr[1][1]*myPtr[2][2])-(myPtr[1][2]*myPtr[2][1]))) - (myPtr[0][1]*((myPtr[1][0]*myPtr[2][2])-(myPtr[1][2]*myPtr[2][0]))) + (myPtr[0][2]*((myPtr[1][0]*myPtr[2][1])-(myPtr[1][1]*myPtr[2][0]))));
    }
}
