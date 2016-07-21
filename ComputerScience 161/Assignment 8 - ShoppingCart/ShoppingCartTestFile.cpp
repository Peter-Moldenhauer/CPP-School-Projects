/***********************************************************************************
** Name: Peter Moldenhauer
** Date: 5/16/16
** Description: This program is a testing file to be used with the Item and
**ShoppingCart class files. Note: the Item and ShoppingCart classes are commented
**out in this file due to initial testing before I made separate files for them.
************************************************************************************/

#include "Item.hpp"
#include "ShoppingCart.hpp"
#include <iostream>
using namespace std;


/******************************************************
#include <iostream>
#include <string>
#define SIZE 100
using namespace std;


class Item{

	private:
		string name;
		double price;
		int quantity;

	public:
		Item();
		Item(string n1, double p1, int q1);

		void setName(string n);
		void setPrice(double p);
		void setQuantity(int q);

		string getName();
	  	double getPrice();
		int getQuantity();

};

Item::Item(){
	setName("");
	setPrice(0.0);
	setQuantity(0);
}

Item::Item(string n1, double p1, int q1){
	setName(n1);
	setPrice(p1);
	setQuantity(q1);
}

void Item::setName(string n){
	name = n;
}

void Item::setPrice(double p){
	price = p;
}

void Item::setQuantity(int q){
	quantity = q;
}

string Item::getName(){
	return name;
}

double Item::getPrice(){
	return price;
}

int Item::getQuantity(){
	return quantity;
}

class ShoppingCart{

	private:
		Item* itemList[SIZE];
		int arrayEnd;

	public:
		ShoppingCart();
		void addItem(Item *item);
		double totalPrice();

};

ShoppingCart::ShoppingCart(){
	Item** ptr;

	for(ptr = itemList; ptr < itemList + SIZE; ptr++){
		*ptr = NULL;
	}

	arrayEnd = 0;
}

void ShoppingCart::addItem(Item *item){
	if(arrayEnd < SIZE){
		itemList[arrayEnd++] = item;
	}
}

double ShoppingCart::totalPrice(){
	Item** item;
	double total = 0.0;

	for(item = itemList; item < itemList + arrayEnd; item++){
		Item currentItem = **item;
		total += currentItem.getPrice() * currentItem.getQuantity();
	}
	return total;
}
**********************************************************************/

//main function below to test Item and ShoppingCart classes
int main(){
	Item a("affidavit", 179.99, 12);  //create Item objects
	Item b("Bildurngsroman", 0.7, 20);
	Item c("capybara", 4.5, 6);
	Item d("dirigible", 0.05, 16);

	ShoppingCart sc1; //create a ShoppingCart object
	sc1.addItem(&a);  //add Items to this specific ShoppingCart object
	sc1.addItem(&b);
	sc1.addItem(&c);
	sc1.addItem(&d);
	double diff = sc1.totalPrice();

	//sc1.printCart();
	cout << "Total: " << diff << endl;

	return 0;
}



