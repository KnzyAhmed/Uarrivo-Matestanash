#ifndef ORDINARY_H
#define ORDINARY_H

#include <iostream>
using namespace std;
#include "car.h"



class ordinary : public car {
private:
    float driverRating;
    float carRating;
public:
    ordinary();
    ordinary(float DRIVERRATING, float CARRATING, int n, int p, string ct, string c);
    ordinary(const ordinary& o);
    float getcarrate();
    float getdriverrate();

};

#endif // ORDINARY_H
