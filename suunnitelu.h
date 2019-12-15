#ifndef SUUNNITELU_H
#define SUUNNITELU_H

#include <QDialog>
#include "login.h" // !
namespace Ui {
class Suunnitelu;
}

class Suunnitelu : public QDialog
{
    Q_OBJECT

public:
    explicit Suunnitelu(QWidget *parent = 0);
    ~Suunnitelu();

private slots:


    void on_pushButton_upd_list_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_paivita_clicked();

    void on_pushButton_filter_clicked();

private:
    Ui::Suunnitelu *ui;
};

#endif // SUUNNITELU_H
