#include "List.h"
#include <iostream>
#include <iomanip>

// This constructor function sets up an empty list of Items
List::List(){
    maxSize = 4; // Create List object automatically with 4 to be used as the starting array size
    currentSize = 0;
    itemArray = new Item[maxSize];
}

// Destructor deallocates the list of item objects
List::~List(){
    delete [] itemArray;
}

// this function adds a new item into the list array
void List::addItem(){
    if(currentSize == maxSize)  // if the array of items is at capacity, then increase the size of the array
        increaseSize();// This function overloads the == operator to see if two object names are equal to each other

    string name;
    bool inArray = false;
    cout << "\nPlease enter the item name: ";
    getline(cin,name);

    if (currentSize == 0){ // if there are no items in the array list then automatically initialize the first item in itemArray
        itemArray[currentSize].setName(name);
        itemArray[currentSize].setUnit();
        itemArray[currentSize].setQty();
        itemArray[currentSize].setUnitPrice();
        itemArray[currentSize].setTotal();
        cout << "Item added successfully!" << endl;

        currentSize++;
    }else{ // if there is at least 1 item in itemArray, then check to see if the name the user entered is equal to the object(s) name(s) in the list
        itm1.setName(name);  // initialize a separate item object to compare to the items in itemArray
        for (int i = 0; i < currentSize; i++){
            if (itm1 == itemArray[i]){
                inArray = true;  // true if the name user entered is the same as a name in an item object that is currently in itemArray
            }
        }
        if (inArray == true){
                cout << "This item is already on the list! " << endl;
            }else if (inArray == false){ // if the name user entered is not equal to any names in itemArray, then initialize a new item element in itemArray
                itemArray[currentSize].setName(name);
                itemArray[currentSize].setUnit();
                itemArray[currentSize].setQty();
                itemArray[currentSize].setUnitPrice();
                itemArray[currentSize].setTotal();
                cout << "Item added successfully!" << endl;

                currentSize++;
            }
    }
}

// This function calculates and returns the total cost of all items on the list
double List::getTotalCost(){
    double total = 0;

    for (int i=0; i < currentSize; i++)  // look at each item in array
        total += itemArray[i].getTotal();

    return total;
}

// This function removes an item object from the list array
void List::deleteItem(){
    string itemName;
    cout << "\nEnter the item name that you wish to remove: ";  // prompt user for the item name to be removed
    getline(cin,itemName);

    int thisEntry = findItem(itemName);  // locate the item in the list array

    if (thisEntry == -1)
        cout << itemName << " not found in list! \n";
    else{
        for (int j = thisEntry + 1; j < currentSize; j++) //shift each succeeding element "down" one position in the array which deletes the specified item
            itemArray[j-1] = itemArray[j];

        currentSize--;  // decrement current number of items in array
        cout << "Item removed successfully!\n";
    }
}

// This function locates an item name in the list array and returns the position of the item as an integer if found, returns -1 if item is not found
int List::findItem(string itemName){
    for (int i=0; i < currentSize; i++)  // look at each item in array
        if (itemName.compare(itemArray[i].getName()) == 0)
            return i;  // If item name is found, return position and exit
    return -1;  // If item name is not found, return -1
}

// This function prints out the current list items to the screen
void List::printList(){
    if (currentSize == 0){
        cout << "\nCurrent list is empty!\n";
        return;
    }
    // Display a heading at top
    cout << "\n\t---ITEM NAME---\t\t---UNIT---\t---QTY---\t---PRICE---\t---TOTAL---\n\n";

    for (int i = 0; i < currentSize; i++) // for each element of array, print out the item data
        itemArray[i].print();

    cout << "\n\t\t\t*** The grand total of the list is: $" << setprecision(2) << fixed << getTotalCost() << " ***\n" << endl;
}

// This function doubles the size of the List array by creating a new larger array and changing the pointer to refer to this new array
void List::increaseSize(){
    maxSize = currentSize * 2;  // Determine a new size for the array
    Item *newArray = new Item[maxSize];  // Allocate a new array

    for (int i = 0; i < currentSize; i++)  // Copy each old entry of initial array into the new array
        newArray[i] = itemArray[i];

    delete [] itemArray;  // Remove old array
    itemArray = newArray;  // Point old name to new array
}

