#include "login.h"
#include "ui_login.h"
#include <QPixmap>
#include <QMessageBox>
#include "gestion_produits.h"
#include <QtMultimedia/QSound>
login::login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/Ben Moussa/Desktop/Projet 2A/CRUD_YaCine/affiche.jpg");
    ui->background->setPixmap(pix);
    ui->statusbar->addPermanentWidget(ui->etat,3);
    ui->statusbar->addPermanentWidget(ui->progressBar,1);
    ui->progressBar->setValue(0);
}

login::~login()
{
    delete ui;
}


void login::on_connecter_clicked()
{
    QString identifiant = ui->id_edit->text();
    QString mdp = ui->mdp_edit->text();
    QSound::play("C:/Users/Ben Moussa/Desktop/Projet 2A/App_DesktopV0/y2mate.com - free_no_copyrightclicking_subscribe_button_with_sound_gIeF2xccRbU.mp3");
    if (identifiant == "yassine" && mdp== "yassinebm"){
       hide();
       Gestion_produits p;
       p.exec();
        ui->etat->setText("identifiant et mot de passe correctes");
        ui->progressBar->setValue(100);
    }
    else{
        ui->etat->setText("identifiant et mot de passe incorrectes");
        QMessageBox::information(this,"Warning","Mot de passe ou identifiant incorrectes");
    }
}
void login::on_check_mdp_toggled(bool checked)
{

    if(checked){
        ui->mdp_edit->setEchoMode(QLineEdit::Normal);
    }
    else
         ui->mdp_edit->setEchoMode(QLineEdit::Password);
}
