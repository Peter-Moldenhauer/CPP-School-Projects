/**********************************************************************************
** Name: Peter Moldenhauer
** Date: 4/16/16
** Description: Project 4a. This program determines the distance an object falls
**due to gravity in a specific time period. The user will input a time in seconds
**that an object has been falling. The program will then return the distance in
**meters that the object has fallen in that time.
***********************************************************************************/

#include <iostream>
#include <cmath>  //needed for the pow function

using namespace std;

double fallDistance(double time);  //function prototype with a parameter of double type


int main(){

	double inputTime;

	cout << "Please enter the time in seconds that the object has been falling: " << endl;
	cin >> inputTime;

	double distance = fallDistance(inputTime);    //Call the fallDistance function with inputTime as an argument and assign the return value of the function to a variable

	cout << "The distance in meters that the object has fallen in that time is: " << distance <<endl;

	return 0;
}

/****************************************************************************************
* This is the fallDistance function. This function takes a parameter of double type and
* then uses it to complete the formula to determine the distance an object falls due to
* gravity at a specific time period. Formula: distance = (1/2)(gravity)(time squared)
* This formula will then return the corresponding distance value.
******************************************************************************************/
double fallDistance(double time){    //Define fallDistance function to calculate distance using a parameter for time

	double timeSquared;            //Declare a variable to be used for time squared
    timeSquared = pow(time,2);   //pow function to calculate time squared

	return timeSquared*(0.5)*(9.8);  //Return the distance value
}
