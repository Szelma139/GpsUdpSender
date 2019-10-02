#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <routelist.h>

class DatabaseManager
{
public:
    DatabaseManager();
    QSqlDatabase  m_db;
    void connectDB();
    void closeDB();
    RouteList  getListOfPositions();
    RouteList  r;

};

#endif // DATABASEMANAGER_H
