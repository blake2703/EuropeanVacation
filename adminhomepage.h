#ifndef ADMINHOMEPAGE_H
#define ADMINHOMEPAGE_H

#include <QDialog>

#include "admineditCity.h"
#include "adminchangefoodprice.h"
#include "adminaddnewfood.h"
#include "admindeletefood.h"

namespace Ui {
class adminHomepage;
}

class adminHomepage : public QDialog
{
    Q_OBJECT

public:
    explicit adminHomepage(QWidget *parent = nullptr);
    ~adminHomepage();

    void setupPage();

private slots:


    void on_foodPriceUpdate_clicked();

    void on_newFoodUpdate_clicked();

    void on_deleteFoodUpdate_clicked();

    void on_editCityUpdate_clicked();

private:
    Ui::adminHomepage *ui;
};

#endif // ADMINHOMEPAGE_H
