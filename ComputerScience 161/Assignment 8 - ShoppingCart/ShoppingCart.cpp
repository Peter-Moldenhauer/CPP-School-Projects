/***********************************************************************************
** Name: Peter Moldenhauer
** Date: 5/16/16
** Description: This is the function implementation file for the ShoppingCart class.
**When used in combination with the Item class, this file demonstrates a shopping
**cart program in which a user can store a list of selected items that includes
**specific information to each item in the shopping cart.
************************************************************************************/

#include "Item.hpp"  //include Item class header file
#include "ShoppingCart.hpp"  //Include ShoppingCart class header file
#include <iostream>
using namespace std;

ShoppingCart::ShoppingCart(){  //Default constructor that initializes each element of the array to NULL
	Item** ptr;  //pointer to pointer to Item

	for(ptr = itemList; ptr < itemList + SIZE; ptr++){  //for loop to point all elements of array to Null
		*ptr = NULL;
	}

	arrayEnd = 0;  //initialize arrayEnd to 0 to indicate ShoppingCart has no items
}

void ShoppingCart::addItem(Item *item){  //Uses a pointer to an Item as a parameter and adds it to the array
	if(arrayEnd < SIZE){
		itemList[arrayEnd++] = item;
	}
}

double ShoppingCart::totalPrice(){ //calculate and return the total price of the items in the shopping cart
	Item** item;  //pointer to current pointer to Item
	double total = 0.0;  //accumulate total

	for(item = itemList; item < itemList + arrayEnd; item++){  //dereference twice to get each item and add its price to the running total
		Item currentItem = **item;
		total += currentItem.getPrice() * currentItem.getQuantity();
	}
	return total;
}



