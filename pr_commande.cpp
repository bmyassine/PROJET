#include "pr_commande.h"

pr_commande::pr_commande()
{

}
pr_commande::pr_commande(int refcommande,int refproduit,int quantite)
{
  this->refcommande=refcommande;
  this->refproduit=refproduit;
  this->quantite=quantite;
}
QSqlQueryModel * pr_commande::Modelrefcommande_livs()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery *query = new QSqlQuery();
    query->prepare("select refcommande from commande");
    query->exec();
    model->setQuery(*query);
    return model;
}
QSqlQueryModel * pr_commande::Modelrefproduit()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery *query = new QSqlQuery();
    query->prepare("select refproduit from produit");
    query->exec();
    model->setQuery(*query);
    return model;
}
bool pr_commande::ajouter(){
    QSqlQuery query;
    QString res= QString::number(refcommande),res2= QString::number(refproduit),res3= QString::number(quantite);
    query.prepare("INSERT INTO con_commande (refcommande, refproduit, quantite) VALUES (:refcommande, :refproduit, :quantite)");
    query.bindValue(":refcommande", res);
    query.bindValue(":refproduit", res2);
    query.bindValue(":quantite",res3);
    return query.exec();
}
QSqlQueryModel * pr_commande::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from con_commande");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("refcommande"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("refproduit"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("quantite"));
    return model;
}
