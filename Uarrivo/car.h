#ifndef CAR_H
#define CAR_H


#include <iostream>
using namespace std;

class car {
protected:
    string carType; //type of car Mercedes GLA 2021, Corolla Toyota 2018 etc...
    bool New;
    double pricePerKm; //average price per km of the car
    string carplate;
    string color; //color of the car


public:
    car();
   // car(string ct, bool n, string carpla, string c, double ppk);
    string getCarType();
    bool getNew();
    double getPricePerKm();
    string getColor();
    string getCarplate();
    void setcarplate(string);
};

#endif // CAR_H
