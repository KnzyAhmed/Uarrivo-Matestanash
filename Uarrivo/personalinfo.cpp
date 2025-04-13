#include "personalinfo.h"

personal_info::personal_info()
{
    firstname = "no";
    lastname = "name";
    age = -11;
}
string personal_info:: getname(){
    return name;
};

void personal_info::setname(string first, string last){
    firstname = first;
    lastname = last;
    name = firstname + " " + lastname;
};
int personal_info::getage(){
    return age;
};

void personal_info:: setage(int a){
    age = a;
};

personal_info::personal_info(const personal_info& p){
    name = p.name;
    firstname = p.firstname;
    lastname = p.lastname;
    age = p.age;
}
string personal_info::getfirst(){return firstname;}
string personal_info::getlast(){return lastname;}
void personal_info::setf(string f){
    firstname = f;
}
void personal_info::setl(string l){
    lastname = l;
}
