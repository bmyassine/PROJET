#include "notifiacation.h"
#include <QSystemTrayIcon>
#include<QString>
notifiacation::notifiacation()
{
num=0;
}

void notifiacation::notifiacation_ajout_produit(QString id)
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("C:/Users/Haboub/Pictures/Wallpapers/witcherHorizon.jpg"));
    QString s = id;
    //notifyIcon->setVisible(1);
    notifyIcon->show();
    notifyIcon->showMessage("News","Un nouvel hotel a été ajouté !",QSystemTrayIcon::Information,15000);
//num++;
}

void notifiacation::notifiacation_commande(QString id)
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("C:/Users/Ben Moussa/Desktop/show.png"));
    QString s = id;
    //notifyIcon->setVisible(1);
    notifyIcon->show();
    notifyIcon->showMessage("News","Une nouvelle destiantion a été ajoutée !",QSystemTrayIcon::Information,15000);
//num++;
}


void notifiacation::notifiacation_ajout_procommande(QString id)
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->setIcon(QIcon("C:/Users/Haboub/Pictures/Wallpapers/witcherHorizon.jpg"));
    QString s = id;
    //notifyIcon->setVisible(1);
    notifyIcon->show();
    notifyIcon->showMessage("Gestion d'agence de voyage","Nouvelle instance ouverte",QSystemTrayIcon::Information,15000);
//num++;
}
