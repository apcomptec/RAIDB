#ifndef LOGICDISKGROUP_H
#define LOGICDISKGROUP_H
#include "dataStructure/DLL.h"
#include "ip.h"

#define NUMMAXDISK 4

class LogicDiskGroup
{
private:
    DLL<IP*>* _listIP;
    DLL<IP*>* _listResult;
    int numDiskComplete, numDiskIncomplete;

public:
    //CONSTRUCTOR Y DESTRUCTOR
    LogicDiskGroup();
    ~LogicDiskGroup();

    //Metodos
    void insertIP(IP*);
    void removeIP(IP*);
    IP* searchIP(IP*);

    void calcAndOrganize();
    IP *getRandomIP();
    DLL<IP *> *getListIP();
};

#endif // LOGICDISKGROUP_H
