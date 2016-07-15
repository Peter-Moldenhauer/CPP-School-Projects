/**********************************************************************************
** Name: Peter Moldenhauer
** Date: 4/16/16
** Description: Project 4b. This program takes three int parameters by reference
**from the user and sorts their values into ascending order, so that the first
**parameter now has the lowest value, the second parameter the middle value, and
**the third parameter has the highest value.
***********************************************************************************/

#include <iostream>
using namespace std;

void smallSort(int &x, int &y, int &z);  //function prototype, takes three int parameters by reference

int main()
{

	int a, b, c;  //Declare three int variables that the user will enter in

	cout << "Enter int a: ";    //User inputs values to get a, b and c
	cin >> a;
	cout << "Enter int b: ";
	cin >> b;
	cout << "Enter int c: ";
	cin >> c;

	smallSort(a, b, c);      //Call the smallSort function with the three variables as arguments

	cout << "Int a: " << a << endl;    //Print out new values of a, b and c, these values changed because they were passed by reference
	cout << "Int b: " << b << endl;    //Note: If these values were passed by value, they would not have changed
	cout << "Int c: " << c << endl;

	return 0;
}

/*****************************************************************************************
* This is the smallSort function. This function takes three int variables by reference
* and orders them from least to greatest. Since this is a void function, it does not
* return anything.
******************************************************************************************/
void smallSort(int &x, int &y, int &z)    //Define the smallSort function
{
//The following if statements below order the values from least to greatest
	if(x > y){
		int temp = x;
		x = y;
		y = temp;
	}
	if(x > z){
		int temp = x;
		x = z;
		z = temp;
	}
	if(y > z){
		int temp = y;
		y = z;
		z = temp;
	}
}

