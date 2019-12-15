#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QtSql>  // !
#include <QDebug> // !
#include <QFileInfo> // !
#include "lohkontiedot.h"
#include "suunnitelu.h"
#include "toiminpiteet.h"
#include "kayttajat.h"

namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    QSqlDatabase myDB; // !
    void connClose()
    {
       myDB.close();
       myDB.removeDatabase(QSqlDatabase::defaultConnection);
       qDebug () <<("close the database");  // !
    }
    bool connOpen()
    {
        myDB = QSqlDatabase ::addDatabase("QSQLITE");  // !
        myDB.setDatabaseName("...");  // path to sqlite file

        if (!myDB.open())
            {
            qDebug () <<("failed open the database"); // !
            return false;
            }
        else
        {
            qDebug () <<("open the database");  // !
            return true;
        }
    }

    explicit Login(QWidget *parent = 0);
    ~Login();

private slots:
    void on_actionTietoja_triggered();

    void on_actionLopeta_triggered();

    void on_pushButton_Lohkontiedot_clicked();

    void on_pushButton_Suunnittelu_clicked();

    void on_pushButton_Toiminpiteet_clicked();

    void on_pushButton_Login_Delete_clicked();

    void on_pushButton_Kayttajat_clicked();

    void on_pushButton_Login_clicked();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
