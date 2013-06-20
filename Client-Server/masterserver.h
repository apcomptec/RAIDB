#ifndef MASTERSERVER_H
#define MASTERSERVER_H
#include "server.h"

class MasterServer: public Server
{
private:
    ThreadServer * _threadMaster;

public:
    MasterServer();
    ~MasterServer();
    void incomingConnection(int pSocketDescriptor);
};

#endif // MASTERSERVER_H
