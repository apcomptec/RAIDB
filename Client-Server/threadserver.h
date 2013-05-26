#ifndef THREADSERVER_H
#define THREADSERVER_H

#include <QThread>
#include <QTcpSocket>


class ThreadServer : public QThread
{
    Q_OBJECT
public:
    //Constructor
    explicit ThreadServer(int ID, QObject *parent = 0);
    //Ejecucion del hilo
    void run();

signals:
    //Error
    void error(QTcpSocket::SocketError socketerror);

public slots:
    //Lectura de datos
    void readyRead();
    //Desconexion
    void disconnect();

    
public slots:

private:
    //Socket para recibir
    QTcpSocket *_socket;
    //Identificador del socket
    int _socketDescriptor;
};

#endif // THREADSERVER_H
