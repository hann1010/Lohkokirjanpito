#ifndef TOIMINPITEET_H
#define TOIMINPITEET_H

#include <QDialog>
#include "login.h" // !
namespace Ui {
class Toiminpiteet;
}

class Toiminpiteet : public QDialog
{
    Q_OBJECT

public:
    explicit Toiminpiteet(QWidget *parent = 0);
    ~Toiminpiteet();

private slots:
    void on_pushButton_upd_list_clicked();

    void on_dateEdit_perusmuokkaus_userDateChanged(const QDate &date);

    void on_dateEdit_kylvomuokkaus_userDateChanged(const QDate &date);



    void on_dateEdit_kylvo_userDateChanged(const QDate &date);

    void on_dateEdit_korj1_userDateChanged(const QDate &date);

    void on_dateEdit_korj2_userDateChanged(const QDate &date);

    void on_dateEdit_vilj_Tounta_paiva_userDateChanged(const QDate &date);

    void on_dateEdit_vilj_Tounta_paiva2_userDateChanged(const QDate &date);

    void on_dateEdit_vilj_Tounta_paiva3_userDateChanged(const QDate &date);

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_paivita_clicked();

    void on_pushButton_filter_clicked();



private:
    Ui::Toiminpiteet *ui;
};

#endif // TOIMINPITEET_H
