#ifndef PAYMENT_H
#define PAYMENT_H


#include <iostream>
#include "wallet.h"
#include "creditcard.h"
using namespace std;

class payment {
private:
     creditCard credit;
     wallet Wallet; //Wallet is of type wallet which is a class I defined ~ Seif

public:
     payment();
   void pay(creditCard CREDITCARD, double PAYMENT); // payment method 1 which uses a credit card
   void pay(wallet WALLET, double PAYMENT); //payment method 2 which uses wallet


};

#endif // PAYMENT_H
