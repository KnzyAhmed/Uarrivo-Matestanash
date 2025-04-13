#ifndef LUXURIOUS_H
#define LUXURIOUS_H

#include <iostream>
#include "car.h"
using namespace std;

class luxurious: public car {
private:
    float driverRating;
    float carRating;


public:
    luxurious();
    luxurious(const luxurious& l);
    luxurious(float DRIVERRATING, float CARRATING, int n, int p, string ct, string c);
    float getcarrate();
    float getdriverrate();


};
#endif // LUXURIOUS_H
