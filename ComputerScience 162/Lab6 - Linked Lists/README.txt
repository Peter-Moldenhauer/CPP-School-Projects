Name: Peter Moldenhauer
Email: moldenhp@oregonstate.edu
Class: CS 162
Assignment: Lab 6
Date: 10/31/16 

This is the Readme file for Lab 6 that I built. Lab 6 contains the files: makefile, main.cpp, Stack.h, Stack.cpp, Queue.h and Queue.cpp 
To run the program, in the command line enter the directory that all of the files are in (all files must be in the same directory).
Type "make" into the command line and this will run the makefile which in turn will build and link the Lab6 program.
A new file "Lab6" should now be present in the directory. This is the executable file needed to run the program. 
Run the Lab6 file and the program will begin.

How the program works:
When the program starts, the main menu will be displayed to the user. The user can select 1 of 3 options:
1) Access Stack
2) Access Queue 
3) Exit program 

The user then inputs either a 1, 2 or 3 and hits ENTER to make the selection.

If option 1 is selected from main menu:
The Stack operations menu is displayed. At this menu, the user can select 1 of 3 options:
1) Push operation
2) Pop operation
3) Return to main menu

	If option 1 is selected from the stack operations menu:
	The user will be prompted to enter an integer to be added to the stack
	The user then enters an integer and a confirmation message will be displayed that the integer was added to the stack 
	
	If option 2 is selected from the stack operations menu:
	The most recently added integer to the stack will be automatically removed from the stack.
	This is because the stack is a first in, last out structure
	Note: if there are no nodes in the stack and the stack is empty, an error message will be displayed informing the user of this.
	
	If option 3 is selected from the stack operations menu:
	The user will be directed back to the main menu and the main menu will be displayed.
	
If option 2 is selected from the main menu:
The Queue operations menu is displayed. At this menu, the user can select 1 of 3 options:
1) Push operation
2) Pop operation
3) Return to main menu

	If option 1 is selected from the queue operations menu: 
	[Same actions as stack push]
	
	If option 2 is selected from the queue operations menu:
	[Same actions as stack push]
	NOTE: In the queue, the first integer added to queue will be removed because queue is a first in, first out structure
	
	If option 3 is selected from the queue operations menu:
	The user will be directed back to the main menu and the main menu will be displayed.
	
If option 3 is selected from the main menu:
The program will exit 