#include "signup.h"
#include "ui_signup.h"
#include "account.h"
#include "personalinfo.h"
#include <iostream>
#include <string>
#include <fstream>
#include <QMessageBox>
#include "creditcard.h"
#include "customer.h"
#include "service_choice.h"
using namespace std;

SignUp::SignUp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignUp)
{
    ui->setupUi(this);
}

SignUp::~SignUp()
{
    delete ui;
}

void SignUp::on_signupwindow_button_clicked()
{
    string username, finame, laname, password;
    QMessageBox msg, msgbox, underage, couldntadd, availability, wrongphone;
    int agee, phonenum, rate = 0.0;
    availability.setText("username is unavailabe, please pick another one.");
    wrongphone.setText("your phone number is invalid, has to be 10 digits.");
    underage.setText("users under 18 are not allowed to register.");
    couldntadd.setText("Couldn't add customer to memory");
    msg.setText("successfully signed up.");
    msgbox.setText("ERROR, FORGOT A FIELD");
    QString fname, lname, age, pass, email, phone;
    fname = ui->firstname_input->text();
    lname = ui->lastname_input->text();
    age = ui->age_input->text();
    pass = ui->password_input->text();
    email = ui->username_input->text();
    phone = ui->phone_input->text();

    account a;
    personal_info p;

    agee = age.toInt();
    phonenum = phone.toInt();
    username = email.toStdString();
    password = pass.toStdString();
    laname = lname.toStdString();
    finame= fname.toStdString();

     int countnum = 0, phonenumber = phonenum;
     while(phonenumber != 0 ){
         phonenumber = phonenumber/10;
         countnum++;
     }


    if(ui->firstname_input->text().isEmpty() || ui->lastname_input->text().isEmpty() || ui->password_input->text().isEmpty() || ui->username_input->text().isEmpty() || ui->phone_input->text().isEmpty() || ui->age_input->text().isEmpty()){
        msgbox.exec();
    }else if(agee < 18){
        underage.exec();
    }else if(customer::allowregister(username) == false){
        availability.exec();}
    else if(countnum != 10){
        wrongphone.exec();
    }else{
        a.setall(username,password,0.0,phonenum);
        p.setname(finame,laname);
        p.setage(agee);
        wallet w;
        w.setBalance(100.00);
        creditCard card("0",0,0.0,"N/A",0,0);
        customer::addaccount(a,p, w,card);
        fstream add(R"(D:\PROJECT_CS\customersACCs.txt)",ios::app);
        //log.open("log.txt", fstream::app)
        if(add.is_open()){
            add << endl << username << " " << password << " " << rate << " " << phonenum << " " << finame << " " << laname << " " << agee << " " << 100.00 << " " << "N/a" << " " << 000 << " " << 000 << " " << 000 << " " << 000 << " " << 000;

        }else{
            couldntadd.exec();

        }
        add.close();
        msg.exec();
        this->close();
    }
}
