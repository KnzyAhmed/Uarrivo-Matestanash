#include "login.h"
#include "ui_login.h"
#include <iostream>
#include <string.h>
#include <QMessageBox>
#include "customer.h"
#include "service_choice.h"

using namespace std;

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_login_buton_clicked()
{
    bool condition = false;
    QString mail,password;
    mail = ui->email_inputlogin->text();
    password = ui->password_inputlogin->text();
    string email = mail.toStdString();;
    string passw = password.toStdString();
    condition = customer::isaccount(email,passw);
    QMessageBox msgBox,msg;
    msg.setText("successfully logged in.");
    msgBox.setText("ERROR, INCORRECT PASSWORD OR EMAIL");
    if(condition == true){
        msg.exec();
        this->close();
        customer::setcustomer(email);
        service_choice *newForm = new service_choice;
        newForm->open();
    } else msgBox.exec();
}
