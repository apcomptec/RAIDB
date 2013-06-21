#ifndef THREADSERVER_H
#define THREADSERVER_H

#include <QThread>
#include <QTcpSocket>
#include <QDataStream>


class ThreadServer : public QThread
{
    Q_OBJECT
public:
    //Constructor
    ThreadServer(int ID, QObject *parent = 0);
    ThreadServer();
    //Ejecucion del hilo
    void run();
    virtual void answerProtocol(QString) = 0;
    void writeToClient(QString);

signals:
    //Error
    void error(QTcpSocket::SocketError socketerror);

public slots:
    //Lectura de datos
    void readyRead();
    //Desconexion
    void disconnect();

    
public slots:

protected:
    //Socket para recibir
    QTcpSocket *_socket;
    //Identificador del socket
    int _socketDescriptor;
};

#endif // THREADSERVER_H
