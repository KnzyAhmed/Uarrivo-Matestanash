#ifndef PAYMENT_WINDOW_H
#define PAYMENT_WINDOW_H

#include <QDialog>

namespace Ui {
class payment_window;
}

class payment_window : public QDialog
{
    Q_OBJECT

public:
    explicit payment_window(QWidget *parent = nullptr);
    ~payment_window();
    void setdistance(int);
    void setfee(int);

private slots:
    void on_walletmoney_clicked();

    void on_creditcard_clicked();
    void on_cash_clicked();

private:
    Ui::payment_window *ui;
    int pricetopay;
    int distance;
};

#endif // PAYMENT_WINDOW_H
