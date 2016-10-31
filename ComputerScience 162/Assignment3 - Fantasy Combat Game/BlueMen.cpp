/************************************************************************************************************
** Program Filename: Creature.h
** Author: Peter Moldenhauer
** Date: 10/30/16
** Assignment: Assignment 3
** Description: This is the .cpp file for the BlueMen class. BlueMen is derived from the Creature class.
** Input: none
** Output: This class outputs information to the user regarding attacks, defense, roll results and name.
**************************************************************************************************************/

#include "BlueMen.h"

/***********************************************************************************************
* Function: setData()
* Description: This function initializes all of the fields in the class
* Parameters: none
* Pre-Conditions: an object of this class must be created
* Post-Conditions: none
* Return: none
*************************************************************************************************/
void BlueMen::setData(){
    name = "Blue Men";
    armor = 3;
    strength = 12;
    dead = false;
    loseDie = 0;  // SPECIAL ABLITY
}

/***********************************************************************************************
* Function: attack()
* Description: This function lets this creature attack another one
* Parameters: none
* Pre-Conditions: an object of this class must be created
* Post-Conditions: none
* Return: the attack points directed towards the opposing creature
*************************************************************************************************/
int BlueMen::attack(){
    int damage = attackRoll();
    cout << "Blue Men attack! Blue Men generated " << damage << " damage points to opponent..." << endl;
    return damage;
}

/***********************************************************************************************
* Function: defense()
* Description: This function lets this creature defend and possibly die if attack was too strong
* Parameters: d (the attack points from the opposing creature)
* Pre-Conditions: an object of this class must be created
* Post-Conditions: none
* Return: none
*************************************************************************************************/
void BlueMen::defense(int d){
    int defense = defenseRoll();
    int damage;

    if (d != 999){
        cout << "Blue Men attempt to defend! Blue Men generated " << defense << " defense points. " << endl;
        damage = d - defense;
    }
    else
        damage = d;

    if (damage <= 0){
        cout << "Blue Men defend! No change in armor and strength." << endl;
        cout << "Remaining armor points: " << armor << endl;
        cout << "Remaining strength points: " << strength << endl;
    }else if (damage > 0 && damage <= armor){
        armor = armor - damage;
        cout << "Blue Men's armor absorbed the attack! " << endl;
        cout << "Remaining armor points: " << armor << endl;
        cout << "Remaining strength points: " << strength << endl;
    }else if (damage == 999){
        cout << "Blue Men Die! Blue Men all looked into Medusa's eyes and all turned to stone!" << endl;
        cout << "Armor points: 0" << endl;
        cout << "Strength points: 0" << endl;
        dead = true;  // vampire dies!
    }else if (damage > armor){
        damage = damage - armor;
        strength = strength - damage;
        armor = 0;
        if (strength > 0){
            cout << "Blue Men get hurt but survive! " << endl;
            cout << "Remaining armor points: " << armor << endl;
            cout << "Remaining strength points: " << strength << endl;
        }else if(strength <= 0){
            cout << "Blue Men Die! Defense not strong enough!" << endl;
            cout << "Armor points: " << armor << endl;
            cout << "Strength points: " << strength << endl;
            dead = true;  // vampire dies!
        }
    }

    // SPECIAL ABILITY - Mob - for every 4 points of damage they lose one defense die
    if (strength <= 8 && strength > 4)
        loseDie = 1; // lose 1 die
    else if (strength <= 4 && strength > 0)
        loseDie = 2; // lose 2 die
}

/***********************************************************************************************
* Function: getName()
* Description: This function returns this creatures name
* Parameters: none
* Pre-Conditions: an object of this class must first be created
* Post-Conditions: none
* Return: name (the name of this creature)
*************************************************************************************************/
string BlueMen::getName(){
    return name;
}

/***********************************************************************************************
* Function: isDead()
* Description: This function returns a bool variable relating to if this creature is dead or not
* Parameters: none
* Pre-Conditions: an object of this class must first be created
* Post-Conditions: none
* Return: dead (bool variable that is either true or false)
*************************************************************************************************/
bool BlueMen::isDead(){
    return dead;
}

/***********************************************************************************************
* Function: attackRoll()
* Description: This function rolls the appropriate die for this creatures attack
* Parameters: none
* Pre-Conditions: an object of this class must first be created
* Post-Conditions: none
* Return: roll (the roll result)
*************************************************************************************************/
int BlueMen::attackRoll(){
    int roll = rand() % 10 + 1;  // generate random number within 10
    roll = roll + (rand() % 10 + 1); // 2nd dice roll, add together
    return roll;
}

/***********************************************************************************************
* Function: defenseRoll()
* Description: This function rolls the appropriate die for this creatures defense
* Parameters: none
* Pre-Conditions: an object of this class must first be created
* Post-Conditions: none
* Return: roll (the roll result)
*************************************************************************************************/
int BlueMen::defenseRoll(){
    int roll;
    if (loseDie == 0){
        roll = rand() % 6 + 1;  // generate random number within 6
        roll = roll + (rand() % 6 + 1); // 2nd dice roll, add together
        roll = roll + (rand() % 6 + 1); // 3rd dice roll, add together
    }else if (loseDie == 1){
        roll = rand() % 6 + 1;  // generate random number within 6
        roll = roll + (rand() % 6 + 1); // 2nd dice roll, add together
    }else if (loseDie == 2){
        roll = rand() % 6 + 1;  // generate random number within 6
    }
    return roll;
}

/***********************************************************************************************
* Function: getArmor()
* Description: This function returns this creatures armor points
* Parameters: none
* Pre-Conditions: an object of this class must first be created
* Post-Conditions: none
* Return: armor (this creatures armor points)
*************************************************************************************************/
int BlueMen::getArmor(){
    return armor;
}

/***********************************************************************************************
* Function: getArmor()
* Description: This function returns this creatures strength points
* Parameters: none
* Pre-Conditions: an object of this class must first be created
* Post-Conditions: none
* Return: strength (this creatures strength points)
*************************************************************************************************/
int BlueMen::getStrength(){
    return strength;
}
