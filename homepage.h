#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QMainWindow>
#include <QMovie>
#include <QSqlDatabase>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSqlQuery>
#include <QMessageBox>

#include "adminhomepage.h"

QT_BEGIN_NAMESPACE
namespace Ui { class homepage; }
QT_END_NAMESPACE

class homepage : public QMainWindow
{
    Q_OBJECT

public:
    homepage(QWidget *parent = nullptr);
    ~homepage();

    void createWelcomeLabel();
    void createAdminCredentials();
    void createAdminLoginButton();
    void createUserCredentials();
    void createUserLoginButton();



private slots:
    void on_adminLoginButton_clicked();

private:
    Ui::homepage *ui;

    QString firstName;
    QString lastName;
    QString emailAddress;
    QString phoneNumber;
    QString username;
    QString password;
    QString passwordHint;

    QLineEdit *firstNameEdit;
    QLineEdit *lastNameEdit;
    QLineEdit *emailAddressEdit;
    QLineEdit *phoneNumerEdit;
    QLineEdit *usernameEdit;
    QLineEdit *firstPasswordEdit;
    QLineEdit *reenterPasswordEdit;
    QLineEdit *passwordHintEdit;

    QWidget *leftWidget;
    QWidget *rightWidget;

    QVBoxLayout *leftLayout;
    QVBoxLayout *rightLayout;

    QSqlDatabase data;
};
#endif // HOMEPAGE_H
