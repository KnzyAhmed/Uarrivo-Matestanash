#include "original_map.h"
#include "ui_original_map.h"
#include <fstream>
#include <QMessageBox>
#include "personalinfo.h"
#include "luxurious.h"
#include "ordinary.h"
#include "taxi.h"
#include "taxilist.h"
#include <ctime>
#include "ordinarylist.h"
#include "luxlist.h"
#include "route_popup.h"
#include "signup.h"
#include "payment_window.h"

#include "ui_route_popup.h"

using namespace std;

int original_map::price;
original_map::original_map(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::original_map)
{
    QMessageBox msgBox;

    ui->setupUi(this);
    QPixmap mapp("C:/Users/kenzy/Dropbox/My PC (DESKTOP-R153SN6)/Downloads/Map finished.PNG");
    ui->mappic->setPixmap(mapp);
    srand (time(NULL));


    fstream readtaxi(R"(E:\Uarrivoo\taxis.txt)",ios::in );
    fstream readord(R"(E:\Uarrivoo\ordinary.txt)",ios::in );
    fstream readlux(R"(E:\Uarrivoo\luxcars.txt)",ios::in );
    personal_info info;
    int tcount = 0, lcount = 0, ocount = 0;

    string tcars[100];
    string ocars[100];
    string lcars[100];

    if(readtaxi.is_open()){ //setting the list of taxis
        while(readtaxi >> tcars[tcount]){
            tcount++;
        }
    }else {
        msgBox.setText("!!ERROR OPENING FILE!!");
        msgBox.exec();

    }
    readtaxi.close();

    for(int i = 0; i<tcount ;i++){
        taxi tcar(stod(tcars[i+5]), stod(tcars[i+4]), stoi(tcars[i+1]), stoi(tcars[i+2]), tcars[i], tcars[i+3]);
        tcar.setcarplate(tcars[i+9]);
        info.setname(tcars[i+6], tcars[i+7]);
        info.setage(stoi(tcars[i+8]));
        int loc = (rand() % 5) + 0;
        tList.insert(tcar, info, loc);
        i=i+9;
    }

    if(readord.is_open()){
        while(readord >> ocars[ocount]){
            ocount++;
        }
    }else {
        msgBox.setText("!!ERROR OPENING FILE!!");
        msgBox.exec();

    }
    readord.close();
    for(int i = 0; i<ocount ;i++){
        ordinary ocar(stof(ocars[i+5]), stof(ocars[i+4]), stoi(ocars[i+1]), stoi(ocars[i+2]), ocars[i], ocars[i+3]);
        ocar.setcarplate(ocars[i+9]);
        info.setname(ocars[i+6], ocars[i+7]);
        info.setage(stoi(ocars[i+8]));
        int loca = (rand() % 5) + 0;
        ordList.insert(ocar, info, loca);
        i=i+9;
    }

    if(readlux.is_open()){
        while(readlux >> lcars[lcount]){
            lcount++;
        }
    }else {
        msgBox.setText("!!ERROR OPENING FILE!!");
        msgBox.exec();

    }
    readlux.close();
    for(int i = 0; i<lcount ;i++){
        luxurious lcar(stof(lcars[i+5]), stof(lcars[i+4]), stoi(lcars[i+1]), stoi(lcars[i+2]), lcars[i], lcars[i+3]);
        info.setname(lcars[i+6], lcars[i+7]);
        lcar.setcarplate(lcars[i+9]);
        info.setage(stoi(lcars[i+8]));
        int locat = (rand() % 5) + 0;
        luxuriousList.insert(lcar, info, locat);
        i=i+9;
    }

}

original_map::~original_map()
{
    delete ui;
}



// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int original_map:: minDistance(int shortest_dist[], bool visited[])
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < 6; v++)
        if (visited[v] == false && shortest_dist[v] <= min)
            min = shortest_dist[v], min_index = v;

    return min_index;
}

// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
int original_map::dijkstra(int graph[6][6], int location, int destination)
{
    int shortest_dist[6]; // The output array. dist[i] will hold the shortest
    // distance from src to i

    bool visited[6]; // sptSet[i] will be true if vertex i is included in shortest
    // path tree or shortest distance from src to i is finalized

    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < 6; i++)
        shortest_dist[i] = INT_MAX, visited[i] = false;

    // Distance of source vertex from itself is always 0
    shortest_dist[location] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < 6 - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to src in the first iteration.
        int u = minDistance(shortest_dist, visited);

        // Mark the picked vertex as processed
        visited[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < 6; v++)

            // Update dist[v] only if is not in sptSet, there is an edge from
            // u to v, and total weight of path from src to v through u is
            // smaller than current value of dist[v]
            if (!visited[v] && graph[u][v] && shortest_dist[u] != INT_MAX
                && shortest_dist[u] + graph[u][v] < shortest_dist[v])
                shortest_dist[v] = shortest_dist[u] + graph[u][v];
    }

    // print the constructed distance array
    //printSolution(dist, V);
    return shortest_dist[destination];
}

void original_map::on_confirming_trip_clicked()
{
    QMessageBox error,statement;
    QString carchoice = ui->car_choice->currentText();

     destination = ui->destination_input->text();
     location = ui->location_input->text();
    error.setText("You did something wrong");
    int loca, desti, distance;
   route_popup *newform = new route_popup;
    //newform->open();

    string loc, dest;
    loc = location.toStdString();
    dest = destination.toStdString();
    if(location == "A"){
        loca = 0;
        if(destination == "B"){
            distance = dijkstra(graph, 0, 1);
            statement.setText("Going from " + location +" to " + destination);
            newform->pickroute(loc,dest);
            desti=1;
            statement.exec();
        }
        else if(destination == "C"){
           distance = dijkstra(graph, 0, 2);
            statement.setText("Going from " + location +" to " + destination);
             newform->pickroute(loc,dest);
             statement.exec();
              desti=2;
        }
        else if(destination == "D"){
           distance = dijkstra(graph, 0, 3);
            statement.setText("Going from " + location +" to " + destination);
             newform->pickroute(loc,dest);
             statement.exec();
              desti=3;
        }
        else if(destination == "E"){
           distance = dijkstra(graph, 0, 4);
            statement.setText("Going from " + location +" to " + destination);
             newform->pickroute(loc,dest);
             statement.exec();
              desti=4;
        }
        else if(destination == "F"){
            distance =dijkstra(graph, 0, 5);
            statement.setText("Going from " + location +" to " + destination);
             newform->pickroute(loc,dest);
             statement.exec();
              desti=5;
        }else{
            error.exec();

        }

    }else if(location == "B"){
        loca = 1;
        if(destination == "A"){
           distance = dijkstra(graph, 1, 0);
            statement.setText("Going from " + location +" to " + destination);
             newform->pickroute(loc,dest);
             statement.exec();
              desti=0;
        }
        else if(destination == "C"){
           distance = dijkstra(graph, 1, 2);
            statement.setText("Going from " + location +" to " + destination);
             newform->pickroute(loc,dest);
             statement.exec();
              desti=2;
        }
        else if(destination == "D"){
           distance = dijkstra(graph, 1, 3);
            statement.setText("Going from " + location +" to " + destination);
             newform->pickroute(loc,dest);
             statement.exec();
              desti=3;
        }
        else if(destination == "E"){
           distance = dijkstra(graph, 1, 4);
            statement.setText("Going from " + location +" to " + destination);
             newform->pickroute(loc,dest);
             statement.exec();
              desti=4;
        }
        else if(destination == "F"){
          distance =  dijkstra(graph, 1, 5);
            statement.setText("Going from " + location +" to " + destination);
         newform->pickroute(loc,dest);
         statement.exec();
          desti=5;
        }else{
            error.exec();

        }

    }else if(location == "C"){
        loca = 2;
        if(destination == "A"){
           distance = dijkstra(graph, 2, 0);
            statement.setText("Going from " + location +" to " +destination);
             newform->pickroute(loc,dest);
             statement.exec();
              desti=0;
        }
        else if(destination == "B"){
           distance = dijkstra(graph, 2, 1);
            statement.setText("Going from " + location +" to " +destination);
             newform->pickroute(loc,dest);
             statement.exec();
              desti=1;
        }
        else if(destination == "D"){
           distance = dijkstra(graph, 2, 3);
            statement.setText("Going from " + location +" to " +destination);
             newform->pickroute(loc,dest);
             statement.exec();
              desti=3;
        }
        else if(destination == "E"){
           distance = dijkstra(graph, 2, 4);
            statement.setText("Going from " + location +" to " +destination);
             newform->pickroute(loc,dest);
             statement.exec();
              desti=4;
        }
        else if(destination == "F"){
          distance =  dijkstra(graph, 2, 5);
            statement.setText("Going from " + location +" to " +destination);
             newform->pickroute(loc,dest);
             statement.exec();
              desti=5;
        }else{
            error.exec();

        }

    }else if(location == "D"){
        loca = 3;
        if(destination == "A"){
            desti=0;
           distance = dijkstra(graph, loca, desti);
            statement.setText("Going from " + location +" to " +destination);
             newform->pickroute(loc,dest);
             statement.exec();

        }
        else if(destination == "B"){
           distance = dijkstra(graph, 3, 1);
            statement.setText("Going from " + location +" to " +destination);
             newform->pickroute(loc,dest);
             statement.exec();
              desti=1;
        }
        else if(destination == "C"){
           distance = dijkstra(graph, 3, 2);
            statement.setText("Going from " + location + " to " +destination);
             newform->pickroute(loc,dest);
             statement.exec();
              desti=2;
        }
        else if(destination == "E"){
          distance =  dijkstra(graph, 3, 4);
            statement.setText("Going from " + location +" to " +destination);
             newform->pickroute(loc,dest);
             statement.exec();
              desti=4;
        }
        else if(destination == "F"){
           distance = dijkstra(graph, 3, 5);
            statement.setText("Going from " + location +" to " +destination);
             newform->pickroute(loc,dest);
             statement.exec();
              desti=5;
        }else{
            error.exec();

        }

    }else if( location == "E"){
        loca = 4;
        if(destination == "A"){
           distance = dijkstra(graph, 4, 0);
            statement.setText("Going from " + location +" to " +destination);
             newform->pickroute(loc,dest);
             statement.exec();
              desti=0;
        }
        else if(destination == "B"){
           distance = dijkstra(graph, 4, 1);
            statement.setText("Going from " + location +" to " +destination);
             newform->pickroute(loc,dest);
             statement.exec();
              desti=1;
        }
        else if(destination == "C"){
           distance = dijkstra(graph, 4, 2);
            statement.setText("Going from " + location +" to " +destination);
             newform->pickroute(loc,dest);
             statement.exec();
              desti=2;
        }
        else if(destination == "D"){
          distance =  dijkstra(graph, 4, 3);
            statement.setText("Going from " + location +" to " +destination);
             newform->pickroute(loc,dest);
             statement.exec();
              desti=3;
        }
        else if(destination == "F"){
           distance = dijkstra(graph, 4, 5);
            statement.setText("Going from " + location +" to " +destination);
             newform->pickroute(loc,dest);
             statement.exec();
              desti=5;
        }else{
            error.exec();
        }

    }else if(location == "F"){
        loca = 5;
        if(destination == "A"){
            statement.setText("Going from " + location +" to " +destination);
         distance =   dijkstra(graph, 5, 0);
             newform->pickroute(loc,dest);
             statement.exec();
             desti=0;
        }
        else if(destination == "B"){
          distance =  dijkstra(graph, 5, 1);
            statement.setText("Going from " + location +" to " +destination);
             newform->pickroute(loc,dest);
             statement.exec();
              desti=1;
        }
        else if(destination == "C"){
            distance = dijkstra(graph, 5, 2);

            statement.setText("Going from " + location +" to " +destination + " " );
             newform->pickroute(loc,dest);
             statement.exec();
              desti=2;
        }
        else if(destination == "D"){
           distance = dijkstra(graph, 5, 3);
            statement.setText("Going from " + location +" to " +destination);
             newform->pickroute(loc,dest);
             statement.exec();
              desti=3;
        }
        else if(destination == "E"){
           distance = dijkstra(graph, 5, 4);
            statement.setText("Going from " + location +" to " +destination);
             newform->pickroute(loc,dest);
             statement.exec();
              desti=4;
        }else {
            error.exec();

        }


    }else{
        error.exec();
    }
    int location;
    if(carchoice == "Taxi"){
        driver = tList.returndriver(loca, graph);
        taxicar = tList.returnnearest(loca,graph);
        location = tList.returlocation(loca,graph);
        price = taxicar.getPricePerKm()*distance;

        string l;
        if(location == 0){l = "A";}
        if(location == 1){l = "B";}
        if(location == 2){l = "C";}
        if(location == 3){l = "D";}
        if(location == 4){l = "E";}
        if(location == 5){l = "F";}
//            QString namee= QString::fromStdString(name);
//             ui->name_label->setText("  "+ namee);
        ui->car_location->setText(QString::fromStdString(l));
        ui->age_driver->setText(QString::fromStdString(to_string(driver.getage())));
        ui->car_rate->setText(QString::fromStdString(to_string(taxicar.getcarrate())));
        ui->car_type->setText(QString::fromStdString(taxicar.getCarType()));
        ui->carplate->setText(QString::fromStdString(taxicar.getCarplate()));
        ui->driver_name->setText(QString::fromStdString(driver.getname()));
        ui->driver_rate->setText(QString::fromStdString(to_string(taxicar.getdriverrate())));
    }
    if(carchoice == "Ordinary Car"){
        driver = ordList.returndriver(loca,graph);
          location = ordList.returlocation(loca,graph);
        ordinarycar = ordList.returnnearest(loca,graph);
        price = ordinarycar.getPricePerKm()*distance;

        string l;
        if(location == 0){l = "A";}
        if(location == 1){l = "B";}
        if(location == 2){l = "C";}
        if(location == 3){l = "D";}
        if(location == 4){l = "E";}
        if(location == 5){l = "F";}
        ui->car_location->setText(QString::fromStdString(l));

        ui->age_driver->setText(QString::fromStdString(to_string(driver.getage())));
        ui->car_rate->setText(QString::fromStdString(to_string(ordinarycar.getcarrate())));
        ui->car_type->setText(QString::fromStdString(ordinarycar.getCarType()));
        ui->carplate->setText(QString::fromStdString(ordinarycar.getCarplate()));
        ui->driver_name->setText(QString::fromStdString(driver.getname()));
        ui->driver_rate->setText(QString::fromStdString(to_string(ordinarycar.getdriverrate())));
    }
    if(carchoice == "Luxurious Car"){
        driver = luxuriousList.returndriver(loca,graph);
        luxuriouscar = luxuriousList.returnnearest(loca,graph);
          location = luxuriousList.returlocation(loca,graph);
          price = luxuriouscar.getPricePerKm()*distance;
          string l;
          if(location == 0){l = "A";}
          if(location == 1){l = "B";}
          if(location == 2){l = "C";}
          if(location == 3){l = "D";}
          if(location == 4){l = "E";}
          if(location == 5){l = "F";}
          ui->car_location->setText(QString::fromStdString(l));

        ui->age_driver->setText(QString::fromStdString(to_string(driver.getage())));
        ui->car_rate->setText(QString::fromStdString(to_string(luxuriouscar.getcarrate())));
        ui->car_type->setText(QString::fromStdString(luxuriouscar.getCarType()));
        ui->carplate->setText(QString::fromStdString(luxuriouscar.getCarplate()));
        ui->driver_name->setText(QString::fromStdString(driver.getname()));
        ui->driver_rate->setText(QString::fromStdString(to_string(luxuriouscar.getdriverrate())));
    }
    int time = distance/2;
    ui->time->setText(QString::fromStdString(to_string(time)));
    ui->distance_label->setText(QString::fromStdString(to_string(distance)));
    ui->price_trip->setText(QString::fromStdString(to_string(price)));
    distancee = distance;
}

void original_map::on_confirm_trip_clicked()
{
 payment_window* newform = new payment_window;

 newform->setfee(price);
 newform->setdistance(distancee);
 newform->show();
}
