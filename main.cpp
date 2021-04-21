#include <QCoreApplication>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QFile>
#include <QDate>
#include <QDebug>

void printSqlite();
void recordSqlite();
void deleteSqlite();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:/QtProject/qmlsqlite/MedicalMeasurements.db3");//для windows
    db.open();

    printSqlite();


    db.close();

    return a.exec();
}

void printSqlite()
{
    QSqlQuery query;
    query.exec("SELECT NUMBERPERDAY, PROBENUMBER, DATEYEAR, DATEMONTH, DATEDAY, TIMEHOUR, TIMEMINUTE, GL, LC, BARCODE FROM TABLEMEDICALMEASUREMENTS");
    while(query.next()){
        //QString id = query.value(0).toString();
        QString number_per_day = query.value(1).toString();
        QString probe_number = query.value(2).toString();
        QString date_year = query.value(3).toString();
        QString date_month = query.value(4).toString();
        QString date_day = query.value(5).toString();
        QString time_hour = query.value(6).toString();
        QString time_minute = query.value(7).toString();
        QString gl = query.value(8).toString();
        QString lc = query.value(9).toString();
        QString bar_code = query.value(10).toString();
        qDebug() << number_per_day << " " << probe_number << " " << date_year << " " << date_month << " "
                 << date_day << " " << time_hour << " " << time_minute << " " << gl << " " << lc << " " << bar_code;
    }
}

void recordSqlite()
{

}

void deleteSqlite()
{

}
