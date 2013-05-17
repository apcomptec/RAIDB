#include <QtCore/QCoreApplication>
#include "client.h"

int mainClient(int argc, char *argv[])
//int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString ip ("172.26.105.190");
    Client c;
    c.connectToServer(ip, 9999);
    return a.exec();
}
