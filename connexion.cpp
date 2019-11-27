#include "connexion.h"
#include <QSqlError>
connexion::connexion()
{

}
bool connexion::ouvrirconnexion(){
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Base_de_projet");
    db.setUserName("yassine");
    db.setPassword("esprit18");
    if(db.open())
    test=true;
    else throw QString ("Erreur Paramétres"+db.lastError().text());
    return test;}

void connexion::fermerconnexion(){
    db.close();
}

