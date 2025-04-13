//Seif H Awad
//900202224
#ifndef CARRESERVATION_H
#define CARRESERVATION_H

#include <iostream>
using namespace std;

class carReservation{
private:
    bool shared; //is there a carpool, if so the bill will be split
    string carType;
  //  customer Customer1; //customer of type customer
    // customer Customer2; //optional customer
    string carPlate; //the plate number and letters
    bool cancelled;

public:
    carReservation();
    bool cancelRide(); //returns true if the customer cancelled the ride
    bool isShared();
    int avgTime(/* location x, */ int AVGTIMEPERKM);
    //average time in minutes will be calculated using distance from location and avg time per km
    //from respective cars luxurious, taxi, or ordinary


};

#endif // CARRESERVATION_H
