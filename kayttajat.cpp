#include "kayttajat.h"
#include "ui_kayttajat.h"
#include <QMessageBox>
#include <QDateEdit>
#include <QDate>



Kayttajat::Kayttajat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Kayttajat)
{
    ui->setupUi(this);
    Kayttajat::on_pushButton_Update_list_clicked();

}

Kayttajat::~Kayttajat()
{
    delete ui;

}


void Kayttajat::on_pushButton_Update_list_clicked()
{

    Login conn;
    QSqlQueryModel * modal=new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery* qry=new QSqlQuery(conn.myDB);
    qry->prepare("select  rowID,kayttaja,etunimi,sukunimi from users "); // * tai ID,user,role sen mukaan mitkä kaikki halutaan taulukkoon
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);

    conn.connClose();
    qDebug() << (modal->rowCount());

}



void Kayttajat::on_tableView_activated(const QModelIndex &index)
{

    QString val=ui->tableView->model()->data(index).toString();
   int va3=ui->tableView->model()->rowCount();

    qDebug () << va3;

   Login conn;
   conn.connOpen();
   if(!conn.connOpen())
   {
       qDebug () <<"Falied to open the database";
       return;
   }

   conn.connOpen();
       QSqlQuery qry;
       qry.prepare("select * from users where rowID='"+val+"'  ");

       if (qry.exec())
       {

           while (qry.next())
           {

           ui->lineEdit_ID->setText(val);
          // ui->lineEdit_ID->setText(qry.value(0).toString());
           ui->lineEdit_Kayttaja->setText(qry.value(1).toString());
           ui->lineEdit_Etu_Nimi->setText(qry.value(2).toString());
           ui->lineEdit_Suku_Nimi->setText(qry.value(3).toString());
           ui->lineEdit_Salasana->setText(qry.value(4).toString());
           ui->comboBox_Rooli->setEditText(qry.value(5).toString());
           ui->lineEdit_Luotu->setText(qry.value(6).toString());
           ui->lineEdit_Muokattu->setText(qry.value(7).toString());

           }
           conn.connClose();

       }
       else
       {
          QMessageBox::critical(this,tr("Error::"),qry.lastError().text());


       }
}




void Kayttajat::on_pushButton_Uusi_clicked()
{
    QDate date=QDate::currentDate();
    QTime time=QTime::currentTime();
    QString date_txt=date.toString("dd.MM.yyyy");
    QString time_txt=time.toString("hh.mm.ss");
    ui->lineEdit_Luotu->setText(date_txt+"  "+time_txt);
    ui->lineEdit_Muokattu->setText("");





     QString ID, user, etuNim, sukuNi, Pass, rooli, luotu, muokattu ;
     ID=ui->lineEdit_ID->text();
     user=ui->lineEdit_Kayttaja->text();
     etuNim=ui->lineEdit_Etu_Nimi->text();
     sukuNi=ui->lineEdit_Suku_Nimi->text();
     Pass=ui->lineEdit_Salasana->text();
     rooli=ui->comboBox_Rooli->currentText();
     luotu=ui->lineEdit_Luotu->text();
     muokattu=ui->lineEdit_Muokattu->text();

     Login conn;
     conn.connOpen();
     if(!conn.connOpen()){
         qDebug () <<"Falied to open the database";
         return;
    }
   //  connOpen();
     QSqlQuery qry;
     qry.prepare("insert into users ( kayttaja, EtuNimi, SukuNimi, SalaSana, Rooli, LuontiPaiva, PaivitysPaiva  ) values('"+user+"','"+etuNim+"','"+sukuNi+"','"+Pass+"','"+rooli+"','"+luotu+"','"+muokattu+"')");

     if (qry.exec())
     {
      QMessageBox::information(this,tr("Tietokanta"),tr("Tiedot tallennettu"));
      conn.connClose();

     }
     else
     {
        QMessageBox::critical(this,tr("Error"),qry.lastError().text());


     }


     Kayttajat::on_pushButton_Update_list_clicked();
}

void Kayttajat::on_pushButton_Paivita_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("Tietokanta"),"Haluatko varmasi päivittää tiedot?",
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes)
  {

    QDate date=QDate::currentDate();
    QTime time=QTime::currentTime();
    QString date_txt=date.toString("dd.MM.yyyy");
    QString time_txt=time.toString("hh.mm.ss");
    ui->lineEdit_Muokattu->setText(date_txt+"  "+time_txt);

    QString ID, user, etuNim, sukuNi, Pass, rooli, luotu, muokattu ;
    ID=ui->lineEdit_ID->text();
    user=ui->lineEdit_Kayttaja->text();
    etuNim=ui->lineEdit_Etu_Nimi->text();
    sukuNi=ui->lineEdit_Suku_Nimi->text();
    Pass=ui->lineEdit_Salasana->text();
    rooli=ui->comboBox_Rooli->currentText();
    luotu=ui->lineEdit_Luotu->text();
    muokattu=ui->lineEdit_Muokattu->text();

    if (ID == "" )
    {
        QMessageBox::critical(this,tr("Virhe"),tr("rowID on tyhjä ei voi päivittää. Lataa listalta uudelleen ja päivitä"));
    }
    else
    {



    Login conn;
    conn.connOpen();
    if(!conn.connOpen()){
        qDebug () <<"Falied to open the database";
        return;
   }
  //  connOpen();
    QSqlQuery qry;
    qry.prepare("update users set kayttaja='"+user+"',EtuNimi='"+etuNim+"',SukuNimi='"+sukuNi+"',SalaSana='"+Pass+"',Rooli='"+rooli+"',LuontiPaiva='"+luotu+"',PaivitysPaiva='"+muokattu+"' where rowID='"+ID+"'  ");

    if (qry.exec())
    {
     QMessageBox::information(this,tr("Tietokanta"),tr("Tiedot päivitetty"));
     conn.connClose();

    }
    else
    {
       QMessageBox::critical(this,tr("Error"),qry.lastError().text());


    }
  // Kayttajat::on_pushButton_Update_list_clicked();
  }
 }
}
void Kayttajat::on_comboBox_Rooli_currentTextChanged(const QString &arg1)
{
    QString roolitxt=ui->comboBox_Rooli->currentText();
   // ui->lineEdit_rooli->setText(roolitxt);
}

void Kayttajat::on_pushButton_clicked()
{
    QString ID;
    ID=ui->lineEdit_ID->text();

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("Tietokanta"),"Haluatko varmasi poistaa rivin: "+ID+"?",
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes)
  {



    Login conn;
    conn.connOpen();
    if(!conn.connOpen()){
        qDebug () <<"Falied to open the database";
        return;
    }
 //     conn.connOpen();
    QSqlQuery qry;
    qry.prepare("Delete from users  where rowID='"+ID+"'");

    if (qry.exec())
    {
     QMessageBox::information(this,tr("Tietokanta"),tr("Poistettu tietokannasta"));
     conn.connClose();

    }
    else
    {
       QMessageBox::critical(this,tr("Error"),qry.lastError().text());
    }
  Kayttajat::on_pushButton_Update_list_clicked();
  }
}


