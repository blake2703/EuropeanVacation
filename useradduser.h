#ifndef USERADDUSER_H
#define USERADDUSER_H

#include <QDialog>
#include <QString>
#include <QMessageBox>
#include <QTextBrowser>
#include <QTableView>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>
#include <QtDebug>
#include <QFileInfo>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QSqlTableModel>

namespace Ui {
class userAddUser;
}

class userAddUser : public QDialog
{
    Q_OBJECT

public:
    explicit userAddUser(QWidget *parent = nullptr);
    ~userAddUser();

    void setupPage();

private slots:
    void on_updateButton_clicked();

private:
    Ui::userAddUser *ui;

    QString username;
    QString password;
    QSqlDatabase data;
};

#endif // USERADDUSER_H
