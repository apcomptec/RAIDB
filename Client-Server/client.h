
#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>
#include <cstdio>
#include <iostream>
#include "ClientNode.h"
#include "ListClient.h"

class QTcpSocket;

class Client : public QObject
{
    Q_OBJECT
public:
    //Constructor
    explicit Client(QObject *parent = 0);

    //Conectar al servidor
    void connectToServer(QString pIp, int pPort);
    void ListAllconnection(string pIP,int pPort);
    void ConnectToAllserver();

signals:

//public slots:
////    //Estar conectado para enviar datos
//   void on_connected();

private:
    //Socket de envio
    QTcpSocket* socket;

public:
    ListClient* Listconnection;
};

#endif // CLIENT_H
