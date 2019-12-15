#ifndef LOHKONTIEDOT_H
#define LOHKONTIEDOT_H

#include <QDialog>
#include "login.h" // !

namespace Ui {
class Lohkontiedot;
}

class Lohkontiedot : public QDialog
{
    Q_OBJECT

public:
    explicit Lohkontiedot(QWidget *parent = 0);
    ~Lohkontiedot();

private slots:

    void on_pushButton_Upd_List_clicked();

    void on_pushButton_Filter_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_paivita_clicked();


    void on_pushButton_Uusi_clicked();

    void on_pushButton_poista_clicked();

private:
    Ui::Lohkontiedot *ui;
};

#endif // LOHKONTIEDOT_H
