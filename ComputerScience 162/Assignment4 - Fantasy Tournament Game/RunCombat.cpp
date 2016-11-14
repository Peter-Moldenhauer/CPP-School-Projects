/************************************************************************************************************
** Program Filename: RunCombat.cpp
** Author: Peter Moldenhauer
** Date: 11/10/16
** Assignment: Assignment 4
** Description: This is the RunCombat class .cpp file. The RunCombat class runs a tournament consisting of
** matchups between two teams of Creatures lined up in Queues. It can also determine the winning team and other
** info about the tournament when a tournament ends.
** Input: Creature pointers in Queue
** Output: Runs tournament and prints out tournament info
**************************************************************************************************************/

#include "RunCombat.h"


/*********************************************************************
** Function: RunCombat()
** Description: Constructs a RunCombat from two pointers to
** Queue objects, each containing a number of Creature pointers.
** Parameters: s1 - player 1's team, s2 - player 2's team, t1 - player
** 1's team name, t2 - player 2's team name
** Pre-Conditions: s1 and s2 contain no NULL pointers
** Post-Conditions: all instance fields initialized, including the
** Stack on the heap
** Return: none
*********************************************************************/
RunCombat::RunCombat(Queue* s1, Queue* s2, string t1, string t2){
    srand(time(0)); // seed random num generator

    team1Name = t1;
    team2Name = t2;

    side1 = s1;
    side2 = s2;

    losers = new Stack;

    numRounds = 0;

    side1pts = 0;
    side2pts = 0;
}


/*********************************************************************
** Function: RunCombat::~RunCombat()
** Description: Destructs this RunCombat and frees all heap memory.
** Parameters: none
** Pre-Conditions: the Stack has not been deallocated yet
** Post-Conditions: the Stack has been deallocated
** Return: none
*********************************************************************/
RunCombat::~RunCombat(){
    delete losers;
}


/************************************************************************
** Function: playMatch()
** Description: Runs the tournament between each teams creature lineup
** Parameters: none
** Pre-Conditions: RunCombat object needs to already be made
** Post-Conditions: Runs the tournament between each teams lineup
** Return: none
*************************************************************************/
void RunCombat::playMatch(){
    bool keepLooping = true;

    while (keepLooping == true){
        // pop out each teams first creature to fight from the Queue
        Creature *creature1 = side1->remove();
        Creature *creature2 = side2->remove();

        // if either creature = NULL then that means than one of the Queue's is empty - don't battle then!
        if (creature1 == NULL || creature2 == NULL)
            keepLooping = false;

        if (keepLooping == true){
            numRounds++;
            bool p1Dead = false;
            bool p2Dead = false;
            int damage = 0;

            // display info on each round to the user
            cout << "\n\t\t  -- Round " << numRounds << " --" << endl;
            cout << creature1->getName() << " (" << creature1->getTeamName() << ") VS. " << creature2->getName() << " (" << creature2->getTeamName() << ")" << endl;
            cout << creature1->getName() << " (" << creature1->getTeamName() << ") starting armor: " << creature1->getArmor() << ", starting strength: " << creature1->getStrength() << endl;
            cout << creature2->getName() << " (" << creature2->getTeamName() << ") starting armor: " << creature2->getArmor() << ", starting strength: " << creature2->getStrength() << endl;

            while (p1Dead == false && p2Dead == false){
                //cout << "Player 1 attack:" << endl;
                damage = creature1->attack(); // creature1 attack
                //cout << "\nPlayer 2 defense:" << endl;
                creature2->defense(damage);  // creature2 defend

                p2Dead = creature2->isDead(); // check to see if creature2 died

                if (p2Dead == false){
                    //cout << "\nPlayer 2 attack:" << endl;
                    damage = creature2->attack(); // creature2 attack
                    //cout << "\nPlayer 1 defense:" << endl;
                    creature1->defense(damage); // creature1 defend
                    //cout << endl;
                }
                p1Dead = creature1->isDead(); // check to see if creature1 died
            }

            // Round over, display winner/loser
            if (p1Dead == true){
                side2pts++;
                cout << "*** " << team2Name << " wins with " << creature2->getName() << " ***" << endl;
                cout << team1Name << " points: " << side1pts << endl;
                cout << team2Name << " points: " << side2pts << endl;
                //cout << "\n*** Round over - Player 2 Wins round " << numRounds << " with " << creature2->getName() << "!!! ***" << endl;
                creature2->revive(); // revive creature2 before adding back in Queue
                side2->add(creature2);  //add creature2 back in QUEUE
                losers->add(creature1); // put creature1 in loser STACK
            }else if(p2Dead == true){
                side1pts++;
                cout << "*** " << team1Name << " wins with " << creature1->getName() << " ***" << endl;
                cout << team1Name << " points: " << side1pts << endl;
                cout << team2Name << " points: " << side2pts << endl;
                //cout << "\n*** Round over - Player 1 Wins round " << numRounds << " with " << creature1->getName() << "!!! ***" << endl;
                creature1->revive(); // revive creature1 before adding back in Queue
                side1->add(creature1);  // add creature1 back in QUEUE
                losers->add(creature2); // put creature2 in loser STACK
            }
        }
    }
    cout << "--------------------------------------------------------" << endl;
}

/************************************************************************
** Function: finalScore()
** Description: Displays the final results of the tournament
** Parameters: none
** Pre-Conditions: RunCombat object needs to already be made and the
** tournament already ran.
** Post-Conditions: Displays the final results of the tournament
** Return: none
*************************************************************************/
void RunCombat::finalScore(){

    if (side1pts > side2pts){
        cout << "\nEnd of tournament - " << team1Name << " wins!!!" << endl;
        cout << team1Name << " final score: " << side1pts << endl;
        cout << team2Name << " final score: " << side2pts << endl;
    }else if (side2pts > side1pts){
        cout << "\nEnd of tournament - " << team2Name << " wins!!!" << endl;
        cout << team1Name << " final score: " << side1pts << endl;
        cout << team2Name << " final score: " << side2pts << endl;
    }else if (side1pts == side2pts){
        cout << "\nEnd of tournament - TIE GAME!!!" << endl;
        cout << team1Name << " final score: " << side1pts << endl;
        cout << team2Name << " final score: " << side2pts << endl;

        //Flip a coin to determine the winner if its a tie game
        cout << "\nFlipping a coin to determine the winner due to tie game..." << endl;
        cout << team1Name << ", enter heads or tails to call the coin flip." << endl;
        cout << "1) Heads" << endl;
        cout << "2) Tails" << endl;

        bool getData = true;
        int userInput;

        while (getData == true){
            cout << "Enter 1 for heads and 2 for tails here: ";
            cin >> userInput;
            if (userInput > 0 && userInput <= 2){
                getData = false;
            }else{
                cout << "Please enter either 1 or 2 to make your selection!" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }
        }
        int flip = rand() % 2 + 1; // generate a random number to simulate a coin flip
        if (flip == userInput && userInput == 1)
            cout << "Coin flip was heads - " << team1Name << " wins the tournament!!!" << endl;
        else if (flip == userInput && userInput == 2)
            cout << "Coin flip was tails - " << team1Name << " wins the tournament!!!" << endl;
        else if (flip != userInput && userInput == 1)
            cout << "Coin flip was tails - " << team2Name << " wins the tournament!!!" << endl;
        else if (flip != userInput && userInput == 2)
            cout << "Coin flip was heads - " << team2Name << " wins the tournament!!!" << endl;
    }
}

/************************************************************************
** Function: printLosers()
** Description: Gives user the option to display the losing creatures of
** each round in the tournament
** Parameters: none
** Pre-Conditions: Stack needs to be filled with the losing creatures of
** the tournament
** Post-Conditions: Displays the losing creatures of each round
** Return: none
*************************************************************************/
void RunCombat::printLosers(){
    char choice;
    bool keepLooping = true;

    cout << "\nWould you like to view the contents of the loser pile? [Y/N]: ";
    cin >> choice;

    if (choice == 'Y' || choice == 'y'){
        cout << "\nList of creatures who lost, with the loser of the first round displayed last..." << endl;
        while (keepLooping == true){
            // remove creature from the Stack
            Creature *c1 = losers->remove();
            // if the stack returns NULL, then there are no creatures in the stack - do not display anything!
            if (c1 == NULL)
                keepLooping = false;
            // display the creature that was removed from the stack
            if (keepLooping == true){
                cout << c1->getName() << " (" << c1->getTeamName() << ")" << endl;
            }
        }
    }
}
