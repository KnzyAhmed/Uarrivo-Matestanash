#include "service_choice.h"
#include "ui_service_choice.h"
#include <iostream>
#include "customer.h"
#include <QMessageBox>
#include <string>
#include "original_map.h"
#include "ui_modify_info.h"
#include "modify_info.h"

using namespace std;

service_choice::service_choice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::service_choice)
{
    ui->setupUi(this);
    string name;
    name = customer::returnname();
    QString namee= QString::fromStdString(name);
     ui->name_label->setText("  "+ namee);
}

service_choice::~service_choice()
{
    delete ui;
}

void service_choice::on_restaurantdelivery_button_clicked()
{

}

void service_choice::on_carreserving_button_clicked()
{
    original_map *newform = new original_map;
    newform->open();
    //this->hide();
}

void service_choice::on_profile_modify_clicked()
{

    modify_info *newform = new modify_info;
    newform->show();

}
