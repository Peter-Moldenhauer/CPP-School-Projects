/***********************************************************************************************
** Name: Peter Moldenhauer
** Date: 5/26/16
** Description: This is the implementation file for the Library class. Together with the Patron
**and Book class files, this program demonstrates a library simulator. This library
**simulator allows a user to create patron information (ID number, name, etc) in addition to
**information on specific books in a library (title, author, etc). This program also allows a
**patron to check out books, add books to library, update an "on hold" list and calculate fines
**due to late book returns to the library.
**************************************************************************************************/

#include "Library.hpp"  //include Library header file

using std::string;
using std::vector;

Library::Library() //Constructor creates a library object
{
    currentDate = 0; //Set current date to 0
}

void Library::addBook(Book* b)  //Add a Book pointer to the holdings vector
{
    holdings.push_back(b);
}

void Library::addPatron(Patron* m)  //Add a Patron pointer to the members vector
{
    members.push_back(m);
}

string Library::checkOutBook(string pID, string bID) //Lets a patron check out a book as long as certain conditions are met, returns status of check out attempt
{
    Book *book = getBook(bID);  //This is the specific book to be checked out
    Patron *patron = getPatron(pID);  //This is the specific patron who is checking out the book

    if (book == NULL){  //if book is not in holdings vector then dont allow check out
        return "Book not found!";
    }
    if (patron == NULL){  //if patron is not in member vector then dont allow check out
        return "Patron not found!";
    }
    Locale status = book->getLocation();  //Get the status of the book

    if (status == CHECKED_OUT){  //if book is already checked out dont allow check out
        return "Book is already checked out";
    }

    if (status == ON_HOLD_SHELF){   //check to see if book is on hold shelf
        if (book->getRequestedBy() != patron){  //If this book is on the hold shelf that is requested by another patron, dont allow check out
            return "Book is on hold by another member";
        }else{   //This patron is allowed to check out the book, no one is requesting it now
            book->setRequestedBy(NULL);
        }
    }

    book->setCheckedOutBy(patron); //Update information about book
    book->setDateCheckedOut(currentDate);
    book->setLocation(CHECKED_OUT);

    patron->addBook(book);  //Add the Book to the list (vector) of checked out books by this patron

    return "Check out successful";
}

string Library::returnBook(string bID)
{
    Book *book = getBook(bID);  //what specific book is to be returned

    if (book == NULL){
        return "Book not found!";
    }

    Locale status = book->getLocation();  //Get the status of the book

    if (status != CHECKED_OUT){
        return "Book is already in library";
    }

    Patron *patron = book->getCheckedOutBy();  //determine what patron is returning the book

    patron->removeBook(book);  //remove book from patrons list of checked out books

    if (book->getRequestedBy()){ //If the Book was requested by another patron, put book on hold shelf, otherwise put book on shelf
        book->setLocation(ON_HOLD_SHELF);
    }else{
        book->setLocation(ON_SHELF);
    }

    book->setCheckedOutBy(NULL); //No one is checking out book now

    return "return successful";
}

string Library::requestBook(string pID, string bID)  //Allows a patron to request a Book from the library granted certain criteria are met, returns a string stating the status of request attempt
{
    Book *book = getBook(bID);  //This is the specific book to be requested
    Patron *patron = getPatron(pID);  //This is the specific patron who is requesting the book

    if (book == NULL){  //If book is not in library's holding list (vector) then do not allow request
        return "Book not found!";
    }
    if (patron == NULL){  //if patron is not in member vector then dont allow check out
        return "Patron not found!";
    }

    Locale status = book->getLocation();  //Get the status of the book

    if (status = ON_HOLD_SHELF){  //if Book is on hold, check to see if it is by this patron, if not then do not allow the request
        if (book->getRequestedBy() != patron){
            return "Book already on hold";
        }
    }

    if (status == ON_SHELF){
        book->setLocation(ON_HOLD_SHELF);  //Put the book on hold if it wasn't already on hold
    }
    book->setRequestedBy(patron);

    return "Request successful";
}

string Library::payFine(std::string pID, double payment) //Attempt to pay the library fine for the patron with the given ID number and given dollar amount
{
    Patron *patron = getPatron(pID);  //This is the specific patron who is paying the fine

    if (patron == NULL){
        return "Patron not found";
    }

    patron->amendFine(-payment);

    return "Payment successful";
}

void Library::incrementCurrentDate()  //Increment current date
{
    ++currentDate;

    int numHoldings = holdings.size(); //number of total books in the holdings list (vector)

    for (int i = 0; i < numHoldings; i++){ //loop through the list (vector) of holdings
        Book *book = holdings.at(i);
        int checkOutLenght = book->getCheckOutLength(); //get check out length of a book (21)

        int dateCheckedOut = book->getDateCheckedOut();  //get date book was checked out
        int dueDate = dateCheckedOut + checkOutLenght;   //calculate due date

        int daysOverdue = currentDate - dueDate;  //calculate days overdue

        if (daysOverdue > 0){  //if book is past due date then add fine to patron
            Patron *patron = book->getCheckedOutBy();
            if (patron != NULL){
                patron->amendFine(0.10);  //add .10 to patron's fine
            }
        }
    }
}

Patron* Library::getPatron(string pID)  //return a pointer to Patron with the given ID number
{
    int numMembers = members.size();

    for (int i = 0; i < numMembers; i++){  //loop through the list (vector) of members
        string curID = members.at(i)->getIdNum();

        if (pID == curID){
            return members.at(i);  //If specific member (based on ID) is located, return member
        }
    }

    return NULL;  //return NULL if member is not in list
}

Book* Library::getBook(string bID)  //returns a pointer to a Book with a given ID code
{
    int numBooks = holdings.size();

    for (int i = 0; i < numBooks; i++){  //loop through all of the books
        string curID = holdings.at(i)->getIdCode();

        if (bID == curID){
            return holdings.at(i);  //if specific book (based on ID) is located, return book
        }
    }

    return NULL;  //return NULL if book is not in list
}

