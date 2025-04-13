#include "wallet.h"

wallet::wallet()
{
    balance = 0;
}
wallet::wallet(const wallet& cop){
    balance = cop.balance;
}

void wallet::setBalance(int BALANCE){
    balance = BALANCE;
}

float wallet::getBalance(){
   return balance;
}

void wallet::deduct(int mon){
    balance =  balance - mon;
}

void wallet::emptywall(){
    balance = 0;
}
