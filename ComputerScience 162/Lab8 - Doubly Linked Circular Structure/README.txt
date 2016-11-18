Name: Peter Moldenhauer
Email: moldenhp@oregonstate.edu
Class: CS 162
Assignment: Lab 8
Date: 11/17/16 

This is the Readme file for Lab 8 that I built. Lab 8 contains the files: makefile, main.cpp, queue.cpp and queue.h.  
To run the program, in the command line enter the directory that all of the files are in (all files must be in the same directory).
Type "make" into the command line and this will run the makefile which in turn will build and link the Lab8 program.
A new file "Lab8" should now be present in the directory. This is the executable file needed to run the program. 
Run the Lab8 file and the program will begin.

How the program works:
When the program starts, a main menu will be displayed to the user. The user can select 1 of 5 options:
1) Enter a value to be added to the queue
2) Display first node (front) value
3) Remove first node (front) value
4) Display the queue contents
5) Exit 

The user then inputs either a 1, 2, 3, 4 or 5 and hits ENTER to make the selection.

If option 1 is selected from main menu:
User is prompted to enter a integer to be added to a queue.
The integer that the user enters must be in the range of 0 to 1000.

If option 2 is selected from main menu:
The first value in the queue will be printed to the screen. If there are no current values in the queue
then an error message will be printed to the screen and the value -1 will be returned

If option 3 is selected from main menu:
If there are currently value(s) in the queue then the first value will be removed from the queue. If there 
are no values in the queue, then an error message will be printed to the screen. 

If option 4 is selected from main menu:
The contents of the queue will be printed to the screen. If the queue is empty then an error message will be 
printed to the screen and the value -1 will be returned. 

If option 5 is selected from main menu:
Program exits 