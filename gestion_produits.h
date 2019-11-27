#ifndef GESTION_PRODUITS_H
#define GESTION_PRODUITS_H
#include "produit.h"
#include <QDialog>
#include "produit_livrer.h"
#include "smtp.h"
namespace Ui {
class Gestion_produits;
}

class Gestion_produits : public QDialog
{
    Q_OBJECT

public:
    explicit Gestion_produits(QWidget *parent = nullptr);
    ~Gestion_produits();
    void sendMail();
    void mailSent(QString);
private slots:
    void on_ajouter_clicked();

    void on_supprimer_clicked();

    void on_tabproduit_2_clicked(const QModelIndex &index);

    void on_modifier_clicked();

    void on_comboBox_m_currentIndexChanged(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_comboBox_2_activated(const QString &arg1);

    void on_radioButton_4_clicked();

    void on_radioButton_5_clicked();

    void on_radioButton_6_clicked();

    void on_radioButton_7_clicked();

    void on_radioButton_8_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_comboBox_m_2_currentIndexChanged(const QString &arg1);

    void on_modifier_2_clicked();

    void on_supprimer_2_clicked();

    void on_ajouter_2_clicked();

    void on_ajouter_3_clicked();

    void on_sendBtn_clicked();

    void on_radioButton_clicked(bool checked);

    void on_radioButton_2_toggled(bool checked);

    void on_pushButton_7_clicked();

    void on_radioButton_clicked();

    void on_comboBox_11_currentTextChanged(const QString &arg1);

    void on_spinBox_valueChanged(int arg1);

private:
    Ui::Gestion_produits *ui;
    produit tmpproduit;
    QString collect;
    int qt;
    QString pays,type;
    produit_livrer tmpprodlivrer;
};

#endif // GESTION_PRODUITS_H
