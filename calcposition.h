#ifndef CALCPOSITION_H
#define CALCPOSITION_H
#include <routelist.h>

class calcPosition
{
public:
    calcPosition();
    double szybkosc;
    double azymut;
    void sendToNext(RouteList r);
    double poz_startX, poz_startY;
    double poz_docelX, poz_docelY;
    void test(RouteList r);
    double toRadian(double input);
    void tripToOne(RouteList r);
    double toDegree(double input);
    void getNewCoord(RouteList r);
    double calBearing(RouteList r);
    void calcNextPoint(RouteList r);

public:
    double bearing;


private:
    QVector < double > vecLat;
    QVector < double > vecLon;
};

#endif // CALCPOSITION_H
