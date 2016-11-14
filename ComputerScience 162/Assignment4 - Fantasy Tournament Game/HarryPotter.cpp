/************************************************************************************************************
** Program Filename: Creature.h
** Author: Peter Moldenhauer
** Date: 11/10/16
** Assignment: Assignment 4
** Description: This is the .cpp file for the HarryPotter class. HarryPotter is derived from the Creature class.
** Input: none
** Output: This class outputs information to the user regarding attacks, defense, roll results and name.
**************************************************************************************************************/

#include "HarryPotter.h"

/***********************************************************************************************
* Function: setData()
* Description: This function initializes all of the fields in the class
* Parameters: none
* Pre-Conditions: an object of this class must be created
* Post-Conditions: none
* Return: none
*************************************************************************************************/
void HarryPotter::setData(string tN){
    name = "Harry Potter";
    teamName = tN;
    armor = 0;
    strength = 10;
    dead = false;
    hogwarts = 1;  // hogwarts variable used for SPECIAL ABILITY
}

/***********************************************************************************************
* Function: attack()
* Description: This function lets this creature attack another one
* Parameters: none
* Pre-Conditions: an object of this class must be created
* Post-Conditions: none
* Return: the attack points directed towards the opposing creature
*************************************************************************************************/
int HarryPotter::attack(){
    int damage = attackRoll(); // call attackRoll function
    //cout << "Harry Potter attacks! Harry Potter generated " << damage << " damage points to opponent..." << endl;
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
void HarryPotter::defense(int d){
    int defense = defenseRoll(); // call defense roll function
    int damage;

    if (d != 999){
        //cout << "Harry Potter attempts to defend! Harry Potter generated " << defense << " defense points. " << endl;
        damage = d - defense;
    }
    else
        damage = d;

    if (damage <= 0){
        //cout << "Harry Potter defends! No change in armor and strength." << endl;
        //cout << "Remaining armor points: " << armor << endl;
        //cout << "Remaining strength points: " << strength << endl;
    }else if (damage == 999 && hogwarts == 1){ // SPECIAL ABILITY
        //cout << "Harry Potter Dies! Harry Potter looked into Medusa's eyes and turned to stone!" << endl;
        //cout << "~Hogwarts~ Harry Potter immediately recovered and now has 20 strength points!" << endl;
        hogwarts = 0;
        strength = 20;
        //cout << "Armor points: " << armor << endl;
        //cout << "Strength points: " << strength << endl;
    }else if (damage == 999 && hogwarts == 0){
        //cout << "Harry Potter Dies! Harry Potter looked into Medusa's eyes and turned to stone!" << endl;
        strength = 0;
        //cout << "Armor points: " << armor << endl;
        //cout << "Strength points: " << strength << endl;
        dead = true;  // Harry dies!
    }else if (damage > armor){
        damage = damage - armor;
        strength = strength - damage;
        armor = 0;
        if (strength > 0){
            //cout << "Harry Potter gets hurt but survives! " << endl;
            //cout << "Remaining armor points: " << armor << endl;
            //cout << "Remaining strength points: " << strength << endl;
        }else if(strength <= 0 && hogwarts == 1){  // SPECIAL ABILITY
            //cout << "Harry Dies! Defense not strong enough!" << endl;
            //cout << "~Hogwarts~ Harry Potter immediately recovered and now has 20 strength points!" << endl;
            hogwarts = 0;
            strength = 20;
            //cout << "Armor points: " << armor << endl;
            //cout << "Strength points: " << strength << endl;
        }else if(strength <= 0 && hogwarts == 0){
            //cout << "Harry Dies! Defense not strong enough!" << endl;
            //cout << "Armor points: " << armor << endl;
            //cout << "Strength points: " << strength << endl;
            dead = true;  // Harry dies!
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
string HarryPotter::getName(){
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
string HarryPotter::getTeamName(){
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
bool HarryPotter::isDead(){
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
int HarryPotter::attackRoll(){
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
int HarryPotter::defenseRoll(){
    int roll = rand() % 6 + 1;  // generate random number within 6
    roll = roll + (rand() % 6 + 1); // 2nd dice roll, add together
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
int HarryPotter::getArmor(){
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
int HarryPotter::getStrength(){
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
void HarryPotter::revive(){
    if (strength < 10)
        strength = 10;  // revive some strength but not all of it to the level of when creature started
}
