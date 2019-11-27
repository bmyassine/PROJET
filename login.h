#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class login; }
QT_END_NAMESPACE

class login : public QMainWindow
{
    Q_OBJECT

public:
    login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_connecter_clicked();

    void on_check_mdp_stateChanged(int arg1);

    void on_check_mdp_toggled(bool checked);

private:
    Ui::login *ui;
};
#endif // LOGIN_H
