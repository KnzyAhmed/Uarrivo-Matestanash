
#ifndef ORDINARYLIST_H
#define ORDINARYLIST_H
#include "ordinary.h"
#include "personalinfo.h"

#include <iostream>
using namespace std;


struct ordinaryNode{
    ordinary car;
    int location;
    personal_info driver;
    ordinaryNode* next;
    ordinaryNode(){
        next = nullptr;
    }
};

class ordinaryList{
private:
    ordinaryNode* head;
    int count;
public:
    ordinaryList();
    void insert(ordinary l, personal_info p, int location);
    void deletecar(string driversname);
    int minDistance(int[6], bool[6]);
    int dijkstra(int[6][6], int, int);
    ordinary returnnearest(int location, int graph[6][6]);
    personal_info returndriver(int location, int graph[6][6]);
    int returlocation(int location, int graph[6][6]);

};

#endif // ORDINARYLIST_H
