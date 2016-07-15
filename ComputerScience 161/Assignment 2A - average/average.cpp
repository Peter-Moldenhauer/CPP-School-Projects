/**************************************************************
** Author: Peter Moldenhauer
** Date: 4/3/16
** Description: This program asks the user for five numbers and
**then prints out the average of those numbers.
***************************************************************/

#include <iostream>

using namespace std;

int main()
{
	double number1, number2, number3, number4, number5, numberAverage;

	cout << "Please enter five numbers. " << endl;

	cin >> number1;
	cin >> number2;
	cin >> number3;
	cin >> number4;
	cin >> number5;

	numberAverage = (number1 + number2 + number3 + number4 + number5)/5; //Calculate the average of the five numbers

	cout << "The average of those numbers is: " << endl;
	cout << numberAverage << endl;

	return 0;
}

