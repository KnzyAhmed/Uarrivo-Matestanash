#include "account.h"

#include <iostream>
#include <string>
using namespace std;

account::account(){
    password = -0123;
    email = "rubbish";
    phonenumber = 0;
    rating = 0.0;
}

void account :: setall(string em, string pass, double rate, int pho){
    rating = rate;
    email = em;
    password = pass;
    phonenumber = pho;
}

account :: account(const account &accou){
    email = accou.email;
    password =  accou.password;
    phonenumber = accou.phonenumber;
    rating = accou.rating;
}

void account:: setemail(string mail){
    this->email = mail;
};
void account::setpassword(string pass){
    this->password = pass;
};
void account::setphone(int number){
    this->phonenumber = number;
};
void account::setrate(double num){
    this->rating = num;
}


int account::getphone(){
    return phonenumber;
};
string account::getpass(){
    return password;
};
string account::getemail(){
    return email;
};
double account::getrating(){
    return rating;
};
void account::readinfo(int num, int pass, string email, double rate){
    this-> email = email;
    this-> rating = rate;
    this-> phonenumber = num;
    this->password = pass;
//#include <QFile>
//QFile bfile("/Users/salmaaly/build-lesgooo-Desktop_Qt_5_12_10_clang_64bit-Debug/gameboard.txt");
// bfile.open(QIODevice::ReadOnly);
//  QTextStream stream(&bfile);

}

bool account:: allowlogin(string pass, string mail){
    if(email == mail && password == pass){
        return true;
    }else { return false;}
}

