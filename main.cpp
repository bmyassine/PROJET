#include "login.h"
#include "connexion.h"
#include <QApplication>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    login w;
    connexion c;
    try {
        c.ouvrirconnexion();
        w.show();

    } catch (QString s) {
       qDebug()<<s;
    }
    return a.exec();
}
