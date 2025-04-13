#ifndef TAXI_SEIF_H
#define TAXI_SEIF_H
#include "car_seif.h"


class taxi: public car {
private:
    double driverRating;
    double carRating;

public:
    taxi();
    taxi(double DRIVERRATING, double CARRATING, int neww, int price, string cartype, string color);
    taxi(const taxi& t);
    float getcarrate();
    float getdriverrate();
};

#endif // TAXI_SEIF_H
