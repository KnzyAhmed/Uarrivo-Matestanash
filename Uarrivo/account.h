#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include  "string"
using namespace std;
class account
{
protected:

    string email;
    string password;
    double rating;
    int phonenumber;

public:
    account();
    void setall(string, string, double, int);
    account(const account& acc);
    void setemail(string);
    void setpassword(string);
    void setphone(int);
    void setrate(double);
    int getphone();
    string getpass();
    string getemail();
    double getrating();
    void readinfo(int, int, string, double);
    bool allowlogin(string, string);


};

#endif // ACCOUNT_H
