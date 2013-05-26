#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QDebug>
#include "threadserver.h"

class Server : public QTcpServer
{
    Q_OBJECT
public:
    //Constructor
    explicit Server(QObject *parent = 0);
    //Se inicializa el server
    void startServer();

signals:

public slots:
    
protected:
    //Recibe conexiones
    void incomingConnection(int pSocketDescriptor);
};

#endif // SERVER_H
