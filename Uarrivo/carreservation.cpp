#include "carreservation.h"

carReservation::carReservation()
{
    shared = false; //is there a carpool, if so the bill will be split
    carType = "N/A";
  //  customer Customer1; //customer of type customer
    // customer Customer2; //optional customer
    carPlate = "N/A"; //the plate number and letters
    cancelled = false;
}



bool carReservation::cancelRide() {
    cancelled = true;

    cout << "The ride has been cancelled" << endl;

    return cancelled;
} //returns true if the customer cancelled the ride

bool carReservation::isShared(){
    return shared;
}

int carReservation::avgTime(/* location x, */ int AVGTIMEPERKM){ //AVGTIMEPERKM is AVGTIME per km for cars in the city can be found in car class
    /* int distance = x.distanceCalculator(); //function in location made by knzy that will calculate distance
     * return AVGTIMEPERKM * distance;

*/
} //average time in minutes
