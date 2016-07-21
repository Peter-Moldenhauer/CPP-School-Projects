/*********************************************************************************************
** Name: Peter Moldenhauer
** Date: 5/26/16
** Description: This is the implementation file for the Book class. Together with the Patron
**and Library class files, this program demonstrates a library simulator. This library
**simulator allows a user to create patron information (ID number, name, etc) in addition to
**information on specific books in a library (title, author, etc). This program also allows a
**patron to check out books, add books to library, update an "on hold" list and calculate fines
**due to late book returns to the library.
************************************************************************************************/

#include "Book.hpp"  //include Book class header file
using std::string;

//Constructor that makes a book object from parameters for an ID code,
//a title and an author name
Book::Book(string idc, string t, string a)
{
    idCode = idc;
    title = t;
    author = a;

    checkedOutBy = NULL;  //Book starts out being not checked out
    requestedBy = NULL;  //Book starts out by being not requested by a patron
    location = ON_SHELF;   //Book starts out on the shelf
}

int Book::getCheckOutLength()  //Returns the max number of days this book may be checked out for
{
    return CHECK_OUT_LENGTH;  //constant variable, 21 is used for now
}

string Book::getIdCode()   //Returns the ID code for the book
{
    return idCode;
}

string Book::getTitle()  //Returns the title of the book
{
    return title;
}

string Book::getAuthor()   //Returns the author of the book
{
    return author;
}

Locale Book::getLocation()  //Returns the location of the book (either on shelf, on hold shelf or checked out)
{
    return location;
}

void Book::setLocation(Locale location1)  //Sets the location of book (on shelf, on hold shelf or checked out)
{
    location = location1;
}

Patron* Book::getCheckedOutBy()  //Returns a pointer to the specific patron checking out the book
{
    return checkedOutBy;
}

void Book::setCheckedOutBy(Patron* patron1)  //Sets the specific patron checking out the book via a pointer
{
    checkedOutBy = patron1;
}

Patron* Book::getRequestedBy()  //Returns a pointer to the specific patron requesting the book.
{
    return requestedBy;
}

void Book::setRequestedBy(Patron* patron1)  //Sets the specific patron requesting the book via a pointer
{
    requestedBy = patron1;
}

int Book::getDateCheckedOut()  //Returns the date the book was checked out
{
    return dateCheckedOut;
}

void Book::setDateCheckedOut(int date1)  //Sets the date the book was checked out
{
    dateCheckedOut = date1;
}
