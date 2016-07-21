/*********************************************************************************************
** Name: Peter Moldenhauer
** Date: 5/26/16
** Description: This is the implementation file for the Patron class. Together with the Book
**and Library class files, this program demonstrates a library simulator. This library
**simulator allows a user to create patron information (ID number, name, etc) in addition to
**information on specific books in a library (title, author, etc). This program also allows a
**patron to check out books, add books to library, update an "on hold" list and calculate fines
**due to late book returns to the library.
************************************************************************************************/

#include "Patron.hpp" //include the Patron class header file

using std::string;
using std::vector;

//Constructor that creates a Patron object with a patron ID number
//and a name, patron's fine amount starts at 0
Patron::Patron(string idn, string n)
{
    idNum = idn;
    name = n;
    fineAmount = 0.0;
}

string Patron::getIdNum()  //Returns the patrons ID number
{
    return idNum;
}

string Patron::getName()  //Returns the patrons name
{
    return name;
}

vector<Book*> Patron::getCheckedOutBooks()  //Returns the list of books this specific patron has checked out, in the form of a vector of pointers to Books
{
    return checkedOutBooks;
}

void Patron::addBook(Book* b)  //Adds a pointer to a Book to the list (vector) of this patron's checked out books
{
    checkedOutBooks.push_back(b); //add the pointer b to the checkedoutbooks vector
}

void Patron::removeBook(Book* b) //Remove a specific book (that is given as a pointer to a book) from the list (vector) of books checked out
{
    int numOfCheckedOutBooks = checkedOutBooks.size();  //Get the total length of the list of books in the vector

    for (int i = 0; i < numOfCheckedOutBooks; i++){  //Loop through the list (vector) of books to find the book passed as parameter
        Book *currentBook = checkedOutBooks.at(i);
        if (b == currentBook){
            checkedOutBooks.erase(checkedOutBooks.begin() + i);  //When the specific book is located in the vector, remove it from the vector
            return;
        }
    }
}

double Patron::getFineAmount()  //Returns the total dollar amount this patron owes in fines
{
    return fineAmount;
}

void Patron::amendFine(double amount)  //Sets the total dollar amount in fines. Adds a given dollar amount (parameter) to total fines the patron owes
{
    fineAmount += amount;
}
