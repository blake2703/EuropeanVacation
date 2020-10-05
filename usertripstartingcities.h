#ifndef USERTRIPSTARTINGCITIES_H
#define USERTRIPSTARTINGCITIES_H

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
class userTripStartingCities;
}

class userTripStartingCities : public QDialog
{
    Q_OBJECT

public:
    explicit userTripStartingCities(QWidget *parent = nullptr);
    ~userTripStartingCities();

    void setupPage();
    void print();
    void insert(QString);
    void find();

private:
    Ui::userTripStartingCities *ui;
    QSqlDatabase data;
    QString start;
    QString end;
    double distance;
};

#endif // USERTRIPSTARTINGCITIES_H
