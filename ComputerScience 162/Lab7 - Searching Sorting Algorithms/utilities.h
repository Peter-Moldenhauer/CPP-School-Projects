/******************************************************************************
 ** Program Filename: utilities.h
 ** Author: Peter Moldenhauer
 ** Date: 11/8/16
 ** Description: This is a header file that includes the declarations
 ** for utility functions which provide I/O validation.
 ** Input:
 ** Output:
 *******************************************************************************/

#include <fstream>
#include <string>
#include <iostream>
using namespace std;

void showMenu();
int getChoice();

double get_valid_double();
double get_valid_double_in_range(const double low, const double high);
int get_valid_int();
int get_valid_int_in_range(const int low, const int high);

ifstream& open_in_file(ifstream& fs, string fn);
ofstream& open_out_file(ofstream& fs, string fn);
