/***********************************************************************************
** Name: Peter Moldenhauer
** Date: 5/16/16
** Description: This is the function header file for the ShoppingCart class.
**When used in combination with the Item class, this file demonstrates a shopping
**cart program in which a user can store a list of selected items that includes
**specific information to each item in the shopping cart. The ShoppingCart class
**stores a list of Items and allows Items to be added. It also determines the total
**price of the items on the list.
************************************************************************************/

#ifndef SHOPPING_CART_HPP  //include guards
#define SHOPPING_CART_HPP

#define SIZE 100   //Will be used for the maximum size of list

#include "Item.hpp"  //include Item class header file

class ShoppingCart{  //ShoppingCart class

	private:
		Item* itemList[SIZE];   //Pointer to Item array
		int arrayEnd;  //Keeps track of the index of the next empty spot in the array

	public:
		ShoppingCart();  //Defalut constructor
		void addItem(Item *item); //takes a pointer to an Item as a parameter and adds it to the array
		double totalPrice();  //Returns the total cost of all Items in the ShoppingCart list
};

#endif  //include guard

