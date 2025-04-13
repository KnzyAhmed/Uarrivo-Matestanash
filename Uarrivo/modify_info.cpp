#include "modify_info.h"
#include "ui_modify_info.h"
#include <iostream>
#include <string>
#include <fstream>
#include <QMessageBox>
#include "customer.h"
#include "setcredit.h"

using namespace std;

modify_info::modify_info(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::modify_info)
{
    ui->setupUi(this);

    QString fname = QString::fromStdString(customer::returnname());
    ui->fname_label->setText(fname);
    QString lanme = QString::fromStdString(customer::returnlname());
    ui->lname_label->setText(lanme);
    QString phone = QString::fromStdString(customer::returnphone());
    ui->phone_label->setText(phone);
    QString pass = QString::fromStdString(customer::returnpass());
    ui->pass_label->setText(pass);
    QString balance = QString::fromStdString(to_string(customer::returnbalance()));
    ui->walletbalance_output->setText(balance);
    ui->rewards_output->setText(QString::fromStdString(to_string(customer::returnrewards())));
}

modify_info::~modify_info()
{
    delete ui;
}

void modify_info::on_modify_fname_clicked()
{
    QString name;
    string info[1000];
    string original = customer::returnname();

    QMessageBox msgBox, msg;
    msg.setText("Name modified successfully.");
    name = ui->fname_new->text();
    string newname = name.toStdString();
    customer::modifyfname(newname);
    string replace = newname;
    fstream read(R"(D:\PROJECT_CS\customersACCs.txt)",ios::in);
    fstream copy(R"(E:\Uarrivoo\replace.txt)",ios::out);
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
    int copyy = 0;
    if(copy.is_open()){
        while( copyy < accounts){

            copy << info[copyy] << " " << info[copyy+1] << " " <<info[copyy+2] << " " <<info[copyy+3] << " " << info[copyy+4] << " " << info[copyy+5] << " " << info[copyy+6] << " " << info[copyy+7]  << " " << info[copyy+8] << " " << info[copyy+9] << " " << info[copyy+10] << " " << info[copyy+11] << " " << info[copyy+12] << " " << info[copyy+13] << endl;
            copyy= copyy+14;
        }
    }else {
        msgBox.setText("!!ERROR OPENING FILE!!");
        msgBox.exec();

    }
    msg.exec();
    fstream write(R"(D:\PROJECT_CS\customersACCs.txt)",ios::out);
    int index = 0;
    if(write.is_open()){
        while(index < accounts){
            if(index != 0 && index%14 == 0){
                write << endl;
            }
            if(info[index] == original){
                info[index] = replace;
            }
           write << info[index] << " ";

           index++;

        }
    }else {
        msgBox.setText("!!ERROR OPENING FILE!!");
        msgBox.exec();

    }
    read.close();
}

void modify_info::on_modify_lname_clicked()
{
    QString name;
    string original = customer::returnlname();
    name = ui->lname_new->text();
    string newname = name.toStdString();
    customer::modifylname(newname);
    string replace = newname;
    string info[1000];

    QMessageBox msgBox, msg;
    msg.setText("Last name modified successfully");
    fstream read(R"(D:\PROJECT_CS\customersACCs.txt)",ios::in);
    fstream copy(R"(E:\Uarrivoo\replace.txt)",ios::out);
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
    int copyy = 0;
    if(copy.is_open()){
        while( copyy < accounts){

            copy << info[copyy] << " " << info[copyy+1] << " " <<info[copyy+2] << " " <<info[copyy+3] << " " << info[copyy+4] << " " << info[copyy+5] << " " << info[copyy+6] << " " << info[copyy+7]  << " " << info[copyy+8] << " " << info[copyy+9] << " " << info[copyy+10] << " " << info[copyy+11] << " " << info[copyy+12] << " " << info[copyy+13] << endl;
            copyy= copyy+14;
        }
    }else {
        msgBox.setText("!!ERROR OPENING FILE!!");
        msgBox.exec();

    }
    msg.exec();
    fstream write(R"(D:\PROJECT_CS\customersACCs.txt)",ios::out);
    int index = 0;
    if(write.is_open()){
        while(index < accounts){
            if(index != 0 && index%14 == 0){
                write << endl;
            }
            if(info[index] == original){
                info[index] = replace;
            }
           write << info[index] << " ";

           index++;

        }
    }else {
        msgBox.setText("!!ERROR OPENING FILE!!");
        msgBox.exec();

    }
    read.close();
}

void modify_info::on_modify_phone_clicked()
{
    QString num;
    string original = customer::returnphone();
    num = ui->phone_new->text();
    int phone = num.toInt();
    customer::modifyphone(phone);

    string replace = to_string(phone);
    string info[1000];
    QMessageBox msgBox, msg;
    msg.setText("Phone number modified successfully");
    fstream read(R"(D:\PROJECT_CS\customersACCs.txt)",ios::in);
    fstream copy(R"(E:\Uarrivoo\replace.txt)",ios::out);
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
    int copyy = 0;
    if(copy.is_open()){
        while( copyy < accounts){

            copy << info[copyy] << " " << info[copyy+1] << " " <<info[copyy+2] << " " <<info[copyy+3] << " " << info[copyy+4] << " " << info[copyy+5] << " " << info[copyy+6] << " " << info[copyy+7]  << " " << info[copyy+8] << " " << info[copyy+9] << " " << info[copyy+10] << " " << info[copyy+11] << " " << info[copyy+12] << " " << info[copyy+13] << endl;
            copyy = copyy+14;
        }
    }else {
        msgBox.setText("!!ERROR OPENING FILE!!");
        msgBox.exec();

    }
    msg.exec();
    fstream write(R"(D:\PROJECT_CS\customersACCs.txt)",ios::out);
    int index = 0;
    if(write.is_open()){
        while(index < accounts){
            if(index != 0 && index%14 == 0){
                write << endl;
            }
            if(info[index] == original){
                info[index] = replace;
            }
           write << info[index] << " ";

           index++;

        }
    }else {
        msgBox.setText("!!ERROR OPENING FILE!!");
        msgBox.exec();

    }
    read.close();
}

void modify_info::on_modify_pass_clicked()
{
    QString pass;
    string original = customer::returnpass();
    pass = ui->pass_new->text();
    string newpass = pass.toStdString();
    customer::modifypass(newpass);

    string replace = newpass;
    string info[1000];
    QMessageBox msgBox, msg;
    msg.setText("Password modified successfully");
    fstream read(R"(D:\PROJECT_CS\customersACCs.txt)",ios::in);
    fstream copy(R"(E:\Uarrivoo\replace.txt)",ios::out);
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
    int copyy = 0;
    if(copy.is_open()){
        while( copyy < accounts){

            copy << info[copyy] << " " << info[copyy+1] << " " <<info[copyy+2] << " " <<info[copyy+3] << " " << info[copyy+4] << " " << info[copyy+5] << " " << info[copyy+6] << " " << info[copyy+7] << " " << info[copyy+8] << " " << info[copyy+9] << " " << info[copyy+10] << " " << info[copyy+11] << " " << info[copyy+12] << " " << info[copyy+13] << endl;
            copyy= copyy+14;
        }
    }else {
        msgBox.setText("!!ERROR OPENING FILE!!");
        msgBox.exec();

    }
    msg.exec();
    fstream write(R"(D:\PROJECT_CS\customersACCs.txt)",ios::out);
    int index = 0;
    if(write.is_open()){
        while(index < accounts){
            if(index != 0 && index%14 == 0){
                write << endl;
            }
            if(info[index] == original){
                info[index] = replace;
            }
           write << info[index] << " ";

           index++;

        }
    }else {
        msgBox.setText("!!ERROR OPENING FILE!!");
        msgBox.exec();

    }
    read.close();
}

void modify_info::on_setcreditcard_clicked()
{
    setCredit *newform = new setCredit;
    newform->show();
}
