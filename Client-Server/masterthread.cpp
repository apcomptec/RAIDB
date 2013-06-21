#include "masterthread.h"

MasterThread::MasterThread(int pId, QObject* pParent)
    :QThread(pParent)
{
    this->_socketDescriptor = pId;
}

MasterThread::~MasterThread()
{}
