#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>
#include <cstdio>
#include <iostream>
#include "dataStructure/DLL.h"

class QTcpSocket;

class Client : public QObject
{
    Q_OBJECT
public:
    //Constructor
    explicit Client(QObject *parent = 0);
    //Conectar al servidor
    void connectToServer(QString pIp, int);

signals:

public slots:
    //Estar conectado para enviar datos
    void on_connected();
    void connectToMultipleServer(DLL<QString>*, int pPort);

private:
    //Socket de envio
    QTcpSocket* _socket;
    //Arreglo de sockets
    QTcpSocket* _socketArray;
};

#endif // CLIENT_H
