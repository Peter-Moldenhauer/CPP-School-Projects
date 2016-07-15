/*******************************************************************************
** Name: Peter Moldenhauer
** Date: 4/3/16
** Description: This program asks the user for a (integer) number of cents,
**from 0 to 99, and outputs how many of each type of coin would represent
**that amount with the fewest total number of coins.
********************************************************************************/

#include <iostream>

using namespace std;

int main()
{
	int cents, changeQuarters, changeDimes, changeNickels, changePennies;

	cout << "Please enter an amount in cents less than a dollar. " << endl;

	cin >> cents;

	changeQuarters = cents/25;     //calculate the change in quarters
	cents = cents%25;              //remaining change after quarters
	changeDimes = cents/10;        //calculate the change in dimes
	cents = cents%10;	       //remaining change after dimes
	changeNickels = cents/5;       //calculate the change in nickels
	cents = cents%5;	       //remaining change after nickels
	changePennies = cents/1;       //calculate the change in pennies

	cout << "Your change will be: " << endl;
	cout << "Q: " << changeQuarters << endl;
	cout << "D: " << changeDimes << endl;
	cout << "N: " << changeNickels << endl;
	cout << "P: " << changePennies << endl;

	return 0;
}



