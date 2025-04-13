#ifndef SERVICE_CHOICE_H
#define SERVICE_CHOICE_H

#include <QDialog>

namespace Ui {
class service_choice;
}

class service_choice : public QDialog
{
    Q_OBJECT

public:
    explicit service_choice(QWidget *parent = nullptr);
    ~service_choice();

private slots:
    void on_restaurantdelivery_button_clicked();

    void on_carreserving_button_clicked();

    void on_profile_modify_clicked();

private:
    Ui::service_choice *ui;
};

#endif // SERVICE_CHOICE_H
