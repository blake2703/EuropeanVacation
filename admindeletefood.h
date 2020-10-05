#ifndef ADMINDELETEFOOD_H
#define ADMINDELETEFOOD_H

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
class adminDeleteFood;
}

class adminDeleteFood : public QDialog
{
    Q_OBJECT

public:
    explicit adminDeleteFood(QWidget *parent = nullptr);
    ~adminDeleteFood();

    void setupPage();

private slots:
    void on_updateButton_clicked();

    void on_showAll_clicked();

private:
    Ui::adminDeleteFood *ui;
    QString City;
    QString Food;
    double Price;
    QSqlDatabase data;
};

#endif // ADMINDELETEFOOD_H