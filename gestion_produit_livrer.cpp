#include "gestion_produit_livrer.h"
#include "ui_gestion_produit_livrer.h"
#include "produit_livrer.h"
#include <QMessageBox>
gestion_produit_livrer::gestion_produit_livrer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_produit_livrer)
{
    ui->setupUi(this);
    ui->comboBox_s->setModel(tmpprodlivrer.Modelrefcommande_livs());
    ui->comboBox_m->setModel(tmpprodlivrer.Modelrefcommande_livs());
    ui->tabproduit_2->setModel(tmpprodlivrer.afficher());
}

gestion_produit_livrer::~gestion_produit_livrer()
{
    delete ui;
}

void gestion_produit_livrer::on_ajouter_clicked()
{
    int refcommande = ui->lineEdit_ref->text().toInt();
    QString nom = ui->nom_e->text();
    int cin = ui->cin_client_e->text().toInt();
    //float prix = ui->prix_e->text().toFloat();
    QString adresse = ui->adresse_e->text();

   // QString date_exp = ui->date_exp_e->text();
 //   float solde = ui->solde_e_2->text().toFloat();
    produit_livrer p(refcommande,nom,cin,adresse);
    bool test=p.ajouter();
    if(test)
  {ui->tabproduit_2->setModel(tmpprodlivrer.afficher());
        ui->comboBox_s->setModel(tmpprodlivrer.Modelrefcommande_livs());
        ui->comboBox_m->setModel(tmpprodlivrer.Modelrefcommande_livs());
  QMessageBox::information(nullptr, QObject::tr("Ajouter un produit"),
                    QObject::tr("produit ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un employé"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void gestion_produit_livrer::on_supprimer_clicked()
{
    int ref_ch = ui->comboBox_s->currentText().toInt();
    bool test=tmpprodlivrer.supprimer(ref_ch);
    if(test)
    {ui->tabproduit_2->setModel(tmpprodlivrer.afficher());//refresh
         ui->comboBox_m->setModel(tmpprodlivrer.Modelrefcommande_livs());
        QMessageBox::information(nullptr, QObject::tr("Supprimer un produit"),
                    QObject::tr("Produit supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un produit"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void gestion_produit_livrer::on_modifier_clicked()
{
    QString nom= ui->nom_m->text();
    //QString date_exp= ui->date_exp_m->text();
    QString adresse= ui->adresse_m->text();
    int cin= ui->cin_m->text().toInt();
    int refcommande= ui->comboBox_m->currentText().toInt();
 /*   int refrayon=0;
    int qt_rayon=0;
    float prix = ui->prix_m->text().toFloat();
    float solde = ui->solde_m->text().toFloat(); */
      produit_livrer p;
       if(p.rech(refcommande)){
           bool test = p.modifier(nom,cin,adresse,refcommande);
           if(test){
               ui->tabproduit_2->setModel(tmpprodlivrer.afficher());
               ui->comboBox_m->setModel(tmpprodlivrer.Modelrefcommande_livs());
               QMessageBox::information(nullptr,QObject::tr("Produit modifier"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);
           }
       }
}

void gestion_produit_livrer::on_comboBox_m_currentIndexChanged(const QString &arg1)
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
