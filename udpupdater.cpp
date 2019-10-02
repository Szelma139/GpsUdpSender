#include "udpupdater.h"
#include <QByteArray>
#include <QDataStream>

UdpUpdater::UdpUpdater(QObject * parent)
{
//connect(&timer,SIGNAL(timeout()), this, SLOT(sendDatagram()));
//timer.start(1000);
}


void UdpUpdater::sendDatagram()
{
    QByteArray datagram;
       QDataStream out(&datagram, QIODevice::WriteOnly);
       out.setVersion(QDataStream::Qt_4_3);
       out <<"GPRMC";

       udpSocket.writeDatagram(datagram, QHostAddress::LocalHost, 5824);
}
