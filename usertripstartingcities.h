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

private:
    Ui::userTripStartingCities *ui;
    QSqlDatabase data;

    struct cityData
    {
        QString start;
        QString end;
        double dist;
    };
public:
    explicit userTripStartingCities(QWidget *parent = nullptr);
    ~userTripStartingCities();

    void setupPage();

    void print(QString table);
    void insert(QString table, QString start, QString end, double dist); // inserts record into table with paramaters as values
    void searchMinDist(QString table, QString &start, QString &end, double &dist); // returns values to paramters passed in
    void updateTable(QString table, QString searchVal);// removes all values from table with search condition
    void setTable(QString table1,QString table2);//sets the values from the 2nd parameter to the first
    void clearTable(QString table); // clears all records from a table;
    void count(int &flag,QString table); // returns # of records
    void getTotalDist(QString table,int &totalDist);





};

#endif // USERTRIPSTARTINGCITIES_H
