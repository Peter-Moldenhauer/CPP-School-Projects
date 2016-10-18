#include "Item.h"
#include <iostream>
#include <iomanip>  // used to align text and decimal points


// Default constructor for Item class initializes all of the data members to be blank (or zero)
Item::Item(){
    this->name = " ";
    this->unit = " ";
    this->qty = 0;
    this->pricePerUnit = 0;
    this->total = pricePerUnit * static_cast<double>(qty);
}

// This function overloads the == operator to see if two object names are equal to each other
bool operator==(Item &a, Item &b){
    return a.getName() == b.getName();
}

// This function sets the item name
void Item::setName(string n){
    name = n;
}

// This function sets the item unit
void Item::setUnit(){
    cout << "Please enter the unit of measure (can, box, pound etc.): ";
    getline(cin,unit);
}

// This function sets the item quantity
void Item::setQty(){
    cout << "Please enter the quantity of units: ";
    qty = validateQty();
}

// This function sets the unit price
void Item::setUnitPrice(){
    cout << "Please enter the price per unit: ";
    pricePerUnit = validateP();
}

// This function calculates and sets the total price
void Item::setTotal(){
    total = this->pricePerUnit * this->qty;
}

// This function returns the item name
string Item::getName(){
    return name;
}

// This function returns the unit of measure of the item
string Item::getUnit(){
    return unit;
}

// This function returns the quantity of the item
double Item::getQty(){
    return qty;
}

// This function returns the price per unit
double Item::getPricePerUnit(){
    return pricePerUnit;
}

// This function returns the total price of a given item
double Item::getTotal(){
    return total;
}

// This function prints out all of the data to a given Item object
void Item::print(){
    cout << "\t" << setw(20) << left << name;
    cout << "\t" << setw(10) << left << unit;
    cout << "\t" << setw(5) << right << setprecision(2) << fixed << qty;
    cout << "\t\t" << setw(8) << right << setprecision(2) << fixed << pricePerUnit;
    cout << "\t" << setw(8) << right << setprecision(2) << fixed << total << endl;
}

// This function validates the user input of quantity
double Item::validateQty(){
    bool getData = true;
    double quantity;

    while (getData == true){
        cin >> quantity;

        if (quantity > 0.0){
            getData = false;
        }else{
            cout << "Error! Quantity must be a number greater than 0. Enter quantity again: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
    return quantity;
}

// This function validates the user input of price per unit
double Item::validateP(){
    bool getData = true;
    double price;

    while (getData == true){
        cin >> price;
        if (price > 0.0){
            getData = false;
        }else{
            cout << "Error! Price per unit must be a number greater than 0. Enter price per unit again: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
    return price;
}
