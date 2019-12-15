#include "login.h"
#include "ui_login.h"
#include <QMessageBox>



Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->pushButton_Kayttajat->hide();
    ui->pushButton_Lohkontiedot->hide();
    ui->pushButton_Suunnittelu->hide();
    ui->pushButton_Toiminpiteet->hide();


    if (!connOpen()) // !
        ui->label_Status->setText("Ei yhteyttä tietokantaan"); // !
    else
        ui->label_Status->setText("");  // !
}

Login::~Login()
{
    connClose();
    delete ui;
}

void Login::on_actionTietoja_triggered()
{
    QMessageBox::information(this,tr("Ohje"),tr("Lohkokirjanpito 3.00.47 \nc Hanna P \n2009-2019"));

}

void Login::on_actionLopeta_triggered()
{
    this->close();
}

void Login::on_pushButton_Lohkontiedot_clicked()
{
     Lohkontiedot lohkontiedot;
     lohkontiedot.setModal(true);
     lohkontiedot.exec();
}

void Login::on_pushButton_Suunnittelu_clicked()
{
    Suunnitelu suunnitelu;
    suunnitelu.setModal(true);
    suunnitelu.exec();

}

void Login::on_pushButton_Toiminpiteet_clicked()
{
    Toiminpiteet toiminpiteet;
    toiminpiteet.setModal(true);
    toiminpiteet.exec();
}

void Login::on_pushButton_Login_Delete_clicked()
{
    ui->lineEdit_User->setText("");
    ui->lineEdit_Pass->setText("");
    ui->label_Status->setText("Kirjauduttu ulos.");
    ui->pushButton_Kayttajat->hide();
    ui->pushButton_Lohkontiedot->hide();
    ui->pushButton_Suunnittelu->hide();
    ui->pushButton_Toiminpiteet->hide();
}

void Login::on_pushButton_Kayttajat_clicked()
{
    Kayttajat kayttajat;
    kayttajat.setModal(true);
    kayttajat.exec();
}

void Login::on_pushButton_Login_clicked()
{
    QString username, password;
    username=ui->lineEdit_User->text();
    password=ui->lineEdit_Pass->text();

if (username==(""))
{
    QMessageBox::critical(this,tr("Virhe"),tr("Kirjoita Käyttäjätunnus! "));
    ui->label_Status->setText("Kirjoita Käyttäjätunnus!");

}

    else
{

    connOpen();
    if(!myDB.isOpen()){
        qDebug () <<"Falied to open the database";
        return;
   }
  //  connOpen();
    QSqlQuery qry;
    qry.prepare("select * from users where Kayttaja='"+username +"' and Salasana='"+password+"'");

    if (qry.exec())
    {
        int count=0;
        while (qry.next())
        {
            count++;
        }
        if(count==1)
        {
         connClose();
      //  this->hide();
            ui->label_Status->setText("Käyttäjä: ["+ username + "] kirjautunut");
       //     Info info;
        //    info.setModal(true);
          //  info.exec();


            ui->pushButton_Lohkontiedot->show();
            ui->pushButton_Suunnittelu->show();
            ui->pushButton_Toiminpiteet->show();
            ui->pushButton_Kayttajat->show();

        }
        if(count<1)
        {
            ui->label_Status->setText("Käyttäjätunnus hylätty");
            QMessageBox::critical(this,tr("Virhe"),tr("Käyttäjätunnus hylätty "));
        }
        if(count>1)
        {
            ui->label_Status->setText("username and password NOT ok too many");
            QMessageBox::critical(this,tr("Virhe"),tr("Käyttäjätunnus hylätty, useita samoja tunnuksia! "));
        }
    }
    else
    {
       QMessageBox::critical(this,tr("Error"),qry.lastError().text());
       ui->label_Status->setText("Tietokantavirhe!");  // !

    }
}
}
