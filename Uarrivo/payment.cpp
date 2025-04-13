#include "payment.h"
#include "wallet.h"


payment::payment()
{
     creditCard theCreditCard(creditCard(0, 0, 0, "visa", 0, 0)); //default values set
     credit = theCreditCard;
     Wallet.setBalance(0); //Wallet is of type wallet which is a class I defined ~ Seif
}

void payment::pay(creditCard CREDITCARD, double PAYMENT){
    //more functunalities will be added as we countinue the app
    if(credit.getUsableMoney() > PAYMENT) {
    CREDITCARD = credit;
    credit.setUsableMoney(CREDITCARD.getUsableMoney() - PAYMENT);

    }

} // payment method 1 which uses a credit card
void payment::pay(wallet WALLET, double PAYMENT){
    //more functunalities will be added as we countinue the app
    if(Wallet.getBalance() > PAYMENT) {
    WALLET = Wallet;
    Wallet.setBalance(WALLET.getBalance() - PAYMENT);

    }
} //payment method 2 which uses wallet
