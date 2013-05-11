#include <QtCore/QCoreApplication>
#include "client.h"

int mainClient(int argc, char *argv[])
//int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Client c;
    c.connectToServer("192.168.0.105", 1234);
    return a.exec();
}
