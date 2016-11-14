/************************************************************************************************************
** Program Filename: Creature.h
** Author: Peter Moldenhauer
** Date: 11/10/16
** Assignment: Assignment 4
** Description: This is the .cpp file for the Vampire class. Vampire is derived from the Creature class.
** Input: none
** Output: This class outputs information to the user regarding attacks, defense, roll results and name.
**************************************************************************************************************/

#include "Vampire.h"

/***********************************************************************************************
* Function: setData()
* Description: This function initializes all of the fields in the class
* Parameters: none
* Pre-Conditions: an object of this class must be created
* Post-Conditions: none
* Return: none
*************************************************************************************************/
void Vampire::setData(string tN){
    name = "Vampire";
    teamName = tN;
    armor = 1;
    strength = 18;
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
int Vampire::attack(){
    int damage = attackRoll();
    //cout << "Vampire attacks! Vampire generated " << damage << " damage points to opponent..." << endl;
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
void Vampire::defense(int d){
    int charm = rand() % 2 + 1; // determine if vampire charmed opponent into not attacking, 50% chance opponent does not attack

    if (charm == 1){ // SPECIAL ABILITY
        //cout << "Vampire charmed opponent into not attacking! Vampire takes no damage." << endl;
        //cout << "Remaining armor points: " << armor << endl;
        //cout << "Remaining strength points: " << strength << endl;
    }else{
        int defense = defenseRoll();
        int damage;

        if (d != 999){
            //cout << "Vampire attempts to defend! Vampire generated " << defense << " defense points. " << endl;
            damage = d - defense;
        }
        else
            damage = d;

        if (damage <= 0){
            //cout << "Vampire defends! No change in armor and strength." << endl;
            //cout << "Remaining armor points: " << armor << endl;
            //cout << "Remaining strength points: " << strength << endl;
        }else if (damage == armor){
            armor = armor - damage;
            //cout << "Vampire armor absorbed the attack! " << endl;
            //cout << "Remaining armor points: " << armor << endl;
            //cout << "Remaining strength points: " << strength << endl;
        }else if (damage == 999){
            //cout << "Vampire Dies! Vampire looked into Medusa's eyes and turned to stone!" << endl;
            //cout << "Armor points: 0" << endl;
            //cout << "Strength points: 0" << endl;
            dead = true;  // vampire dies!
        }else if (damage > armor){
            damage = damage - armor;
            strength = strength - damage;
            armor = 0;
            if (strength > 0){
                //cout << "Vampire gets hurt but survives! " << endl;
                //cout << "Remaining armor points: " << armor << endl;
                //cout << "Remaining strength points: " << strength << endl;
            }else if(strength <= 0){
                //cout << "Vampire Dies! Defense not strong enough!" << endl;
                //cout << "Armor points: " << armor << endl;
                //cout << "Strength points: " << strength << endl;
                dead = true;  // vampire dies!
            }
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
string Vampire::getName(){
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
string Vampire::getTeamName(){
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
bool Vampire::isDead(){
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
int Vampire::attackRoll(){
    int roll = rand() % 12 + 1;  // generate random number within 12
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
int Vampire::defenseRoll(){
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
int Vampire::getArmor(){
    return armor;
}

/***********************************************************************************************
* Function: getStrength()
* Description: This function returns this creatures strength points
* Parameters: none
* Pre-Conditions: an object of this class must first be created
* Post-Conditions: none
* Return: strength (this creatures strength points)
*************************************************************************************************/
int Vampire::getStrength(){
    return strength;
}

/***********************************************************************************************
* Function: revive()
* Description: This function revives vampire if vampire wins and is put back in Queue to fight
* again.
* Parameters: none
* Pre-Conditions: an object of this class must first be created
* Post-Conditions: vampire object has an increase in strength points
* Return: non
*************************************************************************************************/
void Vampire::revive(){
    if (strength < 10)
        strength = 10;  // revive some strength but not all of it to the level of when creature started
}
