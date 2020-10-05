#ifndef USERHOMEPAGE_H
#define USERHOMEPAGE_H

#include <QDialog>
#include "usershowcitiesanddistancestoberlin.h"
#include "usertripstartingcities.h"
#include "userpurchasefood.h"

namespace Ui {
class userHomepage;
}

class userHomepage : public QDialog
{
    Q_OBJECT

public:
    explicit userHomepage(QWidget *parent = nullptr);
    ~userHomepage();

    void setupPage();

private slots:
    void on_CitiesAndDistancesFromBerlinButton_clicked();

    void on_startingCitiesButton_clicked();

    void on_purchaseFoodButton_clicked();

private:
    Ui::userHomepage *ui;
};

#endif // USERHOMEPAGE_H
