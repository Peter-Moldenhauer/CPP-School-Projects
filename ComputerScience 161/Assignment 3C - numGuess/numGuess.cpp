/***********************************************************
** Name: Peter Moldenhauer
** Date: 4/10/16
** Description: Project 3c This program prompts the user for
**an integer that another player will try to guess. This
**program uses a loop that repeats until the user correctly
**guesses the number.
************************************************************/


#include <iostream>
using namespace std;

int main(){

	int numb, guess, tries=0;
	bool LoopCount = 1;

	cout<<"Enter an integer for the player to guess. "<<endl;
	cin>>numb;
	cout<<"Enter your guess. "<<endl;

	while(LoopCount){     //Keep looping while LoopCount is true

		cin>>guess;

		if(guess==numb){
			tries++;        //Add 1 to the count for total of tries
			LoopCount=0;    //Exit loop by turning LoopCount to false
		}
		if(guess>numb){
			tries++;        //Maintain count of total tries
			cout<<"Too high - try again! "<<endl;
		}
		if(guess<numb){
			tries++;        //Maintain count of total tries
			cout<<"Too low - try again! "<<endl;
		}
	}

	cout<<"You guessed it in "<<tries<<" tries."<<endl;

	return 0;
}
