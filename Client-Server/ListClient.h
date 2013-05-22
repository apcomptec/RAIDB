#ifndef LISTCLIENT_H
#define LISTCLIENT_H
#include "ClientNode.h"
class ListClient
{
public:
    ClientNode* _head;
    ClientNode* _tail;
    unsigned short count;

public:
    ListClient();
    void insertconnection(string pIP,int pPort);
    void printconnection();
    ClientNode* gethead();
    unsigned short getcount();
    void setcount(unsigned short count);
};

#endif // LISTCLIENT_H
