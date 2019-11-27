#ifndef GESTION_PRODUIT_LIVRER_H
#define GESTION_PRODUIT_LIVRER_H
#include "produit_livrer.h"
#include <QDialog>

namespace Ui {
class gestion_produit_livrer;
}

class gestion_produit_livrer : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_produit_livrer(QWidget *parent = nullptr);
    ~gestion_produit_livrer();

private slots:
    void on_ajouter_clicked();

    void on_supprimer_clicked();

    void on_modifier_clicked();

    void on_comboBox_m_currentIndexChanged(const QString &arg1);

private:
    Ui::gestion_produit_livrer *ui;
    produit_livrer tmpprodlivrer;
    QString collect;
};

#endif // GESTION_PRODUIT_LIVRER_H
