#ifndef PRODUIT_LIVRER_H
#define PRODUIT_LIVRER_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
class produit_livrer
{
public:
    produit_livrer();
    produit_livrer(int,QString,int,QString);
    int get_refcommande();
    QString get_adresse();
    QString get_nom_client();
    int get_cin_client();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool rech(int);
    bool modifier(QString,int,QString,int);
    bool trier();
    QSqlQueryModel * Modelrefcommande_liv();
    QSqlQueryModel * Modelrefcommande_livs();
    QSqlQueryModel * chercher (int ref);
     QSqlQueryModel * chercher2 (QString type);
     QSqlQueryModel * trierquantite();
     QSqlQueryModel * trierrefcommande();
     QSqlQueryModel * triernom();
     QSqlQueryModel * triercin();
private:
    int refcommande,cin_client;
    QString nom_client,adresse;

};

#endif // PRODUIT_LIVRER_H
