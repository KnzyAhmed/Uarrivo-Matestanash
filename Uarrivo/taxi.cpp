#include "taxi.h"

taxi::taxi()
{
    driverRating = 0;
    carRating = 0;
}


taxi::taxi(double DRIVERRATING, double CARRATING, int neww, int price, string cartype, string colour) :car(){ //can set thisLuxurious later as well
    driverRating = DRIVERRATING;
    carRating = CARRATING;
    carType = cartype;
    color = colour;
    pricePerKm = price;
    New = neww;
}

taxi::taxi(const taxi& t){
    carRating = t.carRating;
    driverRating = t.driverRating;
    carType = t.carType;
    color = t.color;
    pricePerKm = t.pricePerKm;
    New = t.New;
    carplate = t.carplate;
}

float taxi::getcarrate(){
    return carRating;
}
float taxi::getdriverrate(){
    return driverRating;
}
