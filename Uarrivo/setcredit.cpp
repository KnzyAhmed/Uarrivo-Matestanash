#include "setcredit.h"
#include "ui_setcredit.h"
#include "creditcard.h"
#include <qmessagebox.h>
#include "customer.h"

setCredit::setCredit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setCredit)
{
    ui->setupUi(this);
}

setCredit::~setCredit()
{
    delete ui;
}

void setCredit::on_confirmationbutton_clicked()
{
    QMessageBox error;
    error.setText("You left a field empty.");
    creditCard obj;
    QString cvv, ccnum, balance, month, year, type;
    cvv = ui->cvv->text();
    ccnum = ui->creditnumber->text();
    balance = ui->balance->text();
    month = ui->monthofexp->text();
    year = ui->yearofexp->text();
    type = ui->type->text();
    if(ui->cvv->text().isEmpty() || ui->creditnumber->text().isEmpty() || ui->balance->text().isEmpty() || ui->monthofexp->text().isEmpty() || ui->yearofexp->text().isEmpty() || ui->type->text().isEmpty()){
        error.exec();
    }else{
        int cvvn = stoi(cvv.toStdString());
        string creditnum = ccnum.toStdString();
        int monthofex = stoi(month.toStdString());
        int yearofex = stoi(year.toStdString());
        string typee = type.toStdString();
        int balancee = stoi(balance.toStdString());
        obj.setall(typee, creditnum, cvvn, monthofex, yearofex, balancee);
        customer::setcredit(obj);
        customer::writecreditonfile();
    }

    }



