#include "toiminpiteet.h"
#include "ui_toiminpiteet.h"
#include <QMessageBox>
#include <QDateEdit>
#include <QDate>

Toiminpiteet::Toiminpiteet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Toiminpiteet)
{
    ui->setupUi(this);
    Toiminpiteet::on_pushButton_upd_list_clicked();
    ui->dateEdit_perusmuokkaus->setDate(QDate::currentDate());
    ui->dateEdit_kylvomuokkaus->setDate(QDate::currentDate());
    ui->dateEdit_kylvo->setDate(QDate::currentDate());
    ui->dateEdit_korj1->setDate(QDate::currentDate());
    ui->dateEdit_korj2->setDate(QDate::currentDate());
    ui->lineEdit_perusmuok_paiva->setText("");
    ui->lineEdit_kylvomuok_paiva->setText("");
    ui->lineEdit_vilj_kylvpiva->setText("");
    ui->lineEdit_vilj_korj1piva->setText("");
    ui->lineEdit_vilj_korj2piva->setText("");
    ui->dateEdit_vilj_Tounta_paiva->setDate(QDate::currentDate());
    ui->dateEdit_vilj_Tounta_paiva2->setDate(QDate::currentDate());
    ui->dateEdit_vilj_Tounta_paiva3->setDate(QDate::currentDate());
    ui->lineEdit_vilj_Kavins_paiva->setText("");
    ui->lineEdit_vilj_Kavins_paiva2->setText("");
    ui->lineEdit_vilj_Kavins_paiva3->setText("");
}

Toiminpiteet::~Toiminpiteet()
{

    delete ui;
}

void Toiminpiteet::on_pushButton_upd_list_clicked()
{
    QDate date=QDate::currentDate();
    QString date_txt=date.toString("yyyy");

    Login conn;
    QSqlQueryModel * modal=new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery* qry=new QSqlQuery(conn.myDB);
    qry->prepare("select  rowID,dKasvulohkoNimi AS 'Lohkon nimi',dKasvulohkonTunnus AS 'Lohkon tunnus',dVuosi AS 'Vuosi',dSuunViljKasvilaji AS 'Suun Kasvilaji',dSuunViljLajike AS 'Suun Lajike',dToimViljKasvil AS 'Toim Kasvilaji' from kortit where dVuosi like'%"+date_txt+"%'  "); // * tai ID,user,role sen mukaan mitkä kaikki halutaan taulukkoon
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);

    conn.connClose();
    qDebug() << (modal->rowCount());
}

void Toiminpiteet::on_dateEdit_perusmuokkaus_userDateChanged(const QDate &date)
{
    ui->lineEdit_perusmuok_paiva->setText(QDateEdit(date).text());
}

void Toiminpiteet::on_dateEdit_kylvomuokkaus_userDateChanged(const QDate &date)
{
    ui->lineEdit_kylvomuok_paiva->setText(QDateEdit(date).text());
}







void Toiminpiteet::on_dateEdit_kylvo_userDateChanged(const QDate &date)
{
    ui->lineEdit_vilj_kylvpiva->setText(QDateEdit(date).text());
}

void Toiminpiteet::on_dateEdit_korj1_userDateChanged(const QDate &date)
{
    ui->lineEdit_vilj_korj1piva->setText(QDateEdit(date).text());
}

void Toiminpiteet::on_dateEdit_korj2_userDateChanged(const QDate &date)
{
    ui->lineEdit_vilj_korj2piva->setText(QDateEdit(date).text());
}

void Toiminpiteet::on_dateEdit_vilj_Tounta_paiva_userDateChanged(const QDate &date)
{
    ui->lineEdit_vilj_Kavins_paiva->setText(QDateEdit(date).text());
}

void Toiminpiteet::on_dateEdit_vilj_Tounta_paiva2_userDateChanged(const QDate &date)
{
    ui->lineEdit_vilj_Kavins_paiva2->setText(QDateEdit(date).text());
}

void Toiminpiteet::on_dateEdit_vilj_Tounta_paiva3_userDateChanged(const QDate &date)
{
    ui->lineEdit_vilj_Kavins_paiva3->setText(QDateEdit(date).text());
}

void Toiminpiteet::on_tableView_activated(const QModelIndex &index)
{
    QString val=ui->tableView->model()->data(index).toString();




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
           ui->lohkonKokoHaLineEdit->setText(qry.value(11).toString());
           ui->rowIDLineEdit->setText(val);
           ui->comboBox_perusmuok_tapa->setEditText(qry.value(71).toString());
           ui->lineEdit_perusmuok_paiva->setText(qry.value(72).toString());
           ui->comboBox_kylvomuokkaus_tapa->setEditText(qry.value(73).toString());
           ui->kasvulohkonNimiLineEdit->setText(qry.value(3).toString());
           ui->lineEdit_kylvomuok_paiva->setText(qry.value(74).toString());
           ui->comboBox_syys_kasittelu->setEditText(qry.value(75).toString());
           ui->lineEdit_typpi_lahtotaso->setText(qry.value(76).toString());
           ui->lineEdit_Tarkennus_sato->setText(qry.value(77).toString());
           ui->lineEdit_Tarkennus_oljet->setText(qry.value(78).toString());
           ui->lineEdit_Tarkennus_muut->setText(qry.value(79).toString());
           ui->lineEdit_Tarkennus_yhteensa->setText(qry.value(80).toString());
           ui->lineEdit_Tarkennus_lahtaso_fos->setText(qry.value(81).toString());
           ui->lineEdit_Tarkennus_satotavoite->setText(qry.value(83).toString());
           ui->lineEdit_Tarkennus_yht_kg->setText(qry.value(84).toString());
           ui->lineEdit_Tark_edelliselta_Vuodelta->setText(qry.value(82).toString());
           ui->Combo_Tarkennus_lannoite->setEditText(qry.value(85).toString());
           ui->lineEdit_Tarkennus_lannoite_typpi->setText(qry.value(86).toString());
           ui->Combo_Tarkennus_lannoite_2->setEditText(qry.value(87).toString());
           ui->lineEdit_Tarkennus_lannoite_typpi2->setText(qry.value(88).toString());
           ui->lineEdit_Tarkennus_lannoite_typpea_yht->setText(qry.value(89).toString());
           ui->lineEdit_Tarkennus_lannoite_fofori_yht->setText(qry.value(90).toString());
           ui->lineEdit_vilj_esikasvi->setText(qry.value(91).toString());
           ui->comboBox_vilj_kasvilaji->setEditText(qry.value(92).toString());
           ui->comboBox_vilj_lajike->setEditText(qry.value(93).toString());
           ui->comboBox_vilj_siemenmaara->setEditText(qry.value(94).toString());
           ui->lineEdit_vilj_kylvpiva->setText(qry.value(95).toString());
           ui->lineEdit_vilj_korj1piva->setText(qry.value(96).toString());
           ui->lineEdit_vilj_sato1->setText(qry.value(97).toString());
           ui->lineEdit_vilj_korj2piva->setText(qry.value(98).toString());
           ui->lineEdit_vilj_sato2->setText(qry.value(99).toString());
           ui->comboBox_vilj_Torjunta_aine->setEditText(qry.value(100).toString());
           ui->lineEdit_vilj_Torjunta_maara->setText(qry.value(101).toString());
           ui->lineEdit_vilj_Kavins_paiva->setText(qry.value(102).toString());
           ui->comboBox_vilj_Torjunta_aine2->setEditText(qry.value(103).toString());
           ui->lineEdit_vilj_Torjunta_maara2->setText(qry.value(104).toString());
           ui->lineEdit_vilj_Kavins_paiva2->setText(qry.value(105).toString());
           ui->comboBox_vilj_Torjunta_aine3->setEditText(qry.value(106).toString());
           ui->lineEdit_vilj_Torjunta_maara3->setText(qry.value(107).toString());
           ui->lineEdit_vilj_Kavins_paiva3->setText(qry.value(108).toString());
           ui->lineEdit_muut_keraajakasvi->setText(qry.value(109).toString());
           ui->comboBox_muut_kynnetaan->setEditText(qry.value(110).toString());
           ui->comboBox_muut_nurmi->setEditText(qry.value(111).toString());
           ui->lineEdit_muut_muut->setText(qry.value(112).toString());
           ui->comboBox_muut_suojakaista->setEditText(qry.value(113).toString());
           ui->textEdit_muut_havainnot->setText(qry.value(114).toString());


           }
           conn.connClose();

       }
       else
       {
          QMessageBox::critical(this,tr("Error::"),qry.lastError().text());


       }
}

void Toiminpiteet::on_pushButton_paivita_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("Tietokanta"),"Haluatko varmasi päivittää tiedot?",
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes)
  {



    QString ID, Perusmuokk_tapa, Perusmuokk_paiva, Kylvomuokk_tapa, Kylvomuokk_paiva, Syyskasittely, Typpi_lahtotaso, Tarkennus_sato, Tarkennus_oljet, Tarkennus_muut, Tarkennus_yht, Tarkennus_lah_fos ;
    QString Tarkennus_satotavoite, Tarkennus_yht_kg, Tarkennus_ed_vuodelta, Tarkennus_lannoite, Tarkennus_Lannoite_typpi, Tarkennus_lannoite2, Tarkennus_lannoite_typpi2, Tarkennus_lannoite_typpi_yht  ;
    QString Tarennus_lannoite_fosfori_yht, Vilj_esikasvi, Vilj_kasvilaji, Vilj_lajike, Vilj_siemenmaara, Vilj_kylvopaiva, Vilj_korjuu1paiva, Vilj_sato1, Vilj_korjuu2paiva, Vilj_sato2, Vilj_torjunta_aine  ;
    QString Vilj_torjunta_maara, Vilj_Kavins_paiva, Vilj_torjunta_aine2, Vilj_torjunta_maara2, Vilj_Kavins_paiva2, Vilj_torjunta_aine3, Vilj_torjunta_maara3, Vilj_Kavins_paiva3, Muut_keraajakasvi ;
    QString Muut_kynnetaan, Muut_nurmi, Muut_muut, Muut_suojakaista, Muut_havainnot ;


    ID=ui->rowIDLineEdit->text();

    Perusmuokk_tapa=ui->comboBox_perusmuok_tapa->currentText();
    Perusmuokk_paiva=ui->lineEdit_perusmuok_paiva->text();
    Kylvomuokk_tapa=ui->comboBox_kylvomuokkaus_tapa->currentText();
    Kylvomuokk_paiva=ui->lineEdit_kylvomuok_paiva->text();
    Syyskasittely=ui->comboBox_syys_kasittelu->currentText();
    Typpi_lahtotaso=ui->lineEdit_typpi_lahtotaso->text();
    Tarkennus_sato=ui->lineEdit_Tarkennus_sato->text();
    Tarkennus_oljet=ui->lineEdit_Tarkennus_oljet->text();
    Tarkennus_muut=ui->lineEdit_Tarkennus_muut->text();
    Tarkennus_yht=ui->lineEdit_Tarkennus_yhteensa->text();
    Tarkennus_lah_fos=ui->lineEdit_Tarkennus_lahtaso_fos->text();
    Tarkennus_satotavoite=ui->lineEdit_Tarkennus_satotavoite->text();
    Tarkennus_yht_kg=ui->lineEdit_Tarkennus_yht_kg->text();
    Tarkennus_ed_vuodelta=ui->lineEdit_Tark_edelliselta_Vuodelta->text();
    Tarkennus_lannoite=ui->Combo_Tarkennus_lannoite->currentText();
    Tarkennus_Lannoite_typpi=ui->lineEdit_Tarkennus_lannoite_typpi->text();
    Tarkennus_lannoite2=ui->Combo_Tarkennus_lannoite_2->currentText();
    Tarkennus_lannoite_typpi2=ui->lineEdit_Tarkennus_lannoite_typpi2->text();
    Tarkennus_lannoite_typpi_yht=ui->lineEdit_Tarkennus_lannoite_typpea_yht->text();
    Tarennus_lannoite_fosfori_yht=ui->lineEdit_Tarkennus_lannoite_fofori_yht->text();
    Vilj_esikasvi=ui->lineEdit_vilj_esikasvi->text();
    Vilj_kasvilaji=ui->comboBox_vilj_kasvilaji->currentText();
    Vilj_lajike=ui->comboBox_vilj_lajike->currentText();
    Vilj_siemenmaara=ui->comboBox_vilj_siemenmaara->currentText();
    Vilj_kylvopaiva=ui->lineEdit_vilj_kylvpiva->text();
    Vilj_korjuu1paiva=ui->lineEdit_vilj_korj1piva->text();
    Vilj_sato1=ui->lineEdit_vilj_sato1->text();
    Vilj_korjuu2paiva=ui->lineEdit_vilj_korj2piva->text();
    Vilj_sato2=ui->lineEdit_vilj_sato2->text();
    Vilj_torjunta_aine=ui->comboBox_vilj_Torjunta_aine->currentText();
    Vilj_torjunta_maara=ui->lineEdit_vilj_Torjunta_maara->text();
    Vilj_Kavins_paiva=ui->lineEdit_vilj_Kavins_paiva->text();
    Vilj_torjunta_aine2=ui->comboBox_vilj_Torjunta_aine2->currentText();
    Vilj_torjunta_maara2=ui->lineEdit_vilj_Torjunta_maara2->text();
    Vilj_Kavins_paiva2=ui->lineEdit_vilj_Kavins_paiva2->text();
    Vilj_torjunta_aine3=ui->comboBox_vilj_Torjunta_aine3->currentText();
    Vilj_torjunta_maara3=ui->lineEdit_vilj_Torjunta_maara3->text();
    Vilj_Kavins_paiva3=ui->lineEdit_vilj_Kavins_paiva3->text();
    Muut_keraajakasvi=ui->lineEdit_muut_keraajakasvi->text();
    Muut_kynnetaan=ui->comboBox_muut_kynnetaan->currentText();
    Muut_nurmi=ui->comboBox_muut_nurmi->currentText();
    Muut_muut=ui->lineEdit_muut_muut->text();
    Muut_suojakaista=ui->comboBox_muut_suojakaista->currentText();
    Muut_havainnot=ui->textEdit_muut_havainnot->toPlainText();


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
    qry.prepare("update kortit set dToimMaankPmuokkTapa='"+Perusmuokk_tapa+"',dToimMaankPmuokkpaiva='"+Perusmuokk_paiva+"',dToimMaankKmuokkTapa='"+Kylvomuokk_tapa+"',dToimMaankKmuokkPaiva='"+Kylvomuokk_paiva+"',"
                 "dToimMaanKsyyskasittely='"+Syyskasittely+"', dToimLannLahtot='"+Typpi_lahtotaso+"', dToimLannTarkSato='"+Tarkennus_sato+"',dToimLannTarkOljet='"+Tarkennus_oljet+"',"
                  "dToimLannTarkMuut='"+Tarkennus_muut+"', dToimLannTarkYht='"+Tarkennus_yht+"', dToimLannFosfLahtot='"+Tarkennus_lah_fos+"',dToimLannTavoite='"+Tarkennus_satotavoite+"',"
                   "dToimLannYht='"+Tarkennus_yht_kg+"', dToimLannEdVuodelta='"+Tarkennus_ed_vuodelta+"', dToimLannValLann1='"+Tarkennus_lannoite+"',dToimLannTyppea='"+Tarkennus_lannoite_typpi_yht+"',"
                    "dToimLannFosforia='"+Tarennus_lannoite_fosfori_yht+"', dToimViljEsik='"+Vilj_esikasvi+"', dToimViljKasvil='"+Vilj_kasvilaji+"',dToimViljLajike='"+Vilj_lajike+"',"
                     "dToimLannValLann2='"+Tarkennus_lannoite2+"', dToimLannLannMaara1='"+Tarkennus_Lannoite_typpi+"', dToimLannLannMaara2='"+Tarkennus_lannoite_typpi2+"', "
                      "dToimViljSiemMaara='"+Vilj_siemenmaara+"', dToimViljKylvPaiv='"+Vilj_kylvopaiva+"', dToimViljKorjPaiv1='"+Vilj_korjuu1paiva+"', "
                       "dToimViljSato1='"+Vilj_sato1+"', dToimViljKorjPaiv2='"+Vilj_korjuu2paiva+"', dToimViljSato2='"+Vilj_sato2+"',dToimKasvinsTaine1='"+Vilj_torjunta_aine+"',"
                        "dToimKasvinsKmaara1='"+Vilj_torjunta_maara+"', dToimKasvinsPaiva1='"+Vilj_Kavins_paiva+"', dToimKasvinsTaine2='"+Vilj_torjunta_aine2+"',dToimKasvinsKmaara2='"+Vilj_torjunta_maara2+"',"
                         "dToimKasvinsPaiva2='"+Vilj_Kavins_paiva2+"', dToimKasvinsTaine3='"+Vilj_torjunta_aine3+"', dToimKasvinsKmaara3='"+Vilj_torjunta_maara3+"',dToimKasvinsPaiva3='"+Vilj_Kavins_paiva3+"',"
                          "dToimMuutKeraajak='"+Muut_keraajakasvi+"', dToimMuutSyysvilj='"+Muut_kynnetaan+"', dToimMuutNurmi='"+Muut_nurmi+"',dToimMuutMuut='"+Muut_muut+"',"
                            "dToimMuutSuojakaist='"+Muut_suojakaista+"', dToimMuutHavainn='"+Muut_havainnot+"' where rowID='"+ID+"'");

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

void Toiminpiteet::on_pushButton_filter_clicked()
{
    QString Filtertxt;
    Filtertxt=ui->lineEdit_filter->text();
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


