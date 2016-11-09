/************************************************************************************************************
** Program Filename: main.cpp
** Author: Peter Moldenhauer
** Date: 11/8/16
** Assignment: Lab 7
** Description: This program demonstrates linear search, bubble sort and binary search.
** Input: Text files to read from
** Output: Text files of sorted values.
**************************************************************************************************************/

#include "utilities.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

void linearSearch(int val, string in_file); // linear search algorithm based off of the book example on page 596
void bubbleSort(string in_file, string out_file); // bubble sort algorithm based off book example on page 607
void binarySearch(int val, string in_file); // binary search algorithm based off the book example on page 599

int main()
{
    int choice;

    cout << "CS162 Lab 7 - Linear search, binary search and bubble sort" << endl;
    cout << "By: Peter Moldenhauer" << endl;

    do {
        showMenu();
        choice = getChoice();
        cin.ignore();

        switch (choice){
            case 1:  // user wants linear search
                {
                    cout << "\n-- Linear Search --" << endl;
                    cout << "Enter the name of the input file to be used..." << endl;
                    cout << "(Example: early.txt, middle.txt, late.txt or missing0.txt)" << endl;
                    cout << "The linear search will search the file for the target value of 0." << endl;
                    cout << "Enter file name here: ";
                    string filename;
                    getline(cin, filename);

                    // search through file for 0 and print result
                    linearSearch(0, filename);
                }
                break;
            case 2: // user wants bubble sort
                {
                    cout << "\n-- Bubble Sort --" << endl;
                    cout << "Enter the name of the input file to be used..." << endl;
                    cout << "(Example: early.txt, middle.txt, late.txt or missing0.txt)" << endl;
                    cout << "The bubble sort will sort the file into ascending order." << endl;
                    cout << "Enter file name here: ";
                    string in_file;
                    getline(cin, in_file);

                    cout << "Enter the name of the output file to be written to..." << endl;
                    cout << "(Example: output.txt)" << endl;
                    cout << "Enter file name here: ";
                    string out_file;
                    getline(cin, out_file);

                    // sort input file and write results to the specified output file
                    bubbleSort(in_file, out_file);
                }
                break;
            case 3:  // user wants binary search
                {
                    cout << "\n-- Binary Search --" << endl;
                    cout << "Enter the name of the input file to be used..." << endl;
                    cout << "NOTE: input file must already be sorted." << endl;
                    cout << "(Example: sorted.txt or output.txt)" << endl;
                    cout << "Enter file name here: ";
                    string filename;
                    getline(cin, filename);

                    cout << "What is the target value that you would like to search for: ";
                    int val = get_valid_int();

                    // search through sorted file and print results
                    binarySearch(val, filename);
                }
                break;
        }

    } while (choice != 4); // if user enters 4 then program exits

    cout << "\nExiting Lab 7 program. Goodbye!!!\n" << endl;

    return 0;
}


/*********************************************************************
 ** Function: linearSearch()
 ** Description: Searches a file of whitespace-separated integers for
 ** the given value (0) and prints which indices, if any contain the
 ** value.
 ** Parameters: val - the integer value to search on, in_file - the
 ** name of the file to search.
 ** Pre-Conditions: in_file contains only whitespace-separated
 ** integers
 ** Post-Conditions: all indices containing val are printed, the file
 ** is closed
 *********************************************************************/
 void linearSearch(int val, string in_file){

    cout << "Linear Search for " << val << " in \'" << in_file << "\'...\n";

    // open file handle
    ifstream in;
    open_in_file(in, in_file);

    // list of values
    vector<int> list;

    // read all values to vector
    int cur;
    while (in >> cur)
        list.push_back(cur);

    // print vector contents
    cout << "File contents: ";
    int num_vals = list.size();
    for (int i = 0; i < num_vals; ++i)
        cout << list[i] << ' ';
    cout << endl;

    // algorithm based off of the book example on page 596
    bool found = false;
    for (int i = 0; i < num_vals; ++i)
        if (list[i] == val)
        {
            cout << "Found " << val << " at index " << i << '\n';
            found = true;
        }

    if (found == false)
        cout << "Did not find " << val << " in the file.\n";

    // close the file handle
    in.close();
}

/*********************************************************************
 ** Function: bubbleSort()
 ** Description: Sorts a list of whitespace-separated integers from
 ** an input file and outputs the resulting list to an output file.
 ** Parameters: in_file - the name of the input file, out_file - the
 ** name of the output file
 ** Pre-Conditions: in_file contains a list of whitespace-separated
 ** integers
 ** Post-Conditions: out_file contains a list of whitespace-separated
 ** integers sorted in ascending order
 *********************************************************************/
 void bubbleSort(string in_file, string out_file){

    cout << "Bubble sort \'" << in_file << "\'...\n";

    // open file handle
    ifstream in;
    open_in_file(in, in_file);

    // list of values
    vector<int> list;

    // store file contents to vector
    int cur;
    while (in >> cur)
        list.push_back(cur);

    // close input file
    in.close();

    // verify vector
    cout << "Input file contents: ";
    int num_vals = list.size();
    for (int i = 0; i < num_vals; ++i)
        cout << list[i] << ' ';
    cout << endl;

    // algorithm based off book example on page 607
    bool swapped = true;
    int temp;
    while (swapped)
    {
        swapped = false;
        for (int i = 0; i < num_vals - 1; ++i)
            if (list[i] > list[i + 1])
            {
                temp = list[i];
                list[i] = list[i + 1];
                list[i + 1] = temp;
                swapped = true;
            }
    }

    // open output file handle
    ofstream out;
    open_out_file(out, out_file);

    // verify vector and write out
    cout << "Output file sorted contents: ";
    for (int i = 0; i < num_vals; ++i){
        cout << list[i] << ' ';
        out << list[i] << ' ';
    }
    cout << endl;

    // close the output file
    out.close();
}

/*********************************************************************
 ** Function: binarySearch()
 ** Description: Searches a sorted file of whitespace-separated
 ** integers for the given value and prints an index, if any,
 ** containing the value.
 ** Parameters: val - the integer value to search on, in_file - the
 ** name of the file to search
 ** Pre-Conditions: in_file contains only whitespace-separated
 ** integers sorted in ascending order
 ** Post-Conditions: an index containing val is printed, if one exists,
 ** and the file is closed
 *********************************************************************/
 void binarySearch(int val, string in_file){

    cout << "Binary Search for " << val << " in \'" << in_file << "\'...\n";

    // open file handle
    ifstream in;
    open_in_file(in, in_file);

    // list of values
    vector<int> list;

    // read all values to vector
    int cur;
    while (in >> cur)
        list.push_back(cur);

    // print vector contents
    cout << "File contents: ";
    int num_vals = list.size();
    for (int i = 0; i < num_vals; ++i)
        cout << list[i] << ' ';
    cout << endl;

    // algorithm based off the book example on page 599
    int begin = 0;          // first index of current search section
    int end = num_vals;     // last index of current search section
    int middle = 0;         // middle of current search section
    bool found = false;     // found matching int?
    int pos = -1;           // index of found int

    // until a value is found or end < begin
    while (!found && begin <= end)
    {
        middle = (begin + end) / 2;
        if (list[middle] == val)
        {
            // we're done
            found = true;
            pos = middle;
        }
        else if (list[middle] > val)
            end = middle - 1;
        else
            begin = middle + 1;
    }

    // print the result
    if (pos == -1)
        cout << "Did not find " << val << " in the file.\n";
    else
        cout << "Found " << val << " at index " << pos << '\n';

    // close the file handle
    in.close();
}
