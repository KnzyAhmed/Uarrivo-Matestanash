#include "payment_window.h"
#include "ui_payment_window.h"
#include <QMessageBox>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

#include "customer.h"
payment_window::payment_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::payment_window)
{
    ui->setupUi(this);
}

payment_window::~payment_window()
{
    delete ui;
}

void payment_window::setdistance(int d){
    distance = d;
}

void payment_window::setfee(int price){
    pricetopay = price;
}

void payment_window::on_walletmoney_clicked()
{
    QMessageBox paidd;
    paidd.setText("There is nothing to pay for, you already paid.");
    if(pricetopay == 0){
     paidd.exec();
     this->close();
    }
    QMessageBox error, paid;
    error.setText("You do not have enough money in your wallet, please choose to pay the rest with cash or with creditcard.");
    paid.setText(QString::fromStdString(to_string(pricetopay)) + "LE have been deduced from your wallet." );
    double amountpresent = customer::returnbalance();
    if(amountpresent < pricetopay){
        error.exec();
        customer::emptywallet();
        pricetopay = pricetopay - customer::returnbalance();
    }else {
        paid.exec();
        customer::deductfromwallet(pricetopay);
        pricetopay = 0;
       this->close();
    }

}

void payment_window::on_creditcard_clicked()
{
    creditCard card;
    card = customer::returncredit();
    QMessageBox paidd;
    paidd.setText("There is nothing to pay for, you already paid.");

    if(pricetopay == 0){
    paidd.exec();
    this->close();
    }

    QMessageBox nocard, paid;
       nocard.setText("You have not set your creditcard info, please choose another payment method or go set your card info from the profile.");
       paid.setText(QString::fromStdString(to_string(pricetopay)) + "LE have been deduced from your creditcard." );
    if(customer::getcardtype() == "N/A"){
        nocard.exec();
    }
    else{

       // card.deductfrombalance(pricetopay);
        customer::setcredit(card);
        customer::deductfromcredit(pricetopay);
             pricetopay = 0;
        paid.exec();
    }
}

void payment_window::on_cash_clicked()
{
    QMessageBox paidd;
    paidd.setText("There is nothing to pay for, you already paid.");
    if(pricetopay == 0){
     paidd.exec();
     this->close();
    }
    QMessageBox paid;
    paid.setText("Please pay to the driver, enjoy your ride.");
    paid.exec();
    pricetopay = 0;
}
