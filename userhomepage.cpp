#include "userhomepage.h"
#include "ui_userhomepage.h"

userHomepage::userHomepage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::userHomepage)
{
    ui->setupUi(this);
    setStyleSheet("background-color: white");
    setupPage();
}

userHomepage::~userHomepage()
{
    delete ui;
}

void userHomepage::setupPage()
{
    QFont welcomeFont("Courier", 70, QFont::Bold);
    ui->welcomeLabel->setFont(welcomeFont);
    ui->welcomeLabel->setAlignment(Qt::AlignCenter);
    ui->welcomeLabel->setStyleSheet("color: black");
    ui->welcomeLabel->setText("Welcome User!");
    ui->welcomeLabel->setGeometry(450, 50, 700, 100); //EDIT THIS TO FIT YOUR SCREEN

    QFont userFont("Courier", 15, QFont::Bold);
    ui->CitiesAndDistancesFromBerlinButton->setFont(userFont);
    ui->CitiesAndDistancesFromBerlinButton->setText("Cities With distances to Berlin");
    ui->CitiesAndDistancesFromBerlinButton->setStyleSheet("color: black");
    ui->CitiesAndDistancesFromBerlinButton->setStyleSheet("background-color: black");
    ui->CitiesAndDistancesFromBerlinButton->setGeometry(600, 200, 300, 50);

    ui->startingCitiesButton->setFont(userFont);
    ui->startingCitiesButton->setText("Cities With distances to Berlin");
    ui->startingCitiesButton->setStyleSheet("color: black");
    ui->startingCitiesButton->setStyleSheet("background-color: black");
    ui->startingCitiesButton->setGeometry(600, 300, 300, 50);

    ui->purchaseFoodButton->setFont(userFont);
    ui->purchaseFoodButton->setText("Purchase Food");
    ui->purchaseFoodButton->setStyleSheet("color: black");
    ui->purchaseFoodButton->setStyleSheet("background-color: black");
    ui->purchaseFoodButton->setGeometry(600, 400, 300, 50);


}

void userHomepage::on_CitiesAndDistancesFromBerlinButton_clicked()
{
    userShowCitiesAndDistancesToBerlin newPage;
    newPage.setModal(true);
    newPage.showMaximized();
    newPage.exec();
}

void userHomepage::on_startingCitiesButton_clicked()
{
    userTripStartingCities newCity;
    newCity.setModal(true);
    newCity.showMaximized();
    newCity.exec();
}

void userHomepage::on_purchaseFoodButton_clicked()
{
    userPurchaseFood newFood;
    newFood.setModal(true);
    newFood.showMaximized();
    newFood.exec();
}
