#include "route_popup.h"
#include "ui_route_popup.h"

route_popup::route_popup(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::route_popup)
{
    ui->setupUi(this);


}



route_popup::~route_popup()
{
    delete ui;
}


void route_popup::pickroute(string a, string b){

    b1 = a;
    b2 = b;
    if(b1 == "A" && b2 == "B"){
    QPixmap mapp("C:/Users/kenzy/Dropbox/My PC (DESKTOP-R153SN6)/Downloads/A to B fastest route.PNG");
         ui->mappic->setPixmap(mapp);
        }
    if(b1 == "A" && b2 == "C"){
    QPixmap mapp("C:/Users/kenzy/Dropbox/My PC (DESKTOP-R153SN6)/Downloads/A to C fastest route.PNG");
        ui->mappic->setPixmap(mapp);
    }
    if(b1 == "A" && b2 == "D"){
        QPixmap mapp("C:/Users/kenzy/Dropbox/My PC (DESKTOP-R153SN6)/Downloads/A to D fastest route.PNG");
        ui->mappic->setPixmap(mapp);
        }
    if(b1 == "A" && b2 == "E"){
        QPixmap mapp("C:/Users/kenzy/Dropbox/My PC (DESKTOP-R153SN6)/Downloads/A to E fastest route.PNG");
        ui->mappic->setPixmap(mapp);
        }
    if(b1 == "A" && b2 == "F"){
        QPixmap mapp("C:/Users/kenzy/Dropbox/My PC (DESKTOP-R153SN6)/Downloads/A to F fastest route.PNG");
        ui->mappic->setPixmap(mapp);
        }
    if(b1 == "B" && b2 == "A"){
        QPixmap mapp("C:/Users/kenzy/Dropbox/My PC (DESKTOP-R153SN6)/Downloads/B to A fastest route.PNG");
        ui->mappic->setPixmap(mapp);
        }
    if(b1 == "B" && b2 =="C"){
        QPixmap mapp("C:/Users/kenzy/Dropbox/My PC (DESKTOP-R153SN6)/Downloads/B to C fastest route.PNG");
        ui->mappic->setPixmap(mapp);
        }
    if(b1 == "B" && b2 == "D"){
        QPixmap mapp("C:/Users/kenzy/Dropbox/My PC (DESKTOP-R153SN6)/Downloads/B to D fastest route.PNG");
        ui->mappic->setPixmap(mapp);
        }
    if(b1 == "B" && b2 == "E"){
        QPixmap mapp("C:/Users/kenzy/Dropbox/My PC (DESKTOP-R153SN6)/Downloads/E to B fastest route.PNG");
        ui->mappic->setPixmap(mapp);
        }
    if(b1 == "B" && b2 =="F"){
        QPixmap mapp("C:/Users/kenzy/Dropbox/My PC (DESKTOP-R153SN6)/Downloads/B to F fastest route.PNG");
        ui->mappic->setPixmap(mapp);
        }
    if(b1 == "C" && b2 =="A"){
        QPixmap mapp("C:/Users/kenzy/Dropbox/My PC (DESKTOP-R153SN6)/Downloads/C to A fastest route.PNG");
        ui->mappic->setPixmap(mapp);
        }
    if(b1 == "C" && b2 == "B"){
        QPixmap mapp("C:/Users/kenzy/Dropbox/My PC (DESKTOP-R153SN6)/Downloads/C to B fastest route.PNG");
        ui->mappic->setPixmap(mapp);
        }
    if(b1 == "C" && b2 == "D"){
        QPixmap mapp("C:/Users/kenzy/Dropbox/My PC (DESKTOP-R153SN6)/Downloads/C to D fastest route.PNG");
        ui->mappic->setPixmap(mapp);
        }
    if(b1 == "C" && b2 == "E"){
        QPixmap mapp("C:/Users/kenzy/Dropbox/My PC (DESKTOP-R153SN6)/Downloads/C to E fastest route.PNG");
        ui->mappic->setPixmap(mapp);
        }
    if(b1 == "C" && b2 == "F"){
        QPixmap mapp("C:/Users/kenzy/Dropbox/My PC (DESKTOP-R153SN6)/Downloads/C to F fastest route.PNG");
        ui->mappic->setPixmap(mapp);
        }
    if(b1 == "D" && b2 == "A"){
        QPixmap mapp("C:/Users/kenzy/Dropbox/My PC (DESKTOP-R153SN6)/Downloads/D to A fastest route.PNG");
        ui->mappic->setPixmap(mapp);
        }
    if(b1 == "D" && b2 == "B"){
        QPixmap mapp("C:/Users/kenzy/Dropbox/My PC (DESKTOP-R153SN6)/Downloads/D to B fastest route.PNG");
        ui->mappic->setPixmap(mapp);
        }
    if(b1 == "D" && b2 == "C"){
        QPixmap mapp("C:/Users/kenzy/Dropbox/My PC (DESKTOP-R153SN6)/Downloads/D to C fastest route.PNG");
        ui->mappic->setPixmap(mapp);
        }
    if(b1 == "D" && b2 == "E"){
        QPixmap mapp("C:/Users/kenzy/Dropbox/My PC (DESKTOP-R153SN6)/Downloads/D to E fastest route.PNG");
        ui->mappic->setPixmap(mapp);
        }
    if(b1 == "D" && b2 == "F"){
        QPixmap mapp("C:/Users/kenzy/Dropbox/My PC (DESKTOP-R153SN6)/Downloads/D to F fastest route.PNG");
        ui->mappic->setPixmap(mapp);
        }
    if(b1 == "E" && b2 == "A"){
        QPixmap mapp("C:/Users/kenzy/Dropbox/My PC (DESKTOP-R153SN6)/Downloads/E to A fastest route.PNG");
        ui->mappic->setPixmap(mapp);
        }
    if(b1 == "E" && b2 == "B"){
        QPixmap mapp("C:/Users/kenzy/Dropbox/My PC (DESKTOP-R153SN6)/Downloads/E to B fastest route.PNG");
        ui->mappic->setPixmap(mapp);
        }
    if(b1 == "E" && b2 == "C"){
        QPixmap mapp("C:/Users/kenzy/Dropbox/My PC (DESKTOP-R153SN6)/Downloads/E to C fastest route.PNG");
        ui->mappic->setPixmap(mapp);
        }
    if(b1 == "E" && b2 == "D"){
        QPixmap mapp("C:/Users/kenzy/Dropbox/My PC (DESKTOP-R153SN6)/Downloads/E to D fastest route.PNG");
        ui->mappic->setPixmap(mapp);
        }
    if(b1 == "E" && b2 == "F"){
        QPixmap mapp("C:/Users/kenzy/Dropbox/My PC (DESKTOP-R153SN6)/Downloads/E to F fastest route.PNG");
        ui->mappic->setPixmap(mapp);
        }
    if(b1 == "F" && b2 == "A"){
        QPixmap mapp("C:/Users/kenzy/Dropbox/My PC (DESKTOP-R153SN6)/Downloads/F to A fastest route.PNG");
        ui->mappic->setPixmap(mapp);
        }
    if(b1 == "F" && b2 == "B"){
        QPixmap mapp("C:/Users/kenzy/Dropbox/My PC (DESKTOP-R153SN6)/Downloads/F to B fastest route.PNG");
        ui->mappic->setPixmap(mapp);
        }
    if(b1 == "F" && b2 == "C"){
        QPixmap mapp("C:/Users/kenzy/Dropbox/My PC (DESKTOP-R153SN6)/Downloads/F to C fastest route.PNG");
        ui->mappic->setPixmap(mapp);
        }
    if(b1 == "F" && b2 == "D"){
        QPixmap mapp("C:/Users/kenzy/Dropbox/My PC (DESKTOP-R153SN6)/Downloads/F to D fastest route.PNG");
        ui->mappic->setPixmap(mapp);
        }
    if(b1 == "F" && b2 == "E"){
        QPixmap mapp("C:/Users/kenzy/Dropbox/My PC (DESKTOP-R153SN6)/Downloads/F to E fastest route.PNG");
        ui->mappic->setPixmap(mapp);
        }
    this->show();
}
//void route_popup::sendroute(string loc, string dest){
//    pickroute(loc,dest);
//}

//PUT INTO BUTTON CODE
//map_popup *newform = new map_popup;
//newform->takechars('A','C');
//newform->show();
