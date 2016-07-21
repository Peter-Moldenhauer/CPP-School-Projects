/***********************************************************************************
** Name: Peter Moldenhauer
** Date: 5/16/16
** Description: This is the header file for the Item class.
**When used in combination with the ShoppingCart class, the Item class demonstrates
**a shopping cart program in which a user can store a list of selected items that
**includes specific information to each item in a shopping cart.
************************************************************************************/

#ifndef ITEM_HPP  //include guards
#define ITEM_HPP

#include <iostream>
#include <string>

using namespace std;

class Item{  //Item Class

	private:
		string name;    //item name variable
		double price;   //item price variable
		int quantity;   //item quantity variable

	public:
		Item();  //Default constructor
		Item(string n1, double p1, int q1);  //Constructor with three parameters

		//Getters, no parameters!
		string getName();
		double getPrice();
		int getQuantity();

		//Setters, takes parameters but do not return anything!
		void setName(string n);
		void setPrice(double p);
		void setQuantity(int q);

}; //Don't forget semi-colon here

#endif  //include guard


