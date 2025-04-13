#include "ordinary.h"
#include "car.h"
#include "ordinarynode.h"

ordinary::ordinary()
{
    driverRating = 0;
    carRating = 0;
}

ordinary::ordinary(float DRIVERRATING, float CARRATING, int n, int p, string ct, string c):car() { //can set thisLuxurious later as well
    driverRating = DRIVERRATING;
    carRating = CARRATING;
    carType = ct;
    color = c;
    pricePerKm = p;
    New = n;
}


ordinary::ordinary(const ordinary& o){
    carRating = o.carRating;
    driverRating = o.driverRating;
    carType = o.carType;
    color = o.color;
    pricePerKm = o.pricePerKm;
    New = o.New;
    carplate = o.carplate;
}
float ordinary::getcarrate(){
    return carRating;
}
float ordinary::getdriverrate(){
    return driverRating;
}
