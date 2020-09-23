#ifndef ADMINEDITDATA_H
#define ADMINEDITDATA_H

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
class adminEditData;
}

class adminEditData : public QDialog
{
    Q_OBJECT

public:
    explicit adminEditData(QWidget *parent = nullptr);
    ~adminEditData();

    void setUpPage();

    void addNewCityAndFood();

private slots:
    void on_updateButton_clicked();

    void on_showAll_clicked();


private:
    Ui::adminEditData *ui;
    QString City;
    QString Food;
    double Price;
    QSqlDatabase data;
};

#endif // ADMINEDITDATA_H
