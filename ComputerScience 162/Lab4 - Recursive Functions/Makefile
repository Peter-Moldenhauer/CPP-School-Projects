####################################################
#Name: Peter Moldenhauer
#Date: 10/20/16
#Description: This is a makefile that builds the 
#executable file "Lab4" from the files main.cpp
#functions.h and functions.cpp  
#####################################################


# CXX is a standard variable name used for the g++ compiler.
CXX = g++


# CXXFLAGS is a standard variable name for compile flags.
# -std=c++0x specifies to use a certain language version.
CXXFLAGS = -std=c++0x


# -Wall turns on all warnings
CXXFLAGS += -Wall


# -pedantic-errors strictly enforces the standard
CXXFLAGS += -pedantic-errors


# -g turns on debug information
CXXFLAGS += -g 


##### USER SECTION ######


# SRCS is a standard name for the source files
SRC1 = main.cpp
SRC2 = functions.cpp
SRCS = ${SRC1} ${SRC2} 


# HEADERS is a standard name for the header files.
HEADER1 = functions.h 
HEADERS = ${HEADER1} 


# This will be the executable name
PROG1 = Lab4 
PROGS = ${PROG1}
 

##### BUILD SECTION ######


# Typing "make" in terminal calls the first build available 
# Typing "make all" in terminal calls this build
all:
	${CXX} ${CXXFLAGS} ${SRCS} -o ${PROG1}
 

# Typing "make clean" calls this build
# This is designed to clean up the folder
clean:
	rm -f ${PROGS} *.o *~ 
