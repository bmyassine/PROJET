#ifndef PR_COMMANDE_H
#define PR_COMMANDE_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
class pr_commande
{public:
    pr_commande();
    pr_commande(int,int,int);
    int get_refcommande();
    int get_quantite();
    int get_refproduit();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool rech(int);
    bool modifier(QString,int,QString,int);
    bool trier();
    QSqlQueryModel * Modelrefproduit();
    QSqlQueryModel * Modelrefcommande_livs();
    QSqlQueryModel * chercher (int ref);
     QSqlQueryModel * chercher2 (QString type);
     QSqlQueryModel * trierquantite();
     QSqlQueryModel * trierrefcommande();
     QSqlQueryModel * triernom();
     QSqlQueryModel * triercin();
private:
    int refcommande,refproduit,quantite;
};

#endif // PR_COMMANDE_H
