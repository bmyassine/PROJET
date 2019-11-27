#include "produit.h"

produit::produit()
{

}
produit::produit(int refproduit,QString nom,QString type,QString pays,int qt_stock)
{
  this->qt_stock=qt_stock;
  this->refproduit=refproduit;
  this->nom=nom;

  this->type=type;
  this->pays=pays;
  this->qt_rayon=0;
  this->refrayon=0;


}
int produit::get_refproduit(){return  refproduit;}
QString produit::get_nom(){return nom;}
QString produit::get_date_exp(){return date_exp;}
QString produit::get_type(){return type;}
int produit::get_qt_stock(){return  qt_stock;}
int produit::get_qt_rayon(){return  qt_rayon;}
int produit::get_refrayon(){return  refrayon;}
float produit::get_prix(){return prix;}
float produit::get_solde(){return solde;}
QSqlQueryModel * produit::Modelrefproduit()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery *query = new QSqlQuery();
    query->prepare("select refproduit from produit");
    query->exec();
    model->setQuery(*query);
    return model;
}

bool produit::ajouter(){
    QSqlQuery query;
    QString res= QString::number(refproduit),res1= QString::number(qt_stock);//res2= QString::number(prix);//res3= QString::n
    query.prepare("INSERT INTO produit (refproduit, nom, type, pays, qt_stock) VALUES (:refproduit, :nom, :type, :pays, :qt_stock)");
    query.bindValue(":refproduit", res);
    query.bindValue(":nom", nom);
    query.bindValue(":type", type);
   // query.bindValue(":prix", prix);
    query.bindValue(":pays", pays);
    query.bindValue(":qt_stock", res1);
    //query.bindValue(":date_exp", date_exp);
   // query.bindValue(":solde", solde);
    return query.exec();
}
QSqlQueryModel * produit::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from produit");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("refproduit"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("pays"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("qt_stock"));

    return model;
}
bool produit::supprimer(int ref_ch)
{
QSqlQuery query;

query.prepare("Delete from produit where refproduit = :ref ");
query.bindValue(":ref", ref_ch);
return    query.exec();
}
bool produit::rech(int x){
    QSqlQuery query;
    query.prepare("select * from produit where REFPRODUIT = :reference;");
    query.bindValue(":reference", x);
    return query.exec();
}
bool produit::modifier(QString a,QString b,QString c,int d,int f){
    QSqlQuery query;
    QString yep=QString::number(f);
    query.prepare("UPDATE produit set nom=:nom ,type=:type ,pays=:pays , qt_stock=:quantite  where refproduit ='"+yep+"'");
    query.bindValue(":reference",f);
    query.bindValue(":nom", a);
    query.bindValue(":type", b);
    query.bindValue(":pays", c);
    query.bindValue(":quantite",d);
    return query.exec();
}
QSqlQueryModel * produit::chercher(int ref)
 {
     QSqlQueryModel * model = new QSqlQueryModel();
     QSqlQuery query;
     query.prepare(QString("select * from produit WHERE refproduit=:ref"));
     query.bindValue(":ref",ref);
      query.exec();
     model->setQuery(query);
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("refproduit"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("pays"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("qt_stock"));
return model;
 }
QSqlQueryModel * produit::chercher2(QString type)
 {

     QSqlQueryModel * model = new QSqlQueryModel();
     QSqlQuery query;
     query.prepare(QString("select * from produit WHERE type=:type"));

     query.bindValue(":type",type);

      query.exec();
     model->setQuery(query);
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("refproduit"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("pays"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("qt_stock"));


return model;
 }
QSqlQueryModel * produit::trierrefproduit()
 { QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare(QString("SELECT * FROM produit ORDER BY refproduit;"));
    query.exec();
    model->setQuery(query);
    return model;
 }

QSqlQueryModel * produit::triernom()
 { QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare(QString("SELECT * FROM produit ORDER BY nom;"));
    query.exec();
    model->setQuery(query);
    return model;
 }

QSqlQueryModel * produit::triertype()
 { QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare(QString("SELECT * FROM produit ORDER BY type;"));
    query.exec();
    model->setQuery(query);
    return model;
 }
QSqlQueryModel * produit::trierqt_stock()
 { QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare(QString("SELECT * FROM produit ORDER BY qt_stock"));
    query.exec();
    model->setQuery(query);
    return model;
 }
