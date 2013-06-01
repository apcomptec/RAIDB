#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>
#include <cstdio>
#include <QString>

class QTcpSocket;

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = 0);
    void connectToServer(QString pIP, int pPort);

signals:

public slots:
    void on_connected(QString);

private:
    QTcpSocket* socket;
};

#endif // CLIENT_H
