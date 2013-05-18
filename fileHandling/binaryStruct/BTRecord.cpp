/*******************************************************************************
 * File: BTRecord.cpp
 * Author: Brallan Aguilar
 * Description: Implementación de BTRecord.h
 * Reference:
 ******************************************************************************/

#include "BTRecord.h"

BTRecord::BTRecord()
{
    // vacío
}

DLL<IRecordDataType *> *BTRecord::getDataListPtr() const
{
    return _dataListPtr;
}

void BTRecord::setDataList(DLL<IRecordDataType *> *pDataListPtr)
{
    _dataListPtr = pDataListPtr;
}


unsigned short BTRecord::getParentPtr() const
{
    return _parentPtr;
}

void BTRecord::setParentPtr(unsigned short pParentPtr)
{
    _parentPtr = pParentPtr;
}

unsigned short BTRecord::getLeftChildPtr() const
{
    return _leftChildPtr;
}

void BTRecord::setLeftChildPtr(unsigned short pLeftChildPtr)
{
    _leftChildPtr = pLeftChildPtr;
}

unsigned short BTRecord::getRightChildPtr() const
{
    return _rightChildPtr;
}

void BTRecord::setRightChildPtr(unsigned short pRightChildPtr)
{
    _rightChildPtr = pRightChildPtr;
}

void BTRecord::printRecord() const
{
    std::cout << "Parent" << "LeftChild" << "RightChild" << "DataList\n";

}

std::string BTRecord::castRecordToBinary()
{

}
