/*********************************************************************************************
** Name: Peter Moldenhauer
** Date: 5/26/16
** Description: This is the main.cpp file that includes the Book, Library and Patron classes.
**Together with the Patron, Book and Library class files, this program demonstrates a library
**simulator. This library simulator allows a user to create patron information (ID number,
**name, etc) in addition to information on specific books in a library (title, author, etc).
**This program also allows a patron to check out books, add books to library, update an "on hold"
**list and calculate fines due to late book returns to the library.
**
**Note: The main function in this file is what gathers the class files together and allows the
**program to run. In this main function I create Book objects, Patron objects and a Library
**object to test the program to check for errors.
************************************************************************************************/


#include "Library.hpp"
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {
  Book b1("123", "War and Peace", "Tolstoy");
  Book b2("234", "Moby Dick", "Melville");
  Book b3("345", "Phantom Tollbooth", "Juster");
  Book b4("666", "Sam City", "Hell");

  cout << "A book's check out length should be 21: "
       << b1.getCheckOutLength() << endl;

  cout << "b1's ID Code should be 123: "     << b1.getIdCode()  << endl;
  cout << "b2's title should be Moby Dick: " << b2.getTitle()   << endl;
  cout << "b3's author should be Juster: "   << b3.getAuthor()  << endl;

  cout << "All three books should be on the shelf." << endl;

  if (b1.getLocation() != ON_SHELF) {
    cout << "ERROR: b1 is off the shelf" << endl;
  }
  if (b2.getLocation() != ON_SHELF) {
    cout << "ERROR: b2 is off the shelf" << endl;
  }
  if (b3.getLocation() != ON_SHELF) {
    cout << "ERROR: b3 is off the shelf" << endl;
  }

  Patron p1("abc", "Felicity");
  Patron p2("bcd", "Waldo");
  Library lib;
  lib.addBook(&b1);
  lib.addBook(&b2);
  lib.addBook(&b3);

  lib.addPatron(&p1);
  lib.addPatron(&p2);

  lib.checkOutBook("bcd", "234");

  cout << "Now b2 should be checked out by p2." << endl;

  if (b2.getLocation() != CHECKED_OUT) {
    cout << "ERROR: b2 is not checked out" << endl;
    if (b2.getLocation() == ON_SHELF) {
      cout << "b2 is on the shelf" << endl;
    } else {
      cout << "b2 is on hold" << endl;
    }
  }

  if (b2.getCheckedOutBy() != &p2) {
    cout << "ERROR: p2 is not checking out this book" << endl;
    if (b2.getCheckedOutBy() == NULL) {
      cout << "ERROR: nobody is checking out this book" << endl;
    }
  }

  cout << "p1's total fine amount should be $0.00: "
       << p1.getFineAmount() << endl;
  cout << "p2's total fine amount should be $0.00: "
       << p2.getFineAmount() << endl;


  for (int i=0; i<7; i++)
     lib.incrementCurrentDate();

  cout << "It is now day 7." << endl;

  cout << "p1's total fine amount should be $0.00: "
       << p1.getFineAmount() << endl;
  cout << "p2's total fine amount should be $0.00: "
       << p2.getFineAmount() << endl;

  cout << "p2 should have 1 book checked out." << endl;
  if (p2.getCheckedOutBooks().size() != 1) {
    cout << "ERROR: p2 has" <<  p2.getCheckedOutBooks().size() << endl;
  }

  lib.checkOutBook("bcd", "123");

  cout << "Now b1 should be checked out by p2." << endl;

  if (b1.getLocation() != CHECKED_OUT) {
    cout << "ERROR: b1 is not checked out" << endl;
    if (b1.getLocation() == ON_SHELF) {
      cout << "b1 is on the shelf" << endl;
    } else {
      cout << "b1 is on hold" << endl;
    }
  }

  if (b1.getCheckedOutBy() != &p2) {
    cout << "ERROR: p2 is not checking out this book" << endl;
    if (b1.getCheckedOutBy() == NULL) {
      cout << "ERROR: nobody is checking out this book" << endl;
    }
  }

  cout << "p1's total fine amount should be $0.00: "
       << p1.getFineAmount() << endl;
  cout << "p2's total fine amount should be $0.00: "
       << p2.getFineAmount() << endl;

  cout << "p2 should have 2 books checked out." << endl;
  if (p2.getCheckedOutBooks().size() != 2) {
    cout << "ERROR: p2 has" <<  p2.getCheckedOutBooks().size() << endl;
  }

  lib.checkOutBook("abc", "345");

  cout << "Now b3 should be checked out by p1." << endl;

  cout << "p1 should have 1 book checked out." << endl;
  if (p1.getCheckedOutBooks().size() != 1) {
    cout << "ERROR: p1 has" <<  p1.getCheckedOutBooks().size() << endl;
  }


  for (int i=0; i<24; i++)
     lib.incrementCurrentDate();

  cout << "It is now day 31." << endl;

  cout << "p1's total fine amount should be $0.30: "
       << p1.getFineAmount() << endl;
  cout << "p2's total fine amount should be $1.30: "
       << p2.getFineAmount() << endl;

  lib.payFine("bcd", 0.4);

  cout << "p2 just paid $0.40 in fines" << endl;
  cout << "p1's total fine amount should be $0.30: "
       << p1.getFineAmount() << endl;
  cout << "p2's total fine amount should be $0.90: "
       << p2.getFineAmount() << endl;


  cout << "p2 wants to return b2." << endl;
  cout << lib.returnBook("234") << endl;

  cout << "p2 should have 1 book checked out." << endl;
  if (p2.getCheckedOutBooks().size() != 1) {
    cout << "ERROR: p2 has" <<  p2.getCheckedOutBooks().size() << endl;
  }

  cout << "p2 wants to return b2 again." << endl;
  cout << lib.returnBook("234") << endl;

  cout << "p2 should have 1 book checked out." << endl;
  if (p2.getCheckedOutBooks().size() != 1) {
    cout << "ERROR: p2 has" <<  p2.getCheckedOutBooks().size() << endl;
  }

  cout << "p1 wants to request b1 but it is checked out." << endl;
  cout << lib.requestBook("abc", "123") << endl;

  if (b1.getLocation() != CHECKED_OUT) {
    cout << "ERROR: b1 is not checked out" << endl;
    if (b1.getLocation() == ON_SHELF) {
      cout << "b1 is on the shelf" << endl;
    } else {
      cout << "b1 is on hold" << endl;
    }
  }

  if (b1.getCheckedOutBy() != &p2) {
    cout << "ERROR: p2 is not checking out this book" << endl;
    if (b1.getCheckedOutBy() == NULL) {
      cout << "ERROR: nobody is checking out this book" << endl;
    }
  }

  cout << "p1 wants to request b2." << endl;
  cout << lib.requestBook("abc", "234") << endl;

  if (b2.getLocation() != ON_HOLD_SHELF) {
    cout << "ERROR: b2 is not on hold" << endl;
    if (b2.getLocation() == CHECKED_OUT) {
      cout << "b2 is checked out" << endl;
    } else {
      cout << "b2 is on the shelf" << endl;
    }
  }

  if (b2.getCheckedOutBy() != NULL) {
    cout << "ERROR: someone is checking out this book" << endl;
  }
  if (b2.getRequestedBy() != &p1) {
    cout << "ERROR: b2 is not requested by p1" << endl;
  }

  cout << "p2 wants to request b2." << endl;
  cout << lib.requestBook("bcd", "234") << endl;

  cout << "Testing getPatron()." << endl;
  if (&p1 != lib.getPatron("abc")) {
    cout << "ERROR: cannot find patron abc" << endl;
  }
  if (lib.getPatron("test") != NULL) {
    cout << "ERROR: patron test found when not there" << endl;
  }

  cout << "Testing getBook()." << endl;
  if (&b2 != lib.getBook("234")) {
    cout << "ERROR: cannot find book 234" << endl;
  }
  if (lib.getBook("test") != NULL) {
    cout << "ERROR: book test found when not there" << endl;
  }

  cout << "Attempting to return a book that isn't checked out." << endl;
  cout << lib.returnBook("234") << endl;

  cout << "Attempting to check out a book not in holdings." << endl;
  cout << lib.checkOutBook("abc", "456") << endl;

  return 0;
}
