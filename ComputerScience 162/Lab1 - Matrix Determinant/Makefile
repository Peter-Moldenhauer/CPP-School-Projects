####################################################
#Name: Peter Moldenhauer
#Date: 9/25/16
#Description: This is a makefile that builds the 
#executable file "Lab1" from the files main.cpp
#readMatrix.cpp, readMatrix.h, determinant.cpp and 
#determinant.h 
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
SRC2 = readMatrix.cpp
SRC3 = determinant.cpp 
SRCS = ${SRC1} ${SRC2} ${SRC3}


# HEADERS is a standard name for the header files.
HEADER1 = readMatrix.h
HEADER2 = determinant.h
HEADERS = ${HEADER1} ${HEADER2} 


# These will be the executable names
PROG1 = Lab1
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
