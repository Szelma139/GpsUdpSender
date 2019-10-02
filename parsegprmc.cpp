#include "parsegprmc.h"

ParseGPRMC::ParseGPRMC()
{
 //$GPRMC, 120000.00, A, lat, N, lon, E, szybkosc,
    //azymut, 130694,E,A,*20
    //202.9

    //minimalna ramka GPRMC
    // $GPRMC, 120000.00,A, lat, lon, szybkosc,
    //azymut, 130694, 003.1, *20

}



void ParseGPRMC::createGPRMC(QString lon, QString lat, QString szybkosc)
{

this->lon=lon;
this->lat=lat;
this->speedKn=szybkosc;
}
