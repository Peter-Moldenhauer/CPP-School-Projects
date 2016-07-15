/**********************************************************************************************************
** Name: Peter Moldenhauer
** Date: 4/16/16
** Description: Project 4c. This program demonstrates a hailstone sequence that starts with some positive
**integer entered in by the user. If the integer is even, then the program divides it by two to get the
**next integer in the sequence, but if it is odd then the program multiplies it by three and adds one to
**get the next integer in the sequence. The program then uses the value it just generated to find out the
**next value, according to the same rules. The hailStone function in the program returns how many steps it
**takes to reach 1. If the starting integer is 1, then the return value is 0 since it takes no steps to
**reach 1.
*************************************************************************************************************/

#include <iostream>
using namespace std;

int hailStone(int startInt);  //hailStone function prototype, takes an int parameter

int main(){

	int startInput;  //Declare an int variable for the user input

	cout << "Please enter a positive integer: ";
	cin >> startInput;

	int numberSteps = hailStone(startInput);     //Call the hailStone function with the user input as an argument, assign the returned value from the function to a variable

	cout << "Total number of steps it took to reach 1: " << numberSteps << endl;

	return 0;
}

/************************************************************************
* This is the hailStone function. This function returns how many steps it
* takes to reach 1.
*************************************************************************/
int hailStone(int startInt){     //Define the hailstone function with startInt as a parameter

	int count = 0;  //Declare an int variable to keep track of the number of steps to reach 1

	while(startInt > 1){    //while loop to keep looping until integer = 1

		if(startInt % 2 == 0){   //Determine if integer is even

			startInt = startInt / 2;
			count = count + 1;   //increment count

			//cout << "Integer: " << startInt << endl;   //used for testing and debugging
			//cout << "Count: " << count << endl;
		}
		else{

			startInt = (startInt * 3) + 1;   //if integer is odd then multiply by 3 and add 1
			count = count + 1;  //increment count

			//cout << "Integer: " << startInt << endl;   //used for testing and debugging
			//cout << "Count: " << count << endl;
		}
	}

	return count;  //Return the total number of steps to took to reach 1
}
