/************************************************************************************************************
** Program Filename: Character.cpp
** Author: Peter Moldenhauer
** Date: 11/25/16
** Assignment: Assignment 5 (Final Assignment)
** Description: This is the Character class .cpp file for a text based adventure game. The Character class
** implements the character and character attributes that will be moving through the spaces in the game.
**************************************************************************************************************/

#include "Character.h"
#include "Space.h"


/*********************************************************************
** Function: Character()
** Description: This is the Character class constructor. This
** constructor initializes various data members in the class.
*********************************************************************/
Character::Character() {
    this->hasCKey = false;
    this->hasKey = false;
}

/*********************************************************************
** Function: setName()
** Description: This function initializes the name data member
*********************************************************************/
void Character::setName(std::string n) {
    this->name = n;
}

/*********************************************************************
** Function: setHasKey()
** Description: This function initializes the hasKey data member
*********************************************************************/
void Character::setHasKey(bool b) {
    this->hasKey = b;
}

/*********************************************************************
** Function: setHasCKey()
** Description: This function initializes the hasCKey data member
*********************************************************************/
void Character::setHasCKey(bool b) {
    this->hasCKey = b;
}

/*********************************************************************
** Function: setCurrentSpace()
** Description: This function initializes the currentSpace data
** member to a specific Space class pointer
*********************************************************************/
void Character::setCurrentSpace(Space *c) {
    this->currentSpace = c;
}

/*********************************************************************
** Function: getCurrentSpace()
** Description: This function returns this specific class's current
** space (a pointer to a Space object)
*********************************************************************/
Space* Character::getCurrentSpace() {
    return this->currentSpace;
}

/*********************************************************************
** Function: getHasKey()
** Description: This function returns this specific class's hasKey
** data member
*********************************************************************/
bool Character::getHasKey() {
    return this->hasKey;
}

/*********************************************************************
** Function: getHasCKey()
** Description: This function returns this specific class's hasCKey
** data member
*********************************************************************/
bool Character::getHasCKey() {
    return this->hasCKey;
}

/*********************************************************************
** Function: moveFwd()
** Description: This function checks for NULL pointers, then moves the
** character forward or displays a message
*********************************************************************/
void Character::moveFwd() {
    if (currentSpace->getFwd() != NULL) {
        // If space requires key (locomotive cab)
        if (!currentSpace->getFwd()->getRequiresKey()) {
            std::cout << "\nMoving forward...";
            //sleep(1);
            this->currentSpace = currentSpace->getFwd();
            std::cout << "You're now " << this->currentSpace->getSpaceName();
        } else {
            if (currentSpace->getFwd()->getSpaceName() == "in the locomotive cab") {
                if (this->getHasCKey()) {
                    this->currentSpace = currentSpace->getFwd();
                    std::cout << "\nMoving forward...\n"
                    << "** Entering the locomotive cab **\n";
                } else {
                    std::cout << "\nThe locomotive cab seems to be locked.\n";
                }
            }
        }
    } else {
        std::cout << "\nThere's no way forward from here.\n";
    }
}

/*********************************************************************
** Function: moveBack()
** Description: This function checks for NULL pointers, then moves the
** character backwards or displays a message
*********************************************************************/
void Character::moveBack() {
    if (currentSpace->getBack() != NULL) {
        if (!currentSpace->getBack()->getRequiresKey()) {
            std::cout << "\nMoving backward...";
            //sleep(1);
            this->currentSpace = currentSpace->getBack();
            std::cout << "You're now " << this->currentSpace->getSpaceName();
        } else {
            if (currentSpace->getBack()->getSpaceName() == "in the baggage car") {
                if (this->getHasKey()) {
                    this->currentSpace = currentSpace->getBack();
                    std::cout << "\nMoving backward...\n"
                    << "** Entering the baggage area **\n";
                } else {
                    std::cout << "\nThis door seems to be locked.\n";
                }
            } else if (currentSpace->getBack()->getSpaceName() == "in the locomotive cab") {
                std::cout << "\nMoving backward...";
                //sleep(1);
                this->currentSpace = currentSpace->getBack();
                std::cout << "You're now " << this->currentSpace->getSpaceName();
            }
        }
    } else {
        std::cout << "\nThere's no way backward from here.\n";
    }
}

/*********************************************************************
** Function: moveLeft()
** Description: This function checks for NULL pointers, then moves the
** character left or displays a message
*********************************************************************/
void Character::moveLeft() {
    if (currentSpace->getLeft() != NULL) {
        std::cout << "\nMoving left...";
        //sleep(1);
        this->currentSpace = currentSpace->getLeft();
        std::cout << "You're now " << this->currentSpace->getSpaceName();
    } else {
        std::cout << "\nYou can't go that way.\n";
    }
}

/*********************************************************************
** Function: moveRight()
** Description: This function checks for NULL pointers, then moves the
** character right or displays a message
*********************************************************************/
void Character::moveRight() {
    if (currentSpace->getRight() != NULL) {
        std::cout << "\nMoving right...";
        //sleep(1);
        this->currentSpace = currentSpace->getRight();
        std::cout << "You're now " << this->currentSpace->getSpaceName();
    } else {
        std::cout << "\nYou can't go that way.\n";
    }
}

/*********************************************************************
** Function: getName()
** Description: This function returns this specific class's name data
** member
*********************************************************************/
std::string Character::getName() {
    return this->name;
}

/*********************************************************************
** Function: addObject()
** Description: This function adds an item to the objects vector
*********************************************************************/
void Character::addObject(std::string o) {
    this->objects.push_back(o);
    std::cout << "\n\n** " << o << " acquired **\n";
}

/*********************************************************************
** Function: objectSearch()
** Description: This function searches the objects vector for a
** specific item. If the item is found, true is returned, if the item
** is not found, then false is returned.
*********************************************************************/
bool Character::objectSearch(std::string s) {
    size_t i;
    for (i = 0; i < this->objects.size(); i++) {
        if (objects[i] == s) {
            return true;
        }
    }

    return false;
}
