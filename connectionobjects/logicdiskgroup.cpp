#include "logicdiskgroup.h"

LogicDiskGroup::LogicDiskGroup()
{
    this->_listIP = new DLL<IP*>();
}

LogicDiskGroup::~LogicDiskGroup(){}

void LogicDiskGroup::insertIP(IP * pIP)
{
    this->_listIP->insertAtBack(pIP);
}

void LogicDiskGroup::removeIP(IP * pIP)
{
    this->_listIP->removeSpecific(pIP);
}

IP* LogicDiskGroup::searchIP(IP * pIP)
{
    return this->_listIP->searchInOrder(pIP)->getData();
}

void LogicDiskGroup::calcAndOrganize()
{
    this->_listResult = new DLL<IP*>();

    int numDisk = this->_listIP->getSize();

    if((numDisk % NUMMAXDISK) == 0)
    {
        this->numDiskComplete = numDisk / NUMMAXDISK;
    }else
    {
        numDiskComplete = numDisk / NUMMAXDISK;
        numDiskIncomplete = numDisk - (numDiskComplete * NUMMAXDISK);
    }

    if(this->_listIP->getSize() < NUMMAXDISK)
    {
        this->_listResult = this->_listIP;
    }
    for (int var = 0; var < NUMMAXDISK; ++var) {
        this->_listResult->insertAtBack(this->getRandomIP());
    }
}

IP* LogicDiskGroup::getRandomIP()
{
    int it = 0, randDisk = rand() % this->_listIP->getSize();
    DLLNode<IP*>* tmpDisk = this->_listIP->getHeadPtr();
    while(it != randDisk)
    {
        tmpDisk = tmpDisk->getNextPtr();
        it++;
    }
    this->removeIP(tmpDisk->getData());
    return tmpDisk->getData();
}

DLL<IP*>* LogicDiskGroup::getListIP()
{
    this->calcAndOrganize();
    return this->_listResult;
}
