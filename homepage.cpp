#include "homepage.h"
#include "ui_homepage.h"

#include <QColor>
#include <QPixmap>
#include <QPainter>
#include <QDebug>


homepage::homepage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::homepage)
{
    ui->setupUi(this);
   // showMaximized();


    QSize movieSize;
    movieSize.setWidth(500);
    movieSize.setHeight(200);
    QMovie *movie = new QMovie("/Users/blakedickerson/Downloads/vaca.gif");
    movie->setSpeed(50);
    QLabel *processLabel = new QLabel(this);
    //processLabel->setGeometry(400, 50, 3000, 300);
    movie->setScaledSize(movieSize);
    processLabel->setMovie(movie);
    processLabel->setGeometry(0, 0, 500, 200); //EDIT THIS TO FIT YOUR SCREEN
    movie->start();

    QSize movieSize2;
    movieSize2.setWidth(500);
    movieSize2.setHeight(200);
    QMovie *movie2 = new QMovie("/Users/blakedickerson/Downloads/vaca.gif");
    movie2->setSpeed(50);
    QLabel *processLabel2 = new QLabel(this);
    //processLabel->setGeometry(400, 50, 3000, 300);
    movie2->setScaledSize(movieSize);
    processLabel2->setMovie(movie);
    processLabel2->setGeometry(900, 0, 500, 200); //EDIT THIS TO FIT YOUR SCREEN
    movie2->start();


    createWelcomeLabel();
    createAdminCredentials();
    createAdminLoginButton();
    createUserCredentials();
    createUserLoginButton();

    setStyleSheet("background-color: white");
    showMaximized();
}

homepage::~homepage()
{
    delete ui;
}

void homepage::createWelcomeLabel()
{
    QFont welcomeFont("Courier", 70, QFont::Bold);
    ui->welcomeLabel->setFont(welcomeFont);
    ui->welcomeLabel->setAlignment(Qt::AlignCenter);
    ui->welcomeLabel->setStyleSheet("color: black");
    ui->welcomeLabel->setText("Welcome!");
    ui->welcomeLabel->setGeometry(450, 50, 500, 100); //EDIT THIS TO FIT YOUR SCREEN
}

void homepage::createAdminCredentials()
{
    QFont firstNameFont("Courier", 25, QFont::Bold);
    QFont firstNameFont2("Courier", 40, QFont::Bold);

    ui->adminUsernameLabel->setFont(firstNameFont2);
    ui->adminUsernameLabel->setStyleSheet("color:black");
    ui->adminUsernameLabel->setText("Admin?");
    ui->adminUsernameLabel->setGeometry(650, 250, 350, 50); //EDIT THIS TO FIT YOUR SCREEN

    ui->adminUsernameEdit->setFont(firstNameFont);
    ui->adminUsernameEdit->setStyleSheet("color: black");
    ui->adminUsernameEdit->setPlaceholderText("What is your username?");
    ui->adminUsernameEdit->setGeometry(150, 300, 350, 50); //EDIT THIS TO FIT YOUR SCREEN

    ui->adminPasswordEdit->setFont(firstNameFont);
    ui->adminPasswordEdit->setPlaceholderText("What is your password?");
    ui->adminPasswordEdit->setStyleSheet("color: black");
    ui->adminPasswordEdit->setEchoMode(QLineEdit::Password);
    ui->adminPasswordEdit->setGeometry(850, 300, 350, 50); //EDIT THIS TO FIT YOUR SCREEN
}

void homepage::createAdminLoginButton()
{
    QFont userFont("Courier", 15, QFont::Bold);
    ui->adminLoginButton->setFont(userFont);
    ui->adminLoginButton->setText("Log In");
    ui->adminLoginButton->setStyleSheet("color: black");
    ui->adminLoginButton->setStyleSheet("background-color: black");
    ui->adminLoginButton->setGeometry(650, 400, 100, 50);
}

void homepage::createUserCredentials()
{
    QFont firstNameFont("Courier", 25, QFont::Bold);
    QFont firstNameFont2("Courier", 40, QFont::Bold);

    ui->userLabel->setFont(firstNameFont2);
    ui->userLabel->setStyleSheet("color:black");
    ui->userLabel->setText("User?");
    ui->userLabel->setGeometry(650, 550, 350, 50); //EDIT THIS TO FIT YOUR SCREEN

    ui->userUsernameEdit->setFont(firstNameFont);
    ui->userUsernameEdit->setStyleSheet("color: black");
    ui->userUsernameEdit->setPlaceholderText("What is your username?");
    ui->userUsernameEdit->setGeometry(150, 600, 350, 50); //EDIT THIS TO FIT YOUR SCREEN

    ui->userPasswordEdit->setFont(firstNameFont);
    ui->userPasswordEdit->setPlaceholderText("What is your password?");
    ui->userPasswordEdit->setStyleSheet("color: black");
    ui->userPasswordEdit->setEchoMode(QLineEdit::Password);
    ui->userPasswordEdit->setGeometry(850, 600, 350, 50); //EDIT THIS TO FIT YOUR SCREEN
}

void homepage::createUserLoginButton()
{
    QFont userFont("Courier", 15, QFont::Bold);
    ui->userLoginButton->setFont(userFont);
    ui->userLoginButton->setText("Log In");
    ui->userLoginButton->setStyleSheet("color: black");
    ui->userLoginButton->setStyleSheet("background-color: black");
    ui->userLoginButton->setGeometry(650, 700, 100, 50);
}


void homepage::on_adminLoginButton_clicked()
{
    //Allow our Qstring var to match user input
    QString username = ui->adminUsernameEdit->text();
    QString password = ui->adminPasswordEdit->text();

    //Close database
    data.close();
    data.removeDatabase("first");

    //Add database and set name
    data = QSqlDatabase::addDatabase("QSQLITE", "first");
    data.setDatabaseName("/Users/blakedickerson/Desktop/computerScience/C++/CS1DLebowitz/Projects/Project 1/database/mugbyData.db");

    //Check to see if database is open
    if (data.open())
    {
        //QMessageBox::information(this, "Success", "Yes");

        //Declare query for username
        QSqlQuery query(data);

        //Declare query for password
        QSqlQuery passQuery(data);

        //prepare query
        query.prepare(QString("SELECT * FROM Admin WHERE username = :username AND password = :password"));

        //Bind values
        query.bindValue(":username", username);
        query.bindValue(":password", password);

        //Check to see if query executed
        if (!query.exec())
        {
            QMessageBox::warning(this, "Fail", "Query did not execute");
        }
        //else query is good
        else
        {
            int count = 0; //count var

            while(query.next())
            {
                count++; //inc count if the query is able to get to the end of email and pass and match them
            }
            if (count == 1)
            {
                QFont newFont("Courier", 20, QFont::Bold);
                QMessageBox myBox;
                myBox.setFont(newFont);
                myBox.setText("Username and password correct.");
                myBox.setInformativeText("Would you like to continue?");
                myBox.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
                myBox.setDefaultButton(QMessageBox::Yes);
                myBox.setStyleSheet("color: white");
                myBox.setBaseSize(QSize(500, 150));
               int yes = myBox.exec();
               if (yes == QMessageBox::Yes)
               {
                   //open new page
                   adminHomepage newHomepage;
                   newHomepage.setModal(true);
                   newHomepage.showMaximized();
                   newHomepage.exec();
               }
               else
               {
                   //reset
               }
            }
            else
            {
                qDebug() << "no";
            }

    }
    data.close();
    data.removeDatabase("first");

}


}
