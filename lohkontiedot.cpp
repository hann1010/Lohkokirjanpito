#include "lohkontiedot.h"
#include "ui_lohkontiedot.h"
#include <QMessageBox>
#include <QDateEdit>
#include <QDate>

Lohkontiedot::Lohkontiedot(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Lohkontiedot)
{
    ui->setupUi(this);
    Lohkontiedot::on_pushButton_Upd_List_clicked();
}

Lohkontiedot::~Lohkontiedot() // !
{
    delete ui;
}


void Lohkontiedot::on_pushButton_Upd_List_clicked()
{
    QDate date=QDate::currentDate();
    QString date_txt=date.toString("yyyy");

    Login conn;
    QSqlQueryModel * modal=new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery* qry=new QSqlQuery(conn.myDB);
    qry->prepare("select  rowID,dKasvulohkoNimi AS 'Lohkon nimi',dKasvulohkonTunnus AS 'Lohkon tunnus',dVuosi AS 'Vuosi',dSuunViljKasvilaji AS 'Suun Kasvilaji',dSuunViljLajike AS 'Suun Laijke',dToimViljKasvil AS 'Toim Kasvilaji' from kortit where dVuosi like'%"+date_txt+"%' "); // * tai ID,user,role sen mukaan mitkä kaikki halutaan taulukkoon
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);

    conn.connClose();
    qDebug() << (modal->rowCount());
}



void Lohkontiedot::on_pushButton_Filter_clicked()
{
    QString Filtertxt;
    Filtertxt=ui->lineEdit_Filter->text();
    QString filterinfo=ui->comboBox_filter->currentText();

    Login conn;
    QSqlQueryModel * modal=new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery* qry=new QSqlQuery(conn.myDB);


    if (filterinfo==("Rivi nro"))
    {
    qry->prepare("select  rowID,dKasvulohkoNimi,dKasvulohkonTunnus,dVuosi,dToimViljKasvil,dToimViljLajike,dSuunViljKasvilaji from kortit where rowID like'%"+Filtertxt+"%'");
    qDebug () <<("haku 1.");  // !
    qDebug () <<(Filtertxt);  // !
    }

    if (filterinfo==("Lohkon nimi"))
    {
    qry->prepare("select  rowID,dKasvulohkoNimi,dKasvulohkonTunnus,dVuosi,dToimViljKasvil,dToimViljLajike,dSuunViljKasvilaji from kortit where dKasvulohkoNimi like'%"+Filtertxt+"%'");
    qDebug () <<("haku 2.");  // !
    qDebug () <<(Filtertxt);  // !
    }

    if (filterinfo==("Lohkontunnus"))
    {
    qry->prepare("select  rowID,dKasvulohkoNimi,dKasvulohkonTunnus,dVuosi,dToimViljKasvil,dToimViljLajike,dSuunViljKasvilaji from kortit where dKasvulohkonTunnus like'%"+Filtertxt+"%'");
    qDebug () <<("haku 3.");  // !
    qDebug () <<(Filtertxt);  // !
    }

    if (filterinfo==("Laji"))
    {
    qry->prepare("select  rowID,dKasvulohkoNimi,dKasvulohkonTunnus,dVuosi,dToimViljKasvil,dToimViljLajike,dSuunViljKasvilaji from kortit where dToimViljKasvil like'%"+Filtertxt+"%'");
    qDebug () <<("haku 4.");  // !
    qDebug () <<(Filtertxt);  // !
    }

    if (filterinfo==("Lajike"))
    {
    qry->prepare("select  rowID,dKasvulohkoNimi,dKasvulohkonTunnus,dVuosi,dToimViljKasvil,dToimViljLajike,dSuunViljKasvilaji from kortit where dToimViljLajike like'%"+Filtertxt+"%'");
    qDebug () <<("haku 5.");  // !
    qDebug () <<(Filtertxt);  // !
    }
    if (filterinfo==("Vuosi"))
    {
    qry->prepare("select  rowID,dKasvulohkoNimi,dKasvulohkonTunnus,dVuosi,dToimViljKasvil,dToimViljLajike,dSuunViljKasvilaji from kortit where dVuosi like'%"+Filtertxt+"%'");
    qDebug () <<("haku 6.");  // !
    qDebug () <<(Filtertxt);  // !
    }
    qry->exec();

    modal->setQuery(*qry);
    ui->tableView->setModel(modal);

    conn.connClose();
    qDebug() << (modal->rowCount());
}

void Lohkontiedot::on_tableView_activated(const QModelIndex &index)
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
       qry.prepare("select * from kortit where rowID='"+val+"'  ");

       if (qry.exec())
       {

           while (qry.next())
           {

           ui->rowIDLineEdit->setText(val);
           ui->ssLineEdit_Tila->setText(qry.value(0).toString());
           ui->tilatunnusLineEdit->setText(qry.value(1).toString());
           ui->vuosiLineEdit->setText(qry.value(2).toString());
           ui->kasvulohkonNimiLineEdit->setText(qry.value(3).toString());
           ui->kasvulohkonTunnuusLineEdit->setText(qry.value(4).toString());
           ui->tutkimusvuosiLineEdit->setText(qry.value(5).toString());
           ui->multavuusLineEdit->setText(qry.value(6).toString());
           ui->kalsiumCaLukuLineEdit->setText(qry.value(7).toString());
           ui->kaliumKLukuLineEdit->setText(qry.value(8).toString());
           ui->booriBLukuLineEdit->setText(qry.value(9).toString());
           ui->sinkkiZnLukuLineEdit->setText(qry.value(10).toString());
           ui->pintaAlaLineEdit->setText(qry.value(11).toString());
           ui->maalajiLineEdit->setText(qry.value(12).toString());
           ui->pHLukuLineEdit->setText(qry.value(13).toString());
           ui->fosforiPLukuLineEdit->setText(qry.value(14).toString());
           ui->mangnesiumMgLukuLineEdit->setText(qry.value(15).toString());
           ui->kupariCuLukuLineEdit->setText(qry.value(16).toString());


           }
           conn.connClose();

       }
       else
       {
          QMessageBox::critical(this,tr("Error::"),qry.lastError().text());


       }
}

void Lohkontiedot::on_pushButton_paivita_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("Tietokanta"),"Haluatko varmasi päivittää tiedot?",
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes)
  {



    QString ID, Tila, tilatunnus, vuosi, kasvulohkonNimi, kasvulohkonTunnus, TutkimVuosi, Multavuus, kalsium, kalium, boori, sinkki, pintaAla, maalaji, PHluku, fosfori, magnesium, kupari  ;

    ID=ui->rowIDLineEdit->text();
    Tila=ui->ssLineEdit_Tila->text();
    tilatunnus=ui->tilatunnusLineEdit->text();
    vuosi=ui->vuosiLineEdit->text();
    kasvulohkonNimi=ui->kasvulohkonNimiLineEdit->text();
    kasvulohkonTunnus=ui->kasvulohkonTunnuusLineEdit->text();
    TutkimVuosi=ui->tutkimusvuosiLineEdit->text();
    Multavuus=ui->multavuusLineEdit->text();
    kalsium=ui->kalsiumCaLukuLineEdit->text();
    kalium=ui->kaliumKLukuLineEdit->text();
    boori=ui->booriBLukuLineEdit->text();
    sinkki=ui->sinkkiZnLukuLineEdit->text();
    pintaAla=ui->pintaAlaLineEdit->text();
    maalaji=ui->maalajiLineEdit->text();
    PHluku=ui->pHLukuLineEdit->text();
    fosfori=ui->fosforiPLukuLineEdit->text();
    magnesium=ui->mangnesiumMgLukuLineEdit->text();
    kupari=ui->kupariCuLukuLineEdit->text();

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
    qry.prepare("update kortit set dTilanNimi='"+Tila+"',dTilaTunnus='"+tilatunnus+"',dVuosi='"+vuosi+"',dKasvulohkoNimi='"+kasvulohkonNimi+"',dKasvulohkonTunnus='"+kasvulohkonTunnus+"',dTutkimusVuosi='"+TutkimVuosi+"',"
                                             " dMultavuus='"+Multavuus+"', dKalsium='"+kalsium+"',dKalium='"+kalium+"', "
                                                "dBoori='"+boori+"',dSinkki='"+sinkki+"', dPintaAla='"+pintaAla+"',dMaalaji='"+maalaji+"',       "
                                                    "dPHluku='"+PHluku+"',dFosfori='"+fosfori+"', dMagnesium='"+magnesium+"',dKupari='"+kupari+"'  where rowID='"+ID+"'  ");

    if (qry.exec())
    {
     QMessageBox::information(this,tr("Tietokanta"),tr("Tiedot päivitetty"));
     conn.connClose();

    }
    else
    {
       QMessageBox::critical(this,tr("Error"),qry.lastError().text());


    }
// Lohkontiedot::on_pushButton_Upd_List_clicked();
  }
 }
}



void Lohkontiedot::on_pushButton_Uusi_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("Tietokanta"),"Haluatko varmasi luoda uuden?",
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes)
  {

    QDate date=QDate::currentDate();

    QString date_txt=date.toString("yyyy");
    ui->vuosiLineEdit->setText(date_txt);

    QString ID, Tila, tilatunnus, vuosi, kasvulohkonNimi, kasvulohkonTunnus, TutkimVuosi, Multavuus, kalsium, kalium, boori, sinkki, pintaAla, maalaji, PHluku, fosfori, magnesium, kupari  ;

    ID=ui->rowIDLineEdit->text();
    Tila=ui->ssLineEdit_Tila->text();
    tilatunnus=ui->tilatunnusLineEdit->text();
    vuosi=ui->vuosiLineEdit->text();
    kasvulohkonNimi=ui->kasvulohkonNimiLineEdit->text();
    kasvulohkonTunnus=ui->kasvulohkonTunnuusLineEdit->text();
    TutkimVuosi=ui->tutkimusvuosiLineEdit->text();
    Multavuus=ui->multavuusLineEdit->text();
    kalsium=ui->kalsiumCaLukuLineEdit->text();
    kalium=ui->kaliumKLukuLineEdit->text();
    boori=ui->booriBLukuLineEdit->text();
    sinkki=ui->sinkkiZnLukuLineEdit->text();
    pintaAla=ui->pintaAlaLineEdit->text();
    maalaji=ui->maalajiLineEdit->text();
    PHluku=ui->pHLukuLineEdit->text();
    fosfori=ui->fosforiPLukuLineEdit->text();
    magnesium=ui->mangnesiumMgLukuLineEdit->text();
    kupari=ui->kupariCuLukuLineEdit->text();

    Login conn;
    conn.connOpen();
    if(!conn.connOpen()){
        qDebug () <<"Falied to open the database";
        return;
   }
  //  connOpen();
    QSqlQuery qry;
    qry.prepare("insert into kortit ( dTilanNimi, dTilaTunnus, dVuosi, dKasvulohkoNimi, dKasvulohkonTunnus, dTutkimusVuosi, dMultavuus, dKalsium, dKalium, dBoori, dSinkki, dPintaAla, "
                " dMaalaji, dPHluku, dFosfori, dMagnesium, dKupari  ) "
                " values('"+Tila+"','"+tilatunnus+"','"+vuosi+"','"+kasvulohkonNimi+"','"+kasvulohkonTunnus+"','"+TutkimVuosi+"','"+Multavuus+"','"+kalsium+"', "
                      " '"+kalium+"','"+boori+"','"+sinkki+"','"+pintaAla+"','"+maalaji+"','"+PHluku+"','"+fosfori+"','"+magnesium+"','"+kupari+"')");

    if (qry.exec())
    {
     QMessageBox::information(this,tr("Tietokanta"),tr("Tiedot tallennettu vuodeksi asetettu: ")+ vuosi);
     Lohkontiedot::on_pushButton_Upd_List_clicked();
     conn.connClose();

    }
    else
    {
       QMessageBox::critical(this,tr("Error"),qry.lastError().text());


    }
  }
}

void Lohkontiedot::on_pushButton_poista_clicked()
{
    QString ID;
    ID=ui->rowIDLineEdit->text();



    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("Tietokanta"),"Haluatko varmasi poistaa rivin: "+ID+"?" ,
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
    qry.prepare("Delete from kortit  where rowID='"+ID+"'");

    if (qry.exec())
    {
     QMessageBox::information(this,tr("Tietokanta"),tr("Poistettu tietokannasta"));
     conn.connClose();

    }
    else
    {
       QMessageBox::critical(this,tr("Error"),qry.lastError().text());
    }
 // Kayttajat::on_pushButton_Update_list_clicked();
  }
}
