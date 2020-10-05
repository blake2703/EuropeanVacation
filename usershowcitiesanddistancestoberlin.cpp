#include "usershowcitiesanddistancestoberlin.h"
#include "ui_usershowcitiesanddistancestoberlin.h"

#include "QScrollBar"
#include "QtGui"

userShowCitiesAndDistancesToBerlin::userShowCitiesAndDistancesToBerlin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::userShowCitiesAndDistancesToBerlin)
{
    ui->setupUi(this);
    setupPage();
}

userShowCitiesAndDistancesToBerlin::~userShowCitiesAndDistancesToBerlin()
{
    delete ui;
}

void userShowCitiesAndDistancesToBerlin::setupPage()
{
    QFont newFont("courier", 70, QFont::Bold);
    ui->welcomeLabel->setFont(newFont);
    ui->welcomeLabel->setText("Cities And Distances");
    ui->welcomeLabel->setGeometry(450, 50, 700, 100); //EDIT THIS TO FIT YOUR SCREEN

    data.close();
    data.removeDatabase("first");

    QSqlDatabase customerDatabase = QSqlDatabase::addDatabase("QSQLITE", "first");
    customerDatabase.setDatabaseName("/Users/blakedickerson/Desktop/computerScience/C++/CS1DLebowitz/Projects/Project 1/database/mugbyData.db");
    if (customerDatabase.open()) {
       // QMessageBox::information(this, "Database success", "Database Is Connected!");

        //Create query always pass database name into it
        QSqlQuery query(customerDatabase);


        //Prepare query, run values that you want to retrieve from table
        query.prepare(QString("SELECT * FROM Cities")); //change to get data from distances and name of cities

        //Error check
        if (!query.exec()) {
            QMessageBox::warning(this, "Fail", "Query did not execute");
        }
        else
        {

            while(query.next())
            {
                QString Start = query.value(0).toString();
                QString End = query.value(1).toString(); //change
                double Distance = query.value(2).toDouble(); //change
            }

            QSqlQueryModel *search = new QSqlTableModel;
            search->setQuery(query);
            ui->tableView->setGeometry(500, 200, 500, 500);
            ui->tableView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
            ui->tableView->show();
            ui->tableView->setModel(search);
        }
    }
}
