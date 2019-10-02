#ifndef ROUTELIST_H
#define ROUTELIST_H
#include <QVector>
#include <QList>

class RouteList
{
public:
    RouteList();
    QVector <QString> pozx;
    QVector <QString> pozy;
    QVector <double> lon;
    QVector <double> lat;

    void addToPozx(QString x);
    void addToPozy(QString y);
    QString getPozX();
    QString getPozY();
    QString getFirstX();
    QString getFirstY();
    QString getLastX();
    QString getLastY();
    QString getAzimuthAtoB();
    QVector<double> coordToLon(QVector<QString> vec);
    //QVector<double> coordToLat(QVector<QString> vec);


};

#endif // ROUTELIST_H
