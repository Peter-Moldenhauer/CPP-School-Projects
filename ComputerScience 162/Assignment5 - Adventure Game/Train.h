/************************************************************************************************************
** Program Filename: Train.h
** Author: Peter Moldenhauer
** Date: 11/25/16
** Assignment: Assignment 5 (Final Assignment)
** Description: This is the Train class header file for a text based adventure game. The Train class creates
** all of the spaces in the train environment that the character can move around in.
**************************************************************************************************************/

#ifndef TRAIN_H
#define TRAIN_H

#include "LookingOutside.h"
#include "LocomotiveCar.h"
#include "ConductorSeat.h"
#include "EngineerSeat.h"
#include "ForwardAttendantCar.h"
#include "FrontGalley.h"
#include "FrontRestroom.h"
#include "FirstClassCar.h"
#include "BradPitt.h"
#include "DonaldTrump.h"
#include "CoachClassCar.h"
#include "CryingBaby.h"
#include "SnoringSleeper.h"
#include "BackLoungeCar.h"
#include "BackRestroom.h"
#include "SnackStand.h"
#include "BaggageCar.h"
#include "Character.h"

class Train
{
    private:
        Character *character;
    public:
        Character* getCharacter();
        Train();
};

#endif // TRAIN_H
