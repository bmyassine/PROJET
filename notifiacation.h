
#ifndef NOTIFICATION_H
#define NOTIFICATION_H
#include <QSystemTrayIcon>
#include<QString>
class notifiacation
{
private:
    int num;
public:
    notifiacation();
    void notifiacation_ajout_produit(QString);
    void notifiacation_commande(QString id);
    void notifiacation_ajout_procommande(QString id);
};

#endif // NOTIFICATION_H
