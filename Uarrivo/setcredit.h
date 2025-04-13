#ifndef SETCREDIT_H
#define SETCREDIT_H

#include <QDialog>

namespace Ui {
class setCredit;
}

class setCredit : public QDialog
{
    Q_OBJECT

public:
    explicit setCredit(QWidget *parent = nullptr);
    ~setCredit();

private slots:
    void on_confirmationbutton_clicked();

private:
    Ui::setCredit *ui;
};

#endif // SETCREDIT_H
