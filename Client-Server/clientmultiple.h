#ifndef CLIENTMULTIPLE_H
#define CLIENTMULTIPLE_H
#include <QString>
#include "client.h"
#include "dataStructure/DLL.h"


class ClientMultiple
{
public:
    ClientMultiple();
    void addIPAdrress(QString, int);
    void start();

private:
    DLL<Client*>* _list;
};

#endif // CLIENTMULTIPLE_H
