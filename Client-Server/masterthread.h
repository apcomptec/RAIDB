#ifndef MASTERTHREAD_H
#define MASTERTHREAD_H
#include "threadserver.h"
#include "QRegExpValidator"
#include "QStringList"
#include "dataStructure/DLL.h"
#include "user.h"

class MasterThread: public ThreadServer
{
private:
    DLL<User*>* _listUser;
    DLL<int>* _listIdDisk;

public:
    MasterThread(int &pID, QObject *parent);
    ~MasterThread();

    void answerProtocol(QString);
    QString addUser(QString);
    QString verifyUser(QString);
};

#endif // MASTERTHREAD_H
