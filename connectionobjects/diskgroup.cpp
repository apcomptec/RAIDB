#include "diskgroup.h"

DiskGroup::DiskGroup(DLL<IP *> * pList, int pID)
{
    this->_listDisk = pList;
    this->_id = pID;
}

DiskGroup::~DiskGroup()
{}

DLL<IP*>* DiskGroup::getListIP()
{
    return this->_listDisk;
}

void DiskGroup::setListIP(DLL<IP *> *pList)
{
    this->_listDisk = pList;
}

void DiskGroup::verifyAndChangeSize()
{
    DLLNode<IP*>* tmpNode = this->_listDisk->getHeadPtr();
    IP* lessSizeIP = tmpNode->getData();
    while(tmpNode != nullptr)
    {
        if(lessSizeIP->getSize() > tmpNode->getData()->getSize())
        {
            lessSizeIP = tmpNode->getData();
        }
        tmpNode = tmpNode->getNextPtr();
    }

    tmpNode = this->_listDisk->getHeadPtr();
    while(tmpNode != nullptr)
    {
        tmpNode->getData()->setSize(lessSizeIP->getSize());
        tmpNode = tmpNode->getNextPtr();
    }
}
