#ifndef WALLET_H
#define WALLET_H


#include <iostream>
using namespace std;


class wallet{

private:
    int balance;

public:
    wallet();
    wallet(const wallet& cop);
    void setBalance(int BALANCE);
    float getBalance();
    void deduct(int);
    void emptywall();
};

#endif // WALLET_H
