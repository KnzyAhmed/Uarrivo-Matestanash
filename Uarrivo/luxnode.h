#ifndef LUXNODE_H
#define LUXNODE_H



//#include <iostream>
//#include "personalinfo.h"
//#include "luxurious_seif.h"
//using namespace std;

//struct luxNode{
//    luxurious lux;
//    int location;
//    personal_info driver;
//    luxNode* next;
//};

//class luxlist{
//private:
//    luxNode* head;
//public:

//    void insert(luxurious l, personal_info p, int location){
//        luxNode* newnode = new luxNode;
//        newnode->lux = l;
//        newnode->driver = p;
//        newnode->location = location;
//        if(head == nullptr){
//            head = newnode;
//        }else{
//            luxNode* curr = head;
//            while(curr->next!=nullptr){
//                curr = curr->next;
//            }
//            curr->next = newnode;
//        }
//    };

//    void deletecar(string driversname){
//        luxNode* curr = head;
//        luxNode* prev;
//        if(head->driver.getname() == driversname){
//            head = head->next;
//            delete curr;
//            return;
//        }else{
//            while(curr->driver.getname() != driversname && curr->next !=nullptr){
//                if(curr->driver.getname() == driversname){
//                    prev->next = curr->next;
//                    delete curr;
//                }
//                prev = curr;
//                curr = curr->next;
//            }
//            if(curr->driver.getname() == driversname){
//                prev->next = curr->next;
//                delete curr;
//            }
//        }
//        return;
//    };


//};
#endif // LUXNODE_SEIF_H
