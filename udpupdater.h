#ifndef UDPUPDATER_H
#define UDPUPDATER_H

#include <QUdpSocket>
#include <QTimer>


class UdpUpdater : public QObject
{
    Q_OBJECT
public:
    UdpUpdater(QObject * parent);
    int ramka;
    QUdpSocket udpSocket;
    QTimer timer;
public slots:
    void sendDatagram();
};

#endif // UDPUPDATER_H
