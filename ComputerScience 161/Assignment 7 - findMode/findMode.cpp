/**************************************************************************************
** Name: Peter Moldenhauer
** Date: 5/8/16
** Description: Assignment 7 - This program uses a function that takes as parameters
**an array of ints and the size of the array and then returns a vector containing the
**mode or modes.
**Note: Per assignment instructions, the main function is commented out.
***************************************************************************************/

#include <iostream>
#include <vector>   //need for vector type
#include <algorithm>  //need for sort() function
using namespace std;

vector<int> findMode(int nums[], int size)  //declare a function that returns a vector of ints
{
	int maxFreq = 1;  //store highest found frequency
	vector<int> modes;  //store all modes

	for (int i = 0; i < size; i++)  //loop through all the integers
    {

		int curFreq = 1;  //accumulator for occurrences of value at index i, starting from index i + 1
		//starting at the index after i, loop through the integers in the list
		//seek any matches with the value at index i
		//Starting after index i will prevent duplicate values from being pushed to modes

		for (int j = i + 1; j < size; j++)
        {

			if (nums[i] == nums[j])
            {  //if a match is found, increment the accumulator
				curFreq++;
			}
		}
		//if the accumulator for index i matches the maximum frequency seen thus far,
		//push the value stored at index i to modes
		if (curFreq == maxFreq)
        {
			modes.push_back(nums[i]);
		}

		//if the accumulator for index i is greater than the maximum frequency seen,
		//update maxFreq, clear all values stored in modes (since there are other values
		//that occur more frequently), and push the value stored at index i to modes
		if (curFreq > maxFreq)
        {
			maxFreq = curFreq;
			modes.clear();
			modes.push_back(nums[i]);
		}

	}

	//sort all the modes
	sort(modes.begin(), modes.end());

	return modes;

}
//Main function commented out, just used for testing program, not to be included in final assignment submission
/************************************************************
int main(){

	const int SIZE = 10;
	int myArray[SIZE] = {1, 4, 4, 4, 3, 2, 2, 5, 2, 6};

	cout << "The mode(s) in the array is(are): " << endl;
	vector<int> mode = findMode(myArray, SIZE);
	for (int i = 0; i < mode.size(); i++){
		cout << mode[i] << " ";
		cout << endl;
	}

	return 0;

}

****************************************************************/

