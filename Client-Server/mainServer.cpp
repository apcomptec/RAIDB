#include <QCoreApplication>
#include "server.h"

//int mainServer(int argc, char *argv[])
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Server server;
    server.startServer();
    
    return a.exec();
}
