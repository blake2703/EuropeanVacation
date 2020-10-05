#include "userpurchasefood.h"
#include "ui_userpurchasefood.h"

userPurchaseFood::userPurchaseFood(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::userPurchaseFood)
{
    ui->setupUi(this);
    setupPage();
}

userPurchaseFood::~userPurchaseFood()
{
    delete ui;
}

void userPurchaseFood::setupPage()
{
    QFont welcomeFont("Courier", 70, QFont::Bold);
    ui->Heading->setFont(welcomeFont);
    ui->Heading->setAlignment(Qt::AlignCenter);
    ui->Heading->setStyleSheet("color: black");
    ui->Heading->setText("Welcome User!");
    ui->Heading->setGeometry(450, 50, 700, 100); //EDIT THIS TO FIT YOUR SCREEN

    QFont newFont2("courier", 40, QFont::Bold);
    ui->foodItemLabel->setFont(newFont2);
    ui->foodItemLabel->setText("Enter Food Item:");
    ui->foodItemLabel->setGeometry(150, 200, 400, 100);
    ui->foodItemEdit->setPlaceholderText("I.E. Fish");
    ui->foodItemEdit->setGeometry(150, 300, 500, 50);
    ui->foodItemEdit->setFont(newFont2);

    ui->foodItemToPurchaseLabel->setFont(newFont2);
    ui->foodItemToPurchaseLabel->setText("Quantity:");
    ui->foodItemToPurchaseLabel->setGeometry(150, 400, 400, 100);
    ui->foodItemToPurchaseEdit->setPlaceholderText("I.E. Fish");
    ui->foodItemToPurchaseEdit->setGeometry(150, 500, 500, 50);
    ui->foodItemToPurchaseEdit->setFont(newFont2);

    ui->searchFoodButton->setGeometry(150, 700, 150, 50);
    ui->searchFoodButton->setText("Add Values");






//    itemsInCart = 0;
//    ui->CartHeading->setText("How many food items would you like to purchase?");
//    ui->CartHeading->setStyleSheet("font: 18pt;");
//    ui->CartHeading->setGeometry(100, 100, 850, 50);

//    ui->CardNumber->setText("Enter Card Number: ");

//    ui->CardNameHolder->setText("Enter Card NameHolder: ");
//    ui->CardNameHolderEdit->setReadOnly(true);
//    ui->CardNameHolderEdit->setPlaceholderText("Must Enter a Valid Quantity To Cart");


}

void userPurchaseFood::on_searchFoodButton_clicked()
{
    data.close();
    data.removeDatabase("first");

    QSqlDatabase customerDatabase = QSqlDatabase::addDatabase("QSQLITE", "first");
    customerDatabase.setDatabaseName("/Users/blakedickerson/Desktop/computerScience/C++/CS1DLebowitz/Projects/Project 1/database/mugbyData.db");

    //Prompt admin for customer attributes
    Food = ui->foodItemEdit->text();
    quantity = ui->foodItemToPurchaseEdit->text().toDouble();

    if(customerDatabase.open()) {
        QSqlQuery query(customerDatabase);
        //Check capitalize first letter to match database, do not let member get added to database

        query.prepare(QString("SELECT * FROM Data WHERE CIty = :City AND Food = :Food"));
        //Put values from line edit into database
        query.bindValue(0, quantity);
        query.bindValue(1, Food);
        if(!query.exec())
        {
            QMessageBox::warning(this, "Fail", "Query did not execute");
        }
        int count = 0;
                   while (query.next())
                   {
                       count++;
                   }
                   if (count == 1)
                   {
                       //found
                       QMessageBox::information(this, "Success", "Food Found");
                       //delete
                       query.prepare(QString("UPDATE Data SET Price = :Price WHERE Food = :Food"));
                       //query.bindValue(":CIty", City);
                       query.bindValue(":Food", Food);
                       query.bindValue(":Price", quantity);


                       if (!query.exec())
                       {
                           QMessageBox::warning(this, "Fail", "Query did not execute");
                       }
                       else
                       {
                           QMessageBox::information(this, "Success", "Price Updated");
                       }
                   }
                   else
                   {
                       //not found
                       QMessageBox::information(this, "Fail", "Food was not found");
                       //prompt for another attempt
                   }
               }

           else
           {
               QMessageBox::warning(this, "Fail", "Database did not open");
           }
}
