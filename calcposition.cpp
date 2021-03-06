#include "calcposition.h"
#include <QDebug>
#include <math.h>
#include <algorithm>
#include <ostream>


calcPosition::calcPosition()
{

}



void calcPosition::sendToNext(RouteList r)
{
    szybkosc = 50;
    //masz szybkosc i wspolrzedne startowe i docelowe, musze obliczyc psorednie

}

void calcPosition::tripToOne(RouteList r)
{
    double currentLat, currentLon;
    currentLat = r.lat.front();
    currentLon = r.lon.front();

     while(currentLat >= r.lat[1] &&
           currentLon >= r.lon[1])
     {

     }
}

void calcPosition::calcNextPoint(RouteList r)
{
   double lat = toRadian(r.lat[0]);
   double lon = toRadian(r.lon[0]);
   double nextLat=toRadian(r.lat[1]);
   double nextLon=toRadian(r.lon[1]);

}

void calcPosition::test(RouteList r)
{
    double lat,lon,dist;
    double nextLat, nextLon;
    double latNew,lonNew;
    //lat=r.lat.front();
    //lon=r.lon.front();

    for (int i =0 ; i<r.lat.size(); i++)
    {
        qDebug() << "Size w tym momencie - " << i;
        lat = r.lat[i];
        lon = r.lon[i];
        if (i+1 >=r.lat.size()) return;
        nextLat=r.lat[i+1];
        nextLon=r.lon[i+1];
        auto bearing = calBearing(r);
        dist = 0.01388;
        double R = 6371e3;

        double lat1=toRadian(lat);
        double lat2=toRadian(nextLat);
        double dLat=toRadian(nextLat-lat);
        double dLon=toRadian(nextLon-lon);

        double a = sin(dLat/2) * sin(dLat/2) +
                cos(lat1) * cos(lat2) *
                sin(dLon/2) * sin(dLon/2);

        double c = 2 * atan2(sqrt(a), sqrt(1-a));

        auto d = R * c /1000;  //w km

        auto p =d;


        qDebug() << "Odcinek trasy pomierdzy przystankami " << d << "km";

        //d dystans
        R = 6371e3;
        d = 0.1388;
        auto la = toDegree(asin( sin(lat1) * cos(d/R) +
                                 cos(lat1) * sin(d/R) * cos( bearing)));

        auto lo = lon + atan2(sin(bearing) * sin(d/R) * cos(lat1),
                              cos(d/R) - sin(lat1) * sin(la));

        qDebug()<< i <<" Lat - " <<QString::number(la, 'g', 10)
                <<"  Lon - "<< QString::number(lo, 'g', 10) << "dla odcinka " << d << "km";
        qDebug() << "Lat -  52.59055487   Lon -  21.42633887 dla dystansu " << p;


    } //tutaj
}

double calcPosition::toRadian(double input)
{
    // const double halfC = M_PI/180;
    // double degree = input *halfC;
    double radian = (input * M_PI)/180;
    return radian;
}

double calcPosition::toDegree(double input)
{
    double degree = (input * 180)/M_PI;
    return degree;
}




double calcPosition::calBearing(RouteList r)
{

    double lat1Rad,lat2Rad,lon1Rad,lon2Rad;
    lat1Rad=toRadian(r.lat.front());
    lon1Rad=toRadian(r.lon.front());
    lat2Rad=toRadian(r.lat.back());
    lon2Rad=toRadian(r.lon.back());
    //to bylo oryginalne
    //auto y = sin(lon2-lon1) * cos(lat2);
    // auto x = cos (lat1) * sin (lat2) -
    //  sin (lat1) * cos ((lat2)) * cos(lon2-lon1);
    auto x = cos(lat1Rad) * sin(lat2Rad) -
            sin(lat1Rad) * cos(lat2Rad) * cos(lon2Rad - lon1Rad);
    auto y = sin(lon2Rad-lon1Rad) * cos(lat2Rad);
    auto brng = toDegree(atan2(y, x));
    if (brng <0 ) brng = brng + 360;
    qDebug() <<"Azymut koncowy"<< brng;


    return brng;

}

