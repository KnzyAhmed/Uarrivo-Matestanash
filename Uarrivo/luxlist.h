#ifndef LUXLIST_H
#define LUXLIST_H



#include <iostream>
#include "personalinfo.h"
#include "luxurious.h"
using namespace std;

struct luxNode{
    luxurious car;
    int location;
    personal_info driver;
    luxNode* next;
    luxNode(){
        next = nullptr;
    }
};

class luxlist{
private:
    luxNode* head;
    int count;
public:
    luxlist();
    void insert(luxurious l, personal_info p, int location);

    void deletecar(string driversname);
    int minDistance(int[6], bool[6]);
    int dijkstra(int[6][6], int, int);
    luxurious returnnearest(int location, int graph[6][6]);
    personal_info returndriver(int location, int graph[6][6]);
    int returlocation(int location, int graph[6][6]);

};

#endif // LUXLIST_H
