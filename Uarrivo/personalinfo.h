#ifndef PERSONALINFO_H
#define PERSONALINFO_H


#include <iostream>
#include  "string"
using namespace std;


class personal_info
{
public:
    personal_info();
    personal_info(const personal_info& p);
    string getname();
    string getfirst();
    string getlast();
    void setf(string);
    void setl(string);
    void setname(string, string);
    int getage();
    void setage(int);

private:
    string firstname;
    string lastname;

    string name = firstname + " " + lastname;
    int age;
};


#endif // PERSONALINFO_H
