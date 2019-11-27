#ifndef PRODUIT_H
#define PRODUIT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class produit
{public:
    produit();
    produit(int,QString,QString,QString,int);
    int get_refproduit();
    QString get_nom();
    QString get_type();
    QString get_date_exp();
    QString get_pays();
    int get_qt_stock();
    int get_qt_rayon();
    int get_refrayon();
    float get_prix();
    float get_solde();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool rech(int);
    bool modifier(QString,QString,QString,int,int);
    bool trier();
    QSqlQueryModel * Modelrefproduit();
    QSqlQueryModel * chercher (int ref);
     QSqlQueryModel * chercher2 (QString type);
     QSqlQueryModel * trierqt_stock();
     QSqlQueryModel * trierrefproduit();
     QSqlQueryModel * triernom();
     QSqlQueryModel * triertype();
private:
    QString nom,type,pays,date_exp;
    int qt_stock,qt_rayon,refrayon,refproduit;
    float solde,prix;
};



#endif // PRODUIT_H
