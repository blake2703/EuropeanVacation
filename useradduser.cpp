#include "useradduser.h"
#include "ui_useradduser.h"

userAddUser::userAddUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::userAddUser)
{
    ui->setupUi(this);
    setupPage();
}

userAddUser::~userAddUser()
{
    delete ui;
}

void userAddUser::setupPage()
{
    QFont newFont("courier", 70, QFont::Bold);
    ui->welcomeLabel->setFont(newFont);
    ui->welcomeLabel->setText("User Sign Up");
    ui->welcomeLabel->setGeometry(450, 50, 700, 100); //EDIT THIS TO FIT YOUR SCREEN

    QFont newFont2("courier", 40, QFont::Bold);
    ui->userNameLabel->setFont(newFont2);
    ui->userNameLabel->setText("Enter Username:");
    ui->userNameLabel->setGeometry(150, 200, 400, 100);
    ui->usernameEdit->setPlaceholderText("I.E. mugbyRocks");
    ui->usernameEdit->setGeometry(150, 300, 500, 50);
    ui->usernameEdit->setFont(newFont2);


    //if theres time put a limiting factor on password
    ui->passwordLabel->setFont(newFont2);
    ui->passwordLabel->setText("Enter Password:");
    ui->passwordLabel->setGeometry(150, 400, 400, 100);
    ui->passwordEdit->setPlaceholderText("I.E. mugbyIsABeast");
    ui->passwordEdit->setGeometry(150, 500, 500, 50);
    ui->passwordEdit->setFont(newFont2);

    ui->updateButton->setGeometry(150, 700, 150, 50);
    ui->updateButton->setText("Add Values");
}

void userAddUser::on_updateButton_clicked()
{
   data.close();
   data.removeDatabase("first");

   QSqlDatabase customerDatabase = QSqlDatabase::addDatabase("QSQLITE", "first");
   customerDatabase.setDatabaseName("/Users/blakedickerson/Desktop/computerScience/C++/CS1DLebowitz/Projects/Project 1/database/mugbyData.db");

   //Prompt admin for customer attributes
   username = ui->usernameEdit->text();
   password = ui->passwordEdit->text();

   if(customerDatabase.open()) {
       QSqlQuery query(customerDatabase);
       //Check capitalize first letter to match database, do not let member get added to database

       query.prepare(QString("INSERT INTO Users (username, password) VALUES (:username, :password)"));
       //Put values from line edit into database
       query.bindValue(0, username);
       query.bindValue(1, password);
       if(!query.exec())
       {
           QMessageBox::warning(this, "Fail", "Query did not execute");
       }
       else
       {
           QMessageBox::information(this, "Success", "User added...");
       }
   }
   else {
       QMessageBox::warning(this, "Fail", "Database not connected!");
   }
}

