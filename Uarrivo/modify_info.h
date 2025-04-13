#ifndef MODIFY_INFO_H
#define MODIFY_INFO_H

#include <QMainWindow>

namespace Ui {
class modify_info;
}

class modify_info : public QMainWindow
{
    Q_OBJECT

public:
    explicit modify_info(QWidget *parent = nullptr);
    ~modify_info();

private slots:
    void on_modify_fname_clicked();

    void on_modify_lname_clicked();

    void on_modify_phone_clicked();

    void on_modify_pass_clicked();

    void on_setcreditcard_clicked();

private:
    Ui::modify_info *ui;
};

#endif // MODIFY_INFO_H
