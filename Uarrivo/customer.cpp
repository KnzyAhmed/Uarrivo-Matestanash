//#include "customer.h"
#include "ui_customer.h"
#include<QGraphicsScene>
#include <QFile>
#include <sstream>
#include <QMessageBox>
#include <QTextStream>
#include <cmath>
#include "login.h"
#include "signup.h"
#include <fstream>
#include <iomanip>
#include "accountslist.h"
#include "personalinfo.h"
#include <iostream>
#include <string>
using namespace std;

accountlist customer :: list;
account customer:: acc;
personal_info customer::info;
wallet customer:: mywallet;
int customer::points;
creditCard customer::mycard;

customer::customer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::customer)
{
    ui->setupUi(this);

    QMessageBox msgBox;
    fstream read(R"(D:\PROJECT_CS\customersACCs.txt)",ios::in);
    account obj;
    wallet bal;
    creditCard card;
    personal_info inform;
    string info[1000];
    string em;

    int accounts =0;
    if(read.is_open()){
        while(read >> info[accounts]){
            accounts++;
        }
    }else {
        msgBox.setText("!!ERROR OPENING FILE!!");
        msgBox.exec();

    }
    read.close();

    for(int i = 0; i<accounts ;i++){
        obj.setemail(info[i]);
        obj.setpassword(info[i+1]);
        obj.setrate(stod(info[i+2]));
        obj.setphone(stoi(info[i+3]));
        inform.setname(info[i+4], info[i+5]);
        inform.setage(stoi(info[i+6]));
        bal.setBalance(stoi(info[i+7]));
        if(info[i+8] == "N/A"){
            card.setall("N/A", "0",0,0,0,0.0);
        }else{
            card.setall(info[i+8],info[i+9], stoi(info[i+10]), stoi(info[i+11]), stoi(info[i+12]), stoi(info[i+13]));
        }
        list.insert(obj, inform, bal, card);
        i=i+13;
    }
}


customer::~customer()
{
    delete ui;
}

bool customer::isaccount(string acc, string pass){
    if(list.login(pass,acc) == true){
        return true;
    }else{
        return false;
    }
};

void customer::addaccount(account a, personal_info p,wallet w, creditCard c){
    list.insert(a,p, w, c);
}
bool customer::allowregister(string user){
    if(list.usernameavailable(user) == true){
        return true;

    }else{ return false;}
}

void customer::setcustomer(string email){
    acc = list.returnaccount(email);
    info = list.returninfo(email);
    mywallet = list.returnwallet(email);
    mycard = list.returncredit(email);
}

string customer::returnname(){
    return info.getfirst();
}

void customer::on_login_buton_clicked()
{
    Login *loginwindow = new Login;
    loginwindow->open();
   // this->hide();
}

void customer::on_signup_buttom_clicked()
{
    SignUp *newForm = new SignUp;
    newForm->open();
    //this->hide();
}
float customer:: round(float var)
{

    char str[40];

       // Print in string the value of var
       // with two decimal point
       sprintf(str, "%.2f", var);

       // scan string value in var
       sscanf(str, "%f", &var);

       return var;
}


void customer::modifyfname(string f){
    info.setf(f);
}
void customer::modifylname(string l){
    info.setl(l);
}
void customer::modifyphone(int p){
    acc.setphone(p);
}
void customer::modifypass(string pass){
    acc.setpassword(pass);
}
string customer::returnlname(){
    return info.getlast();
}
string customer::returnpass(){
    return acc.getpass();
}
string customer::returnphone(){
    int pho = acc.getphone();
    string phone = to_string(pho);
    return phone;
}
int customer::returnbalance(){
    return mywallet.getBalance();
}



void customer::deductfromwallet(int n){
    int original = mywallet.getBalance();
    int replace = original - n;
    string info[1000];

    QMessageBox msgBox, msg;
    //msg.setText("Last name modified successfully");
    fstream read(R"(D:\PROJECT_CS\customersACCs.txt)",ios::in);
    fstream copy(R"(E:\Uarrivoo\replace.txt)",ios::out);
    int accounts =0;
    if(read.is_open()){
        while(read >> info[accounts]){
            accounts++;
        }
    }else {
        msgBox.setText("!!ERROR READING FILE!!");
        msgBox.exec();

    }
    read.close();
    int copyy = 0;
    if(copy.is_open()){
        while( copyy < accounts){

            copy << info[copyy] << " " << info[copyy+1] << " " <<info[copyy+2] << " " <<info[copyy+3] << " " << info[copyy+4] << " " << info[copyy+5] << " " << info[copyy+6] << " " << info[copyy+7]  << " " << info[copyy+8] << " " << info[copyy+9] << " " << info[copyy+10] << " " << info[copyy+11] << " " << info[copyy+12] << " " << info[copyy+13] << endl;
            copyy= copyy+14;
        }
    }else {
        msgBox.setText("!!ERROR COPYING FILE!!");
        msgBox.exec();

    }
    //msg.exec();
    //cout << fixed << showpoint << setprecision(2);
    QString rep = QString::fromStdString(to_string(replace));
    msg.setText(rep);
    msg.exec();

    fstream write(R"(D:\PROJECT_CS\customersACCs.txt)",ios::out);
    int index = 0;
    if(write.is_open()){
        while(index < accounts){
            if(index != 0 && index%14 == 0){
                write << endl;
            }
            if(info[index] == to_string(original)){
                info[index] = to_string(replace);

            }
           write << info[index] << " ";

           index++;

        }
    }else {
        msgBox.setText("!!ERROR CHANGING WALLET BALANCE IN FILE!!");
        msgBox.exec();

    }
    read.close();



    mywallet.deduct(n);
    points = 0.5*n;
}
int customer::returnrewards(){
    return points;
}
void customer::writecreditonfile(){
    string namee = acc.getemail();
    string info[1000];

    QMessageBox msgBox, msg;
    //msg.setText("Last name modified successfully");
    fstream read(R"(D:\PROJECT_CS\customersACCs.txt)",ios::in);
    fstream copy(R"(E:\Uarrivoo\replace.txt)",ios::out);
    int accounts =0;
    if(read.is_open()){
        while(read >> info[accounts]){
            accounts++;
        }
    }else {
        msgBox.setText("!!ERROR READING FILE!!");
        msgBox.exec();

    }
    read.close();
    int copyy = 0;
    if(copy.is_open()){
        while( copyy < accounts){

            copy << info[copyy] << " " << info[copyy+1] << " " <<info[copyy+2] << " " <<info[copyy+3] << " " << info[copyy+4] << " " << info[copyy+5] << " " << info[copyy+6] << " " << info[copyy+7]  << " " << info[copyy+8] << " " << info[copyy+9] << " " << info[copyy+10] << " " << info[copyy+11] << " " << info[copyy+12] << " " << info[copyy+13] << endl;
            copyy= copyy+14;
        }
    }else {
        msgBox.setText("!!ERROR COPYING FILE!!");
        msgBox.exec();

    }
    fstream write(R"(D:\PROJECT_CS\customersACCs.txt)",ios::out);
    int index = 0;
    if(write.is_open()){
        while(index < accounts){
            if(index != 0 && index%14 == 0){
                write << endl;
            }

            if(info[index] == namee){
                   write << info[index] << " " << info[index+1] << " " <<info[index+2] << " " <<info[index+3] << " " << info[index+4] << " " << info[index+5] << " " << info[index+6] << " " << info[index+7] << " " << mycard.gettype() << " " << mycard.getcnumber() << " " << to_string(mycard.getcvv()) << " " << to_string(mycard.getmonth()) << " " <<to_string(mycard.getyear()) << " " << to_string(mycard.getUsableMoney()) <<endl;
                   index = index+14;
            }
           write << info[index] << " ";

           index++;

        }

        QMessageBox mess;
        mess.setText("Successfuly set CreditCard");
        mess.exec();
    }else {
        msgBox.setText("!!ERROR CHANGING WALLET BALANCE IN FILE!!");
        msgBox.exec();

    }
    read.close();

}

void customer::deductfromcredit(int amount){
    int original = mycard.getUsableMoney();
    int replace = original - amount;
    string info[1000];

    QMessageBox msgBox, msg;
    //msg.setText("Last name modified successfully");
    fstream read(R"(D:\PROJECT_CS\customersACCs.txt)",ios::in);
    fstream copy(R"(E:\Uarrivoo\replace.txt)",ios::out);
    int accounts =0;
    if(read.is_open()){
        while(read >> info[accounts]){
            accounts++;
        }
    }else {
        msgBox.setText("!!ERROR READING FILE!!");
        msgBox.exec();

    }
    read.close();
    int copyy = 0;
    if(copy.is_open()){
        while( copyy < accounts){

            copy << info[copyy] << " " << info[copyy+1] << " " <<info[copyy+2] << " " <<info[copyy+3] << " " << info[copyy+4] << " " << info[copyy+5] << " " << info[copyy+6] << " " << info[copyy+7]  << " " << info[copyy+8] << " " << info[copyy+9] << " " << info[copyy+10] << " " << info[copyy+11] << " " << info[copyy+12] << " " << info[copyy+13] << endl;
            copyy= copyy+14;
        }
    }else {
        msgBox.setText("!!ERROR COPYING FILE!!");
        msgBox.exec();

    }
    //msg.exec();
    //cout << fixed << showpoint << setprecision(2);
    QString rep = QString::fromStdString(to_string(replace));
    msg.setText(rep);
    msg.exec();

    fstream write(R"(D:\PROJECT_CS\customersACCs.txt)",ios::out);
    int index = 0;
    if(write.is_open()){
        while(index < accounts){
            if(index != 0 && index%14 == 0){
                write << endl;
            }
            if(info[index] == to_string(original)){
                info[index] = to_string(replace);

            }
           write << info[index] << " ";

           index++;

        }
    }else {
        msgBox.setText("!!ERROR CHANGING WALLET BALANCE IN FILE!!");
        msgBox.exec();

    }
    read.close();
    mycard.deductfrombalance(amount);
}

void customer::emptywallet(){
    mywallet.emptywall();
}

string customer::getcardtype(){
    return mycard.gettype();
}
float customer::getcardbalance(){
    return mycard.getUsableMoney();
}
void customer::setcredit(creditCard obj){
    mycard = obj;
}

creditCard customer::returncredit(){
    return mycard;
}
