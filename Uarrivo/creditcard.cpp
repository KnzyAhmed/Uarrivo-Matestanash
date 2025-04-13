#include "creditcard.h"


creditCard::creditCard()
{
    number = " "; //credit card number
    cvv = 0; //the cvv number
    usableMoney = 100; //the usable money in the credit card
    type = "N/A"; //type of credit card...Visa, Mastercard, etc...
    monthOfExp = 1; //day of expiration date;
    yearOfExp = 2021; //year of expiration date;
}

creditCard :: creditCard(const creditCard& c){
    number =  c.number;
    cvv = c.cvv;
    usableMoney = c.usableMoney;
    type = c.type;
    monthOfExp = c.monthOfExp;
    yearOfExp = c.yearOfExp;
}

void creditCard::setall(string typ, string ccnum, int cv, int month, int year, int balance){
    type = typ;
    number = ccnum;
    cvv = cv;
    yearOfExp =  year;
    monthOfExp = month;
    usableMoney = balance;
}
creditCard::creditCard(string NUMBER, int CVV, int USABLEMONEY, string TYPE, int MONTHOFEXP, int YEAROFEXP){
    number = NUMBER; //credit card number
    cvv = CVV; //the cvv number
    usableMoney = USABLEMONEY; //the usable money in the credit card
    type = TYPE; //type of credit card...Visa, Mastercard, etc...
    monthOfExp = MONTHOFEXP; //day of expiration date;
    yearOfExp = YEAROFEXP; //year of expiration date;
}
//I use all caps with the names of the variables so anyone can know which each variable represents
int creditCard:: getUsableMoney(){
    return usableMoney;
}
string creditCard::gettype(){
    return type;
}

void creditCard:: setUsableMoney(int UsableMoney){
    usableMoney = UsableMoney;
}
void creditCard::deductfrombalance(int amount){
    usableMoney = usableMoney-amount;
}
string creditCard:: getcnumber(){
    return number;
};
int creditCard:: getcvv(){return cvv;}
int creditCard::getmonth(){return monthOfExp;}
int creditCard::getyear(){return yearOfExp;}
