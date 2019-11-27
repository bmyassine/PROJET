#include "gestion_produits.h"
#include "ui_gestion_produits.h"
#include "produit.h"
#include <QMessageBox>
#include "pr_commande.h"
#include "smtp.h"
#include "statistiques.h"
#include "notifiacation.h"
Gestion_produits::Gestion_produits(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Gestion_produits)
{
    ui->setupUi(this);
    ui->tabproduit_2->setModel(tmpproduit.afficher());
    ui->comboBox_m->setModel(tmpproduit.Modelrefproduit());
    ui->comboBox->setModel(tmpproduit.Modelrefproduit());
    ui->comboBox_s->setModel(tmpprodlivrer.Modelrefcommande_livs());
    ui->comboBox_m_2->setModel(tmpprodlivrer.Modelrefcommande_livs());
    ui->tabproduit_3->setModel(tmpprodlivrer.afficher());
    ui->comboBox_5->setModel(tmpprodlivrer.Modelrefcommande_livs());
    ui->comboBox_6->setModel(tmpproduit.Modelrefproduit());
    connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));

}

Gestion_produits::~Gestion_produits()
{
    delete ui;
}
/////
void Gestion_produits::on_ajouter_clicked()
{
    int refproduit = ui->reference_e_2->text().toInt();
    QString nom = ui->nom_e->text();

    //float prix = ui->prix_e->text().toFloat();
    QString payss = pays;
    int qt_stock = ui->qt_stock_e->text().toInt();
   // QString date_exp = ui->date_exp_e->text();
 //   float solde = ui->solde_e_2->text().toFloat();
    produit p(refproduit,nom,type,payss,qt_stock);
    bool test=p.ajouter();
    if(test)

  {ui->tabproduit_2->setModel(tmpproduit.afficher());
         ui->comboBox_m->setModel(tmpproduit.Modelrefproduit());
         ui->comboBox->setModel(tmpproduit.Modelrefproduit());
             ui->comboBox_6->setModel(tmpproduit.Modelrefproduit());
             QString okd="";
                  notifiacation ok;
                  ok.notifiacation_commande(okd);
  QMessageBox::information(nullptr, QObject::tr("Ajouter un produit"),
                    QObject::tr("produit ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un employé"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


  }


void Gestion_produits::on_supprimer_clicked()
{
    int ref_ch = ui->comboBox->currentText().toInt();
    bool test=tmpproduit.supprimer(ref_ch);
    if(test)
    {ui->tabproduit_2->setModel(tmpproduit.afficher());//refresh
         ui->comboBox_m->setModel(tmpproduit.Modelrefproduit());
         ui->comboBox->setModel(tmpproduit.Modelrefproduit());
         ui->comboBox_6->setModel(tmpproduit.Modelrefproduit());
        QMessageBox::information(nullptr, QObject::tr("Supprimer un produit"),
                    QObject::tr("Produit supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un produit"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}


void Gestion_produits::on_modifier_clicked()
{

     QString nom= ui->nom_m->text();
     //QString date_exp= ui->date_exp_m->text();
     QString type= ui->type_m->text();
     QString pays= ui->pays_m->text();
    // int qt_stock= ui->quantite_m->text().toInt();
     int refproduit= ui->comboBox_m->currentText().toInt();
  /*   int refrayon=0;
     int qt_rayon=0;
     float prix = ui->prix_m->text().toFloat();
     float solde = ui->solde_m->text().toFloat(); */
       produit p;
        if(p.rech(refproduit)){
            bool test = p.modifier(nom,type,pays,qt,refproduit);
            if(test){
                ui->tabproduit_2->setModel(tmpproduit.afficher());
                ui->comboBox_m->setModel(tmpproduit.Modelrefproduit());
                QMessageBox::information(nullptr,QObject::tr("Produit modifier"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);
            }
        }
}

void Gestion_produits::on_comboBox_m_currentIndexChanged(const QString &arg1)
{
    QString code = QString::number(arg1.toInt());
    QSqlQuery query;
    query.prepare("select * from produit where refproduit='"+code+"'");
    query.exec();
    while(query.next())
    {
        ui->nom_m->setText(query.value(1).toString());
        ui->type_m->setText(query.value(2).toString());
        ui->pays_m->setText(query.value(3).toString());
        ui->spinBox->setValue(query.value(4).toInt());
    }
}

void Gestion_produits::on_pushButton_2_clicked()
{
    int refproduit = ui->lineEdit->text().toInt();
    QString nom = ui->lineEdit_2->text();


    ui->tabproduit_2->setModel(tmpproduit.chercher(refproduit));

    // ui->tableView->reset();
    ui->tabproduit_2->setModel(tmpproduit.chercher2(nom));


    ui->tabproduit_2->setModel(tmpproduit.chercher2(collect));
        QMessageBox::information(nullptr, QObject::tr("recherche un rayon"),
                          QObject::tr("rayon recherche.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
       // ui->tableView->setModel(tmprayon.afficher())

}

void Gestion_produits::on_comboBox_2_activated(const QString &arg1)
{
    collect=arg1;
}

void Gestion_produits::on_radioButton_4_clicked()
{
 ui->tabproduit_2->setModel(tmpproduit.afficher());
}

void Gestion_produits::on_radioButton_5_clicked()
{
    ui->tabproduit_2->setModel(tmpproduit.trierrefproduit());
}

void Gestion_produits::on_radioButton_6_clicked()
{
    ui->tabproduit_2->setModel(tmpproduit.trierqt_stock());
}


void Gestion_produits::on_radioButton_7_clicked()
{
    ui->tabproduit_2->setModel(tmpproduit.triernom());
}

void Gestion_produits::on_radioButton_8_clicked()
{
    ui->tabproduit_2->setModel(tmpproduit.triertype());
}

/////
void Gestion_produits::on_comboBox_m_2_currentIndexChanged(const QString &arg1)
{
    QString code = QString::number(arg1.toInt());
    QSqlQuery query;
    query.prepare("select * from commande where refcommande='"+code+"'");
    query.exec();
    while(query.next())
    {
        ui->nom_m->setText(query.value(1).toString());
        ui->adresse_m->setText(query.value(3).toString());
        ui->cin_m->setText(query.value(2).toString());

    }
}

void Gestion_produits::on_modifier_2_clicked()
{
    QString nom= ui->nom_m_2->text();
    //QString date_exp= ui->date_exp_m->text();
    QString adresse= ui->adresse_m->text();
    int cin= ui->cin_m->text().toInt();
    int refcommande= ui->comboBox_m_2->currentText().toInt();
 /*   int refrayon=0;
    int qt_rayon=0;
    float prix = ui->prix_m->text().toFloat();
    float solde = ui->solde_m->text().toFloat(); */
      produit_livrer p;
       if(p.rech(refcommande)){
           bool test = p.modifier(nom,cin,adresse,refcommande);
           if(test){
               ui->tabproduit_3->setModel(tmpprodlivrer.afficher());
               ui->comboBox_m_2->setModel(tmpprodlivrer.Modelrefcommande_livs());
               QMessageBox::information(nullptr,QObject::tr("Produit modifier"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);
           }}
}

void Gestion_produits::on_supprimer_2_clicked()
{
    int ref_ch = ui->comboBox_s->currentText().toInt();
    bool test=tmpprodlivrer.supprimer(ref_ch);
    if(test)
    {ui->tabproduit_3->setModel(tmpprodlivrer.afficher());//refresh
         ui->comboBox_m->setModel(tmpprodlivrer.Modelrefcommande_livs());
         ui->comboBox_s->setModel(tmpprodlivrer.Modelrefcommande_livs());
         ui->comboBox_5->setModel(tmpprodlivrer.Modelrefcommande_livs());
        QMessageBox::information(nullptr, QObject::tr("Supprimer un produit"),
                    QObject::tr("Produit supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un produit"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void Gestion_produits::on_ajouter_2_clicked()
{
    int refcommande = ui->lineEdit_ref->text().toInt();
    QString nom = ui->nom_e_2->text();
    int cin = ui->cin_client_e->text().toInt();
    //float prix = ui->prix_e->text().toFloat();
    QString adresse = ui->adresse_e->text();

   // QString date_exp = ui->date_exp_e->text();
 //   float solde = ui->solde_e_2->text().toFloat();
    produit_livrer p(refcommande,nom,cin,adresse);
    bool test=p.ajouter();
    if(test)
  {ui->tabproduit_3->setModel(tmpprodlivrer.afficher());
        ui->comboBox_s->setModel(tmpprodlivrer.Modelrefcommande_livs());
        ui->comboBox_m_2->setModel(tmpprodlivrer.Modelrefcommande_livs());
        ui->comboBox_5->setModel(tmpprodlivrer.Modelrefcommande_livs());
  QMessageBox::information(nullptr, QObject::tr("Ajouter un produit"),
                    QObject::tr("produit ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un employé"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
////

void Gestion_produits::on_ajouter_3_clicked()
{
    int refcommande = ui->comboBox_5->currentText().toInt();
    int refproduit = ui->comboBox_6->currentText().toInt();
    int quantite = ui->quantite_e->text().toInt();
    pr_commande p(refcommande,refproduit,quantite);
    bool test=p.ajouter();
    if(test)
  {ui->tabproduit_3->setModel(tmpprodlivrer.afficher());
        ui->comboBox_s->setModel(tmpprodlivrer.Modelrefcommande_livs());
        ui->comboBox_m_2->setModel(tmpprodlivrer.Modelrefcommande_livs());
        ui->comboBox_5->setModel(tmpprodlivrer.Modelrefcommande_livs());
  QMessageBox::information(nullptr, QObject::tr("Ajouter un produit"),
                    QObject::tr("produit ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un employé"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}


void Gestion_produits::on_sendBtn_clicked()
{
//sendMail();
}

void Gestion_produits::on_radioButton_clicked(bool checked)
{
    if(checked){
        pays ="Tunis";}
}

void Gestion_produits::on_radioButton_2_toggled(bool checked)
{
    if(checked){
        pays ="Importe";}
}

void Gestion_produits::on_pushButton_7_clicked()
{
    statistiques *p = new statistiques();
    p->setWindowModality(Qt::ApplicationModal);
    p->show();
}



void Gestion_produits::on_comboBox_11_currentTextChanged(const QString &arg1)
{
    type=arg1;
}

void Gestion_produits::on_spinBox_valueChanged(int arg1)
{
    qt=arg1;
}
