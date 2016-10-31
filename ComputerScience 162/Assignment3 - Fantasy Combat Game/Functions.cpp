/************************************************************************************************************
** Program Filename: Functions.cpp
** Author: Peter Moldenhauer
** Date: 10/30/16
** Assignment: Assignment 3
** Description: This is the .cpp file for various functions that are used in the main.cpp file for a program
** that implements a fantasy combat game. These functions print out menu's to the screen, get and validate
** user input and run test fights between creatures.
** Input: Some of the functions in this file require user input.
** Output: Some of these functions output information to the user (menu's and results of test fights).
**************************************************************************************************************/

#include "Functions.h"

/***********************************************************************************************
* Function: showMenu()
* Description: This function displays the opening menu to the user
* Parameters: none
* Pre-Conditions: none
* Post-Conditions: none
* Return: none
*************************************************************************************************/
void showMenu(){
    cout << "Please select one of the following options... " << endl;
    cout << "1) View game rules and descriptions of creatures." << endl;
    cout << "2) Start combat between two creatures." << endl;
    cout << "3) Run test driver to simulate all possible creature attacks." << endl;
    cout << "4) Exit program." << endl;
}

/***********************************************************************************************
* Function: getChoice()
* Description: This function prompts user for menu selection choice and validates the input
* Parameters: none
* Pre-Conditions: Beginning menu has to be displayed to the user first
* Post-Conditions: none
* Return: user menu choice
*************************************************************************************************/
int getChoice(){
    bool getData = true;
    int userInput;

    while (getData == true){
        cout << "Enter [1 - 4]: ";
        cin >> userInput;
        if (userInput > 0 && userInput <= 4){
            getData = false;
        }else{
            cout << "Please enter either 1, 2, 3 or 4 to make your selection!" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
    return userInput;
}

/***********************************************************************************************
* Function: showRules()
* Description: This function displays the game rules and the descriptions of the creatures
* Parameters: none
* Pre-Conditions: user must choose to view the rules via the main menu
* Post-Conditions: none
* Return: none
*************************************************************************************************/
void showRules(){
    //cout <<"\033[2J\033[1;1H";   // clear the screen
    system("CLS");                 // clear the screen WINDOWS

    cout << "\t\t\t\t- GAME RULES -\n" << endl;
    cout << "This program allows two creatures to battle each other at a time" << endl;
    cout << "Each creature starts off with its own unique armor and strength points." << endl;
    cout << "Each creature will take turns rolling the appropriate number and type of dice for attack and defense." << endl;
    cout << "Creature 1 will attack by rolling the dice and then creature 2 will roll a dice for defense." << endl;
    cout << "The defense roll will then be subtracted from the attack roll." << endl;
    cout << "The result will be the damage to the defender (creature 2)." << endl;
    cout << "Creature 2 then attacks creature 1 and creature 1 defends." << endl;
    cout << "The attacking will continue until one of the creatures' strength points goes to 0 or less.\n" << endl;
    cout << "\t\t\t  - Description of Creatures -\n" << endl;
    cout << "** VAMPIRE ** Suave, debonair, but vicious and surprisingly resilient! " << endl;
    cout << "Vampires can charm an opponent into not attacking. For a given attack there is a 50% chance that their" << endl;
    cout << "opponent does not actually attack them." << endl;
    cout << "Armor: 1, Strength Points: 18\n" << endl;
    cout << "** Barbarian ** Similar to Conan or Hercules from the movies. Big sword, big muscles, bare torso." << endl;
    cout << "Armor: 0, Strength Points: 12\n" << endl;
    cout << "** Blue Men ** These small men are fast and tough. They are hard to hit and can take some damage. " << endl;
    cout << "They can do a lot of damage when they crawl inside the armor or clothing of an opponent. " << endl;
    cout << "Blue Men are a swarm of individuals. For every 4 points of damage they lose one defense die." << endl;
    cout << "Armor: 3, Strength Points: 12\n" << endl;
    cout << "** Medusa ** Scrawny lady with snakes for hair. They help with fighting. Just don't look at her!" << endl;
    cout << "If Medusa rolls a 12 in attack, then the target has looked her in the eyes and is turned to stone." << endl;
    cout << "The Medusa then wins!" << endl;
    cout << "Armor: 3, Strength Points: 8\n " << endl;
    cout << "** Harry Potter ** Everyone knows who Harry Potter is, no description needed!" << endl;
    cout << "If Harry dies, he immediately recovers and his total strength becomes 20. " << endl;
    cout << "If he were to die again, then he is dead." << endl;
    cout << "Armor: 0, Strength Points: 10 (first life), 20 (second life)\n" << endl;

    cout << "Press ENTER to return to the main menu...";
    cin.get();
    // clear the screen
    //cout <<"\033[2J\033[1;1H";   // clear the screen FLIP
    system("CLS");                 // clear the screen WINDOWS
}

/***********************************************************************************************************************
* Function: getCreature1()
* Description: This function prompts user on which creature to use for player 1, it also verifies that input is correct
* Parameters: none
* Pre-Conditions: user must choose to start a two player game first via the main menu
* Post-Conditions: none
* Return: user input of which creature they want to select
*************************************************************************************************************************/
int getCreature1(){
    //cout <<"\033[2J\033[1;1H";   // clear the screen
    system("CLS");                 // clear the screen WINDOWS

    cout << "Which creature will player 1 be using... " << endl;
    cout << "1) Vampire" << endl;
    cout << "2) Barbarian" << endl;
    cout << "3) Blue Men" << endl;
    cout << "4) Medusa" << endl;
    cout << "5) Harry Potter" << endl;

    bool getData = true;
    int userInput;

    while (getData == true){
        cout << "Enter [1 - 5]: ";
        cin >> userInput;
        if (userInput > 0 && userInput <= 5){
            getData = false;
        }else{
            cout << "Please enter either 1, 2, 3, 4 or 5 to make your selection!" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
    return userInput;
}

/***********************************************************************************************************************
* Function: getCreature2()
* Description: This function prompts user on which creature to use for player 2, it also verifies that input is correct
* Parameters: none
* Pre-Conditions: user must choose to start a two player game first via the main menu
* Post-Conditions: none
* Return: user input of which creature they want to select
*************************************************************************************************************************/
int getCreature2(){

    cout << "\nWhich creature will player 2 be using... " << endl;
    cout << "1) Vampire" << endl;
    cout << "2) Barbarian" << endl;
    cout << "3) Blue Men" << endl;
    cout << "4) Medusa" << endl;
    cout << "5) Harry Potter" << endl;

    bool getData = true;
    int userInput;

    while (getData == true){
        cout << "Enter [1 - 5]: ";
        cin >> userInput;
        if (userInput > 0 && userInput <= 5){
            cout << endl;
            getData = false;
        }else{
            cout << "Please enter either 1, 2, 3, 4 or 5 to make your selection!" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
    return userInput;
}

/***********************************************************************************************
* Function: showTestMenu()
* Description: This function displays the menu in the testing suite option
* Parameters: none
* Pre-Conditions: user must choose the testing suite option via the main menu
* Post-Conditions: none
* Return: none
*************************************************************************************************/
void showTestMenu(){
    //cout <<"\033[2J\033[1;1H";   // clear the screen
    system("CLS");                 // clear the screen WINDOWS

    cout << "*** TESTING SUITE *** " << endl;
    cout << "Here you will be able to test and run every combination of creature attacks." << endl;
    cout << "\nPlease select one of the following options... " << endl;
    cout << "1) Vampire vs. Vampire" << endl;
    cout << "2) Vampire vs. Barbarian" << endl;
    cout << "3) Vampire vs. Blue Men" << endl;
    cout << "4) Vampire vs. Medusa" << endl;
    cout << "5) Vampire vs. Harry Potter" << endl;
    cout << "6) Barbarian vs. Barbarian" << endl;
    cout << "7) Barbarian vs. Blue Men" << endl;
    cout << "8) Barbarian vs. Medusa" << endl;
    cout << "9) Barbarian vs. Harry Potter" << endl;
    cout << "10) Blue Men vs. Blue Men" << endl;
    cout << "11) Blue Men vs. Medusa" << endl;
    cout << "12) Blue Men vs. Harry Potter" << endl;
    cout << "13) Medusa vs. Medusa" << endl;
    cout << "14) Medusa vs. Harry Potter" << endl;
    cout << "15) Harry Potter vs. Harry Potter" << endl;
    cout << "16) Return to main menu\n" << endl;
}

/***********************************************************************************************
* Function: getTestChoice()
* Description: This function gets and verifies the user input selection from the testing menu
* Parameters: none
* Pre-Conditions: user must first view the testing menu choices to know what numbers to enter
* Post-Conditions: none
* Return: none
*************************************************************************************************/
int getTestChoice(){
    bool getData = true;
    int userInput;

    while (getData == true){
        cout << "Enter [1 - 15] to test attack or enter 16 to return to main menu: ";
        cin >> userInput;

        if (userInput > 0 && userInput <= 16){
            getData = false;
        }else{
            cout << "Please enter either 1 through 16 to make your selection!" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
    return userInput;
}

/***********************************************************************************************
* Function: runTests()
* Description: This function allows the user to test an attack of any match up of creatures
* Parameters: none
* Pre-Conditions: user selects which match up to be run
* Post-Conditions: none
* Return: none
*************************************************************************************************/
void runTests(int t){
    int damage;
    Creature *creature1;
    Creature *creature2;

    if (t == 1){
        creature1 = new Vampire;
        creature2 = new Vampire;

        // initialize the data members for the creatures
        creature1->setData();
        creature2->setData();

        cout << "\nPlayer 1 is: " << creature1->getName() << endl;
        cout << "Player 2 is: " << creature2->getName() << endl;
        cout << endl;

        bool p1Dead = false;
        bool p2Dead = false;

        while (p1Dead == false && p2Dead == false){
            cout << "Player 1 attack:" << endl;
            damage = creature1->attack(); // creature1 attack
            cout << "\nPlayer 2 defense:" << endl;
            creature2->defense(damage);  // creature2 defend

            p2Dead = creature2->isDead(); // check to see if creature2 died

            if (p2Dead == false){
                cout << "\nPlayer 2 attack:" << endl;
                damage = creature2->attack(); // creature2 attack
                cout << "\nPlayer 1 defense:" << endl;
                creature1->defense(damage); // creature1 defend
                cout << endl;
            }
            p1Dead = creature1->isDead(); // check to see if creature1 died
        }
        // Game over, display winner/loser
        if (p1Dead == true){
            cout << "\n*** Battle over - Player 2 Wins with " << creature2->getName() << "!!! ***" << endl;
        }else if(p2Dead == true){
            cout << "\n*** Battle over - Player 1 Wins with " << creature1->getName() << "!!! ***" << endl;

        // deallocate memory
        delete creature1;
        delete creature2;
        }

    }else if (t == 2){
        creature1 = new Vampire;
        creature2 = new Barbarian;

        // initialize the data members for the creatures
        creature1->setData();
        creature2->setData();

        cout << "\nPlayer 1 is: " << creature1->getName() << endl;
        cout << "Player 2 is: " << creature2->getName() << endl;
        cout << endl;

        bool p1Dead = false;
        bool p2Dead = false;

        while (p1Dead == false && p2Dead == false){
            cout << "Player 1 attack:" << endl;
            damage = creature1->attack(); // creature1 attack
            cout << "\nPlayer 2 defense:" << endl;
            creature2->defense(damage);  // creature2 defend

            p2Dead = creature2->isDead(); // check to see if creature2 died

            if (p2Dead == false){
                cout << "\nPlayer 2 attack:" << endl;
                damage = creature2->attack(); // creature2 attack
                cout << "\nPlayer 1 defense:" << endl;
                creature1->defense(damage); // creature1 defend
                cout << endl;
            }
            p1Dead = creature1->isDead(); // check to see if creature1 died
        }
        // Game over, display winner/loser
        if (p1Dead == true){
            cout << "\n*** Battle over - Player 2 Wins with " << creature2->getName() << "!!! ***" << endl;
        }else if(p2Dead == true){
            cout << "\n*** Battle over - Player 1 Wins with " << creature1->getName() << "!!! ***" << endl;

        // deallocate memory
        delete creature1;
        delete creature2;
        }

    }else if (t == 3){
        creature1 = new Vampire;
        creature2 = new BlueMen;

        // initialize the data members for the creatures
        creature1->setData();
        creature2->setData();

        cout << "\nPlayer 1 is: " << creature1->getName() << endl;
        cout << "Player 2 is: " << creature2->getName() << endl;
        cout << endl;

        bool p1Dead = false;
        bool p2Dead = false;

        while (p1Dead == false && p2Dead == false){
            cout << "Player 1 attack:" << endl;
            damage = creature1->attack(); // creature1 attack
            cout << "\nPlayer 2 defense:" << endl;
            creature2->defense(damage);  // creature2 defend

            p2Dead = creature2->isDead(); // check to see if creature2 died

            if (p2Dead == false){
                cout << "\nPlayer 2 attack:" << endl;
                damage = creature2->attack(); // creature2 attack
                cout << "\nPlayer 1 defense:" << endl;
                creature1->defense(damage); // creature1 defend
                cout << endl;
            }
            p1Dead = creature1->isDead(); // check to see if creature1 died
        }
        // Game over, display winner/loser
        if (p1Dead == true){
            cout << "\n*** Battle over - Player 2 Wins with " << creature2->getName() << "!!! ***" << endl;
        }else if(p2Dead == true){
            cout << "\n*** Battle over - Player 1 Wins with " << creature1->getName() << "!!! ***" << endl;

        // deallocate memory
        delete creature1;
        delete creature2;
        }

    }else if (t == 4){
        creature1 = new Vampire;
        creature2 = new Medusa;

        // initialize the data members for the creatures
        creature1->setData();
        creature2->setData();

        cout << "\nPlayer 1 is: " << creature1->getName() << endl;
        cout << "Player 2 is: " << creature2->getName() << endl;
        cout << endl;

        bool p1Dead = false;
        bool p2Dead = false;

        while (p1Dead == false && p2Dead == false){
            cout << "Player 1 attack:" << endl;
            damage = creature1->attack(); // creature1 attack
            cout << "\nPlayer 2 defense:" << endl;
            creature2->defense(damage);  // creature2 defend

            p2Dead = creature2->isDead(); // check to see if creature2 died

            if (p2Dead == false){
                cout << "\nPlayer 2 attack:" << endl;
                damage = creature2->attack(); // creature2 attack
                cout << "\nPlayer 1 defense:" << endl;
                creature1->defense(damage); // creature1 defend
                cout << endl;
            }
            p1Dead = creature1->isDead(); // check to see if creature1 died
        }
        // Game over, display winner/loser
        if (p1Dead == true){
            cout << "\n*** Battle over - Player 2 Wins with " << creature2->getName() << "!!! ***" << endl;
        }else if(p2Dead == true){
            cout << "\n*** Battle over - Player 1 Wins with " << creature1->getName() << "!!! ***" << endl;

        // deallocate memory
        delete creature1;
        delete creature2;
        }

    }else if (t == 5){
        creature1 = new Vampire;
        creature2 = new HarryPotter;

        // initialize the data members for the creatures
        creature1->setData();
        creature2->setData();

        cout << "\nPlayer 1 is: " << creature1->getName() << endl;
        cout << "Player 2 is: " << creature2->getName() << endl;
        cout << endl;

        bool p1Dead = false;
        bool p2Dead = false;

        while (p1Dead == false && p2Dead == false){
            cout << "Player 1 attack:" << endl;
            damage = creature1->attack(); // creature1 attack
            cout << "\nPlayer 2 defense:" << endl;
            creature2->defense(damage);  // creature2 defend

            p2Dead = creature2->isDead(); // check to see if creature2 died

            if (p2Dead == false){
                cout << "\nPlayer 2 attack:" << endl;
                damage = creature2->attack(); // creature2 attack
                cout << "\nPlayer 1 defense:" << endl;
                creature1->defense(damage); // creature1 defend
                cout << endl;
            }
            p1Dead = creature1->isDead(); // check to see if creature1 died
        }
        // Game over, display winner/loser
        if (p1Dead == true){
            cout << "\n*** Battle over - Player 2 Wins with " << creature2->getName() << "!!! ***" << endl;
        }else if(p2Dead == true){
            cout << "\n*** Battle over - Player 1 Wins with " << creature1->getName() << "!!! ***" << endl;

        // deallocate memory
        delete creature1;
        delete creature2;
        }

    }else if (t == 6){
        creature1 = new Barbarian;
        creature2 = new Barbarian;

        // initialize the data members for the creatures
        creature1->setData();
        creature2->setData();

        cout << "\nPlayer 1 is: " << creature1->getName() << endl;
        cout << "Player 2 is: " << creature2->getName() << endl;
        cout << endl;

        bool p1Dead = false;
        bool p2Dead = false;

        while (p1Dead == false && p2Dead == false){
            cout << "Player 1 attack:" << endl;
            damage = creature1->attack(); // creature1 attack
            cout << "\nPlayer 2 defense:" << endl;
            creature2->defense(damage);  // creature2 defend

            p2Dead = creature2->isDead(); // check to see if creature2 died

            if (p2Dead == false){
                cout << "\nPlayer 2 attack:" << endl;
                damage = creature2->attack(); // creature2 attack
                cout << "\nPlayer 1 defense:" << endl;
                creature1->defense(damage); // creature1 defend
                cout << endl;
            }
            p1Dead = creature1->isDead(); // check to see if creature1 died
        }
        // Game over, display winner/loser
        if (p1Dead == true){
            cout << "\n*** Battle over - Player 2 Wins with " << creature2->getName() << "!!! ***" << endl;
        }else if(p2Dead == true){
            cout << "\n*** Battle over - Player 1 Wins with " << creature1->getName() << "!!! ***" << endl;

        // deallocate memory
        delete creature1;
        delete creature2;
        }

    }else if (t == 7){
        creature1 = new Barbarian;
        creature2 = new BlueMen;

        // initialize the data members for the creatures
        creature1->setData();
        creature2->setData();

        cout << "\nPlayer 1 is: " << creature1->getName() << endl;
        cout << "Player 2 is: " << creature2->getName() << endl;
        cout << endl;

        bool p1Dead = false;
        bool p2Dead = false;

        while (p1Dead == false && p2Dead == false){
            cout << "Player 1 attack:" << endl;
            damage = creature1->attack(); // creature1 attack
            cout << "\nPlayer 2 defense:" << endl;
            creature2->defense(damage);  // creature2 defend

            p2Dead = creature2->isDead(); // check to see if creature2 died

            if (p2Dead == false){
                cout << "\nPlayer 2 attack:" << endl;
                damage = creature2->attack(); // creature2 attack
                cout << "\nPlayer 1 defense:" << endl;
                creature1->defense(damage); // creature1 defend
                cout << endl;
            }
            p1Dead = creature1->isDead(); // check to see if creature1 died
        }
        // Game over, display winner/loser
        if (p1Dead == true){
            cout << "\n*** Battle over - Player 2 Wins with " << creature2->getName() << "!!! ***" << endl;
        }else if(p2Dead == true){
            cout << "\n*** Battle over - Player 1 Wins with " << creature1->getName() << "!!! ***" << endl;

        // deallocate memory
        delete creature1;
        delete creature2;
        }

    }else if (t == 8){
        creature1 = new Barbarian;
        creature2 = new Medusa;

        // initialize the data members for the creatures
        creature1->setData();
        creature2->setData();

        cout << "\nPlayer 1 is: " << creature1->getName() << endl;
        cout << "Player 2 is: " << creature2->getName() << endl;
        cout << endl;

        bool p1Dead = false;
        bool p2Dead = false;

        while (p1Dead == false && p2Dead == false){
            cout << "Player 1 attack:" << endl;
            damage = creature1->attack(); // creature1 attack
            cout << "\nPlayer 2 defense:" << endl;
            creature2->defense(damage);  // creature2 defend

            p2Dead = creature2->isDead(); // check to see if creature2 died

            if (p2Dead == false){
                cout << "\nPlayer 2 attack:" << endl;
                damage = creature2->attack(); // creature2 attack
                cout << "\nPlayer 1 defense:" << endl;
                creature1->defense(damage); // creature1 defend
                cout << endl;
            }
            p1Dead = creature1->isDead(); // check to see if creature1 died
        }
        // Game over, display winner/loser
        if (p1Dead == true){
            cout << "\n*** Battle over - Player 2 Wins with " << creature2->getName() << "!!! ***" << endl;
        }else if(p2Dead == true){
            cout << "\n*** Battle over - Player 1 Wins with " << creature1->getName() << "!!! ***" << endl;

        // deallocate memory
        delete creature1;
        delete creature2;
        }

    }else if (t == 9){
        creature1 = new Barbarian;
        creature2 = new HarryPotter;

        // initialize the data members for the creatures
        creature1->setData();
        creature2->setData();

        cout << "\nPlayer 1 is: " << creature1->getName() << endl;
        cout << "Player 2 is: " << creature2->getName() << endl;
        cout << endl;

        bool p1Dead = false;
        bool p2Dead = false;

        while (p1Dead == false && p2Dead == false){
            cout << "Player 1 attack:" << endl;
            damage = creature1->attack(); // creature1 attack
            cout << "\nPlayer 2 defense:" << endl;
            creature2->defense(damage);  // creature2 defend

            p2Dead = creature2->isDead(); // check to see if creature2 died

            if (p2Dead == false){
                cout << "\nPlayer 2 attack:" << endl;
                damage = creature2->attack(); // creature2 attack
                cout << "\nPlayer 1 defense:" << endl;
                creature1->defense(damage); // creature1 defend
                cout << endl;
            }
            p1Dead = creature1->isDead(); // check to see if creature1 died
        }
        // Game over, display winner/loser
        if (p1Dead == true){
            cout << "\n*** Battle over - Player 2 Wins with " << creature2->getName() << "!!! ***" << endl;
        }else if(p2Dead == true){
            cout << "\n*** Battle over - Player 1 Wins with " << creature1->getName() << "!!! ***" << endl;

        // deallocate memory
        delete creature1;
        delete creature2;
        }

    }else if (t == 10){
        creature1 = new BlueMen;
        creature2 = new BlueMen;

        // initialize the data members for the creatures
        creature1->setData();
        creature2->setData();

        cout << "\nPlayer 1 is: " << creature1->getName() << endl;
        cout << "Player 2 is: " << creature2->getName() << endl;
        cout << endl;

        bool p1Dead = false;
        bool p2Dead = false;

        while (p1Dead == false && p2Dead == false){
            cout << "Player 1 attack:" << endl;
            damage = creature1->attack(); // creature1 attack
            cout << "\nPlayer 2 defense:" << endl;
            creature2->defense(damage);  // creature2 defend

            p2Dead = creature2->isDead(); // check to see if creature2 died

            if (p2Dead == false){
                cout << "\nPlayer 2 attack:" << endl;
                damage = creature2->attack(); // creature2 attack
                cout << "\nPlayer 1 defense:" << endl;
                creature1->defense(damage); // creature1 defend
                cout << endl;
            }
            p1Dead = creature1->isDead(); // check to see if creature1 died
        }
        // Game over, display winner/loser
        if (p1Dead == true){
            cout << "\n*** Battle over - Player 2 Wins with " << creature2->getName() << "!!! ***" << endl;
        }else if(p2Dead == true){
            cout << "\n*** Battle over - Player 1 Wins with " << creature1->getName() << "!!! ***" << endl;

        // deallocate memory
        delete creature1;
        delete creature2;
        }

    }else if (t == 11){
        creature1 = new BlueMen;
        creature2 = new Medusa;

        // initialize the data members for the creatures
        creature1->setData();
        creature2->setData();

        cout << "\nPlayer 1 is: " << creature1->getName() << endl;
        cout << "Player 2 is: " << creature2->getName() << endl;
        cout << endl;

        bool p1Dead = false;
        bool p2Dead = false;

        while (p1Dead == false && p2Dead == false){
            cout << "Player 1 attack:" << endl;
            damage = creature1->attack(); // creature1 attack
            cout << "\nPlayer 2 defense:" << endl;
            creature2->defense(damage);  // creature2 defend

            p2Dead = creature2->isDead(); // check to see if creature2 died

            if (p2Dead == false){
                cout << "\nPlayer 2 attack:" << endl;
                damage = creature2->attack(); // creature2 attack
                cout << "\nPlayer 1 defense:" << endl;
                creature1->defense(damage); // creature1 defend
                cout << endl;
            }
            p1Dead = creature1->isDead(); // check to see if creature1 died
        }
        // Game over, display winner/loser
        if (p1Dead == true){
            cout << "\n*** Battle over - Player 2 Wins with " << creature2->getName() << "!!! ***" << endl;
        }else if(p2Dead == true){
            cout << "\n*** Battle over - Player 1 Wins with " << creature1->getName() << "!!! ***" << endl;

        // deallocate memory
        delete creature1;
        delete creature2;
        }

    }else if (t == 12){
        creature1 = new BlueMen;
        creature2 = new HarryPotter;

        // initialize the data members for the creatures
        creature1->setData();
        creature2->setData();

        cout << "\nPlayer 1 is: " << creature1->getName() << endl;
        cout << "Player 2 is: " << creature2->getName() << endl;
        cout << endl;

        bool p1Dead = false;
        bool p2Dead = false;

        while (p1Dead == false && p2Dead == false){
            cout << "Player 1 attack:" << endl;
            damage = creature1->attack(); // creature1 attack
            cout << "\nPlayer 2 defense:" << endl;
            creature2->defense(damage);  // creature2 defend

            p2Dead = creature2->isDead(); // check to see if creature2 died

            if (p2Dead == false){
                cout << "\nPlayer 2 attack:" << endl;
                damage = creature2->attack(); // creature2 attack
                cout << "\nPlayer 1 defense:" << endl;
                creature1->defense(damage); // creature1 defend
                cout << endl;
            }
            p1Dead = creature1->isDead(); // check to see if creature1 died
        }
        // Game over, display winner/loser
        if (p1Dead == true){
            cout << "\n*** Battle over - Player 2 Wins with " << creature2->getName() << "!!! ***" << endl;
        }else if(p2Dead == true){
            cout << "\n*** Battle over - Player 1 Wins with " << creature1->getName() << "!!! ***" << endl;

        // deallocate memory
        delete creature1;
        delete creature2;
        }

    }else if (t == 13){
        creature1 = new Medusa;
        creature2 = new Medusa;

        // initialize the data members for the creatures
        creature1->setData();
        creature2->setData();

        cout << "\nPlayer 1 is: " << creature1->getName() << endl;
        cout << "Player 2 is: " << creature2->getName() << endl;
        cout << endl;

        bool p1Dead = false;
        bool p2Dead = false;

        while (p1Dead == false && p2Dead == false){
            cout << "Player 1 attack:" << endl;
            damage = creature1->attack(); // creature1 attack
            cout << "\nPlayer 2 defense:" << endl;
            creature2->defense(damage);  // creature2 defend

            p2Dead = creature2->isDead(); // check to see if creature2 died

            if (p2Dead == false){
                cout << "\nPlayer 2 attack:" << endl;
                damage = creature2->attack(); // creature2 attack
                cout << "\nPlayer 1 defense:" << endl;
                creature1->defense(damage); // creature1 defend
                cout << endl;
            }
            p1Dead = creature1->isDead(); // check to see if creature1 died
        }
        // Game over, display winner/loser
        if (p1Dead == true){
            cout << "\n*** Battle over - Player 2 Wins with " << creature2->getName() << "!!! ***" << endl;
        }else if(p2Dead == true){
            cout << "\n*** Battle over - Player 1 Wins with " << creature1->getName() << "!!! ***" << endl;

        // deallocate memory
        delete creature1;
        delete creature2;
        }

    }else if (t == 14){
        creature1 = new Medusa;
        creature2 = new HarryPotter;

        // initialize the data members for the creatures
        creature1->setData();
        creature2->setData();

        cout << "\nPlayer 1 is: " << creature1->getName() << endl;
        cout << "Player 2 is: " << creature2->getName() << endl;
        cout << endl;

        bool p1Dead = false;
        bool p2Dead = false;

        while (p1Dead == false && p2Dead == false){
            cout << "Player 1 attack:" << endl;
            damage = creature1->attack(); // creature1 attack
            cout << "\nPlayer 2 defense:" << endl;
            creature2->defense(damage);  // creature2 defend

            p2Dead = creature2->isDead(); // check to see if creature2 died

            if (p2Dead == false){
                cout << "\nPlayer 2 attack:" << endl;
                damage = creature2->attack(); // creature2 attack
                cout << "\nPlayer 1 defense:" << endl;
                creature1->defense(damage); // creature1 defend
                cout << endl;
            }
            p1Dead = creature1->isDead(); // check to see if creature1 died
        }
        // Game over, display winner/loser
        if (p1Dead == true){
            cout << "\n*** Battle over - Player 2 Wins with " << creature2->getName() << "!!! ***" << endl;
        }else if(p2Dead == true){
            cout << "\n*** Battle over - Player 1 Wins with " << creature1->getName() << "!!! ***" << endl;

        // deallocate memory
        delete creature1;
        delete creature2;
        }

    }else if (t == 15){
        creature1 = new HarryPotter;
        creature2 = new HarryPotter;

        // initialize the data members for the creatures
        creature1->setData();
        creature2->setData();

        cout << "\nPlayer 1 is: " << creature1->getName() << endl;
        cout << "Player 2 is: " << creature2->getName() << endl;
        cout << endl;

        bool p1Dead = false;
        bool p2Dead = false;

        while (p1Dead == false && p2Dead == false){
            cout << "Player 1 attack:" << endl;
            damage = creature1->attack(); // creature1 attack
            cout << "\nPlayer 2 defense:" << endl;
            creature2->defense(damage);  // creature2 defend

            p2Dead = creature2->isDead(); // check to see if creature2 died

            if (p2Dead == false){
                cout << "\nPlayer 2 attack:" << endl;
                damage = creature2->attack(); // creature2 attack
                cout << "\nPlayer 1 defense:" << endl;
                creature1->defense(damage); // creature1 defend
                cout << endl;
            }
            p1Dead = creature1->isDead(); // check to see if creature1 died
        }
        // Game over, display winner/loser
        if (p1Dead == true){
            cout << "\n*** Battle over - Player 2 Wins with " << creature2->getName() << "!!! ***" << endl;
        }else if(p2Dead == true){
            cout << "\n*** Battle over - Player 1 Wins with " << creature1->getName() << "!!! ***" << endl;

        // deallocate memory
        delete creature1;
        delete creature2;
        }

    }else{
        // do nothing
    }
}
