#ifndef MASTERTHREAD_H
#define MASTERTHREAD_H
#include "threadserver.h"
#include "dataStructure/DLL.h"

class MasterThread: public ThreadServer
{
private:
    DLL<QString>* _listUser;
    DLL<int>* _listIdDisk;

public:
    MasterThread(int pId, QObject *pParent = 0);
    ~MasterThread();
};

#endif // MASTERTHREAD_H
