#include "databasemanager.h"
#include <QSqlQuery>
#include <routelist.h>
#include <query.h>
#include <QDebug>
#include <QSqlError>
#include <calcposition.h>

DatabaseManager::DatabaseManager()
{

}

void DatabaseManager::connectDB()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("/home/radek/baza.db");
    m_db.open();
}

void DatabaseManager::closeDB()
{
    m_db.close();
}

RouteList DatabaseManager::getListOfPositions()
{

    QSqlQuery query(get_route);
    query.prepare(get_route);
    query.bindValue(":id", 3 );


    qDebug() << "Baza otwarta";
if (query.exec())
    while (query.next())
    {
        r.addToPozx(query.value(1).toString());
        r.addToPozy(query.value(2).toString());

    }

r.lon=r.coordToLon(r.pozx);
r.lat=r.coordToLon(r.pozy);
qDebug() << r.coordToLon(r.pozx);
qDebug() << r.coordToLon(r.pozy);



calcPosition c;
c.test(r);
return this->r;


}


