/*********************************************************
** Name: Peter Moldenhauer
** Date: 4/10/16
** Description: Assignment 3.a This program asks the user
**for a series of numbers. It then finds the min. and max.
**of the numbers that the user entered.
**********************************************************/


#include <iostream>
using namespace std;

int main(){

	int n, numbOfInts, max, min;

	cout<<"How many integers would you like to enter? "<<endl;
	cin>>numbOfInts;
	cout<<"Please enter "<<numbOfInts<<" integers: "<<endl;

	cin>>n;	             //First integer entered by user, user will enter at least 1 integer

	max=n;
	min=n;

	while(numbOfInts > 1){	    //loop starts

	cin>>n;

	if (n > max)
		max=n;
	if (n < min)
		min=n;

	numbOfInts--;                //loop count is reduced by 1 each time

	}


	cout<<"min: "<<min<<endl;
	cout<<"max: "<<max<<endl;

return 0;
}
