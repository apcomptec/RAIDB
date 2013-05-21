#ifndef CLIENTNODE_H
#define CLIENTNODE_H
#include <fstream>
#include <iostream>
using namespace std;



class ClientNode
{
public:
    string _IP;
    int _Port;
    ClientNode* _Next;
    ClientNode* _Previous;
public:
    ClientNode(string pIP, int pPort);
    string getIP();
    int getPort();
    ClientNode* getnext();
    ClientNode* getprevious();
    void setIP(string pIP);
    void setPort(int pPort);
    void setnext(ClientNode* pNext);
    void setprevious(ClientNode* pPrevious);

};

#endif // CLIENTNODE_H
