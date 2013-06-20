#include <QCoreApplication>
#include "masterserver.h"
#include "serverstorage.h"

int mainServer(int argc, char *argv[])
//int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Server *serverMaster = new MasterServer();
    serverMaster->startServer(9999);
    
    return a.exec();
}
