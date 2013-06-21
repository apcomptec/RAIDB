#ifndef MASTERSERVER_H
#define MASTERSERVER_H
#include "server.h"
#include "masterthread.h"

class MasterServer: public Server
{
private:

public:
    MasterServer();
    ~MasterServer();
    void incomingConnection(int pSocketDescriptor);
};

#endif // MASTERSERVER_H
