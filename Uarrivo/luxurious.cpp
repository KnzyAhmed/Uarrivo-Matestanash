#include "luxurious.h"

#include "luxlist.h"

luxurious::luxurious()
{
    driverRating = 0;
    carRating = 0;

}

luxurious::luxurious(float DRIVERRATING, float CARRATING, int n, int p, string ct, string c) :car(){
    driverRating = DRIVERRATING;
    carRating = CARRATING;
    carType = ct;
    color = c;
    pricePerKm = p;
    New = n;
}

luxurious :: luxurious(const luxurious& l){
    carRating = l.carRating;
    driverRating = l.driverRating;
    carType = l.carType;
    color = l.color;
    pricePerKm = l.pricePerKm;
    New = l.New;
    carplate = l.carplate;

}
float luxurious::getcarrate(){
    return carRating;
}
float luxurious::getdriverrate(){
    return driverRating;
}
