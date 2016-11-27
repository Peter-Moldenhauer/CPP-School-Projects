/************************************************************************************************************
** Program Filename: Space.cpp
** Author: Peter Moldenhauer
** Date: 11/25/16
** Assignment: Assignment 5 (Final Assignment)
** Description: This is the Space class .cpp file for a text based adventure game. The Space class
** is an abstract base class from which all of the unique spaces used in the game are derived from.
**************************************************************************************************************/

#include "Space.h"
#include "Character.h"

/*********************************************************************
** Function: Space()
** Description: This is the Space class default constructor. This
** constructor initializes various data members in the class.
*********************************************************************/
Space::Space() {
    this->fwd = NULL;
    this->back = NULL;
    this->left = NULL;
    this->right = NULL;
    this->requiresKey = false;
}

/*********************************************************************
** Function: ~Space()
** Description: This is the Space class destructor.
*********************************************************************/
Space::~Space() {
}

/*********************************************************************
** Function: Space()
** Description: This is the Space class constructor. This
** constructor initializes various data members in the class.
*********************************************************************/
Space::Space(Space *f, Space *b, Space *l, Space *r) {
    this->fwd = f;
    this->back = b;
    this->left = l;
    this->right = r;
    this->requiresKey = false;
}

/*********************************************************************
** Function: setLocation()
** Description: This function initializes various data members
*********************************************************************/
void Space::setLocation(Space *f, Space *b, Space *l, Space *r, Character *c, std::string s) {
    this->fwd = f;
    this->back = b;
    this->left = l;
    this->right = r;
    this->character = c;
    this->spaceName = s;
}

/*********************************************************************
** Function: manipulate()
** Description: This is a virtual function used in the derived classes.
** The default class behavior of the function is implemented here.
*********************************************************************/
void Space::manipulate() {
    std::cout << "Nothing to do here\n";
}

/*********************************************************************
** Function: getRequiresKey()
** Description: This function returns the requiresKey data member
*********************************************************************/
bool Space::getRequiresKey() {
    return this->requiresKey;
}

/*********************************************************************
** Function: getBack()
** Description: This function returns a space pointer or NULL
*********************************************************************/
Space* Space::getBack() {
    if (this->back != NULL) {
        return this->back;
    } else {
        return NULL;
    }
}

/*********************************************************************
** Function: getFwd()
** Description: This function returns a space pointer or NULL
*********************************************************************/
Space* Space::getFwd() {
    if (this->fwd != NULL) {
        return this->fwd;
    } else {
        return NULL;
    }
}

/*********************************************************************
** Function: getLeft()
** Description: This function returns a space pointer or NULL
*********************************************************************/
Space* Space::getLeft() {
    if (this->left != NULL) {
        return this->left;
    } else {
        return NULL;
    }
}

/*********************************************************************
** Function: getRight()
** Description: This function returns a space pointer or NULL
*********************************************************************/
Space* Space::getRight() {
    if (this->right != NULL) {
        return this->right;
    } else {
        return NULL;
    }
}

/*********************************************************************
** Function: getSpaceName()
** Description: This function returns a string to a given space name
*********************************************************************/
std::string Space::getSpaceName() {
    return this->spaceName;
}
