#ifndef QUERY_H
#define QUERY_H

#endif // QUERY_H
#include <QString>


const QString get_route = "SELECT sta.NAZWA, sta.POZX, sta.POZY, sta.NAZWA_PELN "
       "from TRASA as tra "
      "LEFT JOIN STACJE as sta on tra.id_stacji = sta.id_stacji "
      "LEFT JOIN POCIAGI as poc on tra.ID_POCIAGU = poc.ID_POCIAGU "
      "where poc.ID_POCIAGU=:id";
