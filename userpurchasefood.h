#ifndef USERPURCHASEFOOD_H
#define USERPURCHASEFOOD_H

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
class userPurchaseFood;
}

class userPurchaseFood : public QDialog
{
    Q_OBJECT

public:
    explicit userPurchaseFood(QWidget *parent = nullptr);
    ~userPurchaseFood();

    void setupPage();

private slots:
    void on_searchFoodButton_clicked();

private:
    Ui::userPurchaseFood *ui;
    int itemsInCart;

    QString Food;
    int quantity;
    QSqlDatabase data;
};

#endif // USERPURCHASEFOOD_H
