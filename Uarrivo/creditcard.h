#ifndef CREDITCARD_H
#define CREDITCARD_H


#include <iostream>
using namespace std;

class creditCard{
private:
    string number; //credit card number
    int cvv; //the cvv number
    int usableMoney; //the usable money in the credit card
    string type; //type of credit card...Visa, Mastercard, etc...
    int monthOfExp; //day of expiration date;
    int yearOfExp; //year of expiration date;

public:
    creditCard();
    creditCard(const creditCard& c);
    void setall(string, string, int, int, int, int);
    creditCard(string NUMBER, int CVV, int USABLEMONEY, string TYPE, int DAYOFEXP, int YEAROFEXP);
    //I use all caps with the names of the variables so anyone can know which each variable represents
    int getUsableMoney();
    string gettype();
    string getcnumber();
    int getcvv();
    int getmonth();
    int getyear();
    void deductfrombalance(int);
    void setUsableMoney(int UsableMoney);

};
#endif // CREDITCARD_H
