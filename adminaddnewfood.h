#ifndef ADMINADDNEWFOOD_H
#define ADMINADDNEWFOOD_H

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
class adminAddNewFood;
}

class adminAddNewFood : public QDialog
{
    Q_OBJECT

public:
    explicit adminAddNewFood(QWidget *parent = nullptr);
    ~adminAddNewFood();

    void setupPage();

private slots:
    void on_updateButton_clicked();

    void on_showAll_clicked();

private:
    Ui::adminAddNewFood *ui;

    QString City;
    QString Food;
    double Price;
    QSqlDatabase data;
};

#endif // ADMINADDNEWFOOD_H
