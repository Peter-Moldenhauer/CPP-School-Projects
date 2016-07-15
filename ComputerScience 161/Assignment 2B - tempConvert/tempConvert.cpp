/**********************************************************
** Name: Peter Moldenhauer
** Date: 4/3/16
** Description: This program converts Celsius temperatures
**to Fahrenheit temperatures.
***********************************************************/

#include <iostream>

using namespace std;

int main()
{

	double cTemp, fTemp; //variables for celsius and fahrenheit temps

	cout << "Please enter a Celsius temperature. " << endl;
	cin >> cTemp;

	fTemp = (9.0/5.0)*(cTemp)+32;  //calculate fahrenheit temp

	cout << "The equivalent Fahrenheit temperature is:  \n" << fTemp << endl;

	return 0;
}


