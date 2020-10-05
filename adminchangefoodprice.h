#ifndef ADMINCHANGEFOODPRICE_H
#define ADMINCHANGEFOODPRICE_H

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
class adminChangeFoodPrice;
}

class adminChangeFoodPrice : public QDialog
{
    Q_OBJECT

public:
    explicit adminChangeFoodPrice(QWidget *parent = nullptr);
    ~adminChangeFoodPrice();

    void setupPage();

private slots:
    void on_updateButton_clicked();

    void on_showAll_clicked();

private:
    Ui::adminChangeFoodPrice *ui;
    QString City;
    QString Food;
    double Price;
    QSqlDatabase data;

};


#endif // ADMINCHANGEFOODPRICE_H
