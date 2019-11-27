#include "menu.h"
#include "ui_menu.h"
#include "gestion_produits.h"
#include "gestion_produit_livrer.h"
menu::menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
}

menu::~menu()
{
    delete ui;
}

void menu::on_pushButton_clicked()
{
    Gestion_produits p;
    p.exec();
}

void menu::on_pushButton_2_clicked()
{
    gestion_produit_livrer p;
    p.exec();
}
