####################################################
#Name: Peter Moldenhauer
#Date: 10/30/16
#Description: This is a makefile that builds the 
#executable file "Assignment3" from the files main.cpp
#Functions.cpp Creature.cpp Vampire.cpp Barbarian.cpp
#BlueMen.cpp Medusa.cpp and HarryPotter.cpp  
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
SRC2 = Functions.cpp
SRC3 = Creature.cpp
SRC4 = Vampire.cpp
SRC5 = Barbarian.cpp
SRC6 = BlueMen.cpp
SRC7 = Medusa.cpp
SRC8 = HarryPotter.cpp
SRCS = ${SRC1} ${SRC2} ${SRC3} ${SRC4} ${SRC5} ${SRC6} ${SRC7} ${SRC8} 


# HEADERS is a standard name for the header files.
HEADER1 = Functions.h
HEADER2 = Creature.h 
HEADER3 = Vampire.h
HEADER4 = Barbarian.h
HEADER5 = BlueMen.h
HEADER6 = Medusa.h 
HEADER7 = HarryPotter.h
HEADERS = ${HEADER1} ${HEADER2} ${HEADER3} ${HEADER4}


# This will be the executable name
PROG1 = Assignment3 
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
