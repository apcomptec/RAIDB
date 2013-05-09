#include "server.h"

Server::Server(QObject *parent) :
    QTcpServer(parent)
{
}


void Server::startServer()
{
    if(!this->listen(QHostAddress::Any, 1234))
    {
        qDebug() << "No se pudo iniciar el servidor";
    }
    else
    {
        qDebug() << "Escuchando..." ;
    }
}

void Server::incomingConnection(int pSocketDescriptor)
{
    qDebug() << pSocketDescriptor << "Conectando...";
    ThreadServer *thread = new ThreadServer(pSocketDescriptor);

    connect(thread, SIGNAL(finished()), thread,SLOT(deleteLater()));
    thread->start();
}
