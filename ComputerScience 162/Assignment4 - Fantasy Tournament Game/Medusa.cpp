/************************************************************************************************************
** Program Filename: Creature.h
** Author: Peter Moldenhauer
** Date: 11/10/16
** Assignment: Assignment 4
** Description: This is the .cpp file for the Medusa class. Medusa is derived from the Creature class.
** Input: none
** Output: This class outputs information to the user regarding attacks, defense, roll results and name.
**************************************************************************************************************/

#include "Medusa.h"

/***********************************************************************************************
* Function: setData()
* Description: This function initializes all of the fields in the class
* Parameters: none
* Pre-Conditions: an object of this class must be created
* Post-Conditions: none
* Return: none
*************************************************************************************************/
void Medusa::setData(string tN){
    name = "Medusa";
    teamName = tN;
    armor = 3;
    strength = 8;
    dead = false;
}

/***********************************************************************************************
* Function: attack()
* Description: This function lets this creature attack another one
* Parameters: none
* Pre-Conditions: an object of this class must be created
* Post-Conditions: none
* Return: the attack points directed towards the opposing creature
*************************************************************************************************/
int Medusa::attack(){
    int damage = attackRoll();
    if (damage == 12){  // SPECIAL ABLITY
        //cout << "Medusa rolled a 12! Opponent has looked in Medusa's eyes and turned to stone!" << endl;
        damage = 999;
    }else if(damage != 12){
        //cout << "Medusa attacks! Medusa generated " << damage << " damage points to opponent..." << endl;
    }
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
void Medusa::defense(int d){
    int defense = defenseRoll();
    int damage;

    if (d != 999){
        //cout << "Medusa attempts to defend! Medusa generated " << defense << " defense points. " << endl;
        damage = d - defense;
    }
    else
        damage = d;

    if (damage <= 0){
        //cout << "Medusa defends! No change in armor and strength." << endl;
        //cout << "Remaining armor points: " << armor << endl;
        //cout << "Remaining strength points: " << strength << endl;
    }else if (damage > 0 && damage <= armor){
        armor = armor - damage;
        //cout << "Medusa's armor absorbed the attack! " << endl;
        //cout << "Remaining armor points: " << armor << endl;
        //cout << "Remaining strength points: " << strength << endl;
    }else if (damage == 999){
        //cout << "Medusa Dies! Medusa looked into other Medusa's eyes and turned to stone!" << endl;
        //cout << "Armor points: 0" << endl;
        //cout << "Strength points: 0" << endl;
        dead = true;
    }else if (damage > armor){
        damage = damage - armor;
        strength = strength - damage;
        armor = 0;
        if (strength > 0){
            //cout << "Medusa gets hurt but survives! " << endl;
            //cout << "Remaining armor points: " << armor << endl;
            //cout << "Remaining strength points: " << strength << endl;
        }else if(strength <= 0){
            //cout << "Medusa Dies! Defense not strong enough!" << endl;
            //cout << "Armor points: " << armor << endl;
            //cout << "Strength points: " << strength << endl;
            dead = true;  // vampire dies!
        }
    }
}

/***********************************************************************************************
* Function: getName()
* Description: This function returns this creatures name
* Parameters: none
* Pre-Conditions: an object of this class must first be created
* Post-Conditions: none
* Return: name (the name of this creature)
*************************************************************************************************/
string Medusa::getName(){
    return name;
}

/***********************************************************************************************
* Function: getTeamName()
* Description: This function returns this creatures name
* Parameters: none
* Pre-Conditions: an object of this class must first be created
* Post-Conditions: none
* Return: name (the name of this creature)
*************************************************************************************************/
string Medusa::getTeamName(){
    return teamName;
}

/***********************************************************************************************
* Function: isDead()
* Description: This function returns a bool variable relating to if this creature is dead or not
* Parameters: none
* Pre-Conditions: an object of this class must first be created
* Post-Conditions: none
* Return: dead (bool variable that is either true or false)
*************************************************************************************************/
bool Medusa::isDead(){
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
int Medusa::attackRoll(){
    int roll = rand() % 6 + 1;  // generate random number within 6
    roll = roll + (rand() % 6 + 1); // 2nd dice roll, add together
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
int Medusa::defenseRoll(){
    int roll = rand() % 6 + 1;  // generate random number within 6
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
int Medusa::getArmor(){
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
int Medusa::getStrength(){
    return strength;
}

/***********************************************************************************************
* Function: revive()
* Description: This function revives creature if it wins and is put back in Queue to fight
* again.
* Parameters: none
* Pre-Conditions: an object of this class must first be created
* Post-Conditions: vampire object has an increase in strength points
* Return: non
*************************************************************************************************/
void Medusa::revive(){
    if (strength < 4)
        strength = 6;  // revive some strength but not all of it to the level of when creature started
}
