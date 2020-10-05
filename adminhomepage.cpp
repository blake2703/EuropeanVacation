#include "adminhomepage.h"
#include "ui_adminhomepage.h"

adminHomepage::adminHomepage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminHomepage)
{
    ui->setupUi(this);
    setStyleSheet("background-color: white");
    setupPage();
}

adminHomepage::~adminHomepage()
{
    delete ui;
}

void adminHomepage::setupPage()
{
    QFont welcomeFont("Courier", 70, QFont::Bold);
    ui->welcomeLabel->setFont(welcomeFont);
    ui->welcomeLabel->setAlignment(Qt::AlignCenter);
    ui->welcomeLabel->setStyleSheet("color: black");
    ui->welcomeLabel->setText("Welcome Admin!");
    ui->welcomeLabel->setGeometry(450, 50, 700, 100); //EDIT THIS TO FIT YOUR SCREEN

    QFont userFont("Courier", 15, QFont::Bold);
    ui->editCityUpdate->setFont(userFont);
    ui->editCityUpdate->setText("Add New City And Food");
    ui->editCityUpdate->setStyleSheet("color: black");
    ui->editCityUpdate->setStyleSheet("background-color: black");
    ui->editCityUpdate->setGeometry(600, 200, 300, 50);

    ui->foodPriceUpdate->setFont(userFont);
    ui->foodPriceUpdate->setText("Update Food Price");
    ui->foodPriceUpdate->setStyleSheet("color: black");
    ui->foodPriceUpdate->setStyleSheet("background-color: black");
    ui->foodPriceUpdate->setGeometry(600, 300, 300, 50);

    ui->newFoodUpdate->setFont(userFont);
    ui->newFoodUpdate->setText("Add New Food");
    ui->newFoodUpdate->setStyleSheet("color: black");
    ui->newFoodUpdate->setStyleSheet("background-color: black");
    ui->newFoodUpdate->setGeometry(600, 400, 300, 50);

    ui->deleteFoodUpdate->setFont(userFont);
    ui->deleteFoodUpdate->setText("Delete Food");
    ui->deleteFoodUpdate->setStyleSheet("color: black");
    ui->deleteFoodUpdate->setStyleSheet("background-color: black");
    ui->deleteFoodUpdate->setGeometry(600, 500, 300, 50);


}


void adminHomepage::on_foodPriceUpdate_clicked()
{
    adminChangeFoodPrice newFood;
    newFood.setModal(true);
    newFood.showMaximized();
    newFood.exec();
}

void adminHomepage::on_newFoodUpdate_clicked()
{
    adminAddNewFood newFood;
    newFood.setModal(true);
    newFood.showMaximized();
    newFood.exec();
}

void adminHomepage::on_deleteFoodUpdate_clicked()
{
    adminDeleteFood newFood;
    newFood.setModal(true);
    newFood.showMaximized();
    newFood.exec();
}

void adminHomepage::on_editCityUpdate_clicked()
{
    adminEditData newEdit;
    newEdit.setModal(true);
    newEdit.showMaximized();
    newEdit.exec();
}
