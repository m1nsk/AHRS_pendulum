#include "piserver.h"
#include <iostream>

using namespace std;

PiServer::PiServer(QObject *parent) :
    QTcpServer(parent)
{
    if (listen(QHostAddress::LocalHost, 8001)) {
        cout << "Listening...";
    } else {
        cout << "Error while starting:" << errorString().toStdString();
    }
}

void PiServer::incomingConnection(qintptr handle)
{
    QTcpSocket *socket = new QTcpSocket();
    socket->setSocketDescriptor(handle);

    connect(socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(onDisconnected()));
}

void PiServer::onReadyRead()
{
    QTcpSocket *socket = qobject_cast<QTcpSocket*>(sender());
    QByteArray data = socket->readAll();
    SocketData sd;
    if (!socketMap.contains(socket->socketDescriptor())) {
        sd = {
           QDateTime::currentDateTime(),
            ProtocolParser::getFullLength(data),
            data
        };
        socketMap.insert(socket->socketDescriptor(), sd);
    } else {
        sd = socketMap.value(socket->socketDescriptor());
        sd.socketData += data;
        socketMap.insert(socket->socketDescriptor(), sd);
    }
    if (sd.fullSize <= sd.socketData.size()) {
        Message *msg = ProtocolParser::parseData(sd.socketData);
        if (msg) {
            socket->write(QString("OK").toLatin1());
            emit newDataRead(*msg);
        } else {
            socket->write(QString("FAIL").toLatin1());
        }
        socketMap.remove(socket->socketDescriptor());
        socket->disconnectFromHost();
    }
}

void PiServer::onDisconnected()
{
    QTcpSocket *socket = qobject_cast<QTcpSocket*>(sender());
    socket->close();
    socket->deleteLater();
}
