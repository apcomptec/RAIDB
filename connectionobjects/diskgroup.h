#ifndef DISKGROUP_H
#define DISKGROUP_H
#include "dataStructure/DLL.h"
#include "ip.h"
#include "raid/IRaid.h"


class DiskGroup
{
private:
    DLL<IP*>* _listDisk;
    int _id;
    IRaid* _raid;

public:
    //CONSTRUCTOR Y DESTRUCTOR
    DiskGroup(DLL<IP*>* pList, int pID);
    ~DiskGroup();

    //METODOS
    DLL<IP*>* getListIP();
    void setListIP(DLL<IP*>*);

    void verifyAndChangeSize();
};

#endif // DISKGROUP_H
