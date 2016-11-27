/************************************************************************************************************
** Program Filename: Train.cpp
** Author: Peter Moldenhauer
** Date: 11/25/16
** Assignment: Assignment 5 (Final Assignment)
** Description: This is the Train class .cpp file for a text based adventure game. The Train class creates
** all of the spaces in the train environment that the character can move around in.
**************************************************************************************************************/

#include "Train.h"

/*********************************************************************
** Function: Train()
** Description: This is the Train class constructor. The constructor
** sets up all of the space objects, character and the starting point.
*********************************************************************/
Train::Train() {

    // First instantiate all Space objects
    LookingOutside *lookingOutside = new LookingOutside();
    LocomotiveCar *locomotiveCar = new LocomotiveCar();
    ConductorSeat *conductorSeat = new ConductorSeat();
    EngineerSeat *engineerSeat = new EngineerSeat();
    ForwardAttendantCar *forwardAttendantCar = new ForwardAttendantCar();
    FrontGalley *frontGalley = new FrontGalley();
    FrontRestroom *frontRestroom = new FrontRestroom();
    FirstClassCar *firstClassCar = new FirstClassCar();
    BradPitt *bradPitt = new BradPitt();
    DonaldTrump *donaldTrump = new DonaldTrump();
    CryingBaby *cryingBaby = new CryingBaby();
    CoachClassCar *coachClassCar = new CoachClassCar(cryingBaby);
    SnoringSleeper *snoringSleeper = new SnoringSleeper();
    BackLoungeCar *backLoungeCar = new BackLoungeCar();
    BackRestroom *backRestroom = new BackRestroom();
    SnackStand *snackStand = new SnackStand();
    BaggageCar *baggageCar = new BaggageCar();

    // Instantiate Character and starting point
    this->character = new Character();
    this->character->setCurrentSpace(backRestroom);

    // Then set up Space pointers
    lookingOutside->setLocation(NULL, locomotiveCar, NULL, NULL, character, "looking out the windshield");
    locomotiveCar->setLocation(lookingOutside, forwardAttendantCar, conductorSeat, engineerSeat, character, "in the locomotive cab");
    conductorSeat->setLocation(NULL, NULL, NULL, locomotiveCar, character, "sitting with the conductor");
    engineerSeat->setLocation(NULL, NULL, locomotiveCar, NULL, character, "sitting with the engineer");
    forwardAttendantCar->setLocation(locomotiveCar, firstClassCar, frontRestroom, frontGalley, character, "in the front attendant car");
    frontRestroom->setLocation(NULL, NULL, NULL, forwardAttendantCar, character, "in the front restroom");
    frontGalley->setLocation(NULL, NULL, forwardAttendantCar, NULL, character, "in the front galley");
    firstClassCar->setLocation(forwardAttendantCar, coachClassCar, donaldTrump, bradPitt, character, "in the first class car");
    donaldTrump->setLocation(NULL, NULL, NULL, firstClassCar, character, "sitting next to Donald Trump");
    bradPitt->setLocation(NULL, NULL, firstClassCar, NULL, character, "sitting next to Brad Pitt");
    coachClassCar->setLocation(firstClassCar, backLoungeCar, cryingBaby, snoringSleeper, character, "in the coach class car");
    cryingBaby->setLocation(NULL, NULL, NULL, coachClassCar, character, "sitting next to a crying baby");
    snoringSleeper->setLocation(NULL, NULL, coachClassCar, NULL, character, "sitting next to a snoring sleeper");
    backLoungeCar->setLocation(coachClassCar, baggageCar, backRestroom, snackStand, character, "in the back lounge car");
    backRestroom->setLocation(NULL, NULL, NULL, backLoungeCar, character, "in the back restroom");
    snackStand->setLocation(NULL, NULL, backLoungeCar, NULL, character, "at the rear snack stand");
    baggageCar->setLocation(backLoungeCar, NULL, NULL, NULL, character, "in the baggage car");
}

/*********************************************************************
** Function: getCharacter()
** Description: This function returns this specific train class's
** character data member (Character pointer)
*********************************************************************/
Character* Train::getCharacter() {
    return this->character;
}
