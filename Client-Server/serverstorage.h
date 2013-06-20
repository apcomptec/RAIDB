#ifndef SERVERSTORAGE_H
#define SERVERSTORAGE_H
#include "server.h"

class ServerStorage: public Server
{
public:
    ServerStorage();
    ~ServerStorage();
    void incomingConnection(int pSocketDescriptor);
};

#endif // SERVERSTORAGE_H
