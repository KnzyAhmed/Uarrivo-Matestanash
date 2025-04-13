#ifndef TAXILIST_H
#define TAXILIST_H
#include <iostream>
#include "taxi.h"
#include "personalinfo.h"
using namespace std;

struct taxiNode{
    taxi car;
    int location;
    personal_info driver;
    taxiNode* next;
    taxiNode(){
        next = nullptr;
    }
};

class taxiList
{
private:
    taxiNode* head;
    int count;
public:
    taxiList();
    void insert(taxi l, personal_info p, int location);
    void deletecar(string driversname);
    int minDistance(int[6], bool[6]);
    int dijkstra(int[6][6], int, int);
    taxi returnnearest(int location, int graph[6][6]);
    personal_info returndriver(int location, int graph[6][6]);
    int returlocation(int location, int graph[6][6]);

};

#endif // TAXILIST_H
