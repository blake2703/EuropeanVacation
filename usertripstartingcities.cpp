#include "usertripstartingcities.h"
#include "ui_usertripstartingcities.h"
#include "algorithm"

#include <qqueue.h>

userTripStartingCities::userTripStartingCities(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::userTripStartingCities)
{
    ui->setupUi(this);

    QString allTable = "Cities"; // This is the table that contains all of the other cities

    QString tempTable;  // Table that will be manipulated(Serves as vector)
    QString finalTable; // Table that will contain the final result to be printed
    QString start;      // starting city
    QString end;        // ending city
    double dist;        // distance
    int flag = 100;     // sentinel value that will exit the loop
    int totalDist;

    tempTable = "temp"; //sets the value of temp table
    finalTable = "dummy"; // sets the value of our final table
    start = "Berlin";    //sets the starting city

    //THESE 2 LINES OF CODE NEED TO BE INCLUDED TO ENSURE BOTH TEMP TABLES ARE CLEARED
    clearTable(tempTable);
    clearTable(finalTable);

    setTable(tempTable,allTable); // Temp table is now full with all of the cities

    while(flag !=0)
    {
        searchMinDist(tempTable,start,end,dist); // searches the temp for the values and sets them to parameters
        insert(finalTable,start,end,dist);       // inserts the parameters into final table
        updateTable(tempTable,start);            // updates temp table
        count(flag,tempTable);                   // gets sentinel value
        start = end;                             //updates the starting city to the ending city of the last execution
    }
    //after the loop the final table now contains all of the accurate values and just needs to be printed out
    print(finalTable);
    getTotalDist(finalTable,totalDist);
}

void userTripStartingCities::getTotalDist(QString table,int &totalDist)
{
    data.close();
    data.removeDatabase("first");

    QSqlDatabase customerDatabase = QSqlDatabase::addDatabase("QSQLITE", "first");
    customerDatabase.setDatabaseName("\\Users\\muzzy\\Downloads\\blakeData.db");
    if (customerDatabase.open()) {
        // QMessageBox::information(this, "Database success", "Database Is Connected!");

        //Create query always pass database name into it
        QSqlQuery query(customerDatabase);
        QString value = "SELECT SUM(dist) FROM " + table;

        //Prepare query, run values that you want to retrieve from table
        query.prepare(QString(value)); //change to get data from distances and name of cities

        //Error check
        if (!query.exec())
        {
            QMessageBox::warning(this, "Fail", "Query did not execute");
        }

        query.first();
        totalDist = query.value(0).toInt();
   }
}
void userTripStartingCities::count(int &flag,QString table)
{
    data.close();
    data.removeDatabase("first");

    QSqlDatabase customerDatabase = QSqlDatabase::addDatabase("QSQLITE", "first");
    customerDatabase.setDatabaseName("\\Users\\muzzy\\Downloads\\blakeData.db");
    if (customerDatabase.open()) {
        // QMessageBox::information(this, "Database success", "Database Is Connected!");

        //Create query always pass database name into it
        QSqlQuery query(customerDatabase);
        QString value = "SELECT COUNT(*) FROM " + table;

        //Prepare query, run values that you want to retrieve from table
        query.prepare(QString(value)); //change to get data from distances and name of cities

        //Error check
        if (!query.exec())
        {
            QMessageBox::warning(this, "Fail", "Query did not execute");
        }

        query.first();
        flag = query.value(0).toInt();
   }
}
void userTripStartingCities::clearTable(QString table)
{
    data.close();
    data.removeDatabase("first");

    QSqlDatabase customerDatabase = QSqlDatabase::addDatabase("QSQLITE", "first");
    customerDatabase.setDatabaseName("\\Users\\muzzy\\Downloads\\blakeData.db");
    if (customerDatabase.open()) {
        // QMessageBox::information(this, "Database success", "Database Is Connected!");

        //Create query always pass database name into it
        QSqlQuery query(customerDatabase);

        QString value = "DELETE FROM " + table;

        //Prepare query, run values that you want to retrieve from table
        query.prepare(QString(value)); //change to get data from distances and name of cities

        //Error check
        if (!query.exec())
        {
            QMessageBox::warning(this, "Fail", "Query did not execute");
        }
   }
}
void userTripStartingCities::setTable(QString table1, QString table2)
{
    data.close();
    data.removeDatabase("first");

    QSqlDatabase customerDatabase = QSqlDatabase::addDatabase("QSQLITE", "first");
    customerDatabase.setDatabaseName("\\Users\\muzzy\\Downloads\\blakeData.db");
    if (customerDatabase.open()) {
        // QMessageBox::information(this, "Database success", "Database Is Connected!");

        //Create query always pass database name into it
        QSqlQuery query(customerDatabase);

        QString value = "INSERT INTO " + table1+ " SELECT * FROM "+ table2;

        //Prepare query, run values that you want to retrieve from table
        query.prepare(QString(value)); //change to get data from distances and name of cities

        //Error check
        if (!query.exec())
        {
            QMessageBox::warning(this, "Fail", "Query did not execute");
        }
   }
}
void userTripStartingCities::updateTable(QString table, QString searchVal)
{
    data.close();
    data.removeDatabase("first");

    QSqlDatabase customerDatabase = QSqlDatabase::addDatabase("QSQLITE", "first");
    customerDatabase.setDatabaseName("\\Users\\muzzy\\Downloads\\blakeData.db");
    if (customerDatabase.open()) {
        // QMessageBox::information(this, "Database success", "Database Is Connected!");

        //Create query always pass database name into it
        QSqlQuery query(customerDatabase);

        QString value = "DELETE FROM " + table+ " WHERE Start = :searchVal OR End = :searchVal";

        //Prepare query, run values that you want to retrieve from table
        query.prepare(QString(value)); //change to get data from distances and name of cities
        query.bindValue(":searchVal",searchVal);

        //Error check
        if (!query.exec())
        {
            QMessageBox::warning(this, "Fail", "Query did not execute");
        }
   }

}
userTripStartingCities::~userTripStartingCities()
{
    delete ui;
}


void userTripStartingCities::setupPage()
{
    QFont newFont("courier", 70, QFont::Bold);
    ui->welcomeLabel->setFont(newFont);
    ui->welcomeLabel->setText("11 Cities From Berlin");
    ui->welcomeLabel->setGeometry(450, 50, 700, 100); //EDIT THIS TO FIT YOUR SCREEN
}

void userTripStartingCities::searchMinDist(QString table, QString &start, QString &end, double &dist)
{
    data.close();
    data.removeDatabase("first");

    QSqlDatabase customerDatabase = QSqlDatabase::addDatabase("QSQLITE", "first");
    customerDatabase.setDatabaseName("\\Users\\muzzy\\Downloads\\blakeData.db");
    if (customerDatabase.open()) {
        // QMessageBox::information(this, "Database success", "Database Is Connected!");

        //Create query always pass database name into it
        QSqlQuery query(customerDatabase);

        QString value = "SELECT Start,End, min(dist) FROM " +table+" WHERE Start = :start";
        //Prepare query, run values that you want to retrieve from table
        query.prepare(QString(value)); //change to get data from distances and name of cities
        query.bindValue(":start",start);

        //Error check
        if (!query.exec())
        {
            QMessageBox::warning(this, "Fail", "Query did not execute");
        }

        while(query.next())
        {
            start = query.value(0).toString();
            end = query.value(1).toString();
            dist =  query.value(2).toDouble();
        }
   }
}
void userTripStartingCities::insert(QString table, QString start, QString end, double dist)
{
    data.close();
    data.removeDatabase("first");

    QSqlDatabase customerDatabase = QSqlDatabase::addDatabase("QSQLITE", "first");
    customerDatabase.setDatabaseName("\\Users\\muzzy\\Downloads\\blakeData.db");
    if (customerDatabase.open()) {
        // QMessageBox::information(this, "Database success", "Database Is Connected!");

        //Create query always pass database name into it
        QSqlQuery query(customerDatabase);

        QString value = "INSERT INTO " + table +" (Start, End, Dist) VALUES (:val1, :val2, :val3)";
        //Prepare query, run values that you want to retrieve from table
        query.prepare(QString(value)); //change to get data from distances and name of cities
        query.bindValue(":val1",start);
        query.bindValue(":val2",end);
        query.bindValue(":val3",dist);

        //Error check
        if (!query.exec())
        {
            QMessageBox::warning(this, "Fail", "Query did not execute");
        }
   }
}

void userTripStartingCities::print(QString table)
{
    data.close();
    data.removeDatabase("first");

    QSqlDatabase customerDatabase = QSqlDatabase::addDatabase("QSQLITE", "first");
    customerDatabase.setDatabaseName("\\Users\\muzzy\\Downloads\\blakeData.db");
    if (customerDatabase.open()) {
        // QMessageBox::information(this, "Database success", "Database Is Connected!");

        //Create query always pass database name into it
        QSqlQuery query(customerDatabase);


        QString value = "SELECT * FROM " + table;
        //Prepare query, run values that you want to retrieve from table
        query.prepare(QString(value)); //change to get data from distances and name of cities

        //Error check
        if (!query.exec())
        {
            QMessageBox::warning(this, "Fail", "Query did not execute");
        }

            QSqlQueryModel *search = new QSqlTableModel;
            search->setQuery(query);
            ui->tableView->setGeometry(500, 200, 500, 500);
            ui->tableView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
            ui->tableView->show();
            ui->tableView->setModel(search);
        }
   }
