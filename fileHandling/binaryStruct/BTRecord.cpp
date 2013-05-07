/*******************************************************************************
 * File: BTRecord.cpp
 * Author: Brallan Aguilar
 * Description: Implementación de BTRecord.h
 * Reference:
 ******************************************************************************/

#include "BTRecord.h"

// -----------------------------------------------------------------------------
// DEFINICIÓN DE CONSTANTES
// -----------------------------------------------------------------------------
const char BTRecord::STRING     = 0;
const char BTRecord::CHAR       = 1;
const char BTRecord::SHORT      = 2;
const char BTRecord::INT        = 3;
const char BTRecord::DOUBLE     = 4;
const char BTRecord::BOOL       = 5;
// -----------------------------------------------------------------------------

BTRecord::BTRecord()
{
}

DLL<IRecordDataType *> *BTRecord::getDataListPtr() const
{
    return _dataListPtr;
}

void BTRecord::setDataList(DLL<IRecordDataType *> *pDataListPtr)
{
    _dataListPtr = pDataListPtr;
}

unsigned short *BTRecord::getIndex() const
{
    return _indexPtr;
}

void BTRecord::setIndex(unsigned short *pIndexPtr)
{
    _indexPtr = pIndexPtr;
}

unsigned short *BTRecord::getParentPtr() const
{
    return _parentPtr;
}

void BTRecord::setParentPtr(unsigned short *pParentPtr)
{
    _parentPtr = pParentPtr;
}

unsigned short *BTRecord::getLeftChildPtr() const
{
    return _leftChildPtr;
}

void BTRecord::setLeftChildPtr(unsigned short *pLeftChildPtr)
{
    _leftChildPtr = pLeftChildPtr;
}


void BTRecord::setRightChildPtr(unsigned short *pRightChildPtr)
{
    _rightChildPtr = pRightChildPtr;
}
