#ifndef MASTERTHREAD_H
#define MASTERTHREAD_H
#include "threadserver.h"
#include "QRegExpValidator"
#include "dataStructure/DLL.h"

class MasterThread: public ThreadServer
{
private:
    DLL<QString>* _listUser;
    DLL<int>* _listIdDisk;

public:
    MasterThread(int &pID, QObject *parent);
    ~MasterThread();
    void answerProtocol(QString);
};

#endif // MASTERTHREAD_H
