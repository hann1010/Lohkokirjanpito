#include "suunnitelu.h"
#include "ui_suunnitelu.h"
#include <QMessageBox>
#include <QDateEdit>
#include <QDate>

Suunnitelu::Suunnitelu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Suunnitelu)
{
    ui->setupUi(this);
    Suunnitelu::on_pushButton_upd_list_clicked();
}

Suunnitelu::~Suunnitelu()
{
    delete ui;
}


void Suunnitelu::on_pushButton_upd_list_clicked()
{
    QDate date=QDate::currentDate();
    QString date_txt=date.toString("yyyy");

    Login conn;
    QSqlQueryModel * modal=new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery* qry=new QSqlQuery(conn.myDB);
    qry->prepare("select  rowID,dKasvulohkoNimi AS 'Lohkon nimi',dKasvulohkonTunnus AS 'Lohkon tunnus',dVuosi AS 'Vuosi',dSuunViljKasvilaji AS 'Suun Kasvilaji',dSuunViljLajike AS 'Suun Kasvilajike',dToimViljKasvil AS 'Toim Kasvilaji' from kortit where dVuosi like'%"+date_txt+"%'  "); // * tai ID,user,role sen mukaan mitkä kaikki halutaan taulukkoon
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);

    conn.connClose();
    qDebug() << (modal->rowCount());
}

void Suunnitelu::on_tableView_activated(const QModelIndex &index)
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

           ui->rowIDLineEdit->setText(val);
           ui->comboBox_Esikasvi->setEditText(qry.value(17).toString());
           ui->comboBox_Kasvilaji->setEditText(qry.value(18).toString());
           ui->comboBox_Lajike->setEditText(qry.value(19).toString());
           ui->kasvulohkonNimiLineEdit->setText(qry.value(3).toString());
           ui->comboBox_Satotavoite->setEditText(qry.value(20).toString());
           ui->comboBox_ViljTapa->setEditText(qry.value(21).toString());
           ui->comboBox_SiemenM->setEditText(qry.value(22).toString());
           ui->siemenetYhteensKgLineEdit->setText(qry.value(23).toString());
           ui->lohkonKokoHaLineEdit->setText(qry.value(11).toString());
           ui->lineEdit_Ravinne_lah_N->setText(qry.value(24).toString());
           ui->lineEdit_Ravinne_lah_P->setText(qry.value(25).toString());
           ui->lineEdit_Ravinne_lah_K->setText(qry.value(26).toString());
           ui->lineEdit_Ravinne_Tar_N->setText(qry.value(27).toString());
           ui->lineEdit_Ravinne_tar_P->setText(qry.value(28).toString());
           ui->lineEdit_Ravinne_oljet->setText(qry.value(29).toString());
           ui->lineEdit_Ravinne_esikasvi->setText(qry.value(30).toString());
           ui->lineEdit_Ravinne_Start_N->setText(qry.value(31).toString());
           ui->lineEdit_Ravinne_Start_P->setText(qry.value(32).toString());
           ui->lineEdit_Ravinne_muut_N->setText(qry.value(33).toString());
           ui->lineEdit_Ravinne_muut_P->setText(qry.value(34).toString());
           ui->lineEdit_Ravinne_muut_K->setText(qry.value(35).toString());
           ui->lineEdit_Ravinne_tarv_N->setText(qry.value(36).toString());
           ui->lineEdit_Ravinne_tarv_P->setText(qry.value(37).toString());
           ui->lineEdit_Ravinne_tarv_K->setText(qry.value(38).toString());
           ui->lineEdit_suunn_Lannoit_N->setText(qry.value(39).toString());
           ui->lineEdit_suunn_Lannoit_P->setText(qry.value(40).toString());
           ui->lineEdit_suunn_Lannoit_K->setText(qry.value(41).toString());
           ui->comboBox_suun_lann_Laji->setEditText(qry.value(42).toString());
           ui->lineEdit_suun_lann_Laji_N->setText(qry.value(43).toString());
           ui->lineEdit_suun_lann_Laji_P->setText(qry.value(44).toString());
           ui->lineEdit_suun_lann_Laji_K->setText(qry.value(45).toString());
           ui->comboBox_Suun_lann_maara->setEditText(qry.value(46).toString());
           ui->lineEdit_suun_lann_kalkki->setText(qry.value(47).toString());
           ui->lineEdit_suun_lann_tase_N->setText(qry.value(48).toString());
           ui->lineEdit_suun_lann_tase_P->setText(qry.value(49).toString());
           ui->lineEdit_suun_lann_tase_K->setText(qry.value(50).toString());
           ui->comboBox_suun_suoj_Valm->setEditText(qry.value(51).toString());
           ui->comboBox_suun_suoj_maara->setEditText(qry.value(52).toString());
           ui->lineEdit_suun_suoj_aika->setText(qry.value(53).toString());
           ui->lineEdit_suun_suoj_huom->setText(qry.value(54).toString());
           ui->comboBox_suun_rikka_Valm->setEditText(qry.value(55).toString());
           ui->comboBox_suun_rikka_maara->setEditText(qry.value(56).toString());
           ui->lineEdit_suun_rikka_aika->setText(qry.value(57).toString());
           ui->lineEdit_suun_rikka_huom->setText(qry.value(58).toString());
           ui->lineEdit_suun_tuhol_Valm->setText(qry.value(59).toString());
           ui->lineEdit_suun_tuhol_maara->setText(qry.value(60).toString());
           ui->lineEdit_suun_tuhol_aika->setText(qry.value(61).toString());
           ui->lineEdit_suun_tuhol_huom->setText(qry.value(62).toString());
           ui->lineEdit_suun_tauti_Valm->setText(qry.value(63).toString());
           ui->lineEdit_suun_tauti_maara->setText(qry.value(64).toString());
           ui->lineEdit_suun_tauti_aika->setText(qry.value(65).toString());
           ui->lineEdit_suun_tauti_huom->setText(qry.value(66).toString());
           ui->lineEdit_suun_saade_Valm->setText(qry.value(67).toString());
           ui->lineEdit_suun_saade_maara->setText(qry.value(68).toString());
           ui->lineEdit_suun_saade_aika->setText(qry.value(69).toString());
           ui->lineEdit_suun_saade_huom->setText(qry.value(70).toString());

           }
           conn.connClose();

       }
       else
       {
          QMessageBox::critical(this,tr("Error::"),qry.lastError().text());


       }
}

void Suunnitelu::on_pushButton_paivita_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("Tietokanta"),"Haluatko varmasi päivittää tiedot?",
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes)
  {



    QString ID, Esikasvi, Kasvilaji, Lajike, Satotavoite, ViljTapa, SiemenM, siemenetYhteensa, Ravinne_lah_N, Ravinne_lah_P, Ravinne_lah_K, Ravinne_Tar_N, Ravinne_tar_P, Ravinne_oljet, Ravinne_esikasvi ;
    QString Ravinne_Start_N, Ravinne_Start_P, Ravinne_muut_N, Ravinne_muut_P, Ravinne_muut_K, Ravinne_tarv_N, Ravinne_tarv_P, Ravinne_tarv_K, suunn_Lannoit_N, suunn_Lannoit_P, suunn_Lannoit_K  ;
    QString suun_lann_Laji, suun_lann_Laji_N, suun_lann_Laji_P, suun_lann_Laji_K, Suun_lann_maara, suun_lann_kalkki, suun_lann_tase_N, suun_lann_tase_P, suun_lann_tase_K, suun_suoj_Valm, suun_suoj_maara  ;
    QString suun_suoj_aika, suun_suoj_huom, suun_rikka_Valm, suun_rikka_maara, suun_rikka_aika, suun_rikka_huom, suun_tuhol_Valm, suun_tuhol_maara, suun_tuhol_aika, suun_tuhol_huom ;
    QString suun_tauti_Valm, suun_tauti_maara, suun_tauti_aika, suun_tauti_huom, suun_saade_Valm, suun_saade_maara, suun_saade_aika, suun_saade_huom ;


    ID=ui->rowIDLineEdit->text();
    Esikasvi=ui->comboBox_Esikasvi->currentText();
    Kasvilaji=ui->comboBox_Kasvilaji->currentText();
    Lajike=ui->comboBox_Lajike->currentText();
    Satotavoite=ui->comboBox_Satotavoite->currentText();
    ViljTapa=ui->comboBox_ViljTapa->currentText();
    SiemenM=ui->comboBox_SiemenM->currentText();
    siemenetYhteensa=ui->siemenetYhteensKgLineEdit->text();
    Ravinne_lah_N=ui->lineEdit_Ravinne_lah_N->text();
    Ravinne_lah_P=ui->lineEdit_Ravinne_lah_P->text();
    Ravinne_lah_K=ui->lineEdit_Ravinne_lah_K->text();
    Ravinne_Tar_N=ui->lineEdit_Ravinne_Tar_N->text();
    Ravinne_tar_P=ui->lineEdit_Ravinne_tar_P->text();
    Ravinne_oljet=ui->lineEdit_Ravinne_oljet->text();
    Ravinne_esikasvi=ui->lineEdit_Ravinne_esikasvi->text();
    Ravinne_Start_N=ui->lineEdit_Ravinne_Start_N->text();
    Ravinne_Start_P=ui->lineEdit_Ravinne_Start_P->text();
    Ravinne_muut_N=ui->lineEdit_Ravinne_muut_N->text();
    Ravinne_muut_P=ui->lineEdit_Ravinne_muut_P->text();
    Ravinne_muut_K=ui->lineEdit_Ravinne_muut_K->text();
    Ravinne_tarv_N=ui->lineEdit_Ravinne_tarv_N->text();
    Ravinne_tarv_P=ui->lineEdit_Ravinne_tarv_P->text();
    Ravinne_tarv_K=ui->lineEdit_Ravinne_tarv_K->text();
    suunn_Lannoit_N=ui->lineEdit_suunn_Lannoit_N->text();
    suunn_Lannoit_P=ui->lineEdit_suunn_Lannoit_P->text();
    suunn_Lannoit_K=ui->lineEdit_suunn_Lannoit_K->text();
    suun_lann_Laji=ui->comboBox_suun_lann_Laji->currentText();
    suun_lann_Laji_N=ui->lineEdit_suun_lann_Laji_N->text();
    suun_lann_Laji_P=ui->lineEdit_suun_lann_Laji_P->text();
    suun_lann_Laji_K=ui->lineEdit_suun_lann_Laji_K->text();
    Suun_lann_maara=ui->comboBox_Suun_lann_maara->currentText();
    suun_lann_kalkki=ui->lineEdit_suun_lann_kalkki->text();
    suun_lann_tase_N=ui->lineEdit_suun_lann_tase_N->text();
    suun_lann_tase_P=ui->lineEdit_suun_lann_tase_P->text();
    suun_lann_tase_K=ui->lineEdit_suun_lann_tase_K->text();
    suun_suoj_Valm=ui->comboBox_suun_suoj_Valm->currentText();
    suun_suoj_maara=ui->comboBox_suun_suoj_maara->currentText();
    suun_suoj_aika=ui->lineEdit_suun_suoj_aika->text();
    suun_suoj_huom=ui->lineEdit_suun_suoj_huom->text();
    suun_rikka_Valm=ui->comboBox_suun_rikka_Valm->currentText();
    suun_rikka_maara=ui->comboBox_suun_rikka_maara->currentText();
    suun_rikka_aika=ui->lineEdit_suun_rikka_aika->text();
    suun_rikka_huom=ui->lineEdit_suun_rikka_huom->text();
    suun_tuhol_Valm=ui->lineEdit_suun_tuhol_Valm->text();
    suun_tuhol_maara=ui->lineEdit_suun_tuhol_maara->text();
    suun_tuhol_aika=ui->lineEdit_suun_tuhol_aika->text();
    suun_tuhol_huom=ui->lineEdit_suun_tuhol_huom->text();
    suun_tauti_Valm=ui->lineEdit_suun_tauti_Valm->text();
    suun_tauti_maara=ui->lineEdit_suun_tauti_maara->text();
    suun_tauti_aika=ui->lineEdit_suun_tauti_aika->text();
    suun_tauti_huom=ui->lineEdit_suun_tauti_huom->text();
    suun_saade_Valm=ui->lineEdit_suun_saade_Valm->text();
    suun_saade_maara=ui->lineEdit_suun_saade_maara->text();
    suun_saade_aika=ui->lineEdit_suun_saade_aika->text();
    suun_saade_huom=ui->lineEdit_suun_saade_huom->text();



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
    qry.prepare("update kortit set dSuunViljEsikasvi='"+Esikasvi+"',dSuunViljKasvilaji='"+Kasvilaji+"',dSuunViljLajike='"+Lajike+"',dSuunViljSatotavoite='"+Satotavoite+"',dSuunViljViljelytapa='"+ViljTapa+"',"
                 "dSuunViljSiemenmaara='"+SiemenM+"', dSuunViljSiemenYht='"+siemenetYhteensa+"', dSuunRavLahN='"+Ravinne_lah_N+"',dSuunRavLahP='"+Ravinne_lah_P+"', dSuunRavLahK='"+Ravinne_lah_K+"',"
                  "dSuunRavTavN='"+Ravinne_Tar_N+"', dSuunRavTavP='"+Ravinne_tar_P+"',dSuunRavOlkiN='"+Ravinne_oljet+"', dSuunRavEsikN='"+Ravinne_esikasvi+"',dSuunRavStartN='"+Ravinne_Start_N+"', "
                   "dSuunRavStartP='"+Ravinne_Start_P+"',dSuunRavMuutN='"+Ravinne_muut_N+"', dSuunRavMuutP='"+Ravinne_muut_P+"',dSuunRavMuutK='"+Ravinne_muut_K+"',dSuunRavTarvN='"+Ravinne_tarv_N+"',"
                    "dSuunRavTarvP='"+Ravinne_tarv_P+"', dSuunRavTarvK='"+Ravinne_tarv_K+"',dSuunLannTarveN='"+suunn_Lannoit_N+"', dSuunLannTarveP='"+suunn_Lannoit_P+"',dSuunLannTarveK='"+suunn_Lannoit_K+"',"
                     "dSuunLannLaji='"+suun_lann_Laji+"', dSuunLannLajiN='"+suun_lann_Laji_N+"',dSuunLannLajiP='"+suun_lann_Laji_P+"', dSuunLannLajiK='"+suun_lann_Laji_K+"',dSuunLannMaara='"+Suun_lann_maara+"', "
                      "dSuunLannKalkitus='"+suun_lann_kalkki+"', dSuunLannTaseN='"+suun_lann_tase_N+"',dSuunLannTaseP='"+suun_lann_tase_P+"', dSuunLannTaseK='"+suun_lann_tase_K+"',"
                       "dSuunKasvinsPeittNimi='"+suun_suoj_Valm+"', dSuunKasvinsPeittMaara='"+suun_suoj_maara+"',dSuunKasvinsAika='"+suun_suoj_aika+"', dSuunKasvinsHuom='"+suun_suoj_huom+"', "
                        "dSuunKasvinsRikkaNimi='"+suun_rikka_Valm+"', dSuunKasvinsRikkaMaara='"+suun_rikka_maara+"',dSuunKasvinsRikkaAika='"+suun_rikka_aika+"', dSuunKasvinsRikkaHuom='"+suun_rikka_huom+"', "
                         "dSuunKasvinsTuholNimi='"+suun_tuhol_Valm+"', dSuunKasvinsTuholMaara='"+suun_tuhol_maara+"',dSuunKasvinsTuholAika='"+suun_tuhol_aika+"', dSuunKasvinsTuholHuom='"+suun_tuhol_huom+"',"
                          "dSuunKasvinsKasvitNimi='"+suun_tauti_Valm+"', dSuunKasvinsKasvitMaara='"+suun_tauti_maara+"',dSuunKasvinsKasvitAika='"+suun_tauti_aika+"', dSuunKasvinsKasvitHuom='"+suun_tauti_huom+"', "
                           "dSuunKasvinsKasvunsNimi='"+suun_saade_Valm+"', dSuunKasvinsKasvunsMaara='"+suun_saade_maara+"',dSuunKasvinsKasvunsAika='"+suun_saade_aika+"', dSuunKasvinsKasvunsHuom='"+suun_saade_huom+"' where rowID='"+ID+"'");

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

void Suunnitelu::on_pushButton_filter_clicked()
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
