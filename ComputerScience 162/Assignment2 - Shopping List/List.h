#ifndef LIST_H
#define LIST_H
#include <string>
#include "Item.h"
using namespace std;

class List
{
    private:
        Item *itemArray; // pointer to the list of Items

        Item itm1;  // item object used to compare to items in the item array list

        int maxSize;  // maximum allowable number of entries

        int currentSize; // current number of entries

        void increaseSize();  // increase maximum size of array when required

        int findItem(string itemName);  // This function returns the index of an item, given a name

        double getTotalCost();  // Get the total cost of all items in the list


    public:
        List();   // List constructor

        ~List();   // List destructor

        void addItem();  // Add an Item object to the array

        void deleteItem();  // Delete an Item object from the array

        void printList();  // Print the complete list of items including total cost
};

#endif // LIST_H
