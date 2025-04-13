#ifndef ORIGINAL_MAP_H
#define ORIGINAL_MAP_H
#include "luxlist.h"
#include "ordinarylist.h"
#include "taxilist.h"
#include "personalinfo.h"
#include "luxurious.h"
#include "taxi.h"
#include "ordinary.h"
#include <QDialog>
#include <fstream>
//#include "route_popup.h"


namespace Ui {
class original_map;
}

class original_map : public QDialog
{
    Q_OBJECT


public:
    explicit original_map(QWidget *parent = nullptr);
    ~original_map();

    int minDistance(int[6], bool[6]);
    int dijkstra(int[6][6], int, int);
private slots:
    void on_confirming_trip_clicked();

    void on_confirm_trip_clicked();

private:
    Ui::original_map *ui;
    QString destination, location;
    luxlist luxuriousList;
    ordinaryList ordList;
    taxiList tList;
    static int price;
    personal_info driver;
    int distancee;
    taxi taxicar;
    ordinary ordinarycar;
    luxurious luxuriouscar;
//    route_popup *route;
    int graph[6][6] = {
             /*A*/           {0, 10, 0, 9, 0, 0},
             /*B*/           {10, 0, 4, 0, 0, 18},
             /*C*/           {0, 4, 0, 7, 4, 0},
             /*D*/           {9, 0, 7, 0, 3, 0},
             /*E*/           {0, 0, 4, 3, 0, 2},
             /*F*/           {0, 18, 0, 0, 2, 0}};

};

#endif // ORIGINAL_MAP_H
