#include "ip.h"

IP::IP(QString pIP, int pNumLSS, int pSize, int pSizeBlock, DLL<int>* pNumUsedBlock)
{
    this->_ip = pIP;
    this->_numLSS = pNumLSS;
    this->_sizeDisk = pSize;
    this->_sizeBlock = pSizeBlock;
    this->_numUsedBlocks = pNumUsedBlock;
}

IP::~IP(){}

void IP::setIP(QString pIP)
{
    this->_ip = pIP;
}

void IP::setNumLSS(int pNum)
{
    this->_numLSS = pNum;
}

void IP::setNumUsedBlock(DLL<int>* pNum)
{
    this->_numUsedBlocks = pNum;
}

void IP::setSize(int pSize)
{
    this->_sizeDisk = pSize;
}

void IP::setSizeBlock(int pSize)
{
    this->_sizeBlock = pSize;
}

QString IP::getIP()
{
    return this->_ip;
}

int IP::getNumLSS()
{
    return this->_numLSS;
}

DLL<int>* IP::getNumUsedBlock()
{
    return this->_numUsedBlocks;
}

int IP::getSize(){
    return this->_sizeDisk;
}

int IP::getSizeBlock()
{
    return this->_sizeBlock;
}

void IP::calcNumOfBlocks()
{
    this->_numBlocks = this->_sizeDisk / this->_sizeBlock;
}
