#include "adminaddnewfood.h"
#include "ui_adminaddnewfood.h"

adminAddNewFood::adminAddNewFood(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminAddNewFood)
{
    ui->setupUi(this);
    setupPage();
}

adminAddNewFood::~adminAddNewFood()
{
    delete ui;
}

void adminAddNewFood::setupPage()
{
    QFont newFont("courier", 70, QFont::Bold);
    ui->welcomeLabel->setFont(newFont);
    ui->welcomeLabel->setText("Admin Edit Data");
    ui->welcomeLabel->setGeometry(450, 50, 700, 100); //EDIT THIS TO FIT YOUR SCREEN

    QFont newFont2("courier", 40, QFont::Bold);
    ui->cityLabel->setFont(newFont2);
    ui->cityLabel->setText("Enter City:");
    ui->cityLabel->setGeometry(150, 100, 300, 100);
    ui->cityEdit->setPlaceholderText("I.E. Amsterdam");
    ui->cityEdit->setGeometry(150, 200, 500, 50);
    ui->cityEdit->setFont(newFont2);

    ui->foodLabel->setFont(newFont2);
    ui->foodLabel->setText("Enter Food:");
    ui->foodLabel->setGeometry(150, 300, 300, 100);
    ui->foodEdit->setPlaceholderText("I.E. Fish");
    ui->foodEdit->setGeometry(150, 400, 500, 50);
    ui->foodEdit->setFont(newFont2);

    ui->foodPriceLabel->setFont(newFont2);
    ui->foodPriceLabel->setText("Enter Food Price:");
    ui->foodPriceLabel->setGeometry(150, 500, 600, 100);
    ui->foodPriceEdit->setPlaceholderText("I.E. 17.59");
    ui->foodPriceEdit->setGeometry(150, 600, 500, 50);
    ui->foodPriceEdit->setFont(newFont2);

    ui->updateButton->setGeometry(150, 700, 150, 50);
    ui->updateButton->setText("Add Values");

    ui->showAll->setGeometry(350, 700, 150, 50);
    ui->showAll->setText("Show Data");

    ui->tableView->hide();
}

void adminAddNewFood::on_updateButton_clicked()
{
        data.close();
       data.removeDatabase("first");

       QSqlDatabase customerDatabase = QSqlDatabase::addDatabase("QSQLITE", "first");
       customerDatabase.setDatabaseName("/Users/blakedickerson/Desktop/computerScience/C++/CS1DLebowitz/Projects/Project 1/database/mugbyData.db");

       //Prompt admin for customer attributes
       City = ui->cityEdit->text();
       Food = ui->foodEdit->text();
       Price = ui->foodPriceEdit->text().toDouble();

       if(customerDatabase.open()) {
           QSqlQuery query(customerDatabase);
           //Check capitalize first letter to match database, do not let member get added to database

           query.prepare(QString("INSERT INTO Data (CIty, Food, Price) VALUES (:City, :Food, :Price)"));
           //Put values from line edit into database
           query.bindValue(0, City);
           query.bindValue(1, Food);
           query.bindValue(2, Price);
           if(!query.exec())
           {
               QMessageBox::warning(this, "Fail", "Query did not execute");
           }
           else
           {
               QMessageBox::information(this, "Success", "Data added...");
           }
       }
       else {
           QMessageBox::warning(this, "Fail", "Database not connected!");
       }
}

void adminAddNewFood::on_showAll_clicked()
{
    //close database
       data.close();
       data.removeDatabase("first");

       QSqlDatabase customerDatabase = QSqlDatabase::addDatabase("QSQLITE", "first");
       customerDatabase.setDatabaseName("/Users/blakedickerson/Desktop/computerScience/C++/CS1DLebowitz/Projects/Project 1/database/mugbyData.db");
       if (customerDatabase.open()) {
          // QMessageBox::information(this, "Database success", "Database Is Connected!");

           //Create query always pass database name into it
           QSqlQuery query(customerDatabase);


           //Prepare query, run values that you want to retrieve from table
           query.prepare(QString("SELECT * FROM Data"));

           //Error check
           if (!query.exec()) {
               QMessageBox::warning(this, "Fail", "Query did not execute");
           }
           else
           {

               while(query.next())
               {
                   QString City = query.value(0).toString();
                   QString Food = query.value(1).toString();
                   double Price = query.value(2).toDouble();
               }

               QSqlQueryModel *search = new QSqlTableModel;
               search->setQuery(query);
               ui->tableView->setGeometry(700, 200, 350, 500);
               ui->tableView->show();
               ui->tableView->setModel(search);
           }
       }
}
