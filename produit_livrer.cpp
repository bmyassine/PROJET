#include "produit_livrer.h"

produit_livrer::produit_livrer()
{

}
produit_livrer::produit_livrer(int refcommande,QString nom_client,int cin_client,QString adresse)
{
  this->refcommande=refcommande;
  this->nom_client=nom_client;
  this->cin_client=cin_client;
  this->adresse=adresse;
}
QString produit_livrer::get_adresse(){return adresse;}
QString produit_livrer::get_nom_client(){return nom_client;}
int produit_livrer::get_cin_client(){return  cin_client;}
int produit_livrer::get_refcommande(){return  refcommande;}
bool produit_livrer::ajouter(){
    QSqlQuery query;
    QString res= QString::number(refcommande),res2= QString::number(cin_client);//res3= QString::n
    query.prepare("INSERT INTO commande (refcommande, nom_client, cin_client, adresse_de_livraison) VALUES (:refcommande, :nom, :cin, :adresse)");
    query.bindValue(":refcommande", res);
    query.bindValue(":nom", nom_client);
    query.bindValue(":cin",res2);
    query.bindValue(":adresse",adresse);
    return query.exec();
}
QSqlQueryModel * produit_livrer::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from commande");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("refcommande"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_client"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("cin_client"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));


    return model;
}
bool produit_livrer::supprimer(int ref_ch)
{
QSqlQuery query;

query.prepare("Delete from commande where refcommande = :ref ");
query.bindValue(":ref", ref_ch);
return    query.exec();
}
QSqlQueryModel * produit_livrer::Modelrefcommande_livs()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery *query = new QSqlQuery();
    query->prepare("select refcommande from commande");
    query->exec();
    model->setQuery(*query);
    return model;
}
bool produit_livrer::rech(int x){
    QSqlQuery query;
    query.prepare("select * from commande where refcommande = :reference;");
    query.bindValue(":reference", x);
    return query.exec();
}
bool produit_livrer::modifier(QString a,int b,QString c,int f){
    QSqlQuery query;
    QString yep=QString::number(f);
    QString res=QString::number(b);

    query.prepare("UPDATE commande set nom_client=:nom ,cin_client=:cin ,adresse_de_livraison=:adresse where refcommande ='"+yep+"'");
    query.bindValue(":reference",f);
    query.bindValue(":nom", a);
    query.bindValue(":cin", res);
    query.bindValue(":adresse", c);

    return query.exec();
}
