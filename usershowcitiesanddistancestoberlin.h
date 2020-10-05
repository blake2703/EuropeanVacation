#ifndef USERSHOWCITIESANDDISTANCESTOBERLIN_H
#define USERSHOWCITIESANDDISTANCESTOBERLIN_H

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
class userShowCitiesAndDistancesToBerlin;
}

class userShowCitiesAndDistancesToBerlin : public QDialog
{
    Q_OBJECT

public:
    explicit userShowCitiesAndDistancesToBerlin(QWidget *parent = nullptr);
    ~userShowCitiesAndDistancesToBerlin();

    void setupPage();

private:
    Ui::userShowCitiesAndDistancesToBerlin *ui;
    QSqlDatabase data;
};

#endif // USERSHOWCITIESANDDISTANCESTOBERLIN_H
