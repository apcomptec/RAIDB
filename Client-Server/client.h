#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>
#include <cstdio>
#include <iostream>

class QTcpSocket;

class Client : public QObject
{
    Q_OBJECT
public:
    //Constructor
    explicit Client(QObject *parent = 0);
    //Conectar al servidor
    void connectToServer(QString pIp, int pPort);

signals:

public slots:
    //Estar conectado para enviar datos
    void on_connected();

private:
    //Socket de envio
    QTcpSocket* socket;
};

#endif // CLIENT_H
