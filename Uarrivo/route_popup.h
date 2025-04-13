#ifndef ROUTE_POPUP_H
#define ROUTE_POPUP_H

#include <QMainWindow>
#include <iostream>
#include <string>
using namespace std;

namespace Ui {
class route_popup;
}

class route_popup : public QMainWindow
{
    Q_OBJECT

public:
    explicit route_popup(QWidget *parent = nullptr);
    ~route_popup();
   void pickroute(string a, string b);
  // static void sendroute (string loc, string dest);
;
private:
    Ui::route_popup *ui;
    string b1, b2;
};

#endif // ROUTE_POPUP_H
