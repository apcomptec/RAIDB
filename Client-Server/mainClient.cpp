#include <QtCore/QCoreApplication>
#include "client.h"

int mainClient(int argc, char *argv[])
//int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Client c;
    c.connectToServer("172.26.108.227", 1234);
    return a.exec();
}
