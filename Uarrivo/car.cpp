#include "car.h"

//car::car(string ct, bool n, string carpla, string c, double ppk){
//    carType = ct;
//    New = n;
//    carplate = carpla;
//    color = c;
//    pricePerKm = ppk;
//};


car::car()
{
    carType = "N/A"; //type of car Mercedes GLA 2021, Corolla Toyota 2018 etc...
    New = false;
    pricePerKm = 5; //average price per km of the car
    color = "N/A"; //color of the car
}

string car::getCarType(){
    return carType;
}

bool car::getNew(){
    return New;
}


double car::getPricePerKm(){
    return pricePerKm;
}


string car::getColor(){
    return color;
}
string car::getCarplate(){
    return carplate;
}
void car::setcarplate(string c){
    carplate=c;
}
