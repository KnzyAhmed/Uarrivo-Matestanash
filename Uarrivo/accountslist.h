#ifndef ACCOUNTSLIST_H
#define ACCOUNTSLIST_H

#include <QMainWindow>
#include "account.h"
#include "personalinfo.h"
#include "creditcard.h"
#include "wallet.h"
struct node{
    account user;
    personal_info info;
    wallet w;
    creditCard credit;
    node* next;
    node(){
        next = nullptr;
    }
};


class accountlist
{
private:
    node* head;
public:
    accountlist();
    void insert(account, personal_info, wallet, creditCard);
    bool login(string, string);
    bool usernameavailable(string);
    account returnaccount(string);
    personal_info returninfo(string);
    wallet returnwallet(string);
    creditCard returncredit(string);
    void printlist(){
        node *iter = head;
        while(iter != NULL){
            cout <<iter->user.getemail() << ", " <<iter->user.getpass() << ", " << iter->user.getrating() << ", " << iter->user.getphone() <<endl;
            iter = iter-> next;
        }
        cout << endl;

    }
};

#endif // ACCOUNTSLIST_H
