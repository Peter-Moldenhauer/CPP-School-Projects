Name: Peter Moldenhauer
Email: moldenhp@oregonstate.edu
Class: CS 162
Assignment: Lab 7
Date: 11/8/16 

This is the Readme file for Lab 7 that I built. Lab 7 contains the files: makefile, utilities.cpp and utilities.h.
This lab also runs off of the txt files misssing0.txt, early.txt, middle.txt, late.txt and sorted.txt.  
To run the program, in the command line enter the directory that all of the files are in (all files must be in the same directory).
Type "make" into the command line and this will run the makefile which in turn will build and link the Lab7 program.
A new file "Lab7" should now be present in the directory. This is the executable file needed to run the program. 
Run the Lab7 file and the program will begin.

How the program works:
When the program starts, a main menu will be displayed to the user. The user can select 1 of 4 options:
1) Linear Search
2) Bubble Sort 
3) Binary Search
4) Exit program 

The user then inputs either a 1, 2, 3 or 4 and hits ENTER to make the selection.

If option 1 is selected from main menu:
User is prompted to enter an input file name to search from.
Possible files can include: missing0.txt, early.txt, middle.txt and late.txt.
A linear search algorithm will then be conducted on the list of numbers in the text file.
The index of the numbers in the text file will be displayed if the target value (0) is found. 

If option 2 is selected from main menu:
User is prompted to enter an input file name to sort from.
Possible files can include: missing0.txt, early.txt, middle.txt and late.txt.
The user is then promted to enter a file name to write the sorted values to.
A bubble sort algorithm will then sort the values from the input file into ascending order and write to output file.
The input file contents and the output sorted contents are then displayed.

If option 3 is selected from main menu:
User is prompted to enter an input file name to search from.
Note: the input file must already be in order. Use either the sort.txt file or the file created from main menu option 2 (bubble sort).
User is then prompted for the target value in wich to find in the file.
A binary search algorithm will then be conducted on the list of numbers in the test file to locate the target value. 
The index of the numbers in the text file will be displayed if the target value is found. 

If option 4 is selected from main menu:
Program exits 