#ifndef STATISTIQUE_H
#define STATISTIQUE_H

#include <QDialog>

namespace Ui {
class statistique;
}

class statistique : public QDialog
{
    Q_OBJECT

public:
    explicit statistique(QWidget *parent = nullptr);
    ~statistique();

private:
    Ui::statistique *ui;
};
#include <QWidget>
#include <QMap>
#include <QVector>
namespace Ui {
class statistique_mbarki;
}

class statistique_mbarki : public QWidget
{
    Q_OBJECT

public:
    explicit statistique_mbarki(QWidget *parent = nullptr);
    ~statistique_mbarki();

private:
    Ui::statistique_mbarki *ui;

};
#endif // STATISTIQUE_H
