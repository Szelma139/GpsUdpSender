#include "routelist.h"
#include <ostream>
#include <QDebug>


RouteList::RouteList()
{

}


void RouteList::addToPozx(QString x)
{
    pozx.push_back(x);
}

void RouteList::addToPozy(QString y)
{
    pozy.push_back(y);
}

QString RouteList::getPozX()
{
    for (auto it = pozx.begin(); it!= pozx.end(); it++)
    {
        return *it;
    }

}

QString RouteList::getPozY()
{
    for (auto it = pozy.begin(); it!= pozy.end(); it++)
    {
        return *it;
    }

}

QString RouteList::getFirstX()
{
    return pozx.front();
}

QString RouteList::getFirstY()
{
    return pozy.front();
}

QString RouteList::getLastX()
{
    return pozx.back();
}

QString RouteList::getLastY()
{
    return pozy.back();
}

QString RouteList::getAzimuthAtoB()
{


}



QVector<double> RouteList::coordToLon(QVector<QString> vec)
{
    //x pierwsza wartosc
    QString strDD,strMM;
    double dd,mm,lon;
    QVector<double> coord;
    for (int i=0; i<vec.size(); i++)
    {

        QString t = vec[i]; //aktualy element wektora
        strDD = t.mid(0,2); //stopnie
        strMM=t.mid(2,2) + "." + t.mid(4,4); //minuty
        dd=strDD.toDouble();
        mm=strMM.toDouble();
        lon = dd + (mm/60);
coord.push_back(lon);


        //QString strLon = pozy[i];

        //return *it;
    }
    return coord;
}

//double RouteList::coordToLat(QVector<QString> vec)
//{
    //y druga wartosc
//}


