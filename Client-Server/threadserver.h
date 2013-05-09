#ifndef THREADSERVER_H
#define THREADSERVER_H

#include <QThread>
#include <QTcpSocket>


class ThreadServer : public QThread
{
    Q_OBJECT
public:
    explicit ThreadServer(int ID, QObject *parent = 0);
    void run();

signals:
    void error(QTcpSocket::SocketError socketerror);

public slots:
    void readyRead();
    void disconnect();

    
public slots:

private:
    QTcpSocket *_socket;
    int _socketDescriptor;
};

#endif // THREADSERVER_H
