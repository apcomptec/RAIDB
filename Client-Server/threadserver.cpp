#include "threadserver.h"

ThreadServer::ThreadServer(int ID, QObject *parent) :
    QThread(parent)
{
    this->_socketDescriptor = ID;
}

void ThreadServer::run(){
    //El hilo corre aqui
    qDebug() << "Starting Thread";
    this->_socket  = new QTcpSocket();

    if(!this->_socket->setSocketDescriptor(this->_socketDescriptor))
    {
        emit error(this->_socket->error());
        return;
    }

    connect(this->_socket, SIGNAL(readyRead()),this,SLOT(readyRead()),Qt::DirectConnection);
    connect(this->_socket, SIGNAL(disconnected()),this,SLOT(disconnect()),Qt::DirectConnection);

    qDebug() << this->_socketDescriptor << " Client connected";

    exec();
}

void ThreadServer::readyRead()
{
    QByteArray Data = this->_socket->readAll();

    qDebug() << this->_socketDescriptor << "Data in: " << Data;

    this->_socket->write(Data);
}

void ThreadServer::disconnect()
{
    qDebug() << this->_socketDescriptor << "Client disconnected";
    this->_socket->deleteLater();
    exit(0);
}
