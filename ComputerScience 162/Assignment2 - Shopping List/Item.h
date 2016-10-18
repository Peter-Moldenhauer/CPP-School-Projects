#ifndef ITEM_H
#define ITEM_H
#include <string>
using namespace std;

class Item
{
    private:
        string name;

        string unit;

        double qty;

        double pricePerUnit;

        double total;

        double validateQty(); // This function validates the user input of quantity

        double validateP(); // This function validates the user input of price per unit

    public:
        Item();  // Default constructor initializes data members to blank or zero

        friend bool operator==(Item &a, Item &b);  // This function overloads the == operator to see if two object names are equal to each other

        void setName(string n); // This function sets the private member name

        string getName();  // This function returns the item name

        void setUnit();  // This function sets the private member unit

        string getUnit();  // This function returns the unit of measure of the item

        void setQty();  // This function sets the private member qty

        double getQty();  // This function returns the quantity of the item

        void setUnitPrice();  // This function sets the private member pricePerUnit

        double getPricePerUnit(); // This function returns the price per unit of item

        void setTotal();  // This function sets the private member total

        double getTotal(); // This function returns the total price of the item

        void print(); // This function prints all of the data to the item
};

#endif // ITEM_H
