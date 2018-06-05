#ifndef PISERVER_H
#define PISERVER_H
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QDateTime>
#include "message.h"
#include "protocolparser.h"
#include "parseexception.h"


class PiServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit PiServer(QObject *parent = 0);
    void incomingConnection(qintptr handle);
private:
    struct SocketData {
            QDateTime date;
            long fullSize;
            QByteArray socketData;
        };
     QMap<qintptr, SocketData> socketMap;
public slots:
    void onReadyRead();
    void onDisconnected();
signals:
    void newDataRead(Message message);
};

#endif // PISERVER_H
