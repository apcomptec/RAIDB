#ifndef MASTERTHREAD_H
#define MASTERTHREAD_H
#include "threadserver.h"
#include "QRegExpValidator"
#include "QStringList"
#include "dataStructure/DLL.h"
#include "connectionobjects/user.h"
#include "dataStructure/n_aryrecordfile.h"

class MasterThread: public ThreadServer
{
private:
    DLL<User*>* _listUser;
    DLL<int>* _listIdDisk;
    IN_aryTree<QString>* _fileSystem;

public:
    MasterThread(int &pID, QObject *parent);
    ~MasterThread();

    void answerProtocol(QString);
    QString addUser(QString);
    QString verifyUser(QString);
    void createFolder(QString);
};

#endif // MASTERTHREAD_H
