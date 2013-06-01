#include "client.h"

Client::Client(QObject *parent) :
    QObject(parent)
{
    socket = new QTcpSocket(this);
}

void Client::on_connected(QString pMessage)
{
    socket->write(pMessage.toAscii());
    socket->waitForReadyRead();
    socket->waitForBytesWritten();
    qDebug() << socket->readAll();
}

void Client::connectToServer(QString pIP, int pPort)
{
    QHostAddress address(pIP);
    socket->connectToHost(address, pPort);
}
