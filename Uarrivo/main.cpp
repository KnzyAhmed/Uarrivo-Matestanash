#include "customer.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    customer w;
    w.show();
    return a.exec();
}
