#ifndef KAYTTAJAT_H
#define KAYTTAJAT_H

#include <QDialog>
#include "login.h" // !

namespace Ui {
class Kayttajat;
}

class Kayttajat : public QDialog
{
    Q_OBJECT

public:

    explicit Kayttajat(QWidget *parent = 0);
    ~Kayttajat();

private slots:
    void on_pushButton_Update_list_clicked();


    void on_tableView_activated(const QModelIndex &index);



    void on_pushButton_Uusi_clicked();

    void on_pushButton_Paivita_clicked();

    void on_comboBox_Rooli_currentTextChanged(const QString &arg1);

    void on_pushButton_clicked();


private:

    Ui::Kayttajat *ui;

};

#endif // KAYTTAJAT_H
