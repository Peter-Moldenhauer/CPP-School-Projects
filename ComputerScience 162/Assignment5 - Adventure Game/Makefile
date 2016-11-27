###############################################################
#Name: Peter Moldenhauer
#Date: 11/25/16
#Description: This is a makefile that builds the 
#executable file "finalAssignment" from the files main.cpp
#Character.cpp, Space.cpp, Train.cpp, BackLoungeCar.cpp,
#BackRestroom.cpp, BaggageCar.cpp, BradPitt.cpp, CoachClassCar.cpp,
#ConductorSeat.cpp, CryingBaby.cpp, DonaldTrump.cpp, EngineerSeat.cpp,
#FirstClassCar.cpp, ForwardAttendantCar.cpp, FrontGalley.cpp, 
#FrontRestroom.cpp, LocomotiveCar.cpp, LookingOutside.cpp, 
#SnackStand.cpp, SnoringSleeper.cpp
###############################################################


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
SRC2 = Character.cpp
SRC3 = Space.cpp
SRC4 = Train.cpp
SRC5 = BackLoungeCar.cpp
SRC6 = BackRestroom.cpp
SRC7 = BaggageCar.cpp
SRC8 = BradPitt.cpp
SRC9 = CoachClassCar.cpp 
SRC10 = ConductorSeat.cpp 
SRC11 = CryingBaby.cpp 
SRC12 = DonaldTrump.cpp
SRC13 = EngineerSeat.cpp
SRC14 = FirstClassCar.cpp
SRC15 = ForwardAttendantCar.cpp
SRC16 = FrontGalley.cpp
SRC17 = FrontRestroom.cpp
SRC18 = LocomotiveCar.cpp
SRC19 = LookingOutside.cpp
SRC20 = SnackStand.cpp
SRC21 = SnoringSleeper.cpp 
SRCS = ${SRC1} ${SRC2} ${SRC3} ${SRC4} ${SRC5} ${SRC6} ${SRC7} ${SRC8} ${SRC9} ${SRC10} ${SRC11} ${SRC12} ${SRC13} ${SRC14} ${SRC15} ${SRC16} ${SRC17} ${SRC18} ${SRC19} ${SRC20} ${SRC21}


# HEADERS is a standard name for the header files.
HEADER1 = Character.h
HEADER2 = Space.h 
HEADER3 = Train.h
HEADER4 = BackLoungeCar.h
HEADER5 = BackRestroom.h
HEADER6 = BaggageCar.h 
HEADER7 = BradPitt.h
HEADER8 = CoachClassCar.h 
HEADER9 = ConductorSeat.h 
HEADER10 = CryingBaby.h 
HEADER11 = DonaldTrump.h
HEADER12 = EngineerSeat.h 
HEADER13 = FirstClassCar.h
HEADER14 = ForwardAttendantCar.h
HEADER15 = FrontGalley.h
HEADER16 = FrontRestroom.h 
HEADER17 = LocomotiveCar.h
HEADER18 = LookingOutside.h 
HEADER19 = SnackStand.h 
HEADER20 = SnoringSleeper.h 
HEADERS = ${HEADER1} ${HEADER2} ${HEADER3} ${HEADER4} ${HEADER5} ${HEADER6} ${HEADER7} ${HEADER8} ${HEADER9} ${HEADER10} ${HEADER11} ${HEADER12} ${HEADER13} ${HEADER14} ${HEADER15} ${HEADER16} ${HEADER17} ${HEADER18} ${HEADER19} ${HEADER20}


# This will be the executable name
PROG1 = finalAssignment 
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
