#ifndef PARSEGPRMC_H
#define PARSEGPRMC_H
#include <QString>

class ParseGPRMC
{
public:
    ParseGPRMC();
    ParseGPRMC(   QString header="$GPRMC",
    QString position=NULL,
    QString pos_status="A",
    QString lat=NULL,
    QString lat_dir="N",
    QString lon=NULL,
    QString lon_dir="E",
    QString speedKn=NULL,
    QString track_true=NULL,
    QString date="210307",
    QString mag_var=NULL,
    QString var_dir=NULL,
    QString mode_ind=NULL,
    QString checksum=NULL,
    QString terminator="[CR][LF]");
    void createGPRMC(QString lon, QString lat, QString szybkosc);

    QString header="$GPRMC";
    QString position="133311.00";
    QString pos_status="A";
    QString lat;
    QString lat_dir="N";
    QString lon;
    QString lon_dir="E";
    QString speedKn;
    QString track_true;   //azymut
    QString date="210307";
    QString mag_var="0.0";
    QString var_dir="E";
    QString mode_ind="A";
    QString checksum="*20";
    QString terminator="[CR][LF]";

};

#endif // PARSEGPRMC_H
