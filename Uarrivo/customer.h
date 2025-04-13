#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QMainWindow>
#include "account.h"
#include "accountslist.h"
#include "personalinfo.h"
#include "creditcard.h"
#include "wallet.h"


QT_BEGIN_NAMESPACE
namespace Ui { class customer; }
QT_END_NAMESPACE

class customer : public QMainWindow
{
    Q_OBJECT

public:
    customer(QWidget *parent = nullptr);
    ~customer();
    static bool isaccount(string acc,string pass);
    static void addaccount(account, personal_info, wallet, creditCard);
    static bool allowregister(string user);
    static void setcustomer(string);
    static void modifyfname(string);
    static void modifyphone(int);
    static void modifylname(string);
    static void modifypass(string);
    static string returnlname();
    static string returnpass();
    static string returnphone();
    static string returnname();
    static int returnbalance();
    static creditCard returncredit();
    static void emptywallet();
    static void deductfromwallet(int);
    static string getcardtype();
    static void deductfromcredit(int);
    static void setcredit(creditCard);
    static float getcardbalance();
    static void writecreditonfile();
    static float round(float);
    static int returnrewards();
private slots:

    void on_login_buton_clicked();

    void on_signup_buttom_clicked();

private:
    static accountlist list;
    Ui::customer *ui;
    QString email;
    QString password;
    account myaccount;
    creditCard c;
    static wallet w;
    static int points;
    static account acc;
    static wallet mywallet;
    static creditCard mycard;
    static personal_info info;


};
#endif // CUSTOMER_H
