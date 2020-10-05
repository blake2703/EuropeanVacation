#include "usertripstartingcities.h"
#include "ui_usertripstartingcities.h"

#include <qqueue.h>

userTripStartingCities::userTripStartingCities(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::userTripStartingCities)
{
    ui->setupUi(this);

    setupPage();
    //insert();
    print();
    find();
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

void userTripStartingCities::find()
{
    data.close();
    data.removeDatabase("first");
    QSqlDatabase customerDatabase = QSqlDatabase::addDatabase("QSQLITE", "first");
    customerDatabase.setDatabaseName("/Users/blakedickerson/Desktop/computerScience/C++/CS1DLebowitz/Projects/Project 1/database/mugbyData.db");
    if (customerDatabase.open())
    {
        QSqlQuery query(customerDatabase);
        query.prepare(QString("SELECT Start, End, MIN(Dist) FROM Cities WHERE Start = 'Berlin'"));
        while (query.next())
        {
            start = query.value(0).toString();
            end = query.value(1).toString(); //change
            distance = query.value(2).toDouble(); //change
        }
        qDebug() << start << end << distance;

    }

}

void userTripStartingCities::insert(QString temp)
{
    QVector<QString> newVec;
    newVec = {"Amsterdam", "Brussels", "Budapest", "Berlin", "Hamburg", "Lisbon", "London", "Madrid", "Paris", "Prague", "Rome"};
    data.close();
    data.removeDatabase("first");
    start = "Berlin";
    QSqlDatabase customerDatabase = QSqlDatabase::addDatabase("QSQLITE", "first");
    customerDatabase.setDatabaseName("/Users/blakedickerson/Desktop/computerScience/C++/CS1DLebowitz/Projects/Project 1/database/mugbyData.db");
    if (customerDatabase.open())
    {
        // QMessageBox::information(this, "Database success", "Database Is Connected!");

        //Create query always pass database name into it
        QSqlQuery query(customerDatabase);

        //Prepare query, run values that you want to retrieve from table


       // while (!newVec.empty())
        //{
            query.prepare(QString("INSERT INTO dummy (Start, End, Dist) SELECT Start, End, MIN(Dist) FROM Cities WHERE Start = :start")); //change to get data from distances and name of cities
            //Error check
            query.bindValue(":start", start);
            if (!query.exec()) {
                QMessageBox::warning(this, "Fail", "Query did not execute");
            }
           // else
         //   {
            //    while(query.next())
//                {
//                    start = query.value(0).toString();
//                    end = query.value(1).toString(); //change
//                    distance = query.value(2).toDouble(); //change
//                    query.bindValue(":Start", end);
//                    query.bindValue("End", end);
//                    query.bindValue(":Dist", distance);
//                }
//                  qDebug() << start << " " << end << " " << distance;


//            }
//           // QVector<QStrin/g>::iterator it = newVec.begin();
//            for (int index = 0; index < newVec.size(); index++)
//            {
//                if (newVec.at(index) == start)
//                {
//                    newVec.erase(index + it);
//                    break;
//                }
//            }

      //  }
//        for (int i = 0; i < newVec.size(); i++)
//        {
//            qDebug() << newVec << " ";
//        }
    }
}

void userTripStartingCities::print()
{
    data.close();
    data.removeDatabase("first");

    QSqlDatabase customerDatabase = QSqlDatabase::addDatabase("QSQLITE", "first");
    customerDatabase.setDatabaseName("/Users/blakedickerson/Desktop/computerScience/C++/CS1DLebowitz/Projects/Project 1/database/mugbyData.db");
    if (customerDatabase.open()) {
        // QMessageBox::information(this, "Database success", "Database Is Connected!");

        //Create query always pass database name into it
        QSqlQuery query(customerDatabase);


        //Prepare query, run values that you want to retrieve from table
        query.prepare(QString("SELECT * FROM dummy")); //change to get data from distances and name of cities

        //Error check
        if (!query.exec()) {
            QMessageBox::warning(this, "Fail", "Query did not execute");
        }
        else
        {

            //            while(query.next())
            //            {
            //                QString Start = query.value(0).toString();
            //                QString End = query.value(1).toString(); //change
            //                double Distance = query.value(2).toDouble(); //change
            //            }

            QSqlQueryModel *search = new QSqlTableModel;
            search->setQuery(query);
            ui->tableView->setGeometry(500, 200, 500, 500);
            ui->tableView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
            ui->tableView->show();
            ui->tableView->setModel(search);
        }
    }
}
