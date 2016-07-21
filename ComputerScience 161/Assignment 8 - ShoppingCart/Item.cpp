/***********************************************************************************
** Name: Peter Moldenhauer
** Date: 5/16/16
** Description: This is the function implementation file for the Item class.
**When used in combination with the ShoppingCart class, the Item class demonstrates
**a shopping cart program in which a user can store a list of selected items that
**includes specific information to each item in a shopping cart.
************************************************************************************/

#include "Item.hpp"  //include the Item class header file

Item::Item(){   //Default constructor to create an Item object with these values
	setName("");
	setPrice(0.0);
	setQuantity(0);
}

Item::Item(string n1, double p1, int q1){  //Constructor that creates an item object with three parameters
	setName(n1);  //pass the three parameters to the set methods to initialize the private variables
	setPrice(p1);
	setQuantity(q1);
}
//get methods below
string Item::getName(){
	return name;  //returns Item name
}

double Item::getPrice(){
	return price;    //return Item price
}

int Item::getQuantity(){
	return quantity;   //return Item quantity
}
//set methods below
void Item::setName(string n){   //Set Item name from a given string
	name = n;
}

void Item::setPrice(double p){  //Set Item price from a given price with double type
	price = p;
}

void Item::setQuantity(int q){  //Set Item quantity from a given quantity with int type
	quantity = q;
}


