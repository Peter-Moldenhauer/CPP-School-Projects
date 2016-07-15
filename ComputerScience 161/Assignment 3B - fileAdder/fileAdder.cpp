/***************************************************************
** Name: Peter Moldenhauer
** Date: 4/11/16
** Description: Assignment 3b: File adder. This program prompts
**the user for a name of a file and then tries to open it. The
**program then reads a list of integers in the file, which will
**have one integer per line.
****************************************************************/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){

	ifstream inputFile;
	ofstream outputFile;

	string filename;
	int intFromFile, sum = 0;

	cout<<"Please enter the name of the file that you would like to open: "<<endl;
	cin>>filename;

	inputFile.open(filename.c_str());       //Input file filename

	if(inputFile)                           //Make sure file exists or is able to open
		cout<<"File opened successfully. "<< endl;
	else
		cout<<"Could not access file. "<< endl;

	while(inputFile >> intFromFile){        //Gather all of the integers from filename

		//inputFile >> intFromFile;    I thought I needed this here but I don't

		sum += intFromFile;             //Calculate sum of integers from filename
	}

	outputFile.open("sum.txt");             //Create output file named sum.txt

	outputFile << sum;	                //Write sum of input file to output file

	inputFile.close();
	outputFile.close();

	return 0;
}
